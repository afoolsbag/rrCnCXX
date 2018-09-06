/// \copyright The Unlicense

#include "stdafx.h"
#include "View.h"
#include "Frame.rc.h"

#include "rrwindows/rrwindows.h"

namespace rrMFC {

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
    DcMeth();
}

View::
~View()
{
    DcMeth();
}

#// Overridables

BOOL View::
OnCmdMsg(UINT nID, INT nCode, VOID *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo)
{
    DcCmdMsg();
    return CWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

BOOL View::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
    DcWndMsg();
    return CWnd::OnWndMsg(message, wParam, lParam, pResult);
}

#// Message Handlers

VOID View::
OnContextMenu(CWnd *pWnd, CPoint point)
{
    DcMeth();
    CMenu menu;
    menu.LoadMenu(IDM_FRAME);
    CMenu* pContextMenu = menu.GetSubMenu(3);
    pContextMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_TOPALIGN, point.x, point.y, pWnd->GetParent());
}

VOID View::
OnCommand5()
{
    DcMeth();
}

VOID View::
OnUpdateCommand5(CCmdUI *pCmdUI)
{
    DcMeth();
}

VOID View::
OnCommand6()
{
    DcMeth();
}

VOID View::
OnUpdateCommand6(CCmdUI *pCmdUI)
{
    DcMeth();
}

VOID View::
OnCommand7()
{
    DcMeth();
}

VOID View::
OnUpdateCommand7(CCmdUI *pCmdUI)
{
    DcMeth();
}

VOID View::
OnUndefined(UINT nID)
{
    DcMeth();
}

VOID View::
OnUpdateUndefined(CCmdUI *pCmdUI)
{
    DcMeth();
}

}//namespace rrMFC
