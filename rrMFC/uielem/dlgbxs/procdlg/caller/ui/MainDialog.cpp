/// \copyright The MIT License

#include "stdafx.h"
#include "MainDialog.h"

#include "utils/dbgcon.h"

#include "HostDialog.h"

IMPLEMENT_DYNCREATE(MainDialog, CDialog)

BEGIN_MESSAGE_MAP(MainDialog, CDialog)
    ON_BN_CLICKED(IDC_BROWSE_BUTTON, &MainDialog::OnBnClickedBrowseButton)
END_MESSAGE_MAP()

#// Constructors

MainDialog::
MainDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    DbgConPrt(Yellow, TEXT("MainDialog"));
    DbgConPrt(LightYellow, TEXT("Constructor\n"));
}

MainDialog::
~MainDialog()
{
    DbgConPrt(Yellow, TEXT("MainDialog"));
    DbgConPrt(LightYellow, TEXT("Destructor\n"));
}

#// Overridables

BOOL MainDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConPrt(Yellow, TEXT("MainDialog"));
    DbgConPrtWndMsg(Yellow, TEXT("OnWndMsg"), message, wParam, lParam, pResult);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID MainDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DbgConPrt(Yellow, TEXT("MainDialog"));
    DbgConPrt(LightYellow, TEXT("DoDataExchange\n"));

    DDX_Control(pDX, IDC_PATH_EDIT, PathEdit);
    DDX_Control(pDX, IDC_BROWSE_BUTTON, BrowseButton);
    DDX_Control(pDX, IDOK, OKButton);
    DDX_Control(pDX, IDCANCEL, CancelButton);
}

VOID MainDialog::
OnOK()
{
    DbgConPrt(Yellow, TEXT("MainDialog"));
    DbgConPrt(LightYellow, TEXT("OnOK\n"));

    CString path;
    PathEdit.GetWindowText(path);

    HostDialog hostDlg;
    hostDlg.SetExePath(path);
    hostDlg.DoModal();
}

VOID MainDialog::
OnCancel()
{
    DbgConPrt(Yellow, TEXT("MainDialog"));
    DbgConPrt(LightYellow, TEXT("OnCancel\n"));

    CDialog::OnCancel();
}

#// Message Handlers

VOID MainDialog::
OnBnClickedBrowseButton()
{
    DbgConPrt(Yellow, TEXT("MainDialog"));
    DbgConPrt(LightYellow, TEXT("OnBnClickedBrowseButton\n"));

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
