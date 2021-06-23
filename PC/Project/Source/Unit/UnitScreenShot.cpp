//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <IniFiles.hpp>
#include "UnitProg.h"
#include "UnitMain.h"
#include "UnitThread.h"
#include "UnitLua.h"
#include "UnitSet.h"
#include "UnitScreenShot.h"
#include "lua_if.h"
#include "file_lib.h"
#include "hex2bin.h"
#include "bsp.h"
#include "bsp_udp_modbus.h"
#include "bsp_user_lib.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormScreenShot *FormScreenShot;
//---------------------------------------------------------------------------
__fastcall TFormScreenShot::TFormScreenShot(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormScreenShot::Button1Click(TObject *Sender)
{
	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	Form1->MemoLuaOut->Lines->Add("截屏...");

	/* 通知线程开始传输 */
	g_tCmd.UserCmdStatus = CMDS_READ_SCREEN;
	g_tCmd.UserReq = 1;
}
//---------------------------------------------------------------------------
void __fastcall TFormScreenShot::Button2Click(TObject *Sender)
{
//   int i_Width  = 600 ;
//   int i_Height = 600  ;
//   Graphics::TBitmap *Bitmap = new Graphics::TBitmap;
//   Graphics::TBitmap *Bit = new Graphics::TBitmap;
//   TRect  MyRect     =  Rect(0,0,i_Width,i_Height);
//   TRect  MyOther    =  Rect(0,0,i_Width,i_Height);
//   Bit->Width = i_Width ;
//   Bit->Height = i_Height ;
//   Bitmap->Width  = Image1->Width;
//   Bitmap->Height = Image1->Height;
//   Bitmap->Assign(Image1->Picture->Graphic);
//   Bit->Canvas->CopyRect(MyOther,Bitmap->Canvas,MyRect);
//   Bit->SaveToFile("D://3860.bmp")  ;
//   delete  Bitmap ;
//   delete Bit ;
}
//---------------------------------------------------------------------------

