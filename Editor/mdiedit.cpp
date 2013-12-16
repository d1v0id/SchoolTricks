//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MDIEdit.h"
#include "MDIFrame.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TEditForm *EditForm;

//---------------------------------------------------------------------------

const AnsiString DefaultFileName = AnsiString("Untitled");

__fastcall TEditForm::TEditForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TEditForm::Open(const AnsiString AFileName)
{
   PathName = AFileName;
   Caption = ExtractFileName(AFileName);
   Editor->Lines->LoadFromFile(PathName);
   Editor->SelStart = 0;
   Editor->Modified = false;
}
void __fastcall TEditForm::New1Click(TObject *Sender)
{
  FrameForm->New1Click(Sender);
}
//---------------------------------------------------------------------
void __fastcall TEditForm::Open1Click(TObject *Sender)
{
  FrameForm->Open1Click(Sender);
}
//---------------------------------------------------------------------
void __fastcall TEditForm::Close1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------
void __fastcall TEditForm::Exit1Click(TObject *Sender)
{
  FrameForm->Exit1Click(Sender);
}
//---------------------------------------------------------------------
void __fastcall TEditForm::Save1Click(TObject *Sender)
{
  if(Caption == DefaultFileName){
    Saveas1Click(Sender);
  }
  else{
    Editor->Lines->SaveToFile(PathName);
    Editor->Modified = false;
  }
}
//---------------------------------------------------------------------
void __fastcall TEditForm::Saveas1Click(TObject *Sender)
{
  SaveFileDialog->FileName = PathName;
  if (SaveFileDialog->Execute() ){
    PathName= SaveFileDialog->FileName;
    Caption = ExtractFileName(PathName);
    Save1Click(Sender);
  }
}
//---------------------------------------------------------------------
void __fastcall TEditForm::Print1Click(TObject *Sender)
{
  if (PrintDialog1->Execute()){
    try {
        Editor->Print(PathName);
    }
    catch(...){
        Printer()->EndDoc();
        throw;
    }
  }
}
//---------------------------------------------------------------------
void __fastcall TEditForm::Printersetup1Click(TObject *Sender)
{
  PrinterSetupDialog1->Execute();
}
//---------------------------------------------------------------------
void __fastcall TEditForm::Cut1Click(TObject *Sender)
{
  Editor->CutToClipboard();
}
//---------------------------------------------------------------------
void __fastcall TEditForm::Copy1Click(TObject *Sender)
{
  Editor->CopyToClipboard();
}
//---------------------------------------------------------------------
void __fastcall TEditForm::Paste1Click(TObject *Sender)
{
  Editor->PasteFromClipboard();
}
//---------------------------------------------------------------------
void __fastcall TEditForm::Delete1Click(TObject *Sender)
{
  Editor->ClearSelection();
}
//---------------------------------------------------------------------
void __fastcall TEditForm::Selectall1Click(TObject *Sender)
{
  Editor->SelectAll();
}
//---------------------------------------------------------------------
void __fastcall TEditForm::Left1Click(TObject *Sender)
{
  Left1->Checked   = false;
  Right1->Checked  = false;
  Center1->Checked = false;

  if( dynamic_cast<TMenuItem *>(Sender) !=0)
    dynamic_cast <TMenuItem *>(Sender) ->Checked = true;
    {
     if (Left1->Checked )
       Editor->Paragraph->Alignment = taLeftJustify;
     else if (Right1->Checked)
       Editor->Paragraph->Alignment= taRightJustify;
     else if (Center1->Checked)
       Editor->Paragraph->Alignment = taCenter;
    }
}
//---------------------------------------------------------------------
void __fastcall TEditForm::Wordwrap1Click(TObject *Sender)
{
  Editor->WordWrap = !Editor->WordWrap; //toggle word wrapping
    if (Editor->WordWrap)
      {
       Editor->ScrollBars = ssVertical;
       FrameForm->ToolBtn_WordWrap->Down = true;
      }
    else
      {
       Editor->ScrollBars = ssBoth;
       FrameForm->ToolBtn_WordWrap->Down = false;
      }
      Wordwrap1->Checked = Editor->WordWrap; // set menu item check

}
//---------------------------------------------------------------------
void __fastcall TEditForm::Font1Click(TObject *Sender)
{
  FontDialog1->Font= Editor->Font;

  if (FontDialog1->Execute())
    Editor->SelAttributes->Assign(FontDialog1->Font);
}
//---------------------------------------------------------------------
void __fastcall TEditForm::Edit1Click(TObject *Sender)
{
  bool HasSelection;
  Paste1->Enabled = Clipboard()->HasFormat(CF_TEXT);
  Paste2->Enabled = Paste1->Enabled;
  HasSelection = Editor->SelLength > 0;
  Cut1->Enabled = HasSelection;
  Cut2->Enabled = HasSelection;
  Copy1->Enabled = HasSelection;
  Copy2->Enabled = HasSelection;
  Delete1->Enabled = HasSelection;
}
//---------------------------------------------------------------------
void __fastcall TEditForm::FormClose(TObject *Sender, TCloseAction &Action)
{
  Action=caFree;
}
//---------------------------------------------------------------------
void __fastcall TEditForm::FormCloseQuery(TObject *Sender,
    bool &CanClose)
{
  PathName = EditForm->Caption; 
  if (Editor->Modified)
    {
      TMsgDlgButtons temp_set;
      temp_set<< mbYes<<mbNo <<mbCancel;
      String buffer = "Эй Кодер, ты забыл сохраниться!\nСохранить изменения в " + PathName;

      switch(MessageDlg(buffer, mtConfirmation,temp_set,0))
      {
        case mrYes:
          Save1Click(this);
        break;
        case mrCancel:
          CanClose=false;
        break;  
      }

   }

  FrameForm->ToolBtn_Save->Enabled = false;
  FrameForm->ToolBtn_Close->Enabled = false;
  FrameForm->ToolBtn_WordWrap->Enabled = false;
  FrameForm->ToolBtn_Replace->Enabled = false;
  FrameForm->ToolBtn_Find->Enabled = false;
  FrameForm->ToolBtn_Redo->Enabled = false;
  FrameForm->ToolBtn_Undo->Enabled = false;
  FrameForm->ToolBtn_Del->Enabled = false;
  FrameForm->ToolBtn_Cut->Enabled = false;
  FrameForm->ToolBtn_Past->Enabled = false;
  FrameForm->ToolBtn_Copy->Enabled = false;
}
//---------------------------------------------------------------------
void __fastcall TEditForm::FormCreate(TObject *Sender)
{
   FrameForm->NumbOfUName ++;
   
   PathName = DefaultFileName;

   if(Editor->WordWrap) FrameForm->ToolBtn_WordWrap->Down = true;
   else FrameForm->ToolBtn_WordWrap->Down = false;

   FrameForm->ToolBtn_Save->Enabled = true;
   FrameForm->ToolBtn_Close->Enabled = true;
   FrameForm->ToolBtn_WordWrap->Enabled = true;
   FrameForm->ToolBtn_Replace->Enabled = true;
   FrameForm->ToolBtn_Find->Enabled = true;
   FrameForm->ToolBtn_Redo->Enabled = true;
   FrameForm->ToolBtn_Undo->Enabled = true;
   FrameForm->ToolBtn_Del->Enabled = true;
   FrameForm->ToolBtn_Cut->Enabled = true;
   FrameForm->ToolBtn_Past->Enabled = true;
   FrameForm->ToolBtn_Copy->Enabled = true;
}
//---------------------------------------------------------------------

