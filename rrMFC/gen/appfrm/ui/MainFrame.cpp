/// \copyright The MIT License

#include "stdafx.h"
#include "MainFrame.h"

#include "rrwindows/dbgcon.h"

IMPLEMENT_DYNCREATE(MainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(MainFrame, CFrameWnd)
    ON_WM_CREATE()
    ON_WM_SETFOCUS()
END_MESSAGE_MAP()

#// Constructors

MainFrame::
MainFrame()
{
    DbgConPrtMeth(Yellow);
}

MainFrame::
~MainFrame()
{
    DbgConPrtMeth(Yellow);
}

#// Overridables

BOOL MainFrame::
PreCreateWindow(CREATESTRUCT &cs)
{
    DbgConPrtMeth(Yellow);
    cs.cx = 400;
    cs.cy = 300;
    return CFrameWnd::PreCreateWindow(cs);
}

BOOL MainFrame::
OnCmdMsg(UINT nID, INT nCode, VOID *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo)
{
    DbgConPrtMethCmdMsg(Yellow);
    if (View.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
        return TRUE;
    return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

BOOL MainFrame::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
    DbgConPrtMethWndMsg(Yellow);
    return CFrameWnd::OnWndMsg(message, wParam, lParam, pResult);
}

#// Message Handlers

INT MainFrame::
OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
        return -1;
    DbgConPrtMeth(Yellow);
    if (!View.Create(NULL, NULL,
                     AFX_WS_DEFAULT_VIEW, CRect(0, 0, 0, 0),
                     this, AFX_IDW_PANE_FIRST, NULL))
        return -1;
    return 0;
}

VOID MainFrame::
OnSetFocus(CWnd *pOldWnd)
{
    DbgConPrtMeth(Yellow);
    View.SetFocus();
}
