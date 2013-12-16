//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <NMMSG.hpp>
#include <Psock.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <ComCtrls.hpp>
#include "History.h"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TWMain : public TForm
{
__published:	// IDE-managed Components
        TNMMsg *NMMsg;
        TNMMSGServ *NMMSGServ;
        TButton *Btn_Send;
        TEdit *Ed_Msg;
        TComboBox *Cb_Hosts;
        TRichEdit *Memo;
        TPopupMenu *MemoPopupMenu;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N3;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall CloseWMain();
        void __fastcall Btn_SendClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall Ed_MsgKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall NMMSGServMSG(TComponent *Sender,
          const AnsiString sFrom, const AnsiString sMsg);
        void __fastcall Cb_HostsKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall N1Click(TObject *Sender);
        void __fastcall N2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        History Info;
        AnsiString hostname;
        __fastcall TWMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWMain *WMain;
//---------------------------------------------------------------------------
#endif
