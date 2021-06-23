//---------------------------------------------------------------------------

#ifndef UnitRTTH
#define UnitRTTH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFormRTT : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonStartRTT;
	TComboBox *ComboBoxTerID;
	TButton *ButtonLeft;
	TButton *ButtonRight;
	TRichEdit *RichEdit1;
	TMemo *Memo1;
	TButton *ButtonSend;
	TCheckBox *CheckBoxAuto;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TComboBox *ComboBox1;
	TLabel *Label1;
	TButton *Button1;
	TCheckBox *CheckBox4;
	void __fastcall ButtonRightClick(TObject *Sender);
	void __fastcall ButtonLeftClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormRTT(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormRTT *FormRTT;
//---------------------------------------------------------------------------
#endif
