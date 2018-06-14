/// \copyright The MIT License

#include "stdafx.h"
#include "Vw.h"

#include "rrwindows/dbgcon.h"

#include "resource.h"

BEGIN_MESSAGE_MAP(View, CWnd)
    ON_WM_CONTEXTMENU()

    ON_COMMAND(ID_COMMAND_5, &View::OnCommand5)
    ON_UPDATE_COMMAND_UI(ID_COMMAND_5, &View::OnUpdateCommand5)
    ON_COMMAND(ID_COMMAND_6, &View::OnCommand6)
    ON_UPDATE_COMMAND_UI(ID_COMMAND_6, &View::OnUpdateCommand6)
    ON_COMMAND(ID_COMMAND_7, &View::OnCommand7)
    ON_UPDATE_COMMAND_UI(ID_COMMAND_7, &View::OnUpdateCommand7)
    ON_COMMAND_RANGE(ID_UNDEFINED, ID_RANGELAST, &View::OnUndefined)
    ON_UPDATE_COMMAND_UI_RANGE(ID_UNDEFINED, ID_RANGELAST, &View::OnUpdateUndefined)
END_MESSAGE_MAP()

#// Constructors

View::
View()
{
    DbgConMeth();
}

View::
~View()
{
    DbgConMeth();
}

#// Overridables

BOOL View::
OnCmdMsg(UINT nID, INT nCode, VOID *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo)
{
    DbgConCmdMsg();
    return CWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

BOOL View::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
    DbgConWndMsg();
    return CWnd::OnWndMsg(message, wParam, lParam, pResult);
}

#// Message Handlers

VOID View::
OnContextMenu(CWnd *pWnd, CPoint point)
{
    DbgConMeth();
    CMenu menu;
    menu.LoadMenu(IDM_FRAME);
    CMenu* pContextMenu = menu.GetSubMenu(3);
    pContextMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_TOPALIGN, point.x, point.y, pWnd->GetParent());
}

VOID View::
OnCommand5()
{
    DbgConMeth();
}

VOID View::
OnUpdateCommand5(CCmdUI *pCmdUI)
{
    DbgConMeth();
}

VOID View::
OnCommand6()
{
    DbgConMeth();
}

VOID View::
OnUpdateCommand6(CCmdUI *pCmdUI)
{
    DbgConMeth();
}

VOID View::
OnCommand7()
{
    DbgConMeth();
}

VOID View::
OnUpdateCommand7(CCmdUI *pCmdUI)
{
    DbgConMeth();
}

VOID View::
OnUndefined(UINT nID)
{
    DbgConMeth();
}

VOID View::
OnUpdateUndefined(CCmdUI *pCmdUI)
{
    DbgConMeth();
}
