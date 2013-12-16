//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "SHDocVw_OCX.h"
#include <OleCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <Buttons.hpp>
#include "trayicon.h"
#include <Dialogs.hpp>
#include "File1.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TCppWebBrowser *CppWebBrowser1;
        TPanel *Panel1;
        TLabel *Lbl_Addres;
        TStatusBar *StatusBar1;
        TEdit *Ed_AddresDel;
        TMainMenu *MainMenu1;
        TMenuItem *Fail1;
        TMenuItem *Exit1;
        TMenuItem *Go1;
        TMenuItem *Home1;
        TImageList *CrystallImageList;
        TBitBtn *Btn_Go;
        TTrayIcon *TrayIcon1;
        TImageList *ImageList2;
        TPopupMenu *PopupMenu1;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N3;
        TMenuItem *View;
        TMenuItem *InfoLineVis;
        TMenuItem *ToolBarVis;
        TMenuItem *AddresBarVis;
        TMenuItem *Tools;
        TMenuItem *Help;
        TMenuItem *ControlDlg;
        TMenuItem *html1;
        TOpenDialog *OpenDialog1;
        TImageList *ImageList1;
        TMenuItem *InternetBrowser1;
        TToolBar *ToolBar1;
        TToolButton *TBtn_Back;
        TToolButton *TBtn_Next;
        TToolButton *ToolButton1;
        TToolButton *TBtn_Stop;
        TToolButton *TBtn_Refresh;
        TToolButton *ToolButton2;
        TToolButton *TBtn_Home;
        TComboBox *Ed_Addres;
        void __fastcall FormResize(TObject *Sender);
        void __fastcall LoadHomeSite(TObject *Sender);
        void __fastcall ProgExit(TObject *Sender);
        void __fastcall StopLoadSite(TObject *Sender);
        void __fastcall RefreshSite(TObject *Sender);
        void __fastcall BackSite(TObject *Sender);
        void __fastcall ForwardSite(TObject *Sender);
        void __fastcall LoadSite(TObject *Sender);
        void __fastcall N1Click(TObject *Sender);
        void __fastcall N2Click(TObject *Sender);
        void __fastcall CloseForm(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall InfoLineVisClick(TObject *Sender);
        void __fastcall ToolBarVisClick(TObject *Sender);
        void __fastcall AddresBarVisClick(TObject *Sender);
        void __fastcall ControlDlgClick(TObject *Sender);
        void __fastcall html1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall InternetBrowser1Click(TObject *Sender);
        void __fastcall Ed_AddresKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
        wchar_t adr[30];
        AnsiString Text;
        AnsiString addres;
public:		// User declarations
        History Info;

        AnsiString conf;
        AnsiString home;
        AnsiString startp;
        AnsiString ILineVis;
        AnsiString ABarVis;
        AnsiString TBarVis;

        bool ILineCh;
        bool TBarCh;
        bool ABarCh;
        __fastcall TForm1(TComponent* Owner);
        /* __fastcall LoadFromFileHomeSite(TObject *Sender); */
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
