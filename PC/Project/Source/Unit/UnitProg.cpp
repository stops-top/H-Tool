//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <shlobj.h>
#include <IniFiles.hpp>
#include "UnitProg.h"
#include "UnitMain.h"
#include "UnitThread.h"
#include "UnitLua.h"
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
TFormProg *FormProg;

#define CSV_FILE_LEN_MAX       2 * 1024 * 1024
char g_DeviceMem[CSV_FILE_LEN_MAX];

#define CHIP_NUM_MAX       10000
CHIP_T g_DeviceList[CHIP_NUM_MAX];
int g_DeviceCount = 0;

int g_SelDeviceIndex[10000];

char g_LuaProg[1*1024*1024];
int g_LuaLen = 0;

char g_PCLuaBuf[2*1024*1024];
int g_PCLuaLen = 0;

char g_HexFile[8 * 1024 * 1024];
int g_HexLen;
char g_BinFile[8 * 1024 * 1024];
int g_BinLen;

#define DATA_FILE_COUNT		10		// 数据文件个数

UnicodeString g_InputDataFile[DATA_FILE_COUNT];  //原始数据文件名
UnicodeString g_OutputDataFile[DATA_FILE_COUNT];  //目标数据文件名（hex转化为bin）

void ReadDeviceList(char *pCSV);
int ItemIsRepeat(TComboBox *comboBox, AnsiString s);
void FreshComboxList(void);
// 这是声明
bool __stdcall CrnBrowseDir(HWND hOwner, String RootDir,  LPTSTR lpTitle, LPTSTR lpSelectDir);
int FindFileList(AnsiString pathFrom);

//---------------------------------------------------------------------------
__fastcall TFormProg::TFormProg(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TFormProg::FormCreate(TObject *Sender)
{
	bsp_AddLog("FormProg Create Begin");

	// 固件设置窗口用的变量
	{
		mChkBox[0] = CheckBoxDataEnable1;
		mChkBox[1] = CheckBoxDataEnable2;
		mChkBox[2] = CheckBoxDataEnable3;
		mChkBox[3] = CheckBoxDataEnable4;
		mChkBox[4] = CheckBoxDataEnable5;
		mChkBox[5] = CheckBoxDataEnable6;
		mChkBox[6] = CheckBoxDataEnable7;
		mChkBox[7] = CheckBoxDataEnable8;
		mChkBox[8] = CheckBoxDataEnable9;
		mChkBox[9] = CheckBoxDataEnable10;

		mChkEraseChip[0] = CheckBoxEraseChip_1;
		mChkEraseChip[1] = CheckBoxEraseChip_2;
		mChkEraseChip[2] = CheckBoxEraseChip_3;
		mChkEraseChip[3] = CheckBoxEraseChip_4;
		mChkEraseChip[4] = CheckBoxEraseChip_5;
		mChkEraseChip[5] = CheckBoxEraseChip_6;
		mChkEraseChip[6] = CheckBoxEraseChip_7;
		mChkEraseChip[7] = CheckBoxEraseChip_8;
		mChkEraseChip[8] = CheckBoxEraseChip_9;
		mChkEraseChip[9] = CheckBoxEraseChip_10;

		mEditDataFile[0] = EditDataFile1;
		mEditDataFile[1] = EditDataFile2;
		mEditDataFile[2] = EditDataFile3;
		mEditDataFile[3] = EditDataFile4;
		mEditDataFile[4] = EditDataFile5;
		mEditDataFile[5] = EditDataFile6;
		mEditDataFile[6] = EditDataFile7;
		mEditDataFile[7] = EditDataFile8;
		mEditDataFile[8] = EditDataFile9;
		mEditDataFile[9] = EditDataFile10;

		mEditDataAddress[0] = EditDataAddress1;
		mEditDataAddress[1] = EditDataAddress2;
		mEditDataAddress[2] = EditDataAddress3;
		mEditDataAddress[3] = EditDataAddress4;
		mEditDataAddress[4] = EditDataAddress5;
		mEditDataAddress[5] = EditDataAddress6;
		mEditDataAddress[6] = EditDataAddress7;
		mEditDataAddress[7] = EditDataAddress8;
		mEditDataAddress[8] = EditDataAddress9;
		mEditDataAddress[9] = EditDataAddress10;

		mComboBoxAlgo[0] = ComboBoxDataAlgo1;
		mComboBoxAlgo[1] = ComboBoxDataAlgo2;
		mComboBoxAlgo[2] = ComboBoxDataAlgo3;
		mComboBoxAlgo[3] = ComboBoxDataAlgo4;
		mComboBoxAlgo[4] = ComboBoxDataAlgo5;
		mComboBoxAlgo[5] = ComboBoxDataAlgo6;
		mComboBoxAlgo[6] = ComboBoxDataAlgo7;
		mComboBoxAlgo[7] = ComboBoxDataAlgo8;
		mComboBoxAlgo[8] = ComboBoxDataAlgo9;
		mComboBoxAlgo[9] = ComboBoxDataAlgo10;
	}

	// 读取ini配置文件
	{
		TIniFile *ini;
		int radio;
		AnsiString s1;
		int temp;

		s1 = AppExePath() + "\\app.ini";
		ini = new TIniFile(s1);

		// 解析ini文件
		ComboBoxManufacturer_ItemIndex = ini->ReadInteger("Programmer", "Manufacturer", 0);
		ComboBoxSerial_ItemIndex = ini->ReadInteger("Programmer", "Serial", 0);
		ComboBoxDevice_ItemIndex = ini->ReadInteger("Programmer", "Device", 0);

		g_InputDataFile[0] = ini->ReadString("Programmer", "InputDataFile1", "");
		g_InputDataFile[1] = ini->ReadString("Programmer", "InputDataFile2", "");
		g_InputDataFile[2] = ini->ReadString("Programmer", "InputDataFile3", "");
		g_InputDataFile[3] = ini->ReadString("Programmer", "InputDataFile4", "");
		g_InputDataFile[4] = ini->ReadString("Programmer", "InputDataFile5", "");
		g_InputDataFile[5] = ini->ReadString("Programmer", "InputDataFile6", "");
		g_InputDataFile[6] = ini->ReadString("Programmer", "InputDataFile7", "");
		g_InputDataFile[7] = ini->ReadString("Programmer", "InputDataFile8", "");
		g_InputDataFile[8] = ini->ReadString("Programmer", "InputDataFile9", "");
		g_InputDataFile[9] = ini->ReadString("Programmer", "InputDataFile10", "");

		g_OutputDataFile[0] = ini->ReadString("Programmer", "OutputDataFile1", "");
		g_OutputDataFile[1] = ini->ReadString("Programmer", "OutputDataFile2", "");
		g_OutputDataFile[2] = ini->ReadString("Programmer", "OutputDataFile3", "");
		g_OutputDataFile[3] = ini->ReadString("Programmer", "OutputDataFile4", "");
		g_OutputDataFile[4] = ini->ReadString("Programmer", "OutputDataFile5", "");
		g_OutputDataFile[5] = ini->ReadString("Programmer", "OutputDataFile6", "");
		g_OutputDataFile[6] = ini->ReadString("Programmer", "OutputDataFile7", "");
		g_OutputDataFile[7] = ini->ReadString("Programmer", "OutputDataFile8", "");
		g_OutputDataFile[8] = ini->ReadString("Programmer", "OutputDataFile9", "");
		g_OutputDataFile[9] = ini->ReadString("Programmer", "OutputDataFile10", "");

		EditDataAddress1->Text = ini->ReadInteger("Programmer", "DataAddress1", 0);
		EditDataAddress2->Text = ini->ReadInteger("Programmer", "DataAddress2", 0);
		EditDataAddress3->Text = ini->ReadInteger("Programmer", "DataAddress3", 0);
		EditDataAddress4->Text = ini->ReadInteger("Programmer", "DataAddress4", 0);
		EditDataAddress5->Text = ini->ReadInteger("Programmer", "DataAddress5", 0);
		EditDataAddress6->Text = ini->ReadInteger("Programmer", "DataAddress6", 0);
		EditDataAddress7->Text = ini->ReadInteger("Programmer", "DataAddress7", 0);
		EditDataAddress8->Text = ini->ReadInteger("Programmer", "DataAddress8", 0);
		EditDataAddress9->Text = ini->ReadInteger("Programmer", "DataAddress9", 0);
		EditDataAddress10->Text = ini->ReadInteger("Programmer", "DataAddress10", 0);

		EditDataFile1->Text = ExtractFileName(g_InputDataFile[0]);
		EditDataFile2->Text = ExtractFileName(g_InputDataFile[1]);
		EditDataFile3->Text = ExtractFileName(g_InputDataFile[2]);
		EditDataFile4->Text = ExtractFileName(g_InputDataFile[3]);
		EditDataFile5->Text = ExtractFileName(g_InputDataFile[4]);
		EditDataFile6->Text = ExtractFileName(g_InputDataFile[5]);
		EditDataFile7->Text = ExtractFileName(g_InputDataFile[6]);
		EditDataFile8->Text = ExtractFileName(g_InputDataFile[7]);
		EditDataFile9->Text = ExtractFileName(g_InputDataFile[8]);
		EditDataFile10->Text = ExtractFileName(g_InputDataFile[9]);

		MemoOutputDir->Text = ini->ReadString("Programmer", "OutputFolder", "");
		EditOutFileName->Text = ini->ReadString("Programmer", "OutputFileName", "");

		delete  ini;
	}

	/* 打开文件, 读文件数据 */
	{
		int iFileHandle;
		int iBytesRead;
		int iFileLength;

		AnsiString s1;
		int temp;

		g_DeviceMem[0] = 0;
		g_DeviceCount = 0;

		s1 = AppExePath() + "\\EMMC\\H7-TOOL\\Programmer\\Device\\device.csv";

		iFileHandle = FileOpen(s1, fmOpenRead);
		if (iFileHandle > 0)
		{
			iFileLength = FileSeek(iFileHandle, 0, 2);

			if (iFileLength < CSV_FILE_LEN_MAX)
			{
				g_DeviceMem[iFileLength] = 0;

				FileSeek(iFileHandle, 0, 0);
				FileRead(iFileHandle, g_DeviceMem, iFileLength);
				g_DeviceMem[iFileLength] = 0;
			}
			else
			{
				;
			}
			FileClose(iFileHandle);
		}
	}

	ReadDeviceList(g_DeviceMem);

	FreshComboxList();

	ComboBoxDeviceChange(this);

	ListFileName = new TStringList();
	ListFilePath = new TStringList();
	ListFileType = new TStringList();

	// 填充加密算法文件列表
	{
		String s1;

		ListFileName->Clear();
		ListFilePath->Clear();
		ListFileType->Clear();

		s1 = AppExePath() + "\\EMMC\\H7-TOOL\\Programmer\\LuaLib\\encrypt";
		FindFileList(s1);

		ComboBoxAlgoLua->Items->Clear();

		for (int i = 0; i < ListFileName->Count; i++)
		{
			if (ListFileType->Strings[i] == "File")
			{
				ComboBoxAlgoLua->Items->Add(ListFileName->Strings[i]);
			}
		}

		ComboBoxAlgoLua->ItemIndex = 0;
	}

	bsp_AddLog("FormProg Create End");
}

void __fastcall TFormProg::FormDestroy(TObject *Sender)
{
	SaveIni();

	delete ListFileName;
	delete ListFilePath;
	delete ListFileType;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TFormProg::SaveIni(void)
{
	// 保存ini配置文件
	{
		TIniFile *ini;
		int radio;
		AnsiString s1;
		int temp;

		s1 = AppExePath() + "\\app.ini";
		ini = new TIniFile(s1);

		ini->WriteInteger("Programmer", "Manufacturer", ComboBoxManufacturer->ItemIndex);
		ini->WriteInteger("Programmer", "Serial", ComboBoxSerial->ItemIndex);
		ini->WriteInteger("Programmer", "Device", ComboBoxDevice->ItemIndex);

		ini->WriteString("Programmer", "InputDataFile1", g_InputDataFile[0]);
		ini->WriteString("Programmer", "InputDataFile2", g_InputDataFile[1]);
		ini->WriteString("Programmer", "InputDataFile3", g_InputDataFile[2]);
		ini->WriteString("Programmer", "InputDataFile4", g_InputDataFile[3]);
		ini->WriteString("Programmer", "InputDataFile5", g_InputDataFile[4]);
		ini->WriteString("Programmer", "InputDataFile6", g_InputDataFile[5]);
		ini->WriteString("Programmer", "InputDataFile7", g_InputDataFile[6]);
		ini->WriteString("Programmer", "InputDataFile8", g_InputDataFile[7]);
		ini->WriteString("Programmer", "InputDataFile9", g_InputDataFile[8]);
		ini->WriteString("Programmer", "InputDataFile10", g_InputDataFile[9]);

		ini->WriteString("Programmer", "OutputDataFile1", g_OutputDataFile[0]);
		ini->WriteString("Programmer", "OutputDataFile2", g_OutputDataFile[1]);
		ini->WriteString("Programmer", "OutputDataFile3", g_OutputDataFile[2]);
		ini->WriteString("Programmer", "OutputDataFile4", g_OutputDataFile[3]);
		ini->WriteString("Programmer", "OutputDataFile5", g_OutputDataFile[4]);
		ini->WriteString("Programmer", "OutputDataFile6", g_OutputDataFile[5]);
		ini->WriteString("Programmer", "OutputDataFile7", g_OutputDataFile[6]);
		ini->WriteString("Programmer", "OutputDataFile8", g_OutputDataFile[7]);
		ini->WriteString("Programmer", "OutputDataFile9", g_OutputDataFile[8]);
		ini->WriteString("Programmer", "OutputDataFile10", g_OutputDataFile[9]);

		ini->WriteString("Programmer", "OutputFolder", MemoOutputDir->Text);
		ini->WriteString("Programmer", "OutputFileName", EditOutFileName->Text);

		ini->WriteInteger("Programmer", "DataAddress1", StrToInt(EditDataAddress1->Text));
		ini->WriteInteger("Programmer", "DataAddress2", StrToInt(EditDataAddress2->Text));
		ini->WriteInteger("Programmer", "DataAddress3", StrToInt(EditDataAddress3->Text));

		delete  ini;
	}
}

//根据目录获得odi （不太懂）
LPITEMIDLIST Dir2Pidl(wchar_t * str)
{
	HRESULT hres;
	IShellLink *psl;
	ITEMIDLIST *pidl;
	IPersistFile *ppf;

	//用下面这个函数先初始化COM库，并把当前线程设为单线程模式
	//(single-thread apartment(STA))，以便后面使用COM库函数
	CoInitialize(NULL);

	//获得IShellLink接口的指针，放在psl中
	hres = CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER,
	   IID_IShellLink, (LPVOID*)&psl);
	if (SUCCEEDED(hres))
	{
		// 设置目标文件
		psl->SetPath(str);
		/// 获得目标文件的ITEMIDLIST
		psl->GetIDList(&pidl);

		//获得IPersistFile接口的指针，放在ppf中
		hres = psl->QueryInterface(IID_IPersistFile, (void**)&ppf);
		if (SUCCEEDED(hres))
		{
			WCHAR wsz[MAX_PATH];           //    <=========下面三行代码完成字符串转为Unicode
			#ifdef _UNICODE
			wcscpy(wsz, str);
			#else
			//把字符串转为Unicode
			MultiByteToWideChar(CP_ACP, 0, str, -1, wsz, MAX_PATH);
			#endif

			// Load the shortcut.
			hres = ppf->Load(wsz, STGM_READ);

			if (SUCCEEDED(hres))
			{
				/// 获得快捷方式的ITEMIDLIST
				psl->GetIDList(&pidl);
			}
			ppf->Release();
		}

		psl->Release();
	}
	CoUninitialize();
	return pidl;
}
// 这是定义
bool __stdcall CrnBrowseDir(HWND hOwner, String RootDir,  LPTSTR lpTitle, LPTSTR lpSelectDir)
{
    bool bReslut = false;
	_tcscpy(lpSelectDir, TEXT(""));

    LPMALLOC pShellMalloc;

    if (SHGetMalloc(&pShellMalloc) == NO_ERROR)
	{
		BROWSEINFO bi;
		wchar_t szDisplayName[MAX_PATH];

		memset(&bi, 0x00,sizeof(bi));
		bi.hwndOwner = hOwner;
		//bi.pidlRoot = 0;	//0表示初始目录是桌面 Dir2Pidl(L"D:\\");

		bi.pidlRoot = Dir2Pidl(RootDir.c_str());
		bi.pszDisplayName = szDisplayName;
		bi.lpszTitle = lpTitle;
        bi.ulFlags = BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE;
		bi.lpfn = 0;

        LPITEMIDLIST pidl = SHBrowseForFolder(&bi);

        if (pidl)
        {
			bReslut= SHGetPathFromIDList(pidl, lpSelectDir);

            pShellMalloc->Free(pidl);
        }

        pShellMalloc->Release();
	}
	return bReslut;
}

void ReadDeviceList(char *pCSV)
{
	char *p1, *p2;
	int col = 0;
	int count = 0;

	p1 = pCSV;
	p2 = p1;	/* p1 行首 */
	while (1)
	{
		uint8_t ch;

		ch = *p2;
		if (ch == ',' || ch == '\r' || ch == 0)
		{
			int len = p2 - p1;
			if (col == 0)
			{
				if (len > STR_LEN_MAX - 1)
				{
					len = STR_LEN_MAX - 1;
				}
				memcpy(g_DeviceList[count].Manufacturer, p1, len);
				g_DeviceList[count].Manufacturer[len] = 0;
			}
			else if (col == 1)
			{
				if (len > STR_LEN_MAX - 1)
				{
					len = STR_LEN_MAX - 1;
				}
				memcpy(g_DeviceList[count].Serial, p1, len);
				g_DeviceList[count].Serial[len] = 0;
			}
			else if (col == 2)
			{
				if (len > STR_LEN_MAX - 1)
				{
					len = STR_LEN_MAX - 1;
				}
				memcpy(g_DeviceList[count].Device, p1, len);
				g_DeviceList[count].Device[len] = 0;
			}
			else if (col == 3)
			{
				if (len > STR_LEN_MAX - 1)
				{
					len = STR_LEN_MAX - 1;
				}
				memcpy(g_DeviceList[count].Lua, p1, len);
				g_DeviceList[count].Lua[len] = 0;
			}
			else  /* 多余列 */
			{
				;
			}

			col++;
			if (ch == '\r')
			{

				if (count < CHIP_NUM_MAX)
				{
					count++;
				}
				else
				{
					return;
				}
				col = 0;

				p2++;
				p1 = p2 + 1;      /* 下一行 */
			}
			else if (ch == ',')
			{
                p1 = p2 + 1;      /* 下一节 */
			}
			else if (ch == 0)
			{
				g_DeviceCount = count;
				return;
			}
		}
		p2++;
	}
}

// 判断重复项
int ItemIsRepeat(TComboBox *comboBox, AnsiString s)
{
	 int i;
	 AnsiString s1;

	 for (i = 0; i < comboBox->Items->Count; i++)
	 {
		s1 = comboBox->Items->Strings[i];
		if (s1 == s)
		{
			return 1;
		}
	 }
	 return 0;
}

/* 刷新combox列表 */
void FreshComboxList(void)
{
	int i;
	AnsiString strManu;
	AnsiString strSerial;
	AnsiString strDevice;

	FormProg->ComboBoxManufacturer->Items->Clear();
	FormProg->ComboBoxSerial->Items->Clear();
	FormProg->ComboBoxDevice->Items->Clear();
	for (i = 1; i < g_DeviceCount; i++)
	{
		if (ItemIsRepeat(FormProg->ComboBoxManufacturer, g_DeviceList[i].Manufacturer) == 0)
		{
			FormProg->ComboBoxManufacturer->Items->Add(g_DeviceList[i].Manufacturer);
		}
	}
	FormProg->ComboBoxManufacturer->ItemIndex = FormProg->ComboBoxManufacturer_ItemIndex;

	// 处理系列
	strManu = FormProg->ComboBoxManufacturer->Items->Strings[FormProg->ComboBoxManufacturer->ItemIndex];
	for (i = 1; i < g_DeviceCount; i++)
	{
		if (strManu == g_DeviceList[i].Manufacturer)
		{
			if (ItemIsRepeat(FormProg->ComboBoxSerial, g_DeviceList[i].Serial) == 0)
			{
				FormProg->ComboBoxSerial->Items->Add(g_DeviceList[i].Serial);
			}
		}
	}
	FormProg->ComboBoxSerial->ItemIndex = FormProg->ComboBoxSerial_ItemIndex;

	//处理device
	strSerial = FormProg->ComboBoxSerial->Items->Strings[FormProg->ComboBoxSerial->ItemIndex];
	for (i = 1; i < g_DeviceCount; i++)
	{
		if (strManu == g_DeviceList[i].Manufacturer &&
			strSerial == g_DeviceList[i].Serial)
		{
			if (ItemIsRepeat(FormProg->ComboBoxDevice, g_DeviceList[i].Device) == 0)
			{
				g_SelDeviceIndex[FormProg->ComboBoxDevice->Items->Count] = i;
				FormProg->ComboBoxDevice->Items->Add(g_DeviceList[i].Device);
			}
		}
	}
	FormProg->ComboBoxDevice->ItemIndex = FormProg->ComboBoxDevice_ItemIndex;
}

//---------------------------------------------------------------------------
void __fastcall TFormProg::ComboBoxManufacturerChange(TObject *Sender)
{
	int i;
	AnsiString strManu;
	AnsiString strSerial;
	AnsiString strDevice;

	//FormProg->ComboBoxManufacturer->Items->Clear();
	FormProg->ComboBoxSerial->Items->Clear();
	FormProg->ComboBoxDevice->Items->Clear();

	// 处理系列
	strManu = FormProg->ComboBoxManufacturer->Items->Strings[FormProg->ComboBoxManufacturer->ItemIndex];
	for (i = 1; i < g_DeviceCount; i++)
	{
		if (strManu == g_DeviceList[i].Manufacturer)
		{
			if (ItemIsRepeat(FormProg->ComboBoxSerial, g_DeviceList[i].Serial) == 0)
			{
				FormProg->ComboBoxSerial->Items->Add(g_DeviceList[i].Serial);
			}
		}
	}
	FormProg->ComboBoxSerial->ItemIndex = 0;

	//处理device
	strSerial = FormProg->ComboBoxSerial->Items->Strings[FormProg->ComboBoxSerial->ItemIndex];
	for (i = 1; i < g_DeviceCount; i++)
	{
		if (strManu == g_DeviceList[i].Manufacturer &&
			strSerial == g_DeviceList[i].Serial)
		{
			if (ItemIsRepeat(FormProg->ComboBoxDevice, g_DeviceList[i].Device) == 0)
			{
				g_SelDeviceIndex[FormProg->ComboBoxDevice->Items->Count] = i;
				FormProg->ComboBoxDevice->Items->Add(g_DeviceList[i].Device);
			}
		}
	}
	FormProg->ComboBoxDevice->ItemIndex = 0;
	ComboBoxDeviceChange(FormProg->ComboBoxDevice);
}
//---------------------------------------------------------------------------

void __fastcall TFormProg::ComboBoxSerialChange(TObject *Sender)
{
	int i;
	AnsiString strManu;
	AnsiString strSerial;
	AnsiString strDevice;

	//FormProg->ComboBoxManufacturer->Items->Clear();
	//FormProg->ComboBoxSerial->Items->Clear();
	FormProg->ComboBoxDevice->Items->Clear();

	// 处理系列
	strManu = FormProg->ComboBoxManufacturer->Items->Strings[FormProg->ComboBoxManufacturer->ItemIndex];

	//处理device
	strSerial = FormProg->ComboBoxSerial->Items->Strings[FormProg->ComboBoxSerial->ItemIndex];
	for (i = 1; i < g_DeviceCount; i++)
	{
		if (strManu == g_DeviceList[i].Manufacturer &&
			strSerial == g_DeviceList[i].Serial)
		{
			if (ItemIsRepeat(FormProg->ComboBoxDevice, g_DeviceList[i].Device) == 0)
			{
				g_SelDeviceIndex[FormProg->ComboBoxDevice->Items->Count] = i;
				FormProg->ComboBoxDevice->Items->Add(g_DeviceList[i].Device);
			}
		}
	}
	FormProg->ComboBoxDevice->ItemIndex = 0;
	ComboBoxDeviceChange(FormProg->ComboBoxDevice);
}
//---------------------------------------------------------------------------

void __fastcall TFormProg::GetHexFileStartAddress(int i)
{
	UnicodeString ExtName;
	UnicodeString s;

	g_HexLen = ReadFileToMem(g_InputDataFile[i], g_HexFile, sizeof(g_HexFile));
	if (g_HexLen > 0)
	{
		;
	}
	else
	{
		Form1->MemoLuaOut->Lines->Add("读取数据文件失败 #" + IntToStr(i + 1));
		Form1->MemoLuaOut->Lines->Add("  文件名称: " + g_InputDataFile[i]);
		return;
	}

	ExtName = ExtractFileExt(g_InputDataFile[i]);
	ExtName = ExtName.LowerCase();
	if (ExtName == ".hex")
	{
		uint32_t StartAddress;
		AnsiString str;

		g_BinLen = MyHexToBin(g_HexFile, g_HexLen, g_BinFile, sizeof(g_BinFile), 0xFF, &StartAddress);

		// 处理目标地址
		if (ComboBoxSerial->Text != "8051")   // 8051的HEX文件地址不自动填充，用于烧写LDROM
		{
			str.sprintf("0x%08X", StartAddress);
			mEditDataAddress[i]->Text = str;
		}
	}
	else if (ExtName == ".bin")
	{
//		if (g_HexLen >= sizeof(g_BinFile))
//		{
//			Form1->MemoLuaOut->Lines->Add("文件过大 #" + IntToStr(i + 1));
//			g_BinLen = 0;
//		}
//		else
//		{
//			memcpy(g_BinFile,  g_HexFile, g_HexLen);
//			g_BinLen =  g_HexLen;
//		}
	}
	else
	{
		Form1->MemoLuaOut->Lines->Add("未知文件格式 #" + IntToStr(i + 1));
		return;
	}
}

void LuaAddString(char *_str)
{
	strcpy(&g_LuaProg[g_LuaLen], _str);
	g_LuaLen += strlen(_str);
}

// 生成 MakeConfigFixData() ,SWIM ，SWD均适用
void __fastcall TFormProg::MakeConfigFixData(void)
{
	char buf[4096];
	int temp;
	int i;

	LuaAddString("--配置滚码、UID加密\r\n");

	LuaAddString("function config_fix_data(void)\r\n");
	LuaAddString("  --配置滚码\r\n");
	sprintf(buf, "  SN_ENABLE = %d    -->是否启用滚码\r\n", ComboBoxSNEnable->ItemIndex);
	LuaAddString(buf);

	temp = ComboBoxSNType->ItemIndex;
	sprintf(buf, "  SN_TYPE = %d      --滚码类型 0-普通滚码,顺序加1  1-1970年基准秒数,4-8字节\r\n", temp);
	LuaAddString(buf);

	temp = ComboBoxSNEndain->ItemIndex;
	sprintf(buf, "  SN_FORMAT = %d   --0-二进制小端 1-二进制大端 2-ASCII字符串\r\n", temp);
	LuaAddString(buf);

	LuaAddString("  SN_DATA = {}		--SN数据\r\n");

	temp = MyStrToInt(ComboBoxSNLen->Text);
	sprintf(buf, "  SN_LEN = %d			--SN数据长度\r\n", temp);
	LuaAddString(buf);

	temp = MyStrToInt(EditSNAddr->Text);
	sprintf(buf, "  SN_ADDR = 0x%08X	--存储地址\r\n", temp);
	LuaAddString(buf);

	LuaAddString("\r\n");

		//  --写入烧录器工厂代码(1字节）
	//  TOOL_FACTORY_ENABLE = 0
	//  TOOL_FACTORY_ADDR = 0x08000000
	//
	//  --写入烧录器编号(1字节）
	//  TOOL_SN_ENABLE = 0
	//  TOOL_SN_ADDR = 0x08000000
	//
	//  --写入烧录通道号(1字节）
	//  TOOL_CHANNAL_ENABLE = 0
	//  TOOL_CHANNAL_ADDR = 0x08000000
	LuaAddString("  --写入烧录器工厂代码(1字节）\r\n");
	sprintf(buf, "  TOOL_FACTORY_ENABLE = %d\r\n", ComboBoxToolFactory->ItemIndex);
	LuaAddString(buf);
	sprintf(buf, "  TOOL_FACTORY_ADDR = 0x%08X\r\n", MyStrToInt(EditToolFactoryAddr->Text));
	LuaAddString(buf);

	LuaAddString("  --写入烧录器编号(1字节）\r\n");
	sprintf(buf, "  TOOL_SN_ENABLE = %d\r\n", ComboBoxToolSn->ItemIndex);
	LuaAddString(buf);
	sprintf(buf, "  TOOL_SN_ADDR = 0x%08X\r\n", MyStrToInt(EditToolSnAddr->Text));
	LuaAddString(buf);

	LuaAddString("  --写入烧录通道号(1字节）\r\n");
	sprintf(buf, "  TOOL_CHANNAL_ENABLE = %d\r\n", ComboBoxToolChannel->ItemIndex);
	LuaAddString(buf);
	sprintf(buf, "  TOOL_CHANNAL_ADDR = 0x%08X\r\n", MyStrToInt(EditToolChannelAddr->Text));
	LuaAddString(buf);

	LuaAddString("\r\n");

	LuaAddString("  --常量配置\r\n");
	LuaAddString("  CONST_CFG = {  --使能位, 存储地址, 字符串数据\r\n");
	sprintf(buf, "  	%d, 0x%08X, \"%s\",\r\n", ComboBoxConstEnable_1->ItemIndex,
		MyStrToInt(EditConstAddr_1->Text), (AnsiString)EditConstValue_1->Text.c_str());
	LuaAddString(buf);
	sprintf(buf, "  	%d, 0x%08X, \"%s\",\r\n", ComboBoxConstEnable_2->ItemIndex,
		MyStrToInt(EditConstAddr_2->Text), (AnsiString)EditConstValue_2->Text.c_str());
	LuaAddString(buf);
	sprintf(buf, "  	%d, 0x%08X, \"%s\",\r\n", ComboBoxConstEnable_3->ItemIndex,
		MyStrToInt(EditConstAddr_3->Text), (AnsiString)EditConstValue_3->Text.c_str());
	LuaAddString(buf);
	sprintf(buf, "  	%d, 0x%08X, \"%s\",\r\n", ComboBoxConstEnable_4->ItemIndex,
		MyStrToInt(EditConstAddr_4->Text), (AnsiString)EditConstValue_4->Text.c_str());
	LuaAddString(buf);
	LuaAddString("  }\r\n");

	LuaAddString("\r\n");

	LuaAddString("  --生产日期\r\n");
	sprintf(buf, "  DATE_ENABLE = %d\r\n", ComboBoxDate->ItemIndex);
	LuaAddString(buf);
	sprintf(buf, "  DATE_ADDR = 0x%08X\r\n", MyStrToInt(EditDateAddr->Text));
	LuaAddString(buf);
	sprintf(buf, "  DATE_FORMAT = %d  --日期时间格式r\n", ComboBoxDateType->ItemIndex);
	LuaAddString(buf);
	LuaAddString("  DATE_DATA = \"\"\r\n");

	LuaAddString("\r\n");

	LuaAddString("  --随机数配置\r\n");
	sprintf(buf, "  RNG_CONST_DATA = \"%s\"\r\n", (AnsiString)EditEncryptConst->Text.c_str());
	LuaAddString(buf);
	LuaAddString("  RNG_TAB = {  --使能位, 存储地址, 随机数长度\r\n");
	sprintf(buf, "    %d, 0x%08X, %d,\r\n", ComboBoxAlgoRnd1->ItemIndex,  MyStrToInt(EditAlgoRndAddr1->Text), MyStrToInt(ComboBoxRndLen1->Text));
	LuaAddString(buf);
	sprintf(buf, "    %d, 0x%08X, %d,\r\n", ComboBoxAlgoRnd2->ItemIndex,  MyStrToInt(EditAlgoRndAddr2->Text), MyStrToInt(ComboBoxRndLen2->Text));
	LuaAddString(buf);
	sprintf(buf, "    %d, 0x%08X, %d,\r\n", ComboBoxAlgoRnd3->ItemIndex,  MyStrToInt(EditAlgoRndAddr3->Text), MyStrToInt(ComboBoxRndLen3->Text));
	LuaAddString(buf);
	sprintf(buf, "    %d, 0x%08X, %d,\r\n", ComboBoxAlgoRnd4->ItemIndex,  MyStrToInt(EditAlgoRndAddr4->Text), MyStrToInt(ComboBoxRndLen4->Text));
	LuaAddString(buf);
	LuaAddString("  }\r\n");

	LuaAddString("\r\n");

	LuaAddString("  --UID加密配置参数\r\n");
	LuaAddString("  UID = {}  --[1]OK标志,[2-5]是4路UID\r\n");
	LuaAddString("  \r\n");

	sprintf(buf, "  ENCRYPT_ENABLE = %d\r\n", ComboBoxEncryptEnable->ItemIndex);
	LuaAddString(buf);
	sprintf(buf, "  ENCRYPT_RND_IDX = %d  --加密用初值选择 0:固定数，1-4是随机数\r\n", ComboBoxInitValue->ItemIndex);
	LuaAddString(buf);

	LuaAddString("  ENCRYPT_RND_DATA = {}\r\n");

	for (i = 0; i < 16; i++)
	{
		UnicodeString us;

		us = "A" + IntToStr(i);
		sprintf(buf, "  A%d = %s\r\n", i, (AnsiString)ValueListEditorA->Values[us].c_str());
		LuaAddString(buf);
	}
	sprintf(buf, "  ENCRYPT_LEN = %d --加密结果长度\r\n", MyStrToInt(ComboBoxEncryptResultLen->Text));
	LuaAddString(buf);
	sprintf(buf, "  ENCRYPT_ADDR = 0x%08X\r\n", MyStrToInt(EditEncryptSaveAddr->Text));
	LuaAddString(buf);

	LuaAddString("  \r\n");

	//  --检查UID
	//  UID_CHECK_ENABLE = 0
	//  UID_TABLE = {
	//	"00000000 00000000 00000000", "00000000 00000000 00000000",		--UID掩蔽，UID比对值
	//  }
	LuaAddString("  --检查UID\r\n");
	sprintf(buf, "  UID_CHECK_ENABLE = %d  --检查UID\r\n", CheckBoxCheckUid->Checked?1:0);
	LuaAddString(buf);
	LuaAddString("  UID_TABLE = {\r\n");
	sprintf(buf, "%s\r\n  }\r\n",  (AnsiString)MemoUID->Text.c_str());
	LuaAddString(buf);

	LuaAddString("  \r\n");
	//  --检查截止日期
	//  DEADLINE_ENABLE = 0
	//  DEADLINE_DATE = "2020-01-01 00:00:00"
	LuaAddString("  --检查截止日期\r\n");
	sprintf(buf, "  DEADLINE_ENABLE = %d\r\n", CheckBoxDeadline->Checked?1:0);
	LuaAddString(buf);
	sprintf(buf, "  DEADLINE_DATE = \"%s\"\r\n", (AnsiString)EditDeadlineDate->Text.c_str());
	LuaAddString(buf);

	LuaAddString("end\r\n");

	LuaAddString("\r\n");
}

//配置机台接口
void __fastcall TFormProg::MakeMachineIF(void)
{
	char buf[1024];

	LuaAddString("--配置自动烧录机台接口\r\n");
	LuaAddString("function config_machine_if(void)\r\n");

	sprintf(buf, "  MACHINE_INTERFACE = %d   --烧录机台接口类型 0:不启用 1:标准信号  2:EOT类型的信号\r\n", ComboBoxMachineIF->ItemIndex);
	LuaAddString(buf);
	LuaAddString("\r\n");

	sprintf(buf, "  MI_STD_OK_NG_DELAY = %s   --标准信号，OK NG信号持续时间，ms，0表示一直持续\r\n", (AnsiString)EditStdOkDelay->Text.c_str());
	LuaAddString(buf);
	LuaAddString("\r\n");

	sprintf(buf, "  MI_EOT_TIME1 = %s   --EOT信号时序，延迟1, ms\r\n", (AnsiString)EditEOT_T1->Text.c_str());
	LuaAddString(buf);
	sprintf(buf, "  MI_EOT_TIME2 = %s   --EOT信号时序，延迟2, ms\r\n", (AnsiString)EditEOT_T2->Text.c_str());
	LuaAddString(buf);
	sprintf(buf, "  MI_EOT_TIME3 = %s   --EOT信号时序，延迟3, ms\r\n", (AnsiString)EditEOT_T3->Text.c_str());
	LuaAddString(buf);
	LuaAddString("\r\n");

	sprintf(buf, "  ABORT_ON_ERROR = %d  --出错后终止任务策略，0继续烧录 1立即终止\r\n", ComboBoxAbortOnError->ItemIndex);
	LuaAddString(buf);
	sprintf(buf, "  ABORT_NG_MODE = %d   --终止任务后NG信号策略, 0全部发NG  1仅错误通道发NG\r\n", ComboBoxAbortNG->ItemIndex);
	LuaAddString(buf);

	LuaAddString("end\r\n");
	LuaAddString("config_machine_if()\r\n");

}

void __fastcall TFormProg::MakeLuaForSWD(void)
{
	char buf[1024];
	AnsiString strManu;
	AnsiString strSerial;
	AnsiString strDevice;
	AnsiString strLua;
	AnsiString str;

	strManu = FormProg->ComboBoxManufacturer->Items->Strings[FormProg->ComboBoxManufacturer->ItemIndex];
	strSerial = FormProg->ComboBoxSerial->Items->Strings[FormProg->ComboBoxSerial->ItemIndex];
	strDevice = FormProg->ComboBoxDevice->Items->Strings[FormProg->ComboBoxDevice->ItemIndex];
	strLua = FormProg->LabelDeviceLuaFileName->Caption;

	g_LuaLen = 0;
	LuaAddString("--以下快捷方式将显示在PC软件界面-------------\r\n");
	LuaAddString("--F01=自动编程,start_prog()\r\n");
	//LuaAddString("--F02=烧录测试bin,USE_TEST_BIN=\"0:/H7-TOOL/Programmer/User/TestBin/1k.bin\" start_prog() USE_TEST_BIN=nil\r\n");
	LuaAddString("--F03=擦除MCU flash,erase_chip_mcu()\r\n");
	LuaAddString("--F04=擦除QSPI flash,erase_chip_qspi()\r\n");
	LuaAddString("--F05=擦除EEPROM, erase_chip_eeprom()\r\n");
	LuaAddString("--F06=打印内核id,print_core_id()\r\n");
	LuaAddString("--F07=打印UID,print_uid()\r\n");
	LuaAddString("--F08=打印Flash,print_flash(FLASH_ADDRESS,1024,32,FLASH_ADDRESS)\r\n");
	LuaAddString("--F09=读EEPROM,print_flash(EEPROM_ADDRESS, 256)\r\n");
	LuaAddString("--F10=读回RAM,print_flash(RAM_ADDRESS, 256)\r\n");
	LuaAddString("--F12=掉电复位,beep() set_tvcc(0) delayms(500) set_tvcc(TVCC_VOLT) beep()\r\n");
	LuaAddString("--F13=硬件复位,pg_reset(20)\r\n");
	LuaAddString("--F14=设置读保护,set_read_protect(1)\r\n");
	LuaAddString("--F15=解除读保护,set_read_protect(0)\r\n");
	LuaAddString("--F16=打印Option Bytes,print_option_bytes()\r\n");
	LuaAddString("\r\n");

	sprintf(buf, "MANUFACTURER = \"%s\"\r\n", strManu.c_str());
	LuaAddString(buf);
	sprintf(buf, "SERIAL = \"%s\"\r\n", strSerial.c_str());
	LuaAddString(buf);
	sprintf(buf, "DEVICE = \"%s\"\r\n", strDevice.c_str());
	LuaAddString(buf);

	LuaAddString("\r\n");
	LuaAddString("--加载lua子文件-----------------------------------\r\n");
	{
		char strm[256];
		char strs[256];
		uint8_t filter  = 0;
		uint8_t ch;
		uint8_t pos = 0;

		// 去掉公司名中(开发中)
		filter  = 0;
		pos = 0;
		for (int i = 0; i < strlen(strManu.c_str()); i++)
		{
			ch = strManu.c_str()[i];

			if (filter == 0 && ch == '(')
			{
				 filter = 1;
			}
			else if (filter == 1 && ch == ')')
			{
				 filter = 0;
			}
			else
			{
				if (filter == 0)
				{
					strm[pos++] =  ch;
				}
			}
		}
		strm[pos] = 0;

		// 去掉系列名中括号内注释
		filter  = 0;
		pos = 0;
		for (int i = 0; i < strlen(strSerial.c_str()); i++)
		{
			ch = strSerial.c_str()[i];

			if (filter == 0 && ch == '(')
			{
				 filter = 1;
			}
			else if (filter == 1 && ch == ')')
			{
				 filter = 0;
			}
			else
			{
				if (filter == 0)
				{
					strs[pos++] =  ch;
				}
			}
		}
		strs[pos] = 0;

		sprintf(buf, "dofile(\"0:/H7-TOOL/Programmer/Device/%s/%s/%s\")\r\n",
			strm, strs, strLua.c_str());
	}
	LuaAddString(buf);

	LuaAddString("if IncludeList ~= nil then\r\n");
	LuaAddString("  local i\r\n");
	LuaAddString("  for i = 1,#IncludeList,1 do\r\n");
	LuaAddString("    print(\"dofile : \", IncludeList[i])\r\n");
	LuaAddString("    dofile(IncludeList[i])\r\n");
	LuaAddString("  end\r\n");
	LuaAddString("end\r\n");

	LuaAddString("\r\n");
	LuaAddString("--UID加密和产品序号处理文件\r\n");
	LuaAddString("dofile(\"0:/H7-TOOL/Programmer/LuaLib/fix_data.lua\")\r\n");

	if (ComboBoxEncryptEnable->ItemIndex)
	{
		sprintf(buf, "dofile(\"0:/H7-TOOL/Programmer/LuaLib/encrypt/%s\")\r\n", (AnsiString)ComboBoxAlgoLua->Text.c_str());
		LuaAddString(buf);
	}

	LuaAddString("\r\n");
	LuaAddString("--公共lua子程序\r\n");
	LuaAddString("dofile(\"0:/H7-TOOL/Programmer/LuaLib/prog_lib.lua\")\r\n");
	LuaAddString("\r\n");

	LuaAddString("--烧录机台接口程序\r\n");
	LuaAddString("dofile(\"0:/H7-TOOL/Programmer/LuaLib/machine_if.lua\")\r\n");
	LuaAddString("\r\n");

	LuaAddString("--下面的注释将显示在H7-TOOL液晶屏\r\n");
	str = EditNote1->Text.t_str();
	sprintf(buf, "Note01 = \"%s\"\r\n", str.c_str());
	LuaAddString(buf);

	LuaAddString("\r\n");

	//配置机台接口
	MakeMachineIF();
	LuaAddString("\r\n");

//	LuaAddString("beep()\r\n");

	LuaAddString("--配置芯片接口和参数\r\n");
	LuaAddString("function config_chip1(void)\r\n");

	LuaAddString("  config_cpu()\r\n");
	LuaAddString("\r\n");

	LuaAddString("  --编程任务列表，可以任意追加\r\n");
	LuaAddString("  --文件名支持绝对路径和相对路径，相对路径时和lua文件同目录，支持../上级目录\r\n");
	LuaAddString("  TaskList = {\r\n");

	for (int i = 0; i < 10; i++) {
		if (mChkBox[i]->Checked)
		{
			if (i > 0)
			{
				LuaAddString("\r\n");
			}
			str = mComboBoxAlgo[i]->Text.t_str();
			sprintf(buf, "    %s, --算法文件\r\n", str.c_str());
			LuaAddString(buf);

			str = g_OutputDataFile[i].t_str();
			sprintf(buf, "    \"%s\",  --数据文件\r\n", str.c_str());
			LuaAddString(buf);

			sprintf(buf, "    0x%08x,  --目标地址\r\n", StrToInt(mEditDataAddress[i]->Text));
			LuaAddString(buf);

			if (mChkEraseChip[i]->Checked)
			{
				LuaAddString("    1,  --0表示按扇区擦除, 1表示整片擦除\r\n");
			}
			else
			{
				LuaAddString("    0,  --0表示按扇区擦除, 1表示整片擦除\r\n");
			}
		}
	}
	LuaAddString("  }\r\n");

	LuaAddString("\r\n");

	sprintf(buf, "  DATA_FILE_CHECK_SUMS = 0x%08X\r\n", mDataFileSum);
	LuaAddString(buf);

	LuaAddString("\r\n");

	LuaAddString("  --如果解除读保护后必须断电才能生效，则添加如下代码\r\n");

//	if (CheckBoxRdpPowerOff->Checked)
//	{
//		LuaAddString("  REMOVE_RDP_POWEROFF = 1\r\n");
//	}
//	else
//	{
//		LuaAddString("  REMOVE_RDP_POWEROFF = 0\r\n");
//	}
	str = ValueListEditor1->Values[REMOVE_RDP_POWEROFF];
	sprintf(buf, "  REMOVE_RDP_POWEROFF = %s\r\n", str.c_str());
	LuaAddString(buf);

	str = ValueListEditor1->Values[POWEROFF_TIME1];
	sprintf(buf, "  POWEROFF_TIME1 = %s   --写完OB延迟时间ms\r\n", str.c_str());
	LuaAddString(buf);
	str = ValueListEditor1->Values[POWEROFF_TIME2];
	sprintf(buf, "  POWEROFF_TIME2 = %s   --断电时间ms\r\n",  str.c_str());
	LuaAddString(buf);
	str = ValueListEditor1->Values[POWEROFF_TIME3];
	sprintf(buf, "  POWEROFF_TIME3 = %s   --上电后等待时间ms\r\n",  str.c_str());
	LuaAddString(buf);

	LuaAddString("\r\n");

	LuaAddString("  --定义CPU供电电压TVCC\r\n");
	str = EditTVCC->Text;
	sprintf(buf, "  TVCC_VOLT = %s\r\n", str.c_str());
	LuaAddString(buf);
	LuaAddString("\r\n");

	LuaAddString("  --SWD时钟延迟，0不延迟，值越大速度越慢\r\n");
	LuaAddString("  if (MULTI_MODE == 0) then\r\n");
	str = ValueListEditor1->Values[SWD_CLOCK_DELAY];
	sprintf(buf, "    SWD_CLOCK_DELAY = %s --单路烧录时的时钟延迟\r\n", str.c_str());
	LuaAddString(buf);
	LuaAddString("  else\r\n");
	str = ValueListEditor1->Values[MUL_SWD_CLOCK_DELAY];
	sprintf(buf, "    SWD_CLOCK_DELAY = %s --多路烧录时的时钟延迟\r\n", str.c_str());
	LuaAddString(buf);
	LuaAddString("  end\r\n");
	LuaAddString("\r\n");

	sprintf(buf, "  RESET_MODE = %d --复位模式 0:自动模式,  1:软件模式  2:硬件UnderReset\r\n", ComboBoxResetMode->ItemIndex);
	LuaAddString(buf);

	str = ValueListEditor1->Values[RESET_DELAY];
	sprintf(buf, "  RESET_DELAY = %s --复位后的延迟ms\r\n", str.c_str());
	LuaAddString(buf);
	LuaAddString("\r\n");

	LuaAddString("  --是否核对CPU内核ID\r\n");
	LuaAddString("  CHECK_MCU_ID = 0\r\n");
	LuaAddString("\r\n");

	sprintf(buf, "  VERIFY_MODE = %d  --校验模式: 0:自动(FLM提供校验函数或读回) 1:读回  2:软件CRC32  3:STM32硬件CRC32\r\n",
		ComboBoxVerifyMode->ItemIndex);
 	LuaAddString(buf);
	LuaAddString("\r\n");

	LuaAddString("  --编程结束后复位 0表示不复位  1表示硬件复位\r\n");
	if (CheckBoxAtfterAuotReset->Checked)
	{
		LuaAddString("  RESET_AFTER_COMPLETE = 1\r\n");
	}
	else
	{
		LuaAddString("  RESET_AFTER_COMPLETE = 0\r\n");
	}
	LuaAddString("\r\n");

	LuaAddString("  --1表示自动解除读保护和写保护\r\n");
	if (CheckBoxRemoveProtect->Checked)
	{
		LuaAddString("  AUTO_REMOVE_PROTECT = 1\r\n");
	}
	else
	{
		LuaAddString("  AUTO_REMOVE_PROTECT = 0\r\n");
	}
	LuaAddString("\r\n");

	LuaAddString("  --SWD读内存指令间延迟时间(us)\r\n");
	sprintf(buf, "  MUL_DELAYUS_READ_DATA = %s\r\n",  (AnsiString)ValueListEditor1->Values[MUL_DELAYUS_READ_DATA]);
	LuaAddString(buf);
	LuaAddString("\r\n");

	LuaAddString("  --OPTION BYTES 配置\r\n");
	if (ComboBoxOB->ItemIndex == 0)
	{
		LuaAddString("  OB_ENABLE	= 0  --0表示编程完毕后不写OPTION BYTES\r\n\r\n");
		LuaAddString("  SECURE_ENABLE	= 0  --选择加密还是不加密\r\n");
	}
	else if (ComboBoxOB->ItemIndex == 1)
	{
		LuaAddString("  OB_ENABLE	= 1  --1表示编程完毕后写OPTION BYTES\r\n");
		LuaAddString("  SECURE_ENABLE	= 0  --选择加密还是不加密\r\n");
	}
	else
	{
		LuaAddString("  OB_ENABLE	= 1  --1表示编程完毕后写OPTION BYTES\r\n");
		LuaAddString("  SECURE_ENABLE	= 1  --选择加密还是不加密\r\n");
	}

	str = EditOBAddr->Text;
	sprintf(buf, "  OB_ADDRESS    = \"%s\"\r\n", str.c_str());
	LuaAddString(buf);
	str = EditSecureOff->Text;
	sprintf(buf, "  OB_SECURE_OFF = \"%s\"\r\n", str.c_str());
	LuaAddString(buf);
	str = EditSecureOn->Text;
	sprintf(buf, "  OB_SECURE_ON  = \"%s\"\r\n", str.c_str());
	LuaAddString(buf);

	LuaAddString("\r\n");
	LuaAddString("  pg_reload_var()  --用于更新c程序的全局变量\r\n");

	LuaAddString("\r\n");
	LuaAddString("  --临时用测试bin替代\r\n");
	LuaAddString("  if (USE_TEST_BIN ~= nil) then\r\n");
	LuaAddString("     local i\r\n");
	LuaAddString("     for i = 1, #TaskList, 4 do\r\n");
	LuaAddString("       TaskList[i + 1] = USE_TEST_BIN\r\n");
	LuaAddString("     end\r\n");
	LuaAddString("  end\r\n");

	LuaAddString("end\r\n");
	LuaAddString("\r\n");

	MakeConfigFixData();	  //动态配置滚码 UID加密

	LuaAddString("\r\n");
	LuaAddString("MULTI_MODE = pg_read_c_var(\"MultiProgMode\")\r\n");

	LuaAddString("\r\n");
	LuaAddString("config_chip1()        --执行一次给全局变量赋初值\r\n");

	LuaAddString("\r\n");
	LuaAddString("config_fix_data()     --动态填充SN UID USR数据\r\n");

	LuaAddString("\r\n");
	LuaAddString("---------------------------结束-----------------------------------\r\n");
	LuaAddString("\r\n");
}

void __fastcall TFormProg::MakeLuaForSWIM(void)
{
	char buf[1024];
	AnsiString strManu;
	AnsiString strSerial;
	AnsiString strDevice;
	AnsiString strLua;
	AnsiString str;

	strManu = FormProg->ComboBoxManufacturer->Items->Strings[FormProg->ComboBoxManufacturer->ItemIndex];
	strSerial = FormProg->ComboBoxSerial->Items->Strings[FormProg->ComboBoxSerial->ItemIndex];
	strDevice = FormProg->ComboBoxDevice->Items->Strings[FormProg->ComboBoxDevice->ItemIndex];
	strLua = FormProg->LabelDeviceLuaFileName->Caption;

	g_LuaLen = 0;

	LuaAddString("--以下快捷方式将显示在PC软件界面-------------\r\n");
	LuaAddString("--F01=自动编程,start_prog()\r\n");
	LuaAddString("--F03=擦除flash,erase_chip(FLASH_ADDRESS)\r\n");
	LuaAddString("--F04=擦除eeprom,erase_chip(EEPROM_ADDRESS)\r\n");
	LuaAddString("--F05=打印flash,print_flash(FLASH_ADDRESS,512,16,FLASH_ADDRESS)\r\n");
	LuaAddString("--F06=打印eeprom,print_flash(EEPROM_ADDRESS,256,16,EEPROM_ADDRESS)\r\n");
	LuaAddString("--F07=打印UID,print_flash(UID_ADDR,12)\r\n");
	LuaAddString("--F08=打印内核id,print_core_id()\r\n");
	LuaAddString("--F09=修改RAM,pg_write_mem(0, \"1234\")\r\n");
	LuaAddString("--F10=读回RAM,print_flash(0, 16)\r\n");
	LuaAddString("--F12=掉电复位,beep() set_tvcc(0) delayms(500) set_tvcc(TVCC_VOLT) beep()\r\n");
	LuaAddString("--F13=硬件复位,pg_reset()\r\n");
	LuaAddString("--F14=设置读保护, set_read_protect(1)\r\n");
	LuaAddString("--F15=解除读保护, set_read_protect(0)\r\n");
	LuaAddString("--F16=打印Option Bytes,print_option_bytes()\r\n");
	LuaAddString("\r\n");

	sprintf(buf, "MANUFACTURER = \"%s\"\r\n", strManu.c_str());
	LuaAddString(buf);
	sprintf(buf, "SERIAL = \"%s\"\r\n", strSerial.c_str());
	LuaAddString(buf);
	sprintf(buf, "DEVICE = \"%s\"\r\n", strDevice.c_str());
	LuaAddString(buf);

	LuaAddString("\r\n");
	LuaAddString("--加载lua子文件-----------------------------------\r\n");
	{
		char strm[256];
		char strs[256];
		uint8_t filter;
		uint8_t ch;
		uint8_t pos;

		// 去掉厂商名字中的括号内数据
		filter  = 0;
		pos = 0;
		for (int i = 0; i < strlen(strManu.c_str()); i++)
		{
			ch = strManu.c_str()[i];

			if (filter == 0 && ch == '(')
			{
				 filter = 1;
			}
			else if (filter == 1 && ch == ')')
			{
				 filter = 0;
			}
			else
			{
				if (filter == 0)
				{
					strm[pos++] =  ch;
				}
			}
		}
		strm[pos] = 0;

		// 去掉系列名字中的括号内数据
		filter  = 0;
		pos = 0;
		for (int i = 0; i < strlen(strSerial.c_str()); i++)
		{
			ch = strSerial.c_str()[i];

			if (filter == 0 && ch == '(')
			{
				 filter = 1;
			}
			else if (filter == 1 && ch == ')')
			{
				 filter = 0;
			}
			else
			{
				if (filter == 0)
				{
					strs[pos++] =  ch;
				}
			}
		}
		strs[pos] = 0;

		sprintf(buf, "dofile(\"0:/H7-TOOL/Programmer/Device/%s/%s/%s\")\r\n",
			strm, strs, strLua.c_str());
	}

	LuaAddString(buf);

	LuaAddString("if IncludeList ~= nil then\r\n");
	LuaAddString("  local i\r\n");
	LuaAddString("  for i = 1,#IncludeList,1 do\r\n");
	LuaAddString("    print(\"dofile : \", IncludeList[i])\r\n");
	LuaAddString("    dofile(IncludeList[i])\r\n");
	LuaAddString("  end\r\n");
	LuaAddString("end\r\n");

	LuaAddString("\r\n");
	LuaAddString("--UID加密和产品序号处理文件\r\n");
	LuaAddString("dofile(\"0:/H7-TOOL/Programmer/LuaLib/fix_data.lua\")\r\n");
	LuaAddString("\r\n");

	if (ComboBoxEncryptEnable->ItemIndex)
	{
		sprintf(buf, "dofile(\"0:/H7-TOOL/Programmer/LuaLib/encrypt/%s\")\r\n", (AnsiString)ComboBoxAlgoLua->Text.c_str());
		LuaAddString(buf);
		LuaAddString("\r\n");
	}

	LuaAddString("--公共lua子程序\r\n");
	LuaAddString("dofile(\"0:/H7-TOOL/Programmer/LuaLib/prog_lib.lua\")\r\n");
	LuaAddString("\r\n");

	LuaAddString("--烧录机台接口程序\r\n");
	LuaAddString("dofile(\"0:/H7-TOOL/Programmer/LuaLib/machine_if.lua\")\r\n");
	LuaAddString("\r\n");

	LuaAddString("--下面的注释将显示在H7-TOOL液晶屏\r\n");
	str = EditNote1->Text.t_str();
	sprintf(buf, "Note01 = \"%s\"\r\n", str.c_str());
	LuaAddString(buf);
	LuaAddString("\r\n");

	//配置机台接口
	MakeMachineIF();
	LuaAddString("\r\n");

//	LuaAddString("\r\n");
//	LuaAddString("beep()\r\n");

	LuaAddString("\r\n");

	LuaAddString("--配置芯片接口和参数\r\n");
	LuaAddString("function config_chip1(void)\r\n");

	LuaAddString("  config_cpu()\r\n");
	LuaAddString("\r\n");

	LuaAddString("  --编程任务列表，可以任意追加\r\n");
	LuaAddString("  --文件名支持绝对路径和相对路径，相对路径时和lua文件同目录，支持../上级目录\r\n");
	LuaAddString("  TaskList = {\r\n");
	for (int i = 0; i < 10; i++) {
		if (mChkBox[i]->Checked)
		{
			if (i > 0)
			{
				LuaAddString("\r\n");
			}
			str = mComboBoxAlgo[i]->Text.t_str();
			sprintf(buf, "    \"%s\", --编程算法\r\n", str.c_str());
			LuaAddString(buf);

			str = g_OutputDataFile[i].t_str();
			sprintf(buf, "    \"%s\",  --数据文件\r\n", str.c_str());
			LuaAddString(buf);

			sprintf(buf, "    0x%08x,  --目标地址\r\n", StrToInt(mEditDataAddress[i]->Text));
			LuaAddString(buf);

			if (mChkEraseChip[i]->Checked)
			{
				LuaAddString("    1,  --0表示按扇区擦除, 1表示整片擦除\r\n");
			}
			else
			{
				LuaAddString("    0,  --0表示按扇区擦除, 1表示整片擦除\r\n");
			}
		}
	}
	LuaAddString("  }\r\n");

	LuaAddString("\r\n");

	sprintf(buf, "  DATA_FILE_CHECK_SUMS = 0x%08X\r\n", mDataFileSum);
	LuaAddString(buf);

	LuaAddString("\r\n");

	str = ValueListEditor1->Values[REMOVE_RDP_POWEROFF];
	sprintf(buf, "  REMOVE_RDP_POWEROFF = %s\r\n", str.c_str());
	LuaAddString(buf);

	str = ValueListEditor1->Values[POWEROFF_TIME1];
	sprintf(buf, "  POWEROFF_TIME1 = %s   --写完OB延迟时间ms\r\n", str.c_str());
	LuaAddString(buf);
	str = ValueListEditor1->Values[POWEROFF_TIME2];
	sprintf(buf, "  POWEROFF_TIME2 = %s   --断电时间ms\r\n",  str.c_str());
	LuaAddString(buf);
	str = ValueListEditor1->Values[POWEROFF_TIME3];
	sprintf(buf, "  POWEROFF_TIME3 = %s   --上电后等待时间ms\r\n",  str.c_str());
	LuaAddString(buf);

	LuaAddString("\r\n");

	LuaAddString("  --定义CPU供电电压TVCC\r\n");
	str = EditTVCC->Text;
	sprintf(buf, "  TVCC_VOLT = %s\r\n", str.c_str());
	LuaAddString(buf);
	LuaAddString("\r\n");

	LuaAddString("  --SWD时钟延迟，0不延迟，值越大速度越慢\r\n");
	LuaAddString("  if (MULTI_MODE == 0) then\r\n");
	sprintf(buf, "    SWD_CLOCK_DELAY = %s --单路烧录时的时钟延迟\r\n", (AnsiString)ValueListEditor1->Values[SWD_CLOCK_DELAY].c_str());
	LuaAddString(buf);
	LuaAddString("  else\r\n");
	sprintf(buf, "    SWD_CLOCK_DELAY = %s --多路烧录时的时钟延迟\r\n", (AnsiString)ValueListEditor1->Values[MUL_SWD_CLOCK_DELAY].c_str());
	LuaAddString(buf);
	LuaAddString("  end\r\n");
	LuaAddString("\r\n");

	sprintf(buf, "  RESET_MODE = %d --复位模式 0:自动模式,  1:软件模式  2:硬件UnderReset\r\n", ComboBoxResetMode->ItemIndex);
	LuaAddString(buf);

	sprintf(buf, "  RESET_DELAY = %s --复位后的延迟ms\r\n", (AnsiString)ValueListEditor1->Values[RESET_DELAY].c_str());
	LuaAddString(buf);
	LuaAddString("\r\n");

	LuaAddString("  --是否核对CPU内核ID\r\n");
	LuaAddString("  CHECK_MCU_ID = 0\r\n");
	LuaAddString("\r\n");

	sprintf(buf, "  VERIFY_MODE = %d  --校验模式: 0:自动(FLM提供校验函数或读回) 1:读回  2:软件CRC32  3:STM32硬件CRC32\r\n",
		ComboBoxVerifyMode->ItemIndex);
 	LuaAddString(buf);
	LuaAddString("\r\n");

	LuaAddString("  --编程结束后复位 0表示不复位  1表示硬件复位\r\n");
	if (CheckBoxAtfterAuotReset->Checked)
	{
		LuaAddString("  RESET_AFTER_COMPLETE = 1\r\n");
	}
	else
	{
		LuaAddString("  RESET_AFTER_COMPLETE = 0\r\n");
	}
	LuaAddString("\r\n");

	LuaAddString("  --1表示自动解除读保护和写保护\r\n");
	if (CheckBoxRemoveProtect->Checked)
	{
		LuaAddString("  AUTO_REMOVE_PROTECT = 1\r\n");
	}
	else
	{
		LuaAddString("  AUTO_REMOVE_PROTECT = 0\r\n");
	}
	LuaAddString("\r\n");

	if (LabelDeviceType->Caption == "SPI")
	{
		LuaAddString("\r\n");
		LuaAddString("  --SPI Flash读模式\r\n");
		str = ValueListEditor1->Values[SPI_READ_MODE];
		sprintf(buf, "  READ_MODE  = %s --0表示标准单线  1--表示双线读回\r\n", str.c_str());
		LuaAddString(buf);
	}

	LuaAddString("  --OPTION BYTES 配置\r\n");
	if (ComboBoxOB->ItemIndex == 0)
	{
		LuaAddString("  OB_ENABLE	= 0  --0表示编程完毕后不写OPTION BYTES\r\n\r\n");
		LuaAddString("  SECURE_ENABLE	= 0  --选择加密还是不加密\r\n");
	}
	else if (ComboBoxOB->ItemIndex == 1)
	{
		LuaAddString("  OB_ENABLE	= 1  --1表示编程完毕后写OPTION BYTES\r\n");
		LuaAddString("  SECURE_ENABLE	= 0  --选择加密还是不加密\r\n");
	}
	else
	{
		LuaAddString("  OB_ENABLE	= 1  --1表示编程完毕后写OPTION BYTES\r\n");
		LuaAddString("  SECURE_ENABLE	= 1  --选择加密还是不加密\r\n");
	}

	str = EditOBAddr->Text;
	sprintf(buf, "  OB_ADDRESS    = \"%s\"\r\n", str.c_str());
	LuaAddString(buf);
	str = EditSecureOff->Text;
	sprintf(buf, "  OB_SECURE_OFF = \"%s\"\r\n", str.c_str());
	LuaAddString(buf);
	str = EditSecureOn->Text;
	sprintf(buf, "  OB_SECURE_ON  = \"%s\"\r\n", str.c_str());
	LuaAddString(buf);

	LuaAddString("\r\n");
	LuaAddString("  pg_reload_var()  --用于更新c程序的全局变量\r\n");

	LuaAddString("\r\n");
	LuaAddString("  --临时用测试bin替代\r\n");
	LuaAddString("  if (USE_TEST_BIN ~= nil) then\r\n");
	LuaAddString("     local i\r\n");
	LuaAddString("     for i = 1, #TaskList, 4 do\r\n");
	LuaAddString("       TaskList[i + 1] = USE_TEST_BIN\r\n");
	LuaAddString("     end\r\n");
	LuaAddString("  end\r\n");

	LuaAddString("end\r\n");
	LuaAddString("\r\n");

	MakeConfigFixData();	  //动态配置滚码 UID加密

	LuaAddString("\r\n");
	LuaAddString("MULTI_MODE = pg_read_c_var(\"MultiProgMode\")\r\n");

	LuaAddString("\r\n");
	LuaAddString("config_chip1()        --执行一次给全局变量赋初值\r\n");

	LuaAddString("\r\n");
	LuaAddString("config_fix_data()     --动态填充SN UID USR数据\r\n");

	LuaAddString("\r\n");
	LuaAddString("---------------------------结束-----------------------------------\r\n");
	LuaAddString("\r\n");
}

// 打开文件
void __fastcall TFormProg::Button5Click(TObject *Sender)
{
	uint32_t DataFileSum = 0;

	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	// 转换HEX为bin
	{
		UnicodeString ExtName;
		int i;
		UnicodeString s;

		for (i = 0; i < 10; i++)
		{
			if (mChkBox[i]->Checked)
			{
				g_HexLen = ReadFileToMem(g_InputDataFile[i], g_HexFile, sizeof(g_HexFile));
				if (g_HexLen > 0)
				{
					;
				}
				else
				{
					Form1->MemoLuaOut->Lines->Add("读取数据文件失败 #" + IntToStr(i + 1));
					Form1->MemoLuaOut->Lines->Add("  文件名称: " + g_InputDataFile[i]);
					goto err_quit;
				}

				ExtName = ExtractFileExt(g_InputDataFile[i]);
				ExtName = ExtName.LowerCase();
				if (ExtName == ".hex")
				{
					uint32_t StartAddress;
					AnsiString str;

					g_BinLen = MyHexToBin(g_HexFile, g_HexLen, g_BinFile, sizeof(g_BinFile), 0xFF, &StartAddress);

					s =  mEditDataFile[i]->Text + ".bin";

					// 处理目标地址
					if (ComboBoxSerial->Text != "8051")   // 8051的HEX文件地址不自动填充，用于烧写LDROM
					{
						str.sprintf("0x%08X", StartAddress);
						mEditDataAddress[i]->Text = str;
					}

					g_OutputDataFile[i] = s;
					s = AppExePath() + "\\" + MemoOutputDir->Text + "\\" + s;

					if (SaveMemToFile(s, g_BinFile, g_BinLen) == 0)
					{
						Form1->MemoLuaOut->Lines->Add("保存文件失败 " + s);
						goto err_quit;
					}

					DataFileSum += GetFileSums(s);
				}
				else if (ExtName == ".bin")
				{
					s =  mEditDataFile[i]->Text;

					g_OutputDataFile[i] = s;
					s = AppExePath() + "\\" + MemoOutputDir->Text + "\\" + s;

					CopyFile(g_InputDataFile[i].w_str() , s.w_str(), false);

					DataFileSum += GetFileSums(s);
				}
				else
				{
					Form1->MemoLuaOut->Lines->Add("未知文件格式 #" + IntToStr(i + 1));
					goto err_quit;
				}
			}
		}
	}

	mDataFileSum = DataFileSum;	/* 数据文件校验和 */

	if (LabelDeviceType->Caption == "SWD")
	{
		MakeLuaForSWD();
	}
	else if (LabelDeviceType->Caption == "SWIM")
	{
		MakeLuaForSWIM();
	}
	else if (LabelDeviceType->Caption == "NUVOTON_8051")
	{
		MakeLuaForSWIM();
	}
	else
	{
		MakeLuaForSWIM();
	}

	/* 输出到文本窗口 */
	#if 0
		Form1->MemoLuaOut->SelAttributes->Color = clMaroon;
		Form1->MemoLuaOut->Lines->Add(g_LuaProg) ;
	#endif

	// 保存到 lua
	Form1->MemoLuaOut->Lines->Add("生成烧录配置文件");
	Form1->MemoLuaOut->Lines->Add("输出文件夹: ");

	Form1->MemoLuaOut->Lines->Add(AppExePath() + "\\" + MemoOutputDir->Text);
	{
		UnicodeString s;
		AnsiString str;

		s = AppExePath() + "\\" + MemoOutputDir->Text + "\\" + EditOutFileName->Text + L".lua";
		if (SaveMemToFile(s, g_LuaProg, g_LuaLen) > 0)
		{
			FormLua->RichEditFileName->Text = s;
			Form1->MemoLuaOut->Lines->Add("  " + EditOutFileName->Text + L".lua");
		}
		else
		{
			Form1->MemoLuaOut->Lines->Add("保存文件失败" + s);
			goto err_quit;
		}
	}

	// 配置 ini文件
	{
		UnicodeString s;
		AnsiString str;

		g_LuaLen = 0;
		LuaAddString("Locked = 0\r\n");

		str.sprintf("ProgramLimit = %d\r\n", StrToInt(EditProgrammedLimit->Text));
		LuaAddString(str.c_str());

		str.sprintf("ProgrammedCount = %d\r\n", 0);
		LuaAddString(str.c_str());

		str.sprintf("ProductSN = %d\r\n", StrToInt(EditSNInitValue->Text));
		LuaAddString(str.c_str());

		// 开始保存
		s = AppExePath() + "\\" + MemoOutputDir->Text + "\\" + EditOutFileName->Text + L".ini";
		if (SaveMemToFile(s, g_LuaProg, g_LuaLen) > 0)
		{
			Form1->MemoLuaOut->Lines->Add("  " + EditOutFileName->Text + L".ini");
		}
		else
		{
			Form1->MemoLuaOut->Lines->Add("保存文件失败" + s);
			goto err_quit;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (mChkBox[i]->Checked)
		{
			Form1->MemoLuaOut->Lines->Add("  " + g_OutputDataFile[i]);
		}
	}

	Form1->MemoLuaOut->Lines->Add("");

	{
		char buf[64];

		sprintf(buf, "0x%08X", mDataFileSum);
		Form1->MemoLuaOut->Lines->Add("数据文件累加校验和 : " + (AnsiString)buf);
	}

	Form1->MemoLuaOut->Lines->Add("");
	Form1->MemoLuaOut->Lines->Add("执行成功!");
	Form1->MemoLuaOut->Lines->Add("请将上述文件复制到H7-TOOL的EMMC磁盘");
	Form1->MemoLuaOut->Lines->Add("目录: /H7-TOOL/Programmer/User");

	Form1->MemoLuaOut->Lines->Add("");
	Form1->MemoLuaOut->Lines->Add("【烧录临时文件】使用H7-TOOL上的测试bin验证烧录算法");
	return;  // OK

err_quit:
	return;  // 出错
}

//读lua中的整数变量-------------------------------------------------------------------------
int32_t ReadLuaInt32(char *_VarName, int32_t _Default)
{
	int32_t re;
	int32_t err;

	re = _Default;
	lua_getglobal(g_Lua, _VarName);
	if (lua_isinteger(g_Lua, -1))
	{
		re = lua_tointeger(g_Lua, -1);
	}
	else
	{
		err = 1;
	}
	lua_pop(g_Lua, 1);
	if (err == 1)
	{
		//Form1->MemoLuaOut->Lines->Add("脚本错误" + (AnsiString)_VarName);
	}
	return re;
}

//读lau字符串变量
AnsiString ReadLuaString(char *_VarName)
{
	const char *p;
	int32_t err;

	p = "";
	lua_getglobal(g_Lua, _VarName);
	if (lua_isstring(g_Lua, -1))
	{
		p = lua_tostring(g_Lua, -1);
	}
	else
	{
		err = 1;
	}
	lua_pop(g_Lua, 1);
	if (err == 1)
	{
		Form1->MemoLuaOut->Lines->Add("脚本错误" + (AnsiString)_VarName);
	}
	return AnsiString(p);
}

void __fastcall TFormProg::ComboBoxDeviceChange(TObject *Sender)
{
	AnsiString strManu;
	AnsiString strSerial;
	AnsiString strDevice;
	AnsiString strLua;
	AnsiString str;

	str = (AnsiString)g_DeviceList[g_SelDeviceIndex[FormProg->ComboBoxDevice->ItemIndex]].Lua;
	FormProg->LabelDeviceLuaFileName->Caption = str;

	strManu = FormProg->ComboBoxManufacturer->Items->Strings[FormProg->ComboBoxManufacturer->ItemIndex];
	strSerial = FormProg->ComboBoxSerial->Items->Strings[FormProg->ComboBoxSerial->ItemIndex];
	strDevice = FormProg->ComboBoxDevice->Items->Strings[FormProg->ComboBoxDevice->ItemIndex];
	strLua = FormProg->LabelDeviceLuaFileName->Caption;

	EditOutFileName->Text = "demo_" + strDevice;
	// 器件更新时，PC机加载lua，获取Option bytes变量
	{
		AnsiString s1,s2;
		char strm[256];
		char strs[256];
		uint8_t filter  = 0;
		uint8_t ch;
		uint8_t pos = 0;

		// 去掉公司名中括号内注释
		pos = 0;
		filter  = 0;
		for (int i = 0; i < strlen(strManu.c_str()); i++)
		{
			ch = strManu.c_str()[i];

			if (filter == 0 && ch == '(')
			{
				 filter = 1;
			}
			else if (filter == 1 && ch == ')')
			{
				 filter = 0;
			}
			else
			{
				if (filter == 0)
				{
					strm[pos++] =  ch;
				}
			}
		}
		strm[pos] = 0;

		// 去掉系列名中括号内注释
		pos = 0;
		filter  = 0;
		for (int i = 0; i < strlen(strSerial.c_str()); i++)
		{
			ch = strSerial.c_str()[i];

			if (filter == 0 && ch == '(')
			{
				 filter = 1;
			}
			else if (filter == 1 && ch == ')')
			{
				 filter = 0;
			}
			else
			{
				if (filter == 0)
				{
					strs[pos++] =  ch;
				}
			}
		}
		strs[pos] = 0;

		s2.sprintf("\\EMMC\\H7-TOOL\\Programmer\\Device\\%s\\%s\\%s",
			strm, strs, strLua.c_str());
		s1 = AppExePath() + s2;

		/* 打开文件, 读文件数据 */
		{
			int iFileHandle;
			int iBytesRead;
			int iFileLength;

			iFileHandle = FileOpen(s1, fmOpenRead);
			if (iFileHandle > 0)
			{
				  iFileLength = FileSeek(iFileHandle, 0, 2);

				  if (iFileLength <= 2 * 1024 * 1024)
				  {
						FileSeek(iFileHandle, 0, 0);
						FileRead(iFileHandle, g_PCLuaBuf, iFileLength);
						g_PCLuaLen = iFileLength;
						g_PCLuaBuf[g_PCLuaLen] = 0;

						FileClose(iFileHandle);
				  }
				  else
				  {
						FileClose(iFileHandle);
						Form1->MemoLuaOut->Lines->Add(s1 + "  文件过大(>2M)");
				  }
			}
			else
			{
				Form1->MemoLuaOut->Lines->Add(s1 + "  文件打开失败");
			}
		}

		// 开始执行
		{
			int err = 0;
			const char *p1;
			char cmd0[256];
			int iValue;

			lua_DeInit();

			lua_Init();

			lua_do(g_PCLuaBuf);

			sprintf(cmd0, "DEVICE = \"%s\"", strDevice);
			lua_do(cmd0);
			lua_do("config_cpu()");
			lua_do("pc_default()");

			// 读lua中的全局变量 OB_ADDRESS
			lua_getglobal(g_Lua, "OB_ADDRESS");
            if (lua_isstring(g_Lua, -1))
            {
				p1 = lua_tostring(g_Lua, -1);
				EditOBAddr->Text = p1;
            }
            else
            {
                err = 1;
            }
            lua_pop(g_Lua, 1);
            if (err == 1)
            {
				Form1->MemoLuaOut->Lines->Add("脚本错误 OB_ADDRESS");
			}

			// 读lua中的全局变量 OB_SECURE_OFF
			lua_getglobal(g_Lua, "OB_SECURE_OFF");
            if (lua_isstring(g_Lua, -1))
            {
				p1 = lua_tostring(g_Lua, -1);
				EditSecureOff->Text = p1;
            }
            else
            {
                err = 1;
            }
            lua_pop(g_Lua, 1);
            if (err == 1)
            {
				Form1->MemoLuaOut->Lines->Add("脚本错误 OB_SECURE_OFF");
			}

			// 读lua中的全局变量 OB_SECURE_ON
			lua_getglobal(g_Lua, "OB_SECURE_ON");
			if (lua_isstring(g_Lua, -1))
			{
				p1 = lua_tostring(g_Lua, -1);
				EditSecureOn->Text = p1;
			}
			else
			{
				err = 1;
			}
			lua_pop(g_Lua, 1);
            if (err == 1)
            {
				Form1->MemoLuaOut->Lines->Add("脚本错误 OB_SECURE_ON");
			}

			// 读lua中的全局变量 FLASH_ADDRESS
			lua_getglobal(g_Lua, "FLASH_ADDRESS");
			if (lua_isinteger(g_Lua, -1))
			{
				uint32_t addr;
				AnsiString str;

				addr = lua_tointeger(g_Lua, -1);
				str.sprintf("0x%08X", addr);
				EditDataAddress1->Text = str;
				EditDataAddress2->Text = str;
				EditDataAddress3->Text = str;
				EditDataAddress4->Text = str;
				EditDataAddress5->Text = str;
				EditDataAddress6->Text = str;
				EditDataAddress7->Text = str;
				EditDataAddress8->Text = str;
				EditDataAddress9->Text = str;
				EditDataAddress10->Text = str;

				//读flash界面的初始地址
				EditReadAddr->Text = str;
			}
			else
			{
				err = 1;
			}
			lua_pop(g_Lua, 1);
			if (err == 1)
			{
				Form1->MemoLuaOut->Lines->Add("脚本错误 FLASH_ADDRESS");
			}

			// 读lua中的全局变量 CHIP_TYPE
			LabelDeviceType->Caption = ReadLuaString("CHIP_TYPE");
			LabelPCNote->Caption = ReadLuaString("NOTE_PC");

//			TVCC_VOLT = 3.3			--定义CPU供电电压TVCC
//
//			VERIFY_MODE = 2			--校验模式: 0:自动(FLM提供校验函数或读回) 1:读回  2:软件CRC32  3:STM32硬件CRC32
//
//			REMOVE_RDP_POWEROFF = 1 --写完OB后需要断电
//			POWEROFF_TIME1 = 0   	--写完OB延迟时间ms
//			POWEROFF_TIME2 = 100   	--断电时间ms
//			POWEROFF_TIME3 = 20   	--上电后等待时间ms
//
//			SWD_CLOCK_DELAY_0 = 5 	--单路烧录时的时钟延迟
//			SWD_CLOCK_DELAY_1 = 0 	--多路烧录时的时钟延迟
//
//			AUTO_REMOVE_PROTECT = 1 --自动解除读保护
//
//			NOTE_PC = ""

			if (ReadLuaInt32("AUTO_REMOVE_PROTECT", 0) == 0)
				CheckBoxRemoveProtect->Checked = 0;
			else
				CheckBoxRemoveProtect->Checked = 1;
			ComboBoxVerifyMode->ItemIndex = ReadLuaInt32("VERIFY_MODE", 1);

			iValue = ReadLuaInt32("REMOVE_RDP_POWEROFF", 0);
			if (iValue == 0)
				ValueListEditor1->Values[REMOVE_RDP_POWEROFF] = "0 --禁用";
			else
				ValueListEditor1->Values[REMOVE_RDP_POWEROFF] = "1 --启用";
			ValueListEditor1->Values[POWEROFF_TIME1] = IntToStr(ReadLuaInt32("POWEROFF_TIME1", 0));
			ValueListEditor1->Values[POWEROFF_TIME2] = IntToStr(ReadLuaInt32("POWEROFF_TIME2", 100));
			ValueListEditor1->Values[POWEROFF_TIME3] = IntToStr(ReadLuaInt32("POWEROFF_TIME3", 20));
			ValueListEditor1->Values[SWD_CLOCK_DELAY] = IntToStr(ReadLuaInt32("SWD_CLOCK_DELAY_0", 20));
			ValueListEditor1->Values[MUL_SWD_CLOCK_DELAY] = IntToStr(ReadLuaInt32("SWD_CLOCK_DELAY_1", 20));
			ValueListEditor1->Values[RESET_DELAY] = IntToStr(ReadLuaInt32("SWD_RESET_DELAY", 20));

			ValueListEditor1->Values[MUL_DELAYUS_READ_DATA] = IntToStr(ReadLuaInt32("MUL_DELAYUS_READ_DATA", 0));

			ComboBoxResetMode->ItemIndex = ReadLuaInt32("RESET_MODE", 0);

			if (ReadLuaInt32("ERASE_CHIP_MODE", 1) == 0)
			{
				CheckBoxEraseChip_1->Checked = false;
			}
			else
			{
				CheckBoxEraseChip_1->Checked = true;
			}

//	AlgoFile_FLASH = "0:/H7-TOOL/Programmer/Device/Nuvoton/FLM/M0518_AP_36.FLM"
//	AlgoFile_OTP   = ""
//	AlgoFile_OPT   = "0:/H7-TOOL/Programmer/Device/Nuvoton/FLM/M0518_CFG.FLM"
//	AlgoFile_QSPI  = ""
//
//	AlgoFile_AP	   = AlgoFile_FLASH
//	AlgoFile_LD	   = "0:/H7-TOOL/Programmer/Device/Nuvoton/FLM/M0518_LD_4.FLM"
//	AlgoFile_DAT   = "0:/H7-TOOL/Programmer/Device/Nuvoton/FLM/M0518_DAT.FLM"
//	AlgoFile_CFG   = AlgoFile_OPT

			// 填充算法列表
			ComboBoxDataAlgo1->Clear();
			ComboBoxDataAlgo2->Clear();
			ComboBoxDataAlgo3->Clear();

			// 读lua中的全局变量 FLASH_ADDRESS
			err = lua_getglobal(g_Lua, "AlgoFile_List");
			if (err == 5)
			{
				for (int i = 0; i < 20; i++)
				{
					lua_pushinteger(g_Lua, i + 1);  //c->statck，设置key值，位置-1(上面的-1变为-2)
					lua_gettable(g_Lua, -2);//返回值为值的类型
					if (lua_isstring(g_Lua, -1))
					{
						size_t len;
						const char *pData;
						char buf[256];
						uint16_t k;

						pData = luaL_checklstring(g_Lua, -1, &len); /* 1是参数的位置， len是string的长度 */
						for (k = 0; k < len; k++)
						{
							buf[k] = pData[k];
						}
						buf[len] = 0;
						ComboBoxDataAlgo1->Items->Add((AnsiString)buf);

						lua_pop(g_Lua, 1);
					}
					else
					{
						lua_pop(g_Lua, 1);
						break;
					}
				}
			}
			else	/* 旧lua没有 AlgoFile_List 字段 */
			{
				lua_getglobal(g_Lua, "AlgoFile_AP");
				if (lua_isstring(g_Lua, -1)) {
					p1 = lua_tostring(g_Lua, -1);
					if (p1[0] > 0) ComboBoxDataAlgo1->Items->Add("AlgoFile_AP");
				}
				lua_pop(g_Lua, 1);

				lua_getglobal(g_Lua, "AlgoFile_LD");
				if (lua_isstring(g_Lua, -1)) {
					p1 = lua_tostring(g_Lua, -1);
					if (p1[0] > 0) ComboBoxDataAlgo1->Items->Add("AlgoFile_LD");
				}
				lua_pop(g_Lua, 1);

				lua_getglobal(g_Lua, "AlgoFile_DAT");
				if (lua_isstring(g_Lua, -1)) {
					p1 = lua_tostring(g_Lua, -1);
					if (p1[0] > 0) ComboBoxDataAlgo1->Items->Add("AlgoFile_DAT");
				}
				lua_pop(g_Lua, 1);

				lua_getglobal(g_Lua, "AlgoFile_CFG");
				if (lua_isstring(g_Lua, -1)) {
					p1 = lua_tostring(g_Lua, -1);
					if (p1[0] > 0) ComboBoxDataAlgo1->Items->Add("AlgoFile_CFG");
				}
				lua_pop(g_Lua, 1);

				lua_getglobal(g_Lua, "AlgoFile_FLASH");
				if (lua_isstring(g_Lua, -1)) {
					p1 = lua_tostring(g_Lua, -1);
					if (p1[0] > 0) ComboBoxDataAlgo1->Items->Add("AlgoFile_FLASH");
				}
				lua_pop(g_Lua, 1);

				lua_getglobal(g_Lua, "AlgoFile_OPT");
				if (lua_isstring(g_Lua, -1)) {
					p1 = lua_tostring(g_Lua, -1);
					if (p1[0] > 0) ComboBoxDataAlgo1->Items->Add("AlgoFile_OPT");
				}
				lua_pop(g_Lua, 1);

				lua_getglobal(g_Lua, "AlgoFile_OTP");
				if (lua_isstring(g_Lua, -1)) {
					p1 = lua_tostring(g_Lua, -1);
					if (p1[0] > 0) ComboBoxDataAlgo1->Items->Add("AlgoFile_SPI");
				}
				lua_pop(g_Lua, 1);

				lua_getglobal(g_Lua, "AlgoFile_EEPROM");
				if (lua_isstring(g_Lua, -1)) {
					p1 = lua_tostring(g_Lua, -1);
					if (p1[0] > 0) ComboBoxDataAlgo1->Items->Add("AlgoFile_EEPROM");
				}
				lua_pop(g_Lua, 1);

				lua_getglobal(g_Lua, "AlgoFile_QSPI");
				if (lua_isstring(g_Lua, -1)) {
					p1 = lua_tostring(g_Lua, -1);
					if (p1[0] > 0) ComboBoxDataAlgo1->Items->Add("AlgoFile_QSPI");
				}
				lua_pop(g_Lua, 1);

				lua_getglobal(g_Lua, "AlgoFile_SPI");
				if (lua_isstring(g_Lua, -1)) {
					p1 = lua_tostring(g_Lua, -1);
					if (p1[0] > 0) ComboBoxDataAlgo1->Items->Add("AlgoFile_SPI");
				}
				lua_pop(g_Lua, 1);

				lua_getglobal(g_Lua, "AlgoFile_NAND");
				if (lua_isstring(g_Lua, -1)) {
					p1 = lua_tostring(g_Lua, -1);
					if (p1[0] > 0) ComboBoxDataAlgo1->Items->Add("AlgoFile_NAND");
				}
				lua_pop(g_Lua, 1);
			}
			lua_pop(g_Lua, 1);

			ComboBoxDataAlgo2->Items = ComboBoxDataAlgo1->Items;
			ComboBoxDataAlgo3->Items = ComboBoxDataAlgo1->Items;
			ComboBoxDataAlgo4->Items = ComboBoxDataAlgo1->Items;
			ComboBoxDataAlgo5->Items = ComboBoxDataAlgo1->Items;
			ComboBoxDataAlgo6->Items = ComboBoxDataAlgo1->Items;
			ComboBoxDataAlgo7->Items = ComboBoxDataAlgo1->Items;
			ComboBoxDataAlgo8->Items = ComboBoxDataAlgo1->Items;
			ComboBoxDataAlgo9->Items = ComboBoxDataAlgo1->Items;
			ComboBoxDataAlgo10->Items = ComboBoxDataAlgo1->Items;

			ComboBoxDataAlgo1->ItemIndex = 0;
			ComboBoxDataAlgo2->ItemIndex = 0;
			ComboBoxDataAlgo3->ItemIndex = 0;
			ComboBoxDataAlgo4->ItemIndex = 0;
			ComboBoxDataAlgo5->ItemIndex = 0;
			ComboBoxDataAlgo6->ItemIndex = 0;
			ComboBoxDataAlgo7->ItemIndex = 0;
			ComboBoxDataAlgo8->ItemIndex = 0;
			ComboBoxDataAlgo9->ItemIndex = 0;
			ComboBoxDataAlgo10->ItemIndex = 0;
		}
	}
}
//---------------------------------------------------------------------------



void __fastcall TFormProg::ButtonFile1Click(TObject *Sender)
{
	TButton *btn;
	AnsiString name;
	int idx;

	// ButtonFile1
	btn = (TButton *)Sender;
	name =  btn->Name;
	idx = StrToInt(&name.c_str()[10]);
	if (idx > 0)
	{
    	idx--;
	}
	OpenDialog1->InitialDir = ExtractFilePath(g_InputDataFile[idx]);
	if (OpenDialog1->Execute())
	{
		// 将文件复制到目录
		mEditDataFile[idx]->Text =  ExtractFileName(OpenDialog1->FileName);
		g_InputDataFile[idx] = OpenDialog1->FileName;

		GetHexFileStartAddress(idx);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormProg::ButtonSelectFoldClick(TObject *Sender)
{
	TCHAR sz[256];

	String s1 = AppExePath();

	s1 = s1 + "\\EMMC\\H7-TOOL\\Programmer";
	//s1  = "F:\\数据恢复\\No3\\MyWork\\00.PC软件\\23.H7-TOOL_PC\\H7-TOOL测试软件\\Win32\\Debug\\EMMC\\H7-TOOL\\Programmer";
	if (CrnBrowseDir(Handle, s1, L"请在Programmer\\User文件夹下面选择或新建文件夹", sz))
	{
		/* 只显示部分文件路径 */
		AnsiString s2;
		AnsiString s3;

		s2 = sz;
		s3 = AppExePath();
		MemoOutputDir->Text = (AnsiString)&s2.c_str()[s3.Length() + 1];;
	}
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

// 浏览输出目录

void __fastcall TFormProg::ButtonOBhelpClick(TObject *Sender)
{
	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	Form1->MemoLuaOut->Lines->Add("-----选项字操作说明-----");
	Form1->MemoLuaOut->Lines->Add("芯片型号: " + ComboBoxDevice->Items->Strings[FormProg->ComboBoxDevice->ItemIndex]);
	Form1->MemoLuaOut->Lines->Add("选项字地址排列:");
	Form1->MemoLuaOut->Lines->Add(EditOBAddr->Text);

	Form1->MemoLuaOut->Lines->Add("");
	Form1->MemoLuaOut->Lines->Add("备注");
	if (LabelDeviceType->Caption == "SWD")
	{
		Form1->MemoLuaOut->Lines->Add(" - FFFFFFFF表示自动填充前1个字节的反码");
		Form1->MemoLuaOut->Lines->Add(" - FFFFFFFE表示自动填充前2个字节的反码");
	}
	else if (LabelDeviceType->Caption == "SWIM")
	{
		Form1->MemoLuaOut->Lines->Add(" - FFFF表示自动填充前1个字节的反码");
		Form1->MemoLuaOut->Lines->Add(" - FFFE表示自动填充前2个字节的反码");
	}
	Form1->MemoLuaOut->Lines->Add(" - 遇到反码字节程序会自动插入，无需输入OB数组");
	Form1->MemoLuaOut->Lines->Add(" - 请查找芯片数据手册确定数据含义");
}
//---------------------------------------------------------------------------


void __fastcall TFormProg::Button6Click(TObject *Sender)
{
	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	if (g_tIniParam.CommInterface == 0 && Form1->CheckBoxUDP777->Checked == false)
	{
	   Form1->MemoLuaOut->Lines->Add("以太网连接时，请勾选打开UDP监听端口777");
	}
	else
	{
		mStatus = 0;
		Timer1->Interval = 1;
		Timer1->Enabled = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormProg::Timer1Timer(TObject *Sender)
{
	switch (mStatus)
	{
		case 0:
			FormLua->ButtonDownLuaFileClick(this);	// 下载lua
			Timer1->Interval = 100;
			mStatus++;
			break;

		case 1:
			if (g_tCmd.UserReq == 0)
			{
				mStatus++;
			}
			break;

		case 2:
			{
				AnsiString s;
				AnsiString s1,s2;
				char buf[256];

				if (ComboBoxTempDataFile->ItemIndex == 0)  // 原始固件
				{
					int i;
					char cc;

					s1 = MemoOutputDir->Text;

					for (i = 0; i < s1.Length() ; i++)
					{
						cc = s1.c_str()[i];
						if (cc == '\\')
						{
							cc = '/';
						}
						buf[i] = cc;
					}
					buf[i] = 0;

					s2 = EditDataFile1->Text;
					{
						UnicodeString ExtName;
						ExtName = ExtractFileExt(EditDataFile1->Text);
						ExtName = ExtName.LowerCase();
						if (ExtName == ".hex")
						{
							s2 = s2 + ".bin";
						}
					}
					s.sprintf("USE_TEST_BIN=\"0:/H7-TOOL/%s/%s\"", buf+13,
						s2.c_str());
				}
				else
				{
 					s = "USE_TEST_BIN=\"0:/H7-TOOL/Programmer/User/TestBin/"
						+ ComboBoxTempDataFile->Text + "\"";
				}

				FormTcp->DoLuaSend64H(s);
			}
			Timer1->Interval = 100;
			mStatus++;
			break;

		case 3:
			if (g_tCmd.UserReq == 0)
			{
				mStatus++;
			}
			break;

		case 4:
			{
				AnsiString s;
				s = "start_prog() --USE_TEST_BIN=nil";
				//udp_Send65H((char *)s.c_str(), s.Length());

				FormTcp->DoLuaSend64H(s);
			}
			Timer1->Interval = 100;
			mStatus++;
			break;

		case 5:
			if (g_tCmd.UserReq == 0)
			{
				mStatus++;
			}
			break;

		default:
			Timer1->Enabled = false;
			break;
	}
}
//---------------------------------------------------------------------------



//双击厂商
void __fastcall TFormProg::Label1Click(TObject *Sender)
{
	/* 打开文件, 读文件数据 */
	{
		int iFileHandle;
		int iBytesRead;
		int iFileLength;

		AnsiString s1;
		int temp;

		g_DeviceMem[0] = 0;
		g_DeviceCount = 0;

		s1 = AppExePath() + "\\EMMC\\H7-TOOL\\Programmer\\Device\\device.csv";

		iFileHandle = FileOpen(s1, fmOpenRead);
		if (iFileHandle > 0)
		{
			iFileLength = FileSeek(iFileHandle, 0, 2);

			if (iFileLength < CSV_FILE_LEN_MAX)
			{
				g_DeviceMem[iFileLength] = 0;

				FileSeek(iFileHandle, 0, 0);
				FileRead(iFileHandle, g_DeviceMem, iFileLength);
				g_DeviceMem[iFileLength] = 0;
			}
			else
			{
				;
			}
			FileClose(iFileHandle);
		}
	}

	ReadDeviceList(g_DeviceMem);

	FreshComboxList();

	ComboBoxDeviceChange(this);
}

//---------------------------------------------------------------------------
int FindFileList(AnsiString pathFrom)
{
	WIN32_FIND_DATA wfd;//存放文件信息
	HANDLE handle;
	uint32_t pos = 0;

	//文件夹不存在
	if (!DirectoryExists(pathFrom))
	{
		return 0;
	}

	String strFind = pathFrom + "\\*";

	handle = FindFirstFile(strFind.c_str(), &wfd);
	if (INVALID_HANDLE_VALUE == handle)
	{
		return 0;
	}

	while (1)
	{
		String newPathFrom = pathFrom + "\\" + wfd.cFileName;

		if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)  // 目录
		{
			AnsiString s1;
			//如果不是当前文件夹或者是上层文件夹，则递归调用自己继续拷贝
			//if ((strcmp(wfd.cFileName, ".") != 0) && (strcmp(wfd.cFileName, "..") != 0))

			s1 =  wfd.cFileName;
			if (strcmp(s1.c_str(), ".") != 0 && strcmp(s1.c_str(), "..") != 0)
			{
				FormProg->ListFileName->Add(wfd.cFileName);
				FormProg->ListFilePath->Add(pathFrom);
				FormProg->ListFileType->Add("Dir");

				//wfd.ftLastWriteTime

//				TListItem *li = FormProg->ListView1->Items->Add();
//				li->Caption = wfd.cFileName;
//				li->ImageIndex = 1;
//				li->SubItems->Add(pathFrom);

				FindFileList(newPathFrom);
			}
		}
		else   // 文件
		{
//			TListItem *li = FormProg->ListView1->Items->Add();
//			li->Caption = wfd.cFileName;
//			li->ImageIndex = 0;
//			li->SubItems->Add(pathFrom);

			FormProg->ListFileName->Add(wfd.cFileName);
			FormProg->ListFilePath->Add(pathFrom);
			FormProg->ListFileType->Add("File");
		}

		//寻找下一个
		if (FindNextFile(handle, &wfd) == 0)
		{
			break;
		}
	}
	FindClose(handle);
}

void __fastcall TFormProg::Button7Click(TObject *Sender)
{
	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	/* 填充传输文件列表 */
	{
		String s1;

		s1 = AppExePath() + "\\" + MemoOutputDir->Text;

		ListFilePath->Clear();
		ListFileName->Clear();
		ListFileType->Clear();

		ListFilePath->Add(s1);
		ListFileName->Add("");
		ListFileType->Add("Dir");

		ListFilePath->Add(s1);
		ListFileName->Add(EditOutFileName->Text + L".lua");
		ListFileType->Add("File");

		ListFilePath->Add(s1);
		ListFileName->Add(EditOutFileName->Text + L".ini");
		ListFileType->Add("File");

		for (int i = 0; i < 10; i++)
		{
			if (mChkBox[i]->Checked)
			{
				ListFilePath->Add(s1);
				ListFileName->Add(g_OutputDataFile[i]);
				ListFileType->Add("File");
			}
		}
	}

	/* 通知线程开始传输 */
	g_tCmd.UserCmdStatus = CMDS_UPDATE_CHIP_FILE;
	g_tCmd.UserReq = 1;
}
//---------------------------------------------------------------------------



void __fastcall TFormProg::Button2Click(TObject *Sender)
{
	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	AnsiString s;

	s = "全片擦除: 打钩表示擦除模式为全片擦除。不打钩表示擦除模式是扇区擦除";
	Form1->MemoLuaOut->Lines->Add(s);
	Form1->MemoLuaOut->Lines->Add("");
	Form1->MemoLuaOut->Lines->Add("算法选择: 除了选择下拉列表，也可以指定自己的FLM算法文件");
	Form1->MemoLuaOut->Lines->Add("  例如: 在选择框直接输入 \"0:/H7-TOOL/Programmer/Device/ST/STM32F0xx/STM32F0xx_16.FLM\" ");
	Form1->MemoLuaOut->Lines->Add("        注意必须使用双引号将文件路径括起来");
}
//---------------------------------------------------------------------------

// 读flash测试
void __fastcall TFormProg::ButtonReadFlashClick(TObject *Sender)
{
	AnsiString s;
	uint32_t addr;
	uint32_t offset;

	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	addr = MyStrToInt(EditReadAddr->Text);
	offset = MyStrToInt(EditReadOffset->Text);
	addr = addr + offset * 1024;
	s.sprintf("print_flash(0x%08X,1024,32,0x%08X)", addr, addr);
	//udp_Send65H((char *)s.c_str(), s.Length());
	FormTcp->DoLuaSend64H(s);
}
//---------------------------------------------------------------------------

// 上一页
void __fastcall TFormProg::Button4Click(TObject *Sender)
{
	uint32_t offset;

	offset = MyStrToInt(EditReadOffset->Text);
	if (offset > 0)
	{
		offset--;
	}
	EditReadOffset->Text = IntToStr((__int64)offset);
	ButtonReadFlashClick(this);
}
//---------------------------------------------------------------------------

// 下一页
void __fastcall TFormProg::Button13Click(TObject *Sender)
{
	uint32_t offset;

	offset = MyStrToInt(EditReadOffset->Text);
	offset++;
	EditReadOffset->Text = IntToStr((__int64)offset);
	ButtonReadFlashClick(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormProg::Button3Click(TObject *Sender)
{
	EditReadOffset->Text = "0";

	ButtonReadFlashClick(this);
}
//---------------------------------------------------------------------------


void __fastcall TFormProg::Button14Click(TObject *Sender)
{
	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	Form1->MemoLuaOut->Lines->Add("读FLASH数据...");

	/* 通知线程开始传输 */
	g_tCmd.UserCmdStatus = CMDS_SWD_READ_FLASH;
	g_tCmd.UserReq = 1;
}
//---------------------------------------------------------------------------


void __fastcall TFormProg::ButtonMachineHelpClick(TObject *Sender)
{
	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	Form1->MemoLuaOut->Lines->Add("机台信号定义:");
	Form1->MemoLuaOut->Lines->Add("【单路模式ARM】");
	Form1->MemoLuaOut->Lines->Add(" --编程数据接口--");
	Form1->MemoLuaOut->Lines->Add(" TVCC : 给目标板供电");
	Form1->MemoLuaOut->Lines->Add(" GND : 地");
	Form1->MemoLuaOut->Lines->Add(" D8 : SWDIO");
	Form1->MemoLuaOut->Lines->Add(" D6 : SWCLK");
	Form1->MemoLuaOut->Lines->Add(" D4 : RESET");
	Form1->MemoLuaOut->Lines->Add(" --烧录机台接口--");
	Form1->MemoLuaOut->Lines->Add(" D7 : START");
	Form1->MemoLuaOut->Lines->Add(" D1 : BUSY/EOT");
	Form1->MemoLuaOut->Lines->Add(" D2 : OK");
	Form1->MemoLuaOut->Lines->Add(" D3 : NG");
	Form1->MemoLuaOut->Lines->Add(" 注意1: 信号电平同TVCC的设置电压，一般为3.3V");
	Form1->MemoLuaOut->Lines->Add(" 注意2: 如果勾选解除读保护后重新上电会导致所有信号短暂出现0V");

	Form1->MemoLuaOut->Lines->Add("");
	Form1->MemoLuaOut->Lines->Add("【单路模式STM8】");
	Form1->MemoLuaOut->Lines->Add(" --编程数据接口--");
	Form1->MemoLuaOut->Lines->Add(" TVCC : 给目标板供电");
	Form1->MemoLuaOut->Lines->Add(" GND : 地");
	Form1->MemoLuaOut->Lines->Add(" D4或D5 : RESET");
	Form1->MemoLuaOut->Lines->Add(" D9 : SWIM");
	Form1->MemoLuaOut->Lines->Add(" --烧录机台接口--");
	Form1->MemoLuaOut->Lines->Add(" D7 : START");
	Form1->MemoLuaOut->Lines->Add(" D1 : BUSY/EOT");
	Form1->MemoLuaOut->Lines->Add(" D2 : OK");
	Form1->MemoLuaOut->Lines->Add(" D3 : NG");
	Form1->MemoLuaOut->Lines->Add(" 注意1: 信号电平同TVCC的设置电压，一般为3.3V");
	Form1->MemoLuaOut->Lines->Add(" 注意2: 如果勾选解除读保护后重新上电会导致所有信号短暂出现0V");

	Form1->MemoLuaOut->Lines->Add("");
	Form1->MemoLuaOut->Lines->Add("【1拖2模式】- 1拖4简易转接板");
	Form1->MemoLuaOut->Lines->Add(" --编程数据接口1--");
	Form1->MemoLuaOut->Lines->Add(" CN1-3.3V : 给目标板供电");
	Form1->MemoLuaOut->Lines->Add(" CN1-GND : 地");
	Form1->MemoLuaOut->Lines->Add(" CN1-DIO4 : 第1路SWDIO");
	Form1->MemoLuaOut->Lines->Add(" CN1-CLK4 : 第1路SWCLK");
	Form1->MemoLuaOut->Lines->Add(" CN1-RST4 : 第1路RESET(共用)");
	Form1->MemoLuaOut->Lines->Add(" --编程数据接口2--");
	Form1->MemoLuaOut->Lines->Add(" CN2-3.3V : 给目标板供电");
	Form1->MemoLuaOut->Lines->Add(" CN2-GND : 地");
	Form1->MemoLuaOut->Lines->Add(" CN2-DIO4 : 第2路SWDIO");
	Form1->MemoLuaOut->Lines->Add(" CN2-CLK4 : 第2路SWCLK");
	Form1->MemoLuaOut->Lines->Add(" CN2-RST4 : 第2路RESET(共用)");
	Form1->MemoLuaOut->Lines->Add(" --烧录机台接口--");
	Form1->MemoLuaOut->Lines->Add(" J2-INPUT : 两路公共1个START");
	Form1->MemoLuaOut->Lines->Add(" TTLTX    : 两路公共1个BUSY/EOT");
	Form1->MemoLuaOut->Lines->Add(" CN3-DIO4 : 第1路OK");
	Form1->MemoLuaOut->Lines->Add(" CN3-CLK4 : 第1路NG");
	Form1->MemoLuaOut->Lines->Add(" CN4-DIO4 : 第2路OK");
	Form1->MemoLuaOut->Lines->Add(" CN4-CLK4 : 第2路NG");
	Form1->MemoLuaOut->Lines->Add(" 注意1: 信号电平同TVCC的设置电压，一般为3.3V");
	Form1->MemoLuaOut->Lines->Add(" 注意2: 如果勾选解除读保护后重新上电会导致所有信号短暂出现0V");

	Form1->MemoLuaOut->Lines->Add("");
	Form1->MemoLuaOut->Lines->Add("【1拖4模式】- 1拖4机台转接板");
	Form1->MemoLuaOut->Lines->Add(" J3 : 第1路START BUSY OK NG信号");
	Form1->MemoLuaOut->Lines->Add(" J6 : 第2路START BUSY OK NG信号");
	Form1->MemoLuaOut->Lines->Add(" J7 : 第3路START BUSY OK NG信号");
	Form1->MemoLuaOut->Lines->Add(" J5 : 第4路START BUSY OK NG信号");
	Form1->MemoLuaOut->Lines->Add(" 注意1: 信号电平固定为5.0V");
	Form1->MemoLuaOut->Lines->Add(" 注意2: 四路共用1个START, 必须同时启动");
}
//---------------------------------------------------------------------------

void __fastcall TFormProg::Button15Click(TObject *Sender)
{
	AnsiString filename;

	filename = AppExePath() + "\\Programmer\\LuaLib\\encrypt\\" + ComboBoxAlgoLua->Text;

	Form1->MemoLuaOut->Lines->LoadFromFile(filename);
}
//---------------------------------------------------------------------------

void __fastcall TFormProg::Button16Click(TObject *Sender)
{
	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	Form1->MemoLuaOut->Lines->Add("【UID加密原理】");
	Form1->MemoLuaOut->Lines->Add("");
	Form1->MemoLuaOut->Lines->Add("1、烧录器在烧录芯片时，按照指定的算法将UID码编码为一个加密数据，并写入FLASH指定区域");
	Form1->MemoLuaOut->Lines->Add("");
	Form1->MemoLuaOut->Lines->Add("2、用户的程序必须增加一段UID校验程序比较UID和加密数据是否满足算法规则，不满足则停止运行或呈现随机错误");
	Form1->MemoLuaOut->Lines->Add("");
	Form1->MemoLuaOut->Lines->Add("3、用户程序只要进行了UID加密，就可以防止初级盗版者直接复制程序到其他芯片");
	Form1->MemoLuaOut->Lines->Add("");
	Form1->MemoLuaOut->Lines->Add("4、用户可以自行修改加密算法，以增加保密性");

	Form1->MemoLuaOut->Lines->Add("");
	Form1->MemoLuaOut->Lines->Add("【破解原理】");
	Form1->MemoLuaOut->Lines->Add("");
	Form1->MemoLuaOut->Lines->Add("1、破解者通过对代码反汇编，可以很容易找到访问UID地址空间的地方，从而确定UID校验函数的位置");
	Form1->MemoLuaOut->Lines->Add("");
	Form1->MemoLuaOut->Lines->Add("2、如果找到这个函数，就可以修改这个函数的返回值使其返回校验OK");
	Form1->MemoLuaOut->Lines->Add("");
	Form1->MemoLuaOut->Lines->Add("3、其实破解者一般不会去猜测UID校验算法，这个难度太大，没有足够多的样本是猜不出来的");

	Form1->MemoLuaOut->Lines->Add("");
	Form1->MemoLuaOut->Lines->Add("【加强反破解的策略】");
	Form1->MemoLuaOut->Lines->Add("");
	Form1->MemoLuaOut->Lines->Add("1、读取UID的语句不要用明码地址，访问地址可通过运算后得到。避免通过静态分析hex就轻松攻克");
	Form1->MemoLuaOut->Lines->Add("");
	Form1->MemoLuaOut->Lines->Add("2、关键的校验函数和善后处理语句可以分段组合后动态加载到内存中执行");
	Form1->MemoLuaOut->Lines->Add("");
	Form1->MemoLuaOut->Lines->Add("3、UID校验和善后处理程序可以在程序中多个地方实现");
	Form1->MemoLuaOut->Lines->Add("");
	Form1->MemoLuaOut->Lines->Add("4、UID校验的执行时刻可以随机、定时或硬件满足某个条件再执行");
	Form1->MemoLuaOut->Lines->Add("");
}

//---------------------------------------------------------------------------


void __fastcall TFormProg::BitBtn1Click(TObject *Sender)
{
	String s;

	s =  AppExePath() + "\\" + MemoOutputDir->Text;
	ShellExecute(Handle, NULL, s.c_str(), NULL,NULL,SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TFormProg::Button17Click(TObject *Sender)
{
	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	Form1->MemoLuaOut->Lines->Add("【单路模式ARM, 无需一拖四转接板】");
	Form1->MemoLuaOut->Lines->Add(" --编程数据接口--");
	Form1->MemoLuaOut->Lines->Add(" TVCC : 给目标板供电");
	Form1->MemoLuaOut->Lines->Add(" GND : 地");
	Form1->MemoLuaOut->Lines->Add(" D8 : SWDIO");
	Form1->MemoLuaOut->Lines->Add(" D6 : SWCLK");
	Form1->MemoLuaOut->Lines->Add(" D4 : RESET");

	Form1->MemoLuaOut->Lines->Add("");
	Form1->MemoLuaOut->Lines->Add("【STM8，只支持单路，不支持一拖四】");
	Form1->MemoLuaOut->Lines->Add(" --编程数据接口--");
	Form1->MemoLuaOut->Lines->Add(" TVCC : 给目标板供电");
	Form1->MemoLuaOut->Lines->Add(" GND : 地");
	Form1->MemoLuaOut->Lines->Add(" D4或D5 : RESET");
	Form1->MemoLuaOut->Lines->Add(" D9 : SWIM");

	Form1->MemoLuaOut->Lines->Add("");
	Form1->MemoLuaOut->Lines->Add("【新唐51，只支持单路，不支持一拖四转接板】");
	Form1->MemoLuaOut->Lines->Add(" --编程数据接口--");
	Form1->MemoLuaOut->Lines->Add(" TVCC : 给目标板供电");
	Form1->MemoLuaOut->Lines->Add(" GND : 地");
	Form1->MemoLuaOut->Lines->Add(" D8 : DAT");
	Form1->MemoLuaOut->Lines->Add(" D6 : CLK");
	Form1->MemoLuaOut->Lines->Add(" D4 : RESET");

	Form1->MemoLuaOut->Lines->Add("");
	Form1->MemoLuaOut->Lines->Add("【SPI串行FLASH，单路，无需一拖四转接板】");
	Form1->MemoLuaOut->Lines->Add(" H7-TOOL    SPI-FLASH(SO8引脚)");
	Form1->MemoLuaOut->Lines->Add(" TVCC  ---   VDD  (8)");
	Form1->MemoLuaOut->Lines->Add(" GND   ---   VSS  (4)");
	Form1->MemoLuaOut->Lines->Add(" D0    ---    CE  (1)");
	Form1->MemoLuaOut->Lines->Add(" D1    ---    SCK (6)");
	Form1->MemoLuaOut->Lines->Add(" D2    ---   MOSI (5)");
	Form1->MemoLuaOut->Lines->Add(" D4    ---   MISO (2)");
	Form1->MemoLuaOut->Lines->Add(" D7和D9仅仅用于提供高电平加到FLASH芯片的WP和HOLD引脚");
	Form1->MemoLuaOut->Lines->Add(" D7    ---     WP (3)");
	Form1->MemoLuaOut->Lines->Add(" D9    ---   HOLD (7)");

}
//---------------------------------------------------------------------------

void __fastcall TFormProg::Button1Click(TObject *Sender)
{
	FormLua->ButtonDownLuaFileClick(this);	// 下载lua
}
//---------------------------------------------------------------------------

void __fastcall TFormProg::Button21Click(TObject *Sender)
{
	AnsiString s;

	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	s.sprintf("erase_chip_mcu()  beep()");
	//udp_Send65H((char *)s.c_str(), s.Length());
	FormTcp->DoLuaSend64H(s);
}
//---------------------------------------------------------------------------

void __fastcall TFormProg::Button22Click(TObject *Sender)
{
	AnsiString s;

	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	s.sprintf("set_read_protect(0)  beep()");
	//udp_Send65H((char *)s.c_str(), s.Length());
	FormTcp->DoLuaSend64H(s);
}
//---------------------------------------------------------------------------

void __fastcall TFormProg::Button18Click(TObject *Sender)
{
	AnsiString s;

	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	s.sprintf("print(\"执行掉电复位\") beep()  set_tvcc(0) pg_reset(50) delayms(600) set_tvcc(TVCC_VOLT) beep()");
	//udp_Send65H((char *)s.c_str(), s.Length());
	FormTcp->DoLuaSend64H(s);
}
//---------------------------------------------------------------------------

void __fastcall TFormProg::Button23Click(TObject *Sender)
{
	AnsiString s;

	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	s.sprintf("set_read_protect(1)  beep()");
	//udp_Send65H((char *)s.c_str(), s.Length());
	FormTcp->DoLuaSend64H(s);
}
//---------------------------------------------------------------------------

void __fastcall TFormProg::BitBtn2Click(TObject *Sender)
{
	String s;

	s = AppExePath() + "\\readback";
	ShellExecute(Handle, NULL, s.c_str(), NULL,NULL,SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TFormProg::Button24Click(TObject *Sender)
{
	AnsiString s;

	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	s.sprintf("print_option_bytes()  beep()");
	//udp_Send65H((char *)s.c_str(), s.Length());
	FormTcp->DoLuaSend64H(s);
}
//---------------------------------------------------------------------------

// 其他配置参数，添加下拉列表选择项
void __fastcall TFormProg::ValueListEditor1GetPickList(TObject *Sender, const UnicodeString KeyName,
          TStrings *Values)
{
	//单路模式时钟延迟=0
	//多路模式时钟延迟=0
	//读内存指令间延迟(us)=0
	//硬件复位后延迟(ms)=0
	//解除保护后断电复位=0 --关闭
	//解除保护时延迟断电(ms)=0
	//解除保护断电时长(ms)=200
	//重新上电后的延迟(ms)=20
	//SPI串行Flash读模式=0 --单线模式

	if (KeyName == "解除保护后断电复位")
	{
		Values->Clear();
		Values->Add("0 --禁用");
		Values->Add("1 --启用");
	}
	else if (KeyName == "SPI串行Flash读模式")
	{
		Values->Clear();
		Values->Add("0 --单线标准模式");
		Values->Add("1 --双线读回模式");
	}
}
//---------------------------------------------------------------------------


