/// \copyright The MIT License

#include "stdafx.h"
#include "MainDialog.h"

#include "rrwindows/dbgcon.h"

#include "HostDialog.h"
#include <conio.h>

IMPLEMENT_DYNCREATE(MainDialog, CDialog)

BEGIN_MESSAGE_MAP(MainDialog, CDialog)
    ON_BN_CLICKED(IDC_BROWSE_BUTTON, &MainDialog::OnBnClickedBrowseButton)
END_MESSAGE_MAP()

#// Constructors

MainDialog::
MainDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    DbgConPrtMeth(Yellow);
}

MainDialog::
~MainDialog()
{
    DbgConPrtMeth(Yellow);
}

#// Overridables

BOOL MainDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConPrtMethWndMsg(Yellow);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID MainDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DbgConPrtMeth(Yellow);
    DDX_Control(pDX, IDC_PATH_EDIT, PathEdit);
    DDX_Control(pDX, IDC_BROWSE_BUTTON, BrowseButton);
    DDX_Control(pDX, IDOK, OKButton);
    DDX_Control(pDX, IDCANCEL, CancelButton);
}

VOID MainDialog::
OnOK()
{
    DbgConPrtMeth(Yellow);

    CString path;
    PathEdit.GetWindowText(path);

    HostDialog hostDlg;
    hostDlg.SetExePath(path);
    hostDlg.DoModal();
}

VOID MainDialog::
OnCancel()
{
    DbgConPrtMeth(Yellow);
    CDialog::OnCancel();
}

#// Message Handlers

VOID MainDialog::
OnBnClickedBrowseButton()
{
    DbgConPrtMeth(Yellow);

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
