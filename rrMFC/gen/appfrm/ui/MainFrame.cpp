/// \copyright The MIT License

#include "stdafx.h"
#include "MainFrame.h"

#include "utils/dbgcon.h"

IMPLEMENT_DYNCREATE(MainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(MainFrame, CFrameWnd)
    ON_WM_CREATE()
    ON_WM_SETFOCUS()
END_MESSAGE_MAP()

#// Constructors

MainFrame::
MainFrame()
{
    DbgConPrt(Yellow, TEXT("MainFrame::"));
    DbgConPrt(LightYellow, TEXT("Constructor\n"));
}

MainFrame::
~MainFrame()
{
    DbgConPrt(Yellow, TEXT("MainFrame::"));
    DbgConPrt(LightYellow, TEXT("MainFrame::Destructor\n"));
}

#// Overridables

BOOL MainFrame::
PreCreateWindow(CREATESTRUCT &cs)
{
    DbgConPrt(Yellow, TEXT("MainFrame::"));
    DbgConPrt(LightYellow, TEXT("PreCreateWindow\n"));
    cs.cx = 400;
    cs.cy = 300;
    return CFrameWnd::PreCreateWindow(cs);
}

BOOL MainFrame::
OnCmdMsg(UINT nID, INT nCode, VOID *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo)
{
    DbgConPrt(Yellow, TEXT("MainFrame::"));
    DbgConPrtCmdMsg(LightYellow, TEXT("OnCmdMsg"), nID, nCode, pExtra, pHandlerInfo);
    if (View.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
        return TRUE;
    return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

BOOL MainFrame::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
    DbgConPrt(Yellow, TEXT("MainFrame::"));
    DbgConPrtWndMsg(Yellow, TEXT("OnWndMsg"), message, wParam, lParam, pResult);
    return CFrameWnd::OnWndMsg(message, wParam, lParam, pResult);
}

#// Message Handlers

INT MainFrame::
OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
        return -1;
    DbgConPrt(Yellow, TEXT("MainFrame::"));
    DbgConPrt(LightYellow, TEXT("OnCreate\n"));
    if (!View.Create(NULL, NULL,
                     AFX_WS_DEFAULT_VIEW, CRect(0, 0, 0, 0),
                     this, AFX_IDW_PANE_FIRST, NULL))
        return -1;
    return 0;
}

VOID MainFrame::
OnSetFocus(CWnd *pOldWnd)
{
    DbgConPrt(Yellow, TEXT("MainFrame::"));
    DbgConPrt(LightYellow, TEXT("OnSetFocus\n"));
    View.SetFocus();
}
