//---------------------------------------------------------------------------

#ifndef UnitDBThingsH
#define UnitDBThingsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Graphics.hpp>
#include <vector>
#include "IniFiles.hpp" // Для работы с .ini файлами
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TScrollBox *ScrollBox1;
	TADOConnection *ADOConnection1;
	TADOQuery *ADOQuery1;
	TDBGrid *DBGrid1;
	TComboBox *ComboBox1;
	TButton *Button1;
	TPopupMenu *PopupMenu1;
	TMenuItem *Delete;
	TADOConnection *ADOConnection2;
	TDataSource *DataSource1;
	TADOQuery *ADOQuery2;
	TLabel *Label1;
	TLabel *Label2;
	TButton *Button2;
	TButton *ButtonDelete;
    TLabel *Label3;
	void __fastcall ScrollBox1MouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta,
          TPoint &MousePos, bool &Handled);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ImgEditClick(TObject *Sender);
	void __fastcall LabelNameClick(TObject *Sender);
	void __fastcall DeleteClick(TObject *Sender);
	void __fastcall Label7ContextPopup(TObject *Sender, TPoint &MousePos, bool &Handled);
	void __fastcall ImageFontMouseEnter(TObject *Sender);
	void __fastcall ImageFontMouseLeave(TObject *Sender);
	void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall ImageOptionClick(TObject *Sender);
	void __fastcall CheckBoxClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall ButtonDeleteClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	int ClickFlag, SelectItemCombo, IconSizeThings;
	int SpeedScrollBox1; // Переменная устанавливающая скорость прокрутки ScrollBox'а
	AnsiString NameOfCategory;
	void __fastcall OutputThings();
	void __fastcall LoadFontImages();
	HANDLE h; // Тянем библу, она содержит элементы графического интерфейса

// Изменения размеров формы при BorderStyle = bsNone
// раьотает только при стандартном скине Windows
/*protected:
	MESSAGE void __fastcall WMNCHitTest(Messages::TWMNCHitTest &Message)
	{
		const int BorderSize = 5;

        TForm::Dispatch(&Message);

        if(BorderStyle == bsNone)
        {
            int Bottom = BoundsRect.Bottom - Message.YPos;
			if(Bottom < BorderSize) Message.Result = HTBOTTOM;
			int Right = BoundsRect.Right - Message.XPos;
			if(Right < BorderSize) Message.Result = HTRIGHT;
			if(Bottom < BorderSize && Right < BorderSize) Message.Result = HTBOTTOMRIGHT;
        }
    }
    BEGIN_MESSAGE_MAP
	MESSAGE_HANDLER(WM_NCHITTEST, TWMNCHitTest, WMNCHitTest)
	END_MESSAGE_MAP(TForm); */



	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
