/// \copyright The MIT License

#include "stdafx.h"
#include "resource.h"
#include "MainDialog.h"

#include "utils/dbgcon.inl"

IMPLEMENT_DYNCREATE(MainDialog, CDialog)

BEGIN_MESSAGE_MAP(MainDialog, CDialog)
    ON_BN_CLICKED(IDC_APPEND_LAST_BUTTON, &MainDialog::OnBnClickedAppendLastButton)
    ON_BN_CLICKED(IDC_DELETE_FIRST_BUTTON, &MainDialog::OnBnClickedDeleteFirstButton)
    ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST, &MainDialog::OnLvnItemchangedList)
    ON_NOTIFY(NM_CLICK, IDC_LIST, &MainDialog::OnNMClickList)
    ON_NOTIFY(NM_DBLCLK, IDC_LIST, &MainDialog::OnNMDblclkList)
    ON_NOTIFY(NM_RCLICK, IDC_LIST, &MainDialog::OnNMRClickList)
    ON_NOTIFY(NM_RDBLCLK, IDC_LIST, &MainDialog::OnNMRDblclkList)
END_MESSAGE_MAP()

#// Constructors

MainDialog::
MainDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{}

#// Overridables

VOID MainDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST, ListControl);
}

// https://docs.microsoft.com/cpp/mfc/reference/clistctrl-class#setextendedstyle
// https://docs.microsoft.com/cpp/mfc/reference/clistctrl-class#getextendedstyle
// https://docs.microsoft.com/cpp/mfc/reference/clistctrl-class#insertcolumn
BOOL MainDialog::
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

BOOL MainDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConPrtWndMsg(Yellow, TEXT("MainDialog::OnWndMsg"), message, wParam, lParam, pResult);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

#// Implementation

INT MainDialog::
AppendListItem(const DWORD_PTR itemData, const CString &id, const CString &name, const CString &alias)
{
    CONST INT idx = ListControl.GetItemCount();
    InsertListItem(idx, itemData, id, name, alias);
    return idx;
}

VOID MainDialog::
ClearListSelected()
{
    POSITION pos = ListControl.GetFirstSelectedItemPosition();
    while (pos) {
        INT selectedIdx = ListControl.GetNextSelectedItem(pos);
        ListControl.SetItemState(selectedIdx, ~LVIS_SELECTED, LVIS_SELECTED);
    }
}

VOID MainDialog::
InsertListItem(CONST INT itemIndex, CONST DWORD_PTR itemData, CONST CString &id, CONST CString &name, CONST CString &alias)
{
    ListControl.InsertItem(itemIndex, TEXT(""));
    ListControl.SetItemData(itemIndex, itemData);
    ListControl.SetItemText(itemIndex, ListColumn::Id, id);
    ListControl.SetItemText(itemIndex, ListColumn::Name, TEXT("say you"));
    ListControl.SetItemText(itemIndex, ListColumn::Alias, TEXT("say me"));
}

VOID MainDialog::
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
VOID MainDialog::
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
VOID MainDialog::
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

VOID MainDialog::
OnLvnItemchangedList(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
    DbgConPrt(LightYellow, TEXT("LVN_ITEMCHANGED: item(%d)subitem(%d), state(%u->%u).\n"),
              pNMLV->iItem, pNMLV->iSubItem, pNMLV->uOldState, pNMLV->uNewState);
    *pResult = 0;
}

VOID MainDialog::
OnNMClickList(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
    DbgConPrt(LightYellow, TEXT("NM_CLICK: item(%d)subitem(%d), point(%ld,%ld).\n"),
              pNMItemActivate->iItem, pNMItemActivate->iSubItem, pNMItemActivate->ptAction.x, pNMItemActivate->ptAction.y);
    *pResult = 0;
}

VOID MainDialog::
OnNMDblclkList(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
    DbgConPrt(LightYellow, TEXT("NM_DBLCLK: item(%d)subitem(%d), point(%ld,%ld).\n"),
              pNMItemActivate->iItem, pNMItemActivate->iSubItem, pNMItemActivate->ptAction.x, pNMItemActivate->ptAction.y);
    *pResult = 0;
}

VOID MainDialog::
OnNMRClickList(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
    DbgConPrt(LightYellow, TEXT("NM_RCLICK: item(%d)subitem(%d), point(%ld,%ld).\n"),
              pNMItemActivate->iItem, pNMItemActivate->iSubItem, pNMItemActivate->ptAction.x, pNMItemActivate->ptAction.y);
    *pResult = 0;
}

VOID MainDialog::
OnNMRDblclkList(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
    DbgConPrt(LightYellow, TEXT("NM_RDBLCLK: item(%d)subitem(%d), point(%ld,%ld).\n"),
              pNMItemActivate->iItem, pNMItemActivate->iSubItem, pNMItemActivate->ptAction.x, pNMItemActivate->ptAction.y);
    *pResult = 0;
}