/// \copyright The Unlicense

#include "stdafx.h"
#include "ListDialog.h"
#include "ui.rc.h"

namespace rrMFC {

BEGIN_MESSAGE_MAP(ListDialog, CDialog)
    ON_BN_CLICKED(IDC_APPEND_LAST_BUTTON, &ListDialog::OnBnClickedAppendLastButton)
    ON_BN_CLICKED(IDC_DELETE_FIRST_BUTTON, &ListDialog::OnBnClickedDeleteFirstButton)
    ON_NOTIFY(LVN_GETDISPINFO, IDC_LIST, &ListDialog::OnLvnGetdispinfoList)
    ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST, &ListDialog::OnLvnItemchangedList)
    ON_NOTIFY(NM_CLICK, IDC_LIST, &ListDialog::OnNMClickList)
    ON_NOTIFY(NM_DBLCLK, IDC_LIST, &ListDialog::OnNMDblclkList)
    ON_NOTIFY(NM_RCLICK, IDC_LIST, &ListDialog::OnNMRClickList)
    ON_NOTIFY(NM_RDBLCLK, IDC_LIST, &ListDialog::OnNMRDblclkList)
END_MESSAGE_MAP()

// Attributes

const unsigned ListDialog::IDD {IDD_LIST_DIALOG};

// Overridables

void ListDialog::
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

    ListControl.SetExtendedStyle(ListControl.GetExtendedStyle()
                                 | LVS_EX_DOUBLEBUFFER
                                 | LVS_EX_FULLROWSELECT
                                 | LVS_EX_GRIDLINES
                                 | LVS_EX_HEADERDRAGDROP);

    ListControl.SetBkColor(RGB(0x80, 0x80, 0x80));
    ListControl.SetTextColor(RGB(0xFF, 0xFF, 0xFF));
    ListControl.SetTextBkColor(ListControl.GetBkColor());

    ListControl.InsertColumn(Id, TEXT("ID"), LVCFMT_LEFT, 100);
    ListControl.InsertColumn(Name, TEXT("NAME"), LVCFMT_LEFT, 100);
    ListControl.InsertColumn(Alias, TEXT("ALIAS"), LVCFMT_LEFT, 100);

    return TRUE;
}

// Implementation

int ListDialog::
AppendListItem(const DWORD_PTR itemData, const CString &id, const CString &name, const CString &alias)
{
    const int idx = ListControl.GetItemCount();
    InsertListItem(idx, itemData, id, name, alias);
    return idx;
}

void ListDialog::
ClearListSelected()
{
    POSITION pos = ListControl.GetFirstSelectedItemPosition();
    while (pos) {
        int selectedIdx = ListControl.GetNextSelectedItem(pos);
        ListControl.SetItemState(selectedIdx, ~LVIS_SELECTED, LVIS_SELECTED);
    }
}

void ListDialog::
InsertListItem(const int itemIndex, const DWORD_PTR itemData, const CString &id, const CString &name, const CString &alias)
{
    ListControl.InsertItem(itemIndex, TEXT(""));
    ListControl.SetItemData(itemIndex, itemData);
    ListControl.SetItemText(itemIndex, ListColumn::Id, id);
    ListControl.SetItemText(itemIndex, ListColumn::Name, TEXT("say you"));
    ListControl.SetItemText(itemIndex, ListColumn::Alias, TEXT("say me"));
}

void ListDialog::
SelectListItem(const int itemIndex)
{
    if (ListControl.GetItemCount() <= itemIndex)
        return;
    ListControl.SetItemState(itemIndex, LVIS_SELECTED, LVIS_SELECTED);
    ListControl.SetSelectionMark(itemIndex);
    ListControl.EnsureVisible(itemIndex, FALSE);
}

// Message Handlers

// https://docs.microsoft.com/cpp/mfc/reference/clistctrl-class#getitemcount
//
// https://docs.microsoft.com/cpp/mfc/reference/clistctrl-class#insertitem
// https://docs.microsoft.com/cpp/mfc/reference/clistctrl-class#setitemdata
// https://docs.microsoft.com/cpp/mfc/reference/clistctrl-class#setitemtext
//
// https://docs.microsoft.com/cpp/mfc/reference/clistctrl-class#setitemstate
// https://docs.microsoft.com/cpp/mfc/reference/clistctrl-class#setselectionmark
// https://docs.microsoft.com/cpp/mfc/reference/clistctrl-class#ensurevisible
void ListDialog::
OnBnClickedAppendLastButton()
{
    static INT StaticId = 0;
    ++StaticId;

    CString id;
    id.Format(TEXT("%d"), StaticId);

    ListControl.SetRedraw(FALSE);
    {
        const int idx = AppendListItem(StaticId, id, TEXT("say you"), TEXT("say me"));  // index
        ClearListSelected();
        SelectListItem(idx);
    }
    ListControl.SetRedraw(TRUE);
}

// https://docs.microsoft.com/cpp/mfc/reference/clistctrl-class#insertitem
void ListDialog::
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

void ListDialog::
OnLvnGetdispinfoList(NMHDR *pNMHDR, LRESULT *pResult)
{
    NMLVDISPINFO *pDispInfo = reinterpret_cast<NMLVDISPINFO*>(pNMHDR);
    TRACE(__FUNCTION__ "\n");
    *pResult = 0;
}

void ListDialog::
OnLvnItemchangedList(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
    TRACE(__FUNCTION__ "\n");
    *pResult = 0;
}

void ListDialog::
OnNMClickList(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
    TRACE(__FUNCTION__ "\n");
    *pResult = 0;
}

void ListDialog::
OnNMDblclkList(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
    TRACE(__FUNCTION__ "\n");
    *pResult = 0;
}

void ListDialog::
OnNMRClickList(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
    TRACE(__FUNCTION__ "\n");
    *pResult = 0;
}

void ListDialog::
OnNMRDblclkList(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
    TRACE(__FUNCTION__ "\n");
    *pResult = 0;
}

}//namespace rrMFC
