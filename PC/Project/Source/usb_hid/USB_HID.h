
#ifndef _HIDSDI_H
#define _HIDSDI_H

#include <pshpack4.h>

//#include "wtypes.h"

//#include <windef.h>
//#include <win32.h>
//#include <basetyps.h>


//#include <WinIoCtl.h>
#include <stdio.h>

#include "stdio.h"
#include "conio.h"
#include "windows.h"

#include "setupapi.h"
#include "hiddll.h"

typedef enum _POOL_TYPE {
  NonPagedPool,
  NonPagedPoolExecute                   = NonPagedPool,
  PagedPool,
  NonPagedPoolMustSucceed               = NonPagedPool + 2,
  DontUseThisType,
  NonPagedPoolCacheAligned              = NonPagedPool + 4,
  PagedPoolCacheAligned,
  NonPagedPoolCacheAlignedMustS         = NonPagedPool + 6,
  MaxPoolType,
  NonPagedPoolBase                      = 0,
  NonPagedPoolBaseMustSucceed           = NonPagedPoolBase + 2,
  NonPagedPoolBaseCacheAligned          = NonPagedPoolBase + 4,
  NonPagedPoolBaseCacheAlignedMustS     = NonPagedPoolBase + 6,
  NonPagedPoolSession                   = 32,
  PagedPoolSession                      = NonPagedPoolSession + 1,
  NonPagedPoolMustSucceedSession        = PagedPoolSession + 1,
  DontUseThisTypeSession                = NonPagedPoolMustSucceedSession + 1,
  NonPagedPoolCacheAlignedSession       = DontUseThisTypeSession + 1,
  PagedPoolCacheAlignedSession          = NonPagedPoolCacheAlignedSession + 1,
  NonPagedPoolCacheAlignedMustSSession  = PagedPoolCacheAlignedSession + 1,
  NonPagedPoolNx                        = 512,
  NonPagedPoolNxCacheAligned            = NonPagedPoolNx + 4,
  NonPagedPoolSessionNx                 = NonPagedPoolNx + 32
} POOL_TYPE;

#include "hidsdi.h"
#include "hidpddi.h" // to use the kernel space parser
#include "hidpi.h"

//extern "C"
//{
//	#include "setupapi.h"
//	#include "hiddll.h"
//}

typedef LONG NTSTATUS;

typedef struct _HIDD_CONFIGURATION {
	PVOID    cookie;
	ULONG    size;
    ULONG    RingBufferSize;
} HIDD_CONFIGURATION, *PHIDD_CONFIGURATION;

typedef struct _HIDD_ATTRIBUTES {
	ULONG   Size; // = sizeof (struct _HIDD_ATTRIBUTES)

    //
    // Vendor ids of this hid device
    //
	USHORT  VendorID;
    USHORT  ProductID;
	USHORT  VersionNumber;

    //
	// Additional fields will be added to the end of this structure.
    //
} HIDD_ATTRIBUTES, *PHIDD_ATTRIBUTES;


#define DEV_NUM  10

typedef struct
{
	int                                DevCount;
	int                                DevSelected;
	PSP_DEVICE_INTERFACE_DETAIL_DATA   DevDetailData[DEV_NUM];
	int                                DevDetailDataSz[DEV_NUM];
	int                                DevInputReportSz[DEV_NUM];
	int                                DevOutputReportSz[DEV_NUM];
	int                                DevFeatureReportSz[DEV_NUM];
	HANDLE                             DevHandle;
	OVERLAPPED                         DevOverlapped;
	BOOL                               DevReadPending;
}USER_HID_T;

extern USER_HID_T g_tHID;

//------------------------
extern void  HID_Init();
extern void  HID_UnInit();
extern int   HID_FindDevices();
extern BOOL  HID_GetName(int num, char *buf, int sz);
extern int   HID_GetInputReportSize(int num);
extern int   HID_GetOutputReportSize(int num);
extern int   HID_GetFeatureReportSize(int num);
extern BOOL  HID_Open(int num);
extern int   HID_GetSelectedDevice(void);
extern void  HID_Close();
extern BOOL  HID_Read (BYTE *buf, DWORD sz, DWORD *cnt);
extern BOOL  HID_Write(BYTE *buf, DWORD sz, DWORD *cnt);
extern BOOL  HID_GetFeature(BYTE *buf, DWORD sz);
extern BOOL  HID_SetFeature(BYTE *buf, DWORD sz);
//------------------------

void LoadDll(void);
void FreeDll(void);
void FindDllFunc(void);

extern HANDLE OpenMyHIDDevice(int overlapped);

#include <poppack.h>


#endif