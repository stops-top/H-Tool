//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Source\Unit\UnitDso.cpp", FormDso);
USEFORM("Source\Unit\UnitChangeLog.cpp", FormChangeLog);
USEFORM("Source\Unit\UnitLua.cpp", FormLua);
USEFORM("Source\Unit\UnitMain.cpp", Form1);
USEFORM("Source\Unit\UnitLuaApi.cpp", FormLuaApi);
USEFORM("Source\Unit\UnitCalib.cpp", FormCalib);
USEFORM("Source\Unit\UnitUSBBus.cpp", FormUSBBus);
USEFORM("Source\Unit\UnitRTT.cpp", FormRTT);
USEFORM("Source\Unit\UnitProg.cpp", FormProg);
USEFORM("Source\Unit\UnitScreenShot.cpp", FormScreenShot);
USEFORM("Source\Unit\UnitThread.cpp", FormTcp);
USEFORM("Source\Unit\UnitSet.cpp", FormSet);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
	#if 0       // 只允许运行一个exe
		if (OpenMutexA(MUTEX_ALL_ACCESS, True, "MutexGSG") == 0)
		{
			CreateMutexA(NULL,True,"MutexGSG");
	#else    	//
		{
	#endif

		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->Title = "H7-TOOL";
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TFormCalib), &FormCalib);
		Application->CreateForm(__classid(TFormLua), &FormLua);
		Application->CreateForm(__classid(TFormProg), &FormProg);
		Application->CreateForm(__classid(TFormTcp), &FormTcp);
		Application->CreateForm(__classid(TFormUSBBus), &FormUSBBus);
		Application->CreateForm(__classid(TFormRTT), &FormRTT);
		Application->CreateForm(__classid(TFormSet), &FormSet);
		Application->CreateForm(__classid(TFormDso), &FormDso);
		Application->CreateForm(__classid(TFormLuaApi), &FormLuaApi);
		Application->CreateForm(__classid(TFormChangeLog), &FormChangeLog);
		Application->CreateForm(__classid(TFormScreenShot), &FormScreenShot);
		Application->Run();
		}
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
