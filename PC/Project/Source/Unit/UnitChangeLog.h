//---------------------------------------------------------------------------

#ifndef UnitChangeLogH
#define UnitChangeLogH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFormChangeLog : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TRichEdit *Memo1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormChangeLog(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormChangeLog *FormChangeLog;
//---------------------------------------------------------------------------
#endif
