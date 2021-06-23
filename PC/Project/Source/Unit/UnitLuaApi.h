//---------------------------------------------------------------------------

#ifndef UnitLuaApiH
#define UnitLuaApiH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormLuaApi : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *GPIO;
	TMemo *Memo11;
	TComboBox *ComboBoxStringFunc;
	TGroupBox *GroupBox1;
	TLabel *Label3;
	TComboBox *ComboBoxAiCh;
	TButton *Button3;
	TButton *ButtonReadAdc;
	TButton *Button1;
	TButton *Button2;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TEdit *EditTVCC;
	TLabel *Label1;
	TEdit *EditMV;
	TLabel *Label2;
	TEdit *EditUA;
	TLabel *Label4;
	TCheckBox *CheckBoxClear;
	TMemo *MemoTemp;
	TButton *Button8;
	TComboBox *ComboBoxGpioMode;
	TLabel *Label5;
	TComboBox *ComboBoxGpioId;
	TLabel *Label6;
	TButton *Button9;
	TButton *Button10;
	TButton *Button11;
	TButton *Button12;
	TLabel *Label7;
	TRichEdit *Memo1;
	TButton *Button13;
	TButton *Button14;
	TButton *Button15;
	TButton *Button16;
	TButton *Button17;
	TTabSheet *GUI;
	TColorDialog *ColorDialog1;
	TButton *Button18;
	TEdit *EditColorRGB;
	TEdit *EditColorHex;
	TButton *Button19;
	TButton *Button20;
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall ButtonReadAdcClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall ComboBoxStringFuncClick(TObject *Sender);
	void __fastcall Button13Click(TObject *Sender);
	void __fastcall Button14Click(TObject *Sender);
	void __fastcall Button15Click(TObject *Sender);
	void __fastcall Button16Click(TObject *Sender);
	void __fastcall Button17Click(TObject *Sender);
	void __fastcall Button18Click(TObject *Sender);
	void __fastcall Button19Click(TObject *Sender);
	void __fastcall Button20Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormLuaApi(TComponent* Owner);
	void __fastcall TFormLuaApi::AddLuaSrc(AnsiString str);
	void __fastcall TFormLuaApi::AddLuaSrc0(AnsiString str);
	void __fastcall TFormLuaApi::AddLuaToMemo(AnsiString str);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormLuaApi *FormLuaApi;
//---------------------------------------------------------------------------
#endif
