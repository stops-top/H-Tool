//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitRTT.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormRTT *FormRTT;
//---------------------------------------------------------------------------
__fastcall TFormRTT::TFormRTT(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormRTT::ButtonRightClick(TObject *Sender)
{
	if (ComboBoxTerID->ItemIndex < 15)
	{
		ComboBoxTerID->ItemIndex++;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormRTT::ButtonLeftClick(TObject *Sender)
{
	if (ComboBoxTerID->ItemIndex > 0)
	{
		ComboBoxTerID->ItemIndex--;
	}
}
//---------------------------------------------------------------------------

