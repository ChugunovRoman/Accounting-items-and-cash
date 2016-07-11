//---------------------------------------------------------------------------

#include <vcl.h>
#include <Dateutils.hpp>
#pragma hdrstop
#include "PngImage.hpp"
#include "IniFiles.hpp"

#include "UnitDBThings.h" // Заголовок главной формы
#include "Unit2DBThings.h" // Заголовок второй формы (добавление или редактирование вещи)
#include "UnitImgBig.h" // Заголовок формы увеличенной картинки
#include "UnitSettings.h" // Заголовок формы настроек
#include "UnitResource.h" // Форма ресурсов
#include "UnitCosts.h" // юнит расходов
#include "UnitNC.h" // Форма добавлеения новой категории
#include "UnitCalc.h"  // Форма расчетов

#include "ShellAPI.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
TPngImage *png = new TPngImage; // Для хранения картинок png

std::vector<TImage*> imgcls(6); // TImage'ы содержащие картинку удаления фотки
std::vector<TButton*> BtnLoad(6); // Кнопки для загрузки одной картинки
std::vector<TImage*> SelectFace(2); // Рамка выделения

TImage *ImageFace;
int FlagTag = 0, FlagCount = 0; // Для передачи свойства Tag
AnsiString IDImageFortables = "", id = "", ImgType = "", FaceImageString = "", ArrayNameImage[6], DeleteImages[6]; // Запомним туда имена загруженных картинок
int AllCountImage = 0; // Этой переменной считаем общее количество загруженных фоток
TIniFile *IniFile = new TIniFile(ChangeFileExt(Application->ExeName, ".INI"));
bool Check1Checked = true;
//---------------------------------------------------------------------------
AnsiString __fastcall TForm2::ReturnFullFileName(AnsiString FilePath)
{
    // Функция фозвращает имя файла, без пути
	int index;
	//AnsiString FileName = "";
	for(int i = 1; i < FilePath.Length(); i++)
	{
		if(FilePath.SubString(i, 1) == "\\")
		{
        	index = i;
		}
	}
	/*while(FilePath.Length() && FilePath.SubString(i, 1) != "\")
	{
		FileName += FilePath[i];
		i++;
	}*/
	return FilePath.SubString(++index, FilePath.Length());
}
//---------------------------------------------------------------------------
AnsiString __fastcall TForm2::ReturnFileName(AnsiString FilePath)
{
	// Эта функция получает имя файла с расширением,
	// а возвращает имя этого же файла без расширения
	int i = 1;
	AnsiString FileName = "";
	while(FilePath.Length() && FilePath.SubString(i, 1) != ".")
	{
		FileName += FilePath[i];
		i++;
	}
	return FileName;
}
//---------------------------------------------------------------------------
int __fastcall TForm2::FilingID(AnsiString TableName)
{
	// Функция возвращает следующий свободний ID
	// Если номера ID идут так: 1,2,3,5
	// То функция возвратит число 4, т.к. его нету, а значить это свободное место        
    //Form1->ADOQuery1->Active = true;
    
    
    Form1->ADOQuery1->Active = true;
    Form1->ADOQuery1->First();
    while(!Form1->ADOQuery1->Eof)
    {
        Form1->ADOQuery2->SQL->Text = "UPDATE `"+TableName+"` SET `ID`= "+IntToStr(Form1->ADOQuery1->RecNo)+" WHERE `ID`= " + Form1->ADOQuery1->FieldByName("ID")->AsString + ";";
        Form1->ADOQuery2->ExecSQL();
        Form1->ADOQuery2->Close();
        Form1->ADOQuery1->Next();
    }
    Form1->ADOQuery1->First();
    Form2->UpdateComboBox1(); // Обновляем список ComboBox1
    Form2->ResetQuery1();
    Form1->ADOQuery1->FindLast();
    return Form1->ADOQuery1->FieldByName("ID")->AsInteger+1;
    Form1->ADOQuery1->FindFirst();

}
//---------------------------------------------------------------------------
AnsiString __fastcall TForm2::ReturnTypeFile(AnsiString Path, boolean Points)
{
	// Данная функция возвращает расширение файла
	// Если переданный параметр Points = true, значит возвращаем расширение без точки (jpg)
	// Если переданный параметр Points = false, значит возвращаем расширение с точкой (.jpg)
	int i2, indexPoint;
	AnsiString tmp = "";
	// Цикл от 0 до последнего символа в строке Path
	for(i2 = 0; i2 <= Path.Length(); i2++)
	{
		if(Path.SubString(i2, 1) == ".")
		{
			indexPoint = i2; // запоминаем последние фхождение в строку символа "."
		}

	}
	if(Points)
	{
		return Path.SubString(indexPoint+1, Path.Length());
	}
	else
	{
		return "."+Path.SubString(indexPoint+1, Path.Length());
	}
	
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ResetQuery1()
{
	// Функция для возврата к предыдущему состоянию ADOQuery
	// После посылки запроса, не возвращающего резульлат
	for(int i = 0; i < Form1->ComboBox1->Items->Count; i++)
	{
		// Нулевой элемент всегда должен быть "Все категории"
		if(Form1->ComboBox1->ItemIndex == 0)
		{
			if(Form1->ADOQuery1->Active)
			{
				Form1->ADOQuery1->Active = false;
			}
			Form1->ADOQuery1->SQL->Strings[0] = "SELECT * FROM things";
			Form1->ADOQuery1->Active = true;
			break;
		}
		else
		{
			if(Form1->ADOQuery1->Active)
			{
				Form1->ADOQuery1->Active = false;
			}
			Form1->ADOQuery1->SQL->Strings[0] = "SELECT * FROM things WHERE Category='" + Form1->ComboBox1->Text + "'";
			Form1->ADOQuery1->Active = true;
			break;
		}

	}
	Form1->ComboBox1Change(Form1->ComboBox1);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::UpdateComboBox1()
{
	// Обновляем список категорий (ComboBox1)
	int IndexItem = Form1->ComboBox1->ItemIndex;
	if(Form1->ADOQuery1->Active)
	{
		Form1->ADOQuery1->Active = false;
	}
	Form1->ADOQuery1->SQL->Strings[0] = "SELECT * FROM Category"; // Формируем запрос на полную выборку
	Form1->ADOQuery1->Active = true; // Посылаем запрос на полную выборку
	Form1->ADOQuery1->FindFirst(); // Выбор первой записи в ADOQuery
	Form1->ComboBox1->Items->Clear();
	Form1->ComboBox1->Items->Add("Все категории"); // Сначало добавляем запись "Все категории", а уж в цикле категории
	for(int i = 0; i < Form1->ADOQuery1->RecordCount; i++) // Цикл от 0 до последней записи в ADOQuery
	{
		Form1->ComboBox1->Items->Add(Form1->ADOQuery1->Fields->FieldByName("Category")->AsAnsiString);
		Form1->ADOQuery1->Next(); // Выбор следующей строки в ADOQuery
	}
	Form1->ADOQuery1->FindFirst(); // Выбор первой записи в ADOQuery
	Form1->ComboBox1->ItemIndex = IndexItem; // Выбираем первый элемент ComboBox'а, срабатывает событие TForm1::ComboBox1Change(TObject *Sender)
}
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
	//Form1->ADOQuery1->SQL->Strings[0] = "SELECT * FROM things"; // Формируем запрос на полную выборку
	//Form1->ADOQuery1->Active = true; // Посылаем запрос на полную выборку
	/*TIniFile *IniFile = new TIniFile(ChangeFileExt(Application->ExeName, ".ini")); // Как должен создаться файл Имя_exe_файла.ini
	IniFile->WriteInteger("CountImage", "AllCountImage", AllCountImage);
	delete IniFile;   */
	// Скрываем Image'ы при закрытии формы
	for(int i = 0; i < 6; i++)
	{
		if(img[i] != NULL && img[i]->Visible == true)
		{
			img[i]->Visible = false;
			imgcls[i]->Visible = false;
		}
	}
	Form2->UpdateComboBox1(); // Обновляем список ComboBox1
	Form2->ResetQuery1();
	Form1->ScrollBox1->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	Close(); // Вызываем собитие FormClose
}
//---------------------------------------------------------------------------
//          Событие при нажатии на кнопку "Сохранить" или "Добавить"       --
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonSaveClick(TObject *Sender)
{
    // По сути, это одна кнопка. Но в зависимости от Caption'а этой кнопки
    // мы делаем разные действия.
    IDImageFortables = "";
	// Проверка пустых полей, тип их надо обязательно заполнить, это поля "Название", "Дата покупки", "Категория", "Стоимость"
	if(ThingName->Text != "" && ThingCategory->Text != "")
	{
		for(int i = 0; i < 6; i++)
		{
			// удаляем картинки которые были ранее загружены, но которые пользователь явно не удалил
			// (Просто нажал снова "Обзор" и загрузил другие фотки, предыдущие мы тогда удаляем)
			if(CompareText(ArrayNameImage[i], ReturnFullFileName(ArrayPathImages[i])) != 0)
			{
				DeleteFile("load\\" + ArrayNameImage[i]);
				//Form2->DescriptionMemo->Lines->Add("load\\" + ArrayNameImage[i]);
            }
			// Удаляем фотки, которые пользователь явно удалил (нажал на крестик)
			if(DeleteImages[i] != "" && DeleteImages[i] != ArrayPathImages[i])
			{
				DeleteFile(DeleteImages[i]);
			}
			// Если путь не пустой, значит добавляем эту фотку в список и кпируем в папку
			if(ArrayPathImages[i] != "")
			{
				MkDir("load"); // Создаем папку "load"
				//CreateDirectory(L"load", &sa);
				String ImgName = "load//" + ReturnFullFileName(ArrayPathImages[i]); // Устанавливаем путь к загруженной картинке
				IDImageFortables += ReturnFullFileName(ArrayPathImages[i]) + "*"; // Имя файлов помещаем в переменную через ","
				CopyFile(ArrayPathImages[i].w_str(), ImgName.w_str(), true); // Копируем загруженные фотки в папку "load"
				//DescriptionMemo->Lines->Add(ImgName);

			}
		}
        // Если введенной в ручную категории нет, то мы ее добавляем
        int flagcat = 0;
        if(Form1->ADOQuery2->Active)
        {
            Form1->ADOQuery2->Active = false;
        }
        Form1->ADOQuery2->SQL->Text = "SELECT * FROM Category";
        Form1->ADOQuery2->Active = true;
        Form1->ADOQuery2->First();
        for(int i = 0; i < Form1->ADOQuery2->RecordCount; i++)
        {
            if(ThingCategory->Text == Form1->ADOQuery2->Fields->FieldByName("Category")->AsString)
            {
                flagcat = 1;
            }
            Form1->ADOQuery2->Next();
        }
        if(flagcat == 0)
        {
            if(Form1->ADOQuery2->Active)
            {
                Form1->ADOQuery2->Active = false;
            }
            Form1->ADOQuery2->SQL->Text = "INSERT INTO Category VALUES('"+IntToStr(Form2->FilingID("Category"))+"', '"+ThingCategory->Text+"')";
            Form1->ADOQuery2->ExecSQL();
        }
        
		if(((TButton*)Sender)->Caption == "Добавить")
		{
            if(CheckBox1->Checked)
            {
                IniFile->WriteInteger("Resource", "ofMonth", IniFile->ReadInteger("Resource", "ofMonth", 0)  - StrToInt(ThingCost->Text));
                Form1->Label3->Caption = "Средства: " + IntToStr(IniFile->ReadInteger("Resource", "ofMonth", 0));
            }
			// Формируем запрос к базе на добавления новой записи с информацией из полей TLabeledEdit + TMemo
			Form1->ADOQuery1->SQL->Strings[0] = "INSERT INTO things VALUES('"+IntToStr(FilingID("things"))+"','"
																				+ThingName->Text+"','"
																				+DateToStr(ThingDOB->Date)+"','"
																				+ThingCost->Text+"','"
																				+ThingCategory->Text+"','"
																				+ThingShop->Text+"','"
																				+DescriptionMemo->Lines->GetText()+"','"
																				+IDImageFortables+"','"
																				+FaceImageString+"','"
                                                                                +IntToStr((int)CheckBox1->Checked)+"')";
			Form1->ADOQuery1->ExecSQL(); // Проворачиваем запрос

			ShowMessage("Вещь добавлена."); // Говорим пользователю, что запись добавлена (заменить на плавную форму)
		}
		else
		{
			// Формируем запрос к базе на добавления новой записи с информацией из полей TLabeledEdit + TMemo
			Form1->ADOQuery1->Active = false; // Вырубаем Query
			Form1->ADOQuery1->SQL->Clear();
			Form1->ADOQuery1->SQL->Add("UPDATE things SET Name='"+ThingName->Text+"' WHERE ID="+id+";");
			Form1->ADOQuery1->ExecSQL(); // Проворачиваем запрос
			Form1->ADOQuery1->Active = false; // Вырубаем Query
			Form1->ADOQuery1->SQL->Clear();
			Form1->ADOQuery1->SQL->Add("UPDATE things SET DOB='"+DateToStr(ThingDOB->Date)+"' WHERE ID="+id+";");
			Form1->ADOQuery1->ExecSQL(); // Проворачиваем запрос
			Form1->ADOQuery1->Active = false; // Вырубаем Query
			Form1->ADOQuery1->SQL->Clear();
			Form1->ADOQuery1->SQL->Add("UPDATE things SET Cost='"+ThingCost->Text+"' WHERE ID="+id+";");
			Form1->ADOQuery1->ExecSQL(); // Проворачиваем запрос
			Form1->ADOQuery1->Active = false; // Вырубаем Query
			Form1->ADOQuery1->SQL->Clear();
			Form1->ADOQuery1->SQL->Add("UPDATE things SET Category='"+ThingCategory->Text+"' WHERE ID="+id+";");
			Form1->ADOQuery1->ExecSQL(); // Проворачиваем запрос
			Form1->ADOQuery1->Active = false; // Вырубаем Query
			Form1->ADOQuery1->SQL->Clear();
			Form1->ADOQuery1->SQL->Add("UPDATE things SET NameShop='"+ThingShop->Text+"' WHERE ID="+id+";");
			Form1->ADOQuery1->ExecSQL(); // Проворачиваем запрос
			Form1->ADOQuery1->Active = false; // Вырубаем Query
			Form1->ADOQuery1->SQL->Clear();
			Form1->ADOQuery1->SQL->Add("UPDATE things SET AddInfo='"+DescriptionMemo->Lines->Text+"' WHERE ID="+id+";");
			Form1->ADOQuery1->ExecSQL(); // Проворачиваем запрос
			Form1->ADOQuery1->Active = false; // Вырубаем Query
			Form1->ADOQuery1->SQL->Clear();
			Form1->ADOQuery1->SQL->Add("UPDATE things SET Images='"+IDImageFortables+"' WHERE ID="+id+";");
			Form1->ADOQuery1->ExecSQL(); // Проворачиваем запрос
			Form1->ADOQuery1->Active = false; // Вырубаем Query
			Form1->ADOQuery1->SQL->Clear();
			Form1->ADOQuery1->SQL->Add("UPDATE things SET FaceImage='"+FaceImageString+"' WHERE ID="+id+";");
			Form1->ADOQuery1->ExecSQL(); // Проворачиваем запрос
            Form1->ADOQuery1->Active = false; // Вырубаем Query
			Form1->ADOQuery1->SQL->Clear();
			Form1->ADOQuery1->SQL->Add("UPDATE things SET Checked='"+IntToStr((int)CheckBox1->Checked)+"' WHERE ID="+id+";");
			Form1->ADOQuery1->ExecSQL(); // Проворачиваем запрос
            // Если чекнут, то вычитаем стоимость из средств, если нет, то и не вычитаем
            if(CheckBox1->Checked)
            {
                if(Check1Checked == false)
                {
                    IniFile->WriteInteger("Resource", "ofMonth", IniFile->ReadInteger("Resource", "ofMonth", 0)  - StrToInt(ThingCost->Text));
                    Form1->Label3->Caption = "Средства: " + IntToStr(IniFile->ReadInteger("Resource", "ofMonth", 0));
                }
                
            }
            else
            {
                if(Check1Checked == true)
                {
                    IniFile->WriteInteger("Resource", "ofMonth", IniFile->ReadInteger("Resource", "ofMonth", 0)  + StrToInt(ThingCost->Text));
                    Form1->Label3->Caption = "Средства: " + IntToStr(IniFile->ReadInteger("Resource", "ofMonth", 0));
                }
                
            }
			ShowMessage("Вещь обновлена."); // Говорим пользователю, что запись добавлена (заменить на плавную форму)
		}
		//UpdateComboBox1(); // Обновляем список ComboBox1
		Close(); // Закрываем форму

	}
	else // Если какое то из полей TLabeledEdit оказалось пустым
	{
        // Перечисляем эти 4 поля 		
		ShowMessage("Поля названия и категрии вещи не должны быть пустыми!"); // Показываем пользователю, какие поля он не заполнил
	}
}
//---------------------------------------------------------------------------
//      Событие при создании формы. Создаем картинки сеткой 3 на 2         --
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
	// при создании формы
	Form1->h = LoadLibrary(L"ProjectDLLIMG.dll"); // Тянем библу, она содержит элементы графического интерфейса
	png->LoadFromResourceName((unsigned int)Form1->h, "BGImageLoad"); // Вынимаем картинку из dll
	Image1->Picture->Assign(png); // втираем ее Image'у

	MenuAddThing->OnClick = Form1->Button1->OnClick;
	MenuSelect->OnClick = Form1->Button2->OnClick;
	MenuDelete->OnClick = Form1->ButtonDelete->OnClick;

	SelectFace[0] = new TImage(Form2);
	SelectFace[0]->Parent = Form2;
	SelectFace[0]->Name = "SelectBorderEdit";
	SelectFace[0]->Width = 109;
	SelectFace[0]->Height = 109;
	SelectFace[0]->Top = 170;
	SelectFace[0]->Left = 87;
	png->LoadFromResourceName((unsigned int)Form1->h, "SelectBorderEdit");
	SelectFace[0]->Picture->Assign(png);
	SelectFace[0]->Visible = false;

	int iTop = 0, iLeft = 0; // переменные для формирования картинок в 2 уровня, т.е. не ++++++, а +++
	for(int i = 0; i < 6; i++) // Сразу создаем 6 Image'во
	{
		// Надо проверить не были ли уже созданы Image'ы
		if(img[i] == NULL) // Если нет, то создаем
		{
			img[i] = new TImage(Form2); // Тут они создаются
			img[i]->Parent = Form2; // Устанавливается родитель
			img[i]->Name = "ImgLoad" + IntToStr(i); // Задается имя
			img[i]->Tag = i;
			img[i]->Width = 105;
			img[i]->Height = 105;
			img[i]->Top = 168+108*iTop;
			img[i]->Left = 12+108*iLeft;
			img[i]->OnMouseEnter = ImageCloseMouseEnter;
			img[i]->OnMouseLeave = ImageCloseMouseLeave;
			img[i]->Visible = false;
			img[i]->OnClick = ImgLoadClick; // И событие при нажатии на картинку
			img[i]->PopupMenu = PopupMenu1;
			img[i]->OnContextPopup = Label1->OnContextPopup;

			imgcls[i] = new TImage(Form2);
			imgcls[i]->Parent = Form2;
			imgcls[i]->Tag = i;
			imgcls[i]->Width = 22;
			imgcls[i]->Height = 14;
			imgcls[i]->Top = 172+108*iTop;
			imgcls[i]->Left = 89+108*iLeft;
			imgcls[i]->Stretch = true;
			png->LoadFromResourceName((unsigned int)Form1->h, "CloseWindowPoint");
			imgcls[i]->Picture->Assign(png);
			imgcls[i]->Visible = false;
			imgcls[i]->OnMouseEnter = ImageCloseMouseEnter;
			imgcls[i]->OnMouseLeave = ImageCloseMouseLeave;
			imgcls[i]->OnClick = ImageCloseClick;
			if(img[i]->Left >= 220)
			{
				iTop++;
				iLeft = -1;
			}
			img[i]->Stretch = true;
            //img[i]->Proportional = true;
			iLeft++;
		}
		img[i]->Picture->Bitmap = NULL;		
	} 
}
//---------------------------------------------------------------------------
//--        Нажатие на кнопку "Обзор", каждый раз догружает фотки          --
//---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click(TObject *Sender)
{   // Загрузка фоток в TImage
	OpenPictureDialog1->Options.operator +=(TOpenOptions() << ofAllowMultiSelect);
	if(OpenPictureDialog1->Execute()) // открываем Диалог загрузки изображений
	{
        int CountLoadImage = 0;
		for(int i = 0; i < 6; i++)
		{ 
            if(img[i]->Visible)
            {
                CountLoadImage++;
            } 
			if(FindComponent("BtnLoad" + IntToStr(i)))
			{
				BtnLoad[i]->Free();
			}
        }
		for(int i = CountLoadImage, j = 0; i < 6; i++)
		{
            if(!img[i]->Visible)
            {
                img[i]->Picture->LoadFromFile(OpenPictureDialog1->Files->Strings[j]);
                img[i]->Visible = true;

                ArrayPathImages[i] = OpenPictureDialog1->Files->Strings[j]; // Сохраняем путь к загруженным картинкам
                //Form2->DescriptionMemo->Lines->Add("i: " + IntToStr(i) + " : " + ArrayPathImages[i]);

                img[i]->ShowHint;
                img[i]->Hint = Form2->ReturnFullFileName(OpenPictureDialog1->Files->Strings[j]);
                j++;
                if(j == OpenPictureDialog1->Files->Count)
                {
                    break;
                }
            }                
		}
        // Считаем сколько картинок загруженно
        // Это нужно для того, чтобы знать сколько
        // кнопок закрытия выводить.
        // Т.е. сколько фоток загруженно, столько же 
        // и кнопок удаления фоток будет. Одна кнопка
        // возле каждой картинки.
        for(int i = 0; i < 6; i++)
        {
            if(img[i]->Visible)
            {
                FlagCount = i; // количество загруженных фоток
            }
        }
		Image1->Visible = false; // Очищаем Image содержащий картинку "Загрузка фотографий"
	}
	Form2->SetFocus(); // Фокус на эту форму
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ImgLoadClick(TObject *Sender)
{
	//DescriptionMemo->Lines->Add(((TImage*)Sender)->Name);
	Form1->ImgEditClick(((TImage*)Sender));
}
//---------------------------------------------------------------------------
// При наведении курсора на картинку отображаем карестик для закриытия данной фотки
//---------------------------------------------------------------------------
void __fastcall TForm2::ImageCloseMouseEnter(TObject *Sender)
{
	for(int i = 0; i <= FlagCount; i++)
	{
		if(((TImage*)Sender)->Tag == imgcls[i]->Tag)
		{
			imgcls[i]->Visible = true;

		}
	}
}
//---------------------------------------------------------------------------
// 			Убираем крестик при выходе курсора из Image'а                  --
//---------------------------------------------------------------------------
void __fastcall TForm2::ImageCloseMouseLeave(TObject *Sender)
{
	for(int i = 0; i <= FlagCount; i++)
	{
		if(((TImage*)Sender)->Tag == imgcls[i]->Tag)
		{
			imgcls[i]->Visible = false;
		}
	}
}
//---------------------------------------------------------------------------
// 					При нажатии на картинку крестика                       --
//---------------------------------------------------------------------------
void __fastcall TForm2::ImageCloseClick(TObject *Sender)
{
	for(int i = 0; i <= FlagCount; i++)
	{
		if(((TImage*)Sender)->Tag == img[i]->Tag)
		{
			/*if(((TImage*)Sender)->Tag == 0)
			{
				SelectFace[0]->Visible = false;
				FaceImageString = "";
			}
			if(((TImage*)Sender)->Tag == ImageFace->Tag)
			{
				SelectFace[0]->Top = img[0]->Top-2;
				SelectFace[0]->Left = img[0]->Left-2;
				FaceImageString = ArrayPathImages[0];
			}*/
			if(ArrayPathImages[i] == Form1->ADOQuery1->Fields->FieldByName("FaceImage")->AsString)
			{
            	FaceImageString = "";
            }
			// елси фотка была ранее загружане, т.е. распологается в нашей папке
			if(ArrayPathImages[i].SubString(0, 4) == "load")
			{
				//DeleteFile(ArrayPathImages[i]);
				DeleteImages[i] = ArrayPathImages[i];
				ArrayPathImages[i] = "";
				((TImage*)Sender)->Visible = false;
				FlagTag = ((TImage*)Sender)->Tag;
				img[i]->Picture->Bitmap = NULL;
				img[i]->Visible = false;
				BtnLoad[i] = new TButton(Form2);
				BtnLoad[i]->Parent = Form2;
				BtnLoad[i]->Tag = i;
				BtnLoad[i]->Caption = "...";
				BtnLoad[i]->Width = 25;
				BtnLoad[i]->Height = 17;
				BtnLoad[i]->Top = ((TImage*)Sender)->Top + 30;
				BtnLoad[i]->Left = ((TImage*)Sender)->Left - 30;
				BtnLoad[i]->Name = "BtnLoad" + IntToStr(i);
				BtnLoad[i]->OnClick = ButtonUpLoadClick;
			}
			else
			{
				ArrayPathImages[i] = "";
				((TImage*)Sender)->Visible = false;
				FlagTag = ((TImage*)Sender)->Tag;
				img[i]->Picture->Bitmap = NULL;
				img[i]->Visible = false;
				BtnLoad[i] = new TButton(Form2);
				BtnLoad[i]->Parent = Form2;
				BtnLoad[i]->Tag = i;
				BtnLoad[i]->Caption = "...";
				BtnLoad[i]->Width = 25;
				BtnLoad[i]->Height = 17;
				BtnLoad[i]->Top = ((TImage*)Sender)->Top + 30;
				BtnLoad[i]->Left = ((TImage*)Sender)->Left - 30;
				BtnLoad[i]->Name = "BtnLoad" + IntToStr(i);
				BtnLoad[i]->OnClick = ButtonUpLoadClick;
			}
			
		}
	}
}
//---------------------------------------------------------------------------
// 					Кнопка для загрузки 1 фотки                            --
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonUpLoadClick(TObject *Sender)
{
    // Убираем ofAllowMultiSelect для выбота только одной фотки
	OpenPictureDialog1->Options.operator -=(TOpenOptions() << ofAllowMultiSelect); // Изменение Options у OpenPictureDialog1
    // При нажатии на кнопку вызываем диалог
	if(OpenPictureDialog1->Execute())
	{
		img[((TButton*)Sender)->Tag]->Picture->LoadFromFile(OpenPictureDialog1->FileName);
		img[((TButton*)Sender)->Tag]->Visible = true;
		ArrayPathImages[((TButton*)Sender)->Tag] = OpenPictureDialog1->FileName;
		BtnLoad[((TButton*)Sender)->Tag]->Free();
	}
}
//---------------------------------------------------------------------------
//      Событие при отображении формы. Ох, делаем тут дохрена всего...     --
//---------------------------------------------------------------------------
void __fastcall TForm2::FormShow(TObject *Sender)
{
    // Зполняем список категорий
    if(Form1->ADOQuery2->Active)
    {
        Form1->ADOQuery2->Active = false;
    }
    Form1->ADOQuery2->SQL->Text = "SELECT * FROM Category";
    Form1->ADOQuery2->Active = true;
    if(Form1->ADOQuery2->RecordCount != 0)
    {    
        Form1->ADOQuery2->First();
        ThingCategory->Clear();
        for(int i = 0; i < Form1->ADOQuery2->RecordCount; i++)
        {
            ThingCategory->Items->Add(Form1->ADOQuery2->Fields->FieldByName("Category")->AsString);
            Form1->ADOQuery2->Next();
        }
    }
    ThingName->SetFocus();
	IDImageFortables = "";
	FaceImageString = "";
	// Проверяем флаг. Если он = 1, значить нажали на название вещи
	if(Form1->ClickFlag == 1)
	{
		// Скрываем картинку "Загрузка фоток"
		if(Image1->Visible == false)
		{
			Image1->Visible = true;
		}
        // берем данные из таблицы
		Form2->Caption = Form1->ADOQuery1->Fields->FieldByName("Name")->AsString;
		id = Form1->ADOQuery1->Fields->FieldByName("ID")->AsString;
		ThingName->Text = Form1->ADOQuery1->Fields->FieldByName("Name")->AsString;
		ThingDOB->Date = StrToDate(Form1->ADOQuery1->Fields->FieldByName("DOB")->AsString);
		ThingCategory->Text = Form1->ADOQuery1->Fields->FieldByName("Category")->AsString;
		ThingShop->Text = Form1->ADOQuery1->Fields->FieldByName("NameShop")->AsString;
		ThingCost->Text = Form1->ADOQuery1->Fields->FieldByName("Cost")->AsString;
        FaceImageString = Form1->ADOQuery1->Fields->FieldByName("FaceImage")->AsString;
		Form2->ButtonSave->Caption = "Сохранить";
		AnsiString IDImageFortables2 = Form1->ADOQuery1->Fields->FieldByName("Images")->AsString;
        if(Form1->ADOQuery1->Fields->FieldByName("Checked")->AsInteger == 0)
        {
            CheckBox1->Checked = false;
        }
        else
        {
            CheckBox1->Checked = true;
        }
        Check1Checked = CheckBox1->Checked;
        ThingDOB->Hint = "Прошло " + IntToStr(DaysBetween(Now(), ThingDOB->Date)) + " дней со для покупки";
		/*if(SelectFace[0]->Visible)
		{
			SelectFace[0]->Visible = false;
		}*/
		for(int i = 0; i < 6; i++) // Скрываем Image'ы от старой вещи
		{
            ArrayNameImage[i] = "";
			if(FindComponent("BtnLoad" + IntToStr(i)))
			{
				BtnLoad[i]->Free();
			}
		}
		if(IDImageFortables2 != "")
		{
            //Form2->DescriptionMemo->Lines->Add("Санная ошибка!");
			AnsiString str = "";
			//int iTop = 0, iLeft = 0; // переменные для формирования картинок в 2 уровня


			if(Image1->Visible)
			{
            	Image1->Visible = false;
			}
			AnsiString FileImage = "";
			//int flag = 0;
			for(int i = 1, IndexType = 0; i <= IDImageFortables2.Length(); i++)
			{
				// показываем Image'ы выбранной вещи
				if(IDImageFortables2[i] != '*')
				{
					ArrayNameImage[IndexType] += IDImageFortables2[i];
				}
				else
				{
					//DescriptionMemo->Lines->Add("load\\" + ArrayNameImage[IndexType]);
					img[IndexType]->Picture->LoadFromFile("load\\" + ArrayNameImage[IndexType]);
					//Form2->DescriptionMemo->Lines->Add("IndexType: " + IntToStr(IndexType));
					ArrayPathImages[IndexType] = "load\\" + ArrayNameImage[IndexType];
					//Form2->DescriptionMemo->Lines->Add(IntToStr(IndexType));
					if(!img[IndexType]->Visible)
					{
						img[IndexType]->Visible = true;
					}

					//if(CompareText(ArrayPathImages[IndexType], Form1->ADOQuery1->Fields->FieldByName("FaceImage")->AsString) == 0)
					/*if(ArrayPathImages[IndexType] == Form1->ADOQuery1->Fields->FieldByName("FaceImage")->AsString)
					{
						//Form2->DescriptionMemo->Lines->Add(ArrayPathImages[IndexType]+"="+Form1->ADOQuery1->Fields->FieldByName("FaceImage")->AsString);
						SelectFace[0]->Top = img[IndexType]->Top-2;
						SelectFace[0]->Left = img[IndexType]->Left-2;
						SelectFace[0]->Visible = true;
						flag = 1;
					}
					if(flag == 0)
					{
						Form2->DescriptionMemo->Lines->Add(ArrayPathImages[IndexType]+"="+Form1->ADOQuery1->Fields->FieldByName("FaceImage")->AsString);
						SelectFace[0]->Top = img[0]->Top-2;
						SelectFace[0]->Left = img[0]->Left-2;
						SelectFace[0]->Visible = true;

					}*/
					FlagCount = IndexType;
					IndexType++;
				}
			}
		}

		Form1->ClickFlag = 0;
	}
	else // В противном случае нажали добавить новую вещь
	{
        ThingCategory->ItemIndex = 0;
		Form2->Caption = "Добавление новой вещи";
		Form2->ButtonSave->Caption = "Добавить";
		Form2->ThingName->Text = "";
		Form2->ThingDOB->Date = Now();
		Form2->ThingCategory->Text = "";
		Form2->ThingShop->Text = "";
		Form2->ThingCost->Text = "0";
		Form2->DescriptionMemo->Lines->Clear();
		if(Image1->Visible == false)
		{
            Image1->Visible = true;
        }
		for(int i = 0; i < 6; i++)
		{
			img[i]->Picture->Bitmap = NULL;
			img[i]->Visible = false;
			imgcls[i]->Visible = false;
		}
        Check1Checked = CheckBox1->Checked;
		/*if(SelectFace[0]->Visible)
		{
            SelectFace[0]->Visible = false;
		}*/
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	long SC_DRAGMOVE = 0xF012;
	if(Button == mbLeft)
	{
		ReleaseCapture();
        SendMessage(Handle, WM_SYSCOMMAND, SC_DRAGMOVE, 0);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ImageFaceContextPopup(TObject *Sender, TPoint &MousePos,
		  bool &Handled)
{
	ImageFace = ((TImage*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FaceImageClick(TObject *Sender)
{
	FaceImageString = "load\\" + ReturnFullFileName(ArrayPathImages[ImageFace->Tag]);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ThingCostKeyPress(TObject *Sender, System::WideChar &Key)

{
	// Ограниченный ввод символов в поле стоимости
	if(((TLabeledEdit*)Sender)->Name == "ThingCost")
	{
		if((Key != VK_BACK) && (Key < '0' || Key > '9'))
		{
			Key=0;
		}
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm2::ButtonClearClick(TObject *Sender)
{
	for(int i = 0; FindComponent("ImgLoad" + IntToStr(i)); i++)
	{
		if(img[i]->Picture->Graphic != NULL)
		{
			img[i]->Picture->Bitmap = NULL;
			img[i]->Visible = false;
			imgcls[i]->Visible = false;
			ArrayPathImages[i] = "";
        }
	}
	IDImageFortables = "";
	FaceImageString = "";
}
//---------------------------------------------------------------------------


void __fastcall TForm2::MenuExitClick(TObject *Sender)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N2Click(TObject *Sender)
{
    FormRes->ShowModal();
	FormRes->Position = poMainFormCenter;    
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N3Click(TObject *Sender)
{
    FormCosts->ShowModal();
    FormCosts->Position = poMainFormCenter;    
}
//---------------------------------------------------------------------------

void __fastcall TForm2::MenuHelpClick(TObject *Sender)
{
    ShellExecute(0, L"open", L"Help.chm", 0, 0, SW_SHOWNORMAL);    
}
//---------------------------------------------------------------------------

void __fastcall TForm2::NewCategoryClick(TObject *Sender)
{
    FormNC->ShowModal();
    FormNC->Position = poMainFormCenter;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::MenuOptionsClick(TObject *Sender)
{
    Form4->ShowModal();    
}
//---------------------------------------------------------------------------


void __fastcall TForm2::CalcClick(TObject *Sender)
{
    FormCalc->ShowModal();    
}
//---------------------------------------------------------------------------


