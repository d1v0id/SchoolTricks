//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TEdit *Ed_HomeSite;
        TLabel *Lbl_HomeSite;
        TBitBtn *BtnControlOk;
        TBitBtn *BtnControlCancel;
        TGroupBox *GroupBox2;
        TComboBox *ComboBox1;
        TCheckBox *CB_InfLine;
        TCheckBox *CB_ABar;
        TCheckBox *CB_TBar;
        TLabel *Lbl_StartPage;
        TLabel *Lbl_1;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall BtnControlCancelClick(TObject *Sender);
        void __fastcall BtnControlOkClick(TObject *Sender);
        void __fastcall CB_InfLineClick(TObject *Sender);
        void __fastcall CB_ABarClick(TObject *Sender);
        void __fastcall CB_TBarClick(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
