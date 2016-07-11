//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitCosts.h" // юнит расходов
#include "UnitDBThings.h" // Заголовок главной формы
#include "UnitResource.h" // Форма ресурсов
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormCosts *FormCosts;
TIniFile *IniFile = new TIniFile(ChangeFileExt(Application->ExeName, ".INI"));
//---------------------------------------------------------------------------
int __fastcall TFormCosts::FilingYID()
{
	// Функция возвращает следующий свободний ID
	// Если номера ID идут так: 1,2,3,5
	// То функция возвратит число 4, т.к. его нету, а значить это свободное место
    ADOQuery1->Active = true;
    ADOQuery1->First();
    while (!ADOQuery1->Eof)
    {
        ADOQuery2->SQL->Text = "UPDATE Costs SET `ID`= "+IntToStr(ADOQuery1->RecNo)+" WHERE `ID`= " + ADOQuery1->FieldByName("ID")->AsString + ";";
        ADOQuery2->ExecSQL();
        ADOQuery2->Close();
        ADOQuery1->Next();
    }
    ADOQuery1->First();
    ADOQuery1->FindLast();
    return ADOQuery1->FieldByName("ID")->AsInteger+1;
    ADOQuery1->FindFirst();
}
//---------------------------------------------------------------------------
__fastcall TFormCosts::TFormCosts(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormCosts::FormShow(TObject *Sender)
{
    
    DateTimePicker1->Date = Now();
    Edit1->Text = "";
    Edit2->Text = "0";
    Edit3->Text = FormatDateTime("dd.mm.yyyy", IncMonth(Now(), -1)) +"-"+ FormatDateTime("dd.mm.yyyy", Now());
    Label4->Caption = IniFile->ReadString("Resource", "ofMonth", "0");
    //FormRes->Label3->Caption;

    if(ADOQuery1->Active)
	{
		ADOQuery1->Active = false;
	}
	ADOQuery1->SQL->Text = "SELECT * FROM Costs";
	ADOQuery1->Active = true;
    ShowScrollBar(DBGrid1->Handle, SB_BOTH, false);    
}
//---------------------------------------------------------------------------
void __fastcall TFormCosts::Button2Click(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------
void __fastcall TFormCosts::Edit2KeyPress(TObject *Sender, System::WideChar &Key)
          
{
    if((Key != VK_RETURN) && (Key != VK_BACK) && (Key < '0' || Key > '9'))
	{
		Key=0;
	}    
}
//---------------------------------------------------------------------------
void __fastcall TFormCosts::Button1Click(TObject *Sender)
{
    if(Edit1->Text != "" && Edit2->Text != "")
    {
        if(CheckBox1->Checked)
        {
            //if(StrToInt(Label4->Caption) - StrToInt(Edit2->Text) >= 0)
            //{
                if(ComboBox1->Text == "Одноразовый")
                {
                    int Income = IniFile->ReadInteger("Resource", "ofMonth", 0) - StrToInt(Edit2->Text);
                    IniFile->WriteInteger("Resource", "ofMonth", Income);
                }             
                if(ADOQuery1->Active)
                {
                    ADOQuery1->Active = false;
                }
                ADOQuery1->SQL->Text = "INSERT INTO Costs VALUES('"+IntToStr(FilingYID())+"', '"+Edit1->Text+"', '"+Edit2->Text+"', '"+ComboBox1->Text+"', '"+DateTimePicker1->Date+"', '1', '0')";
                ADOQuery1->ExecSQL();
            /*}
            else
            {
                ShowMessage("Недостаточно средств!");
            }*/
        }
        else
        {
            if(ADOQuery1->Active)
            {
                ADOQuery1->Active = false;
            }
            ADOQuery1->SQL->Text = "INSERT INTO Costs VALUES('"+IntToStr(FilingYID())+"', '"+Edit1->Text+"', '"+Edit2->Text+"', '"+ComboBox1->Text+"', '"+DateTimePicker1->Date+"', '0', '0')";
            ADOQuery1->ExecSQL();
        }
        
        
    }
    else
    {    
        ShowMessage("Заполните поля!");
    }
    if(ADOQuery1->Active)
	{
		ADOQuery1->Active = false;
        ADOQuery2->Active = false;
	}
	ADOQuery1->SQL->Text = "SELECT * FROM Costs";
    ADOQuery2->SQL->Text = "SELECT * FROM Costs";
	ADOQuery1->Active = true;
    ADOQuery2->Active = true;
    Label4->Caption = IniFile->ReadString("Resource", "ofMonth", "0");
    ShowScrollBar(DBGrid1->Handle, SB_BOTH, false);
}
//---------------------------------------------------------------------------

void __fastcall TFormCosts::FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
    long SC_DRAGMOVE = 0xF012;
	if(Button == mbLeft)
	{
		ReleaseCapture();
        SendMessage(Handle, WM_SYSCOMMAND, SC_DRAGMOVE, 0);
	}    
}
//---------------------------------------------------------------------------
void __fastcall TFormCosts::ComboBox2Change(TObject *Sender)
{
    if(ADOQuery1->RecordCount != 0)
    {
        if(ADOQuery1->Active)
        {
            ADOQuery1->Active = false;    
        }
        if(ComboBox2->ItemIndex == 0)
        {
            ADOQuery1->SQL->Text = "SELECT * FROM Costs;";
        }
        else
        {
            ADOQuery1->SQL->Text = "SELECT * FROM Costs WHERE `Периодичность`='"+ComboBox2->Text+"';";
        }    
        ADOQuery1->Active = true;
        if(ADOQuery1->RecordCount == 0)
        {
            ShowMessage("Таких расходов нет!");
            ADOQuery1->SQL->Text = "SELECT * FROM Costs;";
            ADOQuery1->Active = true;
            ComboBox2->ItemIndex = 0;
        }
    }
    
}
//---------------------------------------------------------------------------

void __fastcall TFormCosts::Timer1Timer(TObject *Sender)
{
    DateTimePicker1->Time = Time();  
}
//---------------------------------------------------------------------------

void __fastcall TFormCosts::Button3Click(TObject *Sender)
{
    if(ADOQuery1->RecordCount != 0)
	{
		ADOQuery1->SQL->Text = "DELETE FROM Costs WHERE `ID`="+ADOQuery1->Fields->FieldByName("ID")->AsString+";";
		ADOQuery1->ExecSQL();
		if(ADOQuery1->Active)
		{
			ADOQuery1->Active = false;
		}
		ADOQuery1->SQL->Text = "SELECT * FROM Costs";
		ADOQuery1->Active = true;
	}
	else
	{
        ShowMessage("Удалять нечего.");
    }
    ShowScrollBar(DBGrid1->Handle, SB_BOTH, false);    
}
//---------------------------------------------------------------------------
void __fastcall TFormCosts::DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State)
{
    if(ADOQuery1->Fields->FieldByName("Вычитать")->AsInteger == 0)
    {
        DBGrid1->Canvas->Font->Color = clGrayText;
    }
    else
    {      
        //DBGrid1->Canvas->Brush->Color = clSkyBlue;
        DBGrid1->Canvas->Font->Color = clBlack;
    }
    if(State.Contains(Grids::gdSelected) && ADOQuery1->Fields->FieldByName("Вычитать")->AsInteger == 0)
    {
        DBGrid1->Canvas->Brush->Color = clSkyBlue;
        DBGrid1->Canvas->Font->Color = System::Uitypes::TColor(0x222222);
    }
    if(State.Contains(Grids::gdSelected) && ADOQuery1->Fields->FieldByName("Вычитать")->AsInteger == 1)
    {
        //State.Contains(Grids::gdRowSelected)
        DBGrid1->Canvas->Brush->Color = clSkyBlue;
        DBGrid1->Canvas->Font->Color = clBlack;
    }
    DBGrid1->Canvas->FillRect(Rect);
    DBGrid1->Canvas->TextOut(Rect.Left+2, Rect.Top+2, Column->Field->Text);
}
//---------------------------------------------------------------------------

void __fastcall TFormCosts::Edit3KeyPress(TObject *Sender, System::WideChar &Key)          
{
    if(Key == VK_RETURN)
    {
        if(Edit3->Text != "")
        {
            AnsiString dateth[2];
            for(int i = 1, DateNum = 0; i <= Edit3->Text.Length(); i++)
            {
                if(Edit3->Text[i] != '-')
                {
                    dateth[DateNum] += Edit3->Text[i];
                }
                else
                {
                    DateNum++;
                }
            }
            if(ADOQuery1->Active)
            {
                ADOQuery1->Active = false;
            }
            if(dateth[1] == "")
            {
                dateth[1] = dateth[0];
            }
            ADOQuery1->SQL->Text = "SELECT * FROM Costs WHERE `Дата` BETWEEN #"+FormatDateTime("yyyy-mm-dd", StrToDate(dateth[0]))+"# AND #"+FormatDateTime("yyyy-mm-dd", StrToDate(dateth[1])+1)+"#;";
            ADOQuery1->Active = true;
        }
        else
        {
            if(ADOQuery1->Active)
            {
                ADOQuery1->Active = false;
            }
            ADOQuery1->SQL->Text = "SELECT * FROM Costs";
            ADOQuery1->Active = true;
        } 
    }
    if((Key != VK_BACK) && (Key < '0' || Key > '9') && (Key != '.') && (Key != '-'))
	{
		Key=0;
	}
}
//---------------------------------------------------------------------------

