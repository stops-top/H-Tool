#include "USB_HID.h"
#include "UnitMain.h"

static HINSTANCE  s_HidDllInst;  // DLL句柄
static HINSTANCE  s_ApiDllInst;  // DLL句柄

BOOLEAN __stdcall (*HidD_GetAttributes) (HANDLE, PHIDD_ATTRIBUTES);
void __stdcall (*HidD_GetHidGuid) (LPGUID);
BOOLEAN __stdcall (*HidD_GetPreparsedData) (HANDLE, PHIDP_PREPARSED_DATA *);
BOOLEAN __stdcall (*HidD_FreePreparsedData) (PHIDP_PREPARSED_DATA);
//BOOLEAN __stdcall HidD_FlushQueue (HANDLE);
//BOOLEAN __stdcall HidD_GetConfiguration (HANDLE, PHIDD_CONFIGURATION, ULONG);
//BOOLEAN __stdcall HidD_SetConfiguration (HANDLE, PHIDD_CONFIGURATION, ULONG);
BOOLEAN __stdcall (*HidD_GetFeature) (HANDLE, PVOID, ULONG);
BOOLEAN __stdcall (*HidD_SetFeature) (HANDLE, PVOID, ULONG);
//BOOLEAN __stdcall HidD_GetNumInputBuffers (HANDLE, PULONG);
//BOOLEAN __stdcall HidD_SetNumInputBuffers (HANDLE, ULONG);
//BOOLEAN __stdcall HidD_GetPhysicalDescriptor (HANDLE, PVOID, ULONG);
//BOOLEAN __stdcall HidD_GetManufacturerString (HANDLE, PVOID, ULONG);
BOOLEAN __stdcall (*HidD_GetProductString) (HANDLE, PVOID, ULONG);
//BOOLEAN __stdcall HidD_GetIndexedString (HANDLE, ULONG, PVOID, ULONG);
//BOOLEAN __stdcall HidD_GetSerialNumberString (HANDLE, PVOID, ULONG);
NTSTATUS __stdcall (*HidP_GetCaps)(_HIDP_PREPARSED_DATA *,_HIDP_CAPS *);

USER_HID_T g_tHID;

// 动态载入dll
void LoadDll(void)
{
	s_HidDllInst = LoadLibrary(L"hid.dll");
	s_ApiDllInst = LoadLibrary(L"setupapi.dll");
}

// 卸载dll
void FreeDll(void)
{
	if (s_HidDllInst > 0)
	{
		FreeLibrary(s_HidDllInst);
	}
	if (s_ApiDllInst > 0)
	{
		FreeLibrary(s_ApiDllInst);
	}
}

// 查找hid.dll 中的函数地址
void FindDllFunc(void)
{
	(FARPROC &)HidD_GetAttributes                   = GetProcAddress(s_HidDllInst, "HidD_GetAttributes");
	(FARPROC &)HidD_GetHidGuid                      = GetProcAddress(s_HidDllInst, "HidD_GetHidGuid");
	(FARPROC &)HidD_GetPreparsedData                = GetProcAddress(s_HidDllInst, "HidD_GetPreparsedData");
	(FARPROC &)HidD_FreePreparsedData               = GetProcAddress(s_HidDllInst, "HidD_FreePreparsedData");
	//(FARPROC &)HidD_FlushQueue                      = GetProcAddress(s_HidDllInst, "HidD_FlushQueue");
	//(FARPROC &)HidD_GetConfiguration                = GetProcAddress(s_HidDllInst, "HidD_GetConfiguration");
	//(FARPROC &)HidD_SetConfiguration                = GetProcAddress(s_HidDllInst, "HidD_SetConfiguration");
	(FARPROC &)HidD_GetFeature                      = GetProcAddress(s_HidDllInst, "HidD_GetFeature");
	(FARPROC &)HidD_SetFeature                      = GetProcAddress(s_HidDllInst, "HidD_SetFeature");
	//(FARPROC &)HidD_GetNumInputBuffers              = GetProcAddress(s_HidDllInst, "HidD_GetNumInputBuffers");
	//(FARPROC &)HidD_SetNumInputBuffers              = GetProcAddress(s_HidDllInst, "HidD_SetNumInputBuffers");
	//(FARPROC &)HidD_GetPhysicalDescriptor           = GetProcAddress(s_HidDllInst, "HidD_GetPhysicalDescriptor");
	//(FARPROC &)HidD_GetManufacturerString           = GetProcAddress(s_HidDllInst, "HidD_GetManufacturerString");
	(FARPROC &)HidD_GetProductString                = GetProcAddress(s_HidDllInst, "HidD_GetProductString");
	//(FARPROC &)HidD_GetIndexedString                = GetProcAddress(s_HidDllInst, "HidD_GetIndexedString");
	//(FARPROC &)HidD_GetSerialNumberString           = GetProcAddress(s_HidDllInst, "HidD_GetSerialNumberString");
	(FARPROC &)HidP_GetCaps                         = GetProcAddress(s_HidDllInst, "HidP_GetCaps");
}

//int                                g_tHID.DevCount;
//int                                g_tHID.DevSelected;
//PSP_DEVICE_INTERFACE_DETAIL_DATA   g_tHID.DevDetailData[DEV_NUM];
//int                                g_tHID.DevDetailDataSz[DEV_NUM];
//int                                g_tHID.DevInputReportSz[DEV_NUM];
//int                                g_tHID.DevOutputReportSz[DEV_NUM];
//int                                g_tHID.DevFeatureReportSz[DEV_NUM];
//HANDLE                             g_tHID.DevHandle;
//OVERLAPPED                         DevOverlapped;
//BOOL                               g_tHID.DevReadPending;

/*
 *  HID Initialization
 *    Parameters:      None
 *    Return Value:    None
 */

void HID_Init() {
  int  i;

  g_tHID.DevCount = 0;

  g_tHID.DevSelected = -1;
  for (i = 0; i < DEV_NUM; i++) {
	g_tHID.DevDetailData[i] = NULL;
  }
}


/*
 *  HID Uninitialization
 *    Parameters:      None
 *    Return Value:    None
 */

void HID_UnInit() {
  int  i;

  for (i = 0; i < DEV_NUM; i++) {
	if (g_tHID.DevDetailData[i]) free(g_tHID.DevDetailData[i]);
  }
}


/*
 *  HID Find Devices
 *    Parameters:      None
 *    Return Value:    Number of Devices found
 */

int HID_FindDevices(void) {
  GUID                             HidGuid;
  HANDLE                           DevHandle;
  HDEVINFO                         DevInfo;
  SP_DEVICE_INTERFACE_DATA         DevData;
  PSP_DEVICE_INTERFACE_DETAIL_DATA DevDetail;
  PSP_DEVICE_INTERFACE_DETAIL_DATA DevDetailSelected;
	PHIDP_PREPARSED_DATA	          	PreparsedData;
//  [bcc32 Error] USB_HID.cpp(270): E2034 Cannot convert '_HIDP_PREPARSED_DATA * *' to '_HIDP_PREPARSED_DATA *'

  HIDP_CAPS	                       Capabilities;
  ULONG                            Length;
  int                              Index;
  int                              Sz;
  BOOL                             ok;

  /* Get GUID for all System HIDs */
  HidD_GetHidGuid(&HidGuid);

  /* Get Device Information for all present devices
	HDEVINFO SetupDiGetClassDevs(
	  _In_opt_ const GUID   *ClassGuid,  此GUID可标识一个设备安装类或一个设备接口类
	  _In_opt_       PCTSTR Enumerator,      过滤枚举的内容：如：PCI则只显示PCI设备
	  _In_opt_       HWND   hwndParent,
	  _In_           DWORD  Flags
	—）

	Flags 通过此参数来过滤指定的设备信息集中的设备。此参数可以是以下标志位中的一个或多个的按位或组合，更多有关标志位组合的信息，请参考备注部分。

DIGCF_ALLCLASSES
　　返回所有已安装设备的列表或所有设备接口类。

DIGCF_DEVICEINTERFACE
　　返回支持指定设备接口类的设备。如果Enumerators参数制定了设备的实例ID，那么必须在Flags参数中设置此标志位。

DIGCF_DEFAULT
　　对于指定的设备接口类，只返回与系统默认设备接口相关联的设备（如果已设置的话）。

DIGCF_PRESENT
　　只返回当前系统中存在的（已连接）设备。

DIGCF_PROFILE
　　只返回当前硬件列表中的一部分设备
	);
  */
  DevInfo = SetupDiGetClassDevs(&HidGuid,
                                NULL,
                                NULL,
								(DIGCF_PRESENT | DIGCF_DEVICEINTERFACE)   //只返回当前系统中存在的（已连接）设备。
                                );

  DevData.cbSize = sizeof(DevData);

  DevDetail = NULL;
  if (g_tHID.DevSelected != -1) {
    // Copy selected device data so we can find it in new list
	DevDetailSelected = (PSP_DEVICE_INTERFACE_DETAIL_DATA) malloc(g_tHID.DevDetailDataSz[g_tHID.DevSelected]);
	memcpy(DevDetailSelected, g_tHID.DevDetailData[g_tHID.DevSelected], g_tHID.DevDetailDataSz[g_tHID.DevSelected]);
  } else {
    DevDetailSelected = NULL;
  }

  for (Index = 0; Index < DEV_NUM; Index++) {
    if (g_tHID.DevDetailData[Index]) {
	  free(g_tHID.DevDetailData[Index]);
	  g_tHID.DevDetailData[Index] = NULL;
	}
  }

  Index = -1;

  /* Scan all Devices */
  g_tHID.DevCount = 0;
  do {

    Index++;

    /* Device Interface Element of a Device Information set */
    ok = SetupDiEnumDeviceInterfaces(DevInfo,
                                     0,
                                     &HidGuid,
                                     Index,
                                     &DevData
                                     );
    if (!ok) break;

    /* Get Device Interface Details - Get Length */
    ok = SetupDiGetDeviceInterfaceDetail(DevInfo,
                                         &DevData,
                                         NULL,
                                         0,
                                         &Length,
                                         NULL
                                         );

    /* Allocate memory for Device Detailed Data */
    if (DevDetail) free(DevDetail);
    DevDetail = (PSP_DEVICE_INTERFACE_DETAIL_DATA) malloc(Length);
	Sz = Length;

    /* Set cbSize in the DevDetail structure */
    DevDetail->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);

    /* Get Device Interface Details */
    ok = SetupDiGetDeviceInterfaceDetail(DevInfo,
                                         &DevData,
                                         DevDetail,
                                         Length,
                                         NULL,
                                         NULL
                                         );
    if (!ok) continue;

    /* Create File for Device Read/Write */
	DevHandle = CreateFile(DevDetail->DevicePath,
                           0,
                           FILE_SHARE_READ | FILE_SHARE_WRITE,
                           (LPSECURITY_ATTRIBUTES)NULL,
                           OPEN_EXISTING,
                           0,
                           NULL
                           );

	// 打印
	{
		AnsiString s;

		s = (AnsiString)DevDetail->DevicePath;
		Form1->MemoLuaOut->Lines->Add(s);
	}

    if (DevHandle == INVALID_HANDLE_VALUE) continue;

	/* Get Preparsed Data */
	ok = HidD_GetPreparsedData(DevHandle, &PreparsedData);
    if (!ok) continue;

    /* Get Device's Capabilities */
	HidP_GetCaps(PreparsedData, &Capabilities);

		// 打印
	{
		char buf[256];
		WCHAR  wbuf[128];

		sprintf(buf, "UsagePage = 0x%04X  Usage = 0x%04X",  Capabilities.UsagePage, Capabilities.Usage);
		Form1->MemoLuaOut->Lines->Add((AnsiString)buf);

		{
		  ok = HidD_GetProductString(DevHandle, wbuf, sizeof(wbuf));

		  if (ok) {
			for (int i = 0; i < 128; i++) {
			  buf[i] = (char)wbuf[i];
			}

			Form1->MemoLuaOut->Lines->Add((AnsiString)buf);
		  }
		}
		Form1->MemoLuaOut->Lines->Add("");
	}

    /* Free the PreparsedData */
    HidD_FreePreparsedData(PreparsedData);

	/* Remember Device Interface Detail Data for acceptable Devices */
	if ((Capabilities.UsagePage == 0xFF00) && (Capabilities.Usage == 0x0001)) {
      g_tHID.DevDetailData[g_tHID.DevCount] = DevDetail;
	  g_tHID.DevDetailDataSz[g_tHID.DevCount] = Sz;
      g_tHID.DevInputReportSz[g_tHID.DevCount] = Capabilities.InputReportByteLength;
	  g_tHID.DevOutputReportSz[g_tHID.DevCount] = Capabilities.OutputReportByteLength;
	  g_tHID.DevFeatureReportSz[g_tHID.DevCount] = Capabilities.FeatureReportByteLength;
	  if (DevDetailSelected)
		if (!wcscmp(DevDetailSelected->DevicePath, g_tHID.DevDetailData[g_tHID.DevCount]->DevicePath))
          g_tHID.DevSelected = g_tHID.DevCount;
      g_tHID.DevCount++;
      DevDetail = NULL;
    }

    CloseHandle (DevHandle);

  } while (g_tHID.DevCount < DEV_NUM);

  if (DevDetail) free(DevDetail);
  if (DevDetailSelected) free(DevDetailSelected);

  SetupDiDestroyDeviceInfoList (DevInfo);

  return (g_tHID.DevCount);
}


/*
 *  HID Get Name (Product String)
 *    Parameters:      num:   Device number
 *                     buf:   Pointer to buffer that receives data
 *                     sz:    Number of bytes to read
 *    Return Value:    TRUE - Success, FALSE - Error
 */

BOOL HID_GetName(int num, char *buf, int sz) {
  HANDLE DevHandle;
  WCHAR  wbuf[128];
  int    i;
  BOOL   ok;

  if (g_tHID.DevDetailData[num] == NULL) return (FALSE);

  /* Create File for Device Read/Write */
  DevHandle = CreateFile(g_tHID.DevDetailData[num]->DevicePath,
						 0,
						 FILE_SHARE_READ | FILE_SHARE_WRITE,
						 (LPSECURITY_ATTRIBUTES)NULL,
						 OPEN_EXISTING,
						 0,
						 NULL
						 );

  if (DevHandle == INVALID_HANDLE_VALUE) return (FALSE);

  ok = HidD_GetProductString(DevHandle, wbuf, sizeof(wbuf));

  if (ok) {
	for (i = 0; i < sz; i++) {
	  *buf++ = (char)wbuf[i];
	}
  }

  CloseHandle (DevHandle);

  return (ok);
}


/*
 *  HID Get Input Report Size
 *    Parameters:      num:   Device number
 *    Return Value:    Number of bytes for Input Report
 */

int HID_GetInputReportSize(int num) {

  return (g_tHID.DevInputReportSz[num]);
}


/*
 *  HID Get Output Report Size
 *    Parameters:      num:   Device number
 *    Return Value:    Number of bytes for Output Report
 */

int HID_GetOutputReportSize(int num) {

  return (g_tHID.DevOutputReportSz[num]);
}


/*
 *  HID Get Feature Report Size
 *    Parameters:      num:   Device number
 *    Return Value:    Number of bytes for Output Report
 */

int HID_GetFeatureReportSize(int num) {

  return (g_tHID.DevFeatureReportSz[num]);
}


/*
 *  HID Open
 *    Parameters:      num:   Device number
 *    Return Value:    TRUE - Success, FALSE - Error
 */

BOOL HID_Open(int num) {

  g_tHID.DevHandle = INVALID_HANDLE_VALUE;

  if (g_tHID.DevDetailData[num] == NULL) return (FALSE);

  /* Create File for Device Read/Write */
  g_tHID.DevHandle = CreateFile(g_tHID.DevDetailData[num]->DevicePath,
                         GENERIC_READ | GENERIC_WRITE,
                         FILE_SHARE_READ | FILE_SHARE_WRITE,
                         (LPSECURITY_ATTRIBUTES)NULL,
                         OPEN_EXISTING,
                         FILE_FLAG_OVERLAPPED,
                         NULL
                         );

  if (g_tHID.DevHandle == INVALID_HANDLE_VALUE) return (FALSE);

  g_tHID.DevSelected = num;
  memset(&g_tHID.DevOverlapped, 0, sizeof(OVERLAPPED));

  return (TRUE);
}


/*
 *  HID Open
 *    Parameters:      None
 *    Return Value:    Device number
 */

int HID_GetSelectedDevice(void) {

  return (g_tHID.DevSelected);
}


/*
 *  HID Close
 *    Parameters:      None
 *    Return Value:    None
 */

void HID_Close() {

  g_tHID.DevSelected = -1;
  CancelIo(g_tHID.DevHandle);
  g_tHID.DevReadPending  = FALSE;
  if (g_tHID.DevHandle != INVALID_HANDLE_VALUE) {
    CloseHandle(g_tHID.DevHandle);
    g_tHID.DevHandle = INVALID_HANDLE_VALUE;
  }
}


/*
 *  HID Read
 *    Parameters:      buf:   Pointer to buffer that receives data
 *                     sz:    Number of bytes to read
 *                     cnt:   Pointer to number of bytes read
 *    Return Value:    TRUE - Success, FALSE - Error
 */

BOOL HID_Read(BYTE *buf, DWORD sz, DWORD *cnt) {
  int last_err;

  /* Read from Device */
  if (!g_tHID.DevReadPending) {
	if (ReadFile(g_tHID.DevHandle, buf, sz, cnt, &g_tHID.DevOverlapped)) {
      return (TRUE);
    }
    g_tHID.DevReadPending = TRUE;
  }
  else {
	if (GetOverlappedResult(g_tHID.DevHandle, &g_tHID.DevOverlapped, cnt, FALSE)) {
      g_tHID.DevReadPending  = FALSE;
      return (TRUE);
    }
  }
  last_err = GetLastError();
  if ((last_err != ERROR_IO_INCOMPLETE) && (last_err != ERROR_IO_PENDING)) {
	g_tHID.DevReadPending  = FALSE;
	CancelIo(g_tHID.DevHandle);
    return (FALSE);
  }

  return (TRUE);
}


/*
 *  HID Write
 *    Parameters:      buf:   Pointer to buffer with data to write
 *                     sz:    Number of bytes to write
 *                     cnt:   Pointer to number of bytes written
 *    Return Value:    TRUE - Success, FALSE - Error
 */

BOOL HID_Write(BYTE *buf, DWORD sz, DWORD *cnt) {

  /* Write to Device */
  if (WriteFile(g_tHID.DevHandle, buf, sz, cnt, &g_tHID.DevOverlapped))
    return (TRUE);
  if (GetLastError() == ERROR_IO_PENDING)
    return (TRUE);

  CancelIo(g_tHID.DevHandle);
  return (FALSE);
}


/*
 *  HID GetFeature
 *    Parameters:      buf:   Pointer to buffer to receive feature report
 *                     sz:    Size of feature report to receive
 *    Return Value:    TRUE - Success, FALSE - Error
 */

BOOL HID_GetFeature(BYTE *buf, DWORD sz) {

  return (HidD_GetFeature(g_tHID.DevHandle, buf, sz));
}


/*
 *  HID SetFeature
 *    Parameters:      buf:   Pointer to buffer with report to send
 *                     sz:    Size of feature report to send
 *    Return Value:    TRUE - Success, FALSE - Error
 */

BOOL HID_SetFeature(BYTE *buf, DWORD sz) {

  return (HidD_SetFeature(g_tHID.DevHandle, buf, sz));
}

