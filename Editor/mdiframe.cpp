//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MDIFrame.h"
#include "MDIEdit.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFrameForm *FrameForm;
//---------------------------------------------------------------------------

const AnsiString DefaultFileName = AnsiString("Untitled");

__fastcall TFrameForm::TFrameForm(TComponent* Owner)
    : TForm(Owner)
{
 NumbOfUName = -1;
}
//---------------------------------------------------------------------------
void __fastcall TFrameForm::Exit1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------
void __fastcall TFrameForm::Tile1Click(TObject *Sender)
{
  Tile();
}
//---------------------------------------------------------------------
void __fastcall TFrameForm::Cascade1Click(TObject *Sender)
{
  Cascade();
}
//---------------------------------------------------------------------
void __fastcall TFrameForm::Arrangeicons1Click(TObject *Sender)
{
  ArrangeIcons();
}
//---------------------------------------------------------------------
void __fastcall TFrameForm::New1Click(TObject *Sender)
{
  EditForm = new TEditForm(this);
  EditForm->Caption = "NoName" + IntToStr(NumbOfUName + 1);
}
//---------------------------------------------------------------------
void __fastcall TFrameForm::Open1Click(TObject *Sender)
{
  if(OpenFileDialog->Execute()){
    EditForm=new TEditForm(this);
    EditForm->Open(OpenFileDialog->FileName);
  }
}
//---------------------------------------------------------------------
void __fastcall TFrameForm::ToolBtn_NewClick(TObject *Sender)
{
 FrameForm->New1Click(Sender);        
}
//---------------------------------------------------------------------------

void __fastcall TFrameForm::ToolBtn_OpenClick(TObject *Sender)
{
 FrameForm->Open1Click(Sender);        
}
//---------------------------------------------------------------------------


void __fastcall TFrameForm::ToolBtn_CloseClick(TObject *Sender)
{
 EditForm->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFrameForm::ToolBtn_SaveClick(TObject *Sender)
{
 EditForm->Save1Click(Sender);        
}
//---------------------------------------------------------------------------

void __fastcall TFrameForm::ToolBtn_CopyClick(TObject *Sender)
{
 EditForm->Copy1Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFrameForm::ToolBtn_PastClick(TObject *Sender)
{
 EditForm->Paste1Click(Sender);        
}
//---------------------------------------------------------------------------

void __fastcall TFrameForm::ToolBtn_CutClick(TObject *Sender)
{
 EditForm->Cut1Click(Sender);        
}
//---------------------------------------------------------------------------

void __fastcall TFrameForm::ToolBtn_DelClick(TObject *Sender)
{
 EditForm->Delete1Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFrameForm::ToolBtn_UndoClick(TObject *Sender)
{
 EditForm->Editor->Undo();
}
//---------------------------------------------------------------------------


void __fastcall TFrameForm::ToolBtn_WordWrapClick(TObject *Sender)
{
 EditForm->Wordwrap1->Click();
}
//---------------------------------------------------------------------------

