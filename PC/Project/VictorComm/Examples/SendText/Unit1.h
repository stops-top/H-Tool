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
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TMemo *Memo1;
    TButton *ButtonSend1;
    TButton *ButtonSet1;
    TTimer *Timer1;
    TYbCommDevice *YbCommDevice1;
    TButton *ButtonClear;
	TPanel *PanelTextEncoding;
	TRadioButton *RadioBtnUTF8;
	TRadioButton *RadioBtnANSI;
    void __fastcall ButtonSet1Click(TObject *Sender);
    void __fastcall ButtonSend1Click(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall ButtonClearClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 