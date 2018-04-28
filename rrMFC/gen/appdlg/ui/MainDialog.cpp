/// \copyright The MIT License

#include "stdafx.h"
#include "MainDialog.h"

#include "utils/dbgcon.h"

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
    DbgConPrt(Yellow, TEXT("MainDialog::"));
    DbgConPrt(LightYellow, TEXT("Constructor\n"));
}

BOOL MainDialog::
Create(LPCTSTR lpszTemplateName, CWnd *pParentWnd /*=NULL*/)
{
    DbgConPrt(Yellow, TEXT("MainDialog::"));
    DbgConPrt(LightYellow, TEXT("Create\n"));
    return CDialog::Create(lpszTemplateName, pParentWnd);
}

BOOL MainDialog::
Create(UINT nIDTemplate, CWnd *pParentWnd /*=NULL*/)
{
    DbgConPrt(Yellow, TEXT("MainDialog::"));
    DbgConPrt(LightYellow, TEXT("Create\n"));
    return CDialog::Create(nIDTemplate, pParentWnd);
}

BOOL MainDialog::
CreateIndirect(LPCDLGTEMPLATE lpDialogTemplate, CWnd *pParentWnd /*=NULL*/, VOID *lpDialogInit /*=NULL*/)
{
    DbgConPrt(Yellow, TEXT("MainDialog::"));
    DbgConPrt(LightYellow, TEXT("CreateIndirect\n"));
    return CDialog::CreateIndirect(lpDialogTemplate, pParentWnd, lpDialogInit);
}

BOOL MainDialog::
CreateIndirect(HGLOBAL hDialogTemplate, CWnd *pParentWnd /*=NULL*/)
{
    DbgConPrt(Yellow, TEXT("MainDialog::"));
    DbgConPrt(LightYellow, TEXT("CreateIndirect\n"));
    return CDialog::CreateIndirect(hDialogTemplate, pParentWnd);
}

INT_PTR MainDialog::
DoModal()
{
    DbgConPrt(Yellow, TEXT("MainDialog::"));
    DbgConPrt(LightYellow, TEXT("DoModal\n"));
    return CDialog::DoModal();
}

MainDialog::
~MainDialog()
{
    DbgConPrt(Yellow, TEXT("MainDialog::"));
    DbgConPrt(LightYellow, TEXT("Destructor\n"));
}

#// Overridables

BOOL MainDialog::
OnInitDialog()
{
    CDialog::OnInitDialog();
    DbgConPrt(Yellow, TEXT("MainDialog::"));
    DbgConPrt(LightYellow, TEXT("OnInitDialog\n"));
    return TRUE;
}

BOOL MainDialog::
OnCmdMsg(UINT nID, INT nCode, VOID *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo)
{
    DbgConPrt(Yellow, TEXT("MainDialog::"));
    DbgConPrtCmdMsg(LightYellow, TEXT("OnCmdMsg"), nID, nCode, pExtra, pHandlerInfo);
    return CDialog::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

BOOL MainDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConPrt(Yellow, TEXT("MainDialog::"));
    DbgConPrtWndMsg(Yellow, TEXT("OnWndMsg"), message, wParam, lParam, pResult);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID MainDialog::
PreInitDialog()
{
    DbgConPrt(Yellow, TEXT("MainDialog::"));
    DbgConPrt(LightYellow, TEXT("PreInitDialog\n"));
    CDialog::PreInitDialog();
}

VOID MainDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DbgConPrt(Yellow, TEXT("MainDialog::"));
    DbgConPrt(LightYellow, TEXT("DoDataExchange\n"));
}

VOID MainDialog::
OnOK()
{
    DbgConPrt(Yellow, TEXT("MainDialog::"));
    DbgConPrt(LightYellow, TEXT("OnOK\n"));
    CDialog::OnOK();
}

VOID MainDialog::
OnCancel()
{
    DbgConPrt(Yellow, TEXT("MainDialog::"));
    DbgConPrt(LightYellow, TEXT("OnCancel\n"));
    CDialog::OnCancel();
}

#// Message Handlers

VOID MainDialog::
OnClose()
{
    DbgConPrt(Yellow, TEXT("MainDialog::"));
    DbgConPrt(LightYellow, TEXT("OnClose\n"));
    CDialog::OnClose();
}

VOID MainDialog::
OnBnClickedOk()
{
    DbgConPrt(Yellow, TEXT("MainDialog::"));
    DbgConPrt(LightYellow, TEXT("OnBnClickedOk\n"));
    CDialog::OnOK();
}

VOID MainDialog::
OnBnClickedCancel()
{
    DbgConPrt(Yellow, TEXT("MainDialog::"));
    DbgConPrt(LightYellow, TEXT("OnBnClickedCancel\n"));
    CDialog::OnCancel();
}

VOID MainDialog::
OnBnClickedAbort()
{
    DbgConPrt(Yellow, TEXT("MainDialog::"));
    DbgConPrt(LightYellow, TEXT("OnBnClickedAbort\n"));
    EndDialog(IDABORT);
}

VOID MainDialog::
OnBnClickedRetry()
{
    DbgConPrt(Yellow, TEXT("MainDialog::"));
    DbgConPrt(LightYellow, TEXT("OnBnClickedRetry\n"));
    EndDialog(IDRETRY);
}

VOID MainDialog::
OnBnClickedIgnore()
{
    DbgConPrt(Yellow, TEXT("MainDialog::"));
    DbgConPrt(LightYellow, TEXT("OnBnClickedIgnore\n"));
    EndDialog(IDIGNORE);
}

VOID MainDialog::
OnBnClickedYes()
{
    DbgConPrt(Yellow, TEXT("MainDialog::"));
    DbgConPrt(LightYellow, TEXT("OnBnClickedYes\n"));
    EndDialog(IDYES);
}

VOID MainDialog::
OnBnClickedNo()
{
    DbgConPrt(Yellow, TEXT("MainDialog::"));
    DbgConPrt(LightYellow, TEXT("OnBnClickedNo\n"));
    EndDialog(IDNO);
}

VOID MainDialog::
OnBnClickedClose()
{
    DbgConPrt(Yellow, TEXT("MainDialog::"));
    DbgConPrt(LightYellow, TEXT("OnBnClickedClose\n"));
    EndDialog(IDCLOSE);
}

VOID MainDialog::
OnBnClickedHelp()
{
    DbgConPrt(Yellow, TEXT("MainDialog::"));
    DbgConPrt(LightYellow, TEXT("OnBnClickedHelp\n"));
    EndDialog(IDHELP);
}
