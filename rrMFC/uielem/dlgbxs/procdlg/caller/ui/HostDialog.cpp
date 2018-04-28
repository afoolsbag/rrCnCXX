/// \copyright The MIT License

#include "stdafx.h"
#include "ui/HostDialog.h"

#include "utils/dbgcon.h"

#include "main.h"

IMPLEMENT_DYNCREATE(HostDialog, CDialog)

BEGIN_MESSAGE_MAP(HostDialog, CDialog)
    ON_WM_CREATE()
    ON_WM_DESTROY()

    ON_WM_MOVE()

    ON_REGISTERED_MESSAGE(RM_RRMFC_GUEST_CREATE, &HostDialog::OnGuestCreate)
    ON_REGISTERED_MESSAGE(RM_RRMFC_GUEST_SIZE, &HostDialog::OnGuestSize)
    ON_REGISTERED_MESSAGE(RM_RRMFC_GUEST_SHOWWINDOW, &HostDialog::OnGuestShowWindow)
    ON_REGISTERED_MESSAGE(RM_RRMFC_GUEST_DESTROY, &HostDialog::OnGuestDestroy)
END_MESSAGE_MAP()

#// Constructors

HostDialog::
HostDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    DbgConPrt(Green, TEXT("HostDialog::"));
    DbgConPrt(LightGreen, TEXT("Constructor\n"));
}

HostDialog::
~HostDialog()
{
    DbgConPrt(Green, TEXT("HostDialog::"));
    DbgConPrt(LightGreen, TEXT("Destructor\n"));
}

#// Overridables

BOOL HostDialog::
OnInitDialog()
{
    CDialog::OnInitDialog();
    DbgConPrt(Green, TEXT("HostDialog::"));
    DbgConPrt(LightGreen, TEXT("OnInitDialog\n"));
    ShowWindow(FALSE);
    return TRUE;
}

BOOL HostDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConPrt(Green, TEXT("HostDialog::"));
    DbgConPrtWndMsg(Green, TEXT("OnWndMsg"), message, wParam, lParam, pResult);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

#// Message Handlers

INT HostDialog::
OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CDialog::OnCreate(lpCreateStruct) == -1)
        return -1;
    DbgConPrt(Green, TEXT("HostDialog::"));
    DbgConPrt(LightGreen, TEXT("OnCreate\n"));

    TCHAR args[16];
    _stprintf_s(args, _countof(args), TEXT(" /host %08p"), GetSafeHwnd());
    STARTUPINFO suInfo = {};
    suInfo.cb = sizeof(suInfo);
    PROCESS_INFORMATION procInfo = {};

    if (!CreateProcess(ExePath, args, NULL, NULL, FALSE, 0, NULL, NULL, &suInfo, &procInfo)) {
        DbgConPrt(White, TEXT("CreateProcess failed: %lu\n"), GetLastError());
        return -1;
    }
    CloseHandle(procInfo.hProcess);
    CloseHandle(procInfo.hThread);

    return 0;
}

VOID HostDialog::
OnMove(INT x, INT y)
{
    CDialog::OnMove(x, y);
    DbgConPrt(Green, TEXT("HostDialog::"));
    DbgConPrt(LightGreen, TEXT("OnMove\n"));

    if (GuestHwnd) {
        DbgConPrt(White, TEXT("Post RM_RRMFC_HOST_MOVE: %d, %d\n"), x, y);
        ::PostMessage(GuestHwnd, RM_RRMFC_HOST_MOVE, x, y);
    }
}

LRESULT HostDialog::
OnGuestCreate(WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(wParam);
    DbgConPrt(Green, TEXT("HostDialog::"));
    DbgConPrt(LightGreen, TEXT("OnGuestCreate\n"));

    DbgConPrt(White, TEXT("Receive RM_RRMFC_GUEST_CREATE with %p\n"), reinterpret_cast<HWND>(lParam));

    GuestHwnd = reinterpret_cast<HWND>(lParam);
    return NULL;
}

LRESULT HostDialog::
OnGuestSize(WPARAM wParam, LPARAM lParam)
{
    DbgConPrt(Green, TEXT("HostDialog::"));
    DbgConPrt(LightGreen, TEXT("OnGuestSize\n"));

    DbgConPrt(White, TEXT("Receive RM_RRMFC_GUEST_SIZE with %u, %ld\n"), wParam, lParam);

    CRect rect;
    GetClientRect(&rect);
    rect.right = rect.left + wParam + 20;
    rect.bottom = rect.top + lParam + 43;
    ClientToScreen(&rect);
    MoveWindow(rect.left, rect.top, rect.Width(), rect.Height());
    return NULL;
}

LRESULT HostDialog::
OnGuestShowWindow(WPARAM wParam, LPARAM lParam)
{
    DbgConPrt(Green, TEXT("HostDialog::"));
    DbgConPrt(LightGreen, TEXT("OnGuestShowWindow\n"));

    DbgConPrt(White, TEXT("Receive RM_RRMFC_GUEST_SHOWWINDOW with %u, %ld\n"), wParam, lParam);

    if (static_cast<BOOL>(lParam))
        ShowWindow(TRUE);
    return NULL;
}

LRESULT HostDialog::
OnGuestDestroy(WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(wParam);
    DbgConPrt(Green, TEXT("HostDialog::"));
    DbgConPrt(LightGreen, TEXT("OnGuestDestroy\n"));

    DbgConPrt(White, TEXT("Receive RM_RRMFC_GUEST_DESTROY with %p\n"), reinterpret_cast<HWND>(lParam));

    GuestHwnd = NULL;
    ShowWindow(SW_HIDE);
    EndDialog(IDCLOSE);
    return NULL;
}
