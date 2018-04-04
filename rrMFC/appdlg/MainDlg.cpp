/// \copyright The MIT License

#include "stdafx.h"
#include "MainDlg.h"

#include "resource.h"

BEGIN_MESSAGE_MAP(CMainDlg, CDialog)
    ON_BN_CLICKED(IDOK, &CMainDlg::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &CMainDlg::OnBnClickedCancel)
END_MESSAGE_MAP()

CMainDlg::CMainDlg(CWnd *pParent /*=NULL*/)
    : CDialog(IDD_MAIN_DLG, pParent)
{}

void CMainDlg::DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
}

void CMainDlg::OnBnClickedOk()
{
    AfxMessageBox(TEXT("OnBnClickedOk"));
    CDialog::OnOK();
}

void CMainDlg::OnBnClickedCancel()
{
    AfxMessageBox(TEXT("OnBnClickedCancel"));
    CDialog::OnCancel();
}
