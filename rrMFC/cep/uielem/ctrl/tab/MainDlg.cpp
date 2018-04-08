/// \copyright The MIT License

#include "stdafx.h"
#include "MainDlg.h"

#include "resource.h"

IMPLEMENT_DYNCREATE(CMainDlg, CDialog)

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
        tab_ctrl_.InsertItem(0, page_title);
        tab_page_0_ctrl_.Create(IDD_PAGE_DLG, &tab_ctrl_);

        page_title.LoadString(IDS_MAIN_DLG_TAB_PAGE_1);
        tab_ctrl_.InsertItem(1, page_title);
        tab_page_1_ctrl_.Create(IDD_PAGE_DLG, &tab_ctrl_);

        page_title.LoadString(IDS_MAIN_DLG_TAB_PAGE_2);
        tab_ctrl_.InsertItem(2, page_title);
        tab_page_2_ctrl_.Create(IDD_PAGE_DLG, &tab_ctrl_);

        CRect client_rect;
        tab_ctrl_.GetClientRect(&client_rect);
        CRect item_rect;
        CRect page_rect;

        tab_ctrl_.GetItemRect(0, &item_rect);
        page_rect.left = client_rect.left + 4;
        page_rect.top = item_rect.Height() + 4;
        page_rect.right = client_rect.right - 4;
        page_rect.bottom = client_rect.bottom - 4;
        tab_page_0_ctrl_.MoveWindow(&page_rect);

        tab_ctrl_.GetItemRect(1, &item_rect);
        page_rect.left = client_rect.left + 4;
        page_rect.top = item_rect.Height() + 4;
        page_rect.right = client_rect.right - 4;
        page_rect.bottom = client_rect.bottom - 4;
        tab_page_1_ctrl_.MoveWindow(&page_rect);

        tab_ctrl_.GetItemRect(2, &item_rect);
        page_rect.left = client_rect.left + 4;
        page_rect.top = item_rect.Height() + 4;
        page_rect.right = client_rect.right - 4;
        page_rect.bottom = client_rect.bottom - 4;
        tab_page_2_ctrl_.MoveWindow(&page_rect);

        tab_ctrl_.SetCurFocus(0);
        tab_page_0_ctrl_.ShowWindow(SW_SHOW);
    }

    return TRUE;
}

void CMainDlg::DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_MAIN_DLG_TAB, tab_ctrl_);
}

void CMainDlg::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
    switch (tab_ctrl_.GetCurSel()) {
    case 0:
        tab_page_0_ctrl_.ShowWindow(SW_SHOW);
        tab_page_0_ctrl_.SetFocus();
        tab_page_1_ctrl_.ShowWindow(SW_HIDE);
        tab_page_2_ctrl_.ShowWindow(SW_HIDE);
        break;
    case 1:
        tab_page_1_ctrl_.ShowWindow(SW_SHOW);
        tab_page_1_ctrl_.SetFocus();
        tab_page_0_ctrl_.ShowWindow(SW_HIDE);
        tab_page_2_ctrl_.ShowWindow(SW_HIDE);
        break;
    case 2:
        tab_page_2_ctrl_.ShowWindow(SW_SHOW);
        tab_page_2_ctrl_.SetFocus();
        tab_page_0_ctrl_.ShowWindow(SW_HIDE);
        tab_page_1_ctrl_.ShowWindow(SW_HIDE);
        break;
    default:
        ASSERT(FALSE);
        break;
    }

    *pResult = 0;
}
