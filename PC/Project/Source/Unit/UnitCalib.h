//---------------------------------------------------------------------------

#ifndef UnitCalibH
#define UnitCalibH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>

#define SQR_WAVE_VOLT_TOP       10000 // 2000    // 方波顶最大电压
#define SQR_WAVE_VOLT_BOTTOM    -10000       // 方波底最小电压
#define SQR_WAVE_VOLT_STEP      100     // 方波电压调节步长

#define SQR_WAVE_FREQ_TOP       100000    // 方波最大频率
#define SQR_WAVE_FREQ_BOTTOM    0           // 方波最小频率
#define SQR_WAVE_FREQ_STEP      1000        // 方波频率调节步长

#define SQR_WAVE_COUNT_TOP       1000       // 方波最大个数
#define SQR_WAVE_COUNT_BOTTOM    1           // 方波最小个数
#define SQR_WAVE_COUNT_STEP      1           // 方波个数调节步长

#define PI  3.14159
#define DAC_MAX     4095    // 12位DAC
#define DEFAULT_MAX_VOLT   5592    // mV

typedef struct {
    char str[32];
    int freq;
}FREQ_LIST_T;

//---------------------------------------------------------------------------
class TFormCalib : public TForm
{
__published:	// IDE-managed Components
	TPageControl *X;
	TTabSheet *TabSheetDC;
	TTabSheet *TabSheet1;
	TMemo *Memo1;
	TButton *Button12;
	TButton *ButtonClear;
	TTabSheet *NTC电阻;
	TButton *ButtonSaveCalib;
	TButton *ButtonLoadCalib;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TGroupBox *GroupBox2;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label22;
	TLabel *Label23;
	TButton *Button19;
	TEdit *EditDACVolt_Y1;
	TButton *ButtonDACVolt;
	TButton *Button21;
	TEdit *EditDACVolt_Y2;
	TEdit *EditDACVolt_X1;
	TEdit *EditDACVolt_X2;
	TButton *Button23;
	TEdit *EditDACVolt_Y3;
	TButton *Button25;
	TEdit *EditDACVolt_Y4;
	TEdit *EditDACVolt_X3;
	TEdit *EditDACVolt_X4;
	TLabel *Label5;
	TGroupBox *GroupBox3;
	TLabel *Label19;
	TLabel *Label20;
	TLabel *Label21;
	TLabel *Label24;
	TLabel *Label25;
	TButton *Button22;
	TEdit *EditDACCurr_Y1;
	TButton *ButtonDACCurr;
	TButton *Button24;
	TEdit *EditDACCurr_Y2;
	TEdit *EditDACCurr_X1;
	TEdit *EditDACCurr_X2;
	TButton *Button26;
	TEdit *EditDACCurr_Y3;
	TButton *Button27;
	TEdit *EditDACCurr_Y4;
	TEdit *EditDACCurr_X3;
	TEdit *EditDACCurr_X4;
	TGroupBox *GroupBox4;
	TLabel *Label11;
	TButton *Button8;
	TEdit *EditTVCCVolt1;
	TButton *Button9;
	TEdit *EditTVCCVolt2;
	TEdit *EditTVCCVoltAdc1;
	TEdit *EditTVCCVoltAdc2;
	TLabel *Label4;
	TGroupBox *GroupBox6;
	TButton *Button28;
	TEdit *EditTVCCCurr1;
	TButton *Button29;
	TEdit *EditTVCCCurr2;
	TButton *Button36;
	TButton *Button37;
	TEdit *EditTVCCCurr4;
	TEdit *EditTVCCCurr3;
	TLabel *Label12;
	TEdit *EditTVCCCurrAdc1;
	TEdit *EditTVCCCurrAdc2;
	TEdit *EditTVCCCurrAdc3;
	TEdit *EditTVCCCurrAdc4;
	TLabel *Label18;
	TGroupBox *GroupBox7;
	TLabel *Label7;
	TButton *Button4;
	TEdit *EditLoadVolt1;
	TButton *Button5;
	TEdit *EditLoadVolt2;
	TEdit *EditLoadVoltAdc1;
	TLabel *Label28;
	TEdit *EditLoadVoltAdc2;
	TGroupBox *GroupBox8;
	TGroupBox *GroupBox9;
	TButton *Button6;
	TEdit *EditLoadCurrLow1;
	TButton *Button7;
	TEdit *EditLoadCurrLow2;
	TButton *Button30;
	TEdit *EditLoadCurrLow3;
	TButton *Button31;
	TEdit *EditLoadCurrLow4;
	TButton *Button32;
	TEdit *EditLoadCurrHigh1;
	TButton *Button33;
	TEdit *EditLoadCurrHigh2;
	TButton *Button34;
	TButton *Button35;
	TEdit *EditLoadCurrHigh4;
	TEdit *EditLoadCurrHigh3;
	TLabel *Label9;
	TLabel *Label26;
	TEdit *EditLoadCurrLowAdc1;
	TEdit *EditLoadCurrLowAdc2;
	TEdit *EditLoadCurrLowAdc4;
	TEdit *EditLoadCurrLowAdc3;
	TLabel *Label29;
	TLabel *Label30;
	TEdit *EditLoadCurrHighAdc1;
	TEdit *EditLoadCurrHighAdc2;
	TEdit *EditLoadCurrHighAdc3;
	TEdit *EditLoadCurrHighAdc4;
	TTabSheet *TabSheet4;
	TGroupBox *GroupBox10;
	TLabel *Label8;
	TButton *ButtonCH1_R1_2;
	TEdit *EditCH1R1Volt1;
	TLabel *Label31;
	TLabel *Label32;
	TLabel *Label33;
	TEdit *EditCH1R1VoltAdc1;
	TLabel *Label34;
	TLabel *Label35;
	TEdit *EditCH1R1Volt2;
	TEdit *EditCH1R1VoltAdc2;
	TButton *Button1;
	TEdit *EditCH1R2Volt1;
	TLabel *Label6;
	TEdit *EditCH1R2VoltAdc1;
	TEdit *EditCH1R2Volt2;
	TEdit *EditCH1R2VoltAdc2;
	TButton *Button2;
	TEdit *EditCH1R3Volt1;
	TLabel *Label36;
	TEdit *EditCH1R3VoltAdc1;
	TEdit *EditCH1R3Volt2;
	TEdit *EditCH1R3VoltAdc2;
	TButton *Button3;
	TEdit *EditCH1R4Volt1;
	TLabel *Label37;
	TEdit *EditCH1R4VoltAdc1;
	TEdit *EditCH1R4Volt2;
	TEdit *EditCH1R4VoltAdc2;
	TButton *Button10;
	TEdit *EditCH1R5Volt1;
	TLabel *Label38;
	TEdit *EditCH1R5VoltAdc1;
	TEdit *EditCH1R5Volt2;
	TEdit *EditCH1R5VoltAdc2;
	TButton *Button41;
	TEdit *EditCH1R6Volt1;
	TLabel *Label39;
	TEdit *EditCH1R6VoltAdc1;
	TEdit *EditCH1R6Volt2;
	TEdit *EditCH1R6VoltAdc2;
	TButton *Button42;
	TEdit *EditCH1R7Volt1;
	TLabel *Label40;
	TEdit *EditCH1R7VoltAdc1;
	TEdit *EditCH1R7Volt2;
	TEdit *EditCH1R7VoltAdc2;
	TButton *Button43;
	TEdit *EditCH1R8Volt1;
	TLabel *Label41;
	TEdit *EditCH1R8VoltAdc1;
	TEdit *EditCH1R8Volt2;
	TEdit *EditCH1R8VoltAdc2;
	TButton *ButtonCH1_R1_1;
	TButton *Button45;
	TButton *Button46;
	TButton *Button47;
	TButton *Button48;
	TButton *Button49;
	TButton *Button50;
	TButton *Button51;
	TGroupBox *GroupBox11;
	TLabel *Label42;
	TLabel *Label43;
	TLabel *Label44;
	TLabel *Label45;
	TLabel *Label46;
	TLabel *Label47;
	TLabel *Label48;
	TLabel *Label49;
	TLabel *Label50;
	TLabel *Label51;
	TLabel *Label52;
	TLabel *Label53;
	TLabel *Label54;
	TButton *ButtonCH2_R1_2;
	TEdit *EditCH2R1Volt1;
	TEdit *EditCH2R1VoltAdc1;
	TEdit *EditCH2R1Volt2;
	TEdit *EditCH2R1VoltAdc2;
	TButton *Button52;
	TEdit *EditCH2R2Volt1;
	TEdit *EditCH2R2VoltAdc1;
	TEdit *EditCH2R2Volt2;
	TEdit *EditCH2R2VoltAdc2;
	TButton *Button53;
	TEdit *EditCH2R3Volt1;
	TEdit *EditCH2R3VoltAdc1;
	TEdit *EditCH2R3Volt2;
	TEdit *EditCH2R3VoltAdc2;
	TButton *Button54;
	TEdit *EditCH2R4Volt1;
	TEdit *EditCH2R4VoltAdc1;
	TEdit *EditCH2R4Volt2;
	TEdit *EditCH2R4VoltAdc2;
	TButton *Button55;
	TEdit *EditCH2R5Volt1;
	TEdit *EditCH2R5VoltAdc1;
	TEdit *EditCH2R5Volt2;
	TEdit *EditCH2R5VoltAdc2;
	TButton *Button56;
	TEdit *EditCH2R6Volt1;
	TEdit *EditCH2R6VoltAdc1;
	TEdit *EditCH2R6Volt2;
	TEdit *EditCH2R6VoltAdc2;
	TButton *Button57;
	TEdit *EditCH2R7Volt1;
	TEdit *EditCH2R7VoltAdc1;
	TEdit *EditCH2R7Volt2;
	TEdit *EditCH2R7VoltAdc2;
	TButton *Button58;
	TEdit *EditCH2R8Volt1;
	TEdit *EditCH2R8VoltAdc1;
	TEdit *EditCH2R8Volt2;
	TEdit *EditCH2R8VoltAdc2;
	TButton *ButtonCH2_R1_1;
	TButton *Button60;
	TButton *Button61;
	TButton *Button62;
	TButton *Button63;
	TButton *Button64;
	TButton *Button65;
	TButton *Button66;
	TGroupBox *GroupBox5;
	TLabel *Label10;
	TLabel *Label15;
	TEdit *EditNTCRes1;
	TButton *Button16;
	TEdit *EditNTCRes2;
	TButton *Button11;
	TEdit *EditNTCRes3;
	TButton *Button39;
	TEdit *EditNTCRes4;
	TButton *Button40;
	TEdit *EditNTCResAdc1;
	TEdit *EditNTCResAdc2;
	TEdit *EditNTCResAdc3;
	TEdit *EditNTCResAdc4;
	TGroupBox *GroupBox1;
	TLabel *Label3;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label27;
	TButton *Button15;
	TEdit *EditTVCC_Y1;
	TButton *ButtonWriteCalibTVCC;
	TButton *Button18;
	TEdit *EditTVCC_Y2;
	TEdit *EditTVCC_X1;
	TEdit *EditTVCC_X2;
	TCheckBox *CheckBoxCalibEnable;
	TOpenDialog *OpenDialog1;
	void __fastcall ButtonClearClick(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall Button15Click(TObject *Sender);
	void __fastcall ButtonWriteCalibTVCCClick(TObject *Sender);
	void __fastcall ButtonDACVoltClick(TObject *Sender);
	void __fastcall ButtonDACCurrClick(TObject *Sender);
	void __fastcall Button18Click(TObject *Sender);
	void __fastcall Button19Click(TObject *Sender);
	void __fastcall Button21Click(TObject *Sender);
	void __fastcall Button22Click(TObject *Sender);
	void __fastcall Button24Click(TObject *Sender);
	void __fastcall Button23Click(TObject *Sender);
	void __fastcall Button25Click(TObject *Sender);
	void __fastcall Button26Click(TObject *Sender);
	void __fastcall Button27Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button28Click(TObject *Sender);
	void __fastcall Button29Click(TObject *Sender);
	void __fastcall Button30Click(TObject *Sender);
	void __fastcall Button31Click(TObject *Sender);
	void __fastcall Button32Click(TObject *Sender);
	void __fastcall Button33Click(TObject *Sender);
	void __fastcall Button34Click(TObject *Sender);
	void __fastcall Button35Click(TObject *Sender);
	void __fastcall Button36Click(TObject *Sender);
	void __fastcall Button37Click(TObject *Sender);
	void __fastcall Button16Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Button39Click(TObject *Sender);
	void __fastcall Button40Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ButtonCH1_R1_1Click(TObject *Sender);
	void __fastcall ButtonCH1_R1_2Click(TObject *Sender);
	void __fastcall ButtonCH2_R1_1Click(TObject *Sender);
	void __fastcall ButtonCH2_R1_2Click(TObject *Sender);
	void __fastcall CheckBoxCalibEnableClick(TObject *Sender);
	void __fastcall ButtonSaveCalibClick(TObject *Sender);
	void __fastcall ButtonLoadCalibClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormCalib(TComponent* Owner);
	void __fastcall RefreshDAC(int dac);
	void __fastcall FileCalibToEdit(void);

 	int mSqrTop, mSqrTopDAC;
    int mSqrBottom, mSqrBottomDAC;
    int mSqrCountPreset, mSqrCount;
    int mDacPos;        // 波形数组索引

	int mMaxVolt;       // 最大电压,对应DAC=255
};
//---------------------------------------------------------------------------
extern PACKAGE TFormCalib *FormCalib;
//---------------------------------------------------------------------------
#endif
