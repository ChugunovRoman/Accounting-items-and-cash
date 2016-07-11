//---------------------------------------------------------------------------

#include <vcl.h>
#include "IniFiles.hpp" // ִכÿ נאבמעû ס .ini פאיכאלט
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("UnitNC.cpp", FormNC);
USEFORM("UnitImgBig.cpp", Form3);
USEFORM("UnitSettings.cpp", Form4);
USEFORM("UnitResource.cpp", FormRes);
USEFORM("UnitDBThings.cpp", Form1);
USEFORM("UnitCosts.cpp", FormCosts);
USEFORM("Unit2DBThings.cpp", Form2);
USEFORM("UnitCalc.cpp", FormCalc);
//---------------------------------------------------------------------------
TIniFile *IniFile = new TIniFile(ChangeFileExt(Application->ExeName, ".INI"));
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->Title = "׃קוע";
		Application->HelpFile = "D:\\׃קובא\\C++ Project\\chm\\Help.chm";
         TStyleManager::TrySetStyle(IniFile->ReadString("Skin", "SelectSkin", "Light"));
		Application->CreateForm(__classid(TForm1), &Form1);
         Application->CreateForm(__classid(TForm2), &Form2);
         Application->CreateForm(__classid(TForm3), &Form3);
         Application->CreateForm(__classid(TForm4), &Form4);
         Application->CreateForm(__classid(TFormRes), &FormRes);
         Application->CreateForm(__classid(TFormCosts), &FormCosts);
         Application->CreateForm(__classid(TFormNC), &FormNC);
         Application->CreateForm(__classid(TFormCalc), &FormCalc);
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
