/// \copyright The MIT License

#include "stdafx.h"
#include "MainFrame.h"

#include <conio.h>

#include "../sysmsgstr.inl"

IMPLEMENT_DYNCREATE(MainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(MainFrame, CFrameWnd)
    ON_WM_NCCREATE()
    ON_WM_NCCALCSIZE()
    ON_WM_CREATE()
    ON_WM_PARENTNOTIFY()
    ON_WM_SHOWWINDOW()

    ON_WM_CLOSE()
    ON_WM_DESTROY()
    ON_WM_NCDESTROY()

    ON_WM_SETFOCUS()
END_MESSAGE_MAP()

MainFrame::MainFrame()
{
    _cputts(TEXT("\tMainFrame::Constructor\n"));
}

MainFrame::~MainFrame()
{
    _cputts(TEXT("\tMainFrame::Destructor\n"));
}

BOOL MainFrame::OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
    _tcprintf_s(TEXT("\tMainFrame::OnWndMsg 0x%04X(%s), with %u, %ld, 0x%p\n"), message, SysMsgStr(message), wParam, lParam, pResult);
    return CFrameWnd::OnWndMsg(message, wParam, lParam, pResult);
}

BOOL MainFrame::PreCreateWindow(CREATESTRUCT &cs)
{
    _cputts(TEXT("\tMainFrame::PreCreateWindow\n"));
    return CFrameWnd::PreCreateWindow(cs);
}

BOOL MainFrame::OnCmdMsg(UINT nID, INT nCode, VOID *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo)
{
    _cputts(TEXT("\tMainFrame::OnCmdMsg\n"));
    if (View.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
        return TRUE;
    return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

BOOL MainFrame::OnNcCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (!CFrameWnd::OnNcCreate(lpCreateStruct))
        return FALSE;
    _cputts(TEXT("\tMainFrame::OnNcCreate\n"));
    return TRUE;
}

VOID MainFrame::OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS *lpncsp)
{
    _cputts(TEXT("\tMainFrame::OnNcCalcSize\n"));
    CFrameWnd::OnNcCalcSize(bCalcValidRects, lpncsp);
}

INT MainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
        return -1;
    _cputts(TEXT("\tMainFrame::OnCreate\n"));
    if (!View.Create(NULL, NULL,
                     AFX_WS_DEFAULT_VIEW, CRect(0, 0, 0, 0),
                     this, AFX_IDW_PANE_FIRST, NULL))
        return -1;
    return 0;
}

VOID MainFrame::OnParentNotify(UINT message, LPARAM lParam)
{
    CFrameWnd::OnParentNotify(message, lParam);
    _cputts(TEXT("\tMainFrame::OnParentNotify\n"));
}

VOID MainFrame::OnShowWindow(BOOL bShow, UINT nStatus)
{
    CFrameWnd::OnShowWindow(bShow, nStatus);
    _cputts(TEXT("\tMainFrame::OnShowWindow\n"));
}

VOID MainFrame::OnClose()
{
    _cputts(TEXT("\tMainFrame::OnClose\n"));
    CFrameWnd::OnClose();
}

VOID MainFrame::OnDestroy()
{
    CFrameWnd::OnDestroy();
    _cputts(TEXT("\tMainFrame::OnDestroy\n"));
}

VOID MainFrame::OnNcDestroy()
{
    CFrameWnd::OnNcDestroy();
    _cputts(TEXT("\tMainFrame::OnNcDestroy\n"));
}

VOID MainFrame::OnSetFocus(CWnd *pOldWnd)
{
#if TRUE
    View.SetFocus();
#else
    CFrameWnd::OnSetFocus(pOldWnd);
#endif
}

