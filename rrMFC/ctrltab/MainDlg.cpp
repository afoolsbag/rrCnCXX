/// \copyright The MIT License

#include "stdafx.h"
#include "MainDlg.h"

#include "resource.h"

BEGIN_MESSAGE_MAP(CMainDlg, CDialog)
END_MESSAGE_MAP()

CMainDlg::CMainDlg(CWnd *pParent /*=NULL*/)
    : CDialog(IDD_MAIN_DLG, pParent)
{}

BOOL CMainDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    {
        ctrl_tab_.InsertItem(0, TEXT("标签一"));
        ctrl_tab_page_0_.Create(IDC_MAIN_DLG_TAB_PAGE_0, &ctrl_tab_);
        ctrl_tab_.InsertItem(1, TEXT("标签二"));
        ctrl_tab_page_1_.Create(IDC_MAIN_DLG_TAB_PAGE_1, &ctrl_tab_);
        ctrl_tab_.InsertItem(2, TEXT("标签三"));
        ctrl_tab_page_2_.Create(IDC_MAIN_DLG_TAB_PAGE_2, &ctrl_tab_);

        CRect client_rect;
        ctrl_tab_.GetClientRect(&client_rect);
        for (ctrl_tab_.GetItemCount())
        CRect item_rect;
        ctrl_tab_.GetItemRect(0, &item_rect);
    }

    return TRUE;
}

void CMainDlg::DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_MAIN_DLG_TAB, ctrl_tab_);
}
