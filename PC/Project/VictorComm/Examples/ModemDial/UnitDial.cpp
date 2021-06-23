//---------------------------------------------------------------------------
// 控件演示程序，Copyright © Victor Chen, www.cppfans.com

#include <vcl.h>
#pragma hdrstop

#include "UnitDial.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormDial *FormDial;
//---------------------------------------------------------------------------
__fastcall TFormDial::TFormDial(TComponent* Owner)
    : TForm(Owner)
{
  Modem = 0;
  iRetryTimes = 0;
  iIconCounter = 0;
  iTotalRetries = 0;
  iCloseDelay = 20; // 20 * TimerInterval = 5 (s)
  iWhatToDo = 0;
  iDetectModem = 3;
  iConnected = 0;
  iResultBytes = 0;
  CloseOnError = false;
  DoubleBuffered = true;

  TMsgStrings Msgs;
  Caption = Msgs.Msg[TMsgStrings::MsgDial]; //"拨号"
  LabelDialPrompt->Caption = Msgs.Msg[TMsgStrings::MsgDialing  ]+":"; //"正在拨号"
  LabelNumPrompt ->Caption = Msgs.Msg[TMsgStrings::MsgPhoneNum ]+":"; //"电话号码"
  EditCopy1      ->Caption = Msgs.Msg[TMsgStrings::MnuCopy     ];     //"复制(&C)"
  EditSelectAll1 ->Caption = Msgs.Msg[TMsgStrings::MnuSelectAll];     //"全选(&A)"
  EditCopy1      ->Hint    = Msgs.Msg[TMsgStrings::MsgCopy     ];     //"复制"
  EditSelectAll1 ->Hint    = Msgs.Msg[TMsgStrings::MsgSelectAll];     //"全选"
  BnCancel       ->Caption = Msgs.Msg[TMsgStrings::MsgCancel   ];     //"取消"
}
//---------------------------------------------------------------------------
__fastcall TFormDial::~TFormDial()
{
  if(Modem)
   {
     if((Modem->ModemStatus & MS_RLSD_ON) == 0)
       Modem->Command("ATH0\r");
   }
}
//---------------------------------------------------------------------------
#pragma argsused // 不使用 Sender 参数
void __fastcall TFormDial::PaintBoxIconPaint(TObject *Sender)
{
  ImageListIcons->Draw(PaintBoxIcon->Canvas, 0,0, iIconCounter, true);
}
//---------------------------------------------------------------------------
#pragma argsused // 不使用 Sender 参数
void __fastcall TFormDial::TimerDialTimer(TObject *Sender)
{
  if(Modem)
   {
     if(iDetectModem)
      {
        DetectModem();
      }
     else if((Modem->ModemStatus & MS_RLSD_ON)&&(iConnected))
      {
        FinalOK();
      }
     else if(iRetryTimes>0)
      {
        DoDialProc();
      }
     else
      {
        FinalError();
      }
   }

  if(++iIconCounter>=6)
    iIconCounter = 0;
  PaintBoxIcon->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TFormDial::DetectModem(void)
{
  switch(iWhatToDo)
   {
     case 0: AddMessage(TMsgStrings().Msg[TMsgStrings::MsgDetectMdm],clBlue);
             break;

     case 1: Modem->PurgeRead();
             Modem->PurgeWrite();
             iResultBytes = 0;
             break;

     case 3: Modem->InitModem();
             break;
   }
  CheckModem();
}
//---------------------------------------------------------------------------

void __fastcall TFormDial::CheckModem(void)
{
  if(iWhatToDo>5)
   {
     char c;
     while(Modem->Read(&c,1))
      {
        if((c==0x0d)||(c==0x0a)||(c==0x00)) //end of message
         {
           iResultBytes = 0;
           ResultBuffer[iResultBytes] = 0;
         }
        else
         {
           if(iResultBytes>=200)
            {
              memcpy(ResultBuffer, ResultBuffer+iResultBytes-32, 32);
              iResultBytes = 32;
            }

           ResultBuffer[iResultBytes++] = toupper(c);
           ResultBuffer[iResultBytes] = 0;

           if(strstr(ResultBuffer,"OK"))
            {
              AddMessage("------------------------------",clBlack);
              iWhatToDo = 0;
              iDetectModem = 0;
              return;
            }

           if(strstr(ResultBuffer,"ERROR"))
            {
              AddMessage(TMsgStrings().Msg[TMsgStrings::MsgCompatible],clFuchsia);
              AddMessage("------------------------------",clBlack);
              iWhatToDo = 0;

              if(--iDetectModem==0)
               {
                 AddMessage(TMsgStrings().Msg[TMsgStrings::MsgDialWithErr],clRed);
                 AddMessage("------------------------------",clBlack);
               }
              return;
            }
         }
      }
   }
  if(++iWhatToDo>32)
   {
     AddMessage(TMsgStrings().Msg[TMsgStrings::MsgDetectErr],clFuchsia);
     iDetectModem--;
     iWhatToDo = 0;

     if(!iDetectModem)
       iRetryTimes = 0;
     else
       AddMessage("------------------------------",clBlack);
   }
}
//---------------------------------------------------------------------------

void __fastcall TFormDial::DoDialProc(void)
{
  switch(iWhatToDo)
   {
     case  0: DisplayRetries(); break;
     case  1: PrepareToDial(); break;
     case  6: DialModem(); break;
   }
  CheckResult();
}
//---------------------------------------------------------------------------

void __fastcall TFormDial::DisplayRetries(void)
{
  if(iRetryTimes!=iTotalRetries)
    AddMessage("------------------------------",clBlack);
  UnicodeString s; //"第 %d 次试拨, 共 %d 次"
  s.sprintf(TMsgStrings().Msg[TMsgStrings::FmtTries].w_str(), iTotalRetries-iRetryTimes+1, iTotalRetries);
  AddMessage(s,clBlue);
}
//---------------------------------------------------------------------------

void __fastcall TFormDial::PrepareToDial(void)
{
  AddMessage(TMsgStrings().Msg[TMsgStrings::MsgPrepare], clBlack); //"正在准备拨号"
  Modem->PurgeRead();
  Modem->PurgeWrite();
  iResultBytes = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFormDial::DialModem(void)
{
  AddMessage(TMsgStrings().Msg[TMsgStrings::MsgDialing], clGreen); //"正在拨号"
  AnsiString cmd = "ATDT" + DialNumber + "\r"; // MODEM 使用 ASCII 指令，非 UNICODE
  Modem->Command(cmd.c_str());
}
//---------------------------------------------------------------------------

void __fastcall TFormDial::CheckResult(void)
{
  if(iWhatToDo>10)
   {
     char c;
     while(Modem->Read(&c,1))
      {
        if((c==0x0d)||(c==0x0a)||(c==0x00)) //end of message
         {
           iResultBytes = 0;
           ResultBuffer[iResultBytes] = 0;
         }
        else
         {
           if(iResultBytes>=200)
            {
              memcpy(ResultBuffer, ResultBuffer+iResultBytes-32, 32);
              iResultBytes = 32;
            }

           ResultBuffer[iResultBytes++] = toupper(c);
           ResultBuffer[iResultBytes] = 0;

           if(strstr(ResultBuffer,"CONNECT"))
            {
              iConnected = 1; //连接成功
              return;
            }

           if(strstr(ResultBuffer,"BUSY"))
            {
              iWhatToDo = 0;
              iRetryTimes--;
              AddMessage(TMsgStrings().Msg[TMsgStrings::MsgBusy], clFuchsia); //"线路忙(占线)"
              return;
            }

           if(strstr(ResultBuffer,"NO DIALTONE"))
            {
              iWhatToDo = 0;
              iRetryTimes--;
              AddMessage(TMsgStrings().Msg[TMsgStrings::MsgNoTone], clFuchsia); //"没有拨号音"
              return;
            }

           if(strstr(ResultBuffer,"NO CARRIER"))
            {
              iWhatToDo = 0;
              iRetryTimes--;
              AddMessage(TMsgStrings().Msg[TMsgStrings::MsgNoCarrier], clFuchsia); //"无法联接(掉线)"
              return;
            }

           if(strstr(ResultBuffer,"ERROR"))
            {
              iWhatToDo = 0;
              iRetryTimes--;
              AddMessage(TMsgStrings().Msg[TMsgStrings::MsgExecError], clFuchsia); //"调制解调器执行命令错误"
              return;
            }
         }
      }
   }

  if(++iWhatToDo>200) // 200 * TimerInterval / 1000 = 50 (s)
   {
     iWhatToDo = 0;
     iRetryTimes--;
     AddMessage(TMsgStrings().Msg[TMsgStrings::MsgNoExponse], clFuchsia); //"没有响应"
     Modem->Command("ATH0\r"); //取消拨号指令
   }
}
//---------------------------------------------------------------------------

void __fastcall TFormDial::FinalOK(void)
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

void __fastcall TFormDial::FinalError(void)
{
  if(iWhatToDo==0)
   {
     AddMessage("------------------------------",clBlack);
     AddMessage(TMsgStrings().Msg[TMsgStrings::MsgCannotCnt], clRed); //"无法连接到对方电脑"
     AddMessage("------------------------------",clBlack);

     try
      {
        BnCancel->Caption = TMsgStrings().Msg[TMsgStrings::MsgClose]; //"关闭"
        BnCancel->Glyph->Assign(ImageExit->Picture);
        BnCancel->NumGlyphs = 1;
      }
     catch(...)
      {
        //do nothing
      }
   }

  if(iWhatToDo<32)
   {
     iWhatToDo++;
   }

  if((iWhatToDo>8) && (CloseOnError))
   {
     ModalResult = IDNO;
   }
}
//---------------------------------------------------------------------------

void __fastcall TFormDial::AddMessage(UnicodeString s, TColor c)
{
  reStatus->SelStart = reStatus->Text.Length();
  reStatus->SelLength = 0;
  reStatus->SelAttributes->Name    = Font->Name;
  reStatus->SelAttributes->Charset = Font->Charset;
  reStatus->SelAttributes->Size    = Font->Size;
  reStatus->SelAttributes->Color   = c;
  reStatus->Lines->Add(s);
}
//---------------------------------------------------------------------------

int __fastcall TFormDial::Dial(TComm32 *lpModem, UnicodeString Number, UnicodeString ToPlace, int Retries)
{
  iWhatToDo = 0;
  iTotalRetries = Retries>0?Retries:1;
  iRetryTimes = iTotalRetries;
  DialNumber = Number;
  LabelNumber->Caption = Number;
  LabelPlace->Caption = ToPlace;

  Modem = lpModem;
  Modem->DisableWrite = true;
  int iRetVal = ShowModal();
  Modem->DisableWrite = false;
  return iRetVal;
}
//---------------------------------------------------------------------------
#pragma argsused // 不使用 Sender 参数
void __fastcall TFormDial::BnCancelClick(TObject *Sender)
{
  ModalResult = iRetryTimes ? IDCANCEL : IDNO;
}
//---------------------------------------------------------------------------

__fastcall TFormDial::TMsgStrings::TMsgStrings()
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

UnicodeString __fastcall TFormDial::TMsgStrings::fGetMsg(TMsgType mt)
{
  if(mt>=0 && mt<MsgCount)
    return _Msg[mt];
  return L"";
}
//---------------------------------------------------------------------------

const wchar_t *TFormDial::TMsgStrings::_Msg_Chs[MsgCount] =
{
  L"确定"                  , //MsgOK
  L"取消"                  , //MsgCancel
  L"关闭"                  , //MsgClose
  L"第 %d 次试拨, 共 %d 次", //FmtTries
  L"正在准备拨号"          , //MsgPrepare
  L"正在拨号"              , //MsgDialing
  L"线路忙(占线)"          , //MsgBusy
  L"没有拨号音"            , //MsgNoTone
  L"无法连接(掉线)"        , //MsgNoCarrier
  L"调制解调器执行命令错误", //MsgExecError
  L"没有响应"              , //MsgNoExponse
  L"无法连接到对方电脑"    , //MsgCannotCnt
  L"电话号码"              , //MsgPhoneNum
  L"拨号"                  , //MsgDial
  L"复制"                  , //MsgCopy
  L"全选"                  , //MsgSelectAll
  L"复制(&C)"              , //MnuCopy
  L"全选(&A)"              , //MnuSelectAll
  L"正在检测调制解调器"    , //MsgDetectMdm
  L"不能检测到调制解调器或者调制解调器电源未开"      , //MsgDetectErr
  L"调制解调器执行命令错误，或者调制解调器指令不兼容", //MsgCompatible
  L"继续试验执行拨号指令……"                        , //MsgDialWithErr
};
//---------------------------------------------------------------------------

const wchar_t *TFormDial::TMsgStrings::_Msg_Cht[MsgCount] =
{
  L"確定"                  , //MsgOK
  L"取消"                  , //MsgCancel
  L"關閉"                  , //MsgClose
  L"第 %d 次試撥, 共 %d 次", //FmtTries
  L"正在準備撥號"          , //MsgPrepare
  L"正在撥號"              , //MsgDialing
  L"線路忙(占線)"          , //MsgBusy
  L"沒有撥號音"            , //MsgNoTone
  L"無法連接(掉線)"        , //MsgNoCarrier
  L"數據機執行命令錯誤"    , //MsgExecError
  L"沒有回應"              , //MsgNoExponse
  L"無法連接到對方電腦"    , //MsgCannotCnt
  L"電話號碼"              , //MsgPhoneNum
  L"撥號"                  , //MsgDial
  L"複製"                  , //MsgCopy
  L"全選"                  , //MsgSelectAll
  L"複製(&C)"              , //MnuCopy
  L"全選(&A)"              , //MnuSelectAll
  L"正在檢測數據機"        , //MsgDetectMdm
  L"不能檢測到數據機或者數據機電源未開"      , //MsgDetectErr
  L"數據機執行命令錯誤，或者數據機指令不相容", //MsgCompatible
  L"繼續試驗執行撥號指令……"                , //MsgDialWithErr
};
//---------------------------------------------------------------------------

const wchar_t *TFormDial::TMsgStrings::_Msg_Enu[MsgCount] =
{
  L"OK"                    , //MsgOK
  L"Cancel"                , //MsgCancel
  L"Close"                 , //MsgClose
  L"Dial %d of %d"         , //FmtTries
  L"Preparing dial"        , //MsgPrepare
  L"Dialing"               , //MsgDialing
  L"Busy"                  , //MsgBusy
  L"No dial tone"          , //MsgNoTone
  L"No carrier"            , //MsgNoCarrier
  L"Execute command error" , //MsgExecError
  L"No answer"             , //MsgNoExponse
  L"Cannot connect to the destination computer", //MsgCannotCnt
  L"Tel. No."              , //MsgPhoneNum
  L"Dial"                  , //MsgDial
  L"Copy"                  , //MsgCopy
  L"Select All"            , //MsgSelectAll
  L"&Copy"                 , //MnuCopy
  L"Select &All"           , //MnuSelectAll
  L"Checking Modem"        , //MsgDetectMdm
  L"Cannot detect modem or modem is power off"   , //MsgDetectErr
  L"Modem execute command error, or incompatible", //MsgCompatible
  L"Continue to try dialing..."                  , //MsgDialWithErr
};
//---------------------------------------------------------------------------

int RunDialogDial(TComponent* Owner, TComm32 *lpModem, UnicodeString Number, UnicodeString ToPlace, int Retries)
{
  FormDial = new TFormDial(Owner);
  int iRetVal = FormDial->Dial(lpModem, Number, ToPlace, Retries);
  delete FormDial;
  return iRetVal;
}
//---------------------------------------------------------------------------
