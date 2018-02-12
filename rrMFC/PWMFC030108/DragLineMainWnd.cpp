/// \copyright The MIT License

#include "stdafx.h"
#include "DragLineMainWnd.h"

BEGIN_MESSAGE_MAP(CDragLineMainWnd, CFrameWnd)
    ON_WM_LBUTTONDOWN()
    ON_WM_MOUSEMOVE()
    ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

CDragLineMainWnd::CDragLineMainWnd()
{
    Create(NULL, TEXT("The DragLine Application"));
}

VOID CDragLineMainWnd::OnLButtonDown(UINT flags, CPoint point)
{
    if (!dragging_) {
        drag_point_ = point;
        temp_point_ = point;
        dragging_ = TRUE;
        SetCapture();
    }

    CWnd::OnLButtonDown(flags, point);
}

VOID CDragLineMainWnd::OnMouseMove(UINT flags, CPoint point)
{
    if (dragging_) {
        CClientDC dvcctx(this);
        CONST INT oldmode = dvcctx.SetROP2(R2_NOT);

        // 擦除上一临时线段
        dvcctx.MoveTo(drag_point_);
        dvcctx.LineTo(temp_point_);

        // 绘制当前临时线段
        dvcctx.MoveTo(drag_point_);
        dvcctx.LineTo(point);

        dvcctx.SetROP2(oldmode);

        temp_point_ = point;
    }

    CWnd::OnMouseMove(flags, point);
}

VOID CDragLineMainWnd::OnLButtonUp(UINT flags, CPoint point)
{
    if (dragging_) {
        drop_point_ = point;
        dragging_ = FALSE;
        if (GetCapture() == this)
            ReleaseCapture();

        CClientDC dvcctx(this);
        CONST INT oldmode = dvcctx.SetROP2(R2_NOT);
        // 擦除上一临时线段
        dvcctx.MoveTo(drag_point_);
        dvcctx.LineTo(temp_point_);
        dvcctx.SetROP2(oldmode);

        // 绘制落笔线段
        CPen pen(PS_SOLID, 4, RGB(255, 0, 255)/*品红*/);
        CPen *CONST oldpen = dvcctx.SelectObject(&pen);
        dvcctx.MoveTo(drag_point_);
        dvcctx.LineTo(drop_point_);
        dvcctx.SelectObject(oldpen);
    }

    CWnd::OnLButtonUp(flags, point);
}
