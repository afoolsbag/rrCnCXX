/// \copyright The Unlicense

#include "stdafx.h"
#include "Frame.h"
#include "Frame.rc.h"

#include "rrwindows/rrwindows.h"

namespace rrMFC {
namespace Test {

const unsigned Frame::IDR {IDR_FRAME};

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
OnCmdMsg(unsigned nID, int nCode, void *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo)
{
    DcCmdMsg();
    if (View.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
        return TRUE;
    return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

BOOL Frame::
OnWndMsg(unsigned message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
    DcWndMsg();
    return CFrameWnd::OnWndMsg(message, wParam, lParam, pResult);
}

#// Message Handlers

int Frame::
OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
        return -1;
    DcMeth();
    if (!View.Create(nullptr, nullptr,
                     AFX_WS_DEFAULT_VIEW, CRect(0, 0, 0, 0),
                     this, AFX_IDW_PANE_FIRST, nullptr))
        return -1;
    return 0;
}

void Frame::
OnSetFocus(CWnd *pOldWnd)
{
    DcMeth();
    View.SetFocus();
}

}//namespace Test
}//namespace rrMFC
