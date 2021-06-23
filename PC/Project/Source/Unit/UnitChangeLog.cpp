//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitChangeLog.h"
#include "file_lib.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormChangeLog *FormChangeLog;
//---------------------------------------------------------------------------
__fastcall TFormChangeLog::TFormChangeLog(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormChangeLog::FormCreate(TObject *Sender)
{
	AnsiString s1;

	s1 = AppExePath() + "\\ChangeLog.txt";

	Memo1->Lines->LoadFromFile(s1);
}
//---------------------------------------------------------------------------

void __fastcall TFormChangeLog::Button1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
