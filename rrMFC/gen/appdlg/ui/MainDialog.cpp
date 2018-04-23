/// \copyright The MIT License

#include "stdafx.h"
#include "resource.h"
#include "MainDialog.h"

#include "utils/dbgcon.h"

IMPLEMENT_DYNCREATE(MainDialog, CDialog)

BEGIN_MESSAGE_MAP(MainDialog, CDialog)
    ON_WM_NCCREATE()
    ON_WM_CREATE()
    ON_WM_DESTROY()
    ON_WM_NCDESTROY()

    ON_WM_CHANGEUISTATE()
    ON_WM_UPDATEUISTATE()
    ON_WM_DWMNCRENDERINGCHANGED()
    ON_WM_SHOWWINDOW()

    ON_WM_ACTIVATEAPP()
    ON_WM_NCACTIVATE()
    ON_WM_ACTIVATE()

    ON_WM_WINDOWPOSCHANGING()
    ON_WM_NCCALCSIZE()
    ON_WM_SIZE()
    ON_WM_MOVE()
    ON_WM_WINDOWPOSCHANGED()

    ON_WM_NCPAINT()
    ON_WM_ERASEBKGND()
    ON_WM_PAINT()

    ON_WM_CLOSE()

    ON_BN_CLICKED(IDOK, &MainDialog::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &MainDialog::OnBnClickedCancel)

    ON_BN_CLICKED(IDABORT, &MainDialog::OnBnClickedAbort)
    ON_BN_CLICKED(IDRETRY, &MainDialog::OnBnClickedRetry)
    ON_BN_CLICKED(IDIGNORE, &MainDialog::OnBnClickedIgnore)

    ON_BN_CLICKED(IDYES, &MainDialog::OnBnClickedYes)
    ON_BN_CLICKED(IDNO, &MainDialog::OnBnClickedNo)

    ON_BN_CLICKED(IDCLOSE, &MainDialog::OnBnClickedClose)
    ON_BN_CLICKED(IDHELP, &MainDialog::OnBnClickedHelp)

END_MESSAGE_MAP()


#ifdef PREFUNCTION
# error Macro name conflicts.
#endif/*PREFUNCTION*/
#define PREFUNCTION do{DbgConPrt(White, TEXT("%p "), GetSafeHwnd());}while(FALSE)

#// Constructors

MainDialog::
MainDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    PREFUNCTION;
    DbgConPrt(LightYellow, TEXT("MainDialog::Constructor\n"));
}

#// Overridables

MainDialog::
~MainDialog()
{
    PREFUNCTION;
    DbgConPrt(LightYellow, TEXT("MainDialog::Destructor\n"));
}

BOOL MainDialog::
PreCreateWindow(CREATESTRUCT &cs)
{
    PREFUNCTION;
    DbgConPrt(LightYellow, TEXT("MainDialog::PreCreateWindow\n"));
    return CDialog::PreCreateWindow(cs);
}

BOOL MainDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    PREFUNCTION;
    DbgConPrtWndMsg(Yellow, TEXT("MainDialog::OnWndMsg"), message, wParam, lParam, pResult);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID MainDialog::
PreInitDialog()
{
    PREFUNCTION;
    DbgConPrt(LightYellow, TEXT("MainDialog::PreInitDialog\n"));
    CDialog::PreInitDialog();
}

VOID MainDialog::
DoDataExchange(CDataExchange *pDX)
{
    PREFUNCTION;
    CDialog::DoDataExchange(pDX);
    DbgConPrt(LightYellow, TEXT("MainDialog::DoDataExchange\n"));
}

BOOL MainDialog::
OnInitDialog()
{
    PREFUNCTION;
    CDialog::OnInitDialog();
    DbgConPrt(LightYellow, TEXT("MainDialog::OnInitDialog\n"));
    return TRUE;
}

VOID MainDialog::
OnOK()
{
    PREFUNCTION;
    DbgConPrt(LightYellow, TEXT("MainDialog::OnOK\n"));
    CDialog::OnOK();
}

VOID MainDialog::
OnCancel()
{
    PREFUNCTION;
    DbgConPrt(LightYellow, TEXT("MainDialog::OnCancel\n"));
    CDialog::OnCancel();
}

VOID MainDialog::
PostNcDestroy()
{
    PREFUNCTION;
    DbgConPrt(LightYellow, TEXT("MainDialog::PostNcDestroy\n"));
    CDialog::PostNcDestroy();
}

#// Message Handlers

BOOL MainDialog::
OnNcCreate(LPCREATESTRUCT lpCreateStruct)
{
    PREFUNCTION;
    if (!CDialog::OnNcCreate(lpCreateStruct))
        return FALSE;
    DbgConPrt(LightYellow, TEXT("MainDialog::OnNcCreate\n"));
    return TRUE;
}

INT MainDialog::
OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    PREFUNCTION;
    if (CDialog::OnCreate(lpCreateStruct) == -1)
        return -1;
    DbgConPrt(LightYellow, TEXT("MainDialog::OnCreate\n"));
    return 0;
}

VOID MainDialog::
OnDestroy()
{
    PREFUNCTION;
    CDialog::OnDestroy();
    DbgConPrt(LightYellow, TEXT("MainDialog::OnDestroy\n"));
}

VOID MainDialog::
OnNcDestroy()
{
    PREFUNCTION;
    CDialog::OnNcDestroy();
    DbgConPrt(LightYellow, TEXT("MainDialog::OnNcDestroy\n"));
}

VOID MainDialog::
OnChangeUIState(UINT nAction, UINT nUIElement)
{
    PREFUNCTION;
    CDialog::OnChangeUIState(nAction, nUIElement);
    DbgConPrt(LightYellow, TEXT("MainDialog::OnChangeUIState\n"));
}

VOID MainDialog::
OnUpdateUIState(UINT nAction, UINT nUIElement)
{
    PREFUNCTION;
    CDialog::OnUpdateUIState(nAction, nUIElement);
    DbgConPrt(LightYellow, TEXT("MainDialog::OnUpdateUIState\n"));
}

VOID MainDialog::
OnNcRenderingChanged(BOOL bIsRendering)
{
    PREFUNCTION;
    DbgConPrt(LightYellow, TEXT("MainDialog::OnNcRenderingChanged\n"));
    CDialog::OnNcRenderingChanged(bIsRendering);
}

VOID MainDialog::
OnShowWindow(BOOL bShow, UINT nStatus)
{
    PREFUNCTION;
    CDialog::OnShowWindow(bShow, nStatus);
    DbgConPrt(LightYellow, TEXT("MainDialog::OnShowWindow\n"));
}

VOID MainDialog::
OnActivateApp(BOOL bActive, DWORD dwThreadID)
{
    PREFUNCTION;
    CDialog::OnActivateApp(bActive, dwThreadID);
    DbgConPrt(LightYellow, TEXT("MainDialog::OnActivateApp\n"));
}

BOOL MainDialog::
OnNcActivate(BOOL bActive)
{
    PREFUNCTION;
    DbgConPrt(LightYellow, TEXT("MainDialog::OnNcActivate\n"));
    return CDialog::OnNcActivate(bActive);
}

VOID MainDialog::
OnActivate(UINT nState, CWnd *pWndOther, BOOL bMinimized)
{
    PREFUNCTION;
    CDialog::OnActivate(nState, pWndOther, bMinimized);
    DbgConPrt(LightYellow, TEXT("MainDialog::OnActivate\n"));
}

VOID MainDialog::
OnWindowPosChanging(WINDOWPOS *lpwndpos)
{
    PREFUNCTION;
    CDialog::OnWindowPosChanging(lpwndpos);
    DbgConPrt(LightYellow, TEXT("MainDialog::OnWindowPosChanging\n"));
}

VOID MainDialog::
OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS *lpncsp)
{
    PREFUNCTION;
    DbgConPrt(LightYellow, TEXT("MainDialog::OnNcCalcSize\n"));
    CDialog::OnNcCalcSize(bCalcValidRects, lpncsp);
}

VOID MainDialog::
OnSize(UINT nType, INT cx, INT cy)
{
    PREFUNCTION;
    CDialog::OnSize(nType, cx, cy);
    DbgConPrt(LightYellow, TEXT("MainDialog::OnSize\n"));
}

VOID MainDialog::
OnMove(INT x, INT y)
{
    PREFUNCTION;
    CDialog::OnMove(x, y);
    DbgConPrt(LightYellow, TEXT("MainDialog::OnMove\n"));
}

VOID MainDialog::
OnWindowPosChanged(WINDOWPOS *lpwndpos)
{
    PREFUNCTION;
    CDialog::OnWindowPosChanged(lpwndpos);
    DbgConPrt(LightYellow, TEXT("MainDialog::OnWindowPosChanged\n"));
}

VOID MainDialog::
OnNcPaint()
{
    PREFUNCTION;
    CDialog::OnNcPaint();
    DbgConPrt(LightYellow, TEXT("MainDialog::OnNcPaint\n"));
}

BOOL MainDialog::
OnEraseBkgnd(CDC *pDC)
{
    PREFUNCTION;
    DbgConPrt(LightYellow, TEXT("MainDialog::OnEraseBkgnd\n"));
    return CDialog::OnEraseBkgnd(pDC);
}

VOID MainDialog::
OnPaint()
{
    PREFUNCTION;
    CDialog::OnPaint();
    DbgConPrt(LightYellow, TEXT("MainDialog::OnPaint\n"));
}

VOID MainDialog::
OnClose()
{
    PREFUNCTION;
    DbgConPrt(LightYellow, TEXT("MainDialog::OnClose\n"));
    CDialog::OnClose();
}

VOID MainDialog::
OnBnClickedOk()
{
    PREFUNCTION;
    DbgConPrt(LightYellow, TEXT("MainDialog::OnBnClickedOk\n"));
    CDialog::OnOK();
}

VOID MainDialog::
OnBnClickedCancel()
{
    PREFUNCTION;
    DbgConPrt(LightYellow, TEXT("MainDialog::OnBnClickedCancel\n"));
    CDialog::OnCancel();
}

VOID MainDialog::
OnBnClickedAbort()
{
    PREFUNCTION;
    DbgConPrt(LightYellow, TEXT("MainDialog::OnBnClickedAbort\n"));
    EndDialog(IDABORT);
}

VOID MainDialog::
OnBnClickedRetry()
{
    PREFUNCTION;
    DbgConPrt(LightYellow, TEXT("MainDialog::OnBnClickedRetry\n"));
    EndDialog(IDRETRY);
}

VOID MainDialog::
OnBnClickedIgnore()
{
    PREFUNCTION;
    DbgConPrt(LightYellow, TEXT("MainDialog::OnBnClickedIgnore\n"));
    EndDialog(IDIGNORE);
}

VOID MainDialog::
OnBnClickedYes()
{
    PREFUNCTION;
    DbgConPrt(LightYellow, TEXT("MainDialog::OnBnClickedYes\n"));
    EndDialog(IDYES);
}

VOID MainDialog::
OnBnClickedNo()
{
    PREFUNCTION;
    DbgConPrt(LightYellow, TEXT("MainDialog::OnBnClickedNo\n"));
    EndDialog(IDNO);
}

VOID MainDialog::
OnBnClickedClose()
{
    PREFUNCTION;
    DbgConPrt(LightYellow, TEXT("MainDialog::OnBnClickedClose\n"));
    EndDialog(IDCLOSE);
}

VOID MainDialog::
OnBnClickedHelp()
{
    PREFUNCTION;
    DbgConPrt(LightYellow, TEXT("MainDialog::OnBnClickedHelp\n"));
    EndDialog(IDHELP);
}

#undef PREFUNCTION
