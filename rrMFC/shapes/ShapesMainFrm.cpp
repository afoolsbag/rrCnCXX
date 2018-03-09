/// \copyright The MIT License

#include "stdafx.h"
#include "ShapesMainFrm.h"

IMPLEMENT_DYNAMIC(CShapesMainFrm, CFrameWnd)

BEGIN_MESSAGE_MAP(CShapesMainFrm, CFrameWnd)
    ON_WM_CREATE()
    ON_WM_SETFOCUS()
END_MESSAGE_MAP()

CShapesMainFrm::CShapesMainFrm()
{
    ;
}

CShapesMainFrm::~CShapesMainFrm()
{
    ;
}

INT CShapesMainFrm::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
        return -1;

    if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW,
                          CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL)) {
        TRACE0("Failed to create view window\n");
        return -1;
    }
    return 0;
}

BOOL CShapesMainFrm::PreCreateWindow(CREATESTRUCT &cs)
{
    if (!CFrameWnd::PreCreateWindow(cs))
        return FALSE;
    cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
    cs.lpszClass = AfxRegisterWndClass(0);
    return TRUE;
}

void CShapesMainFrm::OnSetFocus(CWnd* pOldWnd)
{
    m_wndView.SetFocus();
}

BOOL CShapesMainFrm::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
    if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
        return TRUE;

    return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}
