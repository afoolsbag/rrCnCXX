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

    ON_REGISTERED_MESSAGE(RM_RRMFC_GUEST_CREATING, &HostDialog::OnRrmfcGuestCreating)
    ON_REGISTERED_MESSAGE(RM_RRMFC_GUEST_SIZING, &HostDialog::OnRrmfcGuestSizing)
    ON_REGISTERED_MESSAGE(RM_RRMFC_GUEST_DESTROYING, &HostDialog::OnRrmfcGuestDestroying)
END_MESSAGE_MAP()

#// Constructors

HostDialog::
HostDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    DbgConPrt(LightYellow, TEXT("HostDialog::Constructor\n"));
}

#// Overridables

HostDialog::
~HostDialog()
{
    DbgConPrt(LightYellow, TEXT("HostDialog::Destructor\n"));
}

BOOL HostDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConPrtWndMsg(Yellow, TEXT("HostDialog::OnWndMsg"), message, wParam, lParam, pResult);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID HostDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DbgConPrt(LightYellow, TEXT("HostDialog::DoDataExchange\n"));
}

VOID HostDialog::
OnCancel()
{
    DbgConPrt(LightYellow, TEXT("HostDialog::OnCancel\n"));
    PostQuitMessage(EXIT_SUCCESS);
    CDialog::OnCancel();
}

#// Message Handlers

INT HostDialog::
OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CDialog::OnCreate(lpCreateStruct) == -1)
        return -1;
    DbgConPrt(LightYellow, TEXT("HostDialog::OnCreate\n"));
    return 0;
}

VOID HostDialog::
OnDestroy()
{
    CDialog::OnDestroy();
    DbgConPrt(LightYellow, TEXT("HostDialog::OnDestroy\n"));
}

VOID HostDialog::
OnMove(INT x, INT y)
{
    CDialog::OnMove(x, y);
    DbgConPrt(LightYellow, TEXT("HostDialog::OnMove\n"));
    if (GuestHwnd) {
        DbgConPrt(White, TEXT("RM_RRMFC_HOST_MOVING: %d, %d\n"), x, y);
        ::PostMessage(GuestHwnd, RM_RRMFC_HOST_MOVING, x, y);
    }
}

LRESULT HostDialog::
OnRrmfcGuestCreating(WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(wParam);
    DbgConPrt(LightYellow, TEXT("HostDialog::OnRrmfcGuestCreating\n"));
    GuestHwnd = reinterpret_cast<HWND>(lParam);
    return NULL;
}

LRESULT HostDialog::
OnRrmfcGuestSizing(WPARAM wParam, LPARAM lParam)
{
    DbgConPrt(LightYellow, TEXT("HostDialog::OnRrmfcGuestSizing\n"));
    CRect rect;
    GetClientRect(&rect);
    rect.right = rect.left + wParam + 20;
    rect.bottom = rect.top + lParam + 43;
    ClientToScreen(&rect);
    MoveWindow(rect.left, rect.top, rect.Width(), rect.Height());
    return NULL;
}

LRESULT HostDialog::
OnRrmfcGuestDestroying(WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(wParam);
    DbgConPrt(LightYellow, TEXT("HostDialog::OnRrmfcGuestDestroying\n"));
    return NULL;
}
