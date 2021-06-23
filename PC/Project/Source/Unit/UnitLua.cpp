//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <IniFiles.hpp>
#include "UnitLua.h"
#include "UnitProg.h"
#include "UnitMain.h"
#include "UnitThread.h"
#include "UnitUSBBus.h"
#include "UnitSet.h"
#include "lua_if.h"
#include "file_lib.h"
#include "hex2bin.h"
#include "bsp.h"
#include "bsp_udp_modbus.h"
#include "bsp_user_lib.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormLua *FormLua;
//---------------------------------------------------------------------------
__fastcall TFormLua::TFormLua(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TFormLua::FormCreate(TObject *Sender)
{
	bsp_AddLog("FormLua Create Begin");

	// 读取ini配置文件
	{
		TIniFile *ini;
		int radio;
		AnsiString s1;
		int temp;

		s1 = AppExePath() + "\\app.ini";
		ini = new TIniFile(s1);

		// 解析ini文件
		FormLua->RichEditFileName->Text = ini->ReadString("Lua", "FileName1", "");
		FormLua->EditLua1->Text = ini->ReadString("Lua", "LuaCmd1", "test_gpio()");
		FormLua->EditLua2->Text = ini->ReadString("Lua", "LuaCmd2", "test_ledout()");
		FormLua->EditLua3->Text = ini->ReadString("Lua", "LuaCmd3", "test_swd()");
		FormLua->EditLua4->Text = ini->ReadString("Lua", "LuaCmd4", "test_analog()");
		FormLua->EditLua5->Text = ini->ReadString("Lua", "LuaCmd5", "test_func5()");
		FormLua->EditLua6->Text = ini->ReadString("Lua", "LuaCmd6", "test_func6()");
		FormLua->EditLua7->Text = ini->ReadString("Lua", "LuaCmd7", "test_func7()");
		FormLua->EditLua8->Text = ini->ReadString("Lua", "LuaCmd8", "test_func8()");
		FormLua->EditLua9->Text = ini->ReadString("Lua", "LuaCmd9", "");
		FormLua->EditLua10->Text = ini->ReadString("Lua", "LuaCmd10", "");
		FormLua->EditLua11->Text = ini->ReadString("Lua", "LuaCmd11", "");
		FormLua->EditLua12->Text = ini->ReadString("Lua", "LuaCmd12", "");
		FormLua->EditLua13->Text = ini->ReadString("Lua", "LuaCmd13", "");
		FormLua->EditLua14->Text = ini->ReadString("Lua", "LuaCmd14", "");
		FormLua->EditLua15->Text = ini->ReadString("Lua", "LuaCmd15", "");
		FormLua->EditLua16->Text = ini->ReadString("Lua", "LuaCmd16", "");

		FormLua->EditLuaNote1->Text = ini->ReadString("Lua", "LuaNote1", "test_gpio()");
		FormLua->EditLuaNote2->Text = ini->ReadString("Lua", "LuaNote2", "test_ledout()");
		FormLua->EditLuaNote3->Text = ini->ReadString("Lua", "LuaNote3", "test_swd()");
		FormLua->EditLuaNote4->Text = ini->ReadString("Lua", "LuaNote4", "test_analog()");
		FormLua->EditLuaNote5->Text = ini->ReadString("Lua", "LuaNote5", "test_func5()");
		FormLua->EditLuaNote6->Text = ini->ReadString("Lua", "LuaNote6", "test_func6()");
		FormLua->EditLuaNote7->Text = ini->ReadString("Lua", "LuaNote7", "test_func7()");
		FormLua->EditLuaNote8->Text = ini->ReadString("Lua", "LuaNote8", "test_func8()");
		FormLua->EditLuaNote9->Text = ini->ReadString("Lua", "LuaNote9", "");
		FormLua->EditLuaNote10->Text = ini->ReadString("Lua", "LuaNote10", "");
		FormLua->EditLuaNote11->Text = ini->ReadString("Lua", "LuaNote11", "");
		FormLua->EditLuaNote12->Text = ini->ReadString("Lua", "LuaNote12", "");
		FormLua->EditLuaNote13->Text = ini->ReadString("Lua", "LuaNote13", "");
		FormLua->EditLuaNote14->Text = ini->ReadString("Lua", "LuaNote14", "");
		FormLua->EditLuaNote15->Text = ini->ReadString("Lua", "LuaNote15", "");
		FormLua->EditLuaNote16->Text = ini->ReadString("Lua", "LuaNote16", "");

		delete  ini;

		{
			s1 = AppExePath() + "\\LuaUser1.lua";
			if (FileExists(s1))
			{
				FormLua->MemoLuaTemp1->Lines->LoadFromFile(s1);
			}
			s1 = AppExePath() + "\\LuaUser2.lua";
			if (FileExists(s1))
			{
				FormLua->MemoLuaTemp2->Lines->LoadFromFile(s1);
			}
			s1 = AppExePath() + "\\LuaUser3.lua";
			if (FileExists(s1))
			{
				FormLua->MemoLuaTemp3->Lines->LoadFromFile(s1);
			}
			s1 = AppExePath() + "\\LuaUser4.lua";
			if (FileExists(s1))
			{
				FormLua->MemoLuaTemp4->Lines->LoadFromFile(s1);
			}
			s1 = AppExePath() + "\\LuaUser5.lua";
			if (FileExists(s1))
			{
				FormLua->MemoLuaTemp5->Lines->LoadFromFile(s1);
			}
			s1 = AppExePath() + "\\LuaUser6.lua";
			if (FileExists(s1))
			{
				FormLua->MemoLuaTemp6->Lines->LoadFromFile(s1);
			}
		}
	}

	bsp_AddLog("FormLua Create End");
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TFormLua::Button32Click(TObject *Sender)
{
	int iFileHandle;
	int iBytesRead;
	int iFileLength;

	Form1->OpenDialog1->Filter = "*.lua";
	if (Form1->OpenDialog1->Execute())
	{
		iFileHandle = FileOpen(Form1->OpenDialog1->FileName, fmOpenRead);
		if (iFileHandle > 0)
		{
			  iFileLength = FileSeek(iFileHandle, 0, 2);

			  if (iFileLength <= 32 * 1024)
			  {
					//moFileName->Clear();
					//moFileName->Lines->Add(OpenDialog1->FileName);
					RichEditFileName->Text = Form1->OpenDialog1->FileName;
					FileClose(iFileHandle);

					MemoLua->Lines->LoadFromFile(Form1->OpenDialog1->FileName);

//					RichEditFileName->SelStart =  RichEditFileName->Text.Length();
//					RichEditFileName->SelLength =  RichEditFileName->Text.Length();

//					SendMessage(RichEditFileName->Handle ,WM_KEYDOWN, VK_RIGHT, 0);
			  }
			  else
			  {
					FileClose(iFileHandle);
					ShowMessage("文件过大(>32K)");
			  }
		}
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormLua::ButtonDownLuaFileClick(TObject *Sender)
{
//	if (FormSet->ComboBoxCommMode->ItemIndex != 0)
//	{
//		Form1->MemoLuaOut->Lines->Add("lua功能仅支持以太网连接模式");
//		return;
//	}

	/* 打开文件, 读文件数据 */
	{
		int iFileHandle;
		int iBytesRead;
		int iFileLength;

		iFileHandle = FileOpen(RichEditFileName->Text, fmOpenRead);
		if (iFileHandle > 0)
		{
			iFileLength = FileSeek(iFileHandle, 0, 2);

			if (iFileLength <= 64 * 1024)
			{
				FileSeek(iFileHandle, 0, 0);
				FileRead(iFileHandle, Form1->mLuaText, iFileLength);
				Form1->mLuaLen = iFileLength;
				Form1->mLuaText[iFileLength] = 0;

				FileClose(iFileHandle);

				MemoLua->Lines->LoadFromFile(RichEditFileName->Text);
			}
			else
			{
				FileClose(iFileHandle);
				ShowMessage("文件过大(>64K)");
			}

			/* 解析文件，填充按钮提示栏 */
			{
				char *pText;
				char *p;
				char head[12];
				char strNote[128];
				char strCmd[128];
				int i,j,k;
				AnsiString s;
				TEdit *EditNote[] = {EditLuaNote1, EditLuaNote2, EditLuaNote3, EditLuaNote4,
					EditLuaNote5, EditLuaNote6, EditLuaNote7, EditLuaNote8,
					EditLuaNote9, EditLuaNote10, EditLuaNote11, EditLuaNote12,
					EditLuaNote13, EditLuaNote14, EditLuaNote15, EditLuaNote16};

				TEdit *EditLua[] = {EditLua1, EditLua2, EditLua3, EditLua4,
					EditLua5, EditLua6, EditLua7, EditLua8,
					EditLua9, EditLua10, EditLua11, EditLua12,
					EditLua13, EditLua14, EditLua15, EditLua16};

				s = MemoLua->Text;
				pText = s.c_str();
				for (i = 0; i < 16; i++)
				{
					sprintf(head, "--F%02d=", i + 1);

					p = strstr(pText, head);
					if (p > 0)
					{
						p += 6;
						for (j = 0; j < 128; j++)
						{
							strNote[j] = p[j];
							if (p[j] == ',')
							{
								strNote[j] = 0;
								break;
							}
						}
						strNote[j] = 0;

						j++;
						for (k = 0; j < 128; j++,k++)
						{
							strCmd[k] = p[j];
							if (p[j] == 0 || p[j] == 0x0D || p[j] == 0x0A)
							{
								strCmd[k] = 0;
								break;
							}
						}
						strCmd[j] = 0;

						EditNote[i]->Text = (AnsiString)strNote;
						EditLua[i]->Text = (AnsiString)strCmd;
					}
					else
					{
						EditNote[i]->Text = "";
						EditLua[i]->Text = "";
					}
				}
			}
		}
		else
		{
			ShowMessage("文件打开失败");
			return;
        }
	}

	/* 复位lua环境后再执行 */
	AnsiString s;

	s =  (char *)Form1->mLuaText;
	FormTcp->InitAndDoLuaSend64H(s);
}

//执行lua临时语句---------------------------------------------------------------------------
void __fastcall TFormLua::ButtonDoLuaTempClick(TObject *Sender)
{
	AnsiString s;
	int i;
	TButton *pBtn = (TButton *)Sender;

	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	if (pBtn->Tag == 1) s = MemoLuaTemp1->Text;
	else if (pBtn->Tag == 2) s = MemoLuaTemp2->Text;
	else if (pBtn->Tag == 3) s = MemoLuaTemp3->Text;
	else if (pBtn->Tag == 4) s = MemoLuaTemp4->Text;
	else if (pBtn->Tag == 5) s = MemoLuaTemp5->Text;
	else if (pBtn->Tag == 6) s = MemoLuaTemp6->Text;

	FormTcp->DoLuaSend64H(s);
}
//---------------------------------------------------------------------------

void __fastcall TFormLua::ButtonDoLua1Click(TObject *Sender)
{
	AnsiString s;
	TButton *btn;
	int idx;
	int i;
	TEdit *TableEdit[] = {
		EditLua1,   EditLua2, EditLua3, EditLua4,
		EditLua5,   EditLua6, EditLua7, EditLua8,
		EditLua9,   EditLua10, EditLua11, EditLua12,
		EditLua13,   EditLua14, EditLua15, EditLua16,
	};

	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	// ButtonDoLua1
	btn = (TButton *)Sender;
	s = btn->Name;
	idx = StrToInt(&s.c_str()[11]) - 1;
	s = TableEdit[idx]->Text;
	#if 0
		udp_Send65H((char *)s.c_str(), s.Length());
	#else
		FormTcp->DoLuaSend64H(s);
	#endif
}
//---------------------------------------------------------------------------


