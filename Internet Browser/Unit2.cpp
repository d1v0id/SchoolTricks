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
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormShow(TObject *Sender)
{
 Ed_HomeSite->Text = Form1->home;
 CB_InfLine->Checked = Form1->InfoLineVis->Checked;
 CB_TBar->Checked = Form1->ToolBarVis->Checked;
 CB_ABar->Checked = Form1->AddresBarVis->Checked;
 if(Form1->startp == "z") ComboBox1->ItemIndex = 2;
 if(Form1->startp == "about:blank") ComboBox1->ItemIndex = 1;
 if(Form1->startp == Ed_HomeSite->Text) ComboBox1->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::BtnControlCancelClick(TObject *Sender)
{
 CB_InfLine->Checked = Form1->ILineCh;
 CB_ABar->Checked = Form1->ABarCh;
 CB_TBar->Checked = Form1->TBarCh;

 Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::BtnControlOkClick(TObject *Sender)
{
 Form1->home = Ed_HomeSite->Text;
 //Form1->startp = "text";

 if(ComboBox1->ItemIndex == 0) Form1->startp = Form1->home;
 if(ComboBox1->ItemIndex == 1) Form1->startp = "about:blank";
 if(ComboBox1->ItemIndex == 2) Form1->startp = "z";

 FILE *config;

  config = fopen(Form1->conf.c_str(),"w");
  if ( config != NULL )
  {
    fprintf(config,"%s\n",Ed_HomeSite->Text); //  Write home page
    fprintf(config,"%s\n",Form1->startp);     //  Write start page

    fprintf(config,"%s\n",Form1->ILineVis);   //  Write vis information line
    fprintf(config,"%s\n",Form1->ABarVis);    //  Write vis addres bar
    fprintf(config,"%s\n",Form1->TBarVis);    //  Write vis tool bar
  }
  fclose(config);

 Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::CB_InfLineClick(TObject *Sender)
{
 Form1->StatusBar1->Visible = CB_InfLine->Checked;
 Form1->InfoLineVis->Checked = CB_InfLine->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::CB_ABarClick(TObject *Sender)
{
 Form1->Panel1->Visible = CB_ABar->Checked;
 Form1->AddresBarVis->Checked = CB_ABar->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::CB_TBarClick(TObject *Sender)
{
 Form1->ToolBar1->Visible = CB_TBar->Checked;
 Form1->ToolBarVis->Checked = CB_TBar->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ComboBox1Change(TObject *Sender)
{
 if(ComboBox1->ItemIndex == 0) Lbl_1->Caption = Ed_HomeSite->Text;
 if(ComboBox1->ItemIndex == 1) Lbl_1->Caption = "about:blank";
 if(ComboBox1->ItemIndex == 2) Lbl_1->Caption = "z";
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormActivate(TObject *Sender)
{
 Form1->ILineCh = CB_InfLine->Checked;
 Form1->ABarCh = CB_ABar->Checked;
 Form1->TBarCh = CB_TBar->Checked;
}
//---------------------------------------------------------------------------

