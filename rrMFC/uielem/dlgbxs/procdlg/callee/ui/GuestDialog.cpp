/// \copyright The MIT License

#include "stdafx.h"
#include "GuestDialog.h"

#include "utils/dbgcon.h"

#include "main.h"

IMPLEMENT_DYNCREATE(GuestDialog, CDialog)

BEGIN_MESSAGE_MAP(GuestDialog, CDialog)
    ON_WM_CREATE()
    ON_WM_DESTROY()
    ON_WM_SIZE()
    ON_WM_SHOWWINDOW()

    ON_REGISTERED_MESSAGE(RM_RRMFC_HOST_MOVE, &GuestDialog::OnHostMove)

    ON_BN_CLICKED(IDC_TOGGLE_SIDE_DIALOG_BUTTON, &GuestDialog::OnBnClickedToggleSideDialogButton)
END_MESSAGE_MAP()

#// Constructors

GuestDialog::
GuestDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    DbgConPrt(Yellow, TEXT("GuestDialog::"));
    DbgConPrt(LightYellow, TEXT("Constructor\n"));
}

VOID GuestDialog::
SetHostHwnd(CONST HWND hostHwnd)
{
    HostHwnd = hostHwnd;
}

GuestDialog::
~GuestDialog()
{
    DbgConPrt(Yellow, TEXT("GuestDialog::"));
    DbgConPrt(LightYellow, TEXT("Destructor\n"));
}

#// Overridables

BOOL GuestDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConPrt(Yellow, TEXT("GuestDialog::"));
    DbgConPrtWndMsg(Yellow, TEXT("OnWndMsg"), message, wParam, lParam, pResult);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID GuestDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DbgConPrt(Yellow, TEXT("GuestDialog::"));
    DbgConPrt(LightYellow, TEXT("DoDataExchange\n"));

    DDX_Control(pDX, IDC_TOGGLE_SIDE_DIALOG_BUTTON, ToggleSideDialogButton);
}

VOID GuestDialog::
OnCancel()
{
    DbgConPrt(Yellow, TEXT("GuestDialog::"));
    DbgConPrt(LightYellow, TEXT("OnCancel\n"));

    DestroyWindow();

    CDialog::OnCancel();
}

VOID GuestDialog::
PostNcDestroy()
{
    DbgConPrt(Yellow, TEXT("GuestDialog::"));
    DbgConPrt(LightYellow, TEXT("PostNcDestroy\n"));
    CWnd::PostNcDestroy();

    delete this;
}

#// Message Handlers

INT GuestDialog::
OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CDialog::OnCreate(lpCreateStruct) == -1)
        return -1;
    DbgConPrt(Yellow, TEXT("GuestDialog::"));
    DbgConPrt(LightYellow, TEXT("OnCreate\n"));

    if (!HostHwnd)
        return -1;

    ::SetParent(GetSafeHwnd(), HostHwnd);

    SideDialog.Create(SideDialog::IDD, this);

    HWND hwnd = GetSafeHwnd();
    DbgConPrt(White, TEXT("Post RM_RRMFC_GUEST_CREATE with %p\n"), hwnd);
    ::PostMessage(HostHwnd, RM_RRMFC_GUEST_CREATE, NULL, reinterpret_cast<LPARAM>(hwnd));

    return 0;
}

VOID GuestDialog::
OnDestroy()
{
    CDialog::OnDestroy();
    DbgConPrt(Yellow, TEXT("GuestDialog::"));
    DbgConPrt(LightYellow, TEXT("OnDestroy\n"));

    HWND hwnd = GetSafeHwnd();
    DbgConPrt(White, TEXT("Post RM_RRMFC_GUEST_DESTROY with %p\n"), hwnd);
    ::PostMessage(HostHwnd, RM_RRMFC_GUEST_DESTROY, NULL, reinterpret_cast<LPARAM>(hwnd));
}

VOID GuestDialog::
OnSize(UINT nType, INT cx, INT cy)
{
    CDialog::OnSize(nType, cx, cy);
    DbgConPrt(Yellow, TEXT("GuestDialog::"));
    DbgConPrt(LightYellow, TEXT("OnSize\n"));

    DbgConPrt(White, TEXT("Post RM_RRMFC_GUEST_SIZE with %d, %d\n"), cx, cy);
    ::PostMessage(HostHwnd, RM_RRMFC_GUEST_SIZE, cx, cy);
}

VOID GuestDialog::
OnShowWindow(BOOL bShow, UINT nStatus)
{
    CDialog::OnShowWindow(bShow, nStatus);
    DbgConPrt(Yellow, TEXT("GuestDialog::"));
    DbgConPrt(LightYellow, TEXT("OnShowWindow\n"));

    DbgConPrt(White, TEXT("Post RM_RRMFC_GUEST_SHOWWINDOW with %u, %d\n"), nStatus, bShow);
    ::PostMessage(HostHwnd, RM_RRMFC_GUEST_SHOWWINDOW, nStatus, bShow);  // 注意参数变换了位置
}

LRESULT GuestDialog::
OnHostMove(WPARAM wParam, LPARAM lParam)
{
    DbgConPrt(Yellow, TEXT("GuestDialog::"));
    DbgConPrt(LightYellow, TEXT("OnHostMove\n"));

    DbgConPrt(White, TEXT("Receive RM_RRMFC_HOST_MOVE with %u, %ld\n"), wParam, lParam);

    if (GetFocus() != &SideDialog) {
        CRect hostDialogRect;
        ::GetWindowRect(HostHwnd, &hostDialogRect);
        CRect sideDialogRect;
        SideDialog.GetWindowRect(sideDialogRect);

        SideDialog.MoveWindow(
            hostDialogRect.right - 13, hostDialogRect.top,
            sideDialogRect.Width(), sideDialogRect.Height(), FALSE);
    }

    return NULL;
}

VOID GuestDialog::
OnBnClickedToggleSideDialogButton()
{
    DbgConPrt(Yellow, TEXT("GuestDialog::"));
    DbgConPrt(LightYellow, TEXT("OnBnClickedToggleSideDialogButton\n"));

    if (SideDialog.IsWindowVisible())
        SideDialog.ShowWindow(SW_HIDE);
    else
        SideDialog.ShowWindow(SW_SHOW);
}
