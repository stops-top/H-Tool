//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop
USEFORM("..\Source\Unit_YBCommDevice_About.cpp", Form_YBComm64_About);
USEFORM("..\Source\Unit_YbCommDevice_Settings.cpp", Form_YbCommDevice_Settings);
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Package source.
//---------------------------------------------------------------------------


#pragma argsused
extern "C" int _libmain(unsigned long reason)
{
    return 1;
}
//---------------------------------------------------------------------------
