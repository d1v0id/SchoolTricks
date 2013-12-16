//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "trayicon.h"
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TEnteryForm : public TForm
{
__published:	// IDE-managed Components
        TEdit *Ed_Nick;
        TPopupMenu *PopupMenu;
        TTrayIcon *TrayIcon;
        TMenuItem *N1;
        TMenuItem *N2;
        TImage *Img_Fon;
        TMenuItem *N3;
        TMenuItem *N4;
        void __fastcall Ed_NickKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall N2Click(TObject *Sender);
        void __fastcall N1Click(TObject *Sender);
        void __fastcall Img_FonMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall N3Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TEnteryForm(TComponent* Owner);
        bool wmshow;
};
//---------------------------------------------------------------------------
extern PACKAGE TEnteryForm *EnteryForm;
//---------------------------------------------------------------------------
#endif
