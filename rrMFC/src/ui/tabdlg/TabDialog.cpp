/// \copyright The Unlicense

#include "stdafx.h"
#include "TabDialog.h"
#include "TabDialog.rc.h"

#include "rrwindows/rrwindows.h"

namespace rrMFC {

const UINT TabDialog::IDD {IDD_TAB_DIALOG};

BEGIN_MESSAGE_MAP(TabDialog, CDialog)
    ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &TabDialog::OnTcnSelchangeTab)
END_MESSAGE_MAP()

#// Constructors

TabDialog::
TabDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    DcMeth();
}

TabDialog::
~TabDialog()
{
    DcMeth();
}

#// Overridables

BOOL TabDialog::
OnInitDialog()
{
    CDialog::OnInitDialog();

    {
        CString txt;
        DpWarnExpectTrue(txt.LoadString(IDS_TAB_PAGE_1));
        Tab.InsertItem(TAB_PAGE_1, txt);
        TabPg1.Create(PageDialog::IDD, &Tab);
        CorrectTabPage(TAB_PAGE_1, TabPg1);

        DpWarnExpectTrue(txt.LoadString(IDS_TAB_PAGE_2));
        Tab.InsertItem(TAB_PAGE_2, txt);
        TabPg2.Create(PageDialog::IDD, &Tab);
        CorrectTabPage(TAB_PAGE_2, TabPg2);

        DpWarnExpectTrue(txt.LoadString(IDS_TAB_PAGE_3));
        Tab.InsertItem(TAB_PAGE_3, txt);
        TabPg3.Create(PageDialog::IDD, &Tab);
        CorrectTabPage(TAB_PAGE_3, TabPg3);

        Tab.SetCurFocus(TAB_PAGE_1);
        TabPg1.ShowWindow(SW_SHOW);
    }

    return TRUE;
}

VOID TabDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_TAB, Tab);
}

#// Implementation

VOID TabDialog::
CorrectTabPage(TabPageNo tabPageNo, PageDialog &tabPage) CONST
{
    CRect tabCltRect;
    Tab.GetClientRect(&tabCltRect);

    CRect tabItemRect;
    DpWarnExpectTrue(Tab.GetItemRect(tabPageNo, &tabItemRect));

    CRect pgRt;
    pgRt.left = tabCltRect.left + 4;
    pgRt.top = tabItemRect.Height() + 4;
    pgRt.right = tabCltRect.right - 4;
    pgRt.bottom = tabCltRect.bottom - 4;

    tabPage.MoveWindow(&pgRt);
}


#// Message Handlers

VOID TabDialog::
OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
    DcMeth();

    CONST TabPageNo tabSel = static_cast<TabPageNo>(Tab.GetCurSel());
    switch (tabSel) {
    case TAB_PAGE_1:
        CorrectTabPage(TAB_PAGE_1, TabPg1);
        TabPg1.ShowWindow(SW_SHOW);
        TabPg1.SetFocus();
        TabPg2.ShowWindow(SW_HIDE);
        TabPg3.ShowWindow(SW_HIDE);
        break;
    case TAB_PAGE_2:
        TabPg1.ShowWindow(SW_HIDE);
        CorrectTabPage(TAB_PAGE_2, TabPg2);
        TabPg2.ShowWindow(SW_SHOW);
        TabPg2.SetFocus();
        TabPg3.ShowWindow(SW_HIDE);
        break;
    case TAB_PAGE_3:
        TabPg1.ShowWindow(SW_HIDE);
        TabPg2.ShowWindow(SW_HIDE);
        CorrectTabPage(TAB_PAGE_3, TabPg3);
        TabPg3.ShowWindow(SW_SHOW);
        TabPg3.SetFocus();
        break;
    default:
        DpErrorUSR(tabSel);
        break;
    }

    *pResult = 0;
}

}//namespace rrMFC
