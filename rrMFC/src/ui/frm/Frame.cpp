/// \copyright The Unlicense

#include "stdafx.h"
#include "Frame.h"
#include "Frame.rc.h"

#include "rrwindows/rrwindows.h"

namespace rrMFC {

const UINT Frame::IDR {IDR_FRAME};

BEGIN_MESSAGE_MAP(Frame, CFrameWnd)
    ON_WM_CREATE()
    ON_WM_SETFOCUS()
END_MESSAGE_MAP()

#// Constructorsa

Frame::
Frame()
{
    DcMeth();
}

Frame::
~Frame()
{
    DcMeth();
}

#// Overridables

BOOL Frame::
PreCreateWindow(CREATESTRUCT &cs)
{
    DcMeth();
    cs.cx = 400;
    cs.cy = 300;
    return CFrameWnd::PreCreateWindow(cs);
}

BOOL Frame::
OnCmdMsg(UINT nID, INT nCode, VOID *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo)
{
    DcCmdMsg();
    if (View.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
        return TRUE;
    return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

BOOL Frame::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
    DcWndMsg();
    return CFrameWnd::OnWndMsg(message, wParam, lParam, pResult);
}

#// Message Handlers

INT Frame::
OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
        return -1;
    DcMeth();
    if (!View.Create(NULL, NULL,
                     AFX_WS_DEFAULT_VIEW, CRect(0, 0, 0, 0),
                     this, AFX_IDW_PANE_FIRST, NULL))
        return -1;
    return 0;
}

VOID Frame::
OnSetFocus(CWnd *pOldWnd)
{
    DcMeth();
    View.SetFocus();
}

}//namespace rrMFC
