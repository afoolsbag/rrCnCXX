/// \copyright The MIT License

#include "stdafx.h"
#include "resource.h"
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
    ON_REGISTERED_MESSAGE(RM_RRMFC_GUEST_DESTROY, &HostDialog::OnGuestDestroy)
END_MESSAGE_MAP()

#// Constructors

HostDialog::
HostDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    DbgConPrt(LightGreen, TEXT("HostDialog::Constructor\n"));
}

VOID HostDialog::
SetExePath(LPCTSTR CONST exePath)
{
    ExePath = exePath;
}

HostDialog::
~HostDialog()
{
    DbgConPrt(LightGreen, TEXT("HostDialog::Destructor\n"));
}

#// Overridables

BOOL HostDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConPrtWndMsg(Green, TEXT("HostDialog::OnWndMsg"), message, wParam, lParam, pResult);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID HostDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DbgConPrt(LightGreen, TEXT("HostDialog::DoDataExchange\n"));
}

BOOL HostDialog::
OnInitDialog()
{
    CDialog::OnInitDialog();
    DbgConPrt(LightYellow, TEXT("HostDialog::OnInitDialog\n"));

    CRect dlgRect;
    GetWindowRect(&dlgRect);

    CRect dskRect;
    ::GetWindowRect(::GetDesktopWindow(), &dskRect);

    MoveWindow(dskRect.right / 2, dskRect.bottom / 3, dlgRect.Width(), dlgRect.Height(), FALSE);

    return TRUE;
}

VOID HostDialog::
OnCancel()
{
    DbgConPrt(LightGreen, TEXT("HostDialog::OnCancel\n"));
    CDialog::OnCancel();
}

#// Message Handlers

INT HostDialog::
OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CDialog::OnCreate(lpCreateStruct) == -1)
        return -1;
    DbgConPrt(LightGreen, TEXT("HostDialog::OnCreate\n"));

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
OnDestroy()
{
    CDialog::OnDestroy();
    DbgConPrt(LightGreen, TEXT("HostDialog::OnDestroy\n"));
}

VOID HostDialog::
OnMove(INT x, INT y)
{
    CDialog::OnMove(x, y);
    DbgConPrt(LightGreen, TEXT("HostDialog::OnMove\n"));
    if (GuestHwnd) {
        DbgConPrt(White, TEXT("RM_RRMFC_HOST_MOVING: %d, %d\n"), x, y);
        ::PostMessage(GuestHwnd, RM_RRMFC_HOST_MOVE, x, y);
    }
}

LRESULT HostDialog::
OnGuestCreate(WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(wParam);
    DbgConPrt(LightGreen, TEXT("HostDialog::OnGuestCreate\n"));
    GuestHwnd = reinterpret_cast<HWND>(lParam);
    return NULL;
}

LRESULT HostDialog::
OnGuestSize(WPARAM wParam, LPARAM lParam)
{
    DbgConPrt(LightGreen, TEXT("HostDialog::OnGuestSize\n"));
    CRect rect;
    GetClientRect(&rect);
    rect.right = rect.left + wParam + 20;
    rect.bottom = rect.top + lParam + 43;
    ClientToScreen(&rect);
    MoveWindow(rect.left, rect.top, rect.Width(), rect.Height());
    return NULL;
}

LRESULT HostDialog::
OnGuestDestroy(WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(wParam);
    DbgConPrt(LightGreen, TEXT("HostDialog::OnGuestDestroy\n"));
    GuestHwnd = NULL;
    ShowWindow(SW_HIDE);
    DestroyWindow();
    return NULL;
}
