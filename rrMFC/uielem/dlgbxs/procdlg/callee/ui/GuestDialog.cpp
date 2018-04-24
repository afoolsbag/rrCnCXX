/// \copyright The MIT License

#include "stdafx.h"
#include "resource.h"
#include "ui/GuestDialog.h"

#include "utils/dbgcon.h"

#include "main.h"

IMPLEMENT_DYNCREATE(GuestDialog, CDialog)

BEGIN_MESSAGE_MAP(GuestDialog, CDialog)
    ON_WM_CREATE()
    ON_WM_DESTROY()

    ON_WM_SIZE()

    ON_REGISTERED_MESSAGE(RM_RRMFC_HOST_MOVING, &GuestDialog::OnRrmfcHostMoving)

    ON_BN_CLICKED(IDC_TOGGLE_SIDE_DIALOG_BUTTON, &GuestDialog::OnBnClickedToggleSideDialogButton)
END_MESSAGE_MAP()

#// Constructors

GuestDialog::
GuestDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    DbgConPrt(LightGreen, TEXT("GuestDialog::Constructor\n"));
}

VOID GuestDialog::
SetHostHwnd(CONST HWND hostHwnd)
{
    HostHwnd = hostHwnd;
}

#// Overridables

GuestDialog::
~GuestDialog()
{
    DbgConPrt(LightGreen, TEXT("GuestDialog::Destructor\n"));
}

BOOL GuestDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConPrtWndMsg(Green, TEXT("GuestDialog::OnWndMsg"), message, wParam, lParam, pResult);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID GuestDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DbgConPrt(LightGreen, TEXT("GuestDialog::DoDataExchange\n"));
}

BOOL GuestDialog::
OnInitDialog()
{
    CDialog::OnInitDialog();
    DbgConPrt(LightGreen, TEXT("GuestDialog::OnInitDialog\n"));
    UpdateWindow();
    return TRUE;
}

VOID GuestDialog::
OnCancel()
{
    DbgConPrt(LightGreen, TEXT("GuestDialog::OnCancel\n"));
    CDialog::OnCancel();
}

#// Message Handlers

INT GuestDialog::
OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CDialog::OnCreate(lpCreateStruct) == -1)
        return -1;
    DbgConPrt(LightGreen, TEXT("GuestDialog::OnCreate\n"));

    if (!HostHwnd)
        return -1;

    ::SetParent(GetSafeHwnd(), HostHwnd);

    SideDialog.Create(SideDialog::IDD, this);

    HWND hwnd = GetSafeHwnd();
    DbgConPrt(White, TEXT("RM_RRMFC_GUEST_CREATING: %p\n"), hwnd);
    ::PostMessage(HostHwnd, RM_RRMFC_GUEST_CREATING, NULL, reinterpret_cast<LPARAM>(hwnd));

    return 0;
}

VOID GuestDialog::
OnDestroy()
{
    CDialog::OnDestroy();
    DbgConPrt(LightGreen, TEXT("GuestDialog::OnDestroy\n"));
    HWND hwnd = GetSafeHwnd();
    DbgConPrt(White, TEXT("RM_RRMFC_GUEST_DESTROYING: %p\n"), hwnd);
    ::PostMessage(HostHwnd, RM_RRMFC_GUEST_DESTROYING, NULL, reinterpret_cast<LPARAM>(hwnd));
}

VOID GuestDialog::
OnSize(UINT nType, INT cx, INT cy)
{
    CDialog::OnSize(nType, cx, cy);
    DbgConPrt(LightGreen, TEXT("MainDialog::OnSize\n"));

    DbgConPrt(White, TEXT("RM_RRMFC_GUEST_SIZING: %d, %d\n"), cx, cy);
    ::PostMessage(HostHwnd, RM_RRMFC_GUEST_SIZING, cx, cy);
}

VOID GuestDialog::
OnBnClickedToggleSideDialogButton()
{
    DbgConPrt(LightGreen, TEXT("GuestDialog::OnBnClickedToggleSideDialogButton\n"));
    if (SideDialog.IsWindowVisible())
        SideDialog.ShowWindow(SW_HIDE);
    else
        SideDialog.ShowWindow(SW_NORMAL);

    FromHandle(HostHwnd)->SetFocus();
}

LRESULT GuestDialog::
OnRrmfcHostMoving(WPARAM wParam, LPARAM lParam)
{
    DbgConPrt(LightGreen, TEXT("GuestDialog::OnRrmfcHostMoving\n"));

    CRect hostDlgRect;
    ::GetWindowRect(HostHwnd, &hostDlgRect);
    CRect sideDlgRect;
    SideDialog.GetWindowRect(sideDlgRect);

    CONST CPoint curPos(sideDlgRect.left, sideDlgRect.top);
    CONST CPoint tgtPos(hostDlgRect.right - 13, hostDlgRect.top);

    if (tgtPos != curPos)
        SideDialog.MoveWindow(tgtPos.x, tgtPos.y,
                              sideDlgRect.Width(), sideDlgRect.Height(), FALSE);

    return NULL;
}
