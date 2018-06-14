/// \copyright The MIT License

#include "stdafx.h"
#include "Dlg.h"

#include "rrwindows/dbgcon.h"

BEGIN_MESSAGE_MAP(Dialog, CDialog)
    ON_WM_CLOSE()

    ON_BN_CLICKED(IDOK, &Dialog::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &Dialog::OnBnClickedCancel)

    ON_BN_CLICKED(IDABORT, &Dialog::OnBnClickedAbort)
    ON_BN_CLICKED(IDRETRY, &Dialog::OnBnClickedRetry)
    ON_BN_CLICKED(IDIGNORE, &Dialog::OnBnClickedIgnore)

    ON_BN_CLICKED(IDYES, &Dialog::OnBnClickedYes)
    ON_BN_CLICKED(IDNO, &Dialog::OnBnClickedNo)

    ON_BN_CLICKED(IDCLOSE, &Dialog::OnBnClickedClose)
    ON_BN_CLICKED(IDHELP, &Dialog::OnBnClickedHelp)
END_MESSAGE_MAP()

#// Constructors

Dialog::
Dialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    DbgConMeth();
}

BOOL Dialog::
Create(LPCTSTR lpszTemplateName, CWnd *pParentWnd /*=NULL*/)
{
    DbgConMeth();
    return CDialog::Create(lpszTemplateName, pParentWnd);
}

BOOL Dialog::
Create(UINT nIDTemplate, CWnd *pParentWnd /*=NULL*/)
{
    DbgConMeth();
    return CDialog::Create(nIDTemplate, pParentWnd);
}

BOOL Dialog::
CreateIndirect(LPCDLGTEMPLATE lpDialogTemplate, CWnd *pParentWnd /*=NULL*/, VOID *lpDialogInit /*=NULL*/)
{
    DbgConMeth();
    return CDialog::CreateIndirect(lpDialogTemplate, pParentWnd, lpDialogInit);
}

BOOL Dialog::
CreateIndirect(HGLOBAL hDialogTemplate, CWnd *pParentWnd /*=NULL*/)
{
    DbgConMeth();
    return CDialog::CreateIndirect(hDialogTemplate, pParentWnd);
}

INT_PTR Dialog::
DoModal()
{
    DbgConMeth();
    return CDialog::DoModal();
}

Dialog::
~Dialog()
{
    DbgConMeth();
}

#// Overridables

BOOL Dialog::
OnInitDialog()
{
    CDialog::OnInitDialog();
    DbgConMeth();
    return TRUE;
}

BOOL Dialog::
OnCmdMsg(UINT nID, INT nCode, VOID *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo)
{
    DbgConCmdMsg();
    return CDialog::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

BOOL Dialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConWndMsg();
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID Dialog::
PreInitDialog()
{
    DbgConMeth();
    CDialog::PreInitDialog();
}

VOID Dialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DbgConMeth();
}

VOID Dialog::
OnOK()
{
    DbgConMeth();
    CDialog::OnOK();
}

VOID Dialog::
OnCancel()
{
    DbgConMeth();
    CDialog::OnCancel();
}

#// Message Handlers

VOID Dialog::
OnClose()
{
    DbgConMeth();
    CDialog::OnClose();
}

VOID Dialog::
OnBnClickedOk()
{
    DbgConMeth();
    CDialog::OnOK();
}

VOID Dialog::
OnBnClickedCancel()
{
    DbgConMeth();
    CDialog::OnCancel();
}

VOID Dialog::
OnBnClickedAbort()
{
    DbgConMeth();
    EndDialog(IDABORT);
}

VOID Dialog::
OnBnClickedRetry()
{
    DbgConMeth();
    EndDialog(IDRETRY);
}

VOID Dialog::
OnBnClickedIgnore()
{
    DbgConMeth();
    EndDialog(IDIGNORE);
}

VOID Dialog::
OnBnClickedYes()
{
    DbgConMeth();
    EndDialog(IDYES);
}

VOID Dialog::
OnBnClickedNo()
{
    DbgConMeth();
    EndDialog(IDNO);
}

VOID Dialog::
OnBnClickedClose()
{
    DbgConMeth();
    EndDialog(IDCLOSE);
}

VOID Dialog::
OnBnClickedHelp()
{
    DbgConMeth();
    EndDialog(IDHELP);
}
