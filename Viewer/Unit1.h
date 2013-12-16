//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TPanel *Pnl_Control;
        TButton *Btn_Open;
        TButton *Btn_Close;
        TButton *Btn_Exit;
        TOpenPictureDialog *OpenPicDialog;
        TListBox *M_List;
        TButton *Btn_SlideShow;
        TTimer *Timer1;
        TEdit *Ed_Delay;
        TPanel *Pnl_List;
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TTimer *Timer2;
        TCheckBox *CB_Repeat;
        void __fastcall Btn_ExitClick(TObject *Sender);
        void __fastcall Btn_CloseClick(TObject *Sender);
        void __fastcall Btn_OpenClick(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall M_ListClick(TObject *Sender);
        void __fastcall Btn_SlideShowClick(TObject *Sender);
        void __fastcall Ed_DelayKeyPress(TObject *Sender, char &Key);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Pnl_ListResize(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall Timer2Timer(TObject *Sender);
        void __fastcall CB_RepeatClick(TObject *Sender);
private:	// User declarations
        AnsiString fname;
        bool rep_s;
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
