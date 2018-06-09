/// \copyright The MIT License

#include "stdafx.h"
#include "Dialog.h"

#include "rrwindows/dbgcon.h"

IMPLEMENT_DYNAMIC(Dialog, CDialog)

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
    DbgConPrtMeth(Yellow);
}

BOOL Dialog::
Create(LPCTSTR lpszTemplateName, CWnd *pParentWnd /*=NULL*/)
{
    DbgConPrtMeth(Yellow);
    return CDialog::Create(lpszTemplateName, pParentWnd);
}

BOOL Dialog::
Create(UINT nIDTemplate, CWnd *pParentWnd /*=NULL*/)
{
    DbgConPrtMeth(Yellow);
    return CDialog::Create(nIDTemplate, pParentWnd);
}

BOOL Dialog::
CreateIndirect(LPCDLGTEMPLATE lpDialogTemplate, CWnd *pParentWnd /*=NULL*/, VOID *lpDialogInit /*=NULL*/)
{
    DbgConPrtMeth(Yellow);
    return CDialog::CreateIndirect(lpDialogTemplate, pParentWnd, lpDialogInit);
}

BOOL Dialog::
CreateIndirect(HGLOBAL hDialogTemplate, CWnd *pParentWnd /*=NULL*/)
{
    DbgConPrtMeth(Yellow);
    return CDialog::CreateIndirect(hDialogTemplate, pParentWnd);
}

INT_PTR Dialog::
DoModal()
{
    DbgConPrtMeth(Yellow);
    return CDialog::DoModal();
}

Dialog::
~Dialog()
{
    DbgConPrtMeth(Yellow);
}

#// Overridables

BOOL Dialog::
OnInitDialog()
{
    CDialog::OnInitDialog();
    DbgConPrtMeth(Yellow);
    return TRUE;
}

BOOL Dialog::
OnCmdMsg(UINT nID, INT nCode, VOID *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo)
{
    DbgConPrtMethCmdMsg(Yellow);
    return CDialog::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

BOOL Dialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConPrtMethWndMsg(Yellow);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID Dialog::
PreInitDialog()
{
    DbgConPrtMeth(Yellow);
    CDialog::PreInitDialog();
}

VOID Dialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DbgConPrtMeth(Yellow);
}

VOID Dialog::
OnOK()
{
    DbgConPrtMeth(Yellow);
    CDialog::OnOK();
}

VOID Dialog::
OnCancel()
{
    DbgConPrtMeth(Yellow);
    CDialog::OnCancel();
}

#// Message Handlers

VOID Dialog::
OnClose()
{
    DbgConPrtMeth(Yellow);
    CDialog::OnClose();
}

VOID Dialog::
OnBnClickedOk()
{
    DbgConPrtMeth(Yellow);
    CDialog::OnOK();
}

VOID Dialog::
OnBnClickedCancel()
{
    DbgConPrtMeth(Yellow);
    CDialog::OnCancel();
}

VOID Dialog::
OnBnClickedAbort()
{
    DbgConPrtMeth(Yellow);
    EndDialog(IDABORT);
}

VOID Dialog::
OnBnClickedRetry()
{
    DbgConPrtMeth(Yellow);
    EndDialog(IDRETRY);
}

VOID Dialog::
OnBnClickedIgnore()
{
    DbgConPrtMeth(Yellow);
    EndDialog(IDIGNORE);
}

VOID Dialog::
OnBnClickedYes()
{
    DbgConPrtMeth(Yellow);
    EndDialog(IDYES);
}

VOID Dialog::
OnBnClickedNo()
{
    DbgConPrtMeth(Yellow);
    EndDialog(IDNO);
}

VOID Dialog::
OnBnClickedClose()
{
    DbgConPrtMeth(Yellow);
    EndDialog(IDCLOSE);
}

VOID Dialog::
OnBnClickedHelp()
{
    DbgConPrtMeth(Yellow);
    EndDialog(IDHELP);
}
