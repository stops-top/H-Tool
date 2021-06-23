//---------------------------------------------------------------------------
// 串口控件演示程序，Copyright © Victor Chen

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
  YbCommDevice1->PackageType = cptFrameTimeout; //用判断超时的方法接收数据包
  YbCommDevice1->UsePackage  = true; //启动数据包 (可以随时启动和停止, 与 Active 属性无关)
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
  wchar_t *EndPtr=NULL; //指示数据转换错误 if(EndPtr){if(*EndPtr){ 转换失败 }}

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
        s = "";
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