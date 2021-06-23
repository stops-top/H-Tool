//---------------------------------------------------------------------------
// 控件演示程序，Copyright © Victor Chen

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "YbCommDevice"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
  YbCommDevice1->PackageType = cptFrameHeadTail;
  YbCommDevice1->FrameSettings->FrameHead = 0xdb; //数据包头
  YbCommDevice1->FrameSettings->FrameTail = 0xde; //数据包尾
  YbCommDevice1->FrameSettings->FrameCtrl = 0xdc; //数据控制符

  try
   {
     YbCommDevice1->Active = true;
   }
  catch(Exception &e)
   {
     ShowMessage("YbCommDevice1: "+e.Message);
     if(!YbCommDevice1->SettingsDialog(this,true))
       Application->Terminate();
   }

  YbCommDevice1->PackageSize = 4096; //最大可发送 4096 个字节的数据包
  YbCommDevice1->UsePackage = true; //启动数据包 (可以随时启动和停止, 与 Active 属性无关)
}
//---------------------------------------------------------------------------
#pragma argsused // 不使用 Sender 参数
void __fastcall TForm1::ButtonSetClick(TObject *Sender)
{
  YbCommDevice1->SettingsDialog(this,true);
}
//---------------------------------------------------------------------------
#pragma argsused // 不使用 Sender 参数
void __fastcall TForm1::ButtonSendClick(TObject *Sender)
{
  const int BufSize = 4096;
  char Buffer[BufSize];
  int nBytes = 0;
  wchar_t *EndPtr=0; //指示数据转换错误 if(EndPtr){if(*EndPtr){ 转换失败 }}

  UnicodeString t,s = Edit1->Text.Trim();
  while((s.Length()>0) && (nBytes<BufSize))
   {
     int p = s.Pos(' '); //空格
     if(p>0)
      {
        t = s.SubString(1,p-1);
        s = s.SubString(p+1,s.Length()).Trim();
        Buffer[nBytes++] = wcstol(t.w_str(), &EndPtr, 16); //十六进制字符串转成字节
      }
     else //还剩下最后一个字节
      {
        t = s;
        s = L"";
        Buffer[nBytes++] = wcstol(t.w_str(), &EndPtr, 16); //十六进制字符串转成字节
      }
   }

  YbCommDevice1->WritePackage(Buffer,nBytes); //发送数据包
}
//---------------------------------------------------------------------------
#pragma argsused // 不使用 Sender 参数
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
  const int BufSize = 4096;
  unsigned char Buffer[BufSize];
  int nBytes = 0;

  while((nBytes=YbCommDevice1->ReadPackage(Buffer,BufSize))>0)
   {
     UnicodeString s;
     for(int i=0; i<nBytes; i++)
       s += IntToHex(Buffer[i],2) + " ";
     s = s.Trim();

     if(!s.IsEmpty())
       Memo1->Lines->Add(s);
   }
}
//---------------------------------------------------------------------------

/*-------------------------------------------------------------------------*\
|                                                                           |
| 简单数据包协议的实现原理:                                                 |
|                                                                           |
|   1.定义数据包头,尾,控制符, 例如本程序定义的为 DB,DE,DC                   |
|           (DB,DE,DC 分别取 Data-Begin, Data-End, Data-Control 的字头)     |
|   2.所有的数据发送都以如下格式:                                           |
|            0xDB + 数据 + 0xDE                                             |
|   3.如果数据含有控制符, 转换为 0xDC + 字符, 接收端认为 0xDC 后面的是数据  |
|                                                                           |
| 例如: 3个字节的数据 0x12, 0xdb, 0x99 的数据包格式为:                      |
|                     0xdb, 0x12, 0xdc, 0xdb, 0x99, 0xde                    |
|     其中 0xdb 被转义为 0xdc, 0xdb 两个字节                                |
|                                                                           |
| 以上实现过程是自动执行的                                                  |
|                                                                           |
|---------------------------------------------------------------------------|
|                                                                           |
| 例如发送 0x12, 0xdb, 0x99 数据包, 只需要:                                 |
|                                                                           |
| pkg.nBytes = 3; //发送 3 个字节的数据包                                   |
| pkg.Data[0] = 0x12;                                                       |
| pkg.Data[1] = 0xdb;                                                       |
| pkg.Data[2] = 0x99;                                                       |
| YbCommDevice1->WritePackage(&pkg);                                        |
|                                                                           |
| 实际发送 0xdb, 0x12, 0xdc, 0xdb, 0x99, 0xde 六个字节                      |
|                                                                           |
|---------------------------------------------------------------------------|
|                                                                           |
| 数据包的接收也是自动执行的, 例如串口的数据:                               |
| DB 01 02 DE DB 88 DC DB DE                                                |
| 被解释为 2 个数据包, 其中一个为 01 02 另一个为 88 DB                      |
|                                                                           |
| 不符合规则的数据会自动过滤掉                                              |
| 例如 DB 01 02 DE 55 66 DB 88 DC DB DE 77 当中的 55 66 77 接收时会被滤掉   |
\*-------------------------------------------------------------------------*/
