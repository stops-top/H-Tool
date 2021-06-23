//---------------------------------------------------------------------------
// 控件演示程序，Copyright © Victor Chen, www.cppfans.com

#ifndef UnitDialH
#define UnitDialH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <Buttons.hpp>
#include "TVictorComm32.h"
#include <ComCtrls.hpp>
#include <ActnList.hpp>
#include <StdActns.hpp>
#include <Menus.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFormDial : public TForm
{
__published:	// IDE-managed Components
    TImageList *ImageListIcons;
    TPaintBox *PaintBoxIcon;
    TTimer *TimerDial;
    TBitBtn *BnCancel;
    TBevel *Bevel1;
    TLabel *LabelDialPrompt;
    TLabel *LabelNumPrompt;
    TLabel *LabelNumber;
    TRichEdit *reStatus;
    TLabel *LabelPlace;
    TActionList *ActionListDial;
    TEditCopy *EditCopy1;
    TEditSelectAll *EditSelectAll1;
    TPopupMenu *PopupMenuReStatus;
    TMenuItem *Copy1;
    TMenuItem *SelectAll1;
    TImageList *ImageListMenu;
    TImage *ImageExit;
    void __fastcall PaintBoxIconPaint(TObject *Sender);
    void __fastcall TimerDialTimer(TObject *Sender);
    void __fastcall BnCancelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFormDial(TComponent* Owner);
    __fastcall ~TFormDial();
    int __fastcall Dial(TComm32 *lpModem, UnicodeString Number, UnicodeString ToPlace, int Retries); //IDOK/IDNO/IDCANCEL
    bool CloseOnError;
protected:
    void __fastcall DoDialProc(void);
    void __fastcall DisplayRetries(void);
    void __fastcall PrepareToDial(void);
    void __fastcall DialModem(void);
    void __fastcall CheckResult(void);
    void __fastcall FinalOK(void);
    void __fastcall FinalError(void);
    void __fastcall AddMessage(UnicodeString s, TColor c);

    void __fastcall DetectModem(void);
    void __fastcall CheckModem(void);

    TComm32 *Modem;
    UnicodeString DialNumber;
    int iIconCounter, iRetryTimes, iWhatToDo, iTotalRetries, iCloseDelay, iDetectModem, iConnected;

    int iResultBytes;
    char ResultBuffer[256];
private:
    class TMsgStrings
     {
       public:
         enum TMsgType
          {
            MsgOK          =  0, //"确定"
            MsgCancel      =  1, //"取消"
            MsgClose       =  2, //"关闭"
            FmtTries       =  3, //"第 %d 次试拨, 共 %d 次"
            MsgPrepare     =  4, //"正在准备拨号"
            MsgDialing     =  5, //"正在拨号"
            MsgBusy        =  6, //"线路忙(占线)"
            MsgNoTone      =  7, //"没有拨号音"
            MsgNoCarrier   =  8, //"无法联接(掉线)"
            MsgExecError   =  9, //"调制解调器执行命令错误"
            MsgNoExponse   = 10, //"没有响应"
            MsgCannotCnt   = 11, //"无法连接到对方电脑"
            MsgPhoneNum    = 12, //"电话号码"
            MsgDial        = 13, //"拨号"
            MsgCopy        = 14, //"复制"
            MsgSelectAll   = 15, //"全选"
            MnuCopy        = 16, //"复制(&C)"
            MnuSelectAll   = 17, //"全选(&A)"
            MsgDetectMdm   = 18, //"正在检测调制解调器"
            MsgDetectErr   = 19, //"不能检测到调制解调器或者调制解调器电源未开"
            MsgCompatible  = 20, //"调制解调器执行命令错误，或者调制解调器指令不兼容"
            MsgDialWithErr = 21, //"继续试验执行拨号指令"
            MsgCount       = 22, //=count=
          };

         __fastcall TMsgStrings();
         __property UnicodeString Msg[TMsgType] = { read = fGetMsg };

       private:
         UnicodeString __fastcall fGetMsg(TMsgType mt);

         const wchar_t **_Msg;
         const static wchar_t *_Msg_Chs[MsgCount];
         const static wchar_t *_Msg_Cht[MsgCount];
         const static wchar_t *_Msg_Enu[MsgCount];
     };
};
//---------------------------------------------------------------------------
extern PACKAGE TFormDial *FormDial; //IDOK 成功, IDNO 失败, IDCANCEL 取消
extern int RunDialogDial(TComponent* Owner, TComm32 *lpModem, UnicodeString Number, UnicodeString ToPlace, int Retries=3);
//---------------------------------------------------------------------------
#endif
