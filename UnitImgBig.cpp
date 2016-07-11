//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitDBThings.h"
#include "Unit2DBThings.h"
#include "UnitImgBig.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Image1Click(TObject *Sender)
{
    // При нажатии на картинку, закрываем форму
	Close();
}
//---------------------------------------------------------------------------
