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
     ShowMessage("YbCommDevice1: "+e.Message);
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonSet1Click(TObject *Sender)
{
  YbCommDevice1->SettingsDialog(this,true);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonSend1Click(TObject *Sender)
{
  if(RadioBtnANSI->Checked)
   {
     AnsiString s = Memo1->Text; // 转成 ANSI/ASCII 传输
     YbCommDevice1->Write(s.c_str(),s.Length());
   }
  else // UTF-8
   {
     UTF8String s = Memo1->Text; // 转成 UTF8 传输
     YbCommDevice1->Write(s.c_str(),s.Length());
   }
}
//---------------------------------------------------------------------------
RawByteString sRawBuf; // 这个字符串类型不会解析字符编码，不会丢弃不完整的字符(比如半个汉字)
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
  //收到的字节数不会超过串口缓存的容量, 所以分配一个缓存容量相同的Buf
  char Buf[8192+1]; //多一个文本结束符
  int n = YbCommDevice1->Read(Buf,8192);

  if(n>0) //收到字节数
   {
     Buf[n] = 0; //添加一个文本结束符 '\0'
     sRawBuf+=Buf; // RawByteString 类型，上一次是不完整字符的前半截，能和本次不完整的字符和后半截加在一起，不会因为解析字符编码而丢弃不完整的字符
     if(RadioBtnANSI->Checked)
       Memo1->Text = AnsiString(sRawBuf.c_str()); // RawByteString 里面的字符串内容是 AnsiString
     else
       Memo1->Text = UTF8String(sRawBuf.c_str()); // RawByteString 里面的字符串内容是 UTF8String
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonClearClick(TObject *Sender)
{
  sRawBuf = "";
  Memo1->Lines->Clear();
}
//---------------------------------------------------------------------------
