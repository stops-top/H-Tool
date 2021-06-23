//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitMain.h"
#include "UnitCalib.h"
#include "UnitProg.h"
#include "UnitLua.h"
#include "UnitThread.h"
#include "UnitUSBBus.h"
#include "UnitSet.h"
#include "bsp.h"
#include "bsp_udp_modbus.h"
#include "bsp_user_lib.h"
#include "file_lib.h"
#include "YbCommDevice.h"
#include "bmp_file.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormTcp *FormTcp;

#define H64_MAX_LEN_USB		(1536 - 18)
#define H64_MAX_LEN_RJ45	1024 			/* (1472 - 18) */

#define DYN_ARRAY_SIZE	(16 * 1024)
static unsigned char s_RxBuf [DYN_ARRAY_SIZE];
static uint32_t  s_RxLen = 0;
static TByteDynArray g_buf;

static char s_USB_RxBuf [DYN_ARRAY_SIZE];
static uint32_t  s_USB_RxLen = 0;
static TByteDynArray g_SerialPortBuf;
int g_usb_rx_len = 0;

int g_H64DataMaxLen;

extern char g_BinFile[8 * 1024 * 1024];

TBitmap *g_bmp = new TBitmap;

//---------------------------------------------------------------------------
__fastcall TFormTcp::TFormTcp(TComponent* Owner)
	: TForm(Owner)
{

}

void __fastcall TFormTcp::FormCreate(TObject *Sender)
{
	//g_buf = RawToBytes(RxBuf, 1500);    // 将 unsigned char 数组转换为 TByteDynArray 类型指针

	bsp_AddLog("FormTcp Create Begin");

	g_buf.set_length(DYN_ARRAY_SIZE);
	g_SerialPortBuf.set_length(DYN_ARRAY_SIZE);

	bsp_AddLog("FormTcp Create End");
	Thread1->Start();  //在FormSet 创建后再启动线程
}

//装载文件夹名字到缓冲区
void LoadFolderNameToMem(String FileName)
{
	AnsiString s;
	AnsiString path0;
	AnsiString name;
	int i;

	path0 = AppExePath();	//ExtractFilePath(Application->ExeName);
	name =  FileName;

	/*
		path0 =  /EMMC/H7-TOOL/Programmer/User/Demo
		0:/H7-TOOL/EMMC/H7-TOOL/Programmer/User/Demo
	*/
	//s = "0:/H7-TOOL" + (AnsiString)&name.c_str()[path0.Length()];
	s = "0:/" + (AnsiString)&name.c_str()[path0.Length() + 6];

	FormTcp->mLua.Func = H64_CREATE_FOLDER;	/* 创建文件夹 */

	FormTcp->mLua.DataLen = s.Length() + 1;
	for (i = 0; i < FormTcp->mLua.DataLen; i++)
	{
		if (s.c_str()[i] == '\\')
		{
			s.c_str()[i] = '/';
		}
		FormTcp->mLua.DataBuf[i] = s.c_str()[i];
	}
	FormTcp->mLua.DataBuf[i] = 0;

	//FormProg->LabelTransFile->Caption = s;
	//if (FormProg->CheckBoxDispFileLog->Checked)
	{
		Form1->MemoLuaOut->Lines->Add(s);
	}
}

//装载文件数据到缓冲区
void LoadFileDataToMem(String FileName)
{
	AnsiString s;
	char s2[120];
	AnsiString path0;
	AnsiString name;
	int i;
	char MD5[16];
	int32_t FileSize;

	path0 = AppExePath();	//ExtractFilePath(Application->ExeName);
	name =  FileName;

	//s = "0:/H7-TOOL" + (AnsiString)&name.c_str()[path0.Length()];
	s = "0:/" + (AnsiString)&name.c_str()[path0.Length() + 6];

	FormTcp->mLua.Func = H64_WRITE_FILE;	/* 创建文件夹 */

	FormTcp->mLua.DataLen = 0;

	/* 文件大小（4字节) + MD5 (16字节） + 文件名长度 + 文件名（最大255字节，无0结束符） + 文件数据 */
	{
		FileSize = GetFileMD5(FileName, MD5);

		Uint32ToBEBuf(FileSize,  &FormTcp->mLua.DataBuf[FormTcp->mLua.DataLen]);
		FormTcp->mLua.DataLen += 4;

		memcpy(&FormTcp->mLua.DataBuf[FormTcp->mLua.DataLen], MD5, 16);
		FormTcp->mLua.DataLen += 16;
	}

	/* 文件名长度 */
	FormTcp->mLua.DataBuf[FormTcp->mLua.DataLen++] = s.Length();
	/* 文件名 */
	for (i = 0; i < s.Length(); i++)
	{
		if (s.c_str()[i] == '\\')
		{
			s.c_str()[i] = '/';
		}
		FormTcp->mLua.DataBuf[FormTcp->mLua.DataLen++] = s.c_str()[i];
	}

//	HexBufToAscii(MD5, s2, 16);
//	Form1->MemoLuaOut->Lines->Add("写文件: " + s + " (" + IntToStr(FileSize) + ", MD5: "
//		+ (AnsiString)s2 + ")" );
//	FormProg->LabelTransFile->Caption = "写文件: " + s + " (" + IntToStr(FileSize) + ", MD5: "
//		+ (AnsiString)s2 + ")";
	s = s + " (" + IntToStr(FileSize) + ")";

	//if (FormProg->CheckBoxDispFileLog->Checked)
	{
		Form1->MemoLuaOut->Lines->Add(s);
	}

	/* 后面跟随文件数据 */
	{
		int iFileHandle;
		int iBytesRead;
		int iFileLength;

		iFileHandle = FileOpen(FileName, fmOpenRead);
		if (iFileHandle > 0)
		{
			iFileLength = FileSeek(iFileHandle, 0, 2);

			if (iFileLength <= LUA_DATA_MAX_SIZE - 256)
			{
				FileSeek(iFileHandle, 0, 0);
				FileRead(iFileHandle, &FormTcp->mLua.DataBuf[FormTcp->mLua.DataLen], iFileLength);
				FileClose(iFileHandle);

				FormTcp->mLua.DataLen += iFileLength;

				//测试代码，写到文件debug
//				FileName = FileName + ".Read";
//				iFileHandle = FileCreate(FileName);
//				FileWrite(iFileHandle, FormTcp->mLua.DataBuf, FormTcp->mLua.DataLen);
//				FileClose(iFileHandle);
			}
			else
			{
				Form1->MemoLuaOut->Lines->Add("文件过大");
			}
		}
	}
}

//--更新芯片文件--------------------------------------------------------------------
void __fastcall TFormTcp::UpdateChipFile(void)
{
	static int s_idx = 0;
	static int s_time = 0;
	static int s_retry = 0;
	static int s_head_len = 0;		/* 文件头长度 */

	switch (g_tCmd.CmdStatus)
	{
		case CMDS_UPDATE_CHIP_FILE:
			s_idx = 0;
			g_tCmd.CmdStatus++;

			if (g_tIniParam.CommInterface == 0)
			{
				g_H64DataMaxLen = H64_MAX_LEN_RJ45;
			}
			else
			{
				g_H64DataMaxLen = H64_MAX_LEN_USB;
			}
			Form1->ProgressBar1->Position = 0;	// 进度条
			s_time = bsp_GetRunTime();
			break;

		case CMDS_UPDATE_CHIP_FILE + 1:
			{
				String name;

				if (FormProg->ListFileName->Strings[s_idx] == "")
				{
					name = FormProg->ListFilePath->Strings[s_idx];
				}
				else
				{
					name = FormProg->ListFilePath->Strings[s_idx] + "/" +
						FormProg->ListFileName->Strings[s_idx];
				}

				if (FormProg->ListFileType->Strings[s_idx] == "Dir")	// 文件夹
				{
					LoadFolderNameToMem(name);
				}
				else 	// 文件
				{
					LoadFileDataToMem(name);
				}
			}
			g_tCmd.CmdStatus++;
			break;

		case CMDS_UPDATE_CHIP_FILE + 2:
			mLua.Offset = 0;

			s_head_len = mLua.DataBuf[20] + 21;
			s_retry = 0;
			g_tCmd.CmdStatus++;
			break;

		case CMDS_UPDATE_CHIP_FILE + 3:
			g_tCmd.err = 0;

			/* 文件大小（4字节) + MD5 (16字节） + 文件名长度 + 文件名（最大255字节，无0结束符） + 文件数据 */
			if (mLua.Offset == 0)  /* 第1包, 文件头 + 最大1K数据 */
			{
				if (mLua.DataLen <= g_H64DataMaxLen + s_head_len)
				{
					mLua.PackagLen = mLua.DataLen;
				}
				else
				{
					mLua.PackagLen = g_H64DataMaxLen + s_head_len;
				}

				udp_Send64H(mLua.Func, mLua.DataLen, 0, mLua.PackagLen, &mLua.DataBuf[mLua.Offset]);
				//Form1->MemoLuaOut->Lines->Add(" -- Addr = " + IntToStr(0) +
				//	" len = " + IntToStr(mLua.PackagLen));
			}
			else  	/* 第2包以后 */
			{
				{
					int remain;

					remain = mLua.DataLen - mLua.Offset;	// 剩余字节
					if (remain > g_H64DataMaxLen)
					{
						mLua.PackagLen = g_H64DataMaxLen;
					}
					else
					{
						mLua.PackagLen = remain;
					}
				}
				udp_Send64H(mLua.Func, mLua.DataLen, mLua.Offset - s_head_len, mLua.PackagLen, &mLua.DataBuf[mLua.Offset]);
				//Form1->MemoLuaOut->Lines->Add(" -- Addr = " + IntToStr((int)mLua.Offset - s_head_len) +
				//	" len = " + IntToStr(mLua.PackagLen));   // debug
			}
			mLastTime = bsp_GetRunTime();
			g_tCmd.CmdStatus++;
			break;

		case CMDS_UPDATE_CHIP_FILE + 4:
			if (g_tCmd.RxOk == 1)
			{
				if (g_tCmd.err == 0)  	/* 文件写入成功 */
				{
					mLua.Offset += mLua.PackagLen;
					if (mLua.Offset < mLua.DataLen)
					{
						g_tCmd.CmdStatus--;  	// 继续传输
						break;
					}
					else
					{
						if (++s_idx >= FormProg->ListFileName->Count)
						{
							g_tCmd.CmdStatus++;   // 传输完成
						}
						else
						{
							g_tCmd.CmdStatus =  CMDS_UPDATE_CHIP_FILE + 1;	// 继续下一个文件
						}
						Form1->MemoLuaOut->Lines->Add("  传输成功");
					}
				}
				else if (g_tCmd.err == 1)  	/* 文件内容相同 */
				{
					if (++s_idx >= FormProg->ListFileName->Count)
					{
						g_tCmd.CmdStatus++;   // 传输完成
					}
					else
					{
						g_tCmd.CmdStatus =  CMDS_UPDATE_CHIP_FILE + 1;	// 继续下一个文件
					}
					Form1->MemoLuaOut->Lines->Add("  文件相同");
				}
				else 	/* 写入错误 2写文件失败 3创建目录失败 4 MD5校验失败 */
				{
					String name;

					name = (AnsiString)(char *)FormTcp->mLua.DataBuf;

					g_tCmd.CmdStatus = 0;

					if (g_tCmd.err == 2)  Form1->MemoLuaOut->Lines->Add("  写文件失败 ");
					else if (g_tCmd.err == 3)  Form1->MemoLuaOut->Lines->Add("  创建目录失败 ");
					else if (g_tCmd.err == 4)  Form1->MemoLuaOut->Lines->Add("  MD5校验失败 ");
					else Form1->MemoLuaOut->Lines->Add("  其他写入错误 ");
				}
				Form1->ProgressBar1->Position = 100 * s_idx / FormProg->ListFileName->Count;	// 进度条
				break;
			}
			if (bsp_CheckRunTime(mLastTime) > 3000)
			{
				if (++s_retry > 3)
				{
					String name;

					name = (AnsiString)(char *)FormTcp->mLua.DataBuf;

					g_tCmd.CmdStatus = 0;
					//FormProg->LabelTransFile->Caption =  "通信超时 " + name;
					Form1->MemoLuaOut->Lines->Add("--通信超时，终止");
				}
				else
				{
					Form1->MemoLuaOut->Lines->Add("--继续重传");
					g_tCmd.CmdStatus--;  	// 继续传输
				}
			}
			break;

		case CMDS_UPDATE_CHIP_FILE + 5:
			{
				AnsiString s1;
				s_time = bsp_GetRunTime() - s_time;
				//Form1->MemoLuaOut->Lines->Add("下载成功 (" + IntToStr(s_time) + " ms)");
				s1 = "传输成功 (" + s1.sprintf("%d.%03d", s_time / 1000, s_time % 1000) + " s) 共"
					+ IntToStr(FormProg->ListFileName->Count) + "个文件";
				Form1->ProgressBar1->Position = 100;	// 进度条
				Form1->ProgressBar1->Refresh();

				Form1->MemoLuaOut->Lines->Add(s1);
			}

			g_tCmd.CmdStatus = 0;


			break;
	}
}

/*----LUA程序下载----------------------------------*/
void __fastcall TFormTcp::DownLuaFile(void)
{
	static int s_scan_status = 0;
	static int s_retry = 0;
	static int s_LastTime;
	static int s_idx;

	switch (g_tCmd.CmdStatus)
	{
		case CMDS_DOWNLOAD_LUA:
			mLua.Offset = 0;
			g_tCmd.CmdStatus++;
			break;

		case CMDS_DOWNLOAD_LUA + 1:
			if (mLua.DataLen <= 1024)
			{
				mLua.PackagLen = mLua.DataLen;
			}
			else
			{
				int remain;

				remain = mLua.DataLen - mLua.Offset;	// 剩余字节
				if (remain > 1024)
				{
					mLua.PackagLen = 1024;
				}
				else
				{
					mLua.PackagLen = remain;
                }
            }
			udp_Send64H(mLua.Func, mLua.DataLen, mLua.Offset, mLua.PackagLen, &mLua.DataBuf[mLua.Offset]);
			mLastTime = bsp_GetRunTime();
			g_tCmd.CmdStatus++;
			break;

		case CMDS_DOWNLOAD_LUA + 2:
			if (g_tCmd.RxOk == 1)
			{
				mLua.Offset += mLua.PackagLen;
				if (mLua.Offset < mLua.DataLen)
				{
					g_tCmd.CmdStatus--;  	// 继续传输
				}
				else
				{
					g_tCmd.CmdStatus++;   // 传输完成
				}
			}
			if (bsp_CheckRunTime(mLastTime) > 500)
			{
				g_tCmd.CmdStatus = 0;
				if (mLua.Func == 1)
				{
					Form1->MemoLuaOut->Lines->Add("通信超时，下载失败");
				}
			}
			break;

		case CMDS_DOWNLOAD_LUA + 3:
			if (mLua.Func == H64_LUA_RUN_WITH_RESET)
			{
				Form1->MemoLuaOut->Lines->Add("下载成功");
			}
			g_tCmd.CmdStatus = 0;
			break;
	}
}

/************************程序升级 *************************/
void __fastcall TFormTcp::UpdateFirmware(void)
{
	static int s_scan_status = 0;
	static int s_retry = 0;
	static int s_LastTime;
	static int s_idx;

	switch (g_tCmd.CmdStatus)
	{
		case CMDS_PRO_UPGRADE - 5:     /* 程序升级。1.写app进入BOOT标志 */
			udp_Send06H(REG03_RESET_TO_BOOT, 2);   /* 通知APP进入boot固件升级状态 */
			s_LastTime = bsp_GetRunTime();
			g_tCmd.CmdStatus++;
			break;

		case CMDS_PRO_UPGRADE - 4:
			if (bsp_CheckRunTime(s_LastTime) > 500)
			{
				FormSet->LabelUpgrade->Caption = "设备无应答";
				Form1->MemoLuaOut->Lines->Add(FormSet->LabelUpgrade->Caption);
				g_tCmd.CmdStatus = CMDS_PRO_UPGRADE_ERR;
				break;
			}

			if (g_tCmd.RxOk == 1)
			{
				g_tCmd.CmdStatus++;
				s_LastTime = bsp_GetRunTime();
			}
			break;

		case CMDS_PRO_UPGRADE - 3:  	/* 进入boot后，USB串口会复位 */
			if (bsp_CheckRunTime(s_LastTime) > 2000)
			{
				g_tCmd.CmdStatus++;
			}
			break;

		case CMDS_PRO_UPGRADE - 2:  	/* 进入boot后，USB串口会复位 */
			if (Form1->YbCommDevice1->Active == false)
			{
				Form1->YbCommDevice1->Active = true;
			}
			Form1->YbCommDevice1->Active = true;
			Form1->YbCommDevice1->Parity = 0;
			g_tCmd.CmdStatus++;
			s_LastTime = bsp_GetRunTime();
			break;

		case CMDS_PRO_UPGRADE - 1:  	/* 进入boot后，USB串口会复位 */
			if (bsp_CheckRunTime(s_LastTime) > 2000)
			{
				g_tCmd.CmdStatus++;
			}
			break;

		case CMDS_PRO_UPGRADE:             	 /* 程序升级。1.写app进入BOOT标志 */
			mUpgradeTime = 0;		/* 升级耗时初始为0*/
			RecordID = 0;
			if (Form1->mFileLength == 0)
			{
				FormSet->LabelUpgrade->Caption = "请打开文件！";
                mUserCmdFlag = 0;			 /* 退出循环 */
				break;
			}

			{
				Form1->MemoLuaOut->Lines->Add("程序文件名:" + ExtractFileName(Form1->OpenDialog1->FileName));

			}
			{
				uint16_t reg_buf[6];

				reg_buf[0] = 0; /* APP程序类型: 0 = CPU内部Flash ; 1 = QSPI Flash */
				reg_buf[1] = (APPLICATION_ADDRESS >> 24) * 256 + ((APPLICATION_ADDRESS >> 16) & 0xFF);
				reg_buf[2] = (APPLICATION_ADDRESS >> 8) * 256 + ((APPLICATION_ADDRESS >> 0) & 0xFF);
				reg_buf[3] = (Form1->mFileLength >> 24) * 256 + ((Form1->mFileLength >> 16) & 0xFF);
				reg_buf[4] = (Form1->mFileLength >> 8) * 256 + ((Form1->mFileLength >> 0) & 0xFF);
				udp_Send10H(REG03_BOOT_PROG_TYPE, 5, reg_buf);
			}
			Form1->TimerUpgrade->Tag = 0;
			FormSet->LabelUpgrade->Caption = "1.传送文件信息";
			Form1->MemoLuaOut->Lines->Add(FormSet->LabelUpgrade->Caption);
			s_LastTime = bsp_GetRunTime();
			g_tCmd.CmdStatus++;            		 /* 进入下一步等待应答 */
			break;

		case CMDS_PRO_UPGRADE + 1:
			if (bsp_CheckRunTime(s_LastTime) > 500)
			{
				FormSet->LabelUpgrade->Caption = "设备无应答";
				Form1->MemoLuaOut->Lines->Add(FormSet->LabelUpgrade->Caption);
				g_tCmd.CmdStatus = CMDS_PRO_UPGRADE_ERR;
				break;
			}

			if (g_tCmd.RxOk == 1)
			{
				FormSet->LabelUpgrade->Caption = " -- 文件信息传送OK";
				Form1->MemoLuaOut->Lines->Add(FormSet->LabelUpgrade->Caption);
				g_tCmd.CmdStatus++;
				s_idx = 0;
				Form1->MemoLuaOut->Lines->Add("2.开始擦除Flash");
				s_retry = 0;
			}
			break;

		case CMDS_PRO_UPGRADE + 2:
			udp_Send06H(REG03_BOOT_ERASE_SECTOR, s_idx);
			s_LastTime = bsp_GetRunTime();
			g_tCmd.CmdStatus++;            		 /* 进入下一步等待应答 */
			break;

		case CMDS_PRO_UPGRADE + 3:
			if (bsp_CheckRunTime(s_LastTime) > 5000)
			{
				Form1->MemoLuaOut->Lines->Add(" --擦除失败, " + IntToStr(s_idx));
				if (++s_retry >= 3)
				{
					g_tCmd.CmdStatus = CMDS_PRO_UPGRADE_ERR;
				}
				else
				{
					g_tCmd.CmdStatus--;	/* 重试 */
				}
				break;
			}

			if (g_tCmd.RxOk == 1)
			{
				int n;

				Form1->MemoLuaOut->Lines->Add(" --擦除扇区成功, " + IntToStr(s_idx));
				n = Form1->mFileLength / (128 * 1024);
				if (Form1->mFileLength % (128 * 1024))     /* 不是128K整数倍 */
				{
					n++;
				}
				if (++s_idx >= n)
				{
					g_tCmd.CmdStatus++;  /* 擦除完毕 */
					s_retry = 0;
					Form1->MemoLuaOut->Lines->Add("3.开始传输程序文件...");
				}
				else
				{
					g_tCmd.CmdStatus--;	/* 继续 */
				}
			}
			break;

		case CMDS_PRO_UPGRADE + 4:             /* 程序升级。4.发送程序包 */
			if (RecordID == Form1->mFileLength / UPGRADE_PACKET_LEN)  	/* 最后一包数据的索引 */
			{
				/* 参数1：包长度,
				参数2：记录号,
				参数3：记录长度,
				参数4：有效数据长度,
				参数5：数据包 */
				udp_Send15H(12 + UPGRADE_PACKET_LEN, RecordID , UPGRADE_PACKET_LEN,  Form1->mFileLength % UPGRADE_PACKET_LEN, &Form1->mFileBuf[RecordID * UPGRADE_PACKET_LEN]);
			}
			else
			{
				udp_Send15H(12 + UPGRADE_PACKET_LEN, RecordID, UPGRADE_PACKET_LEN, UPGRADE_PACKET_LEN, &Form1->mFileBuf[RecordID * UPGRADE_PACKET_LEN]);
			}
			s_LastTime = bsp_GetRunTime();
			g_tCmd.CmdStatus++;
			break;

		case CMDS_PRO_UPGRADE + 5:
			if ((bsp_CheckRunTime(s_LastTime) > 1000))   /* 超时，没有应答 */
			{
				FormSet->LabelUpgrade->Caption = " --应答超时";
				Form1->MemoLuaOut->Lines->Add(FormSet->LabelUpgrade->Caption);
				if (++s_retry >= 3)
				{
					uint32_t waddr;
					char buf[32];

					waddr = RecordID * UPGRADE_PACKET_LEN + 0x08020000;
					sprintf(buf, "0x%08X", waddr);
					FormSet->LabelUpgrade->Caption = " --程序写入异常 " + (AnsiString)buf;
					Form1->MemoLuaOut->Lines->Add(FormSet->LabelUpgrade->Caption);
					g_tCmd.CmdStatus = CMDS_PRO_UPGRADE_ERR;
					break;
				}
				else
				{
					g_tCmd.CmdStatus--;   /* 重试 */
				}
			}

			if (g_tCmd.RxOk == 1)
			{
				if (++RecordID > (Form1->mFileLength / UPGRADE_PACKET_LEN))  /* 程序发完了 */
				{
					/* 开始计时，记录程序升级用的时间 */
					Form1->TimerUpgrade->Enabled = false;

					g_tCmd.CmdStatus++;
					s_retry = 0;
				}
				else
				{
					/* 开始计时，记录程序升级用的时间 */
					Form1->TimerUpgrade->Enabled = true;

					/* 升级进度显示百分比 */
					{
						AnsiString s;

						s.sprintf("进度：%d%%", RecordID * UPGRADE_PACKET_LEN * 100  / Form1->mFileLength);
						FormSet->LabelUpgrade->Caption = s;
						/* 程序升级时间 */
						s.sprintf("耗时：%d秒", Form1->TimerUpgrade->Tag);
						FormSet->LabelUPDTime->Caption = s;
					}

					s_retry = 0;
					g_tCmd.CmdStatus--;
				}
			}
			break;

		case CMDS_PRO_UPGRADE + 6:    				   /* 程序升级。5.关闭程序升级标志 */
			udp_Send06H(REG03_BOOT_TRANS_END, 1); 	/* 通知设备程序下载完毕 */
			s_LastTime = bsp_GetRunTime();
			g_tCmd.CmdStatus++;
			break;

		case CMDS_PRO_UPGRADE + 7:
			if ((bsp_CheckRunTime(s_LastTime) > 500))   /* 超时，没有应答 */
			{
				if (++s_retry >= 3)
				{
					Form1->MemoLuaOut->Lines->Add("程序写入异常");
					g_tCmd.CmdStatus = CMDS_PRO_UPGRADE_ERR;
					break;
				}
				else
				{
					g_tCmd.CmdStatus--;   /* 重试 */
				}
			}

			if (g_tCmd.RxOk == 1)
			{
				Form1->MemoLuaOut->Lines->Add("4.程序传输完成");
				s_retry = 0;

//				if (FormSet->CheckBoxAutoUpgrade->Checked)  // 自动升级
//				{
//					g_tCmd.CmdStatus = CMDS_PRO_UPGRADE + 20;
//				}
//				else
				{
					g_tCmd.CmdStatus++;
				}
			}
			break;

		case CMDS_PRO_UPGRADE + 8:
			udp_Send06H(REG03_RESET_TO_BOOT, 1); 	/* 通知系统复位 */
			s_LastTime = bsp_GetRunTime();
			g_tCmd.CmdStatus++;
			break;

		case CMDS_PRO_UPGRADE + 9:
			if ((bsp_CheckRunTime(s_LastTime) > 200))   /* 超时，没有应答 */
			{
				if (++s_retry >= 3)
				{
					FormSet->LabelUpgrade->Caption = "复位失败";
					Form1->MemoLuaOut->Lines->Add(FormSet->LabelUpgrade->Caption);
					g_tCmd.CmdStatus = CMDS_PRO_UPGRADE_ERR;
					break;
				}
				else
				{
					g_tCmd.CmdStatus--;   /* 重试 */
				}
			}

			if (g_tCmd.RxOk == 1)
			{
				FormSet->LabelUpgrade->Caption = "5.升级成功，已复位";
				Form1->MemoLuaOut->Lines->Add(FormSet->LabelUpgrade->Caption);
				g_tCmd.CmdStatus = CMDS_PRO_UPGRADE_OK;
			}
			break;

		case CMDS_PRO_UPGRADE_ERR:
		case CMDS_PRO_UPGRADE_OK:
//			if (FormSet->CheckBoxAutoUpgrade->Checked)  // 自动升级
//			{
//				g_tCmd.CmdStatus = CMDS_PRO_UPGRADE + 20;
//			}
//			else
			{
				g_tCmd.CmdStatus = 0;
				g_tCmd.UserReq = 0;
			}
			break;

		case CMDS_PRO_UPGRADE + 20: 	/* 等待串口拔掉 */
			FormSet->LabelUpgrade->Caption = "6.等待USB线移除";
			Form1->MemoLuaOut->Lines->Add(FormSet->LabelUpgrade->Caption);
			g_tCmd.CmdStatus++;
			s_retry = 0;
			break;

		case CMDS_PRO_UPGRADE + 21:		/* 发送03读，判断USB线是否拔掉 */
			udp_Send03H(REG03_BOOT_HARD_VER, 1);
			s_LastTime = bsp_GetRunTime();
			g_tCmd.CmdStatus++;
			break;

		case CMDS_PRO_UPGRADE + 22:
			if ((bsp_CheckRunTime(s_LastTime) > 100))   /* 超时，没有应答 */
			{
				if (++s_retry >= 3)
				{
					FormSet->LabelUpgrade->Caption = "-USB线已经移除";
					Form1->MemoLuaOut->Lines->Add(FormSet->LabelUpgrade->Caption);
					g_tCmd.CmdStatus++;
					break;
				}
				else
				{
					g_tCmd.CmdStatus--;   /* 重试 */
				}
			}

			if (g_tCmd.RxOk == 1)
			{
				g_tCmd.CmdStatus--;   /* 重试 */
			}
			break;

	   case CMDS_PRO_UPGRADE + 23:
			FormSet->LabelUpgrade->Caption = "7.等待USB线插上";
			Form1->MemoLuaOut->Lines->Add(FormSet->LabelUpgrade->Caption);
			g_tCmd.CmdStatus++;
			s_retry = 0;
			break;

	   case CMDS_PRO_UPGRADE + 24:
			Form1->YbCommDevice1->Active = false;
			Form1->YbCommDevice1->Active = true;
			g_tCmd.CmdStatus++;
			s_retry = 0;
			break;

	   case CMDS_PRO_UPGRADE + 25:
			udp_Send03H(REG03_BOOT_HARD_VER, 1);
			s_LastTime = bsp_GetRunTime();
			g_tCmd.CmdStatus++;
			break;

		case CMDS_PRO_UPGRADE + 26:
			if ((bsp_CheckRunTime(s_LastTime) > 100))   /* 超时，没有应答 */
			{
				if (++s_retry >= 10)
				{
//					if (FormSet->CheckBoxAutoUpgrade->Checked)  // 自动升级
//					{
//						g_tCmd.CmdStatus -= 2;
//					}
//					else
					{
						g_tCmd.CmdStatus = 0;
						g_tCmd.UserReq = 0;
					}
					break;
				}
				else
				{
					g_tCmd.CmdStatus--;   /* 重试 */
				}
			}

			if (g_tCmd.RxOk == 1)
			{
				g_tCmd.CmdStatus =  CMDS_PRO_UPGRADE;
			}
			break;
		}
}

//--读芯片到文件--------------------------------------------------------------------
void __fastcall TFormTcp::ReadChipToFile(void)
{
	static int s_idx = 0;
	static int s_time = 0;
	static int s_retry = 0;
	static int s_head_len = 0;		/* 文件头长度 */

	switch (g_tCmd.CmdStatus)
	{
		case CMDS_SWD_READ_FLASH:
			s_idx = 0;
			g_tCmd.CmdStatus++;

			mLua.Func = 0;   /* 读第1包 */
			mLua.FlashBaseAddr = MyStrToInt(FormProg->EditReadAddr->Text)
				+  MyStrToInt(FormProg->EditReadOffset->Text) * 1024;
			mLua.Offset = 0;
			mLua.PackagLen = 1024;
			mLua.DataLen = 1024 * MyStrToInt(FormProg->EditReadFlashSize->Text);	//文件长度
			Form1->ProgressBar1->Position = 0;	// 进度条
			s_time = bsp_GetRunTime();
			break;

		case CMDS_SWD_READ_FLASH + 1:
			g_tCmd.CmdStatus++;
			break;

		case CMDS_SWD_READ_FLASH + 2:
			s_retry = 0;
			g_tCmd.CmdStatus++;
			break;

		case CMDS_SWD_READ_FLASH + 3:
			g_tCmd.err = 0;
//void udp_Send66H(uint16_t _func, uint32_t _addr, uint32_t _len, uint8_t *_buf)
			udp_Send66H(mLua.Func, mLua.FlashBaseAddr + mLua.Offset, mLua.PackagLen, 0);
			mLastTime = bsp_GetRunTime();
			g_tCmd.CmdStatus++;
			break;

		case CMDS_SWD_READ_FLASH + 4:
			if (g_tCmd.RxOk == 1)
			{
				if (g_tCmd.err == 0)  	/* 成功 */
				{
					mLua.Func = 1;		/* 读第2包和以后的包 */
					mLua.Offset += mLua.PackagLen;
					if (mLua.Offset < mLua.DataLen)
					{
						g_tCmd.CmdStatus--;  	// 继续传输
					}
					else
					{
						g_tCmd.CmdStatus++;   // 传输完成
					}
				}
				else     /* 失败 */
				{
					g_tCmd.CmdStatus = CMDS_SWD_READ_FLASH + 10;
					Form1->MemoLuaOut->Lines->Add("读存储器失败 ");
				}
				Form1->ProgressBar1->Position = 100 * mLua.Offset / mLua.DataLen;	// 进度条
				break;
			}
			if (bsp_CheckRunTime(mLastTime) > 1000)
			{
				if (++s_retry > 3)
				{
					g_tCmd.CmdStatus = 0;
					//Form1->LabelTransFile->Caption =  "通信超时 ";
					Form1->MemoLuaOut->Lines->Add("通信超时 ");
				}
				else
				{
					g_tCmd.CmdStatus--;  	// 继续传输
				}
			}
			break;

		case CMDS_SWD_READ_FLASH + 5:
			{
				AnsiString s1;
				s_time = bsp_GetRunTime() - s_time;

				s1 = "传输成功 (" + s1.sprintf("%d.%03d", s_time / 1000, s_time % 1000) + " s) "
					+ IntToStr((int)mLua.DataLen / 1024) + "KB";
				Form1->ProgressBar1->Position = 100;	// 进度条
				Form1->ProgressBar1->Refresh();

				Form1->MemoLuaOut->Lines->Add(s1);

				// 保存到文件 read_0x08000000_1024kb.bin
				{
					AnsiString name;
					AnsiString str;
					AnsiString now;

					now = Now().FormatString("YYYYMMDD_HHmmSS_");
					str.sprintf("read_0x%08X_%dkB.bin", mLua.FlashBaseAddr, mLua.DataLen / 1024);
					name = AppExePath() + "\\readback\\" + now + str;

					SaveMemToFile(name, mLua.DataBuf, mLua.DataLen);

					Form1->MemoLuaOut->Lines->Add("保存到文件: " + name);
				}

			}
			g_tCmd.CmdStatus = CMDS_SWD_READ_FLASH + 10;
			break;

		case CMDS_SWD_READ_FLASH + 10:
			g_tCmd.CmdStatus = 0;
			break;
	}
}

//--读H7-TOOL的屏幕--------------------------------------------------------------------
void __fastcall TFormTcp::ReadScreen(void)
{
	static int s_idx = 0;
	static int s_time = 0;
	static int s_retry = 0;
	static int s_head_len = 0;		/* 文件头长度 */

	switch (g_tCmd.CmdStatus)
	{
		case CMDS_READ_SCREEN:
			s_idx = 0;
			g_tCmd.CmdStatus++;

			mLua.Func = 0;   /* 读第1包 */
			mLua.FlashBaseAddr = 0;   	// 起始地址 = 0
			mLua.Offset = 0;
			mLua.PackagLen = 960;	//
			mLua.DataLen = 120 * 960;			//文件长度  240 * 240 =  120 * 960
			//Form1->ProgressBar1->Position = 0;	// 进度条
			s_time = bsp_GetRunTime();
			break;

		case CMDS_READ_SCREEN + 1:
			g_tCmd.CmdStatus++;
			break;

		case CMDS_READ_SCREEN + 2:
			s_retry = 0;
			g_tCmd.CmdStatus++;
			break;

		case CMDS_READ_SCREEN + 3:
			g_tCmd.err = 0;
			mLua.Func = H66_READ_DISP_MEM;	// 读显存
			udp_Send66H(mLua.Func, mLua.FlashBaseAddr + mLua.Offset, mLua.PackagLen, 0);
			mLastTime = bsp_GetRunTime();
			g_tCmd.CmdStatus++;
			break;

		case CMDS_READ_SCREEN + 4:
			if (g_tCmd.RxOk == 1)
			{
				if (g_tCmd.err == 0)  	/* 成功 */
				{
					mLua.Func = H66_READ_DISP_MEM;		/* 读第2包和以后的包 */
					mLua.Offset += mLua.PackagLen;
					if (mLua.Offset < mLua.DataLen)
					{
						g_tCmd.CmdStatus--;  	// 继续传输
					}
					else
					{
						g_tCmd.CmdStatus++;   // 传输完成
					}
				}
				else     /* 失败 */
				{
					g_tCmd.CmdStatus = CMDS_READ_SCREEN + 10;
					//Form1->MemoLuaOut->Lines->Add("读屏幕数据失败 ");
				}
				//Form1->ProgressBar1->Position = 100 * mLua.Offset / mLua.DataLen;	// 进度条
				break;
			}
			if (bsp_CheckRunTime(mLastTime) > 1000)
			{
				if (++s_retry > 3)
				{
					g_tCmd.CmdStatus = 0;
					//Form1->LabelTransFile->Caption =  "通信超时 ";
					//Form1->MemoLuaOut->Lines->Add("通信超时 ");
				}
				else
				{
					g_tCmd.CmdStatus--;  	// 继续传输
				}
			}
			break;

		case CMDS_READ_SCREEN + 5:
			{
				{
					TMemoryStream *ms = new TMemoryStream;
					int bmpLen;

					bmpLen = SaveScreenToBmp(240, 240, mLua.DataBuf, g_BinFile);

					ms->Write(g_BinFile, bmpLen);

					//把图像流中的位图显示到Image上面
					ms->Position = 0;
					FormSet->Image1->Picture->Bitmap->LoadFromStream(ms);

					delete ms;
				}
			}
			g_tCmd.CmdStatus = CMDS_READ_SCREEN + 10;
			break;

		case CMDS_READ_SCREEN + 10:
			g_tCmd.CmdStatus = 0;
			break;
	}
}

//---------------------------------------------------------------------------
void __fastcall TFormTcp::UserCmd(void)
{
//	static int s_scan_status = 0;
//	static int s_retry = 0;
//	static int s_LastTime;
//	static int s_idx;

	if (g_tCmd.CmdStatus >= CMDS_DOWNLOAD_LUA && g_tCmd.CmdStatus < CMDS_DOWNLOAD_LUA + 99)
	{
		DownLuaFile();   	// 下载lua小程序
	}
	else if (g_tCmd.CmdStatus >= CMDS_PRO_UPGRADE && g_tCmd.CmdStatus <= CMDS_PRO_UPGRADE + 99)
	{
		UpdateFirmware();	// 升级固件
	}
	else if (g_tCmd.CmdStatus >= CMDS_UPDATE_CHIP_FILE && g_tCmd.CmdStatus <= CMDS_UPDATE_CHIP_FILE + 99)
	{
		UpdateChipFile();	// 下载芯片数据文件
	}
	else if (g_tCmd.CmdStatus >= CMDS_SWD_READ_FLASH && g_tCmd.CmdStatus <= CMDS_SWD_READ_FLASH + 99)
	{
		ReadChipToFile();	// 读芯片数据到文件
	}
	else if (g_tCmd.CmdStatus >= CMDS_READ_SCREEN && g_tCmd.CmdStatus <= CMDS_READ_SCREEN + 99)
	{
		ReadScreen();		// 读屏幕截图
	}
	else
	{

	switch (g_tCmd.CmdStatus)
	{
		/*---- 03h -------*/
		case CMDS_SEND_03H:
			udp_Send03H(g_tCmd.RegAddr, g_tCmd.RegNum);
			g_tCmd.CmdStatus++;
			mLastTime = bsp_GetRunTime();
			break;

		case CMDS_SEND_03H + 1:
			if (g_tCmd.RxOk == 1)
			{
				g_tCmd.CmdStatus = 0;
			}
			if (bsp_CheckRunTime(mLastTime) > 1000)
			{
				g_tCmd.RxOk = 2;	/* 超时 */
				g_tCmd.CmdStatus = 0;
			}
			break;

		/*---- 06h -------*/
		case CMDS_SEND_06H:
			udp_Send06H(g_tCmd.RegAddr, g_tCmd.RegValue);
			g_tCmd.CmdStatus++;
			mLastTime = bsp_GetRunTime();
			break;

		case CMDS_SEND_06H + 1:
			if (g_tCmd.DisabelAck == 1)   /* 不需要应答的情况，PC模拟按键 */
			{
				g_tCmd.DisabelAck = 0;
				g_tCmd.CmdStatus = 0;
				break;
			}

			if (g_tCmd.RxOk == 1)
			{
				g_tCmd.CmdStatus = 0;
			}
			if (bsp_CheckRunTime(mLastTime) > 1000)
			{
				g_tCmd.CmdStatus = 0;
			}
			break;

		/*---- 10h -------*/
		case CMDS_SEND_10H:
			udp_Send10H(g_tCmd.RegAddr, g_tCmd.RegNum, g_tCmd.RegValueBuf);
			g_tCmd.CmdStatus++;
			mLastTime = bsp_GetRunTime();
			break;

		case CMDS_SEND_10H + 1:
			if (g_tCmd.RxOk == 1)
			{
				g_tCmd.CmdStatus = 0;

				if (mDispWriteRegister == 1)
				{
					mDispWriteRegister = 0;
					Form1->MemoLuaOut->Lines->Add("写寄存器成功");
				}
			}
			if (bsp_CheckRunTime(mLastTime) > 1000)
			{
				g_tCmd.CmdStatus = 0;
			}
			break;

		/*---- 0FH -------*/
		case CMDS_SEND_0FH:
			udp_Send0FH(g_tCmd.RegAddr, g_tCmd.RegNum, g_tCmd.RegValueBuf);
			g_tCmd.CmdStatus++;
			mLastTime = bsp_GetRunTime();
			break;

		case CMDS_SEND_0FH + 1:
			if (g_tCmd.RxOk == 1)
			{
				g_tCmd.CmdStatus = 0;
			}
			if (bsp_CheckRunTime(mLastTime) > 1000)
			{
				g_tCmd.CmdStatus = 0;
			}
			break;

		/*-------以太网自动搜索----------*/
		case CMDS_UDP_FIND:
			udp_Send03H_MAC(MAC_FF, REG03_NET_CPU_ID0, 21);
			g_tCmd.CmdStatus++;
			mLastTime = bsp_GetRunTime();
			break;

		case CMDS_UDP_FIND + 1:
			if (bsp_CheckRunTime(mLastTime) > 100)
			{
				g_tCmd.CmdStatus = 0;
			}
			break;

		/*----扫描波形任务-（旧版本，1问1答模式）---------------------------------*/
		case CMDS_READ_WAVE:
			if (FormTcp->CanDrawWave2 == 0)
			{
				g_tCmd.CmdStatus++;
			}
			break;

		case CMDS_READ_WAVE + 1:
			if (g_tCmd.UserReq == 1)    /* 优先响应用户指令 */
			{
				g_tCmd.CmdStatus = 0;
				break;
			}

			/* 自动触发  普通触发  单次触发  */
//			if (Form1->ComboBoxTrigMode->Text == "自动触发")
			{
              	udp_Send06H(REG03_WAVE_LOCK, 1);
				g_tCmd.CmdStatus++;
			}
//			else      /* 普通触发 */
//			{
//				mCmdStatus =  CMDS_READ_WAVE + 3;
//				mWaveReg = REG03_CH1_WAVE_0;
//			}
			mLastTime = bsp_GetRunTime();
			break;

		/* 读波形1 */
		case CMDS_READ_WAVE + 2:
			if (g_tCmd.RxOk == 1)
			{
				Form1->YbCommDevice1->Tag = 0;
				g_tCmd.CmdStatus++;
				mWaveReg = REG03_CH1_WAVE_0;
			}
			if (bsp_CheckRunTime(mLastTime) > 1000)
			{
				Form1->YbCommDevice1->Tag++;   /* 用于错误统计 */
				g_tCmd.CmdStatus = 0;
			}
			break;

		case CMDS_READ_WAVE + 3:
			if (g_tCmd.UserReq == 1)    /* 优先响应用户指令 */
			{
				g_tCmd.CmdStatus = 0;
				break;
			}
			udp_Send03H(mWaveReg, DSO_PACKAGE_SIZE / 2);
			mLastTime = bsp_GetRunTime();
			g_tCmd.CmdStatus++;
			break;

		case CMDS_READ_WAVE + 4:
			if (g_tCmd.RxOk == 1)
			{
				mWaveReg += 1;
				if (mWaveReg < REG03_CH1_WAVE_0 + SAMPLE_BUFF_SIZE / (DSO_PACKAGE_SIZE / 4))
				{
					g_tCmd.CmdStatus--;
				}
				else
				{
					g_tCmd.CmdStatus++;
                }
			}
 			if (bsp_CheckRunTime(mLastTime) > 2000)
			{
				g_tCmd.CmdStatus = 0;
			}
			break;

		/* 读波形2 */
		case CMDS_READ_WAVE + 5:
			// DrawWave1();
			//CanDrawWave1 = 1;
			g_tCmd.CmdStatus++;
			mWaveReg =  REG03_CH2_WAVE_0;
			break;

		case CMDS_READ_WAVE + 6:
			if (g_tCmd.UserReq == 1)    /* 优先响应用户指令 */
			{
				g_tCmd.CmdStatus = 0;
				break;
			}
			udp_Send03H(mWaveReg, DSO_PACKAGE_SIZE / 2);
			mLastTime = bsp_GetRunTime();
			g_tCmd.CmdStatus++;
			break;

		case CMDS_READ_WAVE + 7:
			if (g_tCmd.RxOk == 1)
			{
				mWaveReg += 1;
				if (mWaveReg < REG03_CH2_WAVE_0 + SAMPLE_BUFF_SIZE / (DSO_PACKAGE_SIZE / 4))
				{
					g_tCmd.CmdStatus--;
				}
				else
				{
					g_tCmd.CmdStatus++;
                }
			}
 			if (bsp_CheckRunTime(mLastTime) > 100)
			{
				g_tCmd.CmdStatus = 0;
			}
			break;

		case CMDS_READ_WAVE + 8:
			CanDrawWave2 = 1;
			g_tCmd.CmdStatus = CMDS_READ_AI;
			break;

		/*----扫描波形任务-（新版本，1问1答模式，测试效果不好，原因未查，暂时废弃）---------------------------------*/
		case CMDS_AUTO_WAVE:
			if (FormTcp->CanDrawWave2 == 0)
			{
				g_tCmd.CmdStatus++;
			}
			break;

		case CMDS_AUTO_WAVE + 1:
			if (g_tCmd.UserReq == 1)    /* 优先响应用户指令 */
			{
				g_tCmd.CmdStatus = 0;
				break;
			}

			udp_Send06H(REG03_WAVE_LOCK, 1);
			g_tCmd.CmdStatus++;
			mLastTime = bsp_GetRunTime();
			break;

		case CMDS_AUTO_WAVE + 2:
			if (g_tCmd.RxOk == 1)
			{
				g_tCmd.CmdStatus++;
			}
			if (bsp_CheckRunTime(mLastTime) > 300)
			{
				g_tCmd.CmdStatus = 0;
			}
			break;

		case CMDS_AUTO_WAVE + 3:
			if (g_tCmd.UserReq == 1)    /* 优先响应用户指令 */
			{
				g_tCmd.CmdStatus = 0;
				break;
			}
			//udp_Send60H(uint32_t _ChEn, uint32_t _SampleSize, uint16_t _PackageLen,  uint32_t _Offset)
			{
				uint32_t _ChEn = 0;
				uint32_t _SampleSize;
				uint16_t _PackageLen = 256;
				uint32_t _Offset = 0;

				if (Form1->CheckBoxEnCH1->Checked)
				{
					_ChEn |= 0x01;
				}
				if (Form1->CheckBoxEnCH2->Checked)
				{
					_ChEn |= 0x02;
				}
				_SampleSize = TabelBufSize[Form1->ComboBoxSampleSize->ItemIndex];
				udp_Send60H(_ChEn, _SampleSize, _PackageLen, _Offset);

				H60_ChEn = _ChEn;
				H60_SampleSize = _SampleSize;
				H60_PackageLen = _PackageLen;
				H60_Offset = _Offset;
            }

			mLastTime = bsp_GetRunTime();
			g_tCmd.CmdStatus++;
			break;

		case CMDS_AUTO_WAVE + 4:
			if (g_tCmd.RxOk == 1)
			{
				g_tCmd.RxOk = 0;
				g_tCmd.CmdStatus++;
				mLastTime = bsp_GetRunTime();
			}
			if (bsp_CheckRunTime(mLastTime) > 100)
			{
				g_tCmd.CmdStatus = 0;
			}
			break;

		case CMDS_AUTO_WAVE + 5:	/* 等待传输完毕 */
			if (H60_Ok == 1)
			{
				H60_Ok = 0;
				CanDrawWave2 = 1;
				g_tCmd.CmdStatus = CMDS_READ_AI;
			}
			if (bsp_CheckRunTime(mLastTime) > 300)
			{
				g_tCmd.CmdStatus = 0;
			}
			break;

		/*----读取模拟量（校准后的值）---------------------------------*/
		case CMDS_READ_AI:
			if (g_tCmd.UserReq == 1)    /* 优先响应用户指令 */
			{
				g_tCmd.CmdStatus = 0;
				break;
			}

			udp_Send03H(REG03_X15_00, 24);
			mLastTime = bsp_GetRunTime();
			g_tCmd.CmdStatus++;
			break;

		case CMDS_READ_AI + 1:
			if (g_tCmd.RxOk == 1)
			{
				g_tCmd.CmdStatus = CMDS_READ_ADC;
			}
 			if (bsp_CheckRunTime(mLastTime) > 100)
			{
				g_tCmd.CmdStatus = 0;
			}
			break;

		/*----读取ADC---------------------------------*/
		case CMDS_READ_ADC:
			if (g_tCmd.UserReq == 1)    /* 优先响应用户指令 */
			{
				g_tCmd.CmdStatus = 0;
				break;
			}

			udp_Send03H(REG03_ADC_CH1, 18);
			mLastTime = bsp_GetRunTime();
			g_tCmd.CmdStatus++;
			break;

		case CMDS_READ_ADC + 1:
			if (g_tCmd.RxOk == 1)
			{
				g_tCmd.CmdStatus = 0;
			}
			if (bsp_CheckRunTime(mLastTime) > 100)
			{
				g_tCmd.CmdStatus = 0;
			}
			break;



/*********************程序升级结束*******************/

		case 0:
		default:
			/* 用户指令结束后, 继续读波形 */
			if (g_tCmd.CmdStatus == 0)
			{
				if (g_tCmd.UserReq == 1)
				{
					int i;

					g_tCmd.UserReq = 0;

					g_tCmd.CmdStatus = g_tCmd.UserCmdStatus;
					g_tCmd.RegAddr = g_tCmd.UserRegAddr;	/* 寄存器地址 */
					g_tCmd.RegValue = g_tCmd.UserRegValue;	/* 寄存器值 */
					g_tCmd.RegNum = g_tCmd.UserRegNum;	/* 寄存器个数 */
					for (i = 0; i < g_tCmd.UserRegNum; i++)
					{
						g_tCmd.RegValueBuf[i] = g_tCmd.UserRegValueBuf[i];
					}
				}
				else
				{
					if (Form1->CheckBoxAutoReadWave > 0) {
						if (Form1->CheckBoxAutoReadWave->Checked)
						{
							g_tCmd.CmdStatus = CMDS_READ_WAVE;
						}
					}
				}
			}
			break;
	}
	}
}

//---------------------------------------------------------------------------
void __fastcall TFormTcp::Sacn(void)
{

}

/*
	连包。
(29 984ms) PC <-- Dev : 01 03 04 00 00 00 00 FA 33    01 03 A2 74 00 02 A7 A9   CRC 错误

(30 125ms) PC <-- Dev : 01 03 04 00 00 00 00 FA 33    01 01 01 F4 00 01 BD C4   CRC 错误

(30 250ms) PC <-- Dev : 01 01 01 01 90 48 01 01 01 F9 00 01 2C 07   CRC 错误
怘?
(30 375ms) PC <-- Dev : 01 01 01 00 51 88 01 01 01 FE 00 01 9D C6   CRC 错误
*/
// 校验数据帧，返回1表示检验oK, 0 表示错误
uint8_t M_crc16(uint8_t *_buf, uint16_t _num)
{
	uint16_t crc;

	if (CRC16_Modbus(_buf, _num) == 0)
	{
		return 1;
	}
	return 0;
}

// 解析连包数据帧。 返回第1个有效帧长度。 0 表示无效
int16_t CheckPackage(uint8_t *_buf, uint16_t _len)
{
	uint16_t len;
	uint16_t bytes;

	if (_buf[1] == 0x01)
	{
		/* 01 01 01 01 90 48 */
		len = _buf[2];
		if (_len >= 5 + len && M_crc16(_buf, 5 + len) == 1) 	/* 01 应答 */
		{
			return 5 + len;
		}

		/* 01 01 01 F9 00 01 2C 07  */
		if (_len >= 8 && M_crc16(_buf, 8) == 1) 	/* 01 命令 */
		{
			return 8;
		}

		if (_len >= 8)
		{
			return -1;
		}
	}

	else if (_buf[1] == 0x02)
	{
		/* FC 02 01 00 90 24 */
		len = _buf[2];
		if (_len >= 5 + len && M_crc16(_buf, 5 + len) == 1) 	/* 01 应答 */
		{
			return 5 + len;
		}

		/* FC 02 00 01 00 04 3D E4  */
		if (_len >= 8 && M_crc16(_buf, 8) == 1) 	/* 01 命令 */
		{
			return 8;
		}

		if (_len >= 8)
		{
			return -1;
		}
	}

	else if (_buf[1] == 0x03 || _buf[1] == 0x04)
	{
		/* 01 03 04 00 00 00 00 FA 33 */
		len = _buf[2];
		if (_len >= 5 + len  && M_crc16(_buf, 5 + len) == 1) 	/* 03 应答 */
		{
			return 5 + len;
		}

		/* 01 03 A2 74 00 02 A7 A9 */
		if (_len >= 8 && M_crc16(_buf, 8) == 1) 	/* 03 命令 */
		{
			return 8;
		}

		if (_len >= 8)
		{
			return -1;
		}
	}

	else if (_buf[1] == 0x05 || _buf[1] == 0x06)
	{
		/* FC 06 10 05 00 07 C9 24    */
		/* FC 05 00 01 FF 00 C8 17 */
		if (_len >= 8 && M_crc16(_buf, 8) == 1) 	/* 05 命令 or 应答 */
		{
			return 8;
		}

		if (_len >= 8)
		{
			return -1;
		}
	}

	else if (_buf[1] == 0x10)
	{
		/* FC 10 10 15 00 08 10 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 96 13  */
		len =  BEBufToUint16(&_buf[4]);
		if (len > 0)
		{
			bytes = 2 * len + 1;
			if (_len >= bytes + 8 && M_crc16(_buf, bytes + 8) == 1) 	/* 0F 命令 */
			{
				return bytes + 8;
			}
		}

		/* FC 10 10 15 00 08 C1 26   */
		if (_len >= 8 && M_crc16(_buf, 8) == 1) 	/* 0F 应答 */
		{
			return 8;
		}

		if (_len >= 8)
		{
			return -1;
		}
	}

	else if (_buf[1] == 0x0F)
	{
		/* FC 0F 00 01 00 40 08 00 00 00 00 00 00 00 00 2B 26 */
		len =  BEBufToUint16(&_buf[4]);
		if (len > 0)
		{
			bytes = (len + 7) / 8;
			if (_len >= bytes + 8 && M_crc16(_buf, bytes + 8) == 1) 	/* 0F 命令 */
			{
				return bytes + 8;
			}
		}

		/* FC 0F 00 01 00 40 10 16   */
		if (_len >= 8 && M_crc16(_buf, 8) == 1) 	/* 0F 应答 */
		{
			return 8;
		}

		if (_len >= 8)
		{
			return -1;
		}
	}

	else if (_buf[1] == 0x60)
	{
		/*
			PC发送 60H
			01  ; 从机地址
			60  ; 功能码
			00  : 00表示PC下发，01表示设备应答 （仅仅用于人工分析）
			01 00 00 00  : 通道号使能标志 32bit，bit0表示CH1，bit1表示CH2
			00 00 04 00: 每个通道样本个数
			01 00 : 每通信包样本长度. 单位为1个样本。
			00 00 00 00 : 通道数据偏移 （样本单位，用于重发）
			CC CC : CRC16
		*/
		if (_len >= 19 && M_crc16(_buf, 19) == 1) 	/* 应答异常 */
		{
			return 19;
		}

		/*
		从机首先应答: 60H -

			01  ; 从机地址
			60  ; 功能码
			01  : 00表示PC下发，01表示设备应答 （仅仅用于人工分析）
			01 00 00 00  : 通道号使能标志 32bit，bit0表示CH1，bit1表示CH2
			00 00 04 00 : 每个通道样本个数
			01 00 : 每通信包样本长度. 单位为1个样本。
			00 00 00 00 :
		*/
		if (_len >= 19 && M_crc16(_buf, 19) == 1) 	/* 应答异常 */
		{
			return 19;
		}

		if (_len >= 19)
		{
			return -1;
		}
	}

	else if (_buf[1] == 0x61)
	{
		/*
            H7-TOOL主动发送:
                01  ; 从机地址 ，为1
                61  ; 功能码
                00  ; 通道号，00表示print
                01  : 长度高字节
                08  : 长度低字节
                xx xx xx xx ... : 数据体
				CC CC : CRC16
		*/
		len = BEBufToUint16(&_buf[3]);
		if (_len >= len + 7 && M_crc16(_buf, len + 7) == 1)
		{
			return len + 7;
		}

		if (_len >= len + 7)
		{
			return -1;
		}
	}

	else if (_buf[1] == 0x64)
	{
		/*
		从机应答:
			01  ; 从机地址
			64  ; 功能码
			00  ; 执行结果，0表示OK  1表示错误
			CCCC : CRC16
		*/
		if (_len >= 5 && M_crc16(_buf, 5) == 1) 	/* 应答异常 */
		{
			return 5;
		}

		/*
			主机发送: 小程序数据
			01  ; 站号
			64  ; 功能码
			0100 0000 ; 总长度 4字节
			0000 0000 : 偏移地址 4字节
			0020 0000 : 本包数据长度 4字节
			xx ... xx : 程序数据，n个
			CCCC      : CRC16
		*/
		len = BEBufToUint32(&_buf[10]);
		if (_len >= len + 16)
		{
			if (M_crc16(_buf, len + 16) == 1)
			{
				return len + 16;
			}
			else
			{
				 return -1;
			}
		}

	}

	else if (_buf[1] == 0x65)
	{
		/*
		从机应答:
			01  ; 从机地址
			65  ; 功能码
			00  ; 执行结果，0表示OK  1表示错误
			CCCC : CRC16
		*/
		if (_len >= 5 && M_crc16(_buf, 5) == 1) 	/* 应答异常 */
		{
			return 5;
		}

		/*
		65H - 执行临时的LUA程序，命令帧带程序
			01  ; 从机地址
			65  ; 功能码
			0100 : 本包数据长度 2字节
			xxxx : 脚本数据，0结束
			CCCC : CRC16
		*/
		len = BEBufToUint16(&_buf[2]);
		if (_len >= len + 6)
		{
			if (M_crc16(_buf, len + 6) == 1)
			{
				return len + 6;
			}
			else
			{
				 return -1;
			}
		}
	}
	else if (_buf[1] == 0x66)
	{
		/*
			主机发送: 小程序数据
				01  ; 站号
				66  ; 功能码
				0000  ; 子功能,
					- 0表示读内存（需要初始化pg_init())
					- 1表示读内存 (连续读，无需初始化）
					- 2 写

					- 0x0100   读显示屏缓冲区，用于截屏
				0000 0000 : 偏移地址 4字节
				0020 0000 : 数据长度 4字节
				CCCC      : CRC16

			从机应答:
				01  ; 从机地址
				66  ; 功能码
				0000  ; 子功能
				0000 0000 : 偏移地址 4字节
				0020 0000 : 数据长度 4字节

				00  ; 执行结果，0表示OK  1表示错误

				XX XX ... XX : 数据

				CCCC : CRC16
		*/
		if (_len >= 5 && M_crc16(_buf, 5) == 1) 	/* 应答异常 */
		{
			return 5;
		}

		len = BEBufToUint32(&_buf[8]);
		if (_len >= len + 15)
		{
			if (M_crc16(_buf, len + 15) == 1)
			{
				return len + 15;
			}
			else
			{
				return -1;
			}
		}
	}


//	if (_buf[1] == 0x81 || _buf[1] == 0x82 || _buf[1] == 0x83
//		|| _buf[1] == 0x84 || _buf[1] == 0x85 || _buf[1] == 0x86
//		|| _buf[1] == 0x90 || _buf[1] == 0x8F || _buf[1] == (0x80 + 0x61))
	if (_buf[1] & 0x80)
	{
		/* FC 83 10 C1 26  */
		if (_len >= 5 && M_crc16(_buf, 5) == 1) 	/* 应答异常 */
		{
			return 5;
		}

		if (_len >= 5)
		{
			 return -1;
		}
	}
	return 0;
}

void AnalyzePackage(uint8_t *_rxbuf, uint16_t _rxlen)
{
	switch (_rxbuf[1])
	{
		case 0x03:		// 03H指令的应答
			FormTcp->MODH_03H(_rxbuf, _rxlen);
			g_tCmd.RxOk = 1;
			break;

		case 0x06:		// 06H指令的应答
			FormTcp->MODH_06H(_rxbuf, _rxlen);
			g_tCmd.RxOk = 1;
			break;

		case 0x10:		// 10H指令的应答
			FormTcp->MODH_10H(_rxbuf, _rxlen);
			g_tCmd.RxOk = 1;
			break;

		case 0x0F:		// 0FH指令的应答
			g_tCmd.RxOk = 1;
			break;

		case 0x15:		// 15H指令的应答
			g_tCmd.RxOk = 1;
			break;

		case 0x60:
			g_tCmd.RxOk = 1;
			break;

		case 0x61:  	// Modbus print
			FormTcp->MODH_61H(_rxbuf, _rxlen);
			break;

		case 0x64:
			g_tCmd.err = _rxbuf[4];

			#if 0
			{
				AnsiString s;
				uint32_t total, off, len;

				total = BEBufToUint32(_rxbuf + 5);
				off = BEBufToUint32(_rxbuf + 5 + 4);
				len = BEBufToUint32(_rxbuf + 5 + 8);
				s.sprintf("  rx total = %X, off = %d(%X), len = %d\r\n",
					total, off, off, len);
				Form1->MemoLuaOut->Lines->Add(s);
			}
			#endif
			g_tCmd.RxOk = 1;
			break;

		case 0x65:
			g_tCmd.RxOk = 1;
			break;

		case 0x66:
			FormTcp->MODH_66H(_rxbuf, _rxlen);
			/*
				主机发送: 小程序数据
					01  ; 站号
					66  ; 功能码
					0000  ; 子功能,
						- 0表示读内存
						- 1表示写内存
					0000 0000 : 偏移地址 4字节
					0020 0000 : 数据长度 4字节
					CCCC      : CRC16

				从机应答:
					01  ; 从机地址
					66  ; 功能码
					0000  ; 子功能
					0000 0000 : 偏移地址 4字节
					0020 0000 : 数据长度 4字节

					00  ; 执行结果，0表示OK  1表示错误

					CCCC : CRC16
			*/
			g_tCmd.RxOk = 1;
			g_tCmd.err = _rxbuf[12];
			break;

		case 0x83:    /* 异常 */
		case 0x86:
		case 0x90:
			{
				AnsiString s;

				s.sprintf("执行异常 0x%X", _rxbuf[1]);
				FormCalib->Memo1->Lines->Add(s);
			}
			break;

		 default:
			break;
	}
}

// 处理接收的数据
void __fastcall TFormTcp::DealRxData(void)
{
	if (s_RxLen == 0)
	{
		return;
	}

	try
	{
		// 不带MAC的帧
		if (CRC16_Modbus(s_RxBuf, s_RxLen) == 0)
		{
			if (s_RxLen == 1029) {
				 s_RxLen++;
				 s_RxLen--;
			}
			AnalyzePackage(s_RxBuf, s_RxLen);


			#if 0
			{
				char buf[128];

				sprintf(buf,  "s_RxLenOk = %02X %02X  %d",
					s_RxBuf[0], s_RxBuf[1],	s_RxLen);

				Form1->MemoLuaOut->Lines->Add((AnsiString)buf);
			}
			#endif

			s_RxLen = 0;

			return;
		}
		else
		{
			#if 0
			{
				char buf[128];

				sprintf(buf,  "s_RxLenErr = %02X %02X  %d",
					s_RxBuf[0], s_RxBuf[1],	s_RxLen);

				Form1->MemoLuaOut->Lines->Add((AnsiString)buf);
			}
			#endif
		}

		{
			{
				int ok_len;
				uint16_t ok_pos = 0;

				/* 帧同步 */
				if (s_RxBuf[0] != 1 && s_RxBuf[0] != 0xC8)
				{
					s_RxLen = 0;
					Form1->MemoLuaOut->Lines->Add("收到的数据包帧不同步");
					return;
				}

				for (;;)
				{
					if (s_RxBuf[0] == 0xC8)   // 带MAC的帧
					{
						ok_len = CheckPackage(&s_RxBuf[6], s_RxLen);
						if (ok_len > 0)
						{
							int i;
							AnalyzePackage(&s_RxBuf[6], ok_len);   	/* 处理数据 */
							/* 数据前移 */
							for (i = 0; i < s_RxLen - ok_len + 6; i++)
							{
								s_RxBuf[i] = s_RxBuf[i + ok_len + 6];
							}
							s_RxLen = s_RxLen - ok_len - 6;
						}
						else  if (ok_len == -1)
						{
							s_RxLen = 0;
							break;
						}
						else
						{
							break;
						}
					}
					else if (s_RxBuf[0] == 0x01)  // 正常通信帧
					{
						ok_len = CheckPackage(s_RxBuf, s_RxLen);
						if (ok_len > 0)
						{
							int i;
							AnalyzePackage(s_RxBuf, ok_len);   	/* 处理数据 */

							#if 0
							{
								char buf[128];

								sprintf(buf,  " s_RxLenPP = %02X %02X  %d",
									s_RxBuf[0], s_RxBuf[1],	ok_len);

								Form1->MemoLuaOut->Lines->Add((AnsiString)buf);
							}
							#endif

							/* 数据前移 */
							for (i = 0; i < s_RxLen - ok_len; i++)
							{
								s_RxBuf[i] = s_RxBuf[i + ok_len];
							}
							s_RxLen -= ok_len;
						}
						else  if (ok_len == -1)
						{
							s_RxLen = 0;
							break;
						}
						else
						{
							break;
						}
					}
					else
					{
						s_RxLen = 0;
						return;
					}
				}
			}
		}
	}
	catch (Exception &e)
	{
		Form1->MemoLuaOut->Lines->Add("分析数据异常");
	}
}

// 处理USB串口接收的数据  lua调试用
void __fastcall TFormTcp::DispUartData(void)
{
	int i;
	char *p;

	if (s_USB_RxLen == 0)
	{
		return;
	}
	s_USB_RxBuf[s_USB_RxLen] = 0;
	p = s_USB_RxBuf;
	for (i = 0; i < s_USB_RxLen; i++)
	{
		if (s_USB_RxBuf[i] == 0x0A)
		{
			s_USB_RxBuf[i] = 0;
			Form1->MemoLuaOut->Lines->Add((AnsiString)p);
			p = &s_USB_RxBuf[i + 1];
		}
	}
	s_USB_RxLen = 0;
}

// 通信线程死循环
void __fastcall TFormTcp::CommTaskLoop(void)
{
	;
}

//---------------------------------------------------------------------------

void __fastcall TFormTcp::SendTcpCmd(uint32_t ip, uint32_t tcp_port)
{

}

void __fastcall TFormTcp::SendUdpCmd(uint32_t ip, uint32_t port, uint8_t * cmd_buf, uint16_t cmd_len)
{
	uint8_t *p;
	AnsiString ip_str;

	// 将32位的IP地址转换为字符串格式
	ip_str =  IntToStr((uint8_t)(ip >> 24)) + '.'
		+ IntToStr((uint8_t)(ip >> 16)) + '.' + IntToStr((uint8_t)(ip >> 8)) +
		'.' + IntToStr((uint8_t)ip);
#if 0
	LabelInfoBar->Caption = "UDP扫描 " + ip_str;
#endif
	// 发送到UDP服务端
	{
		TByteDynArray buf;

		buf = RawToBytes(cmd_buf, cmd_len);
		FormTcp->UDP1->SendBuffer(ip_str, port, buf);
	}
}

void __fastcall TFormTcp::SendUdpCmd2(AnsiString str_ip, uint32_t port, uint8_t * cmd_buf, uint16_t cmd_len)
{
	// 发送到UDP服务端
	{
		TByteDynArray buf;

		buf = RawToBytes(cmd_buf, cmd_len);
		FormTcp->UDP1->SendBuffer(str_ip, port, buf);
	}
}

void __fastcall TFormTcp::MODH_03H(uint8_t *_rx_buf, uint16_t _len)
{
	AnsiString s1,s2;
	AnsiString ip;
	int pos = 0;
	char *p;
	float f1;

	switch (g_tCmd.RegAddr)
	{
		case REG03_NET_CPU_ID0:        // UDP搜索 ,带MAC地址
			{
				if (_len != 21 * 2 + 5)
				{
					break;
				}
				/* 前6字节是mac地址，过滤掉重复的 */
				#if 0
				{
					uint8_t mac[6];
					int i;

					p = &_rx_buf[0] - 6;
					memcpy(mac, p, 6);

					for (i = 0; i < mDevNum; i++)
					{
						if (memcmp(mac,  mDevList[i].Mac, 6) == 0)
						{
							return;
						}
					}
				}
				#endif

				pos = 0;
				p = &_rx_buf[3];

				memcpy(mDevList[mDevNum].CpuID,  p, 12);  p += 12;
				mDevList[mDevNum].HardVer = BEBufToUint16(p); p += 2;
				mDevList[mDevNum].SoftVer = BEBufToUint16(p); p += 2;
				memcpy(mDevList[mDevNum].Mac,  p, 6); p += 6;
				memcpy(mDevList[mDevNum].LocalIP,  p, 4); p += 4;
				memcpy(mDevList[mDevNum].NetMask,  p, 4); p += 4;
				memcpy(mDevList[mDevNum].GateWay,  p, 4); p += 4;
				mDevList[mDevNum].LocalPort = BEBufToUint16(p); p += 2;
				memcpy(mDevList[mDevNum].SysIP,  p, 4); p += 4;
				mDevList[mDevNum].SysPort = BEBufToUint16(p);

				s1.sprintf("MAC = %02X-%02X-%02X-%02X-%02X-%02X", mDevList[mDevNum].Mac[0], mDevList[mDevNum].Mac[1], mDevList[mDevNum].Mac[2],
						mDevList[mDevNum].Mac[3], mDevList[mDevNum].Mac[4], mDevList[mDevNum].Mac[5]);
				s2 = s1;

				s1.sprintf("IP = %d.%d.%d.%d", mDevList[mDevNum].LocalIP[0], mDevList[mDevNum].LocalIP[1], mDevList[mDevNum].LocalIP[2],
						mDevList[mDevNum].LocalIP[3]);
				s2 += "," + s1;

				s1.sprintf("HardVer = %04X", mDevList[mDevNum].HardVer);
				s2 += "," + s1;

				s1.sprintf("SoftVer = %04X", mDevList[mDevNum].SoftVer);
				s2 += "," + s1;

				mDevNum++;

				if (mDevNum > MAX_NUM)
				{
					mDevNum = MAX_NUM;
				}

				{
					uint16_t addr, year, month, day, hour, min, sec, msec;
					TDateTime tt;
					AnsiString s1;

					tt = Now();
					tt.DecodeTime(&hour, &min, &sec, &msec);
					tt.DecodeDate(&year, &month, &day);

					s1.sprintf("%02d:%02d:%02d, ", hour, min, sec);
					FormSet->ListBox1->Items->Add(s1 + s2);


					//FormSet->LabelResult->Caption = "已扫描到: " + IntToStr(mDevNum);

					Form1->MemoLuaOut->Lines->Add(s1 + s2);
					//Form1->MemoLuaOut->Lines->Add(FormSet->LabelResult->Caption);
				}

				if (mDevNum > 0)
				{
					FormSet->ListBox1->ItemIndex = 0;
					FormSet->ListBox1Click(this);
				}
			}
			break;

		case REG03_X15_00:	//REG03_AI_CH1:
			if (_rx_buf[2] != ((24 * 2) % 256))
			{
				break;
			}
//	float CH1Volt;
//	float CH2Volt;
//	float HighSideVolt;
//	float HighSideCurr;
//	float TVCCVolt;		/* TVCC实测电压 */
//	float TVCCCurr;		/* TVCC实测电压 */
//	float NTCRes;		/* NTC电阻 */
//	float NTCTemp;		/* NTC温度 */
//	float USBPowerVolt;
//	float ExtPowerVolt;
			p = &_rx_buf[3];
			g_tAI.X15_00 = BEBufToUint16(p); p += 2;
			g_tAI.X31_16 = BEBufToUint16(p); p += 2;
			g_tAI.Y15_00 = BEBufToUint16(p); p += 2;
			g_tAI.Y31_16 = BEBufToUint16(p); p += 2;

			if (g_tAI.X15_00 & 0x200) Form1->ShapeX9->Brush->Color = clRed; else Form1->ShapeX9->Brush->Color = clGray;
			if (g_tAI.X15_00 & 0x100) Form1->ShapeX8->Brush->Color = clRed; else Form1->ShapeX8->Brush->Color = clGray;
			if (g_tAI.X15_00 & 0x80) Form1->ShapeX7->Brush->Color = clRed; else Form1->ShapeX7->Brush->Color = clGray;
			if (g_tAI.X15_00 & 0x40) Form1->ShapeX6->Brush->Color = clRed; else Form1->ShapeX6->Brush->Color = clGray;
			if (g_tAI.X15_00 & 0x20) Form1->ShapeX5->Brush->Color = clRed; else Form1->ShapeX5->Brush->Color = clGray;
			if (g_tAI.X15_00 & 0x10) Form1->ShapeX4->Brush->Color = clRed; else Form1->ShapeX4->Brush->Color = clGray;
			if (g_tAI.X15_00 & 0x08) Form1->ShapeX3->Brush->Color = clRed; else Form1->ShapeX3->Brush->Color = clGray;
			if (g_tAI.X15_00 & 0x04) Form1->ShapeX2->Brush->Color = clRed; else Form1->ShapeX2->Brush->Color = clGray;
			if (g_tAI.X15_00 & 0x02) Form1->ShapeX1->Brush->Color = clRed; else Form1->ShapeX1->Brush->Color = clGray;
			if (g_tAI.X15_00 & 0x01) Form1->ShapeX0->Brush->Color = clRed; else Form1->ShapeX0->Brush->Color = clGray;

			if (g_tAI.Y15_00 & 0x200) Form1->ShapeY9->Brush->Color = clRed; else Form1->ShapeY9->Brush->Color = clGray;
			if (g_tAI.Y15_00 & 0x100) Form1->ShapeY8->Brush->Color = clRed; else Form1->ShapeY8->Brush->Color = clGray;
			if (g_tAI.Y15_00 & 0x80) Form1->ShapeY7->Brush->Color = clRed; else Form1->ShapeY7->Brush->Color = clGray;
			if (g_tAI.Y15_00 & 0x40) Form1->ShapeY6->Brush->Color = clRed; else Form1->ShapeY6->Brush->Color = clGray;
			if (g_tAI.Y15_00 & 0x20) Form1->ShapeY5->Brush->Color = clRed; else Form1->ShapeY5->Brush->Color = clGray;
			if (g_tAI.Y15_00 & 0x10) Form1->ShapeY4->Brush->Color = clRed; else Form1->ShapeY4->Brush->Color = clGray;
			if (g_tAI.Y15_00 & 0x08) Form1->ShapeY3->Brush->Color = clRed; else Form1->ShapeY3->Brush->Color = clGray;
			if (g_tAI.Y15_00 & 0x04) Form1->ShapeY2->Brush->Color = clRed; else Form1->ShapeY2->Brush->Color = clGray;
			if (g_tAI.Y15_00 & 0x02) Form1->ShapeY1->Brush->Color = clRed; else Form1->ShapeY1->Brush->Color = clGray;
			if (g_tAI.Y15_00 & 0x01) Form1->ShapeY0->Brush->Color = clRed; else Form1->ShapeY0->Brush->Color = clGray;

			f1 = BEBufToFloat(p); s1.sprintf("%8.3fV", f1); Form1->LabelCH1_Volt->Caption = s1;  g_tAI.CH1Volt = f1; p += 4;
			f1 = BEBufToFloat(p); s1.sprintf("%8.3fV", f1); Form1->LabelCH2_Volt->Caption = s1;  g_tAI.CH2Volt = f1; p += 4;
			f1 = BEBufToFloat(p); s1.sprintf("%8.2fV", f1); Form1->LabelLoad_Volt->Caption = s1;  g_tAI.HighSideVolt = f1; p += 4;
			f1 = BEBufToFloat(p); s1.sprintf("%8.2fmA", f1); Form1->LabelLoad_Curr->Caption = s1;  g_tAI.HighSideCurr = f1; p += 4;
			f1 = BEBufToFloat(p); s1.sprintf("%8.3fV", f1); Form1->LabelTVCC_Volt->Caption = s1;  g_tAI.TVCCVolt = f1; p += 4;
			f1 = BEBufToFloat(p); s1.sprintf("%8.3fmA", f1); Form1->LabelTVCC_Curr->Caption = s1;  g_tAI.TVCCCurr = f1; p += 4;
			f1 = BEBufToFloat(p); s1.sprintf("%8.3fKΩ", f1); Form1->LabelNTC_Res->Caption = s1;  g_tAI.NTCRes = f1; p += 4;
			f1 = BEBufToFloat(p); s1.sprintf("%8.2f℃", f1); Form1->LabelNTC_Temp->Caption = s1;  g_tAI.NTCTemp = f1; p += 4;
			f1 = BEBufToFloat(p); s1.sprintf("%8.2fV", f1);  g_tAI.USBPowerVolt = f1; p += 4;
			f1 = BEBufToFloat(p); s1.sprintf("%8.2fV", f1);  g_tAI.ExtPowerVolt = f1; p += 4;
			break;

		case REG03_ADC_CH1:
			if (_rx_buf[2] != ((18 * 2) % 256))
			{
				break;
			}
			p = &_rx_buf[3];
			f1 = BEBufToFloat(p); s1.sprintf("%8.1f", f1); Form1->LabelCH1_Adc->Caption = s1;  g_tAI.ADC_CH1Volt = f1; p += 4;
			f1 = BEBufToFloat(p); s1.sprintf("%8.1f", f1); Form1->LabelCH2_Adc->Caption = s1;  g_tAI.ADC_CH2Volt = f1; p += 4;
			f1 = BEBufToFloat(p); s1.sprintf("%8.1f", f1); Form1->LabelLoad_Volt_Adc->Caption = s1;  g_tAI.ADC_HighSideVolt = f1; p += 4;
			f1 = BEBufToFloat(p); s1.sprintf("%8.1f", f1); Form1->LabelLoad_Curr_Adc->Caption = s1;  g_tAI.ADC_HighSideCurr = f1; p += 4;
			f1 = BEBufToFloat(p); s1.sprintf("%8.1f", f1); Form1->LabelTVCC_Volt_Adc->Caption = s1;  g_tAI.ADC_TVCCVolt = f1; p += 4;
			f1 = BEBufToFloat(p); s1.sprintf("%8.1f", f1); Form1->LabelTVCC_Curr_Adc->Caption = s1;  g_tAI.ADC_TVCCCurr = f1; p += 4;
			f1 = BEBufToFloat(p); s1.sprintf("%8.1f", f1); Form1->LabelNTC_Adc->Caption = s1;  g_tAI.ADC_NTCRes = f1; p += 4;
			f1 = BEBufToFloat(p); s1.sprintf("%8.1f", f1);  g_tAI.ADC_USBPowerVolt = f1; p += 4;
			f1 = BEBufToFloat(p); s1.sprintf("%8.1f", f1);  g_tAI.ADC_ExtPowerVolt = f1; p += 4;
			break;

		case REG03_CALIB_CH1_R1_X1:		/* 校准参数 232个 */
			/* 解析校准参数 */
			if (_rx_buf[2] != ((232 * 2) % 256))
			{
				break;
			}
			{
				p = &_rx_buf[3];
				int i;
				for (i = 0; i < 8; i++)
				{
					g_tCalib.CH1[i].x1 = BEBufToFloat(p); p += 4;
					g_tCalib.CH1[i].y1 = BEBufToFloat(p); p += 4;
					g_tCalib.CH1[i].x2 = BEBufToFloat(p); p += 4;
					g_tCalib.CH1[i].y2 = BEBufToFloat(p); p += 4;
				}
				for (i = 0; i < 8; i++)
				{
					g_tCalib.CH2[i].x1 = BEBufToFloat(p); p += 4;
					g_tCalib.CH2[i].y1 = BEBufToFloat(p); p += 4;
					g_tCalib.CH2[i].x2 = BEBufToFloat(p); p += 4;
					g_tCalib.CH2[i].y2 = BEBufToFloat(p); p += 4;
				}
				g_tCalib.LoadVolt.x1 = BEBufToFloat(p); p += 4;
				g_tCalib.LoadVolt.y1 = BEBufToFloat(p); p += 4;
				g_tCalib.LoadVolt.x2 = BEBufToFloat(p); p += 4;
				g_tCalib.LoadVolt.y2 = BEBufToFloat(p); p += 4;

				g_tCalib.LoadCurr[0].x1 = BEBufToFloat(p); p += 4;
				g_tCalib.LoadCurr[0].y1 = BEBufToFloat(p); p += 4;
				g_tCalib.LoadCurr[0].x2 = BEBufToFloat(p); p += 4;
				g_tCalib.LoadCurr[0].y2 = BEBufToFloat(p); p += 4;
				g_tCalib.LoadCurr[0].x3 = BEBufToFloat(p); p += 4;
				g_tCalib.LoadCurr[0].y3 = BEBufToFloat(p); p += 4;
				g_tCalib.LoadCurr[0].x4 = BEBufToFloat(p); p += 4;
				g_tCalib.LoadCurr[0].y4 = BEBufToFloat(p); p += 4;

				g_tCalib.LoadCurr[1].x1 = BEBufToFloat(p); p += 4;
				g_tCalib.LoadCurr[1].y1 = BEBufToFloat(p); p += 4;
				g_tCalib.LoadCurr[1].x2 = BEBufToFloat(p); p += 4;
				g_tCalib.LoadCurr[1].y2 = BEBufToFloat(p); p += 4;
				g_tCalib.LoadCurr[1].x3 = BEBufToFloat(p); p += 4;
				g_tCalib.LoadCurr[1].y3 = BEBufToFloat(p); p += 4;
				g_tCalib.LoadCurr[1].x4 = BEBufToFloat(p); p += 4;
				g_tCalib.LoadCurr[1].y4 = BEBufToFloat(p); p += 4;

				g_tCalib.TVCCVolt.x1 = BEBufToFloat(p); p += 4;
				g_tCalib.TVCCVolt.y1 = BEBufToFloat(p); p += 4;
				g_tCalib.TVCCVolt.x2 = BEBufToFloat(p); p += 4;
				g_tCalib.TVCCVolt.y2 = BEBufToFloat(p); p += 4;

				g_tCalib.TVCCCurr.x1 = BEBufToFloat(p); p += 4;
				g_tCalib.TVCCCurr.y1 = BEBufToFloat(p); p += 4;
				g_tCalib.TVCCCurr.x2 = BEBufToFloat(p); p += 4;
				g_tCalib.TVCCCurr.y2 = BEBufToFloat(p); p += 4;
				g_tCalib.TVCCCurr.x3 = BEBufToFloat(p); p += 4;
				g_tCalib.TVCCCurr.y3 = BEBufToFloat(p); p += 4;
				g_tCalib.TVCCCurr.x4 = BEBufToFloat(p); p += 4;
				g_tCalib.TVCCCurr.y4 = BEBufToFloat(p); p += 4;

				g_tCalib.TVCCSet.x1 = BEBufToFloat(p); p += 4;
				g_tCalib.TVCCSet.y1 = BEBufToFloat(p); p += 4;
				g_tCalib.TVCCSet.x2 = BEBufToFloat(p); p += 4;
				g_tCalib.TVCCSet.y2 = BEBufToFloat(p); p += 4;

				g_tCalib.Dac10V.x1 = BEBufToUint16(p); p += 2;
				g_tCalib.Dac10V.y1 = (int16_t)BEBufToUint16(p); p += 2;
				g_tCalib.Dac10V.x2 = BEBufToUint16(p); p += 2;
				g_tCalib.Dac10V.y2 = (int16_t)BEBufToUint16(p); p += 2;
				g_tCalib.Dac10V.x3 = BEBufToUint16(p); p += 2;
				g_tCalib.Dac10V.y3 = (int16_t)BEBufToUint16(p); p += 2;
				g_tCalib.Dac10V.x4 = BEBufToUint16(p); p += 2;
				g_tCalib.Dac10V.y4 = (int16_t)BEBufToUint16(p); p += 2;

				g_tCalib.Dac20mA.x1 = BEBufToUint16(p); p += 2;
				g_tCalib.Dac20mA.y1 = (int16_t)BEBufToUint16(p); p += 2;
				g_tCalib.Dac20mA.x2 = BEBufToUint16(p); p += 2;
				g_tCalib.Dac20mA.y2 = (int16_t)BEBufToUint16(p); p += 2;
				g_tCalib.Dac20mA.x3 = BEBufToUint16(p); p += 2;
				g_tCalib.Dac20mA.y3 = (int16_t)BEBufToUint16(p); p += 2;
				g_tCalib.Dac20mA.x4 = BEBufToUint16(p); p += 2;
				g_tCalib.Dac20mA.y4 = (int16_t)BEBufToUint16(p); p += 2;

				g_tCalib.NtcRes.x1 = BEBufToFloat(p); p += 4;
				g_tCalib.NtcRes.y1 = BEBufToFloat(p); p += 4;
				g_tCalib.NtcRes.x2 = BEBufToFloat(p); p += 4;
				g_tCalib.NtcRes.y2 = BEBufToFloat(p); p += 4;
				g_tCalib.NtcRes.x3 = BEBufToFloat(p); p += 4;
				g_tCalib.NtcRes.y3 = BEBufToFloat(p); p += 4;
				g_tCalib.NtcRes.x4 = BEBufToFloat(p); p += 4;
				g_tCalib.NtcRes.y4 = BEBufToFloat(p); p += 4;

				FormCalib->FileCalibToEdit();
			}

			{
				FormCalib->Memo1->Lines->Add("-----------------------------------");
				FormCalib->Memo1->Lines->Add("读校准参数成功");
				int i;
				FormCalib->Memo1->Lines->Add("                x1(adc)      y1(模拟量)   x2(adc)      y2(模拟量)");
				for (i = 0; i < 8; i++)
				{
					s1.sprintf("CH1_R%d    = %12.3f,%12.3f,%12.3f,%12.3f", i + 1, g_tCalib.CH1[i].x1, g_tCalib.CH1[i].y1,
							g_tCalib.CH1[i].x2, g_tCalib.CH1[i].y2);
					FormCalib->Memo1->Lines->Add(s1);
				}
				FormCalib->Memo1->Lines->Add("");
				for (i = 0; i < 8; i++)
				{
					s1.sprintf("CH2_R%d    = %12.3f,%12.3f,%12.3f,%12.3f", i + 1, g_tCalib.CH2[i].x1, g_tCalib.CH2[i].y1,
							g_tCalib.CH2[i].x2, g_tCalib.CH2[i].y2);
					FormCalib->Memo1->Lines->Add(s1);
				}

				FormCalib->Memo1->Lines->Add("");

				s1.sprintf("LoadVolt  = %12.3f,%12.3f,%12.3f,%12.3f",  g_tCalib.LoadVolt.x1, g_tCalib.LoadVolt.y1,
							g_tCalib.LoadVolt.x2, g_tCalib.LoadVolt.y2);
				FormCalib->Memo1->Lines->Add(s1);

				s1.sprintf("LoadCurr1 = %12.3f,%12.3f,%12.3f,%12.3f", g_tCalib.LoadCurr[0].x1, g_tCalib.LoadCurr[0].y1,
							g_tCalib.LoadCurr[0].x2, g_tCalib.LoadCurr[0].y2);
				FormCalib->Memo1->Lines->Add(s1);
				s1.sprintf("            %12.3f,%12.3f,%12.3f,%12.3f", g_tCalib.LoadCurr[0].x3, g_tCalib.LoadCurr[0].y3,
							g_tCalib.LoadCurr[0].x4, g_tCalib.LoadCurr[0].y4);
				FormCalib->Memo1->Lines->Add(s1);

				s1.sprintf("LoadCurr2 = %12.3f,%12.3f,%12.3f,%12.3f", g_tCalib.LoadCurr[1].x1, g_tCalib.LoadCurr[1].y1,
							g_tCalib.LoadCurr[1].x2, g_tCalib.LoadCurr[1].y2);
				FormCalib->Memo1->Lines->Add(s1);
				s1.sprintf("            %12.3f,%12.3f,%12.3f,%12.3f", g_tCalib.LoadCurr[1].x3, g_tCalib.LoadCurr[1].y3,
							g_tCalib.LoadCurr[1].x4, g_tCalib.LoadCurr[1].y4);
				FormCalib->Memo1->Lines->Add(s1);

				s1.sprintf("TVCCVolt  = %12.3f,%12.3f,%12.3f,%12.3f", g_tCalib.TVCCVolt.x1, g_tCalib.TVCCVolt.y1,
							g_tCalib.TVCCVolt.x2, g_tCalib.TVCCVolt.y2);
				FormCalib->Memo1->Lines->Add(s1);

				s1.sprintf("TVCCCurr  = %12.3f,%12.3f,%12.3f,%12.3f", g_tCalib.TVCCCurr.x1, g_tCalib.TVCCCurr.y1,
							g_tCalib.TVCCCurr.x2, g_tCalib.TVCCCurr.y2);
				FormCalib->Memo1->Lines->Add(s1);
				s1.sprintf("          = %12.3f,%12.3f,%12.3f,%12.3f", g_tCalib.TVCCCurr.x3, g_tCalib.TVCCCurr.y3,
							g_tCalib.TVCCCurr.x4, g_tCalib.TVCCCurr.y4);
				FormCalib->Memo1->Lines->Add(s1);

				FormCalib->Memo1->Lines->Add("");
				s1.sprintf("TVCCSet   = %12.3f,%12.3f,%12.3f,%12.3f", g_tCalib.TVCCSet.x1, g_tCalib.TVCCSet.y1,
							g_tCalib.TVCCSet.x2, g_tCalib.TVCCSet.y2);
				FormCalib->Memo1->Lines->Add(s1);

				FormCalib->Memo1->Lines->Add("");
				s1.sprintf("Dac10V  = %6d,%6d,%6d,%6d,",
							g_tCalib.Dac10V.x1, g_tCalib.Dac10V.y1,
							g_tCalib.Dac10V.x2, g_tCalib.Dac10V.y2
							);
				s2.sprintf("%6d,%6d,%6d,%6d",
							g_tCalib.Dac10V.x3, g_tCalib.Dac10V.y3,
							g_tCalib.Dac10V.x4, g_tCalib.Dac10V.y4
							);
				FormCalib->Memo1->Lines->Add(s1 + s2);

				s1.sprintf("Dac20mA = %6d,%6d,%6d,%6d,",
							g_tCalib.Dac20mA.x1, g_tCalib.Dac20mA.y1,
							g_tCalib.Dac20mA.x2, g_tCalib.Dac20mA.y2
							);
				s2.sprintf("%6d,%6d,%6d,%6d",
							g_tCalib.Dac20mA.x3, g_tCalib.Dac20mA.y3,
							g_tCalib.Dac20mA.x4, g_tCalib.Dac20mA.y4
							);
				FormCalib->Memo1->Lines->Add(s1 + s2);
				FormCalib->Memo1->Lines->Add("");

				s1.sprintf("NtcRes    = %12.3f,%12.3f,%12.3f,%12.3f", g_tCalib.NtcRes.x1, g_tCalib.NtcRes.y1,
							g_tCalib.NtcRes.x2, g_tCalib.NtcRes.y2);
				FormCalib->Memo1->Lines->Add(s1);
				s1.sprintf("            %12.3f,%12.3f,%12.3f,%12.3f", g_tCalib.NtcRes.x3, g_tCalib.NtcRes.y3,
							g_tCalib.NtcRes.x4, g_tCalib.NtcRes.y4);
				FormCalib->Memo1->Lines->Add(s1);

				FormCalib->Memo1->Lines->Add("");
			}
			break;

		case REG03_BOOT_STATUS:
			p = &_rx_buf[3];
			mBootStatus = BEBufToUint16(p);
			break;

		case REG03_APP_VER:
			p = &_rx_buf[3];
			{
				uint16_t ver;
				char buf[32];

				ver = BEBufToUint16(p);
				sprintf(buf, "V%X.%02X", ver >> 8, ver & 0xFF);
				Form1->MemoLuaOut->Lines->Add("当前APP版本 : " + (AnsiString)buf);
				if (ver < FW_APP_VER)
				{
					Form1->MemoLuaOut->Lines->Add("APP固件需要更新");
				}
				else
				{
					Form1->MemoLuaOut->Lines->Add("APP固件已是最新，无需更新");
				}
			}
			break;

		case REG03_BOOT_VER:
			p = &_rx_buf[3];
			{
				uint16_t ver;
				char buf[32];

				ver = BEBufToUint16(p);
				sprintf(buf, "V%X.%02X", ver >> 8, ver & 0xFF);
				Form1->MemoLuaOut->Lines->Add("当前BOOT版本 : " + (AnsiString)buf);
				if (ver < FW_BOOT_VER)
				{
					Form1->MemoLuaOut->Lines->Add("BOOT固件需要更新");
				}
				else
				{
					Form1->MemoLuaOut->Lines->Add("BOOT固件已是最新，无需更新");
				}
			}
			break;

		default:
			if (g_tCmd.RegAddr >= REG03_CH1_WAVE_0 && g_tCmd.RegAddr < REG03_CH1_WAVE_0 + 512)
			{
				int i;
				int idx;
				int bytes;

				bytes = _rx_buf[2];
				p = &_rx_buf[3];
				// 搜索设备时，马上切换到读波形状态，此时有可能网络应答搜索包，导致浮点异常
				if (bytes == (DSO_PACKAGE_SIZE % 256))
				{
					idx = (g_tCmd.RegAddr - REG03_CH1_WAVE_0) * (DSO_PACKAGE_SIZE / 4);

					for (i = 0; i < g_tCmd.RegNum / 2; i++)
					{
						mAdcBuf1[idx + i] = BEBufToFloat(p);
						p += 4;
					}
				}
			}
			if (g_tCmd.RegAddr >= REG03_CH2_WAVE_0 && g_tCmd.RegAddr < REG03_CH2_WAVE_0 + 512)
			{
				int i;
				int idx;
				int bytes;

				bytes = _rx_buf[2];
                p = &_rx_buf[3];
				if (bytes == (DSO_PACKAGE_SIZE  % 256))
				{
					idx = (g_tCmd.RegAddr - REG03_CH2_WAVE_0) * (DSO_PACKAGE_SIZE / 4);

					for (i = 0; i < g_tCmd.RegNum / 2; i++)
					{
						mAdcBuf2[idx + i] = BEBufToFloat(p);
						p += 4;
					}
				}
			}
			break;
	}
}

extern char s_udp_print_RxBuf[UDP_PRINT_BUFFSIZE];
extern uint32_t  s_udp_print_RxLen;
extern void DispUdpPringData(void);
void __fastcall TFormTcp::MODH_61H(uint8_t *_rx_buf, uint16_t _len)
{
	/*
		H7-TOOL主动发送:    PC无需应答
			01  ; 从机地址 ，为1
			61  ; 功能码
			00  ; 通道号，00表示print
			01  : 长度高字节
			08  : 长度低字节
			xx xx xx xx ... : 数据体
			CC CC : CRC16
	*/
	/*
		H7-TOOL主动发送:
			01  ; 从机地址 ，为1
			61  ; 功能码
			00  ; 通道号，00表示print
			01  : 长度高字节
			08  : 长度低字节
			xx xx xx xx ... : 数据体
			CC CC : CRC16
	*/
	uint8_t func;
	uint8_t ch;
	uint16_t len;
	uint16_t pos;

	pos = 1;
	func = _rx_buf[pos++];
	ch = _rx_buf[pos++];
	len = _rx_buf[pos] * 256 + _rx_buf[pos + 1];
	pos += 2;

	for (int i = 0; i < len; i++)
	{
		if (s_udp_print_RxLen < UDP_PRINT_BUFFSIZE)
		{
			s_udp_print_RxBuf[s_udp_print_RxLen++] = _rx_buf[pos++];
		}
	}

	DispUdpPringData();
}

void __fastcall TFormTcp::MODH_66H(uint8_t *_rx_buf, uint16_t _len)
{
    /*
        主机发送: 小程序数据
            01  ; 站号
            66  ; 功能码
            0000  ; 子功能,
                - 0表示读内存
                - 1表示写内存
            0000 0000 : 偏移地址 4字节
            0020 0000 : 数据长度 4字节
            CCCC      : CRC16

		从机应答:
            01  ; 从机地址
            66  ; 功能码
            0000  ; 子功能
			0000 0000 : 偏移地址 4字节
			0020 0000 : 数据长度 4字节
            00  ; 执行结果，0表示OK  1表示错误

            CCCC : CRC16
	*/
	int pos = 0;
	char *p;
	uint16_t func;
	uint32_t offset;
	uint32_t len;
	uint8_t ack;
	uint32_t i;

	p = &_rx_buf[2];
	func = BEBufToUint16(p); p += 2;
	offset = BEBufToUint32(p); p += 4;
	len = BEBufToUint32(p); p += 4;
	ack = p[0]; p++;

	offset = offset - mLua.FlashBaseAddr;

	if (offset + len > sizeof(mLua.DataBuf))
	{
		return;
	}

	if (func == H66_READ_MEM_INIT || func == H66_READ_MEM
		|| func == H66_READ_DISP_MEM)  /* 读flash */
	{
		if (ack == 0)
		{
			for (i = 0; i < len; i++)
			{
				mLua.DataBuf[offset + i] = *p;
				p++;
			}
		}
	}
	else
	{
		return;
	}
}

void __fastcall TFormTcp::MODH_06H(uint8_t *_rx_buf, uint16_t _len)
{
	uint16_t reg;
	uint16_t value;

	reg = BEBufToUint16(&_rx_buf[2]);
	value = BEBufToUint16(&_rx_buf[4]);
	if (reg >= REG03_CALIB_KEY && reg <= REG03_CALIB_PARAM_END)
	{
		AnsiString s;

		s.sprintf("写入成功. 06H指令, 寄存器0x%04X = 0x%04X", reg, value);

		if (FormCalib->Visible == false)
		{
			Form1->MemoAdd(s);
		}
		else
		{
			FormCalib->Memo1->Lines->Add(s);
		}
	}
}

void __fastcall TFormTcp::MODH_10H(uint8_t *_rx_buf, uint16_t _len)
{
	uint16_t reg;

	reg = BEBufToUint16(&_rx_buf[2]);
	if (reg >= REG03_CALIB_KEY && reg <= REG03_CALIB_PARAM_END)
	{
		AnsiString s;

		s.sprintf("写入成功. 10H指令, 寄存器0x%04X", reg);
		FormCalib->Memo1->Lines->Add(s);
	}
	else if (reg == REG03_NET_LOCAL_IP_H)
	{
        Form1->MemoLuaOut->Lines->Add("修改IP参数成功");
	}
}

void __fastcall TFormTcp::Thread1Run(TIdThreadComponent *Sender)
{
	FormTcp->CommTask();
}
//---------------------------------------------------------------------------

void __fastcall TFormTcp::FormDestroy(TObject *Sender)
{
	Thread1->Terminate();
}

// DoLua ， 不初始化lua
void __fastcall TFormTcp::DoLuaSend64H(AnsiString s)
{
	int i;
	FormTcp->mLua.Func = H64_LUA_RUN_NO_RESET;
	FormTcp->mLua.Offset = 0;

	for (i = 0; i < s.Length(); i++)
	{
		FormTcp->mLua.DataBuf[i] = s.c_str()[i];
	}
	FormTcp->mLua.DataBuf[i] = 0;
	FormTcp->mLua.DataLen = i + 1;

	g_tCmd.UserCmdStatus = CMDS_DOWNLOAD_LUA;
	g_tCmd.UserReq = 1;
}

// DoLua ， 初始化lua
void __fastcall TFormTcp::InitAndDoLuaSend64H(AnsiString s)
{
	int i;
	FormTcp->mLua.Func = H64_LUA_RUN_WITH_RESET;
	FormTcp->mLua.Offset = 0;

	for (i = 0; i < s.Length(); i++)
	{
		FormTcp->mLua.DataBuf[i] = s.c_str()[i];
	}
	FormTcp->mLua.DataBuf[i] = 0;
	FormTcp->mLua.DataLen = i + 1;

	g_tCmd.UserCmdStatus = CMDS_DOWNLOAD_LUA;
	g_tCmd.UserReq = 1;
}

//---------------------------------------------------------------------------

// 通信线程
void __fastcall TFormTcp::CommTask(void)
{
	UnicodeString PeerIP;   	// 对方的IP
	unsigned short PeerPort;	// 对方的端口

	AnsiString s;
	int read_len = 0;
	AnsiString id;

	static uint32_t s_rx_pos = 0;
	static uint32_t s_run_time = 0;

	if (FormSet == NULL || Form1 == NULL || FormLua == NULL
		|| FormCalib == NULL || FormProg == NULL)
	{
		return;
	}

	try
	{
		if (g_tIniParam.CommInterface == 1)     /* 通信接口为USB虚拟串口 */
		{
			// 发送到UDP服务端
			if (Form1->YbCommDevice1->Active == true)
			{
				read_len = Form1->YbCommDevice1->Read((uint8_t *)&g_buf[0], 2048); //收 1 个字节

				// 请求关闭串口
				if (FormTcp->mReqCloseCom == 1)
				{
					FormTcp->mReqCloseCom = 0;
					Form1->YbCommDevice1->Active = false;
				}


				if (read_len > 0)
				{
					Form1->TimerPowerOn->Tag = 0;  // 用于USB掉线监视
				}

				if (read_len > 0 && read_len < DYN_ARRAY_SIZE)
				{
					for (int i = 0; i < read_len; i++)
					{
						if (s_RxLen < DYN_ARRAY_SIZE)
						{
							s_RxBuf[s_RxLen++] = g_buf[i];
						}
					}

					Thread1->Synchronize(DealRxData); 	// 线程同步，解析结果并显示
				}
			}
			else
			{
				Sleep(100);
				return;
			}
		}
		else       /* 通信接口为网口和WIFI  */
		{
			// 读取UDP数据包 - 主要通信接口
			read_len = FormTcp->UDP1->ReceiveBuffer(g_buf, PeerIP, PeerPort, 0);
			if (read_len > 0 && read_len < DYN_ARRAY_SIZE)
			{

				for (int i = 0; i < read_len; i++)
				{
					if (s_RxLen < DYN_ARRAY_SIZE)
					{
						s_RxBuf[s_RxLen++] = g_buf[i];
					}
				}

				Thread1->Synchronize(DealRxData); 	// 线程同步，解析结果并显示
			}

		}
	}
	catch (Exception &e)
	{
		Form1->MemoLuaOut->Lines->Add("读取数据异常");
	}

	try
	{
		UserCmd();   /* 用户临时任务 */

		if (g_tCmd.CmdStatus > 0)
		{

		}
		else
		{
			Sleep(2);
		}
	}
	catch (Exception &e)
	{
		Form1->MemoLuaOut->Lines->Add("执行UserCmd异常");
		g_tCmd.CmdStatus = 0;
		g_tCmd.UserReq = 0;
	}
}
