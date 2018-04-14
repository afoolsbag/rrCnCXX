/// \copyright The MIT License

#include "stdafx.h"
#include "MainFrame.h"

#include <conio.h>

#include "../concol.inl"
#include "../sysmsgstr.inl"

IMPLEMENT_DYNCREATE(MainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(MainFrame, CFrameWnd)
    ON_WM_ACTIVATE()
    ON_WM_ACTIVATEAPP()
    ON_WM_CLOSE()
    ON_WM_CREATE()
    ON_WM_DESTROY()
    ON_WM_DWMNCRENDERINGCHANGED()
    ON_WM_ERASEBKGND()
    ON_WM_MOVE()
    ON_WM_NCACTIVATE()
    ON_WM_NCCALCSIZE()
    ON_WM_NCCREATE()
    ON_WM_NCDESTROY()
    ON_WM_NCPAINT()
    ON_WM_PAINT()
    ON_WM_PARENTNOTIFY()
    ON_WM_SETFOCUS()
    ON_WM_SHOWWINDOW()
    ON_WM_SIZE()
    ON_WM_WINDOWPOSCHANGED()
    ON_WM_WINDOWPOSCHANGING()
END_MESSAGE_MAP()

#// Constructors

MainFrame::MainFrame()
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainFrame::Constructor\n"));
}

#// Overridables

MainFrame::~MainFrame()
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainFrame::Destructor\n"));
}

BOOL MainFrame::OnCmdMsg(UINT nID, INT nCode, VOID *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo)
{
    SetConsoleForeFroundColor(LightYellow);
    _tcprintf_s(TEXT("MainFrame::OnCmdMsg %u with %d, 0x%p, 0x%p\n"), nID, nCode, pExtra, pHandlerInfo);
    if (View.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
        return TRUE;
    return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

BOOL MainFrame::OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
    SetConsoleForeFroundColor(Yellow);
    _tcprintf_s(TEXT("MainFrame::OnWndMsg 0x%04X(%s), with %u, %ld, 0x%p\n"), message, SysMsgStr(message), wParam, lParam, pResult);
    return CFrameWnd::OnWndMsg(message, wParam, lParam, pResult);
}

BOOL MainFrame::PreCreateWindow(CREATESTRUCT &cs)
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainFrame::PreCreateWindow\n"));
    cs.cx = 400;
    cs.cy = 300;
    return CFrameWnd::PreCreateWindow(cs);
}

#// Message Handlers

VOID MainFrame::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
    CFrameWnd::OnActivate(nState, pWndOther, bMinimized);
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainFrame::OnActivate\n"));
}

VOID MainFrame::OnActivateApp(BOOL bActive, DWORD dwThreadID)
{
    CFrameWnd::OnActivateApp(bActive, dwThreadID);
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainFrame::OnActivateApp\n"));
}

VOID MainFrame::OnClose()
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainFrame::OnClose\n"));
    CFrameWnd::OnClose();
}

INT MainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
        return -1;
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainFrame::OnCreate\n"));
    if (!View.Create(NULL, NULL,
                     AFX_WS_DEFAULT_VIEW, CRect(0, 0, 0, 0),
                     this, AFX_IDW_PANE_FIRST, NULL))
        return -1;
    return 0;
}

VOID MainFrame::OnDestroy()
{
    CFrameWnd::OnDestroy();
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainFrame::OnDestroy\n"));
}

VOID MainFrame::OnNcRenderingChanged(BOOL bIsRendering)
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainFrame::OnNcRenderingChanged\n"));
    CFrameWnd::OnNcRenderingChanged(bIsRendering);
}

BOOL MainFrame::OnEraseBkgnd(CDC *pDC)
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainFrame::OnEraseBkgnd\n"));
    return CFrameWnd::OnEraseBkgnd(pDC);
}

VOID MainFrame::OnMove(INT x, INT y)
{
    CFrameWnd::OnMove(x, y);
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainFrame::OnMove\n"));
}

BOOL MainFrame::OnNcActivate(BOOL bActive)
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainFrame::OnNcActivate\n"));
    return CFrameWnd::OnNcActivate(bActive);
}

VOID MainFrame::OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS *lpncsp)
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainFrame::OnNcCalcSize\n"));
    CFrameWnd::OnNcCalcSize(bCalcValidRects, lpncsp);
}

BOOL MainFrame::OnNcCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (!CFrameWnd::OnNcCreate(lpCreateStruct))
        return FALSE;
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainFrame::OnNcCreate\n"));
    return TRUE;
}

VOID MainFrame::OnNcDestroy()
{
    CFrameWnd::OnNcDestroy();
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainFrame::OnNcDestroy\n"));
}

VOID MainFrame::OnNcPaint()
{
    CFrameWnd::OnNcPaint();
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainFrame::OnNcPaint\n"));
}

VOID MainFrame::OnPaint()
{
    CFrameWnd::OnPaint();
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainFrame::OnPaint\n"));
}

VOID MainFrame::OnParentNotify(UINT message, LPARAM lParam)
{
    CFrameWnd::OnParentNotify(message, lParam);
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainFrame::OnParentNotify\n"));
}

VOID MainFrame::OnSetFocus(CWnd *pOldWnd)
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainFrame::OnSetFocus\n"));
#if TRUE
    View.SetFocus();
#else
    CFrameWnd::OnSetFocus(pOldWnd);
#endif
}

VOID MainFrame::OnShowWindow(BOOL bShow, UINT nStatus)
{
    CFrameWnd::OnShowWindow(bShow, nStatus);
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainFrame::OnShowWindow\n"));
}

VOID MainFrame::OnSize(UINT nType, INT cx, INT cy)
{
    CFrameWnd::OnSize(nType, cx, cy);
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainFrame::OnSize\n"));
}

VOID MainFrame::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
    CFrameWnd::OnWindowPosChanged(lpwndpos);
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainFrame::OnWindowPosChanged\n"));
}

VOID MainFrame::OnWindowPosChanging(WINDOWPOS *lpwndpos)
{
    CFrameWnd::OnWindowPosChanging(lpwndpos);
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainFrame::OnWindowPosChanging\n"));
}
