/// \copyright The MIT License

#include "stdafx.h"
#include "ButtonDialog.h"

#include "rrwindows/dbgcon.h"

IMPLEMENT_DYNAMIC(ButtonDialog, CDialog)

BEGIN_MESSAGE_MAP(ButtonDialog, CDialog)
    ON_BN_CLICKED(IDC_BUTTON, &ButtonDialog::OnBnClickedButton)
    ON_BN_CLICKED(IDC_MFC_BUTTON, &ButtonDialog::OnBnClickedMfcButton)
END_MESSAGE_MAP()

#// Constructors

ButtonDialog::
ButtonDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    DbgConPrtMeth(Yellow);
}

ButtonDialog::
~ButtonDialog()
{
    DbgConPrtMeth(Yellow);
}

#// Overridables

BOOL ButtonDialog::
OnInitDialog()
{
    CDialog::OnInitDialog();
    DbgConPrtMeth(Yellow);
    return TRUE;
}

BOOL ButtonDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConPrtMethWndMsg(Yellow);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID ButtonDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DbgConPrtMeth(Yellow);
    DDX_Control(pDX, IDC_BUTTON, Button);
    DDX_Control(pDX, IDC_MFC_BUTTON, MfcButton);
    DDX_Control(pDX, IDC_MFC_COLOR_BUTTON, MfcColorButton);
    DDX_Text(pDX, IDC_MFC_COLOR_BUTTON, MfcColor);
    DDX_Control(pDX, IDC_MFC_LINK_BUTTON, MfcLinkButton);
    DDX_Text(pDX, IDC_MFC_LINK_BUTTON, MfcLink);
    DDX_Control(pDX, IDC_MFC_MENU_BUTTON, MfcMenuButton);
}

#// Message Handlers

VOID ButtonDialog::
OnBnClickedButton()
{
    DbgConPrtMeth(Yellow);
}

VOID ButtonDialog::
OnBnClickedMfcButton()
{
    DbgConPrtMeth(Yellow);
}
