/// \copyright The Unlicense

#include "stdafx.h"
#include "HostDialog.h"
#include "HostDialog.rc.h"

#include "rrwindows/rrwindows.h"

#include "Application.h"

namespace rrMFC {
namespace Test {

const unsigned HostDialog::IDD {IDD_HOST_DIALOG};

BEGIN_MESSAGE_MAP(HostDialog, CDialog)
    ON_WM_CREATE()

    ON_WM_MOVE()

    ON_REGISTERED_MESSAGE(RegisteredMessages::GuestCreate, &HostDialog::OnGuestCreate)
    ON_REGISTERED_MESSAGE(RegisteredMessages::GuestSize, &HostDialog::OnGuestSize)
    ON_REGISTERED_MESSAGE(RegisteredMessages::GuestShowWindow, &HostDialog::OnGuestShowWindow)
    ON_REGISTERED_MESSAGE(RegisteredMessages::GuestDestroy, &HostDialog::OnGuestDestroy)

    ON_WM_TIMER()
END_MESSAGE_MAP()

#// Constructors

HostDialog::
HostDialog(CWnd *pParent /*=nullptr*/)
    : CDialog(IDD, pParent)
{
    DcMeth();
}

HostDialog::
~HostDialog()
{
    DcMeth();
}

#// Overridables

BOOL HostDialog::
OnInitDialog()
{
    CDialog::OnInitDialog();
    DcMeth();
    ShowWindow(SW_HIDE);
    return TRUE;
}

BOOL HostDialog::
OnWndMsg(unsigned message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DcWndMsg();
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

#// Message Handlers

int HostDialog::
OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CDialog::OnCreate(lpCreateStruct) == -1)
        return -1;
    DcMeth();

    ExeParameters.Format(TEXT("/host %08p %s"), GetSafeHwnd(), static_cast<LPCTSTR>(ExeParameters));
    if (RunExecutable(ExePath, ExeParameters)) {
        AfxGetMainWnd()->BeginWaitCursor();
        return 0;
    } else {
        DcKPrint(White, TEXT("CreateProcess failed with %lu, %s\n"), GetLastError(), LastErrorText());
        return -1;
    }
}

void HostDialog::
OnMove(int x, int y)
{
    CDialog::OnMove(x, y);
    DcMeth();

    if (GuestHwnd) {
        DcKPrint(White, TEXT("Post RM_RRMFC_HOST_MOVE with %d, %d\n"), x, y);
        ::PostMessage(GuestHwnd, RegisteredMessages::HostMove, x, y);
    }
}

LRESULT HostDialog::
OnGuestCreate(WPARAM wParam, LPARAM lParam)
{
    UNUSED_ALWAYS(wParam);
    auto const hwnd = reinterpret_cast<HWND>(lParam);
    ASSERT(nullptr != hwnd && IsWindow(hwnd));

    DcKPrint(White, TEXT("Receive RM_RRMFC_GUEST_CREATE with %p\n"), hwnd);
    DcMeth();
    AfxGetMainWnd()->EndWaitCursor();
    ASSERT(GuestHwnd == nullptr);
    GuestHwnd = hwnd;
    SetTimer(CheckGuestAlive, 1000, nullptr);
    return NULL;
}

LRESULT HostDialog::
OnGuestSize(WPARAM wParam, LPARAM lParam)
{
    const auto cx = static_cast<int>(wParam);
    const auto cy = static_cast<int>(lParam);
    DcKPrint(White, TEXT("Receive RM_RRMFC_GUEST_SIZE with %d, %d\n"), cx, cy);
    DcMeth();

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
    const auto bShow = static_cast<BOOL>(lParam);
    const auto nStatus = static_cast<unsigned>(wParam);
    DcKPrint(White, TEXT("Receive RM_RRMFC_GUEST_SHOWWINDOW with %d, %u\n"), bShow, nStatus);
    DcMeth();

    return NULL;
}

LRESULT HostDialog::
OnGuestDestroy(WPARAM wParam, LPARAM lParam)
{
    UNUSED_ALWAYS(wParam);
    const auto hwnd = reinterpret_cast<HWND>(lParam);

    DcKPrint(White, TEXT("Receive RM_RRMFC_GUEST_DESTROY with %p\n"), hwnd);
    DcMeth();

    GuestHwnd = nullptr;
    EndDialog(IDCLOSE);
    return NULL;
}

VOID HostDialog::
OnTimer(UINT_PTR nIDEvent)
{
    switch (nIDEvent) {
    case CheckGuestAlive:
        if (GuestHwnd != nullptr && !IsWindow(GuestHwnd)) {
            KillTimer(CheckGuestAlive);
            EndDialog(IDABORT);
        }
        break;
    default:
        DpErrorUSR(nIDEvent);
        break;
    }
}

}//namespace Test
}//namespace rrMFC
