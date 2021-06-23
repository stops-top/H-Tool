//---------------------------------------------------------------------------
// 控件演示程序，Copyright © Victor Chen, www.cppfans.com

#ifndef UnitHangH
#define UnitHangH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include "TVictorComm32.h"
//---------------------------------------------------------------------------
class TFormHang : public TForm
{
__published:	// IDE-managed Components
    TLabel *LabelPrompt;
    TTimer *TimerHang;
    TImage *Image1;
    void __fastcall TimerHangTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFormHang(TComponent* Owner);
    __fastcall ~TFormHang();

    int  __fastcall Hang(TComm32 *lpModem, int Retries);
    void __fastcall DoHangProc(void);
    void __fastcall CheckResult(void);
    void __fastcall FinalOK(void);
    void __fastcall FinalError(void);
protected:
    TComm32 *Modem;
    int iWhatToDo, iRetryTimes, iTotalRetries, iCloseDelay;
private:
    class TMsgStrings
     {
       public:
         enum TMsgType
          {
            MsgHang    = 0, //"挂机"
            MsgHanging = 1, //"正在挂机, 请稍候……"
            MsgCount   = 2, //=count=
          };

         __fastcall TMsgStrings();
         __property UnicodeString Msg[TMsgType] = { read = fGetMsg };

       private:
         UnicodeString __fastcall fGetMsg(TMsgType mt);

         const wchar_t **_Msg;
         static const wchar_t *_Msg_Chs[MsgCount];
         static const wchar_t *_Msg_Cht[MsgCount];
         static const wchar_t *_Msg_Enu[MsgCount];
     };
};
//---------------------------------------------------------------------------
extern PACKAGE TFormHang *FormHang;
extern int RunDialogHang(TComponent* Owner, TComm32 *lpModem, int Retries=3);
//---------------------------------------------------------------------------
#endif
