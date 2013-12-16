//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef MDIFrameH
#define MDIFrameH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TFrameForm : public TForm
{
__published:	// IDE-managed Components 
    TMainMenu *MainMenu1;
    TMenuItem *File1;
    TMenuItem *New1;
    TMenuItem *Open1;
    TMenuItem *N1;
    TMenuItem *Exit1;
    TMenuItem *Window1;
    TMenuItem *Tile1;
    TMenuItem *Cascade1;
    TMenuItem *Arrangeicons1;
    TOpenDialog *OpenFileDialog;
        TToolBar *ToolBar1;
        TToolButton *ToolBtn_New;
        TToolButton *ToolBtn_Open;
        TToolButton *ToolBtn_Save;
        TToolButton *ToolBtn_Copy;
        TImageList *ImageList1;
        TToolButton *ToolBtn_Past;
        TToolButton *ToolBtn_Cut;
        TToolButton *ToolBtn_Del;
        TToolButton *ToolBtn_Undo;
        TToolButton *ToolBtn_Redo;
        TToolButton *ToolBtn_Find;
        TToolButton *ToolBtn_Replace;
        TToolButton *ToolBtn_WordWrap;
        TToolButton *ToolBtn_Close;
    void __fastcall Exit1Click(TObject *Sender);
    void __fastcall Tile1Click(TObject *Sender);
    void __fastcall Cascade1Click(TObject *Sender);
    void __fastcall Arrangeicons1Click(TObject *Sender);
    
    
    void __fastcall New1Click(TObject *Sender);
    void __fastcall Open1Click(TObject *Sender);
        void __fastcall ToolBtn_NewClick(TObject *Sender);
        void __fastcall ToolBtn_OpenClick(TObject *Sender);
        void __fastcall ToolBtn_CloseClick(TObject *Sender);
        void __fastcall ToolBtn_SaveClick(TObject *Sender);
        void __fastcall ToolBtn_CopyClick(TObject *Sender);
        void __fastcall ToolBtn_PastClick(TObject *Sender);
        void __fastcall ToolBtn_CutClick(TObject *Sender);
        void __fastcall ToolBtn_DelClick(TObject *Sender);
        void __fastcall ToolBtn_UndoClick(TObject *Sender);
        void __fastcall ToolBtn_WordWrapClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        int NumbOfUName;
    virtual __fastcall TFrameForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFrameForm *FrameForm;
//---------------------------------------------------------------------------
#endif
