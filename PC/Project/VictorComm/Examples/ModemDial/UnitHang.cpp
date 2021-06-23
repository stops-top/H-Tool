//---------------------------------------------------------------------------
// 控件演示程序，Copyright © Victor Chen, www.cppfans.com

#include <vcl.h>
#pragma hdrstop

#include "UnitHang.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormHang *FormHang;
//---------------------------------------------------------------------------
__fastcall TFormHang::TFormHang(TComponent* Owner)
    : TForm(Owner)
{
  iWhatToDo = 0;
  iRetryTimes = 0;
  iTotalRetries = 0;
  iCloseDelay = 8; // 8 * TimerInterval = 2 (s)
  Modem = 0;

  TMsgStrings Msgs;
  Caption              = Msgs.Msg[TMsgStrings::MsgHang   ]; //"挂机"
  LabelPrompt->Caption = Msgs.Msg[TMsgStrings::MsgHanging]; //"正在挂机, 请稍候……"
}
//---------------------------------------------------------------------------
__fastcall TFormHang::~TFormHang()
{
  if(Modem)
   {
     EscapeCommFunction(Modem->Handle, SETDTR);
   }
}
//---------------------------------------------------------------------------
int __fastcall TFormHang::Hang(TComm32 *lpModem, int Retries)
{
  iWhatToDo = 0;
  iTotalRetries = Retries>0?Retries:1;
  iRetryTimes = iTotalRetries;

  Modem = lpModem;
  Modem->DisableWrite = true;
  int iRetVal = ShowModal();
  Modem->DisableWrite = false;
  return iRetVal;
}
//---------------------------------------------------------------------------
#pragma argsused // 不使用 Sender 参数
void __fastcall TFormHang::TimerHangTimer(TObject *Sender)
{
  if(Modem)
   {
     if((Modem->ModemStatus & MS_RLSD_ON) == 0)
      {
        FinalOK();
      }
     else if(iRetryTimes>0)
      {
        DoHangProc();
      }
     else
      {
        FinalError();
      }
   }
}
//---------------------------------------------------------------------------
void __fastcall TFormHang::DoHangProc(void)
{
  //... wait ... Command("+++") ... wait ... Command("ATH0\r") ... wait ...
  switch(iWhatToDo)
   {
     case  8: Modem->Command("+++"); break;
     case 16: Modem->Command("ATH0\r"); break;
     case 32: EscapeCommFunction(Modem->Handle, CLRDTR); break;
   }
  CheckResult();
}
//---------------------------------------------------------------------------
void __fastcall TFormHang::CheckResult(void)
{
  if(++iWhatToDo>80) // 80 * TimerInterval / 1000 = 20 (s)
   {
     iWhatToDo = 0;
     iRetryTimes--;
   }
}
//---------------------------------------------------------------------------
void __fastcall TFormHang::FinalOK(void)
{
  if(iCloseDelay)
   {
     if(iCloseDelay>0)
      if(--iCloseDelay==0)
       ModalResult = IDOK;
   }
  else
   {
     ModalResult = IDOK;
   }
}
//---------------------------------------------------------------------------
void __fastcall TFormHang::FinalError(void)
{
  ModalResult = IDNO;
}
//---------------------------------------------------------------------------

__fastcall TFormHang::TMsgStrings::TMsgStrings()
{
  switch(TComm32Language().lcId)
   {
     case TComm32Language::lcidChs:
          _Msg = _Msg_Chs;
          break;

     case TComm32Language::lcidCht:
          _Msg = _Msg_Cht;
          break;

     default:
          _Msg = _Msg_Enu;
          break;
   }
}
//---------------------------------------------------------------------------

UnicodeString __fastcall TFormHang::TMsgStrings::fGetMsg(TMsgType mt)
{
  if(mt>=0 && mt<MsgCount)
    return _Msg[mt];
  return L"";
}
//---------------------------------------------------------------------------

const wchar_t *TFormHang::TMsgStrings::_Msg_Chs[MsgCount] =
{
  L"挂机"                , //MsgHang
  L"正在挂机, 请稍候……", //MsgHanging
};
//---------------------------------------------------------------------------

const wchar_t *TFormHang::TMsgStrings::_Msg_Cht[MsgCount] =
{
  L"掛機"                , //MsgHang
  L"正在掛機, 請稍候……", //MsgHanging
};

const wchar_t *TFormHang::TMsgStrings::_Msg_Enu[MsgCount] =
{
  L"Hang"                   , //MsgHang
  L"Hanging, please wait...", //MsgHanging
};
//---------------------------------------------------------------------------

int RunDialogHang(TComponent* Owner, TComm32 *lpModem, int Retries)
{
  FormHang = new TFormHang(Owner);
  int iRetVal = FormHang->Hang(lpModem, Retries);
  delete FormHang;
  return iRetVal;
}
//---------------------------------------------------------------------------
