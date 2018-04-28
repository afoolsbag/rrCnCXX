/// \copyright The MIT License

#include "stdafx.h"
#include "MainView.h"

#include "utils/dbgcon.h"

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
    DbgConPrt(Green, TEXT("MainView::"));
    DbgConPrt(LightGreen, TEXT("Constructor\n"));
}

MainView::
~MainView()
{
    DbgConPrt(Green, TEXT("MainView::"));
    DbgConPrt(LightGreen, TEXT("Destructor\n"));
}

#// Overridables

BOOL MainView::
OnCmdMsg(UINT nID, INT nCode, VOID *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo)
{
    DbgConPrt(Green, TEXT("MainView::"));
    DbgConPrtCmdMsg(LightGreen, TEXT("OnCmdMsg"), nID, nCode, pExtra, pHandlerInfo);
    return CWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

BOOL MainView::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
    DbgConPrt(Green, TEXT("MainView::"));
    DbgConPrtWndMsg(Green, TEXT("OnWndMsg"), message, wParam, lParam, pResult);
    return CWnd::OnWndMsg(message, wParam, lParam, pResult);
}

#// Message Handlers

VOID MainView::
OnContextMenu(CWnd *pWnd, CPoint point)
{
    DbgConPrt(Green, TEXT("MainView::"));
    DbgConPrt(LightGreen, TEXT("OnContextMenu\n"));

    CMenu menu;
    menu.LoadMenu(IDM_MAIN_FRAME);
    CMenu* pContextMenu = menu.GetSubMenu(3);
    pContextMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_TOPALIGN, point.x, point.y, pWnd->GetParent());
}

VOID MainView::
OnCommand5()
{
    DbgConPrt(Green, TEXT("MainView::"));
    DbgConPrt(LightGreen, TEXT("OnCommand5\n"));
}

VOID MainView::
OnUpdateCommand5(CCmdUI *pCmdUI)
{
    DbgConPrt(Green, TEXT("MainView::"));
    DbgConPrt(LightGreen, TEXT("OnUpdateCommand5\n"));
}

VOID MainView::
OnCommand6()
{
    DbgConPrt(Green, TEXT("MainView::"));
    DbgConPrt(LightGreen, TEXT("OnCommand6\n"));
}

VOID MainView::
OnUpdateCommand6(CCmdUI *pCmdUI)
{
    DbgConPrt(Green, TEXT("MainView::"));
    DbgConPrt(LightGreen, TEXT("OnUpdateCommand6\n"));
}

VOID MainView::
OnCommand7()
{
    DbgConPrt(Green, TEXT("MainView::"));
    DbgConPrt(LightGreen, TEXT("OnCommand7\n"));
}

VOID MainView::
OnUpdateCommand7(CCmdUI *pCmdUI)
{
    DbgConPrt(Green, TEXT("MainView::"));
    DbgConPrt(LightGreen, TEXT("OnUpdateCommand7\n"));
}

VOID MainView::
OnUndefined(UINT nID)
{
    DbgConPrt(Green, TEXT("MainView::"));
    DbgConPrt(LightGreen, TEXT("OnUndefined %u\n"), nID);
}

VOID MainView::
OnUpdateUndefined(CCmdUI *pCmdUI)
{
    DbgConPrt(Green, TEXT("MainView::"));
    DbgConPrt(LightGreen, TEXT("OnUpdateUndefined\n"));
}
