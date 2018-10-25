/// \copyright The Unlicense

#include "stdafx.h"
#include "Dialog.h"
#include "ui.rc.h"

namespace rrMFC {

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

// Constructors

BOOL Dialog::
Create(LPCTSTR lpszTemplateName, CWnd *pParentWnd /*=NULL*/)
{
    TRACE(__FUNCTION__ "\n");
    return CDialog::Create(lpszTemplateName, pParentWnd);
}

BOOL Dialog::
Create(unsigned nIDTemplate, CWnd *pParentWnd /*=NULL*/)
{
    TRACE(__FUNCTION__ "\n");
    return CDialog::Create(nIDTemplate, pParentWnd);
}

BOOL Dialog::
CreateIndirect(LPCDLGTEMPLATE lpDialogTemplate, CWnd *pParentWnd /*=NULL*/, void *lpDialogInit /*=NULL*/)
{
    TRACE(__FUNCTION__ "\n");
    return CDialog::CreateIndirect(lpDialogTemplate, pParentWnd, lpDialogInit);
}

BOOL Dialog::
CreateIndirect(HGLOBAL hDialogTemplate, CWnd *pParentWnd /*=NULL*/)
{
    TRACE(__FUNCTION__ "\n");
    return CDialog::CreateIndirect(hDialogTemplate, pParentWnd);
}

INT_PTR Dialog::
DoModal()
{
    TRACE(__FUNCTION__ "\n");
    return CDialog::DoModal();
}

// Attributes

const unsigned Dialog::IDD {IDD_DIALOG};

// Overridables

BOOL Dialog::
OnInitDialog()
{
    CDialog::OnInitDialog();
    TRACE(__FUNCTION__ "\n");
    return TRUE;
}

void Dialog::
PreInitDialog()
{
    TRACE(__FUNCTION__ "\n");
    CDialog::PreInitDialog();
}

void Dialog::
OnOK()
{
    TRACE(__FUNCTION__ "\n");
    CDialog::OnOK();
}

void Dialog::
OnCancel()
{
    TRACE(__FUNCTION__ "\n");
    CDialog::OnCancel();
}

#// Message Handlers

void Dialog::
OnClose()
{
    TRACE(__FUNCTION__ "\n");
    CDialog::OnClose();
}

void Dialog::
OnBnClickedOk()
{
    TRACE(__FUNCTION__ "\n");
    CDialog::OnOK();
}

void Dialog::
OnBnClickedCancel()
{
    TRACE(__FUNCTION__ "\n");
    CDialog::OnCancel();
}

void Dialog::
OnBnClickedAbort()
{
    TRACE(__FUNCTION__ "\n");
    EndDialog(IDABORT);
}

void Dialog::
OnBnClickedRetry()
{
    TRACE(__FUNCTION__ "\n");
    EndDialog(IDRETRY);
}

void Dialog::
OnBnClickedIgnore()
{
    TRACE(__FUNCTION__ "\n");
    EndDialog(IDIGNORE);
}

void Dialog::
OnBnClickedYes()
{
    TRACE(__FUNCTION__ "\n");
    EndDialog(IDYES);
}

void Dialog::
OnBnClickedNo()
{
    TRACE(__FUNCTION__ "\n");
    EndDialog(IDNO);
}

void Dialog::
OnBnClickedClose()
{
    TRACE(__FUNCTION__ "\n");
    EndDialog(IDCLOSE);
}

void Dialog::
OnBnClickedHelp()
{
    TRACE(__FUNCTION__ "\n");
    EndDialog(IDHELP);
}

}//namespace rrMFC
