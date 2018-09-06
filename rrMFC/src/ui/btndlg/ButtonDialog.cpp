/// \copyright The Unlicense

#include "stdafx.h"
#include "ButtonDialog.h"
#include "ButtonDialog.rc.h"

#include "rrwindows/rrwindows.h"

namespace rrMFC {

const UINT ButtonDialog::IDD {IDD_BUTTON_DIALOG};

BEGIN_MESSAGE_MAP(ButtonDialog, CDialog)
    ON_BN_CLICKED(IDC_BUTTON, &ButtonDialog::OnBnClickedButton)
    ON_BN_CLICKED(IDC_MFC_BUTTON, &ButtonDialog::OnBnClickedMfcButton)
END_MESSAGE_MAP()

#// Constructors

ButtonDialog::
ButtonDialog(CWnd *pParent/*=nullptr*/)
    : CDialog(IDD, pParent)
{
    DcMeth();
}

ButtonDialog::
~ButtonDialog()
{
    DcMeth();
}

#// Overridables

BOOL ButtonDialog::
OnInitDialog()
{
    CDialog::OnInitDialog();
    DcMeth();
    return TRUE;
}

BOOL ButtonDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DcWndMsg();
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

void ButtonDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DcMeth();
    DDX_Control(pDX, IDC_BUTTON, Button);
    DDX_Control(pDX, IDC_MFC_BUTTON, MfcButton);
    DDX_Control(pDX, IDC_MFC_COLOR_BUTTON, MfcColorButton);
    DDX_Text(pDX, IDC_MFC_COLOR_BUTTON, MfcColor);
    DDX_Control(pDX, IDC_MFC_LINK_BUTTON, MfcLinkButton);
    DDX_Text(pDX, IDC_MFC_LINK_BUTTON, MfcLink);
    DDX_Control(pDX, IDC_MFC_MENU_BUTTON, MfcMenuButton);
}

#// Message Handlers

void ButtonDialog::
OnBnClickedButton()
{
    DcMeth();
}

void ButtonDialog::
OnBnClickedMfcButton()
{
    DcMeth();
}

}//namespace rrMFC
