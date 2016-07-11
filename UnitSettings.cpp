//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitDBThings.h" // Заголовок главной формы
#include "Unit2DBThings.h" // Заголовок второй формы (добавление или редактирование вещи)
//#include "UnitImgBig.h" // Заголовок формы увеличенной картинки
#include "UnitSettings.h" // Заголовок формы настроек
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cgrid"
#pragma resource "*.dfm"
TForm4 *Form4;
TIniFile *IniFile = new TIniFile(ChangeFileExt(Application->ExeName, ".INI"));
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
	Form1->IconSizeThings = RadioGroup1->ItemIndex;
	Form1->SpeedScrollBox1 = TrackBar1->Position+1;
    IniFile->WriteString("Color", "ColorSelectedBorder", ArrayColorBorders[ComboBox3->ItemIndex]);
    IniFile->WriteInteger("Color", "FontColorName", Shape1->Brush->Color);
    IniFile->WriteInteger("Color", "BGColorName", Shape2->Brush->Color);
    IniFile->WriteInteger("Color", "EnterColorName", Shape3->Brush->Color);
	Form4->Close();
	Form1->ComboBox1Change(Form1->ComboBox1); // Вызываем событие пересоздание всех объектов грубо говоря
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormShow(TObject *Sender)
{
    // Сохранение настроек в файл
	RadioGroup1->ItemIndex = IniFile->ReadInteger("Size", "IconSizeThings", 2);
	TrackBar1->Position = IniFile->ReadInteger("Speed", "SpeedScrollBox1", 3)-1;
    ComboBox2->Text = IniFile->ReadString("Skin", "SelectSkin", "Light");
    Shape1->Brush->Color = IniFile->ReadInteger("Color", "FontColorName", 0x0);
    Shape2->Brush->Color = IniFile->ReadInteger("Color", "BGColorName", clGradientInactiveCaption);
    Shape3->Brush->Color = IniFile->ReadInteger("Color", "EnterColorName", 0xe75a0c);
    ComboBox4->ItemIndex = 0;

    if(ADOQuery1->Active)
    {
        ADOQuery1->Active = false;
    }
    ADOQuery1->SQL->Text = "SELECT * FROM Category";
    ADOQuery1->Active = true;
    CheckListBox1->Clear();
    ADOQuery1->First();
    while(!ADOQuery1->Eof)
    {
        CheckListBox1->Items->Add(ADOQuery1->Fields->FieldByName("Category")->AsString);
        ADOQuery1->Next();
    }

    TabControl1Change(NULL);
    // Заполняем массив названиями изображений
    // Пришлость делать это вручную, т.к. Имена 
    // картинок программного в таком порядке не получишь :(
    ArrayColorBorders[0] = "SelectBorder";    
    ArrayColorBorders[1] = "BlueSelectBorder";
    ArrayColorBorders[2] = "LightBlueSelectBorder";
    ArrayColorBorders[3] = "SkyBlueSelectBorder";
    ArrayColorBorders[4] = "PurpleSelectBorder";
    ArrayColorBorders[5] = "PinkSelectBorder";
    ArrayColorBorders[6] = "GraySelectBorder";
    ArrayColorBorders[7] = "BlackSelectBorder";
    ArrayColorBorders[8] = "WhiteSelectBorder";
    ArrayColorBorders[9] = "RedSelectBorder";
    ArrayColorBorders[10] = "LightRedSelectBorder";
    ArrayColorBorders[11] = "OrangeSelectBorder";
    ArrayColorBorders[12] = "YellowSelectBorder";
    ArrayColorBorders[13] = "LightGreenSelectBorder";
    ArrayColorBorders[14] = "GreenSelectBorder";
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Edit2KeyPress(TObject *Sender, System::WideChar &Key)          
{
    if((Key != VK_BACK) && (Key < '0' || Key > '7'))
	{
		Key=0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
          
{
    if((Key != VK_BACK) && (Key < '0' || Key > '9'))
	{
		Key=0;
	}    
}
//---------------------------------------------------------------------------

void __fastcall TForm4::ComboBox2Change(TObject *Sender)
{
    TStyleManager::TrySetStyle(ComboBox2->Text);
    IniFile->WriteString("Skin", "SelectSkin", ComboBox2->Text);    
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FormCreate(TObject *Sender)
{
    for(int i = 0; i < TStyleManager::StyleNames.Length; i++)
    {    
        ComboBox2->Items->Add(TStyleManager::StyleNames[i]);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm4::TabControl1Change(TObject *Sender)
{
    GroupBox1->Visible = false;
    RadioGroup1->Visible = false;
    GroupBox3->Visible = false;
    GroupBox4->Visible = false;
    GroupBox5->Visible = false;
    GroupBox6->Visible = false;
    switch(TabControl1->TabIndex)
    {    
        case 0:
        {
            GroupBox3->Visible = true;
            GroupBox4->Visible = true;
        } break;
        case 1:
        {
            GroupBox1->Visible = true;
            RadioGroup1->Visible = true;           
        } break;
        case 2:
        {
            GroupBox5->Visible = true;
            GroupBox6->Visible = true;
        } break;
    } 
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button2Click(TObject *Sender)
{
    if(ColorDialog1->Execute())
    {    
        Shape1->Brush->Color = ColorDialog1->Color;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button3Click(TObject *Sender)
{
    if(ColorDialog1->Execute())
    {    
        Shape2->Brush->Color = ColorDialog1->Color;
    }    
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button4Click(TObject *Sender)
{
    if(ColorDialog1->Execute())
    {    
        Shape3->Brush->Color = ColorDialog1->Color;
    }     
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button5Click(TObject *Sender)
{
    ComboBox3->ItemIndex = 0;
    Shape1->Brush->Color = clBlack;
    Shape2->Brush->Color = clGradientInactiveCaption;
    Shape3->Brush->Color = 0xe75a0c;    
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FormClose(TObject *Sender, TCloseAction &Action)
{
    IniFile->WriteInteger("Size", "IconSizeThings", Form1->IconSizeThings);
	IniFile->WriteInteger("Speed", "SpeedScrollBox1", Form1->SpeedScrollBox1);    
}
//---------------------------------------------------------------------------


void __fastcall TForm4::Button6Click(TObject *Sender)
{
    if(MessageDlg("Вы точно хотите удалить все "+ComboBox4->Text+"?", mtCustom, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
    {   
        ShowMessage("Условие то ваще выполняется?");
        if(ADOQuery1->Active)
        {
            ADOQuery1->Active = false;
        }
        switch(ComboBox4->ItemIndex)
        {
            case 0:
            {
                ADOQuery1->SQL->Text = "DELETE FROM Things;";
                ADOQuery1->ExecSQL();
            } break;
            case 1:
            {
                ADOQuery1->SQL->Text = "DELETE FROM Costs;";
                ADOQuery1->ExecSQL();
            } break;
            case 2:
            {
                ADOQuery1->SQL->Text = "DELETE FROM Resource;";
                ADOQuery1->ExecSQL();
            } break;
        }
        Form1->ComboBox1Change(Form1->ComboBox1); // Вызываем событие пересоздание всех объектов грубо говоря
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button7Click(TObject *Sender)
{
    ADOQuery1->SQL->Text = "DELETE FROM Things;";
    ADOQuery1->ExecSQL();
    ADOQuery1->SQL->Text = "DELETE FROM Category;";
    ADOQuery1->ExecSQL();
    ADOQuery1->SQL->Text = "DELETE FROM Costs;";
    ADOQuery1->ExecSQL();
    ADOQuery1->SQL->Text = "DELETE FROM Resource;";
    ADOQuery1->ExecSQL();    
}
//---------------------------------------------------------------------------


void __fastcall TForm4::Button8Click(TObject *Sender)
{
    int Record = 0;
    for(int i = 0; i < CheckListBox1->Items->Count; i++)
    {
        if(CheckListBox1->Checked[i])
        {
            if(ADOQuery1->Active)
            {
                ADOQuery1->Active = false;
            }
            ADOQuery1->SQL->Text = "SELECT * FROM things WHERE `Category`='"+CheckListBox1->Items->Strings[i]+"';";
            ADOQuery1->Active = true;
            Record = ADOQuery1->RecordCount;
            if(Record != 0)
            {
                if(MessageDlg("Некоторые категории не пусты. Если их удалить, то и вещи этих категорий тоже удаляться. Удалить?", mtCustom, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
                {
                    if(ADOQuery2->Active)
                    {
                        ADOQuery2->Active = false;
                    }
                    ADOQuery2->SQL->Text = "DELETE FROM Category WHERE `Category`='"+CheckListBox1->Items->Strings[i]+"';";
                    ADOQuery2->ExecSQL(); 
                    if(ADOQuery2->Active)
                    {
                        ADOQuery2->Active = false;
                    }
                    ADOQuery2->SQL->Text = "SELECT * FROM Things WHERE `Category`='"+CheckListBox1->Items->Strings[i]+"';";
                    ADOQuery2->Active = true;
                    ADOQuery2->SQL->Text = "DELETE FROM Things WHERE `Category`='"+CheckListBox1->Items->Strings[i]+"';";
                    ADOQuery2->ExecSQL();
                }
                else
                {
                    break;
                }
            }
            else
            {
                if(ADOQuery2->Active)
                {
                    ADOQuery2->Active = false;
                }
                ADOQuery2->SQL->Text = "DELETE FROM Category WHERE `Category`='"+CheckListBox1->Items->Strings[i]+"';";
                ADOQuery2->ExecSQL();
            }
            
        }
        
    }
    if(ADOQuery1->Active)
    {
        ADOQuery1->Active = false;
    }
    ADOQuery1->SQL->Text = "SELECT * FROM Category";
    ADOQuery1->Active = true;
    CheckListBox1->Clear();
    ADOQuery1->First();
    while(!ADOQuery1->Eof)
    {
        CheckListBox1->Items->Add(ADOQuery1->Fields->FieldByName("Category")->AsString);
        ADOQuery1->Next();
    }
    // формирование списка с категориями
	Form2->UpdateComboBox1();
    Form1->ComboBox1Change(Form1->ComboBox1); // Вызываем событие пересоздание всех объектов грубо говоря  
}
//---------------------------------------------------------------------------

