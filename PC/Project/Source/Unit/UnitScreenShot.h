//---------------------------------------------------------------------------

#ifndef UnitScreenShotH
#define UnitScreenShotH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFormScreenShot : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormScreenShot(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormScreenShot *FormScreenShot;
//---------------------------------------------------------------------------
#endif
