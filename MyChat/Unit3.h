//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TSettingForm : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl;
        TTabSheet *Tab1;
        TTabSheet *Tab2;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TComboBox *Cb_BackGrndColor;
        TComboBox *Cb_ForeGrndColor;
        TComboBox *Cb_NickColor;
        TEdit *Ed_Port;
        TLabel *Label4;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall SetMemoColors();
        void __fastcall SaveSetting();
private:	// User declarations
        unsigned i;
        FILE *configure;
        char title[8];
        AnsiString buffer, confpath;
public:		// User declarations
        short BGIndex, FGIndex, NCIndex;
        TColor Memo_BackGrndColor, Memo_ForeGrndColor, Memo_NickGrndColor;
        __fastcall TSettingForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSettingForm *SettingForm;
//---------------------------------------------------------------------------
#endif
