/// \copyright The MIT License

#include "stdafx.h"
#include "SideDialog.h"

#include "rrwindows/dbgcon.h"

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
    DbgConPrtMeth(Green);
}

SideDialog::
~SideDialog()
{
    DbgConPrtMeth(Green);
}

#// Overridables

BOOL SideDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConPrtMethWndMsg(Green);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

#// Message Handlers

VOID SideDialog::
OnMove(INT x, INT y)
{
    CDialog::OnMove(x, y);
    DbgConPrtMeth(Green);

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
