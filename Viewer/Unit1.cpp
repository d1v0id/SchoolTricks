//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int i = 0;
int n = 0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Btn_ExitClick(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Btn_CloseClick(TObject *Sender)
{
 n--;
 Image1->Picture = NULL;
 Btn_Close->Enabled = false;
 M_List->Items->Delete(M_List->ItemIndex);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Btn_OpenClick(TObject *Sender)
{
 if(OpenPicDialog->Execute())
 {
  Image1->Picture->LoadFromFile(OpenPicDialog->FileName);
  //fname = ExtractFileName(OpenPicDialog->FileName);
  M_List->Items->Add(OpenPicDialog->FileName/*fname*/);
  n++;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormResize(TObject *Sender)
{
 Btn_Exit->Left = Width - Btn_Exit->Width - 9;
 M_List->Width = Width - M_List->Left - Btn_Exit->Width - 9;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::M_ListClick(TObject *Sender)
{
 Btn_Close->Enabled = true;
 Image1->Picture->LoadFromFile(M_List->Items->Strings[M_List->ItemIndex].c_str());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Btn_SlideShowClick(TObject *Sender)
{
 if (n > 1)
 {
   Timer1->Interval = StrToInt(Ed_Delay->Text);
   Ed_Delay->Enabled = !Ed_Delay->Enabled;
   Timer1->Enabled = !Timer1->Enabled;
   Btn_Open->Enabled = !Btn_Open->Enabled;
   M_List->Enabled = !M_List->Enabled;
   CB_Repeat->Enabled = !CB_Repeat->Enabled; 

   if(Btn_SlideShow->Caption == "On") Btn_SlideShow->Caption = "Off";
   else Btn_SlideShow->Caption = "On";
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Ed_DelayKeyPress(TObject *Sender, char &Key)
{
 if((Key < '0' || Key > '9') && Key != '8') Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
 if(i < n)
 {
  Image1->Picture->LoadFromFile(M_List->Items->Strings[i].c_str());
  i++;
 }
 else
 {
        if(rep_s) i = 0;
        else{
           Btn_SlideShowClick(Sender);
           Application->MessageBox("The end of slides!","Viewer",
                                    MB_OK | MB_ICONINFORMATION);
        }
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Pnl_ListResize(TObject *Sender)
{
 GroupBox1->Top = Pnl_List->Height - GroupBox1->Height - 10;
 GroupBox2->Top = GroupBox1->Top - GroupBox2->Height - 10;
 M_List->Height = GroupBox2->Top - 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormActivate(TObject *Sender)
{
 //Width = Constraints->MinWidth;
 //Height = Constraints->MinHeight;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
 //Width +=50;
 //Height +=10;
 //if (Width > 655 || Height > 580) { Timer2->Enabled = false; }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::CB_RepeatClick(TObject *Sender)
{
 rep_s = CB_Repeat->Checked;        
}
//---------------------------------------------------------------------------

