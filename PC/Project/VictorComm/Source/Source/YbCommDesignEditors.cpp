//---------------------------------------------------------------------------
#pragma hdrstop

#include "YbCommDevice.h"
#include "YbCommDesignEditors.h"
#include "Unit_YBCommDevice_About.h"
#include "Unit_YbCommDevice_Settings.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
namespace Ybcommdesigneditors {
//---------------------------------------------------------------------------
void __fastcall PACKAGE Register()
{
  TComponentClass classes[1] = {__classid(VictorComm::TYbCommDevice)};
  RegisterComponents("Victor", classes, 0);
  RegisterComponentEditor(__classid(VictorComm::TYbCommDevice),__classid(TYbCommDeviceEditor));
}
//---------------------------------------------------------------------------
void __fastcall TYbCommDeviceEditor::ExecuteVerb(int Index)
{
  if(Index == 0)
   {
     bool bPressedBtnOK;
     VictorComm::TForm_YbCommDevice_Settings *FormSettings;
     VictorComm::TYbCommDevice *lpComm = dynamic_cast<VictorComm::TYbCommDevice*>(Component);

     if(lpComm)
      {
        FormSettings = new VictorComm::TForm_YbCommDevice_Settings(NULL,lpComm,false);
        bPressedBtnOK = FormSettings->ShowModal() == IDOK;
        delete FormSettings;

        if(bPressedBtnOK)
         {
           Designer->Modified();
         }
      }
   }
  else
   {
     VictorComm::TForm_YBComm64_About *FormAbout = new VictorComm::TForm_YBComm64_About(NULL,Component->ClassName());
     FormAbout->ShowModal();
     delete FormAbout;
   }
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TYbCommDeviceEditor::GetVerb(int Index)
{
  if(Index == 0)
    return VictorComm::TForm_YBComm64_About::TMsgStrings().Str_Settings;
  return VictorComm::TForm_YBComm64_About::TMsgStrings().Str_MenuAbout;
}
//---------------------------------------------------------------------------
int __fastcall TYbCommDeviceEditor::GetVerbCount(void)
{
  return 2;
}
//---------------------------------------------------------------------------
} // namespace Ybcommdesigneditors
//---------------------------------------------------------------------------
