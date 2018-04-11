/// \copyright The MIT License

#include "stdafx.h"
#include "resource.h"
#include "MainDialog.h"

IMPLEMENT_DYNCREATE(MainDialog, CDialog)

BEGIN_MESSAGE_MAP(MainDialog, CDialog)
    ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &MainDialog::OnTcnSelchangeTab)
END_MESSAGE_MAP()

MainDialog::MainDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{}

VOID MainDialog::DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_TAB, TabControl);
}

BOOL MainDialog::OnInitDialog()
{
    CDialog::OnInitDialog();

    {
        CString pageTitle;

        pageTitle.LoadString(IDS_TAB_PAGE_0);
        TabControl.InsertItem(0, pageTitle);
        TabPage0Control.Create(PageDialog::IDD, &TabControl);

        pageTitle.LoadString(IDS_TAB_PAGE_1);
        TabControl.InsertItem(1, pageTitle);
        TabPage1Control.Create(PageDialog::IDD, &TabControl);

        pageTitle.LoadString(IDS_TAB_PAGE_2);
        TabControl.InsertItem(2, pageTitle);
        TabPage2Control.Create(PageDialog::IDD, &TabControl);

        CRect cltRect;  // client rect
        TabControl.GetClientRect(&cltRect);
        CRect itemRect;
        CRect pageRect;

        TabControl.GetItemRect(0, &itemRect);
        pageRect.left = cltRect.left + 4;
        pageRect.top = itemRect.Height() + 4;
        pageRect.right = cltRect.right - 4;
        pageRect.bottom = cltRect.bottom - 4;
        TabPage0Control.MoveWindow(&pageRect);

        TabControl.GetItemRect(1, &itemRect);
        pageRect.left = cltRect.left + 4;
        pageRect.top = itemRect.Height() + 4;
        pageRect.right = cltRect.right - 4;
        pageRect.bottom = cltRect.bottom - 4;
        TabPage1Control.MoveWindow(&pageRect);

        TabControl.GetItemRect(2, &itemRect);
        pageRect.left = cltRect.left + 4;
        pageRect.top = itemRect.Height() + 4;
        pageRect.right = cltRect.right - 4;
        pageRect.bottom = cltRect.bottom - 4;
        TabPage2Control.MoveWindow(&pageRect);

        TabControl.SetCurFocus(0);
        TabPage0Control.ShowWindow(SW_SHOW);
    }

    return TRUE;
}

void MainDialog::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
    switch (TabControl.GetCurSel()) {
    case 0:
        TabPage0Control.ShowWindow(SW_SHOW);
        TabPage0Control.SetFocus();
        TabPage1Control.ShowWindow(SW_HIDE);
        TabPage2Control.ShowWindow(SW_HIDE);
        break;
    case 1:
        TabPage0Control.ShowWindow(SW_HIDE);
        TabPage1Control.ShowWindow(SW_SHOW);
        TabPage1Control.SetFocus();
        TabPage2Control.ShowWindow(SW_HIDE);
        break;
    case 2:
        TabPage0Control.ShowWindow(SW_HIDE);
        TabPage1Control.ShowWindow(SW_HIDE);
        TabPage2Control.ShowWindow(SW_SHOW);
        TabPage2Control.SetFocus();
        break;
    default:
        ASSERT(FALSE);
        break;
    }

    *pResult = 0;
}
