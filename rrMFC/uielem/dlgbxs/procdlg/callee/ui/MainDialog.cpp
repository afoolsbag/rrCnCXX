/// \copyright The MIT License

#include "stdafx.h"
#include "resource.h"
#include "MainDialog.h"

#include "utils/dbgcon.h"

#include "main.h"

IMPLEMENT_DYNCREATE(MainDialog, CDialog)

BEGIN_MESSAGE_MAP(MainDialog, CDialog)
    ON_WM_CREATE()
    ON_WM_DESTROY()

    ON_WM_MOVE()

    ON_BN_CLICKED(IDC_TOGGLE_SIDE_DIALOG_BUTTON, &MainDialog::OnBnClickedToggleSideDialogButton)
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

BOOL MainDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    //DbgConPrtWndMsg(Yellow, TEXT("MainDialog::OnWndMsg"), message, wParam, lParam, pResult);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID MainDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DbgConPrt(LightYellow, TEXT("MainDialog::DoDataExchange\n"));
}

VOID MainDialog::
OnCancel()
{
    DbgConPrt(LightYellow, TEXT("MainDialog::OnCancel\n"));
    CDialog::OnCancel();
}

#// Message Handlers

INT MainDialog::
OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CDialog::OnCreate(lpCreateStruct) == -1)
        return -1;
    DbgConPrt(LightYellow, TEXT("MainDialog::OnCreate\n"));

    SideDialog.Create(SideDialog::IDD, this);

    if (GlobalApplication.CallerHwnd) {
        HWND hwnd = GetSafeHwnd();
        DbgConPrt(White, TEXT("Send message: %p\n"), hwnd);
        ::PostMessage(GlobalApplication.CallerHwnd, RM_RRMFC_PROCESS_DIALOG_CALLEE_CREATING,
                      NULL, reinterpret_cast<LPARAM>(hwnd));
    }

    return 0;
}

VOID MainDialog::
OnDestroy()
{
    CDialog::OnDestroy();
    DbgConPrt(LightYellow, TEXT("MainDialog::OnDestroy\n"));
    if (GlobalApplication.CallerHwnd) {
        HWND hwnd = GetSafeHwnd();
        DbgConPrt(White, TEXT("Send message parameter: %p\n"), hwnd);
        ::PostMessage(GlobalApplication.CallerHwnd, RM_RRMFC_PROCESS_DIALOG_CALLEE_DESTROYING,
                      NULL, reinterpret_cast<LPARAM>(hwnd));
    }
}

VOID MainDialog::
OnMove(INT x, INT y)
{
    CDialog::OnMove(x, y);
    DbgConPrt(LightYellow, TEXT("MainDialog::OnMove\n"));

    {
        CRect mainDlgRect;
        GetWindowRect(mainDlgRect);
        CRect sideDlgRect;
        SideDialog.GetWindowRect(sideDlgRect);

        CONST CPoint curPos(sideDlgRect.left, sideDlgRect.top);
        CONST CPoint tgtPos(mainDlgRect.right - 13, mainDlgRect.top);

        if (tgtPos != curPos)
            SideDialog.MoveWindow(tgtPos.x, tgtPos.y,
                                  sideDlgRect.Width(), sideDlgRect.Height(), FALSE);
    }
}

VOID MainDialog::
OnBnClickedToggleSideDialogButton()
{
    DbgConPrt(LightYellow, TEXT("MainDialog::OnBnClickedToggleSideDialogButton\n"));
    if (SideDialog.IsWindowVisible())
        SideDialog.ShowWindow(SW_HIDE);
    else
        SideDialog.ShowWindow(SW_NORMAL);
    SetFocus();
}
