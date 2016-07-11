//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitCalc.h"  // Форма расчетов
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormCalc *FormCalc;
//---------------------------------------------------------------------------
__fastcall TFormCalc::TFormCalc(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormCalc::FormClick(TObject *Sender)
{
    Series1->Clear();
    Series1->Add(500, "Value", clRed);  
    Series1->Add(400, "Value1", clYellow);  
    Chart1->Title->Caption = "sdgfht";
}
//---------------------------------------------------------------------------

