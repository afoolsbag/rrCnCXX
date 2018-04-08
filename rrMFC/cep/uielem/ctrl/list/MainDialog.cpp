/// \copyright The MIT License

#include "stdafx.h"
#include "MainDialog.h"

#include "resource.h"

IMPLEMENT_DYNCREATE(MainDialog, CDialog)

BEGIN_MESSAGE_MAP(MainDialog, CDialog)
    ON_BN_CLICKED(IDC_INSERT_ONE_BUTTON, &MainDialog::OnBnClickedInsertOneButton)
END_MESSAGE_MAP()

MainDialog::MainDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD_MAIN_DIALOG, pParent)
{}

// https://docs.microsoft.com/cpp/mfc/reference/clistctrl-class#insertcolumn
// https://docs.microsoft.com/cpp/mfc/reference/clistctrl-class#insertitem
BOOL MainDialog::OnInitDialog()
{
    CDialog::OnInitDialog();

    {
        ListCtrl.InsertColumn(ListColumn::Id, TEXT("ID"), LVCFMT_LEFT, 100);
        ListCtrl.InsertColumn(ListColumn::Name, TEXT("NAME"), LVCFMT_LEFT, 100);
        ListCtrl.InsertColumn(ListColumn::Alias, TEXT("ALIAS"), LVCFMT_LEFT, 100);
    }

    return TRUE;
}

void MainDialog::DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST, ListCtrl);
}

void MainDialog::OnBnClickedInsertOneButton()
{
    static INT StaticId = 0;
    ++StaticId;

    CString id;
    id.Format(TEXT("%d"), StaticId);

    CONST INT idx = ListCtrl.GetItemCount();  // index

    ListCtrl.SetRedraw(FALSE);
    ListCtrl.InsertItem(idx, TEXT(""));
    ListCtrl.SetItemData(idx, StaticId);
    ListCtrl.SetItemText(idx, ListColumn::Id, id);
    ListCtrl.SetItemText(idx, ListColumn::Name, TEXT("say you"));
    ListCtrl.SetItemText(idx, ListColumn::Alias, TEXT("say me"));
    ListCtrl.SetRedraw(TRUE);
}
