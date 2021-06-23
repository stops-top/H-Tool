//---------------------------------------------------------------------------

#include <vcl.h>
#include "winioctl.h"
#include <ClipBrd.hpp>

#pragma hdrstop

#include <IniFiles.hpp>
#include "UnitSet.h"
#include "UnitLua.h"
#include "UnitProg.h"
#include "UnitMain.h"
#include "UnitThread.h"
#include "UnitUSBBus.h"
#include "UnitRTT.h"
#include "UnitScreenShot.h"
#include "lua_if.h"
#include "file_lib.h"
#include "hex2bin.h"
#include "bsp.h"
#include "bsp_udp_modbus.h"
#include "bsp_user_lib.h"
#include "usb_hid.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormSet *FormSet;

const int g_BaudInt[] = {
	CBR_110, CBR_300, CBR_600, CBR_1200,
	CBR_2400, CBR_4800, CBR_9600, CBR_14400,
	CBR_19200, CBR_38400, CBR_56000, CBR_57600,
	CBR_115200, CBR_128000, CBR_256000
};
/* 0 - 2 分别对应 无检验、及校验、偶校验 */
const int g_Parity[3] = {0, 1, 2};
const char *g_ParityText[3] = {"无校验", "奇校验", "偶校验"};

//---------------------------------------------------------------------------
__fastcall TFormSet::TFormSet(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TFormSet::FormCreate(TObject *Sender)
{
	bsp_AddLog("FormSet Create Begin");

	FormSet->EditH7IPAddr->Text = g_tIniParam.IPAddr;
	FormSet->ComboBoxCommMode->ItemIndex = g_tIniParam.CommInterface;

//		Application->CreateForm(__classid(TFormProg), &FormProg);
//		Application->CreateForm(__classid(TFormUSBBus), &FormUSBBus);
//		Application->CreateForm(__classid(TFormLua), &FormLua);
//		Application->CreateForm(__classid(TFormSet), &FormSet);
	{
		FormProg->Parent = Form1;
		FormProg->Left = Form1->PanelLua->Left + Form1->PanelStation->Left;
		FormProg->Top = Form1->PanelLua->Top + Form1->PanelStation->Top;
		FormProg->Height = Form1->PanelStation->Height;
		FormProg->Width = Form1->PanelStation->Width;

		FormUSBBus->Parent = Form1;
		FormUSBBus->Left = Form1->PanelLua->Left + Form1->PanelStation->Left;
		FormUSBBus->Top = Form1->PanelLua->Top + Form1->PanelStation->Top;
		FormUSBBus->Height = Form1->PanelStation->Height;
		FormUSBBus->Width = Form1->PanelStation->Width;

		FormLua->Parent = Form1;
		FormLua->Left = Form1->PanelLua->Left + Form1->PanelStation->Left;
		FormLua->Top = Form1->PanelLua->Top + Form1->PanelStation->Top;
		FormLua->Height = Form1->PanelStation->Height;
		FormLua->Width = Form1->PanelStation->Width;

		FormSet->Parent = Form1;
		FormSet->Left = Form1->PanelLua->Left + Form1->PanelStation->Left;
		FormSet->Top = Form1->PanelLua->Top + Form1->PanelStation->Top;
		FormSet->Height = Form1->PanelStation->Height;
		FormSet->Width = Form1->PanelStation->Width;

		FormRTT->Parent = Form1;
		FormRTT->Left = Form1->PanelLua->Left + Form1->PanelStation->Left;
		FormRTT->Top = Form1->PanelLua->Top + Form1->PanelStation->Top;
		FormRTT->Height = Form1->PanelStation->Height;
		FormRTT->Width = Form1->PanelStation->Width;
	}

	bsp_AddLog("FormSet Create End");
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TFormSet::Button92Click(TObject *Sender)
{
	Form1->YbCommDevice1->SettingsDialog(this,true);

	if (Form1->YbCommDevice1->Active == true)
	{
		LabelPort->Caption = "当前串口已打开:" + Form1->YbCommDevice1->PortName +
			" 波特率: " + IntToStr(g_BaudInt[Form1->YbCommDevice1->Baud]) +
			"   奇偶校验: " + g_ParityText[Form1->YbCommDevice1->Parity];
	}
	else
	{
		LabelPort->Caption = "当前串口已关闭:" + Form1->YbCommDevice1->PortName +
			" 波特率: " + IntToStr(g_BaudInt[Form1->YbCommDevice1->Baud]) +
			"   奇偶校验: " + g_ParityText[Form1->YbCommDevice1->Parity];
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormSet::Button101Click(TObject *Sender)
{
	try
	{
		Form1->YbCommDevice1->Active = true;
	}
	catch (Exception &e)
	{
		ShowMessage(""+e.Message);
	}

	if (Form1->YbCommDevice1->Active == true)
	{
		LabelPort->Caption = "当前串口已打开:" + Form1->YbCommDevice1->PortName +
			" 波特率: " + IntToStr(g_BaudInt[Form1->YbCommDevice1->Baud]) +
			"   奇偶校验: " + g_ParityText[Form1->YbCommDevice1->Parity];
	}
	else
	{
		LabelPort->Caption = "当前串口已关闭:" + Form1->YbCommDevice1->PortName +
			" 波特率: " + IntToStr(g_BaudInt[Form1->YbCommDevice1->Baud]) +
			"   奇偶校验: " + g_ParityText[Form1->YbCommDevice1->Parity];
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormSet::Button102Click(TObject *Sender)
{
	try
	{
		Form1->YbCommDevice1->Active = false;
	}
	catch (Exception &e)
	{
		ShowMessage(""+e.Message);
	}

	if (Form1->YbCommDevice1->Active == true)
	{
		LabelPort->Caption = "当前串口已打开:" + Form1->YbCommDevice1->PortName +
			" 波特率: " + IntToStr(g_BaudInt[Form1->YbCommDevice1->Baud]) +
			"   奇偶校验: " + g_ParityText[Form1->YbCommDevice1->Parity];
	}
	else
	{
		LabelPort->Caption = "当前串口已关闭:" + Form1->YbCommDevice1->PortName +
			" 波特率: " + IntToStr(g_BaudInt[Form1->YbCommDevice1->Baud]) +
			"   奇偶校验: " + g_ParityText[Form1->YbCommDevice1->Parity];
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormSet::Button105Click(TObject *Sender)
{
  int iFileHandle;
  int iBytesRead;

  Form1->OpenDialog1->InitialDir = AppExePath() + "\\EMMC\\H7-TOOL\\Firmware";
  if (Form1->OpenDialog1->Execute())
  {
		iFileHandle = FileOpen(Form1->OpenDialog1->FileName, fmOpenRead);
		if (iFileHandle > 0)
		{
			#if 0
			  mFileLength = FileSeek(iFileHandle, 0, 2);
			  if (mFileLength <= 2 * 1024 * 1024)
			  {
					FileSeek(iFileHandle,0,0);
					iBytesRead = FileRead(iFileHandle, mFileBuf, mFileLength);
			  }
			  else
			  {
				  ShowMessage("文件过大");
			  }
			#else         /* 先将文件内容和文件长度存入备份缓冲区mbakFileBuf，数据解密后，再放入mFileBuf */
			  Form1->mbakFileLength = FileSeek(iFileHandle, 0, 2);
			  if (Form1->mbakFileLength <= 2 * 1024 * 1024)
			  {
					FileSeek(iFileHandle,0,0);
					iBytesRead = FileRead(iFileHandle, Form1->mbakFileBuf, Form1->mbakFileLength);
			  }
			  else
			  {
				  ShowMessage("文件过大");
			  }
			#endif
			  FileClose(iFileHandle);
		}
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormSet::Button104Click(TObject *Sender)
{
	if (g_tIniParam.CommInterface != 1)
	{
		Form1->MemoLuaOut->Lines->Add("升级固件，需要选择USB通信接口");
		return;
	}

	H7_WriteRegister(REG03_RESET_TO_BOOT, 2);

	Form1->MemoLuaOut->Lines->Add("已通知H7-TOOL进入Boot");

	// 通知通信监控任务，需要重新打开串口了
	Form1->mLinkStatus = 10;
	Form1->TimerPowerOn->Interval = 1000;
}
//---------------------------------------------------------------------------
/*
	校验解密文件
	mbakFileLength --> mFileBuf
*/
uint8_t DecryptFile(char *_infile, int32_t _inlen, char *_outfile, int32_t *_outlen)
{
	/* 开源软件，固件文件就不做校验和加密了 */
	*_outlen = _inlen;
	memcpy(_outfile, _infile, *_outlen);
	return 1;
}

void __fastcall TFormSet::Button103Click(TObject *Sender)
{
	uint32_t outlen;

	if (g_tIniParam.CommInterface != 1)
	{
		Form1->MemoLuaOut->Lines->Add("升级固件，需要选择USB通信接口");
		return;
	}

	if (Form1->YbCommDevice1->Active == false)
	{
		LabelUpgrade->Caption = "请打开串口";
		return;
	}

	/* 解密文件 */
	if (DecryptFile(Form1->mbakFileBuf, Form1->mbakFileLength, Form1->mFileBuf, &Form1->mFileLength) == 1)
	{
		g_tCmd.CmdStatus = CMDS_PRO_UPGRADE; //程序升级状态机
	}
	else
	{
		LabelUpgrade->Caption = "请打开正确的文件";
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormSet::Button106Click(TObject *Sender)
{
	H7_WriteRegister(REG03_RESET_TO_BOOT, 1);
}
//---------------------------------------------------------------------------
void __fastcall TFormSet::ButtonSetClockClick(TObject *Sender)
{
	uint16_t reg_buf[6];
	uint16_t addr, year, month, day, hour, min, sec, msec;
	TDateTime tt;

	tt = Now();
	tt.DecodeTime(&hour, &min, &sec, &msec);
	tt.DecodeDate(&year, &month, &day);
	reg_buf[0] =  year;
	reg_buf[1] =  month;
	reg_buf[2] =  day;
	reg_buf[3] =  hour;
	reg_buf[4] =  min;
	reg_buf[5] =  sec;
	H7_WriteMutiRegisters(REG03_RTC_YEAR, 6, reg_buf);

	Form1->MemoLuaOut->Lines->Add("同步时钟");
	FormTcp->mDispWriteRegister = 1;
}
//---------------------------------------------------------------------------
void __fastcall TFormSet::Button3Click(TObject *Sender)
{
	FormTcp->mDevNum = 0;

	memset(&FormTcp->mDevList, sizeof(FormTcp->mDevList), 0);

	ListBox1->Items->Clear();
//	EditCpuID->Text = "";
//	EditMac->Text = "";
//	EditHardVer->Text = "";
//	EditSoftVer->Text = "";
//	EditLocalIP->Text = "";
//	EditNetMask->Text = "";
//	EditGateWay->Text = "";
//	EditJkxPort->Text = "";
//	EditSysIP->Text = "";
//	EditSysPort->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TFormSet::Button2Click(TObject *Sender)
{
	uint16_t addr, year, month, day, hour, min, sec, msec;
	TDateTime tt;
	AnsiString s;

	if (Form1->CheckBoxAutoReadWave->Checked)
	{
		Form1->CheckBoxAutoReadWave->Checked = false;
		Form1->MemoLuaOut->Lines->Add("已关闭自动刷新波形，开始扫描");
	}

	if (g_tIniParam.CommInterface == 1)
	{
		Form1->MemoLuaOut->Lines->Add("通信接口选择以太网再开始扫描");
		return;
	}

	tt = Now();
	tt.DecodeTime(&hour, &min, &sec, &msec);
	tt.DecodeDate(&year, &month, &day);

	FormTcp->mDevNum = 0;
	ListBox1->Items->Clear();
	EditCpuID->Text = "";
	EditMac->Text = "";
	EditHardVer->Text = "";
	EditSoftVer->Text = "";
	EditLocalIP->Text = "";
	EditNetMask->Text = "";
	EditGateWay->Text = "";
	EditJkxPort->Text = "";
	EditSysIP->Text = "";
	EditSysPort->Text = "";

	//Data :022684DC "FF FF FF FF FF FF 03 00 00 00 0A D5 F7 "

	//udp_Send03H_MAC(MAC_FF, REG03_NET_CPU_ID0, 21);
	g_tCmd.UserCmdStatus = CMDS_UDP_FIND;
	g_tCmd.UserReq = 1;

	Form1->MemoLuaOut->Lines->Add("开始自动搜索H7-TOOL...");
	FormTcp->mDevNum = 0;	/* 清空既往的MAC表 */
}

uint8_t StrToIP(AnsiString s, uint8_t *ip)
{
	char *p;
	char buf[64];


	p = s.c_str();

	for (int i = 0; i < sizeof(buf); i++)
	{
		buf[i] = s.c_str()[i];
	}

	p = buf;

	ip[0] = str_to_int2(p);
	p = strchr(p, '.');
	if (p == 0) return 0;
	p++;

	ip[1] = str_to_int2(p);
	p = strchr(p, '.');
	if (p == 0) return 0;
	p++;

	ip[2] = str_to_int2(p);
	p = strchr(p, '.');
	if (p == 0) return 0;
	p++;

	ip[3] = str_to_int2(p);

	return 1;	/* ok */
}

//---------------------------------------------------------------------------
void __fastcall TFormSet::Button1Click(TObject *Sender)
{
	uint16_t reg_buf[256];
	uint8_t ip_buf[4];
	uint16_t pos = 0;
	int index;
	AnsiString s1;
	char *p;
	int port;
	uint8_t mac[6];

	if (ComboBoxCommMode->ItemIndex == 0)  // 以太网
	{
		if (ListBox1->Count == 0)
		{
			Form1->MemoLuaOut->Lines->Add("请先点击[搜索设备]按钮");
			return;
		}

		index = ListBox1->ItemIndex;
		if (index < 0)
		{
			Form1->MemoLuaOut->Lines->Add("请选择一个H7-TOOL");
			return;
		}

		memcpy(mac, FormTcp->mDevList[index].Mac, 6);
	}

	pos = 0;
	s1 = EditLocalIP->Text;
	if (StrToIP(s1, ip_buf) == 0)
	{
		Form1->MemoLuaOut->Lines->Add("本机IP地址格式错误");
		return;
	}
	reg_buf[pos++] =  (ip_buf[0] << 8) + ip_buf[1];
	reg_buf[pos++] =  (ip_buf[2] << 8) + ip_buf[3];

	s1 = EditNetMask->Text;
	if (StrToIP(s1, ip_buf) == 0)
	{
		Form1->MemoLuaOut->Lines->Add("子网掩码格式错误");
		return;
	}
	reg_buf[pos++] =  (ip_buf[0] << 8) + ip_buf[1];
	reg_buf[pos++] =  (ip_buf[2] << 8) + ip_buf[3];

	s1 = EditGateWay->Text;
	if (StrToIP(s1, ip_buf) == 0)
	{
		Form1->MemoLuaOut->Lines->Add("网关地址格式错误");
		return;
	}
	reg_buf[pos++] =  (ip_buf[0] << 8) + ip_buf[1];
	reg_buf[pos++] =  (ip_buf[2] << 8) + ip_buf[3];

	s1 = EditJkxPort->Text;
	port = StrToInt(s1);
	if (port > 65535 || port < 100)
	{
		Form1->MemoLuaOut->Lines->Add("本机端口号格式错误");
		return;
	}
	reg_buf[pos++] = port;

	s1 = EditSysIP->Text;
	if (StrToIP(s1, ip_buf) == 0)
	{
		Form1->MemoLuaOut->Lines->Add("管理系统IP地址格式错误");
		return;
	}
	reg_buf[pos++] =  (ip_buf[0] << 8) + ip_buf[1];
	reg_buf[pos++] =  (ip_buf[2] << 8) + ip_buf[3];

	s1 = EditSysPort->Text;
	port = StrToInt(s1);
	if (port > 65535)
	{
		Form1->MemoLuaOut->Lines->Add("管理系统端口号格式错误");
		return;
	}
	reg_buf[pos++] = port;

	if (ComboBoxCommMode->ItemIndex == 0)
	{
		Form1->MemoLuaOut->Lines->Add("开始修改IP参数(通过以太网)");
		udp_Send10H_MAC(mac, REG03_NET_LOCAL_IP_H, 10, reg_buf);
	}
	else if (ComboBoxCommMode->ItemIndex == 1)
	{
		Form1->MemoLuaOut->Lines->Add("开始修改IP参数(通过USB)");
		udp_Send10H(REG03_NET_LOCAL_IP_H, 10, reg_buf);
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormSet::ListBox1Click(TObject *Sender)
{
	int index;
	AnsiString s1;

	index = ListBox1->ItemIndex;
	if (index < 0)
	{
		return;
	}

	s1.sprintf("%02X%02X %02X%02X %02X%02X %02X%02X %02X%02X %02X%02X",
		FormTcp->mDevList[index].CpuID[0], FormTcp->mDevList[index].CpuID[1], FormTcp->mDevList[index].CpuID[2], FormTcp->mDevList[index].CpuID[3],
		FormTcp->mDevList[index].CpuID[4], FormTcp->mDevList[index].CpuID[5], FormTcp->mDevList[index].CpuID[6], FormTcp->mDevList[index].CpuID[7],
		FormTcp->mDevList[index].CpuID[8], FormTcp->mDevList[index].CpuID[9], FormTcp->mDevList[index].CpuID[10], FormTcp->mDevList[index].CpuID[11]);
	EditCpuID->Text = s1;

	s1.sprintf("%02X-%02X-%02X-%02X-%02X-%02X", FormTcp->mDevList[index].Mac[0], FormTcp->mDevList[index].Mac[1], FormTcp->mDevList[index].Mac[2],
					FormTcp->mDevList[index].Mac[3], FormTcp->mDevList[index].Mac[4], FormTcp->mDevList[index].Mac[5]);
	EditMac->Text = s1;

	s1.sprintf("%04X", FormTcp->mDevList[index].HardVer);
	EditHardVer->Text = s1;

	s1.sprintf("%04X", FormTcp->mDevList[index].SoftVer);
	EditSoftVer->Text = s1;

	s1.sprintf("%d.%d.%d.%d", FormTcp->mDevList[index].LocalIP[0], FormTcp->mDevList[index].LocalIP[1],
		FormTcp->mDevList[index].LocalIP[2], FormTcp->mDevList[index].LocalIP[3]);
	EditLocalIP->Text = s1;
	EditH7IPAddr->Text = s1;
	g_tIniParam.IPAddr = EditH7IPAddr->Text;

	s1.sprintf("%d.%d.%d.%d", FormTcp->mDevList[index].NetMask[0], FormTcp->mDevList[index].NetMask[1],
		FormTcp->mDevList[index].NetMask[2], FormTcp->mDevList[index].NetMask[3]);
	EditNetMask->Text = s1;

	s1.sprintf("%d.%d.%d.%d", FormTcp->mDevList[index].GateWay[0], FormTcp->mDevList[index].GateWay[1],
		FormTcp->mDevList[index].GateWay[2], FormTcp->mDevList[index].GateWay[3]);
	EditGateWay->Text = s1;

	s1.sprintf("%d", FormTcp->mDevList[index].LocalPort);
	EditJkxPort->Text = s1;

	s1.sprintf("%d.%d.%d.%d", FormTcp->mDevList[index].SysIP[0], FormTcp->mDevList[index].SysIP[1],
		FormTcp->mDevList[index].SysIP[2], FormTcp->mDevList[index].SysIP[3]);
	EditSysIP->Text = s1;

	s1.sprintf("%d", FormTcp->mDevList[index].SysPort);
	EditSysPort->Text = s1;
}
//---------------------------------------------------------------------------


void __fastcall TFormSet::ComboBoxCommModeChange(TObject *Sender)
{
	g_tIniParam.CommInterface = FormSet->ComboBoxCommMode->ItemIndex;
}
//---------------------------------------------------------------------------

void __fastcall TFormSet::EditH7IPAddrChange(TObject *Sender)
{
	;
}
//---------------------------------------------------------------------------

void __fastcall TFormSet::EditH7IPAddrExit(TObject *Sender)
{
	g_tIniParam.IPAddr = EditH7IPAddr->Text;
}
//---------------------------------------------------------------------------

String __fastcall TFormSet::ExecuteApp(String sCmdline)
{
	PROCESS_INFORMATION proc = {0};
	long ret,k=1;
	bool bret;

	STARTUPINFO start = {0};
	SECURITY_ATTRIBUTES sa = {0};
	HANDLE hReadPipe ;
	HANDLE hWritePipe;
	String sOutput;
	String sBuffer;
	unsigned long lngBytesRead;

	char cBuffer[1024 + 2];

	Form1->ProgressBar1->Position = 0;
	Form1->MemoLuaOut->Lines->Add(sCmdline);

	sa.nLength = sizeof(sa);
	sa.lpSecurityDescriptor=0;
	sa.bInheritHandle = TRUE;
	bret = ::CreatePipe(&hReadPipe, &hWritePipe,&sa, 0);
	if (!bret)
	{
		sOutput= "CreatePipe failed. Error: " + String(GetLastError());
		Form1->MemoLuaOut->Lines->Add(sOutput);
		return sOutput;
	}
	start.cb = sizeof(STARTUPINFOA);
	start.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
	start.hStdOutput = hWritePipe;
	start.hStdError = hWritePipe;
	start.wShowWindow = SW_HIDE;
	sBuffer = sCmdline;
	ret =::CreateProcess(0, sBuffer.c_str(), &sa, &sa, TRUE, NORMAL_PRIORITY_CLASS, 0, 0, &start, &proc);
	if (ret == 0)
	{
		sOutput= "Bad command or filename ";
		Form1->MemoLuaOut->Lines->Add(sOutput);
		return sOutput;
	}
	::CloseHandle(hWritePipe);
	do
	{
		memset(cBuffer, '\0 ',sizeof(cBuffer));
		ret = ::ReadFile(hReadPipe, cBuffer, 1024, &lngBytesRead, 0);
		cBuffer[lngBytesRead] = 0;
		sBuffer = String(cBuffer);
		sOutput = sOutput + sBuffer;

		if (mUpdateFileCmd == 1)
		{
			int pos;

			pos = 100 * mUpdatedCount / mUpdateFileCount;

			if (++mUpdatedCount >= mUpdateFileCount)
			{
				pos = 100;
			}
			Form1->ProgressBar1->Position = pos;
			//Form1->ProgressBar1->Refresh();
			//SendMessage(Form1->ProgressBar1->Handle, PBM_SETPOS , pos, 0);
		}
		Form1->MemoLuaOut->Text = Form1->MemoLuaOut->Text+sBuffer;
		SendMessage(Form1->MemoLuaOut->Handle,WM_VSCROLL, SB_BOTTOM, 0);
		Application->ProcessMessages();

	} while (ret != 0 );
	::CloseHandle(proc.hProcess);
	::CloseHandle(proc.hThread);
	::CloseHandle(hReadPipe);

	Form1->ProgressBar1->Position = 100;
	return sOutput;
}

//---------------------------------------------------------------------------

void __fastcall TFormSet::Button4Click(TObject *Sender)
{
	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	ExecuteApp(L"ipconfig /all");
}
//---------------------------------------------------------------------------

void __fastcall TFormSet::Button5Click(TObject *Sender)
{
	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	ExecuteApp(L"ping " + EditH7IPAddr->Text);
}
//---------------------------------------------------------------------------

void __fastcall TFormSet::Button6Click(TObject *Sender)
{
	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	//ExecuteApp(L"systeminfo");

	ExecuteApp(L"wmic os get caption");
	ExecuteApp(L"wmic os get osarchitecture");
}
//---------------------------------------------------------------------------

void __fastcall TFormSet::Button9Click(TObject *Sender)
{
	char buf[256];

	HID_FindDevices();

	Form1->MemoLuaOut->Lines->Add("找到我们的设备个数：" + IntToStr(g_tHID.DevCount));
	for (int i = 0; i < g_tHID.DevCount; i++)
	{
	   HID_GetName(i, buf, sizeof(buf));
	   Form1->MemoLuaOut->Lines->Add((AnsiString)buf);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormSet::Button8Click(TObject *Sender)
{
	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	Form1->MemoLuaOut->Lines->Add("搜素功能用于在IP参数不正确时，可以通过网口修改IP参数");
	Form1->MemoLuaOut->Lines->Add("有些情况，由于系统存在多网卡或防火墙，UDP广播消息无法传送到H7-TOOL，导致搜索不到");
	Form1->MemoLuaOut->Lines->Add("只要IP参数正确（前3字节和电脑IP相同)，能够ping通，就不影响H7-TOOL使用。");
	Form1->MemoLuaOut->Lines->Add("如果搜索不到，可以通过如下2种方式修改IP地址");
	Form1->MemoLuaOut->Lines->Add("  1 切换到USB口，填好IP地址后，点修改IP按钮");
	Form1->MemoLuaOut->Lines->Add("  2 在H7-TOOL屏幕上操作手动修改。 00界面长按S -> 系统设置 -> 网络参数");
	Form1->MemoLuaOut->Lines->Add("可以通过点 ""ping H7-TOOL"" 按钮测试以太网是否联通");
}
//---------------------------------------------------------------------------


void __fastcall TFormSet::Button10Click(TObject *Sender)
{
	String s;

	s =  AppExePath() + "\\Driver";
	ShellExecute(Handle, NULL, s.c_str(), NULL,NULL,SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TFormSet::Button19Click(TObject *Sender)
{
	if (g_tIniParam.CommInterface != 1)
	{
		Form1->MemoLuaOut->Lines->Add("进入U盘模式需要选择USB通信接口");
		return;
	}

	H7_WriteRegister(REG03_RESET_TO_BOOT, JUMP_TO_EMMC);
}
//---------------------------------------------------------------------------

// 搜索USB磁盘，找H7-TOOL的EMMC磁盘
void __fastcall TFormSet::SearchEMMC(void)
{
	wchar_t wbuf[256];
	DWORD dwLen;
	wchar_t disk[4];
	wchar_t ToolDisk[4];
	wchar_t VolumeName[128];
	DWORD nVolumeNameSize;
	AnsiString s;
	uint8_t Found = 0;

	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	Form1->MemoLuaOut->Lines->Add("查找H7-TOOL的EMMC磁盘");

	dwLen = GetLogicalDriveStrings(0, NULL);	//获取系统字符串长度.
	GetLogicalDriveStrings(dwLen, wbuf);		//获取盘符字符串.

	for (int i = 0; i < dwLen; i++)
	{
		/* C:\ */
		disk[0] = wbuf[i++];
		disk[1] = wbuf[i++];
		disk[2] = wbuf[i++];
		disk[3] = 0;

		if (GetDriveType(disk) == DRIVE_REMOVABLE )
		{
			s = AnsiString(disk) + "  可移动磁盘 ";

			/*
				GetVolumeInformation(
				  lpRootPathName: PChar;               {磁盘驱动器代码字符串}
				  lpVolumeNameBuffer: PChar;           {磁盘驱动器卷标名称}
				  nVolumeNameSize: DWORD;              {磁盘驱动器卷标名称长度}
				  lpVolumeSerialNumber: PDWORD;        {磁盘驱动器卷标序列号}
				  var lpMaximumComponentLength: DWORD; {系统允许的最大文件名长度}
				  var lpFileSystemFlags: DWORD;        {文件系统标识}
				  lpFileSystemNameBuffer: PChar;       {文件操作系统名称}
				  nFileSystemNameSize: DWORD           {文件操作系统名称长度}
				): BOOL;
			*/
			VolumeName[0] = 0;	  /* 如果右面有移动盘没卷标，这下面的函数不会对VolumeName赋值 */
			if (GetVolumeInformation(disk, VolumeName, 128, 0, 0, 0, 0, 0)) //判断驱动是否准备就
			{
				s += VolumeName;
			}

			if (wcscmp(VolumeName, L"EMMC") == 0)
			{
				s += " 已识别H7-TOOL的EMMC磁盘";
				Found = 1;
				wcscpy(ToolDisk, disk);
			}
			Form1->MemoLuaOut->Lines->Add(s);
		}
		else
		{
			Form1->MemoLuaOut->Lines->Add(disk);
		}
	}

	if (Found == 0)
	{
		mDiskFound = 0;
		Form1->MemoLuaOut->Lines->Add("没有找到H7-TOOL的磁盘");
		return;
	}

	mDiskFound = 1;
	mDiskEmmc = AnsiString(ToolDisk);
}

//---------------------------------------------------------------------------

// 更新整个H7-TOOL文件夹
void __fastcall TFormSet::ButtonUpdateClick(TObject *Sender)
{
	SearchEMMC();
	if (mDiskFound == 0)
	{
		return;
	}

	/*
		ROBOCOPY source destination /E /

		/E :: 复制子目录，包括空的子目录。
					 /PURGE :: 删除源中不再存在的目标文件/目录。
					   /MIR :: 镜像目录树(等同于 /E 加 /PURGE)。

						/IS :: 包含相同文件。
						/IT :: 包含已调整的文件。

	  开始时间: 2020-12-17 21:51:23
			源= H:\H7-TOOL\
		  目标: D:\H7-TOOL\PC\H7-TOOL_PC\Win32\Debug\Backup\20201217_215121_EMMC\H7-TOOL\

		  文件: *.*

		  选项: *.* /S /E /DCOPY:DA /COPY:DAT /PURGE /MIR /R:1000000 /W:30
	*/

	// 开始复制文件
	{
		String src;
		String tar;
		String cmd;

		// 复制文件
		src = AppExePath() + "\\" + "EMMC\\H7-TOOL";
		tar = mDiskEmmc;
		tar += "\H7-TOOL";
		cmd = "cmd.exe /c ROBOCOPY \"" + src + "\" \"" + tar + "\" /E /IT /V ";

		// 覆盖修改日期相同的文件
		if (CheckBoxDelNoModif->Checked)
		{
			cmd += "/IS ";
		}

		// 同步删除, 删除PC机上不存在的文件
		if (FormSet->CheckBoxDelSync->Checked)
		{
			 cmd += " /PURGE";  //: 删除源中不再存在的目标文件/目录。
		}

		mUpdateFileCmd = 1;

		mUpdateFileCount = 950;
		mUpdatedCount = 0;
		FormSet->ExecuteApp(cmd);

		mUpdateFileCmd = 0;

		Form1->MemoLuaOut->Lines->Add("源   = " + src);
		Form1->MemoLuaOut->Lines->Add("目标 = " + tar);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormSet::Button16Click(TObject *Sender)
{
	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	FormSet->ExecuteApp("cmd.exe /c " + EditCmd->Text);
}
//---------------------------------------------------------------------------


void __fastcall TFormSet::ButtonBackupClick(TObject *Sender)
{
	SearchEMMC();
	if (mDiskFound == 0)
	{
		return;
	}

	/*
		ROBOCOPY source destination /E /

		/E :: 复制子目录，包括空的子目录。
					 /PURGE :: 删除源中不再存在的目标文件/目录。
					   /MIR :: 镜像目录树(等同于 /E 加 /PURGE)。

						/IS :: 包含相同文件。
						/IT :: 包含已调整的文件。

	  开始时间: 2020-12-17 21:51:23
			源= H:\H7-TOOL\
		  目标: D:\H7-TOOL\PC\H7-TOOL_PC\Win32\Debug\Backup\20201217_215121_EMMC\H7-TOOL\

		  文件: *.*

		  选项: *.* /S /E /DCOPY:DA /COPY:DAT /PURGE /MIR /R:1000000 /W:30
	*/

	// 开始复制文件
	{
		String src;
		String tar;
		String cmd;

		// 自动备份
		//if (FormSet->CheckBoxAutoBackup->Checked)
		{
			AnsiString now;

			now = Now().FormatString("YYYYMMDD_HH_");

			tar = AppExePath() + "\\Backup\\" + now + "EMMC\\H7-TOOL";
			src = mDiskEmmc;
			src += "\H7-TOOL";
			cmd = "cmd.exe /c ROBOCOPY \"" + src + "\" \"" + tar + "\" /MIR /V";

			mUpdateFileCmd = 1;
			mUpdateFileCount = 1100;
			mUpdatedCount = 0;
			FormSet->ExecuteApp(cmd);
			mUpdateFileCmd = 0;

			Form1->MemoLuaOut->Lines->Add("源   = " + src);
			Form1->MemoLuaOut->Lines->Add("目标 = " + tar);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormSet::ButtonOpenBakupFolderClick(TObject *Sender)
{
	String s;

	s =  AppExePath() + "\\" + "Backup\\";

	ShellExecute(Form1->Handle, NULL, s.c_str(), NULL, NULL, SW_SHOWNORMAL);

	Form1->MemoLuaOut->Lines->Add("备份文件夹: " + s);
}

//浏览H7-TOOL 的emmc 盘
void __fastcall TFormSet::Button11Click(TObject *Sender)
{

	String s;

	SearchEMMC();
	if (mDiskFound == 0)
	{
		return;
	}

	s = mDiskEmmc;
	ShellExecute(Form1->Handle, NULL, s.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

//---------------------------------------------------------------------------

//浏览pc 的emmc 盘
void __fastcall TFormSet::Button13Click(TObject *Sender)
{
	String s;

	s =  AppExePath() + "\\" + "EMMC\\";
	ShellExecute(Form1->Handle, NULL, s.c_str(), NULL, NULL, SW_SHOWNORMAL);
	Form1->MemoLuaOut->Lines->Add("文件夹: " + s);
}
//---------------------------------------------------------------------------

void __fastcall TFormSet::Button14Click(TObject *Sender)
{
	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	H7_WriteRegister(REG03_RESET_TO_BOOT, 6);
	Form1->MemoLuaOut->Lines->Add("Boot固件文件: H7-TOOL的EMMC磁盘: H7-TOOL\Firmware\H7-BOOT.bin");
	Form1->MemoLuaOut->Lines->Add("已发送更新boot固件指令, 请观察H7-TOOL的小屏幕");
}
//---------------------------------------------------------------------------

void __fastcall TFormSet::ButtonQuiEmmcClick(TObject *Sender)
{
	HANDLE hDevice; // handle to the drive to be examined
	BOOL bResult; // results flag
	DWORD junk; // discard results
	DWORD dwError;
	String csVolume;


	csVolume = mDiskEmmc;
	// Open the volume
	hDevice = CreateFile(csVolume.c_str(), // drive to open
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE, // share mode
		NULL, // default security attributes
		OPEN_EXISTING, // disposition
		0, // file attributes
		NULL); // don't copy any file's attributes

	if (hDevice == INVALID_HANDLE_VALUE) // can't open the drive
	{
		dwError = GetLastError();
		return;
	}

	//Dismount the volume
	bResult = DeviceIoControl(
		hDevice, // handle to volume
		IOCTL_STORAGE_EJECT_MEDIA, //eject USB
		NULL, // lpInBuffer
		0, // nInBufferSize
		NULL, // lpOutBuffer
		0, // nOutBufferSize
		&junk, // discard count of bytes returned
		(LPOVERLAPPED) NULL); // synchronous I/O
	if (!bResult) // IOCTL failed
	{
		dwError = GetLastError();
	}

	// Close the volume handle
	bResult = CloseHandle(hDevice);
	if (!bResult)
	{
		dwError = GetLastError();
	}

	return;
}
//---------------------------------------------------------------------------

void __fastcall TFormSet::Button18Click(TObject *Sender)
{
	// 读boot版本
	H7_ReadRegisters(REG03_BOOT_VER, 1);
}
//---------------------------------------------------------------------------

void __fastcall TFormSet::Button15Click(TObject *Sender)
{
	// 读APP版本
	H7_ReadRegisters(REG03_APP_VER, 1);
}
//---------------------------------------------------------------------------

void __fastcall TFormSet::Button7Click(TObject *Sender)
{
	AnsiString s1;

	s1 = AppExePath() + "\\Driver\\USB驱动安装说明.txt";

	Form1->MemoLuaOut->Lines->LoadFromFile(s1);
}
//---------------------------------------------------------------------------

void __fastcall TFormSet::ButtonScreShotClick(TObject *Sender)
{
	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	/* 通知线程开始传输 */
	g_tCmd.UserCmdStatus = CMDS_READ_SCREEN;
	g_tCmd.UserReq = 1;
}
//---------------------------------------------------------------------------

void __fastcall TFormSet::Button17MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	Form1->MemoLuaOut->Lines->Add("S 键按下");
	g_tCmd.DisabelAck = 1;	/* 禁止应答 */
	H7_WriteRegister(REG03_SEND_KEY, 0x0001);
	g_tCmd.CmdStatus = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFormSet::Button17MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	Form1->MemoLuaOut->Lines->Add("S 键松开");
	g_tCmd.DisabelAck = 1;	/* 禁止应答 */
	H7_WriteRegister(REG03_SEND_KEY, 0x0000);
	g_tCmd.CmdStatus = 0;
}
//---------------------------------------------------------------------------


void __fastcall TFormSet::Button20MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	Form1->MemoLuaOut->Lines->Add("C 键按下");
	g_tCmd.DisabelAck = 1;	/* 禁止应答 */
	H7_WriteRegister(REG03_SEND_KEY, 0x0101);
	g_tCmd.CmdStatus = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFormSet::Button20MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if (Form1->CheckBoxClear->Checked)
	{
		Form1->MemoLuaOut->Clear();
	}

	Form1->MemoLuaOut->Lines->Add("C 键松开");
	g_tCmd.DisabelAck = 1;	/* 禁止应答 */
	H7_WriteRegister(REG03_SEND_KEY, 0x0100);
	g_tCmd.CmdStatus = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFormSet::CheckBoxScreenClick(TObject *Sender)
{
	if (CheckBoxScreen->Checked)
	{
		Timer1->Enabled = true;
		Form1->CheckBoxMonitorUSB->Checked = false;
	}
	else
	{
		Timer1->Enabled = false;
		Form1->CheckBoxMonitorUSB->Checked = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormSet::Timer1Timer(TObject *Sender)
{
	/* 通知线程开始传输 */
	g_tCmd.UserCmdStatus = CMDS_READ_SCREEN;
	g_tCmd.UserReq = 1;
}
//---------------------------------------------------------------------------

void __fastcall TFormSet::Button21Click(TObject *Sender)
{
	AnsiString name;
	AnsiString str;
	AnsiString now;

	now = Now().FormatString("YYYYMMDD_HHmmSS_");
	str.sprintf("截屏.bmp");
	name = AppExePath() + "\\readback\\" + now + str;

	FormSet->Image1->Picture->Bitmap->SaveToFile(name);

	Form1->MemoAdd("截屏已保存 : " + name);
}
//---------------------------------------------------------------------------

void __fastcall TFormSet::Button12Click(TObject *Sender)
{
	String s;

	s =  AppExePath() + "\\" + "Readback\\";

	ShellExecute(Form1->Handle, NULL, s.c_str(), NULL, NULL, SW_SHOWNORMAL);

	Form1->MemoLuaOut->Lines->Add("文件夹: " + s);
}
//---------------------------------------------------------------------------


void __fastcall TFormSet::Button22Click(TObject *Sender)
{
	// 复制到windows剪切板
	Clipboard()->Assign(FormSet->Image1->Picture);

	Form1->MemoAdd("截屏已复制到剪切板");
}
//---------------------------------------------------------------------------

void __fastcall TFormSet::Button23Click(TObject *Sender)
{
//	Graphics::TBitmap *Bitmap = new Graphics::TBitmap();
//
//	Bitmap->Width = Panel1->Width;
//	Bitmap->Height = Panel1->Height;
//	//====Bitmap->Width=Screen->Width;全屏幕截图
//	//====Bitmap->Height=Screen->Height;
//
//	Form1->MemoAdd("Form1->Left=" + IntToStr(Form1->Left));
//	Form1->MemoAdd("FormSet->Left=" + IntToStr(FormSet->Left));
//	Form1->MemoAdd("PageControl1->Left=" + IntToStr(PageControl1->Left));
//	Form1->MemoAdd("Panel1->Left=" + IntToStr(Panel1->Left));
//
//	HDC hdc = GetWindowDC(0);
//	BitBlt(Bitmap->Canvas->Handle, 0, 0, Bitmap->Width, Bitmap->Height,
//		hdc,
//
//		Form1->Left + FormSet->Left + PageControl1->Left + Panel1->Left ,
//		Form1->Top + FormSet->Top + PageControl1->Top + Panel1->Top ,
//		SRCCOPY);
//
//	Clipboard()->Assign(Bitmap);
//	//====Bitmap->SaveToFile(".//screen//screen2.bmp");    //创建BMP格式图片
//	delete   Bitmap;
}

//---------------------------------------------------------------------------

void __fastcall TFormSet::ButtonInitBaseParamClick(TObject *Sender)
{
	if (IDOK == MessageBox(Handle,
		L"这些参数包括: 按键音、屏保时间、缺省启动界面、IP参数、DAP仿真器编号、串口参数等",
		L"恢复基本参数到出厂值",  // 窗口标题
		MB_OKCANCEL | MB_ICONINFORMATION))
	{
		Form1->MemoAdd("恢复H7-TOOL的基本参数到出厂值(不包括模拟量校准参数)");
		H7_WriteRegister(REG03_CALIB_KEY, 0xEF55);	// 恢复基本参数到缺省值
	}
}
//---------------------------------------------------------------------------

