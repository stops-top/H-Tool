//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitMain.h"
#include "UnitCalib.h"
#include "UnitThread.h"
#include "bsp.h"
#include "stdio.h"
#include "bsp_udp_modbus.h"
#include "udp_modbus_addr.h"
#include "file_lib.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormCalib *FormCalib;

// 方波频率列表
FREQ_LIST_T aSqrFreqListStr[] = {
    {"0.1", 5000},
    {"0.2",2500},
    {"0.5",1000},
    {"1",500},
    {"2",250},
    {"3",167},
    {"4",125},
    {"5",100},
    {"6",83},
    {"7",71},
    {"8",62},
    {"9",55},
    {"10",50},
    {"25",20},
    {"50",10},
    {"100",5},
    {"125",4},
    {"166.67",3},
    {"250",2},
    {"500",1}
};
// 正弦波频率列表
FREQ_LIST_T aSinFreqListStr[] = {
    {"0.025", 400},
    {"0.05", 200},
    {"0.1", 100},
    {"0.125", 80},
    {"0.25", 40},
    {"0.5", 20},
    {"1", 10},
    {"1.25", 8},
    {"2", 5},
    {"2.5", 4},    //4ms
    {"5", 2},    //2ms
    {"10", 1}    //1ms
};

//---------------------------------------------------------------------------
__fastcall TFormCalib::TFormCalib(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------void __fastcall TFormCalib::RefreshDAC(int dac)

//---------------------------------------------------------------------------

void __fastcall TFormCalib::ButtonClearClick(TObject *Sender)
{
	Memo1->Lines->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::Button12Click(TObject *Sender)
{
	H7_ReadRegisters(REG03_CALIB_CH1_R1_X1, 224+8);	  /* 读全部的校准参数 */
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::Button15Click(TObject *Sender)
{
	udp_Send06H(REG03_OUT_TVCC_DAC, StrToInt(EditTVCC_X1->Text));
}
//---------------------------------------------------------------------------

// 写入校准参数 TVCC_SET
void __fastcall TFormCalib::ButtonWriteCalibTVCCClick(TObject *Sender)
{
	uint8_t buf[4];
	uint16_t reg_buf[8];
	uint8_t pos = 0;
	float x1,y1,x2,y2;

	x1 = MyStrToFloat(EditTVCC_X1->Text);
	y1 = MyStrToFloat(EditTVCC_Y1->Text);
	x2 = MyStrToFloat(EditTVCC_X2->Text);
	y2 = MyStrToFloat(EditTVCC_Y2->Text);

	FloatToBEBuf(x1, buf);  reg_buf[0] = (buf[0] << 8) + buf[1]; reg_buf[1] = (buf[2] << 8) + buf[3];
	FloatToBEBuf(y1, buf);  reg_buf[2] = (buf[0] << 8) + buf[1]; reg_buf[3] = (buf[2] << 8) + buf[3];
	FloatToBEBuf(x2, buf);  reg_buf[4] = (buf[0] << 8) + buf[1]; reg_buf[5] = (buf[2] << 8) + buf[3];
	FloatToBEBuf(y2, buf);  reg_buf[6] = (buf[0] << 8) + buf[1]; reg_buf[7] = (buf[2] << 8) + buf[3];

	H7_WriteMutiRegisters(REG03_CALIB_TVCC_SET_X1, 8, reg_buf);
}
//---------------------------------------------------------------------------

// 写入校准参数 DAC_Volt
void __fastcall TFormCalib::ButtonDACVoltClick(TObject *Sender)
{
	uint8_t buf[4];
	uint16_t reg_buf[8];
	uint8_t pos = 0;
	float x1,y1,x2,y2,x3,y3,x4,y4;

	x1 = MyStrToFloat(EditDACVolt_X1->Text);
	y1 = MyStrToFloat(EditDACVolt_Y1->Text);
	x2 = MyStrToFloat(EditDACVolt_X2->Text);
	y2 = MyStrToFloat(EditDACVolt_Y2->Text);
	x3 = MyStrToFloat(EditDACVolt_X3->Text);
	y3 = MyStrToFloat(EditDACVolt_Y3->Text);
	x4 = MyStrToFloat(EditDACVolt_X4->Text);
	y4 = MyStrToFloat(EditDACVolt_Y4->Text);

	reg_buf[0] = (uint16_t)x1;
	reg_buf[1] = (uint16_t)y1;
	reg_buf[2] = (uint16_t)x2;
	reg_buf[3] = (uint16_t)y2;
	reg_buf[4] = (uint16_t)x3;
	reg_buf[5] = (uint16_t)y3;
	reg_buf[6] = (uint16_t)x4;
	reg_buf[7] = (uint16_t)y4;

	H7_WriteMutiRegisters(REG03_CALIB_DAC_VOLT_X1, 8, reg_buf);
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::ButtonDACCurrClick(TObject *Sender)
{
	uint8_t buf[4];
	uint16_t reg_buf[8];
	uint8_t pos = 0;
	float x1,y1,x2,y2,x3,y3,x4,y4;

	x1 = MyStrToFloat(EditDACCurr_X1->Text);
	y1 = MyStrToFloat(EditDACCurr_Y1->Text);
	x2 = MyStrToFloat(EditDACCurr_X2->Text);
	y2 = MyStrToFloat(EditDACCurr_Y2->Text);
	x3 = MyStrToFloat(EditDACCurr_X3->Text);
	y3 = MyStrToFloat(EditDACCurr_Y3->Text);
	x4 = MyStrToFloat(EditDACCurr_X4->Text);
	y4 = MyStrToFloat(EditDACCurr_Y4->Text);

	reg_buf[0] = (uint16_t)x1;
	reg_buf[1] = (uint16_t)y1;
	reg_buf[2] = (uint16_t)x2;
	reg_buf[3] = (uint16_t)y2;
	reg_buf[4] = (uint16_t)x3;
	reg_buf[5] = (uint16_t)y3;
	reg_buf[6] = (uint16_t)x4;
	reg_buf[7] = (uint16_t)y4;

	H7_WriteMutiRegisters(REG03_CALIB_DAC_CURR_X1, 8, reg_buf);
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::Button18Click(TObject *Sender)
{
	H7_WriteRegister(REG03_OUT_TVCC_DAC, StrToInt(EditTVCC_X2->Text));
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::Button19Click(TObject *Sender)
{
	H7_WriteRegister(REG03_OUT_VOLT_DAC, StrToInt(EditDACVolt_X1->Text));
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::Button21Click(TObject *Sender)
{
	H7_WriteRegister(REG03_OUT_VOLT_DAC, StrToInt(EditDACVolt_X2->Text));
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::Button22Click(TObject *Sender)
{
	H7_WriteRegister(REG03_OUT_CURR_DAC, StrToInt(EditDACCurr_X1->Text));
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::Button24Click(TObject *Sender)
{
	H7_WriteRegister(REG03_OUT_CURR_DAC, StrToInt(EditDACCurr_X2->Text));
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::Button23Click(TObject *Sender)
{
	H7_WriteRegister(REG03_OUT_VOLT_DAC, StrToInt(EditDACVolt_X3->Text));
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::Button25Click(TObject *Sender)
{
	H7_WriteRegister(REG03_OUT_VOLT_DAC, StrToInt(EditDACVolt_X4->Text));
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::Button26Click(TObject *Sender)
{
	H7_WriteRegister(REG03_OUT_CURR_DAC, StrToInt(EditDACCurr_X3->Text));
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::Button27Click(TObject *Sender)
{
	H7_WriteRegister(REG03_OUT_CURR_DAC, StrToInt(EditDACCurr_X4->Text));
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::Button8Click(TObject *Sender)
{
	float x1, y1;
	AnsiString s1;
	uint16_t reg_buf[4];
	uint8_t buf[4];

	x1 = MyStrToFloat(EditTVCCVoltAdc1->Text);
	y1 = MyStrToFloat(EditTVCCVolt1->Text);

	s1.sprintf("TVCC电压校准点1: x1=%0.3f, y1=%0.3f", x1, y1);
	Memo1->Lines->Add(s1);

	FloatToBEBuf(x1, buf);  reg_buf[0] = (buf[0] << 8) + buf[1]; reg_buf[1] = (buf[2] << 8) + buf[3];
	FloatToBEBuf(y1, buf);  reg_buf[2] = (buf[0] << 8) + buf[1]; reg_buf[3] = (buf[2] << 8) + buf[3];
	H7_WriteMutiRegisters(REG03_CALIB_TVCC_VOLT_X1, 4, reg_buf);
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::Button9Click(TObject *Sender)
{
	float x, y;
	AnsiString s1;
	uint16_t reg_buf[4];
	uint8_t buf[4];

	x = MyStrToFloat(EditTVCCVoltAdc2->Text);
	y = MyStrToFloat(EditTVCCVolt2->Text);

	s1.sprintf("TVCC电压校准点2: x2=%0.3f, y2=%0.3f", x, y);
	Memo1->Lines->Add(s1);

	FloatToBEBuf(x, buf);  reg_buf[0] = (buf[0] << 8) + buf[1]; reg_buf[1] = (buf[2] << 8) + buf[3];
	FloatToBEBuf(y, buf);  reg_buf[2] = (buf[0] << 8) + buf[1]; reg_buf[3] = (buf[2] << 8) + buf[3];
	H7_WriteMutiRegisters(REG03_CALIB_TVCC_VOLT_X2, 4, reg_buf);
}
//---------------------------------------------------------------------------



void __fastcall TFormCalib::Button4Click(TObject *Sender)
{
	float x, y;
	AnsiString s1;
	uint16_t reg_buf[4];
	uint8_t buf[4];

	x = MyStrToFloat(EditLoadVoltAdc1->Text);
	y = MyStrToFloat(EditLoadVolt1->Text);

	s1.sprintf("负载电压校准点1: x1=%0.3f, y1=%0.3f", x, y);
	Memo1->Lines->Add(s1);

	FloatToBEBuf(x, buf);  reg_buf[0] = (buf[0] << 8) + buf[1]; reg_buf[1] = (buf[2] << 8) + buf[3];
	FloatToBEBuf(y, buf);  reg_buf[2] = (buf[0] << 8) + buf[1]; reg_buf[3] = (buf[2] << 8) + buf[3];
	H7_WriteMutiRegisters(REG03_CALIB_LOAD_VOLT_X1, 4, reg_buf);
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::Button5Click(TObject *Sender)
{
	float x, y;
	AnsiString s1;
	uint16_t reg_buf[4];
	uint8_t buf[4];

	x = MyStrToFloat(EditLoadVoltAdc2->Text);
	y = MyStrToFloat(EditLoadVolt2->Text);

	s1.sprintf("负载电压校准点2: x2=%0.3f, y2=%0.3f", x, y);
	Memo1->Lines->Add(s1);

	FloatToBEBuf(x, buf);  reg_buf[0] = (buf[0] << 8) + buf[1]; reg_buf[1] = (buf[2] << 8) + buf[3];
	FloatToBEBuf(y, buf);  reg_buf[2] = (buf[0] << 8) + buf[1]; reg_buf[3] = (buf[2] << 8) + buf[3];
	H7_WriteMutiRegisters(REG03_CALIB_LOAD_VOLT_X2, 4, reg_buf);
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::Button6Click(TObject *Sender)
{
	float x, y;
	AnsiString s1;
	uint16_t reg_buf[4];
	uint8_t buf[4];

	x = MyStrToFloat(EditLoadCurrLowAdc1->Text);
	y = MyStrToFloat(EditLoadCurrLow1->Text);

	s1.sprintf("负载电流1校准点1: x1=%0.3f, y1=%0.3f", x, y);
	Memo1->Lines->Add(s1);

	FloatToBEBuf(x, buf);  reg_buf[0] = (buf[0] << 8) + buf[1]; reg_buf[1] = (buf[2] << 8) + buf[3];
	FloatToBEBuf(y, buf);  reg_buf[2] = (buf[0] << 8) + buf[1]; reg_buf[3] = (buf[2] << 8) + buf[3];
	H7_WriteMutiRegisters(REG03_CALIB_LOAD_CURR1_X1, 4, reg_buf);
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::Button7Click(TObject *Sender)
{
	float x, y;
	AnsiString s1;
	uint16_t reg_buf[4];
	uint8_t buf[4];

	x = MyStrToFloat(EditLoadCurrLowAdc2->Text);
	y = MyStrToFloat(EditLoadCurrLow2->Text);

	s1.sprintf("负载电流1校准点2: x2=%0.3f, y2=%0.3f", x, y);
	Memo1->Lines->Add(s1);

	FloatToBEBuf(x, buf);  reg_buf[0] = (buf[0] << 8) + buf[1]; reg_buf[1] = (buf[2] << 8) + buf[3];
	FloatToBEBuf(y, buf);  reg_buf[2] = (buf[0] << 8) + buf[1]; reg_buf[3] = (buf[2] << 8) + buf[3];
	H7_WriteMutiRegisters(REG03_CALIB_LOAD_CURR1_X2, 4, reg_buf);
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::Button28Click(TObject *Sender)
{
	float x, y;
	AnsiString s1;
	uint16_t reg_buf[4];
	uint8_t buf[4];

	x = MyStrToFloat(EditTVCCCurrAdc1->Text);
	y = MyStrToFloat(EditTVCCCurr1->Text);

	s1.sprintf("TVCC电流校准点1: x1=%0.3f, y1=%0.3f", x, y);
	Memo1->Lines->Add(s1);

	FloatToBEBuf(x, buf);  reg_buf[0] = (buf[0] << 8) + buf[1]; reg_buf[1] = (buf[2] << 8) + buf[3];
	FloatToBEBuf(y, buf);  reg_buf[2] = (buf[0] << 8) + buf[1]; reg_buf[3] = (buf[2] << 8) + buf[3];
	H7_WriteMutiRegisters(REG03_CALIB_TVCC_CURR_X1, 4, reg_buf);
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::Button29Click(TObject *Sender)
{
	float x, y;
	AnsiString s1;
	uint16_t reg_buf[4];
	uint8_t buf[4];

	x = MyStrToFloat(EditTVCCCurrAdc2->Text);
	y = MyStrToFloat(EditTVCCCurr2->Text);

	s1.sprintf("TVCC电流校准点2: x2=%0.3f, y2=%0.3f", x, y);
	Memo1->Lines->Add(s1);

	FloatToBEBuf(x, buf);  reg_buf[0] = (buf[0] << 8) + buf[1]; reg_buf[1] = (buf[2] << 8) + buf[3];
	FloatToBEBuf(y, buf);  reg_buf[2] = (buf[0] << 8) + buf[1]; reg_buf[3] = (buf[2] << 8) + buf[3];
	H7_WriteMutiRegisters(REG03_CALIB_TVCC_CURR_X2, 4, reg_buf);
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::Button30Click(TObject *Sender)
{
	float x, y;
	AnsiString s1;
	uint16_t reg_buf[4];
	uint8_t buf[4];

	x = MyStrToFloat(EditLoadCurrLowAdc3->Text);
	y = MyStrToFloat(EditLoadCurrLow3->Text);

	s1.sprintf("负载电流1校准点3: x3=%0.3f, y3=%0.3f", x, y);
	Memo1->Lines->Add(s1);

	FloatToBEBuf(x, buf);  reg_buf[0] = (buf[0] << 8) + buf[1]; reg_buf[1] = (buf[2] << 8) + buf[3];
	FloatToBEBuf(y, buf);  reg_buf[2] = (buf[0] << 8) + buf[1]; reg_buf[3] = (buf[2] << 8) + buf[3];
	H7_WriteMutiRegisters(REG03_CALIB_LOAD_CURR1_X3, 4, reg_buf);
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::Button31Click(TObject *Sender)
{
	float x, y;
	AnsiString s1;
	uint16_t reg_buf[4];
	uint8_t buf[4];

	x = MyStrToFloat(EditLoadCurrLowAdc4->Text);
	y = MyStrToFloat(EditLoadCurrLow4->Text);

	s1.sprintf("负载电流1校准点4: x2=%0.3f, y2=%0.3f", x, y);
	Memo1->Lines->Add(s1);

	FloatToBEBuf(x, buf);  reg_buf[0] = (buf[0] << 8) + buf[1]; reg_buf[1] = (buf[2] << 8) + buf[3];
	FloatToBEBuf(y, buf);  reg_buf[2] = (buf[0] << 8) + buf[1]; reg_buf[3] = (buf[2] << 8) + buf[3];
	H7_WriteMutiRegisters(REG03_CALIB_LOAD_CURR1_X4, 4, reg_buf);
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::Button32Click(TObject *Sender)
{
	float x, y;
	AnsiString s1;
	uint16_t reg_buf[4];
	uint8_t buf[4];

	x = MyStrToFloat(EditLoadCurrHighAdc1->Text);
	y = MyStrToFloat(EditLoadCurrHigh1->Text);

	s1.sprintf("负载电流2校准点1: x1=%0.3f, y1=%0.3f", x, y);
	Memo1->Lines->Add(s1);

	FloatToBEBuf(x, buf);  reg_buf[0] = (buf[0] << 8) + buf[1]; reg_buf[1] = (buf[2] << 8) + buf[3];
	FloatToBEBuf(y, buf);  reg_buf[2] = (buf[0] << 8) + buf[1]; reg_buf[3] = (buf[2] << 8) + buf[3];
	H7_WriteMutiRegisters(REG03_CALIB_LOAD_CURR2_X1, 4, reg_buf);
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::Button33Click(TObject *Sender)
{
	float x, y;
	AnsiString s1;
	uint16_t reg_buf[4];
	uint8_t buf[4];

	x = MyStrToFloat(EditLoadCurrHighAdc2->Text);
	y = MyStrToFloat(EditLoadCurrHigh2->Text);

	s1.sprintf("负载电流2校准点2: x2=%0.3f, y2=%0.3f", x, y);
	Memo1->Lines->Add(s1);

	FloatToBEBuf(x, buf);  reg_buf[0] = (buf[0] << 8) + buf[1]; reg_buf[1] = (buf[2] << 8) + buf[3];
	FloatToBEBuf(y, buf);  reg_buf[2] = (buf[0] << 8) + buf[1]; reg_buf[3] = (buf[2] << 8) + buf[3];
	H7_WriteMutiRegisters(REG03_CALIB_LOAD_CURR2_X2, 4, reg_buf);
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::Button34Click(TObject *Sender)
{
	float x, y;
	AnsiString s1;
	uint16_t reg_buf[4];
	uint8_t buf[4];

	x = MyStrToFloat(EditLoadCurrHighAdc3->Text);
	y = MyStrToFloat(EditLoadCurrHigh3->Text);

	s1.sprintf("负载电流2校准点3: x3=%0.3f, y3=%0.3f", x, y);
	Memo1->Lines->Add(s1);

	FloatToBEBuf(x, buf);  reg_buf[0] = (buf[0] << 8) + buf[1]; reg_buf[1] = (buf[2] << 8) + buf[3];
	FloatToBEBuf(y, buf);  reg_buf[2] = (buf[0] << 8) + buf[1]; reg_buf[3] = (buf[2] << 8) + buf[3];
	H7_WriteMutiRegisters(REG03_CALIB_LOAD_CURR2_X3, 4, reg_buf);
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::Button35Click(TObject *Sender)
{
	float x, y;
	AnsiString s1;
	uint16_t reg_buf[4];
	uint8_t buf[4];

	x = MyStrToFloat(EditLoadCurrHighAdc4->Text);
	y = MyStrToFloat(EditLoadCurrHigh4->Text);

	s1.sprintf("负载电流2校准点4: x4=%0.3f, y4=%0.3f", x, y);
	Memo1->Lines->Add(s1);

	FloatToBEBuf(x, buf);  reg_buf[0] = (buf[0] << 8) + buf[1]; reg_buf[1] = (buf[2] << 8) + buf[3];
	FloatToBEBuf(y, buf);  reg_buf[2] = (buf[0] << 8) + buf[1]; reg_buf[3] = (buf[2] << 8) + buf[3];
	H7_WriteMutiRegisters(REG03_CALIB_LOAD_CURR2_X4, 4, reg_buf);
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::Button36Click(TObject *Sender)
{
	float x, y;
	AnsiString s1;
	uint16_t reg_buf[4];
	uint8_t buf[4];

	x = MyStrToFloat(EditTVCCCurrAdc3->Text);
	y = MyStrToFloat(EditTVCCCurr3->Text);

	s1.sprintf("TVCC电流校准点3: x3=%0.3f, y3=%0.3f", x, y);
	Memo1->Lines->Add(s1);

	FloatToBEBuf(x, buf);  reg_buf[0] = (buf[0] << 8) + buf[1]; reg_buf[1] = (buf[2] << 8) + buf[3];
	FloatToBEBuf(y, buf);  reg_buf[2] = (buf[0] << 8) + buf[1]; reg_buf[3] = (buf[2] << 8) + buf[3];
	H7_WriteMutiRegisters(REG03_CALIB_TVCC_CURR_X3, 4, reg_buf);
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::Button37Click(TObject *Sender)
{
	float x, y;
	AnsiString s1;
	uint16_t reg_buf[4];
	uint8_t buf[4];

	x = MyStrToFloat(EditTVCCCurrAdc4->Text);
	y = MyStrToFloat(EditTVCCCurr4->Text);

	s1.sprintf("TVCC电流校准点4: x4=%0.3f, y4=%0.3f", x, y);
	Memo1->Lines->Add(s1);

	FloatToBEBuf(x, buf);  reg_buf[0] = (buf[0] << 8) + buf[1]; reg_buf[1] = (buf[2] << 8) + buf[3];
	FloatToBEBuf(y, buf);  reg_buf[2] = (buf[0] << 8) + buf[1]; reg_buf[3] = (buf[2] << 8) + buf[3];
	H7_WriteMutiRegisters(REG03_CALIB_TVCC_CURR_X4, 4, reg_buf);
}
//---------------------------------------------------------------------------



void __fastcall TFormCalib::Button16Click(TObject *Sender)
{
	float x, y;
	AnsiString s1;
	uint16_t reg_buf[4];
	uint8_t buf[4];

	x = MyStrToFloat(EditNTCResAdc1->Text);
	y = MyStrToFloat(EditNTCRes1->Text);

	s1.sprintf("NTC电阻准点1: x1=%0.3f, y1=%0.3f", x, y);
	Memo1->Lines->Add(s1);

	FloatToBEBuf(x, buf);  reg_buf[0] = (buf[0] << 8) + buf[1]; reg_buf[1] = (buf[2] << 8) + buf[3];
	FloatToBEBuf(y, buf);  reg_buf[2] = (buf[0] << 8) + buf[1]; reg_buf[3] = (buf[2] << 8) + buf[3];
	H7_WriteMutiRegisters(REG03_CALIB_NTC_RES_X1, 4, reg_buf);
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::Button11Click(TObject *Sender)
{
	float x, y;
	AnsiString s1;
	uint16_t reg_buf[4];
	uint8_t buf[4];

	x = MyStrToFloat(EditNTCResAdc2->Text);
	y = MyStrToFloat(EditNTCRes2->Text);

	s1.sprintf("NTC电阻准点2: x2=%0.3f, y2=%0.3f", x, y);
	Memo1->Lines->Add(s1);

	FloatToBEBuf(x, buf);  reg_buf[0] = (buf[0] << 8) + buf[1]; reg_buf[1] = (buf[2] << 8) + buf[3];
	FloatToBEBuf(y, buf);  reg_buf[2] = (buf[0] << 8) + buf[1]; reg_buf[3] = (buf[2] << 8) + buf[3];
	H7_WriteMutiRegisters(REG03_CALIB_NTC_RES_X2, 4, reg_buf);

}
//---------------------------------------------------------------------------
void __fastcall TFormCalib::FileCalibToEdit(void)
{
	/* CH1 校准参数 */
	EditCH1R1Volt1->Text    = MyFloatToStr(g_tCalib.CH1[0].y1, "%0.3f");
	EditCH1R1VoltAdc1->Text = MyFloatToStr(g_tCalib.CH1[0].x1, "%0.3f");
	EditCH1R1Volt2->Text    = MyFloatToStr(g_tCalib.CH1[0].y2, "%0.3f");
	EditCH1R1VoltAdc2->Text = MyFloatToStr(g_tCalib.CH1[0].x2, "%0.3f");

	EditCH1R2Volt1->Text    = MyFloatToStr(g_tCalib.CH1[1].y1, "%0.3f");
	EditCH1R2VoltAdc1->Text = MyFloatToStr(g_tCalib.CH1[1].x1, "%0.3f");
	EditCH1R2Volt2->Text    = MyFloatToStr(g_tCalib.CH1[1].y2, "%0.3f");
	EditCH1R2VoltAdc2->Text = MyFloatToStr(g_tCalib.CH1[1].x2, "%0.3f");

	EditCH1R3Volt1->Text    = MyFloatToStr(g_tCalib.CH1[2].y1, "%0.3f");
	EditCH1R3VoltAdc1->Text = MyFloatToStr(g_tCalib.CH1[2].x1, "%0.3f");
	EditCH1R3Volt2->Text    = MyFloatToStr(g_tCalib.CH1[2].y2, "%0.3f");
	EditCH1R3VoltAdc2->Text = MyFloatToStr(g_tCalib.CH1[2].x2, "%0.3f");

	EditCH1R4Volt1->Text    = MyFloatToStr(g_tCalib.CH1[3].y1, "%0.3f");
	EditCH1R4VoltAdc1->Text = MyFloatToStr(g_tCalib.CH1[3].x1, "%0.3f");
	EditCH1R4Volt2->Text    = MyFloatToStr(g_tCalib.CH1[3].y2, "%0.3f");
	EditCH1R4VoltAdc2->Text = MyFloatToStr(g_tCalib.CH1[3].x2, "%0.3f");

	EditCH1R5Volt1->Text    = MyFloatToStr(g_tCalib.CH1[4].y1, "%0.3f");
	EditCH1R5VoltAdc1->Text = MyFloatToStr(g_tCalib.CH1[4].x1, "%0.3f");
	EditCH1R5Volt2->Text    = MyFloatToStr(g_tCalib.CH1[4].y2, "%0.3f");
	EditCH1R5VoltAdc2->Text = MyFloatToStr(g_tCalib.CH1[4].x2, "%0.3f");

	EditCH1R6Volt1->Text    = MyFloatToStr(g_tCalib.CH1[5].y1, "%0.3f");
	EditCH1R6VoltAdc1->Text = MyFloatToStr(g_tCalib.CH1[5].x1, "%0.3f");
	EditCH1R6Volt2->Text    = MyFloatToStr(g_tCalib.CH1[5].y2, "%0.3f");
	EditCH1R6VoltAdc2->Text = MyFloatToStr(g_tCalib.CH1[5].x2, "%0.3f");

	EditCH1R7Volt1->Text    = MyFloatToStr(g_tCalib.CH1[6].y1, "%0.3f");
	EditCH1R7VoltAdc1->Text = MyFloatToStr(g_tCalib.CH1[6].x1, "%0.3f");
	EditCH1R7Volt2->Text    = MyFloatToStr(g_tCalib.CH1[6].y2, "%0.3f");
	EditCH1R7VoltAdc2->Text = MyFloatToStr(g_tCalib.CH1[6].x2, "%0.3f");

	EditCH1R8Volt1->Text    = MyFloatToStr(g_tCalib.CH1[7].y1, "%0.3f");
	EditCH1R8VoltAdc1->Text = MyFloatToStr(g_tCalib.CH1[7].x1, "%0.3f");
	EditCH1R8Volt2->Text    = MyFloatToStr(g_tCalib.CH1[7].y2, "%0.3f");
	EditCH1R8VoltAdc2->Text = MyFloatToStr(g_tCalib.CH1[7].x2, "%0.3f");

	/* CH2 校准参数 */
	EditCH2R1Volt1->Text    = MyFloatToStr(g_tCalib.CH2[0].y1, "%0.3f");
	EditCH2R1VoltAdc1->Text = MyFloatToStr(g_tCalib.CH2[0].x1, "%0.3f");
	EditCH2R1Volt2->Text    = MyFloatToStr(g_tCalib.CH2[0].y2, "%0.3f");
	EditCH2R1VoltAdc2->Text = MyFloatToStr(g_tCalib.CH2[0].x2, "%0.3f");

	EditCH2R2Volt1->Text    = MyFloatToStr(g_tCalib.CH2[1].y1, "%0.3f");
	EditCH2R2VoltAdc1->Text = MyFloatToStr(g_tCalib.CH2[1].x1, "%0.3f");
	EditCH2R2Volt2->Text    = MyFloatToStr(g_tCalib.CH2[1].y2, "%0.3f");
	EditCH2R2VoltAdc2->Text = MyFloatToStr(g_tCalib.CH2[1].x2, "%0.3f");

	EditCH2R3Volt1->Text    = MyFloatToStr(g_tCalib.CH2[2].y1, "%0.3f");
	EditCH2R3VoltAdc1->Text = MyFloatToStr(g_tCalib.CH2[2].x1, "%0.3f");
	EditCH2R3Volt2->Text    = MyFloatToStr(g_tCalib.CH2[2].y2, "%0.3f");
	EditCH2R3VoltAdc2->Text = MyFloatToStr(g_tCalib.CH2[2].x2, "%0.3f");

	EditCH2R4Volt1->Text    = MyFloatToStr(g_tCalib.CH2[3].y1, "%0.3f");
	EditCH2R4VoltAdc1->Text = MyFloatToStr(g_tCalib.CH2[3].x1, "%0.3f");
	EditCH2R4Volt2->Text    = MyFloatToStr(g_tCalib.CH2[3].y2, "%0.3f");
	EditCH2R4VoltAdc2->Text = MyFloatToStr(g_tCalib.CH2[3].x2, "%0.3f");

	EditCH2R5Volt1->Text    = MyFloatToStr(g_tCalib.CH2[4].y1, "%0.3f");
	EditCH2R5VoltAdc1->Text = MyFloatToStr(g_tCalib.CH2[4].x1, "%0.3f");
	EditCH2R5Volt2->Text    = MyFloatToStr(g_tCalib.CH2[4].y2, "%0.3f");
	EditCH2R5VoltAdc2->Text = MyFloatToStr(g_tCalib.CH2[4].x2, "%0.3f");

	EditCH2R6Volt1->Text    = MyFloatToStr(g_tCalib.CH2[5].y1, "%0.3f");
	EditCH2R6VoltAdc1->Text = MyFloatToStr(g_tCalib.CH2[5].x1, "%0.3f");
	EditCH2R6Volt2->Text    = MyFloatToStr(g_tCalib.CH2[5].y2, "%0.3f");
	EditCH2R6VoltAdc2->Text = MyFloatToStr(g_tCalib.CH2[5].x2, "%0.3f");

	EditCH2R7Volt1->Text    = MyFloatToStr(g_tCalib.CH2[6].y1, "%0.3f");
	EditCH2R7VoltAdc1->Text = MyFloatToStr(g_tCalib.CH2[6].x1, "%0.3f");
	EditCH2R7Volt2->Text    = MyFloatToStr(g_tCalib.CH2[6].y2, "%0.3f");
	EditCH2R7VoltAdc2->Text = MyFloatToStr(g_tCalib.CH2[6].x2, "%0.3f");

	EditCH2R8Volt1->Text    = MyFloatToStr(g_tCalib.CH2[7].y1, "%0.3f");
	EditCH2R8VoltAdc1->Text = MyFloatToStr(g_tCalib.CH2[7].x1, "%0.3f");
	EditCH2R8Volt2->Text    = MyFloatToStr(g_tCalib.CH2[7].y2, "%0.3f");
	EditCH2R8VoltAdc2->Text = MyFloatToStr(g_tCalib.CH2[7].x2, "%0.3f");

	/* 负载电压 */
	EditLoadVolt1->Text  = MyFloatToStr(g_tCalib.LoadVolt.y1, "%0.3f");
	EditLoadVolt2->Text  = MyFloatToStr(g_tCalib.LoadVolt.y2, "%0.3f");
	EditLoadVoltAdc1->Text  = MyFloatToStr(g_tCalib.LoadVolt.x1, "%0.3f");
	EditLoadVoltAdc2->Text  = MyFloatToStr(g_tCalib.LoadVolt.x2, "%0.3f");

	/* 负载电流 120mA */
	EditLoadCurrLow1->Text  = MyFloatToStr(g_tCalib.LoadCurr[0].y1, "%0.3f");
	EditLoadCurrLow2->Text  = MyFloatToStr(g_tCalib.LoadCurr[0].y2, "%0.3f");
	EditLoadCurrLow3->Text  = MyFloatToStr(g_tCalib.LoadCurr[0].y3, "%0.3f");
	EditLoadCurrLow4->Text  = MyFloatToStr(g_tCalib.LoadCurr[0].y4, "%0.3f");

	EditLoadCurrLowAdc1->Text  = MyFloatToStr(g_tCalib.LoadCurr[0].x1, "%0.3f");
	EditLoadCurrLowAdc2->Text  = MyFloatToStr(g_tCalib.LoadCurr[0].x2, "%0.3f");
	EditLoadCurrLowAdc3->Text  = MyFloatToStr(g_tCalib.LoadCurr[0].x3, "%0.3f");
	EditLoadCurrLowAdc4->Text  = MyFloatToStr(g_tCalib.LoadCurr[0].x4, "%0.3f");

	/* 负载电流 1.2A */
	EditLoadCurrHigh1->Text  = MyFloatToStr(g_tCalib.LoadCurr[1].y1, "%0.3f");
	EditLoadCurrHigh2->Text  = MyFloatToStr(g_tCalib.LoadCurr[1].y2, "%0.3f");
	EditLoadCurrHigh3->Text  = MyFloatToStr(g_tCalib.LoadCurr[1].y3, "%0.3f");
	EditLoadCurrHigh4->Text  = MyFloatToStr(g_tCalib.LoadCurr[1].y4, "%0.3f");

	EditLoadCurrHighAdc1->Text  = MyFloatToStr(g_tCalib.LoadCurr[1].x1, "%0.3f");
	EditLoadCurrHighAdc2->Text  = MyFloatToStr(g_tCalib.LoadCurr[1].x2, "%0.3f");
	EditLoadCurrHighAdc3->Text  = MyFloatToStr(g_tCalib.LoadCurr[1].x3, "%0.3f");
	EditLoadCurrHighAdc4->Text  = MyFloatToStr(g_tCalib.LoadCurr[1].x4, "%0.3f");

	/* TVCC电流检测 */
	EditTVCCCurr1->Text  = MyFloatToStr(g_tCalib.TVCCCurr.y1, "%0.3f");
	EditTVCCCurr2->Text  = MyFloatToStr(g_tCalib.TVCCCurr.y2, "%0.3f");
	EditTVCCCurr3->Text  = MyFloatToStr(g_tCalib.TVCCCurr.y3, "%0.3f");
	EditTVCCCurr4->Text  = MyFloatToStr(g_tCalib.TVCCCurr.y4, "%0.3f");

	EditTVCCCurrAdc1->Text  = MyFloatToStr(g_tCalib.TVCCCurr.x1, "%0.3f");
	EditTVCCCurrAdc2->Text  = MyFloatToStr(g_tCalib.TVCCCurr.x2, "%0.3f");
	EditTVCCCurrAdc3->Text  = MyFloatToStr(g_tCalib.TVCCCurr.x3, "%0.3f");
	EditTVCCCurrAdc4->Text  = MyFloatToStr(g_tCalib.TVCCCurr.x4, "%0.3f");

	/* TVCC电压检测 */
	EditTVCCVolt1->Text  = MyFloatToStr(g_tCalib.TVCCVolt.y1, "%0.3f");
	EditTVCCVoltAdc1->Text  = MyFloatToStr(g_tCalib.TVCCVolt.x1, "%0.3f");
	EditTVCCVolt2->Text  = MyFloatToStr(g_tCalib.TVCCVolt.y2, "%0.3f");
	EditTVCCVoltAdc2->Text  = MyFloatToStr(g_tCalib.TVCCVolt.x2, "%0.3f");

	EditNTCRes1->Text  = MyFloatToStr(g_tCalib.NtcRes.y1, "%0.3f");
	EditNTCRes2->Text  = MyFloatToStr(g_tCalib.NtcRes.y2, "%0.3f");
	EditNTCRes3->Text  = MyFloatToStr(g_tCalib.NtcRes.y3, "%0.3f");
	EditNTCRes4->Text  = MyFloatToStr(g_tCalib.NtcRes.y4, "%0.3f");

	EditNTCResAdc1->Text  = MyFloatToStr(g_tCalib.NtcRes.x1, "%0.3f");
	EditNTCResAdc2->Text  = MyFloatToStr(g_tCalib.NtcRes.x2, "%0.3f");
	EditNTCResAdc3->Text  = MyFloatToStr(g_tCalib.NtcRes.x3, "%0.3f");
	EditNTCResAdc4->Text  = MyFloatToStr(g_tCalib.NtcRes.x4, "%0.3f");

	/***********/

	EditTVCC_X1->Text = MyFloatToStr(g_tCalib.TVCCSet.x1, "%0.0f");
	EditTVCC_X2->Text = MyFloatToStr(g_tCalib.TVCCSet.x2, "%0.0f");

	EditTVCC_Y1->Text = MyFloatToStr(g_tCalib.TVCCSet.y1, "%0.3f");
	EditTVCC_Y2->Text = MyFloatToStr(g_tCalib.TVCCSet.y2, "%0.3f");

	EditDACVolt_X1->Text = IntToStr(g_tCalib.Dac10V.x1);
	EditDACVolt_X2->Text = IntToStr(g_tCalib.Dac10V.x2);
	EditDACVolt_X3->Text = IntToStr(g_tCalib.Dac10V.x3);
	EditDACVolt_X4->Text = IntToStr(g_tCalib.Dac10V.x4);

	EditDACVolt_Y1->Text = IntToStr(g_tCalib.Dac10V.y1);
	EditDACVolt_Y2->Text = IntToStr(g_tCalib.Dac10V.y2);
	EditDACVolt_Y3->Text = IntToStr(g_tCalib.Dac10V.y3);
	EditDACVolt_Y4->Text = IntToStr(g_tCalib.Dac10V.y4);

	EditDACCurr_X1->Text = IntToStr(g_tCalib.Dac20mA.x1);
	EditDACCurr_X2->Text = IntToStr(g_tCalib.Dac20mA.x2);
	EditDACCurr_X3->Text = IntToStr(g_tCalib.Dac20mA.x3);
	EditDACCurr_X4->Text = IntToStr(g_tCalib.Dac20mA.x4);

	EditDACCurr_Y1->Text = IntToStr(g_tCalib.Dac20mA.y1);
	EditDACCurr_Y2->Text = IntToStr(g_tCalib.Dac20mA.y2);
	EditDACCurr_Y3->Text = IntToStr(g_tCalib.Dac20mA.y3);
	EditDACCurr_Y4->Text = IntToStr(g_tCalib.Dac20mA.y4);
}
//---------------------------------------------------------------------------


void __fastcall TFormCalib::Button39Click(TObject *Sender)
{
	float x, y;
	AnsiString s1;
	uint16_t reg_buf[4];
	uint8_t buf[4];

	x = MyStrToFloat(EditNTCResAdc3->Text);
	y = MyStrToFloat(EditNTCRes3->Text);

	s1.sprintf("NTC电阻准点3: x3=%0.3f, y3=%0.3f", x, y);
	Memo1->Lines->Add(s1);

	FloatToBEBuf(x, buf);  reg_buf[0] = (buf[0] << 8) + buf[1]; reg_buf[1] = (buf[2] << 8) + buf[3];
	FloatToBEBuf(y, buf);  reg_buf[2] = (buf[0] << 8) + buf[1]; reg_buf[3] = (buf[2] << 8) + buf[3];
	H7_WriteMutiRegisters(REG03_CALIB_NTC_RES_X3, 4, reg_buf);
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::Button40Click(TObject *Sender)
{
	float x, y;
	AnsiString s1;
	uint16_t reg_buf[4];
	uint8_t buf[4];

	x = MyStrToFloat(EditNTCResAdc4->Text);
	y = MyStrToFloat(EditNTCRes4->Text);

	s1.sprintf("NTC电阻准点4: x4=%0.3f, y4=%0.3f", x, y);
	Memo1->Lines->Add(s1);

	FloatToBEBuf(x, buf);  reg_buf[0] = (buf[0] << 8) + buf[1]; reg_buf[1] = (buf[2] << 8) + buf[3];
	FloatToBEBuf(y, buf);  reg_buf[2] = (buf[0] << 8) + buf[1]; reg_buf[3] = (buf[2] << 8) + buf[3];
	H7_WriteMutiRegisters(REG03_CALIB_NTC_RES_X4, 4, reg_buf);
}
//---------------------------------------------------------------------------


void __fastcall TFormCalib::FormCreate(TObject *Sender)
{
	bsp_AddLog("FormCalib Create Begin");

	bsp_AddLog("FormCalib Create End");
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::ButtonCH1_R1_1Click(TObject *Sender)
{
	float x1, y1;
	AnsiString s1;
	uint16_t reg_buf[8];
	uint8_t buf[4];
	TButton *pBtn = (TButton *)Sender;

	TEdit *pEditVolt[8] = {
		EditCH1R1Volt1, EditCH1R2Volt1, EditCH1R3Volt1, EditCH1R4Volt1,
		EditCH1R5Volt1, EditCH1R6Volt1, EditCH1R7Volt1, EditCH1R8Volt1
	};
	TEdit *pEditVoltAdc[8] = {
		EditCH1R1VoltAdc1, EditCH1R2VoltAdc1, EditCH1R3VoltAdc1, EditCH1R4VoltAdc1,
		EditCH1R5VoltAdc1, EditCH1R6VoltAdc1, EditCH1R7VoltAdc1, EditCH1R8VoltAdc1
	};

	x1 = MyStrToFloat(pEditVoltAdc[pBtn->Tag]->Text);
	y1 = MyStrToFloat(pEditVolt[pBtn->Tag]->Text);

	s1.sprintf("CH1 R%d 电压校准点1: x1=%0.3f, y1=%0.3f", pBtn->Tag + 1, x1, y1);
	Memo1->Lines->Add(s1);

	FloatToBEBuf(x1, buf); reg_buf[0] = (buf[0] << 8) + buf[1]; reg_buf[1] = (buf[2] << 8) + buf[3];
	FloatToBEBuf(y1, buf); reg_buf[2] = (buf[0] << 8) + buf[1]; reg_buf[3] = (buf[2] << 8) + buf[3];

	H7_WriteMutiRegisters(REG03_CALIB_CH1_R1_X1 + pBtn->Tag * 8, 4, reg_buf);
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::ButtonCH1_R1_2Click(TObject *Sender)
{
	float x1, y1;
	AnsiString s1;
	uint16_t reg_buf[8];
	uint8_t buf[4];
	TButton *pBtn = (TButton *)Sender;

	TEdit *pEditVolt[8] = {
		EditCH1R1Volt2, EditCH1R2Volt2, EditCH1R3Volt2, EditCH1R4Volt2,
		EditCH1R5Volt2, EditCH1R6Volt2, EditCH1R7Volt2, EditCH1R8Volt2
	};
	TEdit *pEditVoltAdc[8] = {
		EditCH1R1VoltAdc2, EditCH1R2VoltAdc2, EditCH1R3VoltAdc2, EditCH1R4VoltAdc2,
		EditCH1R5VoltAdc2, EditCH1R6VoltAdc2, EditCH1R7VoltAdc2, EditCH1R8VoltAdc2
	};

	x1 = MyStrToFloat(pEditVoltAdc[pBtn->Tag]->Text);
	y1 = MyStrToFloat(pEditVolt[pBtn->Tag]->Text);

	s1.sprintf("CH1 R%d 电压校准点2: x1=%0.3f, y1=%0.3f", pBtn->Tag + 1, x1, y1);
	Memo1->Lines->Add(s1);

	FloatToBEBuf(x1, buf); reg_buf[0] = (buf[0] << 8) + buf[1]; reg_buf[1] = (buf[2] << 8) + buf[3];
	FloatToBEBuf(y1, buf); reg_buf[2] = (buf[0] << 8) + buf[1]; reg_buf[3] = (buf[2] << 8) + buf[3];

	H7_WriteMutiRegisters(REG03_CALIB_CH1_R1_X2 + pBtn->Tag * 8, 4, reg_buf);
}
//---------------------------------------------------------------------------


void __fastcall TFormCalib::ButtonCH2_R1_1Click(TObject *Sender)
{
	float x1, y1;
	AnsiString s1;
	uint16_t reg_buf[8];
	uint8_t buf[4];
	TButton *pBtn = (TButton *)Sender;

	TEdit *pEditVolt[8] = {
		EditCH2R1Volt1, EditCH2R2Volt1, EditCH2R3Volt1, EditCH2R4Volt1,
		EditCH2R5Volt1, EditCH2R6Volt1, EditCH2R7Volt1, EditCH2R8Volt1
	};
	TEdit *pEditVoltAdc[8] = {
		EditCH2R1VoltAdc1, EditCH2R2VoltAdc1, EditCH2R3VoltAdc1, EditCH2R4VoltAdc1,
		EditCH2R5VoltAdc1, EditCH2R6VoltAdc1, EditCH2R7VoltAdc1, EditCH2R8VoltAdc1
	};

	x1 = MyStrToFloat(pEditVoltAdc[pBtn->Tag]->Text);
	y1 = MyStrToFloat(pEditVolt[pBtn->Tag]->Text);

	s1.sprintf("CH2 R%d 电压校准点1: x1=%0.3f, y1=%0.3f", pBtn->Tag + 1, x1, y1);
	Memo1->Lines->Add(s1);

	FloatToBEBuf(x1, buf); reg_buf[0] = (buf[0] << 8) + buf[1]; reg_buf[1] = (buf[2] << 8) + buf[3];
	FloatToBEBuf(y1, buf); reg_buf[2] = (buf[0] << 8) + buf[1]; reg_buf[3] = (buf[2] << 8) + buf[3];

	H7_WriteMutiRegisters(REG03_CALIB_CH2_R1_X1 + pBtn->Tag * 8, 4, reg_buf);
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::ButtonCH2_R1_2Click(TObject *Sender)
{
	float x1, y1;
	AnsiString s1;
	uint16_t reg_buf[8];
	uint8_t buf[4];
	TButton *pBtn = (TButton *)Sender;

	TEdit *pEditVolt[8] = {
		EditCH2R1Volt2, EditCH2R2Volt2, EditCH2R3Volt2, EditCH2R4Volt2,
		EditCH2R5Volt2, EditCH2R6Volt2, EditCH2R7Volt2, EditCH2R8Volt2
	};
	TEdit *pEditVoltAdc[8] = {
		EditCH2R1VoltAdc2, EditCH2R2VoltAdc2, EditCH2R3VoltAdc2, EditCH2R4VoltAdc2,
		EditCH2R5VoltAdc2, EditCH2R6VoltAdc2, EditCH2R7VoltAdc2, EditCH2R8VoltAdc2
	};

	x1 = MyStrToFloat(pEditVoltAdc[pBtn->Tag]->Text);
	y1 = MyStrToFloat(pEditVolt[pBtn->Tag]->Text);

	s1.sprintf("CH1 R%d 电压校准点2: x1=%0.3f, y1=%0.3f", pBtn->Tag + 1, x1, y1);
	Memo1->Lines->Add(s1);

	FloatToBEBuf(x1, buf); reg_buf[0] = (buf[0] << 8) + buf[1]; reg_buf[1] = (buf[2] << 8) + buf[3];
	FloatToBEBuf(y1, buf); reg_buf[2] = (buf[0] << 8) + buf[1]; reg_buf[3] = (buf[2] << 8) + buf[3];

	H7_WriteMutiRegisters(REG03_CALIB_CH2_R1_X2 + pBtn->Tag * 8, 4, reg_buf);
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::CheckBoxCalibEnableClick(TObject *Sender)
{
	if (CheckBoxCalibEnable->Checked)
	{
		H7_WriteRegister(REG03_CALIB_KEY, 1);
	}
	else
	{
	 	H7_WriteRegister(REG03_CALIB_KEY, 0);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::ButtonSaveCalibClick(TObject *Sender)
{
	int i;
	char buf[256];
	uint16_t reg_addr;
	float reg_value;
	int16_t reg_value16;

	// 判断是否读取了参数再备份
	if (StrToInt(EditDACVolt_Y2->Text) == 0 || StrToInt(EditDACVolt_Y3->Text) == 0)
	{
		Memo1->Lines->Clear();

		Memo1->Lines->Add("请先执行读校准参数再备份");
		return;
	}

	reg_addr = 0xC000;

	Memo1->Lines->Clear();

	Memo1->Lines->Add("--写模拟量校准参数");
	Memo1->Lines->Add("function write_calib(void)");

	for (i = 0; i < 8; i++)
	{
		reg_value = g_tCalib.CH1[i].x1;
		sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --CH1[%d].x1", reg_addr, reg_value, i);
		Memo1->Lines->Add(buf); reg_addr += 2;

		reg_value = g_tCalib.CH1[i].y1;
		sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --CH1[%d].y1", reg_addr, reg_value, i);
		Memo1->Lines->Add(buf); reg_addr += 2;

		reg_value = g_tCalib.CH1[i].x2;
		sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --CH1[%d].x2", reg_addr, reg_value, i);
		Memo1->Lines->Add(buf); reg_addr += 2;

		reg_value = g_tCalib.CH1[i].y2;
		sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --CH1[%d].y2", reg_addr, reg_value, i);
		Memo1->Lines->Add(buf); reg_addr += 2;

		Memo1->Lines->Add("");
	}

	for (i = 0; i < 8; i++)
	{
		reg_value = g_tCalib.CH2[i].x1;
		sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --CH2[%d].x1", reg_addr, reg_value, i);
		Memo1->Lines->Add(buf); reg_addr += 2;

		reg_value = g_tCalib.CH2[i].y1;
		sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --CH2[%d].y1", reg_addr, reg_value, i);
		Memo1->Lines->Add(buf); reg_addr += 2;

		reg_value = g_tCalib.CH2[i].x2;
		sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --CH2[%d].x2", reg_addr, reg_value, i);
		Memo1->Lines->Add(buf); reg_addr += 2;

		reg_value = g_tCalib.CH2[i].y2;
		sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --CH2[%d].y2", reg_addr, reg_value, i);
		Memo1->Lines->Add(buf); reg_addr += 2;

		Memo1->Lines->Add("");
	}

//	g_tCalib.LoadVolt.x1 = BEBufToFloat(p); p += 4;
//	g_tCalib.LoadVolt.y1 = BEBufToFloat(p); p += 4;
//	g_tCalib.LoadVolt.x2 = BEBufToFloat(p); p += 4;
//	g_tCalib.LoadVolt.y2 = BEBufToFloat(p); p += 4;
	reg_value = g_tCalib.LoadVolt.x1;
	sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --LoadVolt.x1", reg_addr, reg_value);
	Memo1->Lines->Add(buf); reg_addr += 2;

	reg_value = g_tCalib.LoadVolt.y1;
	sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --LoadVolt.y1", reg_addr, reg_value);
	Memo1->Lines->Add(buf); reg_addr += 2;

	reg_value = g_tCalib.LoadVolt.x2;
	sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --LoadVolt.x2", reg_addr, reg_value);
	Memo1->Lines->Add(buf); reg_addr += 2;

	reg_value = g_tCalib.LoadVolt.y2;
	sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --LoadVolt.y2", reg_addr, reg_value);
	Memo1->Lines->Add(buf); reg_addr += 2;

	Memo1->Lines->Add("");

//	g_tCalib.LoadCurr[0].x1 = BEBufToFloat(p); p += 4;
//	g_tCalib.LoadCurr[0].y1 = BEBufToFloat(p); p += 4;
//	g_tCalib.LoadCurr[0].x2 = BEBufToFloat(p); p += 4;
//	g_tCalib.LoadCurr[0].y2 = BEBufToFloat(p); p += 4;
//	g_tCalib.LoadCurr[0].x3 = BEBufToFloat(p); p += 4;
//	g_tCalib.LoadCurr[0].y3 = BEBufToFloat(p); p += 4;
//	g_tCalib.LoadCurr[0].x4 = BEBufToFloat(p); p += 4;
//	g_tCalib.LoadCurr[0].y4 = BEBufToFloat(p); p += 4;

//	g_tCalib.LoadCurr[1].x1 = BEBufToFloat(p); p += 4;
//	g_tCalib.LoadCurr[1].y1 = BEBufToFloat(p); p += 4;
//	g_tCalib.LoadCurr[1].x2 = BEBufToFloat(p); p += 4;
//	g_tCalib.LoadCurr[1].y2 = BEBufToFloat(p); p += 4;
//	g_tCalib.LoadCurr[1].x3 = BEBufToFloat(p); p += 4;
//	g_tCalib.LoadCurr[1].y3 = BEBufToFloat(p); p += 4;
//	g_tCalib.LoadCurr[1].x4 = BEBufToFloat(p); p += 4;
//	g_tCalib.LoadCurr[1].y4 = BEBufToFloat(p); p += 4;
	for (i = 0; i < 2; i++)
	{
		reg_value = g_tCalib.LoadCurr[i].x1;
		sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --LoadCurr[%d].x1", reg_addr, reg_value, i);
		Memo1->Lines->Add(buf); reg_addr += 2;
		reg_value = g_tCalib.LoadCurr[i].y1;
		sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --LoadCurr[%d].y1", reg_addr, reg_value, i);
		Memo1->Lines->Add(buf); reg_addr += 2;

		reg_value = g_tCalib.LoadCurr[i].x2;
		sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --LoadCurr[%d].x2", reg_addr, reg_value, i);
		Memo1->Lines->Add(buf); reg_addr += 2;
		reg_value = g_tCalib.LoadCurr[i].y2;
		sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --LoadCurr[%d].y2", reg_addr, reg_value, i);
		Memo1->Lines->Add(buf); reg_addr += 2;

		reg_value = g_tCalib.LoadCurr[i].x3;
		sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --LoadCurr[%d].x3", reg_addr, reg_value, i);
		Memo1->Lines->Add(buf); reg_addr += 2;
		reg_value = g_tCalib.LoadCurr[i].y3;
		sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --LoadCurr[%d].y3", reg_addr, reg_value, i);
		Memo1->Lines->Add(buf); reg_addr += 2;

		reg_value = g_tCalib.LoadCurr[i].x4;
		sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --LoadCurr[%d].x4", reg_addr, reg_value, i);
		Memo1->Lines->Add(buf); reg_addr += 2;
		reg_value = g_tCalib.LoadCurr[i].y4;
		sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --LoadCurr[%d].y4", reg_addr, reg_value, i);
		Memo1->Lines->Add(buf); reg_addr += 2;

		Memo1->Lines->Add("");
	}

//	g_tCalib.TVCCVolt.x1 = BEBufToFloat(p); p += 4;
//	g_tCalib.TVCCVolt.y1 = BEBufToFloat(p); p += 4;
//	g_tCalib.TVCCVolt.x2 = BEBufToFloat(p); p += 4;
//	g_tCalib.TVCCVolt.y2 = BEBufToFloat(p); p += 4;
	reg_value = g_tCalib.TVCCVolt.x1;
	sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --TVCCVolt.x1", reg_addr, reg_value);
	Memo1->Lines->Add(buf); reg_addr += 2;

	reg_value = g_tCalib.TVCCVolt.y1;
	sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --TVCCVolt.y1", reg_addr, reg_value);
	Memo1->Lines->Add(buf); reg_addr += 2;

	reg_value = g_tCalib.TVCCVolt.x2;
	sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --TVCCVolt.x2", reg_addr, reg_value);
	Memo1->Lines->Add(buf); reg_addr += 2;

	reg_value = g_tCalib.TVCCVolt.y2;
	sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --TVCCVolt.y2", reg_addr, reg_value);
	Memo1->Lines->Add(buf); reg_addr += 2;

	Memo1->Lines->Add("");

//	g_tCalib.TVCCCurr.x1 = BEBufToFloat(p); p += 4;
//	g_tCalib.TVCCCurr.y1 = BEBufToFloat(p); p += 4;
//	g_tCalib.TVCCCurr.x2 = BEBufToFloat(p); p += 4;
//	g_tCalib.TVCCCurr.y2 = BEBufToFloat(p); p += 4;
//	g_tCalib.TVCCCurr.x3 = BEBufToFloat(p); p += 4;
//	g_tCalib.TVCCCurr.y3 = BEBufToFloat(p); p += 4;
//	g_tCalib.TVCCCurr.x4 = BEBufToFloat(p); p += 4;
//	g_tCalib.TVCCCurr.y4 = BEBufToFloat(p); p += 4;
	reg_value = g_tCalib.TVCCCurr.x1;
	sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --TVCCCurr.x1", reg_addr, reg_value);
	Memo1->Lines->Add(buf); reg_addr += 2;
	reg_value = g_tCalib.TVCCCurr.y1;
	sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --TVCCCurr.y1", reg_addr, reg_value);
	Memo1->Lines->Add(buf); reg_addr += 2;

	reg_value = g_tCalib.TVCCCurr.x2;
	sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --TVCCCurr.x2", reg_addr, reg_value);
	Memo1->Lines->Add(buf); reg_addr += 2;
	reg_value = g_tCalib.TVCCCurr.y2;
	sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --TVCCCurr.y2", reg_addr, reg_value);
	Memo1->Lines->Add(buf); reg_addr += 2;

	reg_value = g_tCalib.TVCCCurr.x3;
	sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --TVCCCurr.x3", reg_addr, reg_value);
	Memo1->Lines->Add(buf); reg_addr += 2;
	reg_value = g_tCalib.TVCCCurr.y3;
	sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --TVCCCurr.y3", reg_addr, reg_value);
	Memo1->Lines->Add(buf); reg_addr += 2;

	reg_value = g_tCalib.TVCCCurr.x4;
	sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --TVCCCurr.x4", reg_addr, reg_value);
	Memo1->Lines->Add(buf); reg_addr += 2;
	reg_value = g_tCalib.TVCCCurr.y4;
	sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --TVCCCurr.y4", reg_addr, reg_value);
	Memo1->Lines->Add(buf); reg_addr += 2;

	Memo1->Lines->Add("");

//	g_tCalib.TVCCSet.x1 = BEBufToFloat(p); p += 4;
//	g_tCalib.TVCCSet.y1 = BEBufToFloat(p); p += 4;
//	g_tCalib.TVCCSet.x2 = BEBufToFloat(p); p += 4;
//	g_tCalib.TVCCSet.y2 = BEBufToFloat(p); p += 4;
	reg_value = g_tCalib.TVCCSet.x1;
	sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --TVCCSet.x1", reg_addr, reg_value);
	Memo1->Lines->Add(buf); reg_addr += 2;
	reg_value = g_tCalib.TVCCSet.y1;
	sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --TVCCSet.y1", reg_addr, reg_value);
	Memo1->Lines->Add(buf); reg_addr += 2;

	reg_value = g_tCalib.TVCCSet.x2;
	sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --TVCCSet.x2", reg_addr, reg_value);
	Memo1->Lines->Add(buf); reg_addr += 2;
	reg_value = g_tCalib.TVCCSet.y2;
	sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --TVCCSet.y2", reg_addr, reg_value);
	Memo1->Lines->Add(buf); reg_addr += 2;

	Memo1->Lines->Add("");

//	g_tCalib.Dac10V.x1 = BEBufToUint16(p); p += 2;
//	g_tCalib.Dac10V.y1 = (int16_t)BEBufToUint16(p); p += 2;
//	g_tCalib.Dac10V.x2 = BEBufToUint16(p); p += 2;
//	g_tCalib.Dac10V.y2 = (int16_t)BEBufToUint16(p); p += 2;
//	g_tCalib.Dac10V.x3 = BEBufToUint16(p); p += 2;
//	g_tCalib.Dac10V.y3 = (int16_t)BEBufToUint16(p); p += 2;
//	g_tCalib.Dac10V.x4 = BEBufToUint16(p); p += 2;
//	g_tCalib.Dac10V.y4 = (int16_t)BEBufToUint16(p); p += 2;
	reg_value16 = g_tCalib.Dac10V.x1;
	sprintf(buf, "  write_reg16(0x%04X, %d) --Dac10V.x1", reg_addr, reg_value16);
	Memo1->Lines->Add(buf); reg_addr += 1;
	reg_value16 = g_tCalib.Dac10V.y1;
	sprintf(buf, "  write_reg16(0x%04X, %d) --Dac10V.y1 (mV)", reg_addr, reg_value16);
	Memo1->Lines->Add(buf); reg_addr += 1;

	reg_value16 = g_tCalib.Dac10V.x2;
	sprintf(buf, "  write_reg16(0x%04X, %d) --Dac10V.x2", reg_addr, reg_value16);
	Memo1->Lines->Add(buf); reg_addr += 1;
	reg_value16 = g_tCalib.Dac10V.y2;
	sprintf(buf, "  write_reg16(0x%04X, %d) --Dac10V.y2 (mV)", reg_addr, reg_value16);
	Memo1->Lines->Add(buf); reg_addr += 1;

	reg_value16 = g_tCalib.Dac10V.x3;
	sprintf(buf, "  write_reg16(0x%04X, %d) --Dac10V.x3", reg_addr, reg_value16);
	Memo1->Lines->Add(buf); reg_addr += 1;
	reg_value16 = g_tCalib.Dac10V.y3;
	sprintf(buf, "  write_reg16(0x%04X, %d) --Dac10V.y3 (mV)", reg_addr, reg_value16);
	Memo1->Lines->Add(buf); reg_addr += 1;

	reg_value16 = g_tCalib.Dac10V.x4;
	sprintf(buf, "  write_reg16(0x%04X, %d) --Dac10V.x4", reg_addr, reg_value16);
	Memo1->Lines->Add(buf); reg_addr += 1;
	reg_value16 = g_tCalib.Dac10V.y4;
	sprintf(buf, "  write_reg16(0x%04X, %d) --Dac10V.y4 (mV)", reg_addr, reg_value16);
	Memo1->Lines->Add(buf); reg_addr += 1;

	Memo1->Lines->Add("");

//	g_tCalib.Dac20mA.x1 = BEBufToUint16(p); p += 2;
//	g_tCalib.Dac20mA.y1 = (int16_t)BEBufToUint16(p); p += 2;
//	g_tCalib.Dac20mA.x2 = BEBufToUint16(p); p += 2;
//	g_tCalib.Dac20mA.y2 = (int16_t)BEBufToUint16(p); p += 2;
//	g_tCalib.Dac20mA.x3 = BEBufToUint16(p); p += 2;
//	g_tCalib.Dac20mA.y3 = (int16_t)BEBufToUint16(p); p += 2;
//	g_tCalib.Dac20mA.x4 = BEBufToUint16(p); p += 2;
//	g_tCalib.Dac20mA.y4 = (int16_t)BEBufToUint16(p); p += 2;
	reg_value16 = g_tCalib.Dac20mA.x1;
	sprintf(buf, "  write_reg16(0x%04X, %d) --Dac20mA.x1", reg_addr, reg_value16);
	Memo1->Lines->Add(buf); reg_addr += 1;
	reg_value16 = g_tCalib.Dac20mA.y1;
	sprintf(buf, "  write_reg16(0x%04X, %d) --Dac20mA.y1 (uA)", reg_addr, reg_value16);
	Memo1->Lines->Add(buf); reg_addr += 1;

	reg_value16 = g_tCalib.Dac20mA.x2;
	sprintf(buf, "  write_reg16(0x%04X, %d) --Dac20mA.x2", reg_addr, reg_value16);
	Memo1->Lines->Add(buf); reg_addr += 1;
	reg_value16 = g_tCalib.Dac20mA.y2;
	sprintf(buf, "  write_reg16(0x%04X, %d) --Dac20mA.y2 (uA)", reg_addr, reg_value16);
	Memo1->Lines->Add(buf); reg_addr += 1;

	reg_value16 = g_tCalib.Dac20mA.x3;
	sprintf(buf, "  write_reg16(0x%04X, %d) --Dac20mA.x3", reg_addr, reg_value16);
	Memo1->Lines->Add(buf); reg_addr += 1;
	reg_value16 = g_tCalib.Dac20mA.y3;
	sprintf(buf, "  write_reg16(0x%04X, %d) --Dac20mA.y3 (uA)", reg_addr, reg_value16);
	Memo1->Lines->Add(buf); reg_addr += 1;

	reg_value16 = g_tCalib.Dac20mA.x4;
	sprintf(buf, "  write_reg16(0x%04X, %d) --Dac20mA.x4", reg_addr, reg_value16);
	Memo1->Lines->Add(buf); reg_addr += 1;
	reg_value16 = g_tCalib.Dac20mA.y4;
	sprintf(buf, "  write_reg16(0x%04X, %d) --Dac20mA.y4 (uA)", reg_addr, reg_value16);
	Memo1->Lines->Add(buf); reg_addr += 1;

	Memo1->Lines->Add("");

//	g_tCalib.NtcRes.x1 = BEBufToFloat(p); p += 4;
//	g_tCalib.NtcRes.y1 = BEBufToFloat(p); p += 4;
//	g_tCalib.NtcRes.x2 = BEBufToFloat(p); p += 4;
//	g_tCalib.NtcRes.y2 = BEBufToFloat(p); p += 4;
//	g_tCalib.NtcRes.x3 = BEBufToFloat(p); p += 4;
//	g_tCalib.NtcRes.y3 = BEBufToFloat(p); p += 4;
//	g_tCalib.NtcRes.x4 = BEBufToFloat(p); p += 4;
//	g_tCalib.NtcRes.y4 = BEBufToFloat(p); p += 4;
	reg_value = g_tCalib.NtcRes.x1;
	sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --NtcRes.x1", reg_addr, reg_value);
	Memo1->Lines->Add(buf); reg_addr += 2;
	reg_value = g_tCalib.NtcRes.y1;
	sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --NtcRes.y1", reg_addr, reg_value);
	Memo1->Lines->Add(buf); reg_addr += 2;

	reg_value = g_tCalib.NtcRes.x2;
	sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --NtcRes.x2", reg_addr, reg_value);
	Memo1->Lines->Add(buf); reg_addr += 2;
	reg_value = g_tCalib.NtcRes.y2;
	sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --NtcRes.y2", reg_addr, reg_value);
	Memo1->Lines->Add(buf); reg_addr += 2;

	reg_value = g_tCalib.NtcRes.x3;
	sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --NtcRes.x3", reg_addr, reg_value);
	Memo1->Lines->Add(buf); reg_addr += 2;
	reg_value = g_tCalib.NtcRes.y3;
	sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --NtcRes.y3", reg_addr, reg_value);
	Memo1->Lines->Add(buf); reg_addr += 2;

	reg_value = g_tCalib.NtcRes.x4;
	sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --NtcRes.x4", reg_addr, reg_value);
	Memo1->Lines->Add(buf); reg_addr += 2;
	reg_value = g_tCalib.NtcRes.y4;
	sprintf(buf, "  write_regfloat(0x%04X, %0.3f) --NtcRes.y4", reg_addr, reg_value);
	Memo1->Lines->Add(buf); reg_addr += 2;

	Memo1->Lines->Add("");

	Memo1->Lines->Add("  save_param()	--保存参数到eeprom");
	Memo1->Lines->Add("end");
	Memo1->Lines->Add("");
	Memo1->Lines->Add("write_calib()");
	Memo1->Lines->Add("beep()");
	Memo1->Lines->Add("print(\"写入模拟量校准参数成功\")");

	/* 保存到文件 */
	{
		AnsiString now;
		String tar;

		now = Now().FormatString("YYYYMMDD_HH_");

		tar = AppExePath() + "\\Backup\\" + now + "calib_param.lua";

		Memo1->Lines->SaveToFile(tar);

		Memo1->Lines->Add("");
		Memo1->Lines->Add("恢复参数的脚本已保存到 :" + tar);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormCalib::ButtonLoadCalibClick(TObject *Sender)
{
	OpenDialog1->InitialDir = AppExePath() + "\\Backup\\";
	if (OpenDialog1->Execute())
	{
		Memo1->Lines->LoadFromFile(OpenDialog1->FileName);

		AnsiString s;

		s = Memo1->Lines->Text;
		FormTcp->DoLuaSend64H(s);
	}
}
//---------------------------------------------------------------------------

