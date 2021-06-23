//---------------------------------------------------------------------------
// 控件演示程序，Copyright © Victor Chen

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "YbCommDevice.h"
#include <ExtCtrls.hpp>
#include <stdio.h>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TYbCommDevice *YbCommDevice1;
    TButton *ButtonSend;
    TButton *ButtonSet;
    TMemo *Memo1;
    void __fastcall ButtonSetClick(TObject *Sender);
    void __fastcall ButtonSendClick(TObject *Sender);
    void __fastcall YbCommDevice1Package(TObject *Sender, int NotifyType);
private:	// User declarations
    FILE *FileReceived;
    long ReceivedFileSize;
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 