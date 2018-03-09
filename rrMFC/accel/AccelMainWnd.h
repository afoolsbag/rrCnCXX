//===-- Class Accel Main Window ---------------------------------*- C++ -*-===//
///
/// \file
/// \brief Accel主窗口类
///
/// \author zhengrr
/// \date 2018-2-12
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief Class Accel Main Window
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cframewnd-class
class CAccelMainWnd: public CFrameWnd {
public:
    CAccelMainWnd();

protected:
    INT ribbon_width_ {0};
    INT cell_width_ {0};
    INT cell_height_ {0};
    INT sheet_width_ {0};
    INT sheet_height_ {0};
    INT client_width_ {0};    ///< client area width
    INT client_height_ {0};   ///< client area height
    INT hrz_scroll_pos_ {0};  ///< horizontal scroll position
    INT vrt_scroll_pos_ {0};  ///< vertical scroll position

    /// \brief On Create
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#oncreate
    afx_msg INT OnCreate(LPCREATESTRUCT lpCreateStruct);

    /// \brief On Size
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onsize
    afx_msg VOID OnSize(UINT nType, INT cx, INT cy);

    /// \brief On Paint
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onpaint
    afx_msg VOID OnPaint();

    /// \brief On Horizontal Scroll
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onhscroll
    afx_msg VOID OnHScroll(UINT nSBCode, UINT nPos, CScrollBar *pScrollBar);

    /// \brief On Vertical Scroll
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onvscroll
    afx_msg VOID OnVScroll(UINT nSBCode, UINT nPos, CScrollBar *pScrollBar);

    DECLARE_MESSAGE_MAP()
};
