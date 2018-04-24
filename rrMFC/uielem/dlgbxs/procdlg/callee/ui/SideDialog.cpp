/// \copyright The MIT License

#include "stdafx.h"
#include "resource.h"
#include "ui/SideDialog.h"

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
    DbgConPrt(LightBlue, TEXT("SideDialog::Constructor\n"));
}

#// Overridables

SideDialog::
~SideDialog()
{
    DbgConPrt(LightBlue, TEXT("SideDialog::Destructor\n"));
}

BOOL SideDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConPrtWndMsg(Blue, TEXT("SideDialog::OnWndMsg"), message, wParam, lParam, pResult);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID SideDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DbgConPrt(LightBlue, TEXT("SideDialog::DoDataExchange\n"));
}

#// Message Handlers

INT SideDialog::
OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CDialog::OnCreate(lpCreateStruct) == -1)
        return -1;
    DbgConPrt(LightBlue, TEXT("SideDialog::OnCreate\n"));
    return 0;
}

VOID SideDialog::
OnDestroy()
{
    CDialog::OnDestroy();
    DbgConPrt(LightBlue, TEXT("SideDialog::OnDestroy\n"));
}

VOID SideDialog::
OnMove(INT x, INT y)
{
    CDialog::OnMove(x, y);
    DbgConPrt(LightBlue, TEXT("SideDialog::OnMove\n"));

    if (CWnd *par = GetParent()) {
        CRect sideDlgRect;
        GetWindowRect(sideDlgRect);
        CRect mainDlgRect;
        par->GetWindowRect(mainDlgRect);

        CONST CPoint curPos(mainDlgRect.left, mainDlgRect.top);
        CONST CPoint tgtPos(sideDlgRect.left - mainDlgRect.Width() + 13, sideDlgRect.top);

        if (tgtPos != curPos)
            par->MoveWindow(tgtPos.x, tgtPos.y,
                            mainDlgRect.Width(), mainDlgRect.Height(), FALSE);
    }
}
