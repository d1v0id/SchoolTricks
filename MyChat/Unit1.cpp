//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWMain *WMain;
//---------------------------------------------------------------------------
__fastcall TWMain::TWMain(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TWMain::FormCreate(TObject *Sender)
{
        RECT WArea;
        SystemParametersInfo(SPI_GETWORKAREA, 0, &WArea, 0);
        //this->Height = 400;
        //this->Width = 200;
        //this->Left = WArea.right - this->Width - 40;
        //this->Top = WArea.bottom - this->Height - 40;

        if(FileExists("History.ini"))
        {
        Info.LoadHist("History.ini");
        Info.GoToBeg();
        while(!Info.EndOfList()) WMain->Cb_Hosts->Items->Add(Info.Next());
        } else ShowMessage("No found History file!!!");
}
//---------------------------------------------------------------------------
void __fastcall TWMain::CloseWMain()
{
        //Ф-ция закрытия окна чата
        Close();
}
//---------------------------------------------------------------------------
void __fastcall TWMain::Btn_SendClick(TObject *Sender)
{
        NMMsg->Host = Cb_Hosts->Text;
        NMMsg->FromName = EnteryForm->Ed_Nick->Text;
        NMMsg->PostIt(Ed_Msg->Text);
        Memo->SelAttributes->Color = SettingForm->Memo_ForeGrndColor;
        Memo->Lines->Add(Ed_Msg->Text);
}
//---------------------------------------------------------------------------
void __fastcall TWMain::FormClose(TObject *Sender, TCloseAction &Action)
{
        //WMain->Hide();
        EnteryForm->N1->Caption="Показать";
        EnteryForm->wmshow = false;
}
//---------------------------------------------------------------------------
void __fastcall TWMain::FormResize(TObject *Sender)
{
        Btn_Send->Left = 1;
        Ed_Msg->Left = 1;
        Memo->Left = 1;
        Cb_Hosts->Left = 1;
        Btn_Send->Top = this->Height - Btn_Send->Height - 35;//27 //30
        Ed_Msg->Top = Btn_Send->Top - Ed_Msg->Height - 5;//1 // 5
        Ed_Msg->Width = WMain->Width - 25;//20 // 20
        Memo->Height = Ed_Msg->Top - Memo->Top - 15;//10 //10
        Memo->Width = WMain->Width - 25;//20 //20
        Cb_Hosts->Width = WMain->Width - 25;//20 //20
}
//---------------------------------------------------------------------------
void __fastcall TWMain::Ed_MsgKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == 13) this->Btn_SendClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TWMain::NMMSGServMSG(TComponent *Sender,
      const AnsiString sFrom, const AnsiString sMsg)
{
        Memo->Color = SettingForm->Memo_BackGrndColor;
        Memo->SelAttributes->Color = SettingForm->Memo_NickGrndColor;
        Memo->Lines->Add(sFrom);
        Memo->SelAttributes->Color = SettingForm->Memo_ForeGrndColor;
        Memo->Lines->Add(sMsg);
}
//---------------------------------------------------------------------------
void __fastcall TWMain::Cb_HostsKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == 13)
        {
        hostname = Cb_Hosts->Text;
        if(Info.Add(hostname)) Cb_Hosts->Items->Add(hostname);
        }
}
//---------------------------------------------------------------------------
void __fastcall TWMain::N1Click(TObject *Sender)
{
        Memo->CopyToClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TWMain::N2Click(TObject *Sender)
{
        Memo->SelectAll();
        Memo->CopyToClipboard();
}
//---------------------------------------------------------------------------

