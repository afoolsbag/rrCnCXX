/// \copyright The MIT License

#include "stdafx.h"
#include "MainView.h"

#include "rrwindows/dbgcon.h"

#include "resource.h"

IMPLEMENT_DYNCREATE(MainView, CWnd)

BEGIN_MESSAGE_MAP(MainView, CWnd)
    ON_WM_CONTEXTMENU()

    ON_COMMAND(ID_COMMAND_5, &MainView::OnCommand5)
    ON_UPDATE_COMMAND_UI(ID_COMMAND_5, &MainView::OnUpdateCommand5)
    ON_COMMAND(ID_COMMAND_6, &MainView::OnCommand6)
    ON_UPDATE_COMMAND_UI(ID_COMMAND_6, &MainView::OnUpdateCommand6)
    ON_COMMAND(ID_COMMAND_7, &MainView::OnCommand7)
    ON_UPDATE_COMMAND_UI(ID_COMMAND_7, &MainView::OnUpdateCommand7)
    ON_COMMAND_RANGE(ID_UNDEFINED, ID_RANGELAST, &MainView::OnUndefined)
    ON_UPDATE_COMMAND_UI_RANGE(ID_UNDEFINED, ID_RANGELAST, &MainView::OnUpdateUndefined)
END_MESSAGE_MAP()

#// Constructors

MainView::
MainView()
{
    DbgConPrtMeth(Green);
}

MainView::
~MainView()
{
    DbgConPrtMeth(Green);
}

#// Overridables

BOOL MainView::
OnCmdMsg(UINT nID, INT nCode, VOID *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo)
{
    DbgConPrtMethCmdMsg(Green);
    return CWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

BOOL MainView::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
    DbgConPrtMethWndMsg(Green);
    return CWnd::OnWndMsg(message, wParam, lParam, pResult);
}

#// Message Handlers

VOID MainView::
OnContextMenu(CWnd *pWnd, CPoint point)
{
    DbgConPrtMeth(Green);
    CMenu menu;
    menu.LoadMenu(IDM_MAIN_FRAME);
    CMenu* pContextMenu = menu.GetSubMenu(3);
    pContextMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_TOPALIGN, point.x, point.y, pWnd->GetParent());
}

VOID MainView::
OnCommand5()
{
    DbgConPrtMeth(Green);
}

VOID MainView::
OnUpdateCommand5(CCmdUI *pCmdUI)
{
    DbgConPrtMeth(Green);
}

VOID MainView::
OnCommand6()
{
    DbgConPrtMeth(Green);
}

VOID MainView::
OnUpdateCommand6(CCmdUI *pCmdUI)
{
    DbgConPrtMeth(Green);
}

VOID MainView::
OnCommand7()
{
    DbgConPrtMeth(Green);
}

VOID MainView::
OnUpdateCommand7(CCmdUI *pCmdUI)
{
    DbgConPrtMeth(Green);
}

VOID MainView::
OnUndefined(UINT nID)
{
    DbgConPrtMeth(Green);
}

VOID MainView::
OnUpdateUndefined(CCmdUI *pCmdUI)
{
    DbgConPrtMeth(Green);
}
