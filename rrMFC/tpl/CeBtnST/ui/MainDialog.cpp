/// \copyright The MIT License

#include "stdafx.h"
#include "MainDialog.h"

#include "rrwindows/dbgcon.h"

#include "resource.h"

IMPLEMENT_DYNCREATE(MainDialog, CDialog)

//BEGIN_MESSAGE_MAP(MainDialog, CDialog)
//END_MESSAGE_MAP()

#// Constructors

MainDialog::
MainDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    DbgConPrtMeth(Yellow);
}

MainDialog::
~MainDialog()
{
    DbgConPrtMeth(Yellow);
}

#// Overridables

BOOL MainDialog::
OnInitDialog()
{
    CDialog::OnInitDialog();
    DbgConPrtMeth(Yellow);

    CONST COLORREF buttonColor = GetSysColor(COLOR_BTNFACE) + RGB(30, 30, 30);

    {
        StandardButton.SetIcon(IDI_DISK_AND_WRENCH, CSize(32, 32));
        StandardButton.SetFlat(FALSE);
    }

    {
        KeysButton.SetIcon(IDI_KEYS, CSize(48, 48));
        KeysButton.SetColor(CCeButtonST::BTNST_COLOR_BK_IN, buttonColor);
    }

    {
        DisabledButton.SetIcon(IDI_LOUDSPEAKER, CSize(32, 32),
                               NULL, CSize(32, 32),
                               IDI_LOUDSPEAKER_SILHOUETTE, CSize(32, 32));
        DisabledButton.SetColor(CCeButtonST::BTNST_COLOR_BK_IN, buttonColor);
    }

    {
        SearchButton.SetIcon(IDI_MAGNIFIER, CSize(32, 32),
                             IDI_MAGNIFIER_GRAYSCALE, CSize(32, 32));
        SearchButton.SetColor(CCeButtonST::BTNST_COLOR_BK_IN, buttonColor);
        SearchButton.SetAlign(CCeButtonST::ST_ALIGN_VERT);
        SearchButton.SetMenu(IDM_BUTTON_MENU, m_hWnd);
    }

    {
        LampButton.SetIcon(IDI_LAMP_ON, CSize(32, 32),
                           IDI_LAMP_OFF, CSize(32, 32));
        LampButton.SetColor(CCeButtonST::BTNST_COLOR_BK_IN, buttonColor);
    }

    {
        CheckboxButton.SetFont(GetFont());
        CheckboxButton.SetIcon(IDI_LED_ON, CSize(16, 16),
                               IDI_LED_OFF, CSize(16, 16));
        CheckboxButton.SetColor(CCeButtonST::BTNST_COLOR_BK_IN, buttonColor);
    }

    {
        WebButton.SetIcon(IDI_EARTH, CSize(16, 16));
        WebButton.SetBtnCursor(IDC_CLICKER_HAND, FALSE);
        WebButton.SetURL(TEXT("https://localhost/"));
    }

    {
        EMailButton.SetIcon(IDI_EMAIL, CSize(16, 16));
        EMailButton.SetURL(TEXT("mailto:user@host"));
    }

    return TRUE;
}

VOID MainDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DbgConPrtMeth(Yellow);
    DDX_Control(pDX, IDC_STANDARD_BUTTON, StandardButton);
    DDX_Control(pDX, IDC_SEARCH_BUTTON, SearchButton);
    DDX_Control(pDX, IDC_KEY_MANAGER_BUTTON, KeysButton);
    DDX_Control(pDX, IDC_DISABLED_BUTTON, DisabledButton);
    DDX_Control(pDX, IDC_LAMP_BUTTON, LampButton);
    DDX_Control(pDX, IDC_CHECKBOX_BUTTON, CheckboxButton);
    DDX_Control(pDX, IDC_WEB_BUTTON, WebButton);
    DDX_Control(pDX, IDC_MAIL_BUTTON, EMailButton);
}

BOOL MainDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConPrtMethWndMsg(Yellow);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

#// Implementation

#// Message Handlers
