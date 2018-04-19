/// \copyright The MIT License

#include "stdafx.h"
#include "MainView.h"

#include "utils/dbgcon.inl"

#include "resource.h"

IMPLEMENT_DYNCREATE(MainView, CWnd)

BEGIN_MESSAGE_MAP(MainView, CWnd)
    ON_COMMAND(ID_COMMAND_5, &MainView::OnCommand5)
    ON_COMMAND(ID_COMMAND_6, &MainView::OnCommand6)
    ON_COMMAND(ID_COMMAND_7, &MainView::OnCommand7)
    ON_COMMAND_RANGE(ID_UNDEFINED, ID_RANGELAST, &MainView::OnUndefined)
    ON_UPDATE_COMMAND_UI(ID_COMMAND_5, &MainView::OnUpdateCommand5)
    ON_UPDATE_COMMAND_UI(ID_COMMAND_6, &MainView::OnUpdateCommand6)
    ON_UPDATE_COMMAND_UI(ID_COMMAND_7, &MainView::OnUpdateCommand7)
    ON_UPDATE_COMMAND_UI_RANGE(ID_UNDEFINED, ID_RANGELAST, &MainView::OnUpdateUndefined)
    ON_WM_CONTEXTMENU()
    ON_WM_CREATE()
    ON_WM_DESTROY()
    ON_WM_ERASEBKGND()
    ON_WM_MOVE()
    ON_WM_NCCALCSIZE()
    ON_WM_NCCREATE()
    ON_WM_NCDESTROY()
    ON_WM_NCPAINT()
    ON_WM_PAINT()
    ON_WM_SHOWWINDOW()
    ON_WM_SIZE()
    ON_WM_WINDOWPOSCHANGED()
    ON_WM_WINDOWPOSCHANGING()
END_MESSAGE_MAP()

#// Constructors

MainView::
MainView()
{
    DbgConPrt(LightGreen, TEXT("MainView::Constructor\n"));
}

#// Overridables

MainView::
~MainView()
{
    DbgConPrt(LightGreen, TEXT("MainView::Destructor\n"));
}

BOOL MainView::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
    DbgConPrtWndMsg(Green, TEXT("MainView::OnWndMsg"), message, wParam, lParam, pResult);
    return CWnd::OnWndMsg(message, wParam, lParam, pResult);
}

VOID MainView::
PostNcDestroy()
{
    DbgConPrt(LightGreen, TEXT("MainView::PostNcDestroy\n"));
    CWnd::PostNcDestroy();
}

BOOL MainView::
PreCreateWindow(CREATESTRUCT &cs)
{
    DbgConPrt(LightGreen, TEXT("MainView::PreCreateWindow\n"));
    return CWnd::PreCreateWindow(cs);
}

#// Message Handlers

INT MainView::
OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CWnd::OnCreate(lpCreateStruct) == -1)
        return -1;
    DbgConPrt(LightGreen, TEXT("MainView::OnCreate\n"));
    return 0;
}

VOID MainView::
OnCommand5()
{
    DbgConPrt(LightGreen, TEXT("MainView::OnCommand5\n"));
}

VOID MainView::
OnCommand6()
{
    DbgConPrt(LightGreen, TEXT("MainView::OnCommand6\n"));
}

VOID MainView::
OnCommand7()
{
    DbgConPrt(LightGreen, TEXT("MainView::OnCommand7\n"));
}

VOID MainView::
OnContextMenu(CWnd *pWnd, CPoint point)
{
    DbgConPrt(LightGreen, TEXT("MainView::OnContextMenu\n"));

    CMenu menu;
    menu.LoadMenu(IDM_MAIN_FRAME);
    CMenu* pContextMenu = menu.GetSubMenu(3);
    pContextMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_TOPALIGN, point.x, point.y, pWnd->GetParent());
}

VOID MainView::
OnDestroy()
{
    CWnd::OnDestroy();
    DbgConPrt(LightGreen, TEXT("MainView::OnDestroy\n"));
}

BOOL MainView::
OnEraseBkgnd(CDC *pDC)
{
    DbgConPrt(LightGreen, TEXT("MainView::OnEraseBkgnd\n"));
    return CWnd::OnEraseBkgnd(pDC);
}

VOID MainView::
OnMove(INT x, INT y)
{
    CWnd::OnMove(x, y);
    DbgConPrt(LightGreen, TEXT("MainView::OnMove\n"));
}

VOID MainView::
OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp)
{
    DbgConPrt(LightGreen, TEXT("MainView::OnNcCalcSize\n"));
    CWnd::OnNcCalcSize(bCalcValidRects, lpncsp);
}

BOOL MainView::
OnNcCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (!CWnd::OnNcCreate(lpCreateStruct))
        return FALSE;
    DbgConPrt(LightGreen, TEXT("MainView::OnNcCreate\n"));
    return TRUE;
}

VOID MainView::
OnNcDestroy()
{
    CWnd::OnNcDestroy();
    DbgConPrt(LightGreen, TEXT("MainView::OnNcDestroy\n"));
}

VOID MainView::
OnNcPaint()
{
    CWnd::OnNcPaint();
    DbgConPrt(LightGreen, TEXT("MainView::OnNcPaint\n"));
}

VOID MainView::
OnPaint()
{
    CWnd::OnPaint();
    DbgConPrt(LightGreen, TEXT("MainView::OnPaint\n"));
}

VOID MainView::
OnSize(UINT nType, INT cx, INT cy)
{
    CWnd::OnSize(nType, cx, cy);
    DbgConPrt(LightGreen, TEXT("MainView::OnSize\n"));
}

VOID MainView::
OnShowWindow(BOOL bShow, UINT nStatus)
{
    CWnd::OnShowWindow(bShow, nStatus);
    DbgConPrt(LightGreen, TEXT("MainView::OnShowWindow\n"));
}

VOID MainView::
OnUndefined(UINT nID)
{
    DbgConPrt(LightGreen, TEXT("MainView::OnUndefined %u\n"), nID);
}

VOID MainView::
OnUpdateCommand5(CCmdUI *pCmdUI)
{
    DbgConPrt(LightGreen, TEXT("MainView::OnUpdateCommand5\n"));
}

VOID MainView::
OnUpdateCommand6(CCmdUI *pCmdUI)
{
    DbgConPrt(LightGreen, TEXT("MainView::OnUpdateCommand6\n"));
}

VOID MainView::
OnUpdateCommand7(CCmdUI *pCmdUI)
{
    DbgConPrt(LightGreen, TEXT("MainView::OnUpdateCommand7\n"));
}

VOID MainView::
OnUpdateUndefined(CCmdUI *pCmdUI)
{
    DbgConPrt(LightGreen, TEXT("MainView::OnUpdateUndefined\n"));
}

VOID MainView::
OnWindowPosChanged(WINDOWPOS *lpwndpos)
{
    CWnd::OnWindowPosChanged(lpwndpos);
    DbgConPrt(LightGreen, TEXT("MainView::OnWindowPosChanged\n"));
}

VOID MainView::
OnWindowPosChanging(WINDOWPOS *lpwndpos)
{
    CWnd::OnWindowPosChanging(lpwndpos);
    DbgConPrt(LightGreen, TEXT("MainView::OnWindowPosChanging\n"));
}
