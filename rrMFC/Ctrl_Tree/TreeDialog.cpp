/// \copyright The MIT License

#include "stdafx.h"
#include "TreeDialog.h"
#include "ui.rc.h"

namespace rrMFC {

BEGIN_MESSAGE_MAP(TreeDialog, CDialog)
    ON_NOTIFY(NM_CLICK, IDC_TREE, &TreeDialog::OnNMClickTree)
    ON_NOTIFY(NM_DBLCLK, IDC_TREE, &TreeDialog::OnNMClickTree)
    ON_NOTIFY(TVN_KEYDOWN, IDC_TREE, &TreeDialog::OnTvnKeydownTree)

    ON_NOTIFY(TVN_SELCHANGING, IDC_TREE, &TreeDialog::OnTvnSelchangingTree)
    ON_NOTIFY(TVN_SELCHANGED, IDC_TREE, &TreeDialog::OnTvnSelchangedTree)

    ON_NOTIFY(TVN_ITEMCHANGING, IDC_TREE, &TreeDialog::OnTvnItemChangingTree)
    ON_NOTIFY(TVN_ITEMCHANGED, IDC_TREE, &TreeDialog::OnTvnItemChangedTree)
    ON_EN_CHANGE(IDC_FIND_EDIT, &TreeDialog::OnEnChangeFindEdit)
END_MESSAGE_MAP()

// Attributes

const unsigned TreeDialog::IDD {IDD_TREE_DIALOG};

// Overridables

BOOL TreeDialog::
OnInitDialog()
{
    CDialog::OnInitDialog();
    TRACE(__FUNCTION__ "\n");

    CString text;

    CONST HTREEITEM rootTih = TreeControl.InsertItem(TEXT("root"));
    for (INT i = 1; i < 99; ++i) {
        text.Format(TEXT("sub%d"), i);
        TreeControl.InsertItem(text, rootTih);
    }
    CONST HTREEITEM sub99Tih = TreeControl.InsertItem(TEXT("sub99"), rootTih);
    TreeControl.Expand(rootTih, TVE_EXPAND);

    for (INT i = 1; i < 99; ++i) {
        text.Format(TEXT("sub99sub%d"), i);
        TreeControl.InsertItem(text, sub99Tih);
    }
    TreeControl.Expand(sub99Tih, TVE_EXPAND);

    return TRUE;
}

void TreeDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_TREE, TreeControl);
    DDX_Control(pDX, IDC_FIND_EDIT, FindEditControl);
}

// Implementation

void TreeDialog::
SyncChildCheck(HTREEITEM const item)
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

void TreeDialog::
SyncParentCheck(HTREEITEM const item)
{
    ASSERT(NULL != item);
    HTREEITEM const parent = TreeControl.GetParentItem(item);
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

HTREEITEM TreeDialog::
FindMatchedItem(const CString &token) const
{
    HTREEITEM const rootTih = TreeControl.GetRootItem();
    if (!rootTih)
        return NULL;
    return FindMatchedItem(token, rootTih);
}

HTREEITEM TreeDialog::
FindMatchedItem(const CString &token, HTREEITEM const itemTih) const
{
    ASSERT(NULL != itemTih);
    HTREEITEM child = TreeControl.GetChildItem(itemTih);
    while (NULL != child) {
        if (-1 != TreeControl.GetItemText(child).Find(token))
            return child;
        HTREEITEM CONST rv = FindMatchedItem(token, child);
        if (rv)
            return rv;
        child = TreeControl.GetNextItem(child, TVGN_NEXT);
    }
    return NULL;
}

// Message Handlers

void TreeDialog::
OnNMClickTree(NMHDR *pNMHDR, LRESULT *pResult)
{
    TRACE(__FUNCTION__ "\n");

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

void TreeDialog::
OnNMDblclkTree(NMHDR *pNMHDR, LRESULT *pResult)
{
    TRACE(__FUNCTION__ "\n");
    *pResult = 0;
}

void TreeDialog::
OnTvnKeydownTree(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMTVKEYDOWN pTVKeyDown = reinterpret_cast<LPNMTVKEYDOWN>(pNMHDR);
    TRACE(__FUNCTION__ "\n");
    *pResult = 0;
}

void TreeDialog::
OnTvnSelchangingTree(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
    TRACE(__FUNCTION__ "\n");
    *pResult = 0;
}

void TreeDialog::
OnTvnSelchangedTree(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
    TRACE(__FUNCTION__ "\n");
    *pResult = 0;
}

void TreeDialog::
OnTvnItemChangingTree(NMHDR *pNMHDR, LRESULT *pResult)
{
    NMTVITEMCHANGE *pNMTVItemChange = reinterpret_cast<NMTVITEMCHANGE *>(pNMHDR);
    TRACE(__FUNCTION__ "\n");
    *pResult = 0;
}

void TreeDialog::
OnTvnItemChangedTree(NMHDR *pNMHDR, LRESULT *pResult)
{
    NMTVITEMCHANGE *pNMTVItemChange = reinterpret_cast<NMTVITEMCHANGE*>(pNMHDR);
    TRACE(__FUNCTION__ "\n");
    *pResult = 0;
}

void TreeDialog::
OnEnChangeFindEdit()
{
    TRACE(__FUNCTION__ "\n");
    CString text;
    FindEditControl.GetWindowText(text);
    if (text.GetLength()) {
        HTREEITEM CONST item = FindMatchedItem(text);
        if (item) {
            TreeControl.EnsureVisible(item);
            TreeControl.SelectItem(item);
        }
    }
}

}//namespace rrMFC
