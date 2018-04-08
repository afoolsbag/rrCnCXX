/// \copyright The MIT License

#include "stdafx.h"
#include "MainDlg.h"

#include "resource.h"

BEGIN_MESSAGE_MAP(CMainDlg, CDialog)
    ON_NOTIFY(TCN_SELCHANGE, IDC_MAIN_DLG_TAB, &CMainDlg::OnTcnSelchangeTab)
END_MESSAGE_MAP()

CMainDlg::CMainDlg(CWnd *pParent /*=NULL*/)
    : CDialog(IDD_MAIN_DLG, pParent)
{}

BOOL CMainDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    {
        CString page_title;

        page_title.LoadString(IDS_MAIN_DLG_TAB_PAGE_0);
        ctrl_tab_.InsertItem(0, page_title);
        ctrl_tab_page_0_.Create(IDD_PAGE_DLG, &ctrl_tab_);

        page_title.LoadString(IDS_MAIN_DLG_TAB_PAGE_1);
        ctrl_tab_.InsertItem(1, page_title);
        ctrl_tab_page_1_.Create(IDD_PAGE_DLG, &ctrl_tab_);

        page_title.LoadString(IDS_MAIN_DLG_TAB_PAGE_2);
        ctrl_tab_.InsertItem(2, page_title);
        ctrl_tab_page_2_.Create(IDD_PAGE_DLG, &ctrl_tab_);

        CRect client_rect;
        ctrl_tab_.GetClientRect(&client_rect);
        CRect item_rect;
        CRect page_rect;

        ctrl_tab_.GetItemRect(0, &item_rect);
        page_rect.left = client_rect.left + 4;
        page_rect.top = item_rect.Height() + 4;
        page_rect.right = client_rect.right - 4;
        page_rect.bottom = client_rect.bottom - 4;
        ctrl_tab_page_0_.MoveWindow(&page_rect);

        ctrl_tab_.GetItemRect(1, &item_rect);
        page_rect.left = client_rect.left + 4;
        page_rect.top = item_rect.Height() + 4;
        page_rect.right = client_rect.right - 4;
        page_rect.bottom = client_rect.bottom - 4;
        ctrl_tab_page_1_.MoveWindow(&page_rect);

        ctrl_tab_.GetItemRect(2, &item_rect);
        page_rect.left = client_rect.left + 4;
        page_rect.top = item_rect.Height() + 4;
        page_rect.right = client_rect.right - 4;
        page_rect.bottom = client_rect.bottom - 4;
        ctrl_tab_page_2_.MoveWindow(&page_rect);

        ctrl_tab_.SetCurFocus(0);
        ctrl_tab_page_0_.ShowWindow(SW_SHOW);
    }

    return TRUE;
}

void CMainDlg::DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_MAIN_DLG_TAB, ctrl_tab_);
}

void CMainDlg::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
    switch (ctrl_tab_.GetCurSel()) {
    case 0:
        ctrl_tab_page_0_.ShowWindow(SW_SHOW);
        ctrl_tab_page_0_.SetFocus();
        ctrl_tab_page_1_.ShowWindow(SW_HIDE);
        ctrl_tab_page_2_.ShowWindow(SW_HIDE);
        break;
    case 1:
        ctrl_tab_page_1_.ShowWindow(SW_SHOW);
        ctrl_tab_page_1_.SetFocus();
        ctrl_tab_page_0_.ShowWindow(SW_HIDE);
        ctrl_tab_page_2_.ShowWindow(SW_HIDE);
        break;
    case 2:
        ctrl_tab_page_2_.ShowWindow(SW_SHOW);
        ctrl_tab_page_2_.SetFocus();
        ctrl_tab_page_0_.ShowWindow(SW_HIDE);
        ctrl_tab_page_1_.ShowWindow(SW_HIDE);
        break;
    default:
        ASSERT(FALSE);
        break;
    }

    *pResult = 0;
}
