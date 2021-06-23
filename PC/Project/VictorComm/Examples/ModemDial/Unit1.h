//---------------------------------------------------------------------------
// 控件演示程序，Copyright © Victor Chen, www.cppfans.com

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
    TButton *ButtonSend1;
    TYbCommDevice *YbCommDevice1;
    TButton *ButtonSet1;
    TTimer *Timer1;
    TEdit *Edit1;
    TLabel *Label1;
    TLabel *Label3;
    TMemo *Memo1;
    TButton *Button1;
    TButton *Button2;
    TEdit *Edit2;
    TLabel *Label2;
    void __fastcall ButtonSet1Click(TObject *Sender);
    void __fastcall ButtonSend1Click(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall YbCommDevice1AfterOpen(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 