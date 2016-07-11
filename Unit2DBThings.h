//---------------------------------------------------------------------------

#ifndef Unit2DBThingsH
#define Unit2DBThingsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <System.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TLabel *DescriptionLabel;
	TMemo *DescriptionMemo;
	TButton *ButtonSave;
	TButton *Button2;
	TLabeledEdit *ThingName;
	TLabeledEdit *ThingShop;
	TLabeledEdit *ThingCost;
	TImage *Image1;
	TOpenPictureDialog *OpenPictureDialog1;
	TButton *Button3;
	TPopupMenu *PopupMenu1;
	TMenuItem *FaceImage;
	TLabel *Label1;
	TDateTimePicker *ThingDOB;
	TLabel *Label2;
	TButton *ButtonClear;
	TMainMenu *MainMenu1;
	TMenuItem *MenuAdd;
	TMenuItem *MenuAddThing;
	TMenuItem *MenuResource;
	TMenuItem *N1;
	TMenuItem *MenuSelect;
	TMenuItem *MenuWSelect;
	TMenuItem *MenuDelete;
	TMenuItem *MenuExit;
	TMenuItem *MenuOptions;
        TCheckBox *CheckBox1;
    TMenuItem *N2;
    TMenuItem *N3;
    TMenuItem *MenuHelp;
    TMenuItem *NewCategory;
    TComboBox *ThingCategory;
    TLabel *Label3;
    TPopupMenu *PopupMenu2;
    TMenuItem *Calc;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall ButtonSaveClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall ImgLoadClick(TObject *Sender);
	void __fastcall ImageCloseMouseEnter(TObject *Sender);
	void __fastcall ImageCloseMouseLeave(TObject *Sender);
	void __fastcall ImageCloseClick(TObject *Sender);
	void __fastcall ButtonUpLoadClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall ImageFaceContextPopup(TObject *Sender, TPoint &MousePos, bool &Handled);
	void __fastcall FaceImageClick(TObject *Sender);
	void __fastcall ThingCostKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall ButtonClearClick(TObject *Sender);
	void __fastcall MenuExitClick(TObject *Sender);
    void __fastcall N2Click(TObject *Sender);
    void __fastcall N3Click(TObject *Sender);
    void __fastcall MenuHelpClick(TObject *Sender);
    void __fastcall NewCategoryClick(TObject *Sender);
    void __fastcall MenuOptionsClick(TObject *Sender);
    void __fastcall CalcClick(TObject *Sender);
          



private:	// User declarations
public:		// User declarations
	TImage *img[6]; // √лобально объ¤вл¤ем массив из 6 изображений
	String ArrayPathImages[6];
	AnsiString __fastcall ReturnFileName(AnsiString FilePath);
	AnsiString __fastcall ReturnTypeFile(AnsiString Path, boolean Points);
	AnsiString __fastcall ReturnFullFileName(AnsiString FilePath);
	int __fastcall FilingID(AnsiString TableName);
	void __fastcall ResetQuery1();
	void __fastcall UpdateComboBox1();
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
