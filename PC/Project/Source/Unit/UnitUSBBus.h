//---------------------------------------------------------------------------

#ifndef UnitUSBBusH
#define UnitUSBBusH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.ImgList.hpp>
//---------------------------------------------------------------------------
class TFormUSBBus : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl3;
	TTabSheet *TabSheet7;
	TLabel *Label54;
	TLabel *Label84;
	TComboBox *ComboBoxI2CClock;
	TButton *Button65;
	TButton *ButtonI2CSend;
	TTabSheet *TabSheet8;
	TLabel *Label55;
	TComboBox *ComboBoxBusVolt;
	TLabel *Label1;
	TComboBox *ComboBoxI2CAddr;
	TEdit *EditI2CWriteData0;
	TEdit *EditI2CReadNum;
	TButton *ButtonI2CRead;
	TButton *Button1;
	TButton *Button3;
	TLabel *Label2;
	TLabel *Label11;
	TButton *Button4;
	TButton *Button5;
	TLabel *Label4;
	TEdit *EditI2CWriteData1;
	TLabel *Label5;
	TButton *Button8;
	TMemo *MemoI2C;
	TButton *Button6;
	TButton *Button2;
	TLabel *Label13;
	TLabel *Label3;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label12;
	TEdit *EditI2CDelay;
	TButton *Button7;
	TEdit *EditI2CFor;
	TButton *Button9;
	TButton *Button10;
	TEdit *EditI2CBeepStart;
	TEdit *EditI2CBeepStop;
	TEdit *EditI2CBeepCycle;
	TLabel *Label6;
	TComboBox *ComboBoxI2CDispWidth;
	TLabel *Label14;
	TButton *Button11;
	TButton *Button67;
	TLabel *Label24;
	TButton *Button14;
	TButton *Button22;
	TPanel *Panel1;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label18;
	TLabel *Label20;
	TLabel *Label17;
	TLabel *Label21;
	TLabel *Label19;
	TLabel *Label25;
	TLabel *Label26;
	TImage *ImageSPI_00;
	TComboBox *ComboBoxSPIFreq;
	TButton *Button13;
	TComboBox *ComboBoxSpiCsCh;
	TEdit *EditSPIWriteData0;
	TButton *Button15;
	TButton *Button16;
	TButton *Button17;
	TButton *Button18;
	TButton *Button19;
	TEdit *EditSPIWriteData1;
	TButton *Button12;
	TEdit *EditSPIReadNum1;
	TEdit *EditSPIOnlyReadNum;
	TButton *Button23;
	TComboBox *ComboBoxSPIPhasePol;
	TImage *ImageSPI_01;
	TImage *ImageSPI_10;
	TImage *ImageSPI_11;
	void __fastcall Button67Click(TObject *Sender);
	void __fastcall ComboBoxBusVoltChange(TObject *Sender);
	void __fastcall Button65Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ComboBoxI2CClockChange(TObject *Sender);
	void __fastcall ButtonI2CReadClick(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall ButtonI2CSendClick(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall Button16Click(TObject *Sender);
	void __fastcall Button13Click(TObject *Sender);
	void __fastcall Button18Click(TObject *Sender);
	void __fastcall Button19Click(TObject *Sender);
	void __fastcall Button17Click(TObject *Sender);
	void __fastcall Button15Click(TObject *Sender);
	void __fastcall Button14Click(TObject *Sender);
	void __fastcall Button22Click(TObject *Sender);
	void __fastcall Button23Click(TObject *Sender);
	void __fastcall ComboBoxSPIPhasePolChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormUSBBus(TComponent* Owner);

	void __fastcall TFormUSBBus::AddLuaSrc(AnsiString str);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormUSBBus *FormUSBBus;
//---------------------------------------------------------------------------
#endif
