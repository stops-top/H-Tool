//---------------------------------------------------------------------------

#ifndef UnitSetH
#define UnitSetH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TFormSet : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet2;
	TGroupBox *GroupBox3;
	TLabel *Label2;
	TLabel *Label11;
	TLabel *Label10;
	TLabel *Label12;
	TLabel *Label1;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TEdit *EditMac;
	TEdit *EditHardVer;
	TButton *Button2;
	TEdit *EditSoftVer;
	TEdit *EditCpuID;
	TEdit *EditScanPort;
	TButton *Button3;
	TEdit *EditLocalIP;
	TEdit *EditJkxPort;
	TEdit *EditNetMask;
	TEdit *EditGateWay;
	TEdit *EditSysIP;
	TEdit *EditSysPort;
	TButton *Button1;
	TGroupBox *GroupBox1;
	TLabel *Label48;
	TLabel *Label16;
	TComboBox *ComboBoxCommMode;
	TEdit *EditH7IPAddr;
	TGroupBox *GroupBox4;
	TLabel *LabelPort;
	TButton *Button92;
	TButton *Button101;
	TButton *Button102;
	TListBox *ListBox1;
	TButton *Button4;
	TButton *Button5;
	TGroupBox *GroupBox5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TLabel *Label14;
	TLabel *Label15;
	TButton *Button10;
	TLabel *Label17;
	TOpenDialog *OpenDialog1;
	TTabSheet *TabSheet1;
	TGroupBox *GroupBox6;
	TButton *Button19;
	TGroupBox *GroupBox2;
	TLabel *LabelUpgrade;
	TLabel *LabelUPDTime;
	TLabel *Label3;
	TButton *Button103;
	TButton *Button104;
	TButton *Button105;
	TButton *Button106;
	TButton *Button11;
	TEdit *EditCmd;
	TButton *Button16;
	TButton *ButtonBackup;
	TButton *ButtonOpenBakupFolder;
	TCheckBox *CheckBoxDelNoModif;
	TCheckBox *CheckBoxDelSync;
	TButton *ButtonUpdate;
	TButton *Button13;
	TShape *Shape1;
	TShape *Shape2;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TButton *ButtonSetClock;
	TButton *ButtonQuiEmmc;
	TGroupBox *GroupBox7;
	TLabel *Label22;
	TButton *Button18;
	TButton *Button14;
	TButton *Button15;
	TTabSheet *TabSheet3;
	TButton *ButtonScreShot;
	TButton *Button17;
	TButton *Button20;
	TPanel *Panel1;
	TImage *Image1;
	TTimer *Timer1;
	TCheckBox *CheckBoxScreen;
	TButton *Button21;
	TButton *Button12;
	TButton *Button22;
	TButton *Button23;
	TLabel *Label13;
	TLabel *Label21;
	TLabel *Label23;
	TLabel *Label24;
	TButton *ButtonInitBaseParam;
	TLabel *Label25;
	void __fastcall Button92Click(TObject *Sender);
	void __fastcall Button101Click(TObject *Sender);
	void __fastcall Button102Click(TObject *Sender);
	void __fastcall Button105Click(TObject *Sender);
	void __fastcall Button104Click(TObject *Sender);
	void __fastcall Button103Click(TObject *Sender);
	void __fastcall Button106Click(TObject *Sender);
	void __fastcall ButtonSetClockClick(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ListBox1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ComboBoxCommModeChange(TObject *Sender);
	void __fastcall EditH7IPAddrChange(TObject *Sender);
	void __fastcall EditH7IPAddrExit(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button19Click(TObject *Sender);
	void __fastcall ButtonUpdateClick(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Button16Click(TObject *Sender);
	void __fastcall ButtonBackupClick(TObject *Sender);
	void __fastcall ButtonOpenBakupFolderClick(TObject *Sender);
	void __fastcall Button13Click(TObject *Sender);
	void __fastcall Button14Click(TObject *Sender);
	void __fastcall ButtonQuiEmmcClick(TObject *Sender);
	void __fastcall Button18Click(TObject *Sender);
	void __fastcall Button15Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall ButtonScreShotClick(TObject *Sender);
	void __fastcall Button17MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Button17MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Button20MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Button20MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall CheckBoxScreenClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button21Click(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall Button22Click(TObject *Sender);
	void __fastcall Button23Click(TObject *Sender);
	void __fastcall ButtonInitBaseParamClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormSet(TComponent* Owner);
	String __fastcall TFormSet::ExecuteApp(String sCmdline);

	void __fastcall TFormSet::SearchEMMC(void);

	int mGuiReady;

	String mDiskEmmc;
	int mDiskFound;
	int mUpdateFileCount;	//更新的文件总个数，用于进度指示，不太准
	int mUpdateFileCmd;		// 1表示开始跟新文件，0表示其他操作
	int mUpdatedCount;		// 已更新的文件个数
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSet *FormSet;
//---------------------------------------------------------------------------
#endif
