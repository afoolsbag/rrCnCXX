/// \copyright The MIT License

#include "stdafx.h"
#include "MainView.h"

#include <conio.h>

#include "../concol.inl"
#include "../sysmsgstr.inl"

#include "resource.h"

IMPLEMENT_DYNCREATE(MainView, CWnd)

BEGIN_MESSAGE_MAP(MainView, CWnd)
    ON_WM_NCCREATE()
    ON_WM_NCCALCSIZE()
    ON_WM_CREATE()
    ON_WM_SIZE()
    ON_WM_MOVE()
    ON_WM_SHOWWINDOW()
    ON_WM_WINDOWPOSCHANGING()
    ON_WM_WINDOWPOSCHANGED()
    ON_WM_NCPAINT()
    ON_WM_ERASEBKGND()
    ON_WM_PAINT()

    ON_WM_DESTROY()
    ON_WM_NCDESTROY()

    ON_COMMAND(ID_COMMAND_5, &MainView::OnCommand5)
    ON_UPDATE_COMMAND_UI(ID_COMMAND_5, &MainView::OnUpdateCommand5)
    ON_COMMAND(ID_COMMAND_6, &MainView::OnCommand6)
    ON_UPDATE_COMMAND_UI(ID_COMMAND_6, &MainView::OnUpdateCommand6)
    ON_COMMAND(ID_COMMAND_7, &MainView::OnCommand7)
    ON_UPDATE_COMMAND_UI(ID_COMMAND_7, &MainView::OnUpdateCommand7)
    ON_COMMAND_RANGE(ID_UNDEFINED, ID_RANGELAST, &MainView::OnUndefined)
    ON_UPDATE_COMMAND_UI_RANGE(ID_UNDEFINED, ID_RANGELAST, &MainView::OnUpdateUndefined)
    ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()

MainView::MainView()
{
    SetConsoleForeFroundColor(LightGreen);
    _cputts(TEXT("MainView::Constructor\n"));
}

MainView::~MainView()
{
    SetConsoleForeFroundColor(LightGreen);
    _cputts(TEXT("MainView::Destructor\n"));
}

BOOL MainView::PreCreateWindow(CREATESTRUCT &cs)
{
    SetConsoleForeFroundColor(LightGreen);
    _cputts(TEXT("MainView::PreCreateWindow\n"));
    return CWnd::PreCreateWindow(cs);
}

BOOL MainView::OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
    SetConsoleForeFroundColor(Green);
    _tcprintf_s(TEXT("MainView::OnWndMsg 0x%04X(%s), with %u, %ld, 0x%p\n"), message, SysMsgStr(message), wParam, lParam, pResult);
    return CWnd::OnWndMsg(message, wParam, lParam, pResult);
}

VOID MainView::PostNcDestroy()
{
    SetConsoleForeFroundColor(LightGreen);
    _cputts(TEXT("MainView::PostNcDestroy\n"));
    CWnd::PostNcDestroy();
}

BOOL MainView::OnNcCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (!CWnd::OnNcCreate(lpCreateStruct))
        return FALSE;
    SetConsoleForeFroundColor(LightGreen);
    _cputts(TEXT("MainView::OnNcCreate\n"));
    return TRUE;
}

VOID MainView::OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp)
{
    SetConsoleForeFroundColor(LightGreen);
    _cputts(TEXT("MainView::OnNcCalcSize\n"));
    CWnd::OnNcCalcSize(bCalcValidRects, lpncsp);
}

INT MainView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CWnd::OnCreate(lpCreateStruct) == -1)
        return -1;
    SetConsoleForeFroundColor(LightGreen);
    _cputts(TEXT("MainView::OnCreate\n"));
    return 0;
}

VOID MainView::OnSize(UINT nType, INT cx, INT cy)
{
    CWnd::OnSize(nType, cx, cy);
    SetConsoleForeFroundColor(LightGreen);
    _cputts(TEXT("MainView::OnSize\n"));
}

VOID MainView::OnMove(INT x, INT y)
{
    CWnd::OnMove(x, y);
    SetConsoleForeFroundColor(LightGreen);
    _cputts(TEXT("MainView::OnMove\n"));
}

VOID MainView::OnShowWindow(BOOL bShow, UINT nStatus)
{
    CWnd::OnShowWindow(bShow, nStatus);
    SetConsoleForeFroundColor(LightGreen);
    _cputts(TEXT("MainView::OnShowWindow\n"));
}

VOID MainView::OnWindowPosChanging(WINDOWPOS *lpwndpos)
{
    CWnd::OnWindowPosChanging(lpwndpos);
    SetConsoleForeFroundColor(LightGreen);
    _cputts(TEXT("MainView::OnWindowPosChanging\n"));
}

VOID MainView::OnWindowPosChanged(WINDOWPOS *lpwndpos)
{
    CWnd::OnWindowPosChanged(lpwndpos);
    SetConsoleForeFroundColor(LightGreen);
    _cputts(TEXT("MainView::OnWindowPosChanged\n"));
}

VOID MainView::OnNcPaint()
{
    CWnd::OnNcPaint();
    SetConsoleForeFroundColor(LightGreen);
    _cputts(TEXT("MainView::OnNcPaint\n"));
}

BOOL MainView::OnEraseBkgnd(CDC *pDC)
{
    SetConsoleForeFroundColor(LightGreen);
    _cputts(TEXT("MainView::OnEraseBkgnd\n"));
    return CWnd::OnEraseBkgnd(pDC);
}

VOID MainView::OnPaint()
{
    CWnd::OnPaint();
    SetConsoleForeFroundColor(LightGreen);
    _cputts(TEXT("MainView::OnPaint\n"));
}

VOID MainView::OnDestroy()
{
    CWnd::OnDestroy();
    SetConsoleForeFroundColor(LightGreen);
    _cputts(TEXT("MainView::OnDestroy\n"));
}

VOID MainView::OnNcDestroy()
{
    CWnd::OnNcDestroy();
    SetConsoleForeFroundColor(LightGreen);
    _cputts(TEXT("MainView::OnNcDestroy\n"));
}

VOID MainView::OnCommand5()
{
    SetConsoleForeFroundColor(LightGreen);
    _cputts(TEXT("MainView::OnCommand5\n"));
}

VOID MainView::OnUpdateCommand5(CCmdUI *pCmdUI)
{
    SetConsoleForeFroundColor(LightGreen);
    _cputts(TEXT("MainView::OnUpdateCommand5\n"));
}

VOID MainView::OnCommand6()
{
    SetConsoleForeFroundColor(LightGreen);
    _cputts(TEXT("MainView::OnCommand6\n"));
}

VOID MainView::OnUpdateCommand6(CCmdUI *pCmdUI)
{
    SetConsoleForeFroundColor(LightGreen);
    _cputts(TEXT("MainView::OnUpdateCommand6\n"));
}

VOID MainView::OnCommand7()
{
    SetConsoleForeFroundColor(LightGreen);
    _cputts(TEXT("MainView::OnCommand7\n"));
}

VOID MainView::OnUpdateCommand7(CCmdUI *pCmdUI)
{
    SetConsoleForeFroundColor(LightGreen);
    _cputts(TEXT("MainView::OnUpdateCommand7\n"));
}

VOID MainView::OnUndefined(UINT nID)
{
    SetConsoleForeFroundColor(LightGreen);
    _tcprintf_s(TEXT("MainView::OnUndefined %u\n"), nID);
}

VOID MainView::OnUpdateUndefined(CCmdUI *pCmdUI)
{
    SetConsoleForeFroundColor(LightGreen);
    _cputts(TEXT("MainView::OnUpdateUndefined\n"));
}

VOID MainView::OnContextMenu(CWnd *pWnd, CPoint point)
{
    SetConsoleForeFroundColor(LightGreen);
    _cputts(TEXT("MainView::OnContextMenu\n"));

    CMenu menu;
    menu.LoadMenu(IDM_MAIN_FRAME);
    CMenu* pContextMenu = menu.GetSubMenu(3);
    pContextMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_TOPALIGN, point.x, point.y, pWnd->GetParent());
}
