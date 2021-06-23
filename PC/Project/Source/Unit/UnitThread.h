//---------------------------------------------------------------------------

#ifndef UnitThreadH
#define UnitThreadH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdThreadComponent.hpp>
#include <IdComponent.hpp>
#include <IdUDPBase.hpp>
#include <IdUDPClient.hpp>

#include "udp_modbus_addr.h"
#include <Vcl.ExtCtrls.hpp>

#define MAX_NUM		200

#define UPGRADE_PACKET_LEN	512

#define LUA_DATA_MAX_SIZE	32*1024*1024
typedef struct
{
	uint16_t Func;
	uint8_t DataBuf[LUA_DATA_MAX_SIZE];	// Lua程序数据体
	uint32_t DataLen;	// Lua程序长度
	uint32_t Offset;	// 偏移地址
	uint16_t PackagLen;	// 本包长度

	uint32_t FlashBaseAddr;     // FLASH基地址
}LUA_DOWNLOAD_T;

//---------------------------------------------------------------------------
class TFormTcp : public TForm
{
__published:	// IDE-managed Components
	TIdThreadComponent *Thread1;
	TIdUDPClient *UDP1;
	TTimer *TimerUDP;
	TIdThreadComponent *IdThreadComponent1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Thread1Run(TIdThreadComponent *Sender);
	void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormTcp(TComponent* Owner);

	void __fastcall CommTask(void);
	void __fastcall CommTaskLoop(void);

	void __fastcall SendTcpCmd(uint32_t ip, uint32_t tcp_port);
	void __fastcall SendUdpCmd(uint32_t ip, uint32_t port, uint8_t * cmd_buf, uint16_t cmd_len);
	void __fastcall SendUdpCmd2(AnsiString str_ip, uint32_t port, uint8_t * cmd_buf, uint16_t cmd_len);

	void __fastcall MODH_03H(uint8_t *_rx_buf, uint16_t _len);
	void __fastcall MODH_06H(uint8_t *_rx_buf, uint16_t _len);
	void __fastcall MODH_10H(uint8_t *_rx_buf, uint16_t _len);
	void __fastcall MODH_61H(uint8_t *_rx_buf, uint16_t _len);
	void __fastcall MODH_66H(uint8_t *_rx_buf, uint16_t _len);

	void __fastcall Sacn(void);
	void __fastcall UserCmd(void);
	void __fastcall DealRxData(void);
	void __fastcall DispUartData(void);

	void __fastcall UpdateChipFile(void);
	void __fastcall DownLuaFile(void);
	void __fastcall UpdateFirmware(void);
	void __fastcall ReadChipToFile(void);
	void __fastcall ReadScreen(void);
	void __fastcall TFormTcp::DoLuaSend64H(AnsiString s);
	void __fastcall TFormTcp::InitAndDoLuaSend64H(AnsiString s);

	int mUserCmdFlag;      // 1表示用户指令

	int mUserCmd;          // 表示将要发送的指令
	int mUserAddr;         // 表示临时发送的寄存器地址
	int mUserNum;         // 表示临时发送的寄存器个数
	int mUserValue;         // 表示临时发送的寄存器值

	uint8_t mCmd;
	uint16_t mRegAddr;
	uint16_t mRegNum;
	uint16_t mRegValue;
   //	TByteArray mTxBuf[256];
	uint8_t mTxBuf[256];

	//int mWaveTime;
  //	int mScaning;

	uint32_t mIP_List[1000]; /*　IP列表 */
	int mIP_Counter;     // IP个数

	int mScanStatus;
	int mScanAddr;

	int mTCPTimeout;

	uint32_t mTime1;

	PARAM_T mDevList[MAX_NUM];
	int mDevNum;

	float mAdcBuf1[256 * 1024];
	float mAdcBuf2[256 * 1024];
	uint16_t mWaveReg;
	uint32_t mLastTime;

	//int CanDrawWave1;
	int CanDrawWave2;

	LUA_DOWNLOAD_T mLua;

	int mUpgradeTime;	/* 升级时间 */
	uint16_t mBootStatus;

	int RecordID;

	uint32_t H60_ChEn;
	uint32_t H60_SampleSize;
	uint16_t H60_PackageLen;
	uint32_t H60_Offset;
	uint8_t H60_Ok;

	int mDispWriteRegister;

	int mReqCloseCom;	// 请求关闭串口

	int mNoAck06H;		// 1表示不要求应答， 用于虚拟按键 */
};

enum
{
	CMDS_READ_WAVE = 100,   // 废弃，保留
	CMDS_SCAN_DEV = 200,

	CMDS_DOWNLOAD_LUA = 300,

	CMDS_READ_AI	= 400,
	CMDS_READ_ADC	= 500,

	CMDS_SEND_03H = 1000,
	CMDS_SEND_06H = 1100,
	CMDS_SEND_10H = 1200,
	CMDS_SEND_0FH = 1300,

	CMDS_UPDATE_CHIP_FILE = 1400,
	CMDS_UPDATE_CHIP_FILE_ERR = 1498,
	CMDS_UPDATE_CHIP_FILE_OK = 1499,

	CMDS_SWD_READ_FLASH = 1500,
	CMDS_SWD_READ_FLASH_ERR = 1598,
	CMDS_SWD_READ_FLASH_OK = 1599,

	CMDS_PRO_UPGRADE  =	2000,     //程序升级状态机
	CMDS_PRO_UPGRADE_ERR = 2098,
	CMDS_PRO_UPGRADE_OK	= 2099,

	CMDS_READ_SCREEN = 2500,     // 读屏幕
	CMDS_READ_SCREEN_ERR = 2598,
	CMDS_READ_SCREEN_OK = 2599,

	CMDS_AUTO_WAVE = 3000,	// 61H自动上传波形

	CMDS_UDP_FIND = 4000,




};

/* 66H帧子功能码定义 */
enum
{
    H66_READ_MEM_INIT   = 0,    /* 读内存, */
    H66_READ_MEM        = 1,    /* 写内存 */
    H66_WRITE_MEM       = 2,    /* 写内存 */

    H66_READ_DISP_MEM   = 0x0100,    /* 读显存 */
};


//---------------------------------------------------------------------------
extern PACKAGE TFormTcp *FormTcp;
//---------------------------------------------------------------------------
#endif
