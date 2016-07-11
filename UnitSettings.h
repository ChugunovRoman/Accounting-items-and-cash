//---------------------------------------------------------------------------

#ifndef UnitSettingsH
#define UnitSettingsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
#include "cgrid.h"
#include <Vcl.Dialogs.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.CheckLst.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TTrackBar *TrackBar1;
	TButton *Button1;
	TLabel *Label2;
	TLabel *Label3;
	TGroupBox *GroupBox1;
	TRadioGroup *RadioGroup1;
    TGroupBox *GroupBox3;
    TComboBox *ComboBox2;
    TLabel *Label7;
    TTabControl *TabControl1;
    TGroupBox *GroupBox4;
    TLabel *Label9;
    TComboBox *ComboBox3;
    TLabel *Label8;
    TShape *Shape1;
    TColorDialog *ColorDialog1;
    TButton *Button2;
    TLabel *Label10;
    TShape *Shape2;
    TButton *Button3;
    TLabel *Label11;
    TShape *Shape3;
    TButton *Button4;
    TButton *Button5;
    TLabel *Label12;
    TLabel *Label13;
    TLabel *Label14;
    TGroupBox *GroupBox5;
    TButton *Button6;
    TComboBox *ComboBox4;
    TADOQuery *ADOQuery1;
    TButton *Button7;
    TGroupBox *GroupBox6;
    TCheckListBox *CheckListBox1;
    TButton *Button8;
    TLabel *Label15;
    TADOQuery *ADOQuery2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
        void __fastcall Edit2KeyPress(TObject *Sender, System::WideChar &Key);
    void __fastcall Edit1KeyPress(TObject *Sender, System::WideChar &Key);
    void __fastcall ComboBox2Change(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall TabControl1Change(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall Button4Click(TObject *Sender);
    void __fastcall Button5Click(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall Button6Click(TObject *Sender);
    void __fastcall Button7Click(TObject *Sender);
    void __fastcall Button8Click(TObject *Sender);
          

private:	// User declarations
public:		// User declarations
    AnsiString ArrayColorBorders[15];
	__fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
