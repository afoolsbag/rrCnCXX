/// \copyright The MIT License

#include "stdafx.h"
#include "SideDialog.h"

#include "utils/dbgcon.h"

IMPLEMENT_DYNCREATE(SideDialog, CDialog)

BEGIN_MESSAGE_MAP(SideDialog, CDialog)
    ON_WM_CREATE()
    ON_WM_DESTROY()

    ON_WM_MOVE()
END_MESSAGE_MAP()

#// Constructors

SideDialog::
SideDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    DbgConPrt(Green, TEXT("SideDialog::"));
    DbgConPrt(LightGreen, TEXT("Constructor\n"));
}

SideDialog::
~SideDialog()
{
    DbgConPrt(Green, TEXT("SideDialog::"));
    DbgConPrt(LightGreen, TEXT("Destructor\n"));
}

#// Overridables

BOOL SideDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConPrt(Green, TEXT("SideDialog::"));
    DbgConPrtWndMsg(Green, TEXT("OnWndMsg"), message, wParam, lParam, pResult);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

#// Message Handlers

VOID SideDialog::
OnMove(INT x, INT y)
{
    CDialog::OnMove(x, y);
    DbgConPrt(Green, TEXT("SideDialog::"));
    DbgConPrt(LightGreen, TEXT("OnMove\n"));

    if (GetFocus() == this)
        if (CWnd *par = GetParent()) {
            CRect sideDialogRect;
            GetWindowRect(sideDialogRect);
            CRect mainDialogRect;
            par->GetWindowRect(mainDialogRect);

            par->MoveWindow(
                sideDialogRect.left - mainDialogRect.Width() + 13,
                sideDialogRect.top,
                mainDialogRect.Width(),
                mainDialogRect.Height(),
                FALSE);
        }
}
