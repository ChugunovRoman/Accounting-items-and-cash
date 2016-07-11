//---------------------------------------------------------------------------

#ifndef UnitCostsH
#define UnitCostsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormCosts : public TForm
{
__published:	// IDE-managed Components
    TDBGrid *DBGrid1;
    TComboBox *ComboBox1;
    TButton *Button1;
    TDataSource *DataSource1;
    TADOQuery *ADOQuery1;
    TEdit *Edit1;
    TEdit *Edit2;
    TDateTimePicker *DateTimePicker1;
    TLabel *Label1;
    TComboBox *ComboBox2;
    TButton *Button2;
    TLabel *Label2;
    TEdit *Edit3;
    TADOQuery *ADOQuery2;
    TTimer *Timer1;
    TButton *Button3;
    TLabel *Label3;
    TLabel *Label4;
    TCheckBox *CheckBox1;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Edit2KeyPress(TObject *Sender, System::WideChar &Key);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
    void __fastcall ComboBox2Change(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State);
    void __fastcall Edit3KeyPress(TObject *Sender, System::WideChar &Key);
private:	// User declarations
public:		// User declarations
    int __fastcall FilingYID();
    __fastcall TFormCosts(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormCosts *FormCosts;
//---------------------------------------------------------------------------
#endif
