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
    ON_REGISTERED_MESSAGE(RM_RRMFC_PROCESS_DIALOG_CALLEE_CREATING, &MainDialog::OnRrmfcProcessDialogCalleeCreating)
    ON_REGISTERED_MESSAGE(RM_RRMFC_PROCESS_DIALOG_CALLEE_DESTROYING, &MainDialog::OnRrmfcProcessDialogCalleeDestroying)
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
    TCHAR args[10];
    _stprintf_s(args, _countof(args), TEXT(" %08p"), GetSafeHwnd());
    STARTUPINFO suInfo = {};
    suInfo.cb = sizeof(suInfo);
    PROCESS_INFORMATION procInfo = {};

    if (!CreateProcess(path, args, NULL, NULL, FALSE, 0, NULL, NULL, &suInfo, &procInfo)) {
        DbgConPrt(White, TEXT("CreateProcess failed: %lu.\n"), GetLastError());
        return;
    }

    CloseHandle(procInfo.hProcess);
    CloseHandle(procInfo.hThread);
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
}

LRESULT MainDialog::
OnRrmfcProcessDialogCalleeCreating(WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(wParam);
    DbgConPrt(LightYellow, TEXT("MainDialog::OnRrmfcProcessDialogCalleeCreating\n"));

    HWND hwnd = reinterpret_cast<HWND>(lParam);
    DbgConPrt(White, TEXT("Receive message paramater: %p\n"), hwnd);
    HostDialog hostDlg(hwnd, this);
    hostDlg.DoModal();

    return NULL;
}

LRESULT MainDialog::
OnRrmfcProcessDialogCalleeDestroying(WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(wParam);
    DbgConPrt(LightYellow, TEXT("MainDialog::OnRrmfcProcessDialogCalleeDestroying\n"));
    DbgConPrt(White, TEXT("Receive message paramater: %p\n"), reinterpret_cast<HWND>(lParam));
    return NULL;
}
