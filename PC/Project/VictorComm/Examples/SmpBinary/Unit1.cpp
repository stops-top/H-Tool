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
  try
   {
     YbCommDevice1->Active = true;
   }
  catch(Exception &e)
   {
     ShowMessage(L"YbCommDevice1: "+e.Message);
   }
}
//---------------------------------------------------------------------------
#pragma argsused // 不使用 Sender 参数
void __fastcall TForm1::ButtonSet1Click(TObject *Sender)
{
  YbCommDevice1->SettingsDialog(this,true);
}
//---------------------------------------------------------------------------
#pragma argsused // 不使用 Sender 参数
void __fastcall TForm1::ButtonSend1Click(TObject *Sender)
{
  int nBytes = 0;
  char Buffer[1000];
  wchar_t *EndPtr;
  UnicodeString t,s = Edit1->Text.Trim();
  while(s.Length()>0)
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
  YbCommDevice1->Write(Buffer,nBytes);
}
//---------------------------------------------------------------------------
#pragma argsused // 不使用 Sender 参数
void __fastcall TForm1::YbCommDevice1CommNotify(TObject *Sender, int NotifyType)
{
  UnicodeString s;

  if(NotifyType&EV_ERR)
   {
     s = L"数据错误 ";
   }

  unsigned char Buf[8192]; //收到的字节数不会超过串口缓存的容量, 所以分配一个缓存容量相同的Buf
  int n = YbCommDevice1->Read(Buf,8192); //收到 n 个字节

  for(int i=0; i<n; i++)
    s += IntToHex(Buf[i],2) + " ";
  s = s.Trim();

  if(!s.IsEmpty())
   {
     Memo1->Lines->Add(s);
   }
}
//---------------------------------------------------------------------------

