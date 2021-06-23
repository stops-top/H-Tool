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
    TButton *ButtonSend1;
    TYbCommDevice *YbCommDevice1;
    TButton *ButtonSet1;
    TEdit *Edit1;
    TLabel *Label1;
    TLabel *Label3;
    TMemo *Memo1;
    void __fastcall ButtonSet1Click(TObject *Sender);
    void __fastcall ButtonSend1Click(TObject *Sender);
    void __fastcall YbCommDevice1CommNotify(TObject *Sender,
          int NotifyType);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 