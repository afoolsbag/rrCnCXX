/// \copyright The Unlicense

#include "stdafx.h"
#include "Dialog.h"
#include "Dialog.rc.h"

#include "rrwindows/rrwindows.h"

namespace rrMFC {
namespace Test {

const unsigned Dialog::IDD {IDD_DIALOG};

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
Dialog(CWnd *pParent /*=nullptr*/)
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
Create(unsigned nIDTemplate, CWnd *pParentWnd /*=NULL*/)
{
    DcMeth();
    return CDialog::Create(nIDTemplate, pParentWnd);
}

BOOL Dialog::
CreateIndirect(LPCDLGTEMPLATE lpDialogTemplate, CWnd *pParentWnd /*=NULL*/, void *lpDialogInit /*=NULL*/)
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
OnCmdMsg(unsigned nID, int nCode, void *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo)
{
    DcCmdMsg();
    return CDialog::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

BOOL Dialog::
OnWndMsg(unsigned message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DcWndMsg();
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

void Dialog::
PreInitDialog()
{
    DcMeth();
    CDialog::PreInitDialog();
}

void Dialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DcMeth();
}

void Dialog::
OnOK()
{
    DcMeth();
    CDialog::OnOK();
}

void Dialog::
OnCancel()
{
    DcMeth();
    CDialog::OnCancel();
}

#// Message Handlers

void Dialog::
OnClose()
{
    DcMeth();
    CDialog::OnClose();
}

void Dialog::
OnBnClickedOk()
{
    DcMeth();
    CDialog::OnOK();
}

void Dialog::
OnBnClickedCancel()
{
    DcMeth();
    CDialog::OnCancel();
}

void Dialog::
OnBnClickedAbort()
{
    DcMeth();
    EndDialog(IDABORT);
}

void Dialog::
OnBnClickedRetry()
{
    DcMeth();
    EndDialog(IDRETRY);
}

void Dialog::
OnBnClickedIgnore()
{
    DcMeth();
    EndDialog(IDIGNORE);
}

void Dialog::
OnBnClickedYes()
{
    DcMeth();
    EndDialog(IDYES);
}

void Dialog::
OnBnClickedNo()
{
    DcMeth();
    EndDialog(IDNO);
}

void Dialog::
OnBnClickedClose()
{
    DcMeth();
    EndDialog(IDCLOSE);
}

void Dialog::
OnBnClickedHelp()
{
    DcMeth();
    EndDialog(IDHELP);
}

}//namespace Test
}//namespace rrMFC
