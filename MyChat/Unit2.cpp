//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "trayicon"
#pragma resource "*.dfm"
TEnteryForm *EnteryForm;
//---------------------------------------------------------------------------
__fastcall TEnteryForm::TEnteryForm(TComponent* Owner)
        : TForm(Owner)
{
}
 //---------------------------------------------------------------------------
void __fastcall TEnteryForm::Ed_NickKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == 13) // ��� ������� Enter
        {
                EnteryForm->Hide();
                EnteryForm->N1->Visible = true;
                wmshow = true;
                WMain->ShowModal();
        }
}
//---------------------------------------------------------------------------
void __fastcall TEnteryForm::N2Click(TObject *Sender)
{
        //����� �� ����
        WMain->CloseWMain();
        EnteryForm->Close();
}
//---------------------------------------------------------------------------
void __fastcall TEnteryForm::N1Click(TObject *Sender)
{
        if(wmshow){ WMain->Hide(); N1->Caption="��������"; wmshow = false; }
        else { WMain->Show(); N1->Caption="������"; wmshow = true; }
}
//---------------------------------------------------------------------------
void __fastcall TEnteryForm::Img_FonMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        long SC_WINMOVE = 0xF012;
        if(Button == mbLeft)
        {
         ReleaseCapture();
         SendMessage(Handle, WM_SYSCOMMAND, SC_WINMOVE, 0);
        }
}
//---------------------------------------------------------------------------
void __fastcall TEnteryForm::N3Click(TObject *Sender)
{
        SettingForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TEnteryForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
        // ����� ������ ������� �� ������ � ����
        WMain->Info.SaveHist("History.ini");
        SettingForm->SaveSetting();
}
//---------------------------------------------------------------------------
