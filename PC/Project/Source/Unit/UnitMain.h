//---------------------------------------------------------------------------

#ifndef UnitMainH
#define UnitMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include "YbCommDevice.h"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <VCLTee.Chart.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <VCLTee.Series.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <Vcl.Menus.hpp>
#include <IdCmdTCPClient.hpp>
#include <IdThreadComponent.hpp>
#include <IdAntiFreezeBase.hpp>
#include <Vcl.IdAntiFreeze.hpp>
#include "trayicon.h"
#include <Vcl.ImgList.hpp>
#include <IdUDPBase.hpp>
#include <IdUDPClient.hpp>

#include "udp_modbus_addr.h"
#include <Vcl.DockTabSet.hpp>
#include <Vcl.Tabs.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.Buttons.hpp>
#include <IdGlobal.hpp>
#include <IdSocketHandle.hpp>
#include <IdUDPServer.hpp>
#include <IdHTTP.hpp>

// PC软件版本号定义
		#define PC_SOFT_VER1 	1
		#define PC_SOFT_VER2 	4
		#define PC_SOFT_VER3 	4

		#define PC_SOFT_DATE	"2021-01-24"

		#define FW_APP_VER		0x0147
		#define FW_BOOT_VER		0x0103

#define MAX_NUM		200

// 界面设置的采样深度，字节单位
#define SAMPLE_BUFF_SIZE	TabelBufSize[Form1->ComboBoxSampleSize->ItemIndex]
#define SAMPLE_FREQ	 	TabelFreq[Form1->ComboBoxFreq->ItemIndex]

// LUA UDP print 接收缓冲区.
#define UDP_PRINT_BUFFSIZE	4096

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TTimer *TimerTCP;
	TTimer *TimerPowerOn;
	TMainMenu *MainMenu1;
	TMenuItem *N8;
	TImageList *ImageList1;
	TPanel *PanelLua;
	TOpenDialog *OpenDialog1;
	TYbCommDevice *YbCommDevice1;
	TTimer *TimerUpgrade;
	TMenuItem *N9;
	TMenuItem *N10;
	TIdUDPServer *IdUDPServer1;
	TPanel *Panel8;
	TButton *Button86;
	TButton *Button108;
	TButton *Button109;
	TPanel *PanelDSO;
	TPanel *Panel3;
	TLabel *Label18;
	TLabel *Label20;
	TLabel *Label21;
	TLabel *Label33;
	TLabel *Label32;
	TLabel *LabelCH1_Adc;
	TLabel *LabelCH1_Volt;
	TLabel *LabelCH2_Volt;
	TLabel *LabelCH2_Adc;
	TLabel *LabelLoad_Volt;
	TLabel *LabelLoad_Volt_Adc;
	TLabel *LabelLoad_Curr;
	TLabel *LabelLoad_Curr_Adc;
	TLabel *LabelTVCC_Volt;
	TLabel *LabelTVCC_Volt_Adc;
	TLabel *LabelTVCC_Curr;
	TLabel *LabelTVCC_Curr_Adc;
	TLabel *Label50;
	TLabel *LabelNTC_Res;
	TLabel *LabelNTC_Adc;
	TLabel *LabelNTC_Temp;
	TLabel *Label53;
	TPanel *Panel2;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *LabelMin1;
	TLabel *LabelMax1;
	TLabel *LabelCH1Now;
	TLabel *LabelMin2;
	TLabel *LabelMax2;
	TLabel *LabelCH2Now;
	TLabel *Label49;
	TLabel *LabelT2;
	TLabel *LabelT2T1Freq;
	TLabel *LabelT2T1Diff;
	TLabel *Label57;
	TLabel *LabelDiff1;
	TLabel *LabelDiff2;
	TLabel *Label51;
	TLabel *Label52;
	TLabel *LabelCh1Diff;
	TLabel *LabelCh2Diff;
	TLabel *LabelT1;
	TLabel *Label56;
	TLabel *Label58;
	TLabel *LabelT1Now;
	TLabel *LabelT2Now;
	TChart *Chart1;
	TButton *Button7;
	TButton *Button34;
	TLineSeries *Series1;
	TLineSeries *Series2;
	TPointSeries *Series3;
	TLineSeries *Series4;
	TLineSeries *Series5;
	TLineSeries *Series6;
	TScrollBar *CH1_Offset;
	TScrollBar *CH2_Offset;
	TLabel *Label28;
	TLabel *Label27;
	TButton *Button20;
	TButton *Button6;
	TButton *Button5;
	TButton *Button31;
	TButton *Button30;
	TCheckBox *CheckBoxAutoReadWave;
	TPanel *Panel7;
	TPageControl *PageControl2;
	TTabSheet *TabSheet4;
	TLabel *LabelDacOff;
	TLabel *LabelDacVpp;
	TLabel *LabelDacState;
	TLabel *Label36;
	TLabel *Label37;
	TLabel *Label38;
	TLabel *Label39;
	TButton *ButtonSqrStart;
	TButton *ButtonSqrStop;
	TComboBox *ComboBoxDacVpp;
	TComboBox *ComboBoxDacOffset;
	TComboBox *ComboBoxSqrFreq;
	TComboBox *ComboBoxSqrCount;
	TComboBox *ComboBoxWaveType;
	TComboBox *ComboBoxDuty;
	TTabSheet *TabSheetDC;
	TButton *Button4;
	TButton *Button21;
	TButton *Button42;
	TButton *Button43;
	TButton *Button44;
	TButton *Button45;
	TButton *Button46;
	TButton *Button47;
	TButton *Button48;
	TButton *ButtonDCKey;
	TButton *Button49;
	TButton *Button50;
	TProgressBar *ProgressBarVolt;
	TButton *Button51;
	TButton *Button52;
	TButton *Button53;
	TButton *Button54;
	TButton *Button55;
	TButton *ButtonDacVolt;
	TButton *Button58;
	TButton *Button59;
	TButton *Button60;
	TButton *Button61;
	TButton *Button62;
	TEdit *EditDacInput;
	TButton *ButtonDACOut;
	TButton *Button15;
	TButton *Button16;
	TButton *Button17;
	TButton *Button18;
	TButton *Button19;
	TButton *Button68;
	TButton *Button69;
	TButton *Button70;
	TTabSheet *TabSheet5;
	TButton *Button14;
	TButton *Button57;
	TButton *Button71;
	TButton *Button72;
	TButton *Button73;
	TButton *Button74;
	TButton *Button75;
	TButton *Button76;
	TButton *Button77;
	TButton *Button78;
	TButton *Button79;
	TButton *Button80;
	TButton *Button81;
	TButton *Button82;
	TButton *Button83;
	TButton *Button84;
	TButton *Button85;
	TButton *ButtonDacCurr;
	TButton *Button87;
	TButton *Button88;
	TButton *Button89;
	TButton *Button90;
	TButton *Button91;
	TEdit *EditDacCurr;
	TButton *ButtonDacCurrOut;
	TButton *Button93;
	TButton *Button94;
	TButton *Button95;
	TButton *Button96;
	TButton *Button97;
	TButton *Button98;
	TButton *Button99;
	TButton *Button100;
	TPanel *Panel6;
	TLabel *Label24;
	TLabel *Label25;
	TLabel *Label31;
	TComboBox *ComboBoxDSO_Mode;
	TComboBox *ComboBoxCurrGain;
	TComboBox *ComboBoxTVCC;
	TPanel *Panel4;
	TShape *ShapeX7;
	TShape *ShapeX6;
	TShape *ShapeX5;
	TShape *ShapeX4;
	TShape *ShapeX3;
	TShape *ShapeX2;
	TShape *ShapeX1;
	TShape *ShapeX0;
	TLabel *Label34;
	TLabel *Label35;
	TLabel *Label40;
	TLabel *Label41;
	TLabel *Label42;
	TLabel *Label43;
	TLabel *Label44;
	TLabel *Label45;
	TSpeedButton *SpeedButtonY7;
	TSpeedButton *SpeedButtonY6;
	TSpeedButton *SpeedButtonY5;
	TSpeedButton *SpeedButtonY4;
	TSpeedButton *SpeedButtonY3;
	TSpeedButton *SpeedButtonY2;
	TSpeedButton *SpeedButtonY1;
	TSpeedButton *SpeedButtonY0;
	TShape *ShapeY7;
	TShape *ShapeY6;
	TShape *ShapeY5;
	TShape *ShapeY4;
	TShape *ShapeY3;
	TShape *ShapeY2;
	TShape *ShapeY1;
	TShape *ShapeY0;
	TShape *ShapeX9;
	TShape *ShapeX8;
	TLabel *Label46;
	TLabel *Label47;
	TSpeedButton *SpeedButtonY9;
	TSpeedButton *SpeedButtonY8;
	TShape *ShapeY9;
	TShape *ShapeY8;
	TLabel *Label59;
	TLabel *Label79;
	TLabel *Label80;
	TLabel *Label81;
	TLabel *Label82;
	TCheckBox *CheckBoxD7;
	TCheckBox *CheckBoxD6;
	TCheckBox *CheckBoxD5;
	TCheckBox *CheckBoxD4;
	TCheckBox *CheckBoxD3;
	TCheckBox *CheckBoxD2;
	TCheckBox *CheckBoxD1;
	TCheckBox *CheckBoxD0;
	TCheckBox *CheckBoxD9;
	TCheckBox *CheckBoxD8;
	TLabel *Label3;
	TLabel *Label17;
	TLabel *Label19;
	TLabel *Label22;
	TLabel *Label23;
	TLabel *LabelTrigLevel;
	TLabel *Label29;
	TLabel *LabelTrigPos;
	TLabel *Label30;
	TComboBox *ComboBoxFreq;
	TComboBox *ComboBoxSampleSize;
	TButton *Button22;
	TButton *Button23;
	TButton *Button24;
	TButton *Button29;
	TButton *ButtonStartDSO;
	TButton *ButtonStopDSO;
	TComboBox *ComboBoxTrigChan;
	TComboBox *ComboBoxTrigMode;
	TScrollBar *ScrollBarTrigLevel;
	TCheckBox *CheckBoxEnCH1;
	TCheckBox *CheckBoxEnCH2;
	TScrollBar *ScrollBarTrigPos;
	TComboBox *ComboBoxTrigEdge;
	TRadioGroup *Radio_CH1Gain;
	TRadioGroup *Radio_CH2Gain;
	TPanel *PanelMemo;
	TButton *Button27;
	TCheckBox *CheckBoxUDP777;
	TCheckBox *CheckBoxLuaWordWrap;
	TMemo *MemoLuaOut;
	TButton *Button64;
	TPanel *PanelStation;
	TSplitter *Splitter3;
	TCheckBox *CheckBoxClear;
	TButton *Button9;
	TButton *Button1;
	TButton *Button2;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TPanel *PanelBottom;
	TLabel *LabelUSBName;
	TLabel *LabelVer;
	TLabel *LabelLedUSB;
	TLabel *LabelLedRJ45;
	TLabel *LabelRJ45Name;
	TButton *Button3;
	TButton *Button8;
	TMenuItem *N2;
	TProgressBar *ProgressBar1;
	TCheckBox *CheckBoxMonitorUSB;
	TLabel *LabelCheckVer;
	TButton *ButtonCheckHttp;
	TIdHTTP *IdHTTP1;
	TButton *ButtonGotoDownload;
	TTimer *Timer1;
	TButton *Button10;
	TMenuItem *N1;
	TMenuItem *N3;

	//void __fastcall Timer2Timer(TObject *Sender);

	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	char __fastcall AsciiToHex(char cHex);
	int __fastcall AnsiStrToChars(AnsiString strHex, char * pChar);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall ButtonStartDSOClick(TObject *Sender);
	void __fastcall Button20Click(TObject *Sender);
	void __fastcall TimerTCPTimer(TObject *Sender);
	void __fastcall Thread1Run(TIdThreadComponent *Sender);
	void __fastcall Button22Click(TObject *Sender);
	void __fastcall Button23Click(TObject *Sender);
	void __fastcall Button29Click(TObject *Sender);
	void __fastcall Button24Click(TObject *Sender);
	void __fastcall ScrollBarTrigLevelChange(TObject *Sender);
	void __fastcall ComboBoxFreqClick(TObject *Sender);
	void __fastcall ComboBoxDSO_ModeChange(TObject *Sender);
	void __fastcall ComboBoxCurrGainChange(TObject *Sender);
	void __fastcall Button30Click(TObject *Sender);
	void __fastcall Button31Click(TObject *Sender);
	void __fastcall CH1_OffsetChange(TObject *Sender);
	void __fastcall CH2_OffsetChange(TObject *Sender);
	void __fastcall ComboBoxSampleSizeChange(TObject *Sender);
	void __fastcall ScrollBarTrigPosChange(TObject *Sender);
	void __fastcall RadioButtonVoltClick(TObject *Sender);
	void __fastcall RadioButtonCurrClick(TObject *Sender);
	void __fastcall ButtonSqrStartClick(TObject *Sender);
	void __fastcall ButtonSqrStopClick(TObject *Sender);
	void __fastcall ComboBoxWaveTypeChange(TObject *Sender);
	void __fastcall TimerDacTempTimer(TObject *Sender);
	void __fastcall ComboBoxTrigChanChange(TObject *Sender);
	void __fastcall ComboBoxTrigModeChange(TObject *Sender);
	void __fastcall ComboBoxTrigEdgeChange(TObject *Sender);
	void __fastcall ComboBoxTVCCSelect(TObject *Sender);
	void __fastcall ButtonDacVoltClick(TObject *Sender);
	void __fastcall ButtonDACOutClick(TObject *Sender);
	void __fastcall ButtonDacCurrOutClick(TObject *Sender);
	void __fastcall ButtonDacCurrClick(TObject *Sender);
	void __fastcall CheckBoxD7Click(TObject *Sender);
	void __fastcall CheckBoxD6Click(TObject *Sender);
	void __fastcall CheckBoxD5Click(TObject *Sender);
	void __fastcall CheckBoxD4Click(TObject *Sender);
	void __fastcall CheckBoxD3Click(TObject *Sender);
	void __fastcall CheckBoxD2Click(TObject *Sender);
	void __fastcall CheckBoxD1Click(TObject *Sender);
	void __fastcall CheckBoxD0Click(TObject *Sender);
	void __fastcall ShapeY7MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall SpeedButtonY7Click(TObject *Sender);
	void __fastcall CheckBoxD9Click(TObject *Sender);
	void __fastcall CheckBoxD8Click(TObject *Sender);
	void __fastcall TimerUpgradeTimer(TObject *Sender);
	void __fastcall Button107Click(TObject *Sender);
	void __fastcall ButtonStopDSOClick(TObject *Sender);
	void __fastcall Chart1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Chart1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall LabelT1Click(TObject *Sender);
	void __fastcall LabelT2Click(TObject *Sender);
	void __fastcall LabelY1Click(TObject *Sender);
	void __fastcall LabelY2Click(TObject *Sender);
	void __fastcall TimerPowerOnTimer(TObject *Sender);
	void __fastcall YbCommDevice1Package(TObject *Sender, int NotifyType);
	void __fastcall Radio_CH1GainClick(TObject *Sender);
	void __fastcall Radio_CH2GainClick(TObject *Sender);
	void __fastcall Button27Click(TObject *Sender);
	void __fastcall IdUDPServer1UDPRead(TIdUDPListenerThread *AThread, const TIdBytes AData,
          TIdSocketHandle *ABinding);
	void __fastcall CheckBoxUDP777Click(TObject *Sender);
	void __fastcall N9Click(TObject *Sender);
	void __fastcall N10Click(TObject *Sender);
	void __fastcall CheckBoxLuaWordWrapClick(TObject *Sender);
	void __fastcall Button64Click(TObject *Sender);
	void __fastcall MemoLuaOutClick(TObject *Sender);
	void __fastcall Button86Click(TObject *Sender);
	void __fastcall Button108Click(TObject *Sender);
	void __fastcall PanelStationResize(TObject *Sender);
	void __fastcall Button109Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall LabelLedUSBClick(TObject *Sender);
	void __fastcall LabelLedRJ45Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall CheckBoxMonitorUSBClick(TObject *Sender);
	void __fastcall LabelLedUSBMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall ButtonCheckHttpClick(TObject *Sender);
	void __fastcall ButtonGotoDownloadClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);








private:	// User declarations
	void __fastcall ScanFinger(TObject *Sender);
	void __fastcall DispFingerErr(uint8_t err);
	void __fastcall SaveFingerFile(void);


public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	void __fastcall SendTcpCmd(uint32_t ip, uint32_t tcp_port);
	void __fastcall SendUdpCmd(uint32_t ip, uint32_t port, uint8_t * cmd_buf, uint16_t cmd_len);
	void __fastcall SendUdpCmd2(AnsiString str_ip, uint32_t port, uint8_t * cmd_buf, uint16_t cmd_len);
	int __fastcall TForm1::AutoRunCheck(bool value);
	void __fastcall TForm1::AddWaveData(void);

	void __fastcall TForm1::ParseUR001(TByteDynArray RxBuf);
	void __fastcall TForm1::Memo_AddLine(uint8_t* buf, int len);
	void __fastcall TForm1::DrawWave1(void);
	void __fastcall TForm1::DrawWave2(void);
	void __fastcall TForm1::DacRefreshList(int mode);
	void __fastcall TForm1::DacStartOutput(void);
	void __fastcall TForm1::DacStopOutput(void);

	void __fastcall TForm1::DownloadLuaFile(String FileName);
	void __fastcall TForm1::ChangeFace(String name);
	void __fastcall TForm1::MemoAdd(AnsiString str);
	void __fastcall TForm1::EnumCom(void);


	int mStatus;		// 录入指纹的状态机
	int mUserCmdFlag;      // 1表示用户指令
	int mUserCmd;          // 表示将要发送的指令
	int mUserAddr;         // 表示临时发送的寄存器地址
	int mUserNum;         // 表示临时发送的寄存器个数
	int mUserValue;         // 表示临时发送的寄存器值
	uint8_t mCmd;
	uint16_t mRegAddr;
   //	uint16_t mRegAddr1;
   //	uint16_t mRegAddr2;
   //	uint16_t mRegAddr3;
   //	uint16_t mRegAddr4;
   //	uint16_t mRegAddr5;
	uint16_t mRegNum;
	uint16_t mRegValue;
   //	TByteArray mTxBuf[256];
	uint8_t mTxBuf[256];

	//int mWaveTime;
  //	int mScaning;

	uint32_t mIP_List[1000]; /*　IP列表 */
	int mIP_Counter;     // IP个数

	//int mScanStatus;
	int mScanAddr;

	int mTCPTimeout;

	uint32_t mTime1;

	double mArrayX[256 * 1024];
	double mArrayY[256 * 1024];

	uint16_t mWaveReg;
	uint32_t mLastTime;

	float mWaveHigh;
	float mWaveMid;

	uint8_t mLuaText[64 * 1024];
	int mLuaLen;

   	/* 用于程序下载 */
	char mFileBuf[2*1024*1024];  		/* 文件内容缓冲区 */
	int mFileLength;                   	/* 文件长度 */
	char mbakFileBuf[2*1024*1024];  	/* 2016-07-30 xd 备份上次打开的文件内容 */
	int mbakFileLength;                 /* 备份上次打开的文件长度 */
	uint8_t mFlagBuf[11];

	String mActiveFace;		/* 激活的界面，用于将form窗口定位到主界面 */

	int mLinkStatus;	/* 联机状态 */

	String mHttpLink;
};

/* 光标测量相关 */
typedef struct
{
	float Ch1Y1;
	float Ch1Y2;
	float Ch2Y1;
	float Ch2Y2;
	float T1;
	float T2;
	int State;
}DS0_CURSOR_MEAS_T;
//enum
//{
//	CMDS_READ_WAVE = 100,
//
//	CMDS_SCAN_DEV = 200,
//};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
