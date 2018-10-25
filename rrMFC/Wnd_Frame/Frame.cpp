/// \copyright The Unlicense

#include "stdafx.h"
#include "Frame.h"
#include "ui.rc.h"

namespace rrMFC {

BEGIN_MESSAGE_MAP(Frame, CFrameWnd)
    ON_WM_CREATE()
    ON_WM_SETFOCUS()
END_MESSAGE_MAP()

// Attributes

const unsigned Frame::IDR {IDR_FRAME};

// Overridables

BOOL Frame::
PreCreateWindow(CREATESTRUCT &cs)
{
    TRACE(__FUNCTION__ "\n");
    cs.cx = 400;
    cs.cy = 300;
    return CFrameWnd::PreCreateWindow(cs);
}

BOOL Frame::
OnCmdMsg(unsigned nID, int nCode, void *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo)
{
    TRACE(__FUNCTION__ "\n");
    if (View.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
        return TRUE;
    return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

// Message Handlers

int Frame::
OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
        return -1;
    TRACE(__FUNCTION__ "\n");
    if (!View.Create(nullptr, nullptr,
                     AFX_WS_DEFAULT_VIEW, CRect(0, 0, 0, 0),
                     this, AFX_IDW_PANE_FIRST, nullptr))
        return -1;
    return 0;
}

void Frame::
OnSetFocus(CWnd *pOldWnd)
{
    TRACE(__FUNCTION__ "\n");
    View.SetFocus();
}

}//namespace rrMFC
