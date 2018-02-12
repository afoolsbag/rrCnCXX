//===-- Class DragLine Main Window ------------------------------*- C++ -*-===//
///
/// \file
/// \brief DragLine主窗口类
///
/// \author zhengrr
/// \date 2018-2-9 – 11
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief Class DragLine Main Window
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cframewnd-class
class CDragLineMainWnd: public CFrameWnd {
public:
    CDragLineMainWnd();

protected:
    BOOL dragging_ {FALSE};
    POINT drag_point_ {0, 0};
    POINT temp_point_ {0, 0};
    POINT drop_point_ {0, 0};

    /// \brief On Left Button Down
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onlbuttondown
    afx_msg VOID OnLButtonDown(UINT nFlags, CPoint point);

    /// \brief On Mouse Move
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onmousemove
    afx_msg VOID OnMouseMove(UINT nFlags, CPoint point);

    /// \brief On Left Button Up
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onlbuttonup
    afx_msg VOID OnLButtonUp(UINT nFlags, CPoint point);

    DECLARE_MESSAGE_MAP()
};
