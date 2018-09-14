/// \copyright The MIT License

#include "stdafx.h"
#include "TreeDialog.h"
#include "TreeDialog.rc.h"

#include "rrwindows/rrwindows.h"

namespace rrMFC {
namespace Test {

const UINT TreeDialog::IDD {IDD_TREE_DIALOG};

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

#// Constructors

TreeDialog::
TreeDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    DcMeth();
}

TreeDialog::
~TreeDialog()
{
    DcMeth();
}

#// Overridables

BOOL TreeDialog::
OnInitDialog()
{
    CDialog::OnInitDialog();
    DcMeth();

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

BOOL TreeDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DcWndMsg();
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID TreeDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_TREE, TreeControl);
    DDX_Control(pDX, IDC_FIND_EDIT, FindEditControl);
}

#// Implementation

VOID TreeDialog::
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

VOID TreeDialog::
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

HTREEITEM TreeDialog::
FindMatchedItem(CONST CString &token) CONST
{
    HTREEITEM CONST rootTih = TreeControl.GetRootItem();
    if (!rootTih)
        return NULL;
    return FindMatchedItem(token, rootTih);
}

HTREEITEM TreeDialog::
FindMatchedItem(CONST CString &token, HTREEITEM CONST itemTih) CONST
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

#// Message Handlers

VOID TreeDialog::
OnNMClickTree(NMHDR *pNMHDR, LRESULT *pResult)
{
    DcMeth();

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

VOID TreeDialog::
OnNMDblclkTree(NMHDR *pNMHDR, LRESULT *pResult)
{
    DcMeth();
    *pResult = 0;
}

VOID TreeDialog::
OnTvnKeydownTree(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMTVKEYDOWN pTVKeyDown = reinterpret_cast<LPNMTVKEYDOWN>(pNMHDR);
    DcMeth();
    *pResult = 0;
}

VOID TreeDialog::
OnTvnSelchangingTree(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
    DcMeth();
    *pResult = 0;
}

VOID TreeDialog::
OnTvnSelchangedTree(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
    DcMeth();
    *pResult = 0;
}

VOID TreeDialog::
OnTvnItemChangingTree(NMHDR *pNMHDR, LRESULT *pResult)
{
    NMTVITEMCHANGE *pNMTVItemChange = reinterpret_cast<NMTVITEMCHANGE *>(pNMHDR);
    DcMeth();
    *pResult = 0;
}

VOID TreeDialog::
OnTvnItemChangedTree(NMHDR *pNMHDR, LRESULT *pResult)
{
    NMTVITEMCHANGE *pNMTVItemChange = reinterpret_cast<NMTVITEMCHANGE*>(pNMHDR);
    DcMeth();
    *pResult = 0;
}

VOID TreeDialog::
OnEnChangeFindEdit()
{
    DcMeth();
    CString text;
    FindEditControl.GetWindowText(text);
    if (text.GetLength()) {
        HTREEITEM CONST item = FindMatchedItem(text);
        if (item) {
            DcKPrint(White, TEXT("Found %s matched %s.\n"), static_cast<LPCTSTR>(TreeControl.GetItemText(item)), static_cast<LPCTSTR>(text));
            TreeControl.EnsureVisible(item);
            TreeControl.SelectItem(item);
        }
    }
}

}//namespace Test
}//namespace rrMFC
