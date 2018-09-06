/// \copyright The Unlicense

#include "stdafx.h"
#include "ListDialog.h"
#include "ListDialog.rc.h"

#include "rrwindows/rrwindows.h"

namespace rrMFC {

const UINT ListDialog::IDD {IDD_LIST_DIALOG};

BEGIN_MESSAGE_MAP(ListDialog, CDialog)
    ON_BN_CLICKED(IDC_APPEND_LAST_BUTTON, &ListDialog::OnBnClickedAppendLastButton)
    ON_BN_CLICKED(IDC_DELETE_FIRST_BUTTON, &ListDialog::OnBnClickedDeleteFirstButton)
    ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST, &ListDialog::OnLvnItemchangedList)
    ON_NOTIFY(NM_CLICK, IDC_LIST, &ListDialog::OnNMClickList)
    ON_NOTIFY(NM_DBLCLK, IDC_LIST, &ListDialog::OnNMDblclkList)
    ON_NOTIFY(NM_RCLICK, IDC_LIST, &ListDialog::OnNMRClickList)
    ON_NOTIFY(NM_RDBLCLK, IDC_LIST, &ListDialog::OnNMRDblclkList)
END_MESSAGE_MAP()

#// Constructors

ListDialog::
ListDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{}

#// Overridables

VOID ListDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST, ListControl);
}

// https://docs.microsoft.com/cpp/mfc/reference/clistctrl-class#setextendedstyle
// https://docs.microsoft.com/cpp/mfc/reference/clistctrl-class#getextendedstyle
// https://docs.microsoft.com/cpp/mfc/reference/clistctrl-class#insertcolumn
BOOL ListDialog::
OnInitDialog()
{
    CDialog::OnInitDialog();

    {
        ListControl.SetExtendedStyle(ListControl.GetExtendedStyle()
                                     | LVS_EX_DOUBLEBUFFER
                                     | LVS_EX_FULLROWSELECT
                                     | LVS_EX_GRIDLINES
                                     | LVS_EX_HEADERDRAGDROP);

        ListControl.InsertColumn(ListColumn::Id, TEXT("ID"), LVCFMT_LEFT, 100);
        ListControl.InsertColumn(ListColumn::Name, TEXT("NAME"), LVCFMT_LEFT, 100);
        ListControl.InsertColumn(ListColumn::Alias, TEXT("ALIAS"), LVCFMT_LEFT, 100);
    }

    return TRUE;
}

BOOL ListDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DcWndMsg();
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

#// Implementation

INT ListDialog::
AppendListItem(const DWORD_PTR itemData, const CString &id, const CString &name, const CString &alias)
{
    CONST INT idx = ListControl.GetItemCount();
    InsertListItem(idx, itemData, id, name, alias);
    return idx;
}

VOID ListDialog::
ClearListSelected()
{
    POSITION pos = ListControl.GetFirstSelectedItemPosition();
    while (pos) {
        INT selectedIdx = ListControl.GetNextSelectedItem(pos);
        ListControl.SetItemState(selectedIdx, ~LVIS_SELECTED, LVIS_SELECTED);
    }
}

VOID ListDialog::
InsertListItem(CONST INT itemIndex, CONST DWORD_PTR itemData, CONST CString &id, CONST CString &name, CONST CString &alias)
{
    ListControl.InsertItem(itemIndex, TEXT(""));
    ListControl.SetItemData(itemIndex, itemData);
    ListControl.SetItemText(itemIndex, ListColumn::Id, id);
    ListControl.SetItemText(itemIndex, ListColumn::Name, TEXT("say you"));
    ListControl.SetItemText(itemIndex, ListColumn::Alias, TEXT("say me"));
}

VOID ListDialog::
SelectListItem(CONST INT itemIndex)
{
    if (ListControl.GetItemCount() <= itemIndex)
        return;
    ListControl.SetItemState(itemIndex, LVIS_SELECTED, LVIS_SELECTED);
    ListControl.SetSelectionMark(itemIndex);
    ListControl.EnsureVisible(itemIndex, FALSE);
}

#// Message Handlers

// https://docs.microsoft.com/cpp/mfc/reference/clistctrl-class#getitemcount
//
// https://docs.microsoft.com/cpp/mfc/reference/clistctrl-class#insertitem
// https://docs.microsoft.com/cpp/mfc/reference/clistctrl-class#setitemdata
// https://docs.microsoft.com/cpp/mfc/reference/clistctrl-class#setitemtext
//
// https://docs.microsoft.com/cpp/mfc/reference/clistctrl-class#setitemstate
// https://docs.microsoft.com/cpp/mfc/reference/clistctrl-class#setselectionmark
// https://docs.microsoft.com/cpp/mfc/reference/clistctrl-class#ensurevisible
VOID ListDialog::
OnBnClickedAppendLastButton()
{
    static INT StaticId = 0;
    ++StaticId;

    CString id;
    id.Format(TEXT("%d"), StaticId);

    ListControl.SetRedraw(FALSE);
    {
        CONST INT idx = AppendListItem(StaticId, id, TEXT("say you"), TEXT("say me"));  // index
        ClearListSelected();
        SelectListItem(idx);
    }
    ListControl.SetRedraw(TRUE);
}

// https://docs.microsoft.com/cpp/mfc/reference/clistctrl-class#insertitem
VOID ListDialog::
OnBnClickedDeleteFirstButton()
{
    if (!ListControl.GetItemCount())
        return;

    ListControl.SetRedraw(FALSE);
    {
        ListControl.DeleteItem(0);
        ClearListSelected();
        SelectListItem(0);
    }
    ListControl.SetRedraw(TRUE);
}

VOID ListDialog::
OnLvnItemchangedList(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
    DcKPrint(LightYellow, TEXT("LVN_ITEMCHANGED: item(%d)subitem(%d), state(%u->%u).\n"),
             pNMLV->iItem, pNMLV->iSubItem, pNMLV->uOldState, pNMLV->uNewState);
    *pResult = 0;
}

VOID ListDialog::
OnNMClickList(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
    DcKPrint(LightYellow, TEXT("NM_CLICK: item(%d)subitem(%d), point(%ld,%ld).\n"),
             pNMItemActivate->iItem, pNMItemActivate->iSubItem, pNMItemActivate->ptAction.x, pNMItemActivate->ptAction.y);
    *pResult = 0;
}

VOID ListDialog::
OnNMDblclkList(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
    DcKPrint(LightYellow, TEXT("NM_DBLCLK: item(%d)subitem(%d), point(%ld,%ld).\n"),
             pNMItemActivate->iItem, pNMItemActivate->iSubItem, pNMItemActivate->ptAction.x, pNMItemActivate->ptAction.y);
    *pResult = 0;
}

VOID ListDialog::
OnNMRClickList(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
    DcKPrint(LightYellow, TEXT("NM_RCLICK: item(%d)subitem(%d), point(%ld,%ld).\n"),
             pNMItemActivate->iItem, pNMItemActivate->iSubItem, pNMItemActivate->ptAction.x, pNMItemActivate->ptAction.y);
    *pResult = 0;
}

VOID ListDialog::
OnNMRDblclkList(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
    DcKPrint(LightYellow, TEXT("NM_RDBLCLK: item(%d)subitem(%d), point(%ld,%ld).\n"),
             pNMItemActivate->iItem, pNMItemActivate->iSubItem, pNMItemActivate->ptAction.x, pNMItemActivate->ptAction.y);
    *pResult = 0;
}

}//namespace rrMFC
