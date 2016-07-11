//---------------------------------------------------------------------------

#ifndef UnitResourceH
#define UnitResourceH
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
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
//---------------------------------------------------------------------------
class TFormRes : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TEdit *Edit1;
	TButton *ButtonAdd;
	TButton *ButtonOk;
	TComboBox *ComboBox1;
	TDataSource *DataSource1;
	TADOQuery *ADOQuery1;
	TButton *Button1;
	TADOQuery *ADOQuery2;
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TLabel *Label3;
	TEdit *Edit2;
	TButton *Button3;
	TButton *Button2;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
    TComboBox *ComboBox2;
    TLabel *Label9;
    TLabel *Label10;
    TLabel *Label11;
    TLabel *Label12;
    TLabel *Label13;
    TLabel *Label14;
    TLabel *Label15;
    TLabel *Label16;
    TTabControl *TabControl1;
    TGroupBox *GroupBox2;
    TEdit *EditName;
    TGroupBox *GroupBox3;
    TChart *Chart1;
    TPieSeries *Series1;
    TDateTimePicker *DateTimePicker1;
    TLabel *Label2;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall ButtonOkClick(TObject *Sender);
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall DBGrid1CellClick(TColumn *Column);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall Edit1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit2KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall ComboBox1KeyPress(TObject *Sender, System::WideChar &Key);
    void __fastcall DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State);
    void __fastcall TabControl1Change(TObject *Sender);
    void __fastcall DateTimePicker1Change(TObject *Sender);
          
private:	// User declarations
public:		// User declarations
	int __fastcall FilingZID();
    int __fastcall DayCountLastDate(int DayIncome, AnsiString ResourceType);
    int __fastcall DayOfMonth(int Day);
	__fastcall TFormRes(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormRes *FormRes;
//---------------------------------------------------------------------------
#endif
