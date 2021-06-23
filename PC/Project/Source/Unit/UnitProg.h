//---------------------------------------------------------------------------

#ifndef UnitProgH
#define UnitProgH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ValEdit.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.FileCtrl.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Buttons.hpp>

typedef struct
{
	TStrings *FileName;
	TStrings *FilePath;
	TStrings *FileType;
}FILE_LIST_T;

//---------------------------------------------------------------------------
class TFormProg : public TForm
{
__published:	// IDE-managed Components
	TPanel *PanelProg;
	TLabel *Label11;
	TButton *Button5;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TButton *ButtonSelectFold;
	TMemo *MemoOutputDir;
	TEdit *EditOutFileName;
	TLabel *Label12;
	TButton *Button6;
	TLabel *Label4;
	TComboBox *ComboBoxTempDataFile;
	TButton *Button7;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TComboBox *ComboBoxDevice;
	TLabel *Label3;
	TComboBox *ComboBoxSerial;
	TLabel *LabelSerial;
	TComboBox *ComboBoxManufacturer;
	TLabel *Label1;
	TLabel *LabelDeviceLuaFileName;
	TLabel *LabelDeviceType;
	TGroupBox *GroupBox3;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TComboBox *ComboBoxVerifyMode;
	TCheckBox *CheckBoxRemoveProtect;
	TCheckBox *CheckBoxAtfterAuotReset;
	TEdit *EditTVCC;
	TGroupBox *GroupBox4;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label23;
	TLabel *Label22;
	TLabel *Label28;
	TComboBox *ComboBoxSNEndain;
	TEdit *EditSNInitValue;
	TEdit *EditSNAddr;
	TComboBox *ComboBoxSNType;
	TComboBox *ComboBoxSNLen;
	TGroupBox *GroupBox5;
	TLabel *Label20;
	TLabel *Label19;
	TLabel *Label21;
	TLabel *Label24;
	TEdit *EditConstAddr_1;
	TEdit *EditConstValue_1;
	TEdit *EditConstAddr_2;
	TEdit *EditConstValue_2;
	TEdit *EditConstAddr_3;
	TEdit *EditConstValue_3;
	TEdit *EditConstAddr_4;
	TEdit *EditConstValue_4;
	TGroupBox *GroupBox6;
	TLabel *Label27;
	TLabel *Label25;
	TEdit *EditDateAddr;
	TComboBox *ComboBoxDateType;
	TGroupBox *GroupBox7;
	TComboBox *ComboBoxAlgoLua;
	TLabel *Label36;
	TValueListEditor *ValueListEditorA;
	TGroupBox *GroupBox8;
	TEdit *EditAlgoRndAddr1;
	TComboBox *ComboBoxRndLen1;
	TLabel *Label32;
	TGroupBox *GroupBox9;
	TLabel *Label31;
	TEdit *EditAlgoRndAddr2;
	TComboBox *ComboBoxRndLen2;
	TEdit *EditAlgoRndAddr3;
	TComboBox *ComboBoxRndLen3;
	TLabel *Label43;
	TEdit *EditAlgoRndAddr4;
	TComboBox *ComboBoxRndLen4;
	TLabel *Label33;
	TComboBox *ComboBoxEncryptResultLen;
	TTimer *Timer1;
	TLabel *Label46;
	TEdit *EditEncryptSaveAddr;
	TTabSheet *TabSheet5;
	TGroupBox *GroupBox11;
	TLabel *Label50;
	TCheckBox *CheckBoxDeadline;
	TGroupBox *GroupBox12;
	TLabel *Label52;
	TCheckBox *CheckBoxCheckUid;
	TGroupBox *GroupBox13;
	TEdit *EditEncryptConst;
	TLabel *Label34;
	TComboBox *ComboBoxInitValue;
	TLabel *Label30;
	TEdit *EditToolFactoryAddr;
	TLabel *Label26;
	TLabel *Label41;
	TEdit *EditToolSnAddr;
	TLabel *Label48;
	TEdit *EditToolChannelAddr;
	TEdit *EditDeadlineDate;
	TLabel *Label49;
	TMemo *MemoUID;
	TLabel *Label51;
	TLabel *Label53;
	TLabel *Label54;
	TLabel *Label10;
	TEdit *EditNote1;
	TTabSheet *TabSheet6;
	TGroupBox *GroupBox16;
	TEdit *EditProgrammedLimit;
	TLabel *Label16;
	TGroupBox *GroupBox15;
	TEdit *EditOBAddr;
	TEdit *EditSecureOff;
	TEdit *EditSecureOn;
	TButton *ButtonOBhelp;
	TLabel *Label57;
	TLabel *Label58;
	TLabel *Label59;
	TComboBox *ComboBoxOB;
	TLabel *Label60;
	TOpenDialog *OpenDialog2;
	TPageControl *PageControl2;
	TTabSheet *TabSheet8;
	TTabSheet *TabSheet9;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TEdit *EditDataFile1;
	TCheckBox *CheckBoxDataEnable1;
	TCheckBox *CheckBoxDataEnable2;
	TEdit *EditDataFile2;
	TCheckBox *CheckBoxDataEnable3;
	TEdit *EditDataFile3;
	TButton *ButtonFile1;
	TButton *ButtonFile2;
	TEdit *EditDataAddress1;
	TEdit *EditDataAddress2;
	TEdit *EditDataAddress3;
	TComboBox *ComboBoxDataAlgo1;
	TComboBox *ComboBoxDataAlgo2;
	TComboBox *ComboBoxDataAlgo3;
	TButton *ButtonFile3;
	TCheckBox *CheckBoxDataEnable4;
	TEdit *EditDataFile4;
	TCheckBox *CheckBoxDataEnable5;
	TEdit *EditDataFile5;
	TButton *ButtonFile4;
	TEdit *EditDataAddress4;
	TEdit *EditDataAddress5;
	TComboBox *ComboBoxDataAlgo4;
	TComboBox *ComboBoxDataAlgo5;
	TButton *ButtonFile5;
	TLabel *Label65;
	TLabel *Label66;
	TLabel *Label67;
	TLabel *Label68;
	TEdit *EditDataFile6;
	TCheckBox *CheckBoxDataEnable6;
	TCheckBox *CheckBoxDataEnable7;
	TEdit *EditDataFile7;
	TCheckBox *CheckBoxDataEnable8;
	TEdit *EditDataFile8;
	TButton *ButtonFile6;
	TButton *ButtonFile7;
	TEdit *EditDataAddress6;
	TEdit *EditDataAddress7;
	TEdit *EditDataAddress8;
	TComboBox *ComboBoxDataAlgo6;
	TComboBox *ComboBoxDataAlgo7;
	TComboBox *ComboBoxDataAlgo8;
	TButton *ButtonFile8;
	TCheckBox *CheckBoxEraseChip_6;
	TCheckBox *CheckBoxEraseChip_7;
	TCheckBox *CheckBoxEraseChip_8;
	TCheckBox *CheckBoxDataEnable9;
	TEdit *EditDataFile9;
	TCheckBox *CheckBoxDataEnable10;
	TEdit *EditDataFile10;
	TButton *ButtonFile9;
	TEdit *EditDataAddress9;
	TEdit *EditDataAddress10;
	TComboBox *ComboBoxDataAlgo9;
	TComboBox *ComboBoxDataAlgo10;
	TButton *ButtonFile10;
	TCheckBox *CheckBoxEraseChip_9;
	TCheckBox *CheckBoxEraseChip_10;
	TButton *Button2;
	TLabel *Label69;
	TCheckBox *CheckBoxEraseChip_1;
	TCheckBox *CheckBoxEraseChip_2;
	TCheckBox *CheckBoxEraseChip_3;
	TCheckBox *CheckBoxEraseChip_4;
	TCheckBox *CheckBoxEraseChip_5;
	TLabel *Label70;
	TComboBox *ComboBoxConstEnable_1;
	TLabel *Label71;
	TLabel *Label72;
	TComboBox *ComboBoxConstEnable_2;
	TLabel *Label73;
	TComboBox *ComboBoxConstEnable_3;
	TLabel *Label74;
	TComboBox *ComboBoxConstEnable_4;
	TComboBox *ComboBoxSNEnable;
	TLabel *Label75;
	TComboBox *ComboBoxDate;
	TComboBox *ComboBoxEncryptEnable;
	TLabel *Label76;
	TComboBox *ComboBox1;
	TComboBox *ComboBoxAlgoRnd1;
	TComboBox *ComboBoxAlgoRnd2;
	TLabel *Label35;
	TLabel *Label37;
	TComboBox *ComboBoxAlgoRnd3;
	TComboBox *ComboBoxAlgoRnd4;
	TLabel *Label38;
	TComboBox *ComboBoxToolFactory;
	TLabel *Label42;
	TComboBox *ComboBoxToolSn;
	TLabel *Label44;
	TComboBox *ComboBoxToolChannel;
	TLabel *Label77;
	TLabel *LabelPCNote;
	TLabel *Label56;
	TComboBox *ComboBoxResetMode;
	TTabSheet *TabSheet10;
	TPageControl *PageControl3;
	TTabSheet *标准信号波形;
	TTabSheet *PageControl4;
	TImage *Image1;
	TImage *Image2;
	TEdit *EditStdOkDelay;
	TLabel *Label81;
	TLabel *Label82;
	TLabel *Label83;
	TEdit *EditEOT_T2;
	TEdit *EditEOT_T1;
	TEdit *EditEOT_T3;
	TComboBox *ComboBoxMachineIF;
	TLabel *Label84;
	TButton *ButtonMachineHelp;
	TComboBox *ComboBoxAbortOnError;
	TLabel *Label85;
	TLabel *Label86;
	TComboBox *ComboBoxAbortNG;
	TButton *Button15;
	TButton *Button16;
	TButton *Button17;
	TBitBtn *BitBtn1;
	TPanel *Panel1;
	TLabel *Label39;
	TLabel *Label64;
	TLabel *Label78;
	TLabel *Label79;
	TLabel *Label80;
	TEdit *EditReadAddr;
	TEdit *EditReadOffset;
	TButton *ButtonReadFlash;
	TButton *Button4;
	TButton *Button13;
	TButton *Button3;
	TEdit *EditReadFlashSize;
	TButton *Button14;
	TButton *Button18;
	TButton *Button21;
	TButton *Button22;
	TButton *Button1;
	TLabel *Label91;
	TButton *Button23;
	TBitBtn *BitBtn2;
	TButton *Button24;
	TValueListEditor *ValueListEditor1;
	TLabel *Label2;
	void __fastcall ComboBoxManufacturerChange(TObject *Sender);
	void __fastcall ComboBoxSerialChange(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall ComboBoxDeviceChange(TObject *Sender);
	void __fastcall ButtonFile1Click(TObject *Sender);
	void __fastcall ButtonSelectFoldClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ButtonOBhelpClick(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Label1Click(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall ButtonReadFlashClick(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button13Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button14Click(TObject *Sender);
	void __fastcall ButtonMachineHelpClick(TObject *Sender);
	void __fastcall Button15Click(TObject *Sender);
	void __fastcall Button16Click(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall Button17Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button21Click(TObject *Sender);
	void __fastcall Button22Click(TObject *Sender);
	void __fastcall Button18Click(TObject *Sender);
	void __fastcall Button23Click(TObject *Sender);
	void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall Button24Click(TObject *Sender);
	void __fastcall ValueListEditor1GetPickList(TObject *Sender, const UnicodeString KeyName,
          TStrings *Values);
private:	// User declarations
public:		// User declarations
	__fastcall TFormProg(TComponent* Owner);

	void __fastcall GetHexFileStartAddress(int i);
	void __fastcall MakeLuaForSWD(void);
	void __fastcall MakeLuaForSWIM(void);
	void __fastcall MakeConfigFixData(void);
	void __fastcall MakeMachineIF(void);
	void __fastcall SaveIni(void);

	int ComboBoxManufacturer_ItemIndex;
	int ComboBoxSerial_ItemIndex;
	int ComboBoxDevice_ItemIndex;

	int mStatus;

	char mListBuf[];
	int mListLen;
	int mFolderLevel;
	String FloderName[12];

	TStrings *ListFileName;
	TStrings *ListFilePath;
	TStrings *ListFileType;

	FILE_LIST_T mFileList;

	// 固件窗口
	TCheckBox *mChkBox[10];
	TCheckBox *mChkEraseChip[10];
	TEdit *mEditDataFile[10];
	TEdit *mEditDataAddress[10];
	TComboBox *mComboBoxAlgo[10];


	uint32_t mDataFileSum;

};

#define STR_LEN_MAX   48

typedef struct
{
	char Manufacturer[STR_LEN_MAX];
	char Serial[STR_LEN_MAX];
	char Device[STR_LEN_MAX];
	char Lua[STR_LEN_MAX];
}CHIP_T;

// 其他参数排列次序
//单路模式时钟延迟=0
//多路模式时钟延迟=0
//读内存指令间延迟(us)=0
//硬件复位后延迟(ms)=0
//解除保护后断电复位=0 --关闭
//解除保护时延迟断电(ms)=0
//解除保护断电时长(ms)=200
//重新上电后的延迟(ms)=20
//SPI串行Flash读模式=0 --单线模式
#define SWD_CLOCK_DELAY  		"单路模式时钟延迟"
#define MUL_SWD_CLOCK_DELAY 	"多路模式时钟延迟"
#define MUL_DELAYUS_READ_DATA   "读内存指令间延迟(us)"
#define RESET_DELAY				"硬件复位后延迟(ms)"
#define REMOVE_RDP_POWEROFF		"解除保护后断电复位"
#define POWEROFF_TIME1			"解除保护时延迟断电(ms)"
#define POWEROFF_TIME2			"解除保护断电时长(ms)"
#define POWEROFF_TIME3			"重新上电后的延迟(ms)"
#define SPI_READ_MODE			"SPI串行Flash读模式"

extern CHIP_T g_DeviceList[];
extern int g_DeviceCount;

//---------------------------------------------------------------------------
extern PACKAGE TFormProg *FormProg;
//---------------------------------------------------------------------------

#endif
