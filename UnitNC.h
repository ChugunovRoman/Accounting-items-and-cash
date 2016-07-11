//---------------------------------------------------------------------------

#ifndef UnitNCH
#define UnitNCH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFormNC : public TForm
{
__published:	// IDE-managed Components
    TEdit *Edit1;
    TLabel *Label1;
    TButton *AddCategory;
    TButton *Cansel;
    void __fastcall AddCategoryClick(TObject *Sender);
    void __fastcall CanselClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFormNC(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormNC *FormNC;
//---------------------------------------------------------------------------
#endif
