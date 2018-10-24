/// \copyright The Unlicense

#include "stdafx.h"
#include "ButtonDialog.h"
#include "ButtonDialog.rc.h"

namespace rrMFC {

BEGIN_MESSAGE_MAP(ButtonDialog, CDialog)
    ON_BN_CLICKED(IDC_BUTTON, &ButtonDialog::OnBnClickedButton)
    ON_BN_CLICKED(IDC_MFC_BUTTON, &ButtonDialog::OnBnClickedMfcButton)
END_MESSAGE_MAP()

// Attributes

const unsigned ButtonDialog::IDD {IDD_BUTTON_DIALOG};

// Overridables

void ButtonDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    TRACE(__FUNCTION__ "\n");
    DDX_Control(pDX, IDC_BUTTON, Button);

    DDX_Control(pDX, IDC_MFC_BUTTON, MfcButton);

    DDX_Control(pDX, IDC_MFC_COLOR_BUTTON, MfcColorButton);
    DDX_Text(pDX, IDC_MFC_COLOR_BUTTON, MfcColor);

    DDX_Control(pDX, IDC_MFC_LINK_BUTTON, MfcLinkButton);
    DDX_Text(pDX, IDC_MFC_LINK_BUTTON, MfcLink);

    DDX_Control(pDX, IDC_MFC_MENU_BUTTON, MfcMenuButton);
}

// Message Handlers

void ButtonDialog::
OnBnClickedButton()
{
    TRACE(__FUNCTION__ "\n");
}

void ButtonDialog::
OnBnClickedMfcButton()
{
    TRACE(__FUNCTION__ "\n");
}

}//namespace rrMFC
