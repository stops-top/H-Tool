//---------------------------------------------------------------------------
// 串口控件演示程序，Copyright © Victor Chen

#ifndef UnitSendFileH
#define UnitSendFileH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "YbCommDevice.h"
#include <ActnList.hpp>
#include <StdActns.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include "UnitTsData.h"
#include <mmsystem.h>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TYbCommDevice *YbCommDevice1;
    TActionList *ActionList1;
    TFileOpen *FileOpen1;
    TBitBtn *BitBtn1;
    TProgressBar *ProgressBar1;
    TTimer *Timer1;
    TMemo *Memo1;
    TButton *ButtonSet;
    void __fastcall FileOpen1Accept(TObject *Sender);
    void __fastcall YbCommDevice1Package(TObject *Sender, int NotifyType);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall ButtonSetClick(TObject *Sender);
private:	// User declarations
    UnicodeString dlpath;
    HANDLE hsf, hdf;
    bool bUploading;
    unsigned char PkgID;
    long nSendFileSize;
    long nBytesToReceive, iReceivingCounter;
    TDateTime dtReceiveFileTime;
    void __fastcall ShowInfo(UnicodeString s);
    int __fastcall UploadReq(UnicodeString fname);
    int __fastcall UploadFileData(void);
    int __fastcall WaitforAnswer(unsigned char Cmd, unsigned char id);
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
