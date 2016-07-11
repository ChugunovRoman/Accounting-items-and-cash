//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitNC.h" // ����� ����������� ����� ���������
#include "Unit2DBThings.h" // ��������� ������ ����� (���������� ��� �������������� ����)
#include "UnitDBThings.h" // ��������� ������� �����
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormNC *FormNC;
//---------------------------------------------------------------------------
__fastcall TFormNC::TFormNC(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
//          ������� �� ������ "��������", ��������� ����� ���������        --
//---------------------------------------------------------------------------
void __fastcall TFormNC::AddCategoryClick(TObject *Sender)
{
    if(Edit1->Text != "")
    {    
        if(Form1->ADOQuery1->Active)
        {
            Form1->ADOQuery1->Active = false;
        }
        Form1->ADOQuery1->SQL->Text = "SELECT * FROM Category";
        Form1->ADOQuery1->Active = true;
        if(Form1->ADOQuery1->Active)
        {
            Form1->ADOQuery1->Active = false;
        }
        Form1->ADOQuery1->SQL->Text = "INSERT INTO Category VALUES('"+IntToStr(Form2->FilingID("Category"))+"', '"+Edit1->Text+"')";
        Form1->ADOQuery1->ExecSQL();
        
        Form2->UpdateComboBox1(); // ��������� ������ ComboBox1
        Form2->ResetQuery1();
        Form1->ScrollBox1->SetFocus();
        
    }
    else
    {
        ShowMessage("�������� �� ������ ���� ������!");
    }
}
//---------------------------------------------------------------------------
//                ��������� ����� ������� "������"                         --
//---------------------------------------------------------------------------
void __fastcall TFormNC::CanselClick(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------
