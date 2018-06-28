/// \copyright The MIT License

#include "stdafx.h"
#include "HostDialog.h"

#include "rrwindows/dbgcon.h"
#include "rrwindows/errtxt.h"
#include "rrwindows/runendproc.h"

#include "main.h"

IMPLEMENT_DYNCREATE(HostDialog, CDialog)

BEGIN_MESSAGE_MAP(HostDialog, CDialog)
    ON_WM_CREATE()

    ON_WM_MOVE()

    ON_REGISTERED_MESSAGE(RM_RRMFC_GUEST_CREATE, &HostDialog::OnGuestCreate)
    ON_REGISTERED_MESSAGE(RM_RRMFC_GUEST_SIZE, &HostDialog::OnGuestSize)
    ON_REGISTERED_MESSAGE(RM_RRMFC_GUEST_SHOWWINDOW, &HostDialog::OnGuestShowWindow)
    ON_REGISTERED_MESSAGE(RM_RRMFC_GUEST_DESTROY, &HostDialog::OnGuestDestroy)

    ON_WM_TIMER()
END_MESSAGE_MAP()

#// Constructors

HostDialog::
HostDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    DbgConPrtMeth(Green);
}

HostDialog::
~HostDialog()
{
    DbgConPrtMeth(Green);
}

#// Overridables

BOOL HostDialog::
OnInitDialog()
{
    CDialog::OnInitDialog();
    DbgConPrtMeth(Green);
    ShowWindow(SW_HIDE);
    return TRUE;
}

BOOL HostDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConPrtMethWndMsg(Green);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

#// Message Handlers

INT HostDialog::
OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CDialog::OnCreate(lpCreateStruct) == -1)
        return -1;
    DbgConPrtMeth(Green);

    ExeParameters.Format(TEXT("/host %08p %s"), GetSafeHwnd(), static_cast<LPCSTR>(ExeParameters));
    if (RunProcess(ExePath, ExeParameters)) {
        AfxGetMainWnd()->BeginWaitCursor();
        return 0;
    } else {
        DbgConPrt(White, TEXT("CreateProcess failed with %lu, %s\n"), GetLastError(), GetLastErrorText());
        return -1;
    }
}

VOID HostDialog::
OnMove(INT x, INT y)
{
    CDialog::OnMove(x, y);
    DbgConPrtMeth(Green);

    if (GuestHwnd) {
        DbgConPrt(White, TEXT("Post RM_RRMFC_HOST_MOVE with %d, %d\n"), x, y);
        ::PostMessage(GuestHwnd, RM_RRMFC_HOST_MOVE, x, y);
    }
}

LRESULT HostDialog::
OnGuestCreate(WPARAM wParam, LPARAM lParam)
{
    UNUSED_ALWAYS(wParam);
    HWND CONST hwnd = reinterpret_cast<HWND>(lParam);
    ASSERT(NULL != hwnd && IsWindow(hwnd));

    DbgConPrt(White, TEXT("Receive RM_RRMFC_GUEST_CREATE with %p\n"), hwnd);
    DbgConPrtMeth(Green);
    AfxGetMainWnd()->EndWaitCursor();
    ASSERT(NULL == GuestHwnd);
    GuestHwnd = hwnd;
    SetTimer(CHECK_GUEST_ALIVE, 1000, NULL);
    return NULL;
}

LRESULT HostDialog::
OnGuestSize(WPARAM wParam, LPARAM lParam)
{
    CONST INT cx = wParam;
    CONST INT cy = lParam;
    DbgConPrt(White, TEXT("Receive RM_RRMFC_GUEST_SIZE with %d, %d\n"), cx, cy);
    DbgConPrtMeth(Green);

    CRect rect;
    GetClientRect(&rect);
    rect.right = rect.left + cx + 20;
    rect.bottom = rect.top + cy + 43;
    ClientToScreen(&rect);
    MoveWindow(rect.left, rect.top, rect.Width(), rect.Height());
    return NULL;
}

LRESULT HostDialog::
OnGuestShowWindow(WPARAM wParam, LPARAM lParam)
{
    CONST BOOL bShow = lParam;
    CONST UINT nStatus = wParam;
    DbgConPrt(White, TEXT("Receive RM_RRMFC_GUEST_SHOWWINDOW with %d, %u\n"), bShow, nStatus);
    DbgConPrtMeth(Green);

    return NULL;
}

LRESULT HostDialog::
OnGuestDestroy(WPARAM wParam, LPARAM lParam)
{
    UNUSED_ALWAYS(wParam);
    HWND CONST hwnd = reinterpret_cast<HWND>(lParam);

    DbgConPrt(White, TEXT("Receive RM_RRMFC_GUEST_DESTROY with %p\n"), hwnd);
    DbgConPrtMeth(Green);

    GuestHwnd = NULL;
    EndDialog(IDCLOSE);
    return NULL;
}

VOID HostDialog::
OnTimer(UINT_PTR nIDEvent)
{
    switch (nIDEvent) {
    case CHECK_GUEST_ALIVE:
    {
        if (NULL == GuestHwnd)
            return;
        if (!IsWindow(GuestHwnd)) {
            KillTimer(CHECK_GUEST_ALIVE);
            EndDialog(IDABORT);
        }
        break;
    }
    default:
        ASSERT(FALSE);
        break;
    }
}
