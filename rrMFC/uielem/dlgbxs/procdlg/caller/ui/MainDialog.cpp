/// \copyright The MIT License

#include "stdafx.h"
#include "resource.h"
#include "ui/MainDialog.h"

#include "utils/dbgcon.h"

#include "main.h"
#include "ui/HostDialog.h"

IMPLEMENT_DYNCREATE(MainDialog, CDialog)

BEGIN_MESSAGE_MAP(MainDialog, CDialog)
    ON_BN_CLICKED(IDC_BROWSE_BUTTON, &MainDialog::OnBnClickedBrowseButton)
END_MESSAGE_MAP()

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
    DDX_Control(pDX, IDC_PATH_EDIT, PathEdit);
    DbgConPrt(LightYellow, TEXT("MainDialog::DoDataExchange\n"));
}

VOID MainDialog::
OnOK()
{
    DbgConPrt(LightYellow, TEXT("MainDialog::OnOK\n"));

    CString path;
    PathEdit.GetWindowText(path);

    HostDialog hostDlg;
    hostDlg.SetExePath(path);
    hostDlg.DoModal();
}

VOID MainDialog::
OnCancel()
{
    DbgConPrt(LightYellow, TEXT("MainDialog::OnCancel\n"));
    CDialog::OnCancel();
}

#// Message Handlers

VOID MainDialog::
OnBnClickedBrowseButton()
{
    DbgConPrt(LightYellow, TEXT("MainDialog::OnBnClickedBrowseButton\n"));
    CFileDialog fileDlg(
        TRUE, NULL, TEXT("*.exe"), OFN_READONLY | OFN_FILEMUSTEXIST,
        TEXT("Executable File (*.exe)|*.exe|")
        TEXT("All Files (*.*)|*.*||"),
        this);
    if (fileDlg.DoModal() != IDOK)
        return;
    PathEdit.SetWindowText(fileDlg.GetPathName());
    OnOK();
}
