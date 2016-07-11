//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitResource.h" // Форма ресурсов
#include "UnitDBThings.h" // Заголовок главной формы
#include "Unit2DBThings.h" // Заголовок второй формы (добавление или редактирование вещи)
#include "UnitSettings.h" // Заголовок формы настроек
#include "UnitCosts.h" // юнит расходов
#include <DateUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormRes *FormRes;
TIniFile *IniFile = new TIniFile(ChangeFileExt(Application->ExeName, ".INI"));
int WeeklyFlag = 0, WeeklyUse = 0, DailyFlag = 0, DailyUse = 0, flagTab = 0;
TDateTime LastDate, LastTime;
int MonthGet[12];
//---------------------------------------------------------------------------
int __fastcall TFormRes::FilingZID()
{
	// Функция возвращает следующий свободний ID
	// Если номера ID идут так: 1,2,3,5
	// То функция возвратит число 4, т.к. его нету, а значить это свободное место

    ADOQuery1->Active = true;
    ADOQuery1->First();
    while (!ADOQuery1->Eof)
    {
        ADOQuery2->SQL->Text = "UPDATE Resource SET `ID`= "+IntToStr(ADOQuery1->RecNo)+" WHERE `ID`= " + ADOQuery1->FieldByName("ID")->AsString + ";";
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
__fastcall TFormRes::TFormRes(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormRes::FormCreate(TObject *Sender)
{
    FormRes->Height = 364;
    FormRes->Width = 892;
	FormRes->ADOQuery1->Active = true;
    DateTimePicker1->Date = Now();
	//Edit1->OnKeyPress = Form2->ThingCost->OnKeyPress;
}
//---------------------------------------------------------------------------
void __fastcall TFormRes::FormResize(TObject *Sender)
{
	// Задаем минимальный размер формы
	FormRes->Constraints->MinHeight = 345;
	FormRes->Constraints->MinWidth = 652;
    // При отображении формы почему то меняются Top и Left у TabControl'а
    // Причину не нашел, так что сбрасываю их значения.
    TabControl1->Top = 0;
    TabControl1->Left = 0;
    // растягиваем грид вместе с формой
	//DBGrid1->Width = FormRes->ClientWidth - 256;
	//DBGrid1->Height = FormRes->ClientHeight - 52;
    // Растягиваем с формой TabControl
    TabControl1->Width = FormRes->Width;
    TabControl1->Height = FormRes->Height;
    // Растягиваем с формой GroupBox
    GroupBox2->Width = FormRes->Width - 20;
    GroupBox2->Height = FormRes->Height - 62;
	// Привязываем GroupBox1
	//GroupBox1->Left = FormRes->ClientWidth - GroupBox1->Width - 6;
	//GroupBox1->Height = FormRes->ClientHeight - 48;
    ShowScrollBar(DBGrid1->Handle, SB_BOTH, false);
}
//---------------------------------------------------------------------------
void __fastcall TFormRes::FormMouseDown(TObject *Sender, TMouseButton Button,
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

void __fastcall TFormRes::ButtonOkClick(TObject *Sender)
{
    AnsiString TableName = "";
    if(TabControl1->TabIndex == 0)
    {
        TableName = "Resource";
    }
    if(TabControl1->TabIndex == 1)
    {
        TableName = "Costs";
    }
	if(ADOQuery1->RecordCount != 0)
	{
        AnsiString id = ADOQuery1->Fields->FieldByName("ID")->AsString;
        ADOQuery1->SQL->Text = "UPDATE `"+TableName+"` SET `Название`='"+EditName->Text+"' WHERE `ID`="+id+";";
        ADOQuery1->ExecSQL();
        ADOQuery1->SQL->Text = "UPDATE `"+TableName+"` SET `Стоимость`='"+Edit1->Text+"' WHERE `ID`="+id+";";
        ADOQuery1->ExecSQL();
        ADOQuery1->SQL->Text = "UPDATE `"+TableName+"` SET `Периодичность`='"+ComboBox1->Text+"' WHERE `ID`="+id+";";
        ADOQuery1->ExecSQL();
        if(ComboBox1->Text == "Еженедельный")
        {
            ADOQuery1->SQL->Text = "UPDATE `"+TableName+"` SET `Дата/День`='"+IntToStr(ComboBox2->ItemIndex+1)+"' WHERE `ID`="+id+";";
        }
        if(ComboBox1->Text == "Ежемесячный")
        {
            ADOQuery1->SQL->Text = "UPDATE `"+TableName+"` SET `Дата/День`='"+IntToStr(ComboBox2->ItemIndex+1)+"' WHERE `ID`="+id+";";
        }        
        ADOQuery1->ExecSQL();
        if(ADOQuery1->Active)
        {
            ADOQuery1->Active = false;
        }
        ADOQuery1->SQL->Text = "SELECT * FROM `"+TableName+"`";
        ADOQuery1->Active = true;
	}
    FormShow(NULL); // Вызываем функцию для пересчета среств после редактирования
    ShowScrollBar(DBGrid1->Handle, SB_BOTH, false);
}
//---------------------------------------------------------------------------

void __fastcall TFormRes::ButtonAddClick(TObject *Sender)
{
    AnsiString TableName = "";
    if(TabControl1->TabIndex == 0)
    {
        TableName = "Resource";
    }
    if(TabControl1->TabIndex == 1)
    {
        TableName = "Costs";
    }
	if(Edit1->Text != "")
	{
		if(ADOQuery1->Active)
		{
			ADOQuery1->Active = false;
		}
        
        if(ComboBox1->Text == "Еженедельный")
        {
            ADOQuery1->SQL->Text = "INSERT INTO `"+TableName+"` VALUES('"+IntToStr(FilingZID())+"', '"+Edit1->Text+"', '"+ComboBox1->Text+"', '"+IntToStr(ComboBox2->ItemIndex+1)+"', 0)";
        }
        if(ComboBox1->Text == "Ежемесячный")
        {
            ADOQuery1->SQL->Text = "INSERT INTO `"+TableName+"` VALUES('"+IntToStr(FilingZID())+"', '"+Edit1->Text+"', '"+ComboBox1->Text+"', '"+IntToStr(ComboBox2->ItemIndex+1)+"', 0)";
        }
		ADOQuery1->ExecSQL();
	}
	else
	{
        ShowMessage("Введите стоимость.");
	}
	// Дописать SELECT
    if(ADOQuery1->Active)
	{
		ADOQuery1->Active = false;
	}
	ADOQuery1->SQL->Text = "SELECT * FROM `"+TableName+"`";
	ADOQuery1->Active = true;
    ShowScrollBar(DBGrid1->Handle, SB_BOTH, false);
    FormShow(NULL);    
}
//---------------------------------------------------------------------------
int __fastcall TFormRes::DayCountLastDate(int DayIncome, AnsiString ResourceType)
{
    // Функция для опеределения количества прошедшех "Доходных" дней с последней даты
    int CountDay = 0;
    if(ResourceType == "Ежемесячный")
    {
        TDate funcLastDate = LastDate;
        while(StrToDate(FormatDateTime("dd.mm.yyyy", funcLastDate)) < StrToDate(FormatDateTime("dd.mm.yyyy", Now())))
        {
            if(StrToInt(FormatDateTime("dd", funcLastDate)) == DayIncome)
            {
                CountDay++;
            }
            funcLastDate += 1.0;
        }
        return CountDay;    
    }
    if(ResourceType == "Еженедельный")
    {
        TDate funcLastDate = LastDate;        
        while(StrToDate(FormatDateTime("dd.mm.yyyy", funcLastDate)) < StrToDate(FormatDateTime("dd.mm.yyyy", Now())))
        {
            // Оперделяем день недели даты funcLastDate
            int WeekDayLst = DayOfWeek(StrToDate(FormatDateTime("dd.mm.yyyy", funcLastDate)))-1;
            if(WeekDayLst == 0)
            {
                // 0 - это воскресение, а у нас это 7 день, а не первый
                WeekDayLst = 7; // Значит присваивает 7
            }
            if(WeekDayLst == DayIncome)
            {
                CountDay++;
            }
            funcLastDate += 1.0;
        }
        return CountDay;    
    }
}  
//---------------------------------------------------------------------------
int __fastcall TFormRes::DayOfMonth(int Day)
{

    TDateTime DateMonStart = Now() - StrToInt(FormatDateTime("d", Now()))+1;
    TDateTime DateMonEnd = Now() + (MonthDays[IsLeapYear(StrToInt(FormatDateTime("yyyy", Now())))][StrToInt(FormatDateTime("m", Now()))] - StrToInt(FormatDateTime("d", Now())))-1;

    TDate Date = StrToDate(FormatDateTime("dd.mm.yyyy", IncMonth(Now(), -1)));
    int CountDay = 0; 
    while(DateMonStart <= DateMonEnd)
    {
        //Memo1->Lines->Add(DateToStr(DateMonStart)+" < "+DateToStr(DateMonEnd));
        int WeekDayNow = DayOfWeek(StrToDate(FormatDateTime("dd.mm.yyyy", DateMonStart)))-1;
        if(WeekDayNow == 0)
        {
            WeekDayNow = 7;
        }
        if(WeekDayNow == Day)
        {
            CountDay++;
        }
        DateMonStart += 1;
    }
    return CountDay;
        
}
//---------------------------------------------------------------------------
void __fastcall TFormRes::FormShow(TObject *Sender)
{
    if(flagTab == 0)
    {
        TabControl1->TabIndex = 0;
        flagTab = 1;
    }
    
    TabControl1Change(TabControl1);
    WeeklyFlag = IniFile->ReadInteger("Resource", "WeeklyFlag", 0);
    DailyFlag = IniFile->ReadInteger("Resource", "DailyFlag", 0);
    LastDate = IniFile->ReadDate("Date", "LastDateRun", Now());
    LastTime = IniFile->ReadTime("Date", "LastTimeRun", Time());

    ShowScrollBar(DBGrid1->Handle, SB_BOTH, false);
    FormRes->ActiveControl = ComboBox1;
    ComboBox1->SetFocus();    
    
    //DateTimePicker1->Date = Now();
    // Заполняем список днями или числами
    if(ComboBox1->Text == "Ежемесячный")
    {
        ComboBox2->Clear();
        for(int i = 1; i < 31; i++)
        {
            ComboBox2->Items->Add(IntToStr(i));
        }
        
    }
    if(ComboBox1->Text == "Еженедельный")
    {
        ComboBox2->Clear();
        ComboBox2->Items->Add("Понедельник");
        ComboBox2->Items->Add("Вторник");
        ComboBox2->Items->Add("Среда");
        ComboBox2->Items->Add("Четверг");
        ComboBox2->Items->Add("Пятница");
        ComboBox2->Items->Add("Суббота");
        ComboBox2->Items->Add("Воскресение");
    }
    ComboBox2->ItemIndex = 0;
    
	Edit1->Text = "";
    Edit2->Text = "";
	if(ADOQuery1->Active)
	{                                                               
		ADOQuery1->Active = false;
	}
	ADOQuery1->SQL->Text = "SELECT * FROM Resource";
	ADOQuery1->Active = true;
    
    if(FormCosts->ADOQuery1->Active)
    {
        FormCosts->ADOQuery1->Active = false;
    }
    FormCosts->ADOQuery1->SQL->Text = "SELECT * FROM Costs";
    FormCosts->ADOQuery1->Active = true;
    
	DBGrid1->SelectedRows->CurrentRowSelected = true;
	// Считаем общую прибыль и выводим в лейбл
    int label = 0;
    /*if(ADOQuery1->RecordCount != 0)
    {
        ADOQuery1->FindFirst();
        while(!ADOQuery1->Eof)
        {
            label = StrToInt(Label3->Caption) + ADOQuery1->Fields->FieldByName("Доход")->AsInteger; 
            Label3->Caption = label;
            ADOQuery1->Next();
        }
        
    }*/
    Label3->Caption = IniFile->ReadString("Resource", "ofMonth", IntToStr(label));
    // Считаем доходы
    if(ADOQuery1->RecordCount != 0) // Если есть хоть 1 запись, то пошло-поехало...
    {
        
        ADOQuery1->First();
        // цикл по таблице доходов
        int SumIncomeMonthly = 0, IncomeMonthly = 0, IncomeWeekly = 0;
        while(!ADOQuery1->Eof)
        {
            // определяем сколько "доходных" дней прошло с последнего захода
            int CountDay = DayCountLastDate(ADOQuery1->Fields->FieldByName("Дата/День")->AsInteger, ADOQuery1->Fields->FieldByName("Периодичность")->AsString);
            //Memo1->Lines->Add("Дней: "+IntToStr(CountDay)+" "+ADOQuery1->Fields->FieldByName("Дата/День")->AsString+", "+ ADOQuery1->Fields->FieldByName("Периодичность")->AsString); 
            //Memo1->Lines->Add(ADOQuery1->Fields->FieldByName("Периодичность")->AsString+" == Ежемесячный && "+ADOQuery1->Fields->FieldByName("Получен")->AsString+" == 0 && "+FormatDateTime("d", Now())+" >= "+ADOQuery1->Fields->FieldByName("Дата/День")->AsString+" || "+IntToStr(CountDay)+" != 0");
            // Ежемесячный доход
            if(ADOQuery1->Fields->FieldByName("Периодичность")->AsString == "Ежемесячный")
            {
                if((ADOQuery1->Fields->FieldByName("Периодичность")->AsString == "Ежемесячный" && ADOQuery1->Fields->FieldByName("Получен")->AsInteger == 0 && StrToInt(FormatDateTime("d", Now())) >= ADOQuery1->Fields->FieldByName("Дата/День")->AsInteger) || CountDay != 0)
                {
                    if(CountDay == 0)
                    {
                        SumIncomeMonthly += ADOQuery1->Fields->FieldByName("Стоимость")->AsInteger;
                    }
                    else
                    {
                        SumIncomeMonthly += ADOQuery1->Fields->FieldByName("Стоимость")->AsInteger * CountDay;
                    }
                    ADOQuery2->SQL->Text = "UPDATE `Resource` SET `Получен`=1 WHERE `ID`="+ADOQuery1->Fields->FieldByName("ID")->AsString+";";
                    ADOQuery2->ExecSQL();
                    ADOQuery2->Close();
                }
                if(StrToInt(FormatDateTime("d", Now())) < ADOQuery1->Fields->FieldByName("Дата/День")->AsInteger)
                {
                    ADOQuery2->SQL->Text = "UPDATE `Resource` SET `Получен`=0 WHERE `ID`="+ADOQuery1->Fields->FieldByName("ID")->AsString+";";
                    ADOQuery2->ExecSQL();
                    ADOQuery2->Close();
                }
                IncomeMonthly += ADOQuery1->Fields->FieldByName("Стоимость")->AsInteger;
            }
                        
            // Еженедельный доход
            if(ADOQuery1->Fields->FieldByName("Периодичность")->AsString == "Еженедельный")
            {
                int WeekDayNow = DayOfWeek(StrToDate(FormatDateTime("dd.mm.yyyy", Now())))-1;
                if(WeekDayNow == 0)
                {
                    WeekDayNow = 7;
                }
                if(ADOQuery1->Fields->FieldByName("Периодичность")->AsString == "Еженедельный" && ADOQuery1->Fields->FieldByName("Получен")->AsInteger == 0 && WeekDayNow >= ADOQuery1->Fields->FieldByName("Дата/День")->AsInteger)
                {
                    SumIncomeMonthly += ADOQuery1->Fields->FieldByName("Стоимость")->AsInteger;
                    ADOQuery2->SQL->Text = "UPDATE `Resource` SET `Получен`=1 WHERE `ID`="+ADOQuery1->Fields->FieldByName("ID")->AsString+";";
                    ADOQuery2->ExecSQL();
                    ADOQuery2->Close();
                }
                if(WeekDayNow < ADOQuery1->Fields->FieldByName("Дата/День")->AsInteger)
                {
                    ADOQuery2->SQL->Text = "UPDATE `Resource` SET `Получен`=0 WHERE `ID`="+ADOQuery1->Fields->FieldByName("ID")->AsString+";";
                    ADOQuery2->ExecSQL();
                    ADOQuery2->Close();
                }
                IncomeWeekly += ADOQuery1->Fields->FieldByName("Стоимость")->AsInteger * DayOfMonth(ADOQuery1->Fields->FieldByName("Дата/День")->AsInteger);
            }
            
            ADOQuery1->Next();
        }
        Label3->Caption = IntToStr(StrToInt(Label3->Caption) + SumIncomeMonthly); // Добавляем ежемесячный доход
        
        Label10->Caption = IntToStr(IncomeMonthly + IncomeWeekly); 
        Label12->Caption = IntToStr(IncomeWeekly);       
    }
    
    if(FormCosts->ADOQuery1->Active)
    {
        FormCosts->ADOQuery1->Active = false;
    }
    FormCosts->ADOQuery1->SQL->Text = "SELECT * FROM Costs";
    FormCosts->ADOQuery1->Active = true;
    // Если есть рассходы то мы их суммитруем и вычитаем из доходов если время пришло
    //FormRes->Caption = Now() - StrToInt(FormatDateTime("d", Now()))+1; // Первое число настоящего месяца
    //FormRes->Caption = FormatDateTime("dd.mm.yyyy", Now() + (MonthDays[IsLeapYear(StrToInt(FormatDateTime("yyyy", Now())))][StrToInt(FormatDateTime("m", Now()))] - StrToInt(FormatDateTime("d", Now())))-1); /// Последнее число наст. месяца
    // Здесть происходит вычитание расходов в определенные дни
    if(FormCosts->ADOQuery1->RecordCount != 0)
    {
        FormCosts->ADOQuery1->First();
        // Вычитание расходов в установленные дни
        int ExpenseMonth = 0, ExpenseWeek = 0, SumAllCosts = 0;;        
        while(!FormCosts->ADOQuery1->Eof)
        {
            // Ежемесячный
            if(FormCosts->ADOQuery1->Fields->FieldByName("Периодичность")->AsString == "Ежемесячный" && FormCosts->ADOQuery1->Fields->FieldByName("Вычитать")->AsInteger == 1)
            {
                // Ежемесячный расход вычитается по указанной дате в расходе один раз.
                // Если расход не вычтен, то вычитаем
                int DayCount = 0;
                TDateTime tmpDate = LastDate;
                // Циклим даты, если есть в диапазоне "расходная" дата, то плюсуем переменную
                // Считаем, сколько "расходных" дат в нашем диапазоне (Последнаяя дата захода < Наст. дата)
                while(StrToDate(FormatDateTime("dd.mm.yyyy", tmpDate)) < StrToDate(FormatDateTime("dd.mm.yyyy", Now())))
                {   
                    // Сравниваем текущий щетчик с датой из таблицы текущей записи
                    if(StrToInt(FormatDateTime("d", tmpDate)) == StrToInt(FormatDateTime("d", FormCosts->ADOQuery1->Fields->FieldByName("Дата/День")->AsDateTime)))
                    {
                        DayCount++;    // Количество "расходных" дней
                    }
                    tmpDate += 1.0;              
                }
                //FormRes->Caption = FormCosts->ADOQuery1->Fields->FieldByName("Получен")->AsString+" == 0 && "+DateToStr(FormCosts->ADOQuery1->Fields->FieldByName("Дата")->AsDateTime)+" >= "+DateToStr(Now());
                // Если текущий расход не получен (равен 0) и сегоднящная дата больше либо равна дате текущего расхода ИЛИ мы пропустили "расходные" дни, (фуф блин, ну и условие Оо)
                if((FormCosts->ADOQuery1->Fields->FieldByName("Получен")->AsInteger == 0 && StrToDate(FormatDateTime("dd.mm.yyyy", FormCosts->ADOQuery1->Fields->FieldByName("Дата/День")->AsDateTime)) <= StrToDate(FormatDateTime("dd.mm.yyyy", Now()))) || DayCount != 0)
                {
                    // то мы суммирем текущий расход с предыдущем
                    // если мы пропустили "расходный" день
                    if(DayCount != 0)
                    {
                        // То умножаем текущий расход на количество пропущенных "расходных" дней
                        ExpenseMonth += FormCosts->ADOQuery1->Fields->FieldByName("Стоимость")->AsInteger * DayCount;
                    }
                    else
                    {
                        ExpenseMonth += FormCosts->ADOQuery1->Fields->FieldByName("Стоимость")->AsInteger;
                    }
                    Label3->Caption = IntToStr(StrToInt(Label3->Caption) - ExpenseMonth);
                    //Label6->Caption = IntToStr(ExpenseMonth);
                    // Кидаем запрос на изменеия поля "Получен", меняем на 1, значит расход получен
                    FormCosts->ADOQuery2->SQL->Text = "UPDATE `Costs` SET `Получен`=1 WHERE `ID`="+FormCosts->ADOQuery1->Fields->FieldByName("ID")->AsString+";";
                    FormCosts->ADOQuery2->ExecSQL();
                    FormCosts->ADOQuery2->Close();
                }
                // Если Текущая дата меньше даты текущего расхода
                if(StrToDate(FormatDateTime("dd.mm.yyyy", FormCosts->ADOQuery1->Fields->FieldByName("Дата/День")->AsDateTime)) > StrToDate(FormatDateTime("dd.mm.yyyy", Now())))
                {
                    // То изменяем поле "Получен" на 0, короче сбрасываем.
                    FormCosts->ADOQuery2->SQL->Text = "UPDATE `Costs` SET `Получен`=0 WHERE `ID`="+FormCosts->ADOQuery1->Fields->FieldByName("ID")->AsString+";";
                    FormCosts->ADOQuery2->ExecSQL();
                    FormCosts->ADOQuery2->Close();
                }
                
            }
            // Еженедельный
            if(FormCosts->ADOQuery1->Fields->FieldByName("Периодичность")->AsString == "Еженедельный" && FormCosts->ADOQuery1->Fields->FieldByName("Вычитать")->AsInteger == 1)
            {
                // Берем дату данного ежемесячного расхода. И сравниваем ее с начтоящей датой, Если дата = натоящей, то вычитаем расход
                // И надо установить флаг, что мы его уже вычтили. Если наст. дата больше, а расход не вычтен, то вычитаем и устанавливаем 
                // флаг, что расход вычтен. Так же, если пользователь давно не заходил, считаем сколько "расходных" дней прошло
                // с момента последнего захода.
                TDateTime tmpDate = LastDate; // Запоминаем даты последнего захода в прогу
                int CountDay = 0;
                int NowDay = DayOfWeek(Now())-1; // Определяем день недели по дате
                int ExDay = DayOfWeek(StrToDate(FormatDateTime("dd.mm.yyyy", FormCosts->ADOQuery1->Fields->FieldByName("Дата/День")->AsDateTime)))-1;
                if(NowDay == 0)
                {
                    NowDay = 7;
                }
                if(ExDay == 0)
                {
                    ExDay = 7;
                }
                // Считаем "расходные" дни
                int ExDayCo = 0;
                while(StrToDate(FormatDateTime("dd.mm.yyyy", tmpDate)) < StrToDate(FormatDateTime("dd.mm.yyyy", Now())))
                {                                     
                    ExDayCo = DayOfWeek(tmpDate)-1;
                    if(ExDayCo == 0)
                    {
                        ExDayCo = 7;
                    }
                    if(ExDayCo == NowDay)
                    {                        
                        CountDay++;
                    }
                    tmpDate += 1.0;
                }
                if((FormCosts->ADOQuery1->Fields->FieldByName("Получен")->AsInteger == 0 && NowDay >= ExDay) || CountDay != 0)
                {
                    if(CountDay != 0)
                    {
                        ExpenseWeek += FormCosts->ADOQuery1->Fields->FieldByName("Стоимость")->AsInteger * CountDay;
                    }
                    else
                    {
                        ExpenseWeek += FormCosts->ADOQuery1->Fields->FieldByName("Стоимость")->AsInteger;
                    }
                    Label3->Caption = IntToStr(StrToInt(Label3->Caption) - ExpenseWeek);
                    FormCosts->ADOQuery2->SQL->Text = "UPDATE `Costs` SET `Получен`=1 WHERE `ID`="+FormCosts->ADOQuery1->Fields->FieldByName("ID")->AsString+";";
                    FormCosts->ADOQuery2->ExecSQL();
                    FormCosts->ADOQuery2->Close();
                    
                }
                // Если Текущая дата меньше даты текущего расхода
                if(NowDay < ExDay)
                {
                    // То изменяем поле "Получен" на 0, короче сбрасываем.
                    FormCosts->ADOQuery2->SQL->Text = "UPDATE `Costs` SET `Получен`=0 WHERE `ID`="+FormCosts->ADOQuery1->Fields->FieldByName("ID")->AsString+";";
                    FormCosts->ADOQuery2->ExecSQL();
                    FormCosts->ADOQuery2->Close();
                }               
                
            }
            // Считаем общие расходы за месяц
            TDateTime DateMonStart = Now() - StrToInt(FormatDateTime("d", Now()))+1;
            TDateTime DateMonEnd = Now() + (MonthDays[IsLeapYear(StrToInt(FormatDateTime("yyyy", Now())))][StrToInt(FormatDateTime("m", Now()))] - StrToInt(FormatDateTime("d", Now())))-1;
            if(FormCosts->ADOQuery1->Fields->FieldByName("Дата/День")->AsDateTime >= DateMonStart && FormCosts->ADOQuery1->Fields->FieldByName("Дата/День")->AsDateTime <= DateMonEnd)
            {
                SumAllCosts += FormCosts->ADOQuery1->Fields->FieldByName("Стоимость")->AsInteger;
            }
            Label14->Caption = IntToStr(SumAllCosts);

            // Общие расходы за текущую неделю
            // Надо определить какой сейчас по счету день недели. Вычесть полученное число из текущей даты.
            // Так мы получим дату начала текущей недели, от нее мы и будем крутить цикл. Затем, надо получить
            // дату конца текущей недели. Для этого прибавляем число 6 к дате начала текущей недели.
            int SumWeekAllEx = 0; // Определяем день недели по дате
            int NowDay = DayOfWeek(Now())-1;
            if(NowDay == 0)
            {
                NowDay = 7;
            }
            // Определяем дату начала и конца текущей недели
            TDateTime StartCurrentWeek = Now() - NowDay + 1, EndCurrentWeek = StartCurrentWeek + 6;
            //FormRes->Caption = DateToStr(StartCurrentWeek) + " - " + DateToStr(EndCurrentWeek);
            while(StrToDate(FormatDateTime("dd.mm.yyyy", StartCurrentWeek)) <= StrToDate(FormatDateTime("dd.mm.yyyy", EndCurrentWeek)))
            {
                if(FormCosts->ADOQuery1->Fields->FieldByName("Периодичность")->AsString != "Еженедельный")
                {
                    if(StrToDate(FormatDateTime("dd.mm.yyyy", FormCosts->ADOQuery1->Fields->FieldByName("Дата/День")->AsDateTime)) == StrToDate(FormatDateTime("dd.mm.yyyy", StartCurrentWeek)))
                    {
                        SumWeekAllEx += FormCosts->ADOQuery1->Fields->FieldByName("Стоимость")->AsInteger;
                    }
                }
                else
                {
                    SumWeekAllEx += FormCosts->ADOQuery1->Fields->FieldByName("Стоимость")->AsInteger;
                }
                
                StartCurrentWeek += 1;
            }
            Label16->Caption = IntToStr(SumWeekAllEx);
            // следующая запись в таблице
            FormCosts->ADOQuery1->Next();
        }
        // Общие затраты за текщий месяц
        if(FormCosts->ADOQuery2->Active)
        {
            FormCosts->ADOQuery2->Active = false;
        }
        FormCosts->ADOQuery2->SQL->Text = "SELECT * FROM Costs";
        FormCosts->ADOQuery2->Active = true;
         
        int sum = 0, WeekSum = 0;
        TDateTime DateMonStart = Now() - StrToInt(FormatDateTime("d", Now()))+1;
        TDateTime DateMonEnd = Now() + (MonthDays[IsLeapYear(StrToInt(FormatDateTime("yyyy", Now())))][StrToInt(FormatDateTime("m", Now()))] - StrToInt(FormatDateTime("d", Now())))-1;
        int CountDay = 0, Day = DayOfWeek(DateMonStart)-1;    
        // считаем затраты
        FormCosts->ADOQuery1->First();
        while(!FormCosts->ADOQuery1->Eof)
        {
            if(FormCosts->ADOQuery1->Fields->FieldByName("Периодичность")->AsString == "Ежемесячный" && FormCosts->ADOQuery1->Fields->FieldByName("Вычитать")->AsInteger == 1)
            {
                sum += FormCosts->ADOQuery1->Fields->FieldByName("Стоимость")->AsInteger;
            }
            if(FormCosts->ADOQuery1->Fields->FieldByName("Периодичность")->AsString == "Еженедельный" && FormCosts->ADOQuery1->Fields->FieldByName("Вычитать")->AsInteger == 1)
            {
                // Складываем еженедельный доход, но сначала нужно подсчитать
                // сколько "расходных" дней в текущем месяце
                int DayEx = DayOfWeek(StrToDate(FormatDateTime("dd.mm.yyyy", FormCosts->ADOQuery1->Fields->FieldByName("Дата/День")->AsDateTime)))-1;
                if(DayEx == 0)
                {
                    DayEx = 7;
                }
                while(DateMonStart <= DateMonEnd)
                {
                    Day = DayOfWeek(DateMonStart)-1;
                    if(Day == 0)
                    {
                        Day = 7;
                    }
                    if(Day == DayEx)
                    {
                        CountDay++;
                    }
                    DateMonStart += 1.0;
                }
                WeekSum += FormCosts->ADOQuery1->Fields->FieldByName("Стоимость")->AsInteger;
            }
            FormCosts->ADOQuery1->Next();
        }
        Label8->Caption = IntToStr(WeekSum);
        WeekSum *= CountDay;
        sum += WeekSum;                
        Label6->Caption = IntToStr(sum);
        if(FormCosts->ADOQuery1->Active)
        {
            FormCosts->ADOQuery1->Active = false;
        }
        FormCosts->ADOQuery1->SQL->Text = "SELECT * FROM Costs";
        FormCosts->ADOQuery1->Active = true;
    }
    if(FormCosts->ADOQuery1->Active || FormCosts->ADOQuery2->Active)
    {
        FormCosts->ADOQuery1->Active = false;
        FormCosts->ADOQuery2->Active = false;
    }
    FormCosts->ADOQuery1->SQL->Text = "SELECT * FROM Costs";
    FormCosts->ADOQuery2->SQL->Text = "SELECT * FROM Costs";
    FormCosts->ADOQuery1->Active = true; 
    FormCosts->ADOQuery2->Active = true; 
    ShowScrollBar(DBGrid1->Handle, SB_BOTH, false);
    FormResize(NULL);
        
}
//---------------------------------------------------------------------------

void __fastcall TFormRes::Button1Click(TObject *Sender)
{
    AnsiString TableName = "";
    if(TabControl1->TabIndex == 0)
    {
        TableName = "Resource";
    }
    if(TabControl1->TabIndex == 1)
    {
        TableName = "Costs";
    }
	if(ADOQuery1->RecordCount != 0)
	{
		ADOQuery1->SQL->Text = "DELETE FROM `"+TableName+"` WHERE `ID`="+ADOQuery1->Fields->FieldByName("ID")->AsString+";";
		ADOQuery1->ExecSQL();
		if(ADOQuery1->Active)
		{
			ADOQuery1->Active = false;
		}
		ADOQuery1->SQL->Text = "SELECT * FROM `"+TableName+"`";
		ADOQuery1->Active = true;
	}
	else
	{
        ShowMessage("Удалять нечего.");
    }
	FormShow(NULL);
}
//---------------------------------------------------------------------------


void __fastcall TFormRes::DBGrid1CellClick(TColumn *Column)
{
	if(ADOQuery1->RecordCount != 0)
	{
        ComboBox2->Visible = true;
        EditName->Text = ADOQuery1->Fields->FieldByName("Название")->AsString;
        Edit1->Text = ADOQuery1->Fields->FieldByName("Стоимость")->AsString;
		ComboBox1->Text = ADOQuery1->Fields->FieldByName("Периодичность")->AsString;        
        if(ComboBox1->Text == "Еженедельный")
        {
            ComboBox2->Clear();
            ComboBox2->Items->Add("Понедельник");
            ComboBox2->Items->Add("Вторник");
            ComboBox2->Items->Add("Среда");
            ComboBox2->Items->Add("Четверг");
            ComboBox2->Items->Add("Пятница");
            ComboBox2->Items->Add("Суббота");
            ComboBox2->Items->Add("Воскресение");
            if(TabControl1->TabIndex == 0)
            {
                ComboBox2->ItemIndex = ADOQuery1->Fields->FieldByName("Дата/День")->AsInteger-1;
            }
            if(TabControl1->TabIndex == 1)
            {
                int DayFromColumn = DayOfWeek(ADOQuery1->Fields->FieldByName("Дата/День")->AsDateTime)-1;
                if(DayFromColumn == 0)
                {
                    DayFromColumn = 7;
                }
                ComboBox2->ItemIndex = DayFromColumn-1;
            }
            
        }
        if(ComboBox1->Text == "Ежемесячный")
        {
            ComboBox2->Clear();
            for(int i = 1; i < 31; i++)
            {
                ComboBox2->Items->Add(IntToStr(i));
            }
            if(TabControl1->TabIndex == 0)
            {
                ComboBox2->Text = ADOQuery1->Fields->FieldByName("Дата/День")->AsInteger;
            }
            if(TabControl1->TabIndex == 1)
            {
                ComboBox2->ItemIndex = StrToInt(FormatDateTime("d", ADOQuery1->Fields->FieldByName("Дата/День")->AsDateTime))-1;
            }            
        }
        if(ComboBox1->Text == "Одноразовый")
        {
            ComboBox2->Visible = false;
        }
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormRes::ComboBox1Change(TObject *Sender)
{
    ComboBox2->Visible = true;
    if(ComboBox1->Text == "Ежемесячный")
    {
        ComboBox2->Clear();
        for(int i = 1; i < 31; i++)
        {
            ComboBox2->Items->Add(IntToStr(i));
        }
        
    }
    if(ComboBox1->Text == "Еженедельный")
    {
        ComboBox2->Clear();
        ComboBox2->Items->Add("Понедельник");
        ComboBox2->Items->Add("Вторник");
        ComboBox2->Items->Add("Среда");
        ComboBox2->Items->Add("Четверг");
        ComboBox2->Items->Add("Пятница");
        ComboBox2->Items->Add("Суббота");
        ComboBox2->Items->Add("Воскресение");
    }
    if(ComboBox1->Text == "Одноразовый")
    {
        ComboBox2->Visible = false;
    }
    ComboBox2->ItemIndex = 0;
    ShowScrollBar(DBGrid1->Handle, SB_BOTH, false);
}
//---------------------------------------------------------------------------

void __fastcall TFormRes::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
	// Ограниченный ввод символов в поле стоимости
	if((Key != VK_RETURN) && (Key != VK_BACK) && (Key < '0' || Key > '9'))
	{
		Key=0;
	}
	/*if(Key == VK_RETURN)
	{
		ADOQuery1->SQL->Text = "UPDATE Resource SET `Доход`='"+Edit1->Text+"' WHERE `ID`="+ADOQuery1->Fields->FieldByName("ID")->AsString+";";
		ADOQuery1->ExecSQL();
		if(ADOQuery1->Active)
		{
			ADOQuery1->Active = false;
		}
		ADOQuery1->SQL->Text = "SELECT * FROM Resource";
		ADOQuery1->Active = true;
	}  */

}
//---------------------------------------------------------------------------



void __fastcall TFormRes::Edit2KeyPress(TObject *Sender, System::WideChar &Key)

{
	if((Key != VK_BACK) && (Key < '0' || Key > '9'))
	{
		Key=0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormRes::Button3Click(TObject *Sender)
{
	Label3->Caption = IntToStr(StrToInt(Label3->Caption) + StrToInt(Edit2->Text));
    Form1->Label3->Caption = "Средства: " + FormRes->Label3->Caption;
}
//---------------------------------------------------------------------------

void __fastcall TFormRes::Button2Click(TObject *Sender)
{
	if(StrToInt(Label3->Caption) != 0)
	{
		if(StrToInt(Label3->Caption) - StrToInt(Edit2->Text) >= 0)
		{
			Label3->Caption = IntToStr(StrToInt(Label3->Caption) - StrToInt(Edit2->Text));
		}
		else
		{
			ShowMessage("Слишком большое число вычитания!");
        }
	}
	else
	{
        ShowMessage("Не и из чего вычитать!");
    }
    Form1->Label3->Caption = "Средства: " + FormRes->Label3->Caption;
}
//---------------------------------------------------------------------------

void __fastcall TFormRes::FormClose(TObject *Sender, TCloseAction &Action)
{
    // Сохраняем переменные
    Form1->Label3->Caption = "Средства: " + FormRes->Label3->Caption;
    IniFile->WriteString("Resource", "ofMonth", Label3->Caption); 
    IniFile->WriteInteger("Resource", "WeeklyFlag", WeeklyFlag);   
    IniFile->WriteInteger("Resource", "DailyFlag", DailyFlag);
    for(int i = 0; i < 12; i++)
    {
        IniFile->WriteInteger("MonthGet", "Month"+IntToStr(i), MonthGet[i]);
    }
    IniFile->WriteDate("Date", "LastDateRun", Now());
    IniFile->WriteTime("Date", "LastTimeRun", Time());
    flagTab = 0;  
}
//---------------------------------------------------------------------------

void __fastcall TFormRes::ComboBox1KeyPress(TObject *Sender, System::WideChar &Key)          
{
    Key = 0;    
}
//---------------------------------------------------------------------------

void __fastcall TFormRes::DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State)
{ 
    /*DBGrid1->Canvas->Font->Color = clBlack;
    if(State.Contains(Grids::gdSelected))
    {
        DBGrid1->Canvas->Brush->Color = clSkyBlue;
    }
    DBGrid1->Canvas->FillRect(Rect);
    DBGrid1->Canvas->TextOut(Rect.Left+2, Rect.Top+2, Column->Field->Text);*/
    //ShowScrollBar(DBGrid1->Handle, SB_BOTH, false);   
}
//---------------------------------------------------------------------------
//              Событие при нажатии на вкладки TabControl'а                --
//---------------------------------------------------------------------------
void __fastcall TFormRes::TabControl1Change(TObject *Sender)
{
    EditName->Text = "";
    Edit1->Text = "";
    GroupBox2->Visible = true;
    ComboBox2->Visible = true;
    GroupBox3->Visible = false;
    switch(TabControl1->TabIndex)    
    {
        case 0: // Первая вкладка "Доходы"
        {
            // Выбираем данные из таблицы доходов
            if(ADOQuery1->Active)
            {
                ADOQuery1->Active = false;
            }
            ADOQuery1->SQL->Text = "SELECT * FROM `Resource`";
            ADOQuery1->Active = true;
            // Устанавливаем размер формы
            FormRes->Height = 364;
            FormRes->Width = 892;
            // Очищаем и заполняем ComboBox1
            ComboBox1->Clear();
            ComboBox1->Items->Add("Ежемесячный");
            ComboBox1->Items->Add("Еженедельный");
        } break;
        case 1: // Вторая вкладка "Расходы"
        {
            // Выбираем данные из таблицы расходов
            if(ADOQuery1->Active)
            {
                ADOQuery1->Active = false;
            }
            ADOQuery1->SQL->Text = "SELECT * FROM `Costs`";
            ADOQuery1->Active = true;
            // Устанавливаем размер формы
            FormRes->Height = 364;
            FormRes->Width = 892;
            // Очищаем и заполняем ComboBox1
            ComboBox1->Clear();
            ComboBox1->Items->Add("Одноразовый");
            ComboBox1->Items->Add("Ежемесячный");
            ComboBox1->Items->Add("Еженедельный");
        } break;
        case 2: // Третья вкладка "Расчеты"
        {
            // Скрываем таблицу и кнопки
            GroupBox2->Visible = false;
            GroupBox3->Visible = true;
            // Устанавливаем размер формы
            FormRes->Height = 400;
            FormRes->Width = 750;
        } break;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormRes::DateTimePicker1Change(TObject *Sender)
{
    Series1->Clear();
    Chart1->Title->Caption = "Расходы за "+FormatDateTime("MMMM.yyyy", DateTimePicker1->Date);
    if(ADOQuery1->Active)
    {
        ADOQuery1->Active = false;
    }
    ADOQuery1->SQL->Text = "SELECT * FROM `Costs`";
    ADOQuery1->Active = true;
    if(ADOQuery1->RecordCount != 0)
    {   
        ADOQuery1->First();
        while(!ADOQuery1->Eof)
        {
            if(StrToInt(FormatDateTime("M", ADOQuery1->Fields->FieldByName("Дата/День")->AsDateTime)) == StrToInt(FormatDateTime("M", DateTimePicker1->Date)))
            {
                Series1->Add(ADOQuery1->Fields->FieldByName("Стоимость")->AsInteger, ADOQuery1->Fields->FieldByName("Название")->AsAnsiString);
            }
            ADOQuery1->Next();
        }
        //Series1->CustomXRadius = 100;
        //Series1->CustomYRadius = 100;
    }
    else
    {
        ShowMessage("Расходов нет.");
    }
}
//---------------------------------------------------------------------------


