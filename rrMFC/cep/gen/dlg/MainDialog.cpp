/// \copyright The MIT License

#include "stdafx.h"
#include "MainDialog.h"

#include "resource.h"

IMPLEMENT_DYNCREATE(MainDialog, CDialog)

BEGIN_MESSAGE_MAP(MainDialog, CDialog)
    ON_BN_CLICKED(IDOK, &MainDialog::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &MainDialog::OnBnClickedCancel)
END_MESSAGE_MAP()

MainDialog::MainDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD_MAIN_DIALOG, pParent)
{}

VOID MainDialog::DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
}

VOID MainDialog::OnBnClickedOk()
{
    AfxMessageBox(TEXT("OnBnClickedOk"));
    CDialog::OnOK();
}

VOID MainDialog::OnBnClickedCancel()
{
    AfxMessageBox(TEXT("OnBnClickedCancel"));
    CDialog::OnCancel();
}
