/// \copyright The MIT License

#include "stdafx.h"
#include "MainDialog.h"

#include "rrwindows/dbgcon.h"
#include "rrwindows/sysmsgstr.h"

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
    DbgConPrtDbl(Yellow, TEXT("MainDialog::"), LightYellow, TEXT("Constructor\n"));
}

BOOL MainDialog::
Create(LPCTSTR lpszTemplateName, CWnd *pParentWnd /*=NULL*/)
{
    DbgConPrtDbl(Yellow, TEXT("MainDialog::"), LightYellow, TEXT("Create\n"));
    return CDialog::Create(lpszTemplateName, pParentWnd);
}

BOOL MainDialog::
Create(UINT nIDTemplate, CWnd *pParentWnd /*=NULL*/)
{
    DbgConPrtDbl(Yellow, TEXT("MainDialog::"), LightYellow, TEXT("Create\n"));
    return CDialog::Create(nIDTemplate, pParentWnd);
}

BOOL MainDialog::
CreateIndirect(LPCDLGTEMPLATE lpDialogTemplate, CWnd *pParentWnd /*=NULL*/, VOID *lpDialogInit /*=NULL*/)
{
    DbgConPrtDbl(Yellow, TEXT("MainDialog::"), LightYellow, TEXT("CreateIndirect\n"));
    return CDialog::CreateIndirect(lpDialogTemplate, pParentWnd, lpDialogInit);
}

BOOL MainDialog::
CreateIndirect(HGLOBAL hDialogTemplate, CWnd *pParentWnd /*=NULL*/)
{
    DbgConPrtDbl(Yellow, TEXT("MainDialog::"), LightYellow, TEXT("CreateIndirect\n"));
    return CDialog::CreateIndirect(hDialogTemplate, pParentWnd);
}

INT_PTR MainDialog::
DoModal()
{
    DbgConPrtDbl(Yellow, TEXT("MainDialog::"), LightYellow, TEXT("DoModal\n"));
    return CDialog::DoModal();
}

MainDialog::
~MainDialog()
{
    DbgConPrtDbl(Yellow, TEXT("MainDialog::"), LightYellow, TEXT("Destructor\n"));
}

#// Overridables

BOOL MainDialog::
OnInitDialog()
{
    CDialog::OnInitDialog();
    DbgConPrtDbl(Yellow, TEXT("MainDialog::"), LightYellow, TEXT("OnInitDialog\n"));
    return TRUE;
}

BOOL MainDialog::
OnCmdMsg(UINT nID, INT nCode, VOID *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo)
{
    DbgConPrtDbl(Yellow, TEXT("MainDialog::"), LightYellow, TEXT("OnCmdMsg %u with %d, 0x%p, 0x%p\n"), nID, nCode, pExtra, pHandlerInfo);
    return CDialog::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

BOOL MainDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConPrt(Yellow, TEXT("MainDialog::OnWndMsg 0x%04X(%s), with %u, %ld, 0x%p\n"), message, SysMsgStr(message), wParam, lParam, pResult);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID MainDialog::
PreInitDialog()
{
    DbgConPrtDbl(Yellow, TEXT("MainDialog::"), LightYellow, TEXT("PreInitDialog\n"));
    CDialog::PreInitDialog();
}

VOID MainDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DbgConPrtDbl(Yellow, TEXT("MainDialog::"), LightYellow, TEXT("DoDataExchange\n"));
}

VOID MainDialog::
OnOK()
{
    DbgConPrtDbl(Yellow, TEXT("MainDialog::"), LightYellow, TEXT("OnOK\n"));
    CDialog::OnOK();
}

VOID MainDialog::
OnCancel()
{
    DbgConPrtDbl(Yellow, TEXT("MainDialog::"), LightYellow, TEXT("OnCancel\n"));
    CDialog::OnCancel();
}

#// Message Handlers

VOID MainDialog::
OnClose()
{
    DbgConPrtDbl(Yellow, TEXT("MainDialog::"), LightYellow, TEXT("OnClose\n"));
    CDialog::OnClose();
}

VOID MainDialog::
OnBnClickedOk()
{
    DbgConPrtDbl(Yellow, TEXT("MainDialog::"), LightYellow, TEXT("OnBnClickedOk\n"));
    CDialog::OnOK();
}

VOID MainDialog::
OnBnClickedCancel()
{
    DbgConPrtDbl(Yellow, TEXT("MainDialog::"), LightYellow, TEXT("OnBnClickedCancel\n"));
    CDialog::OnCancel();
}

VOID MainDialog::
OnBnClickedAbort()
{
    DbgConPrtDbl(Yellow, TEXT("MainDialog::"), LightYellow, TEXT("OnBnClickedAbort\n"));
    EndDialog(IDABORT);
}

VOID MainDialog::
OnBnClickedRetry()
{
    DbgConPrtDbl(Yellow, TEXT("MainDialog::"), LightYellow, TEXT("OnBnClickedRetry\n"));
    EndDialog(IDRETRY);
}

VOID MainDialog::
OnBnClickedIgnore()
{
    DbgConPrtDbl(Yellow, TEXT("MainDialog::"), LightYellow, TEXT("OnBnClickedIgnore\n"));
    EndDialog(IDIGNORE);
}

VOID MainDialog::
OnBnClickedYes()
{
    DbgConPrtDbl(Yellow, TEXT("MainDialog::"), LightYellow, TEXT("OnBnClickedYes\n"));
    EndDialog(IDYES);
}

VOID MainDialog::
OnBnClickedNo()
{
    DbgConPrtDbl(Yellow, TEXT("MainDialog::"), LightYellow, TEXT("OnBnClickedNo\n"));
    EndDialog(IDNO);
}

VOID MainDialog::
OnBnClickedClose()
{
    DbgConPrtDbl(Yellow, TEXT("MainDialog::"), LightYellow, TEXT("OnBnClickedClose\n"));
    EndDialog(IDCLOSE);
}

VOID MainDialog::
OnBnClickedHelp()
{
    DbgConPrtDbl(Yellow, TEXT("MainDialog::"), LightYellow, TEXT("OnBnClickedHelp\n"));
    EndDialog(IDHELP);
}
