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

void MainDialog::DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
}

void MainDialog::OnBnClickedOk()
{
    AfxMessageBox(TEXT("OnBnClickedOk"));
    CDialog::OnOK();
}

void MainDialog::OnBnClickedCancel()
{
    AfxMessageBox(TEXT("OnBnClickedCancel"));
    CDialog::OnCancel();
}
