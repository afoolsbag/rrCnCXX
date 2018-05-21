/// \copyright The MIT License

#include "stdafx.h"
#include "MainDialog.h"

#include "rrwindows/dbgcon.h"

IMPLEMENT_DYNCREATE(MainDialog, CDialog)

BEGIN_MESSAGE_MAP(MainDialog, CDialog)
    ON_NOTIFY(NM_CLICK, IDC_TREE, &MainDialog::OnNMClickTree)
    ON_NOTIFY(NM_DBLCLK, IDC_TREE, &MainDialog::OnNMClickTree)
    ON_NOTIFY(TVN_KEYDOWN, IDC_TREE, &MainDialog::OnTvnKeydownTree)

    ON_NOTIFY(TVN_SELCHANGING, IDC_TREE, &MainDialog::OnTvnSelchangingTree)
    ON_NOTIFY(TVN_SELCHANGED, IDC_TREE, &MainDialog::OnTvnSelchangedTree)

    ON_NOTIFY(TVN_ITEMCHANGING, IDC_TREE, &MainDialog::OnTvnItemChangingTree)
    ON_NOTIFY(TVN_ITEMCHANGED, IDC_TREE, &MainDialog::OnTvnItemChangedTree)
END_MESSAGE_MAP()

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

    CONST HTREEITEM rootTih = TreeControl.InsertItem(TEXT("root"));
    CONST HTREEITEM sub1Tih = TreeControl.InsertItem(TEXT("sub1"), rootTih);
    CONST HTREEITEM sub2Tih = TreeControl.InsertItem(TEXT("sub2"), rootTih);
    CONST HTREEITEM sub3Tih = TreeControl.InsertItem(TEXT("sub3"), rootTih);
    TreeControl.Expand(rootTih, TVE_EXPAND);

    CONST HTREEITEM sub2sub1Tih = TreeControl.InsertItem(TEXT("sub2sub1"), sub2Tih);

    return TRUE;
}

BOOL MainDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConPrtMethWndMsg(Yellow);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID MainDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_TREE, TreeControl);
}

#// Implementation

VOID MainDialog::
SyncChildCheck(HTREEITEM CONST item)
{
    ASSERT(NULL != item);
    CONST BOOL check = TreeControl.GetCheck(item);
    HTREEITEM child = TreeControl.GetChildItem(item);
    while (NULL != child) {
        TreeControl.SetCheck(child, check);
        SyncChildCheck(child);
        child = TreeControl.GetNextItem(child, TVGN_NEXT);
    }
}

VOID MainDialog::
SyncParentCheck(HTREEITEM CONST item)
{
    ASSERT(NULL != item);
    HTREEITEM CONST parent = TreeControl.GetParentItem(item);
    if (NULL == parent)
        return;
    HTREEITEM sibling = TreeControl.GetChildItem(parent);
    while (NULL != sibling) {
        if (FALSE == TreeControl.GetCheck(sibling)) {
            TreeControl.SetCheck(parent, FALSE);
            SyncParentCheck(parent);
            return;
        }
        sibling = TreeControl.GetNextItem(sibling, TVGN_NEXT);
    }
    TreeControl.SetCheck(parent, TRUE);
    SyncParentCheck(parent);
}

#// Message Handlers

VOID MainDialog::
OnNMClickTree(NMHDR *pNMHDR, LRESULT *pResult)
{
    DbgConPrtMeth(Yellow);

    CPoint pt;
    GetCursorPos(&pt);
    TreeControl.ScreenToClient(&pt);

    UINT flags = 0u;
    HTREEITEM item = TreeControl.HitTest(pt, &flags);
    if (NULL == item)
        return;
    TreeControl.SelectItem(item);

    if (TVHT_ONITEMSTATEICON == flags) {
        BOOL temp = TreeControl.GetCheck(item);

        TreeControl.SetCheck(item, !temp);
        SyncChildCheck(item);
        SyncParentCheck(item);
        TreeControl.SetCheck(item, temp);
    }

    *pResult = 0;
}

VOID MainDialog::
OnNMDblclkTree(NMHDR *pNMHDR, LRESULT *pResult)
{
    DbgConPrtMeth(Yellow);
    *pResult = 0;
}

VOID MainDialog::
OnTvnKeydownTree(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMTVKEYDOWN pTVKeyDown = reinterpret_cast<LPNMTVKEYDOWN>(pNMHDR);
    DbgConPrtMeth(Yellow);
    *pResult = 0;
}

VOID MainDialog::
OnTvnSelchangingTree(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
    DbgConPrtMeth(Yellow);
    *pResult = 0;
}

VOID MainDialog::
OnTvnSelchangedTree(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
    DbgConPrtMeth(Yellow);
    *pResult = 0;
}

VOID MainDialog::
OnTvnItemChangingTree(NMHDR *pNMHDR, LRESULT *pResult)
{
    NMTVITEMCHANGE *pNMTVItemChange = reinterpret_cast<NMTVITEMCHANGE *>(pNMHDR);
    DbgConPrtMeth(Yellow);
    *pResult = 0;
}

VOID MainDialog::
OnTvnItemChangedTree(NMHDR *pNMHDR, LRESULT *pResult)
{
    NMTVITEMCHANGE *pNMTVItemChange = reinterpret_cast<NMTVITEMCHANGE*>(pNMHDR);
    DbgConPrtMeth(Yellow);
    *pResult = 0;
}
