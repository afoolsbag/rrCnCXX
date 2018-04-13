/// \copyright The MIT License

#include "stdafx.h"
#include "MainFrame.h"

#include <conio.h>

#include "../sysmsgstr.inl"

IMPLEMENT_DYNCREATE(MainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(MainFrame, CFrameWnd)
    ON_WM_CREATE()
    ON_WM_SETFOCUS()
END_MESSAGE_MAP()

MainFrame::MainFrame()
{
    _cputts(TEXT("MainFrame::Constructor\n"));
}

MainFrame::~MainFrame()
{
    _cputts(TEXT("MainFrame::Destructor\n"));
}

BOOL MainFrame::OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
    _tcprintf_s(TEXT("MainFrame::OnWndMsg 0x%04X(%s), with %u, %ld, 0x%p\n"), message, SysMsgStr(message), wParam, lParam, pResult);
    return CFrameWnd::OnWndMsg(message, wParam, lParam, pResult);
}

BOOL MainFrame::PreCreateWindow(CREATESTRUCT &cs)
{
    _cputts(TEXT("MainFrame::PreCreateWindow\n"));
    return CFrameWnd::PreCreateWindow(cs);
}

BOOL MainFrame::OnCmdMsg(UINT nID, INT nCode, VOID *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo)
{
    _cputts(TEXT("MainFrame::OnCmdMsg\n"));
    if (View.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
        return TRUE;
    return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

INT MainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
        return -1;
    _cputts(TEXT("MainFrame <WM_CREATE\n"));
    if (!View.Create(NULL, NULL,
                     AFX_WS_DEFAULT_VIEW, CRect(0, 0, 0, 0),
                     this, AFX_IDW_PANE_FIRST, NULL))
        return -1;
    return 0;
}

void MainFrame::OnSetFocus(CWnd *pOldWnd)
{
#if TRUE
    View.SetFocus();
#else
    CFrameWnd::OnSetFocus(pOldWnd);
#endif
}


