//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSettingForm *SettingForm;
TColor Colors[]={clBlack, clWhite, clGreen, clYellow, clBlue, clRed,
clTeal, clPurple, clSilver, clNavy, clOlive, clLime};
//---------------------------------------------------------------------------
__fastcall TSettingForm::TSettingForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSettingForm::FormCreate(TObject *Sender)
{
        for (i=0; i<12; i++){
        Cb_BackGrndColor->Items->Add(ColorToString(Colors[i]));
        Cb_ForeGrndColor->Items->Add(ColorToString(Colors[i]));
        Cb_NickColor->Items->Add(ColorToString(Colors[i]));
        }

        confpath = ExtractFilePath(Application->ExeName) + "chat.conf";
        if ( (configure = fopen(confpath.c_str(),"r")) != NULL ){
        fscanf(configure,"%d\n",&BGIndex);
        fscanf(configure,"%d\n",&FGIndex);
        fscanf(configure,"%d\n",&NCIndex);
        fclose(configure);
        }
        else {
                ShowMessage("Не найден файл настроек!");
                BGIndex = 0;
                FGIndex = 1;
                NCIndex = 2;
        }
        SettingForm->Cb_BackGrndColor->ItemIndex = BGIndex;
        SettingForm->Cb_ForeGrndColor->ItemIndex = FGIndex;
        SettingForm->Cb_NickColor->ItemIndex = NCIndex;
        SetMemoColors();
}
//---------------------------------------------------------------------------
void __fastcall TSettingForm::SetMemoColors()
{
        SettingForm->Cb_BackGrndColor->ItemIndex = BGIndex;
        SettingForm->Cb_ForeGrndColor->ItemIndex = FGIndex;
        SettingForm->Cb_NickColor->ItemIndex = NCIndex;
        Memo_BackGrndColor = StringToColor(Cb_BackGrndColor->Text);
        Memo_ForeGrndColor = StringToColor(Cb_ForeGrndColor->Text);
        Memo_NickGrndColor = StringToColor(Cb_NickColor->Text);
        WMain->Memo->Color = Memo_BackGrndColor;
}
//---------------------------------------------------------------------------
void __fastcall TSettingForm::SaveSetting()
{
        if ( (configure = fopen(confpath.c_str(),"w")) != NULL ){
        fprintf(configure,"%d\n",SettingForm->Cb_BackGrndColor->ItemIndex);
        fprintf(configure,"%d\n",SettingForm->Cb_ForeGrndColor->ItemIndex);
        fprintf(configure,"%d\n",SettingForm->Cb_NickColor->ItemIndex);
        fclose(configure);
        }
}
//---------------------------------------------------------------------------
