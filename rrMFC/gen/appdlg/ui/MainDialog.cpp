/// \copyright The MIT License

#include "stdafx.h"
#include "MainDialog.h"

#include "rrwindows/dbgcon.h"

IMPLEMENT_DYNCREATE(MainDialog, CDialog)

BEGIN_MESSAGE_MAP(MainDialog, CDialog)
    ON_WM_CLOSE()

    ON_BN_CLICKED(IDOK, &MainDialog::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &MainDialog::OnBnClickedCancel)

    ON_BN_CLICKED(IDABORT, &MainDialog::OnBnClickedAbort)
    ON_BN_CLICKED(IDRETRY, &MainDialog::OnBnClickedRetry)
    ON_BN_CLICKED(IDIGNORE, &MainDialog::OnBnClickedIgnore)

    ON_BN_CLICKED(IDYES, &MainDialog::OnBnClickedYes)
    ON_BN_CLICKED(IDNO, &MainDialog::OnBnClickedNo)

    ON_BN_CLICKED(IDCLOSE, &MainDialog::OnBnClickedClose)
    ON_BN_CLICKED(IDHELP, &MainDialog::OnBnClickedHelp)
END_MESSAGE_MAP()

#// Constructors

MainDialog::
MainDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    DbgConPrtMeth(Yellow);
}

BOOL MainDialog::
Create(LPCTSTR lpszTemplateName, CWnd *pParentWnd /*=NULL*/)
{
    DbgConPrtMeth(Yellow);
    return CDialog::Create(lpszTemplateName, pParentWnd);
}

BOOL MainDialog::
Create(UINT nIDTemplate, CWnd *pParentWnd /*=NULL*/)
{
    DbgConPrtMeth(Yellow);
    return CDialog::Create(nIDTemplate, pParentWnd);
}

BOOL MainDialog::
CreateIndirect(LPCDLGTEMPLATE lpDialogTemplate, CWnd *pParentWnd /*=NULL*/, VOID *lpDialogInit /*=NULL*/)
{
    DbgConPrtMeth(Yellow);
    return CDialog::CreateIndirect(lpDialogTemplate, pParentWnd, lpDialogInit);
}

BOOL MainDialog::
CreateIndirect(HGLOBAL hDialogTemplate, CWnd *pParentWnd /*=NULL*/)
{
    DbgConPrtMeth(Yellow);
    return CDialog::CreateIndirect(hDialogTemplate, pParentWnd);
}

INT_PTR MainDialog::
DoModal()
{
    DbgConPrtMeth(Yellow);
    return CDialog::DoModal();
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
OnCmdMsg(UINT nID, INT nCode, VOID *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo)
{
    DbgConPrtMethCmdMsg(Yellow);
    return CDialog::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

BOOL MainDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConPrtMethWndMsg(Yellow);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID MainDialog::
PreInitDialog()
{
    DbgConPrtMeth(Yellow);
    CDialog::PreInitDialog();
}

VOID MainDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DbgConPrtMeth(Yellow);
}

VOID MainDialog::
OnOK()
{
    DbgConPrtMeth(Yellow);
    CDialog::OnOK();
}

VOID MainDialog::
OnCancel()
{
    DbgConPrtMeth(Yellow);
    CDialog::OnCancel();
}

#// Message Handlers

VOID MainDialog::
OnClose()
{
    DbgConPrtMeth(Yellow);
    CDialog::OnClose();
}

VOID MainDialog::
OnBnClickedOk()
{
    DbgConPrtMeth(Yellow);
    CDialog::OnOK();
}

VOID MainDialog::
OnBnClickedCancel()
{
    DbgConPrtMeth(Yellow);
    CDialog::OnCancel();
}

VOID MainDialog::
OnBnClickedAbort()
{
    DbgConPrtMeth(Yellow);
    EndDialog(IDABORT);
}

VOID MainDialog::
OnBnClickedRetry()
{
    DbgConPrtMeth(Yellow);
    EndDialog(IDRETRY);
}

VOID MainDialog::
OnBnClickedIgnore()
{
    DbgConPrtMeth(Yellow);
    EndDialog(IDIGNORE);
}

VOID MainDialog::
OnBnClickedYes()
{
    DbgConPrtMeth(Yellow);
    EndDialog(IDYES);
}

VOID MainDialog::
OnBnClickedNo()
{
    DbgConPrtMeth(Yellow);
    EndDialog(IDNO);
}

VOID MainDialog::
OnBnClickedClose()
{
    DbgConPrtMeth(Yellow);
    EndDialog(IDCLOSE);
}

VOID MainDialog::
OnBnClickedHelp()
{
    DbgConPrtMeth(Yellow);
    EndDialog(IDHELP);
}
