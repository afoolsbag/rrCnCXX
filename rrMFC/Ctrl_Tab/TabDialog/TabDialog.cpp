/// \copyright The Unlicense

#include "stdafx.h"
#include "TabDialog.h"
#include "TabDialog.rc.h"

namespace rrMFC {

BEGIN_MESSAGE_MAP(TabDialog, CDialog)
    ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &TabDialog::OnTcnSelchangeTab)
END_MESSAGE_MAP()

// Attributes

const unsigned TabDialog::IDD {IDD_TAB_DIALOG};

// Overridables

BOOL TabDialog::
OnInitDialog()
{
    CDialog::OnInitDialog();

    {
        CString txt;
        txt.LoadString(IDS_TAB_PAGE_1);
        Tab.InsertItem(TabPage1, txt);
        TabPg1.Create(PageDialog::IDD, &Tab);
        CorrectTabPage(TabPage1, TabPg1);

        txt.LoadString(IDS_TAB_PAGE_2);
        Tab.InsertItem(TabPage2, txt);
        TabPg2.Create(PageDialog::IDD, &Tab);
        CorrectTabPage(TabPage2, TabPg2);

        txt.LoadString(IDS_TAB_PAGE_3);
        Tab.InsertItem(TabPage3, txt);
        TabPg3.Create(PageDialog::IDD, &Tab);
        CorrectTabPage(TabPage3, TabPg3);

        Tab.SetCurFocus(TabPage1);
        TabPg1.ShowWindow(SW_SHOW);
    }

    return TRUE;
}

void TabDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_TAB, Tab);
}

// Implementation

void TabDialog::
CorrectTabPage(TabPageNo tabPageNo, PageDialog &tabPage) const
{
    CRect tabCltRect;
    Tab.GetClientRect(&tabCltRect);

    CRect tabItemRect;
    Tab.GetItemRect(tabPageNo, &tabItemRect);

    CRect pgRt;
    pgRt.left = tabCltRect.left + 4;
    pgRt.top = tabItemRect.Height() + 4;
    pgRt.right = tabCltRect.right - 4;
    pgRt.bottom = tabCltRect.bottom - 4;

    tabPage.MoveWindow(&pgRt);
}


// Message Handlers

void TabDialog::
OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
    TRACE(__FUNCTION__ "\n");

    CONST TabPageNo tabSel = static_cast<TabPageNo>(Tab.GetCurSel());
    switch (tabSel) {
    case TabPage1:
        CorrectTabPage(TabPage1, TabPg1);
        TabPg1.ShowWindow(SW_SHOW);
        TabPg1.SetFocus();
        TabPg2.ShowWindow(SW_HIDE);
        TabPg3.ShowWindow(SW_HIDE);
        break;
    case TabPage2:
        TabPg1.ShowWindow(SW_HIDE);
        CorrectTabPage(TabPage2, TabPg2);
        TabPg2.ShowWindow(SW_SHOW);
        TabPg2.SetFocus();
        TabPg3.ShowWindow(SW_HIDE);
        break;
    case TabPage3:
        TabPg1.ShowWindow(SW_HIDE);
        TabPg2.ShowWindow(SW_HIDE);
        CorrectTabPage(TabPage3, TabPg3);
        TabPg3.ShowWindow(SW_SHOW);
        TabPg3.SetFocus();
        break;
    default:
        AfxAbort();
        break;
    }

    *pResult = 0;
}

}//namespace rrMFC
