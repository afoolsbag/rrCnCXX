/// \copyright The MIT License

#include "stdafx.h"
#include "ShapesChildView.h"

CShapesChildView::CShapesChildView()
{
    m_nShape = 1;
}

CShapesChildView::~CShapesChildView()
{}

BEGIN_MESSAGE_MAP(CShapesChildView, CWnd)
    ON_WM_PAINT()
    ON_COMMAND(ID_SHAPE_CIRCLE, OnShapeCircle)
    ON_COMMAND(ID_SHAPE_TRIANGLE, OnShapeTriangle)
    ON_COMMAND(ID_SHAPE_SQUARE, OnShapeSquare)
    ON_UPDATE_COMMAND_UI(ID_SHAPE_CIRCLE, OnUpdateShapeCircle)
    ON_UPDATE_COMMAND_UI(ID_SHAPE_TRIANGLE, OnUpdateShapeTriangle)
    ON_UPDATE_COMMAND_UI(ID_SHAPE_SQUARE, OnUpdateShapeSquare)
END_MESSAGE_MAP()

BOOL CShapesChildView::PreCreateWindow(CREATESTRUCT& cs)
{
    if (!CWnd::PreCreateWindow(cs))
        return FALSE;

    cs.dwExStyle |= WS_EX_CLIENTEDGE;
    cs.style &= ~WS_BORDER;
    cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
                                       ::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW + 1), NULL);

    return TRUE;
}

void CShapesChildView::OnPaint()
{
    CPoint points[3];
    CPaintDC dc(this);

    CRect rcClient;
    GetClientRect(&rcClient);

    int cx = rcClient.Width() / 2;
    int cy = rcClient.Height() / 2;
    CRect rcShape(cx - 45, cy - 45, cx + 45, cy + 45);

    CBrush brush(RGB(255, 0, 0));
    CBrush* pOldBrush = dc.SelectObject(&brush);

    switch (m_nShape) {

    case 0: // Circle
        dc.Ellipse(rcShape);
        break;

    case 1: // Triangle
        points[0].x = cx - 45;
        points[0].y = cy + 45;
        points[1].x = cx;
        points[1].y = cy - 45;
        points[2].x = cx + 45;
        points[2].y = cy + 45;
        dc.Polygon(points, 3);
        break;

    case 2: // Square
        dc.Rectangle(rcShape);
        break;
    }
    dc.SelectObject(pOldBrush);
}

void CShapesChildView::OnShapeCircle()
{
    m_nShape = 0;
    Invalidate();
}

void CShapesChildView::OnShapeTriangle()
{
    m_nShape = 1;
    Invalidate();
}

void CShapesChildView::OnShapeSquare()
{
    m_nShape = 2;
    Invalidate();
}

void CShapesChildView::OnUpdateShapeCircle(CCmdUI* pCmdUI)
{
    pCmdUI->SetCheck(m_nShape == 0);
}

void CShapesChildView::OnUpdateShapeTriangle(CCmdUI* pCmdUI)
{
    pCmdUI->SetCheck(m_nShape == 1);
}

void CShapesChildView::OnUpdateShapeSquare(CCmdUI* pCmdUI)
{
    pCmdUI->SetCheck(m_nShape == 2);
}
