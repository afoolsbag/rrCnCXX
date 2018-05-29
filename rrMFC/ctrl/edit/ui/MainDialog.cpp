/// \copyright The MIT License

#include "stdafx.h"
#include "MainDialog.h"

#include "rrwindows/dbgcon.h"

IMPLEMENT_DYNCREATE(MainDialog, CDialog)

BEGIN_MESSAGE_MAP(MainDialog, CDialog)
    ON_EN_CHANGE(IDC_EDIT, &MainDialog::OnEnChangeEdit)
END_MESSAGE_MAP()

#// Constructors

MainDialog::
MainDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    DbgConPrtMeth(Yellow);
}

MainDialog::
~MainDialog()
{
    DbgConPrtMeth(Yellow);
}

#// Overridables

BOOL MainDialog::
OnInitDialog()
{
    CDialog::OnInitDialog();
    DbgConPrtMeth(Yellow);
    return TRUE;
}

BOOL MainDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConPrtMethWndMsg(Yellow);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID MainDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DbgConPrtMeth(Yellow);
    DDX_Control(pDX, IDC_EDIT, EditControl);
}

VOID MainDialog::
OnEnChangeEdit()
{
    DbgConPrtMeth(Yellow);
}
