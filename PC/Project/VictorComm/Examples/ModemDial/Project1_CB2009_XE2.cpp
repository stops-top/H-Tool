//---------------------------------------------------------------------------
// 控件演示程序，Copyright © Victor Chen, www.cppfans.com

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("UnitDial.cpp", FormDial);
USEFORM("UnitHang.cpp", FormHang);
USEFORM("Unit1.cpp", Form1);
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
    try
    {
         Application->Initialize();
         Application->MainFormOnTaskBar = true;
         Application->CreateForm(__classid(TForm1), &Form1);
         Application->CreateForm(__classid(TFormDial), &FormDial);
         Application->CreateForm(__classid(TFormHang), &FormHang);
         Application->Run();
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
