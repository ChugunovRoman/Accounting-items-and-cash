//---------------------------------------------------------------------------

#ifndef UnitCalcH
#define UnitCalcH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFormCalc : public TForm
{
__published:	// IDE-managed Components
    TChart *Chart1;
    TPieSeries *Series1;
    TLineSeries *Series2;
    TLabel *Label1;
    void __fastcall FormClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFormCalc(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormCalc *FormCalc;
//---------------------------------------------------------------------------
#endif
