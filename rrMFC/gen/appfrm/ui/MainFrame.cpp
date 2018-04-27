/// \copyright The MIT License

#include "stdafx.h"
#include "MainFrame.h"

#include "utils/dbgcon.h"

IMPLEMENT_DYNCREATE(MainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(MainFrame, CFrameWnd)
    ON_WM_CREATE()

    ON_WM_CHANGEUISTATE()
    ON_WM_UPDATEUISTATE()
    ON_WM_DWMNCRENDERINGCHANGED()
    ON_WM_SHOWWINDOW()

    ON_WM_ACTIVATEAPP()
    ON_WM_ACTIVATE()
    ON_WM_NCACTIVATE()

    ON_WM_WINDOWPOSCHANGING()
    ON_WM_NCCALCSIZE()
    ON_WM_SIZE()
    ON_WM_MOVE()
    ON_WM_WINDOWPOSCHANGED()

    ON_WM_NCPAINT()
    ON_WM_ERASEBKGND()
    ON_WM_PAINT()

    ON_WM_SETFOCUS()
    ON_WM_PARENTNOTIFY()

    ON_WM_CLOSE()
END_MESSAGE_MAP()

#// Constructors

MainFrame::
MainFrame()
{
    DbgConPrt(LightYellow, TEXT("MainFrame::Constructor\n"));
}

#// Overridables

MainFrame::
~MainFrame()
{
    DbgConPrt(LightYellow, TEXT("MainFrame::Destructor\n"));
}

BOOL MainFrame::
PreCreateWindow(CREATESTRUCT &cs)
{
    DbgConPrt(LightYellow, TEXT("MainFrame::PreCreateWindow\n"));
    cs.cx = 400;
    cs.cy = 300;
    return CFrameWnd::PreCreateWindow(cs);
}

BOOL MainFrame::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
    DbgConPrtWndMsg(Yellow, TEXT("MainFrame::OnWndMsg"), message, wParam, lParam, pResult);
    return CFrameWnd::OnWndMsg(message, wParam, lParam, pResult);
}

BOOL MainFrame::
OnCmdMsg(UINT nID, INT nCode, VOID *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo)
{
    DbgConPrtCmdMsg(LightYellow, TEXT("MainFrame::OnCmdMsg"), nID, nCode, pExtra, pHandlerInfo);
    if (View.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
        return TRUE;
    return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

#// Message Handlers

INT MainFrame::
OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
        return -1;
    DbgConPrt(LightYellow, TEXT("MainFrame::OnCreate\n"));
    if (!View.Create(NULL, NULL,
                     AFX_WS_DEFAULT_VIEW, CRect(0, 0, 0, 0),
                     this, AFX_IDW_PANE_FIRST, NULL))
        return -1;
    return 0;
}

VOID MainFrame::
OnChangeUIState(UINT nAction, UINT nUIElement)
{
    CFrameWnd::OnChangeUIState(nAction, nUIElement);
    DbgConPrt(LightYellow, TEXT("MainFrame::OnChangeUIState\n"));
}

VOID MainFrame::
OnUpdateUIState(UINT nAction, UINT nUIElement)
{
    CFrameWnd::OnUpdateUIState(nAction, nUIElement);
    DbgConPrt(LightYellow, TEXT("MainFrame::OnUpdateUIState\n"));
}

VOID MainFrame::
OnNcRenderingChanged(BOOL bIsRendering)
{
    DbgConPrt(LightYellow, TEXT("MainFrame::OnNcRenderingChanged\n"));
    CFrameWnd::OnNcRenderingChanged(bIsRendering);
}

VOID MainFrame::
OnShowWindow(BOOL bShow, UINT nStatus)
{
    CFrameWnd::OnShowWindow(bShow, nStatus);
    DbgConPrt(LightYellow, TEXT("MainFrame::OnShowWindow\n"));
}

VOID MainFrame::
OnActivateApp(BOOL bActive, DWORD dwThreadID)
{
    CFrameWnd::OnActivateApp(bActive, dwThreadID);
    DbgConPrt(LightYellow, TEXT("MainFrame::OnActivateApp\n"));
}

BOOL MainFrame::
OnNcActivate(BOOL bActive)
{
    DbgConPrt(LightYellow, TEXT("MainFrame::OnNcActivate\n"));
    return CFrameWnd::OnNcActivate(bActive);
}

VOID MainFrame::
OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
    CFrameWnd::OnActivate(nState, pWndOther, bMinimized);
    DbgConPrt(LightYellow, TEXT("MainFrame::OnActivate\n"));
}

VOID MainFrame::
OnWindowPosChanging(WINDOWPOS *lpwndpos)
{
    CFrameWnd::OnWindowPosChanging(lpwndpos);
    DbgConPrt(LightYellow, TEXT("MainFrame::OnWindowPosChanging\n"));
}

VOID MainFrame::
OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS *lpncsp)
{
    DbgConPrt(LightYellow, TEXT("MainFrame::OnNcCalcSize\n"));
    CFrameWnd::OnNcCalcSize(bCalcValidRects, lpncsp);
}

VOID MainFrame::
OnSize(UINT nType, INT cx, INT cy)
{
    CFrameWnd::OnSize(nType, cx, cy);
    DbgConPrt(LightYellow, TEXT("MainFrame::OnSize\n"));
}

VOID MainFrame::
OnMove(INT x, INT y)
{
    CFrameWnd::OnMove(x, y);
    DbgConPrt(LightYellow, TEXT("MainFrame::OnMove\n"));
}

VOID MainFrame::
OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
    CFrameWnd::OnWindowPosChanged(lpwndpos);
    DbgConPrt(LightYellow, TEXT("MainFrame::OnWindowPosChanged\n"));
}

VOID MainFrame::
OnNcPaint()
{
    CFrameWnd::OnNcPaint();
    DbgConPrt(LightYellow, TEXT("MainFrame::OnNcPaint\n"));
}

BOOL MainFrame::
OnEraseBkgnd(CDC *pDC)
{
    DbgConPrt(LightYellow, TEXT("MainFrame::OnEraseBkgnd\n"));
    return CFrameWnd::OnEraseBkgnd(pDC);
}

VOID MainFrame::
OnPaint()
{
    CFrameWnd::OnPaint();
    DbgConPrt(LightYellow, TEXT("MainFrame::OnPaint\n"));
}

VOID MainFrame::
OnSetFocus(CWnd *pOldWnd)
{
    DbgConPrt(LightYellow, TEXT("MainFrame::OnSetFocus\n"));
#if TRUE
    View.SetFocus();
#else
    CFrameWnd::OnSetFocus(pOldWnd);
#endif
}

VOID MainFrame::
OnParentNotify(UINT message, LPARAM lParam)
{
    CFrameWnd::OnParentNotify(message, lParam);
    DbgConPrt(LightYellow, TEXT("MainFrame::OnParentNotify\n"));
}

VOID MainFrame::
OnClose()
{
    DbgConPrt(LightYellow, TEXT("MainFrame::OnClose\n"));
    CFrameWnd::OnClose();
}
