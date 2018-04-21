/// \copyright The MIT License

#include "stdafx.h"
#include "resource.h"
#include "MainDialog.h"

#include "utils/dbgcon.h"

IMPLEMENT_DYNCREATE(MainDialog, CDialog)

//BEGIN_MESSAGE_MAP(MainDialog, CDialog)
//END_MESSAGE_MAP()

#// Constructors

MainDialog::
MainDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    DbgConPrt(LightYellow, TEXT("MainDialog::Constructor\n"));
}

#// Overridables

MainDialog::
~MainDialog()
{
    DbgConPrt(LightYellow, TEXT("MainDialog::Destructor\n"));
}

BOOL MainDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConPrtWndMsg(Yellow, TEXT("MainDialog::OnWndMsg"), message, wParam, lParam, pResult);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID MainDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_TREE, TreeControl);
}

BOOL MainDialog::
OnInitDialog()
{
    CDialog::OnInitDialog();

    CONST HTREEITEM rootTih = TreeControl.InsertItem(TEXT("root"));
    CONST HTREEITEM sub1Tih = TreeControl.InsertItem(TEXT("sub1"), rootTih);
    CONST HTREEITEM sub2Tih = TreeControl.InsertItem(TEXT("sub2"), rootTih);
    CONST HTREEITEM sub3Tih = TreeControl.InsertItem(TEXT("sub3"), rootTih);
    TreeControl.Expand(rootTih, TVE_EXPAND);

    CONST HTREEITEM sub2sub1Tih = TreeControl.InsertItem(TEXT("sub2sub1"), sub2Tih);

    return TRUE;
}

#// Implementation

#// Message Handlers
