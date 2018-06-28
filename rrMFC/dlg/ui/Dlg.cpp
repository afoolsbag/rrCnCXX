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
    DcMeth();
}

BOOL Dialog::
Create(LPCTSTR lpszTemplateName, CWnd *pParentWnd /*=NULL*/)
{
    DcMeth();
    return CDialog::Create(lpszTemplateName, pParentWnd);
}

BOOL Dialog::
Create(UINT nIDTemplate, CWnd *pParentWnd /*=NULL*/)
{
    DcMeth();
    return CDialog::Create(nIDTemplate, pParentWnd);
}

BOOL Dialog::
CreateIndirect(LPCDLGTEMPLATE lpDialogTemplate, CWnd *pParentWnd /*=NULL*/, VOID *lpDialogInit /*=NULL*/)
{
    DcMeth();
    return CDialog::CreateIndirect(lpDialogTemplate, pParentWnd, lpDialogInit);
}

BOOL Dialog::
CreateIndirect(HGLOBAL hDialogTemplate, CWnd *pParentWnd /*=NULL*/)
{
    DcMeth();
    return CDialog::CreateIndirect(hDialogTemplate, pParentWnd);
}

INT_PTR Dialog::
DoModal()
{
    DcMeth();
    return CDialog::DoModal();
}

Dialog::
~Dialog()
{
    DcMeth();
}

#// Overridables

BOOL Dialog::
OnInitDialog()
{
    CDialog::OnInitDialog();
    DcMeth();
    return TRUE;
}

BOOL Dialog::
OnCmdMsg(UINT nID, INT nCode, VOID *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo)
{
    DcCmdMsg();
    return CDialog::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

BOOL Dialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DcWndMsg();
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID Dialog::
PreInitDialog()
{
    DcMeth();
    CDialog::PreInitDialog();
}

VOID Dialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DcMeth();
}

VOID Dialog::
OnOK()
{
    DcMeth();
    CDialog::OnOK();
}

VOID Dialog::
OnCancel()
{
    DcMeth();
    CDialog::OnCancel();
}

#// Message Handlers

VOID Dialog::
OnClose()
{
    DcMeth();
    CDialog::OnClose();
}

VOID Dialog::
OnBnClickedOk()
{
    DcMeth();
    CDialog::OnOK();
}

VOID Dialog::
OnBnClickedCancel()
{
    DcMeth();
    CDialog::OnCancel();
}

VOID Dialog::
OnBnClickedAbort()
{
    DcMeth();
    EndDialog(IDABORT);
}

VOID Dialog::
OnBnClickedRetry()
{
    DcMeth();
    EndDialog(IDRETRY);
}

VOID Dialog::
OnBnClickedIgnore()
{
    DcMeth();
    EndDialog(IDIGNORE);
}

VOID Dialog::
OnBnClickedYes()
{
    DcMeth();
    EndDialog(IDYES);
}

VOID Dialog::
OnBnClickedNo()
{
    DcMeth();
    EndDialog(IDNO);
}

VOID Dialog::
OnBnClickedClose()
{
    DcMeth();
    EndDialog(IDCLOSE);
}

VOID Dialog::
OnBnClickedHelp()
{
    DcMeth();
    EndDialog(IDHELP);
}
