/// \copyright The Unlicense

#include "stdafx.h"
#include "View.h"
#include "Frame.rc.h"

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

// Message Handlers

void View::
OnContextMenu(CWnd *pWnd, CPoint point)
{
    TRACE(__FUNCTION__ "\n");
    CMenu menu;
    menu.LoadMenu(IDM_FRAME);
    CMenu* pContextMenu = menu.GetSubMenu(3);
    pContextMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_TOPALIGN, point.x, point.y, pWnd->GetParent());
}

void View::
OnCommand5()
{
    TRACE(__FUNCTION__ "\n");
}

void View::
OnUpdateCommand5(CCmdUI *pCmdUI)
{
    TRACE(__FUNCTION__ "\n");
}

void View::
OnCommand6()
{
    TRACE(__FUNCTION__ "\n");
}

void View::
OnUpdateCommand6(CCmdUI *pCmdUI)
{
    TRACE(__FUNCTION__ "\n");
}

void View::
OnCommand7()
{
    TRACE(__FUNCTION__ "\n");
}

void View::
OnUpdateCommand7(CCmdUI *pCmdUI)
{
    TRACE(__FUNCTION__ "\n");
}

void View::
OnUndefined(unsigned nID)
{
    TRACE(__FUNCTION__ "\n");
}

void View::
OnUpdateUndefined(CCmdUI *pCmdUI)
{
    TRACE(__FUNCTION__ "\n");
}

}//namespace rrMFC
