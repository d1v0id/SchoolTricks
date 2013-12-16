//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SHDocVw_OCX"
#pragma link "trayicon"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormResize(TObject *Sender)
{
 Btn_Go->Left = Form1->Width - 15 - Btn_Go->Width;
 Lbl_Addres->Left = 10;
 Ed_Addres->Left = Lbl_Addres->Left +  Lbl_Addres->Width + 10;
 Ed_Addres->Width = Form1->Width - 55 - Lbl_Addres->Width - 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LoadSite(TObject *Sender)
{
  // Text = "Загружаю...";

  // CppWebBrowser1->;

  //ComboBox1->Items->Add(Ed_Addres->Text);
  Info.Add(Ed_Addres->Text);

  TBtn_Back->Enabled = true;
  TBtn_Next->Enabled = true;
  TBtn_Stop->Enabled = true;

  TStatusPanel *SLoad=StatusBar1->Panels->operator [](0);
  SLoad->Text=Text;

  if(Ed_Addres->Text != "" && Ed_Addres->Text != "http:\\")
  {
   addres = Ed_Addres->Text; // for exemple: "http://www.google.ru/";
   addres.WideChar(adr,30);
   CppWebBrowser1->Navigate(adr);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LoadHomeSite(TObject *Sender)
{
 Ed_Addres->Text = home;
 Btn_Go->Click();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ProgExit(TObject *Sender)
{
 Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::StopLoadSite(TObject *Sender)
{
 CppWebBrowser1->Stop();
 TBtn_Stop->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RefreshSite(TObject *Sender)
{
 CppWebBrowser1->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BackSite(TObject *Sender)
{
 CppWebBrowser1->GoBack();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ForwardSite(TObject *Sender)
{
 CppWebBrowser1->GoForward();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N1Click(TObject *Sender)
{
 N1->Enabled = false;
 N2->Enabled = true;
 Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender)
{
 N2->Enabled = false;
 N1->Enabled = true;
 Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CloseForm(TObject *Sender)
{
 switch(Application->MessageBox("Вы уверены, что хотите выйти?",
                                "Browser",
                                 MB_YESNO | MB_ICONQUESTION))
 {
  case IDYES: Close(); break;
 }
 /*

 [ Must DO ] : При закрытии окна уточнять закрытие, если юзер выберет НЕТ, отменять закрытие.

 */

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
 if(FileExists("History.ini"))
 {

  Info.LoadHist("History.ini");
  Info.GoToBeg();
  while(!Info.EndOfList()){ Ed_Addres->Items->Add(Info.Next()); }

 }else ShowMessage("No found History file!!!");

 home = "www.scene.ru";
 startp= "z";

 ILineVis = "0";
 ABarVis = "0";
 TBarVis = "0";

 FILE *configure;

  conf = ExtractFilePath(Application->ExeName) + "conf.ini"; // Extract path to .exe file, and summ config name to him
  configure = fopen(conf.c_str(),"r");

  if ( configure != NULL ){
       fscanf(configure,"%s\n",home);      //  Read home site addres
       fscanf(configure,"%s\n",startp);    //  Read start page addres

       fscanf(configure,"%s\n",ILineVis);  //  Read vis information line
       fscanf(configure,"%s\n",ABarVis);   //  Read vis addres bar
       fscanf(configure,"%s\n",TBarVis);   //  Read vis tool bar

  }else ShowMessage("No found configuration file!");

 // Load start page

 if (startp != "z"){
        Ed_Addres->Text = startp;
        Btn_Go->Click();
 }

 // Visible or Invisible Panels and ToolBars on Form1 
 if(StrToInt(ILineVis) == 1){
    StatusBar1->Visible = true;
    InfoLineVis->Checked = true;
 }
 else{
    StatusBar1->Visible = false;
    InfoLineVis->Checked = false;
 }

 if(StrToInt(TBarVis) == 1){
    ToolBar1->Visible = true;
    ToolBarVis->Checked = true;
 }
 else{
    ToolBar1->Visible = false;
    ToolBarVis->Checked = false;
 }

 if(StrToInt(ABarVis) == 1){
    Panel1->Visible = true;
    AddresBarVis->Checked = true;
 }
 else {
    Panel1->Visible = false;
    AddresBarVis->Checked = false;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::InfoLineVisClick(TObject *Sender)
{
 StatusBar1->Visible = InfoLineVis->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolBarVisClick(TObject *Sender)
{
 ToolBar1->Visible = ToolBarVis->Checked;
 //Panel1->Height = Panel1->Height - 34; 
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AddresBarVisClick(TObject *Sender)
{
 Panel1->Visible = AddresBarVis->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ControlDlgClick(TObject *Sender)
{
 /*
 if(StatusBar1->Visible) ILineVis = 1; else ILineVis = 0;
 if(ToolBar1->Visible) TBarVis = 1; else TBarVis = 0;
 if(Panel1->Visible) ABarVis = 1; else ABarVis = 0;
 */

 Form2->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::html1Click(TObject *Sender)
{
 if(OpenDialog1->Execute())
 {
  Ed_Addres->Text = OpenDialog1->FileName;
  Btn_Go->Click();
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
 if(StatusBar1->Visible) ILineVis = 1; else ILineVis = 0;
 if(ToolBar1->Visible) TBarVis = 1; else TBarVis = 0;
 if(Panel1->Visible) ABarVis = 1; else ABarVis = 0;

 FILE *SaveConf;

  SaveConf = fopen(conf.c_str(),"w");
  if ( SaveConf != NULL )
  {
    fprintf(SaveConf,"%s\n",home);       //  Save home site
    if(startp == home) fprintf(SaveConf,"%s\n",home);
    else fprintf(SaveConf,"%s\n",startp);//  Save start page

    fprintf(SaveConf,"%s\n",ILineVis);   //  Save vis information line
    fprintf(SaveConf,"%s\n",ABarVis);    //  Save vis addres bar
    fprintf(SaveConf,"%s\n",TBarVis);    //  Save vis tool bar
  }

  fclose(SaveConf);


  // Call recording History from memory to file
  
  Info.SaveHist("History.ini");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::InternetBrowser1Click(TObject *Sender)
{
 AboutBox->ShowModal();       
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Ed_AddresKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 if(Key==13) Btn_Go->Click();        
}
//---------------------------------------------------------------------------

