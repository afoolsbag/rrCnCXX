/// \copyright The MIT License

#include "stdafx.h"
#include "resource.h"
#include "HostDialog.h"

#include "utils/dbgcon.h"

#include "main.h"

IMPLEMENT_DYNCREATE(HostDialog, CDialog)

BEGIN_MESSAGE_MAP(HostDialog, CDialog)
    ON_WM_CREATE()
    ON_WM_DESTROY()

    ON_REGISTERED_MESSAGE(RM_RRMFC_PROCESS_DIALOG_CALLEE_CREATING, &HostDialog::OnRrmfcProcessDialogCalleeCreating)
    ON_REGISTERED_MESSAGE(RM_RRMFC_PROCESS_DIALOG_CALLEE_DESTROYING, &HostDialog::OnRrmfcProcessDialogCalleeDestroying)
END_MESSAGE_MAP()

#// Constructors

HostDialog::
HostDialog(HWND hwndCallee /*=NULL*/, CWnd *pParent /*=NULL*/)
    : CalleeHwnd(hwndCallee), CDialog(IDD, pParent)
{
    DbgConPrt(LightGreen, TEXT("HostDialog::Constructor\n"));
}

#// Overridables

HostDialog::
~HostDialog()
{
    DbgConPrt(LightGreen, TEXT("HostDialog::Destructor\n"));
}

BOOL HostDialog::
OnInitDialog()
{
    CDialog::OnInitDialog();
    DbgConPrt(LightYellow, TEXT("HostDialog::OnInitDialog\n"));

    SetWindowLong(CalleeHwnd, GWL_STYLE, GetWindowLong(CalleeHwnd, GWL_STYLE)
                  & ~WS_CAPTION);
    SetWindowLong(CalleeHwnd, GWL_EXSTYLE, GetWindowLong(CalleeHwnd, GWL_EXSTYLE)
                  & ~WS_EX_DLGMODALFRAME
                  & ~WS_EX_WINDOWEDGE
                  & ~WS_EX_CLIENTEDGE);

    TCHAR calleeTitle[MAX_PATH] = {0};
    ::GetWindowText(CalleeHwnd, calleeTitle, MAX_PATH);
    SetWindowText(calleeTitle);

    CRect hostRect;
    GetWindowRect(hostRect);
    CRect calleeRect;
    ::GetWindowRect(CalleeHwnd, &calleeRect);

    //MoveWindow(hostRect.left, hostRect.right, calleeRect.Width(), calleeRect.Height());
    ::SetWindowPos(CalleeHwnd, NULL, hostRect.left, hostRect.top,
                   calleeRect.Width(), calleeRect.Height(), SWP_HIDEWINDOW | SWP_FRAMECHANGED);

    ::ShowWindow(CalleeHwnd, SW_NORMAL);
    ShowWindow(SW_NORMAL);

    SetFocus();

    return TRUE;
}

VOID HostDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DbgConPrt(LightGreen, TEXT("HostDialog::DoDataExchange\n"));
}

#// Message Handlers

INT HostDialog::
OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CDialog::OnCreate(lpCreateStruct) == -1)
        return -1;
    DbgConPrt(LightGreen, TEXT("HostDialog::OnCreate\n"));

    ::SetParent(CalleeHwnd, GetSafeHwnd());

    return 0;
}

VOID HostDialog::
OnDestroy()
{
    CDialog::OnDestroy();
    DbgConPrt(LightGreen, TEXT("HostDialog::OnDestroy\n"));
}

LRESULT HostDialog::
OnRrmfcProcessDialogCalleeCreating(WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(wParam);
    DbgConPrt(LightGreen, TEXT("HostDialog::OnRrmfcProcessDialogCalleeCreating\n"));
    return NULL;
}

LRESULT HostDialog::
OnRrmfcProcessDialogCalleeDestroying(WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(wParam);
    DbgConPrt(LightGreen, TEXT("HostDialog::OnRrmfcProcessDialogCalleeDestroying\n"));
    return NULL;
}
