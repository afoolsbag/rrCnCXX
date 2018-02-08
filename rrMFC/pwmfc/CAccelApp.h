//===-- Class Accel Application ---------------------------------*- C++ -*-===//
///
/// \defgroup g_pwmfc_accel Accel（§2.3.6）
/// \ingroup g_pwmfc
///
/// \sa *Programming Windows with MFC* §2.3.6
///
/// \author zhengrr
/// \date 2017-12-8 – 2018-2-7
/// \copyright The MIT License
///
/// @{
//===----------------------------------------------------------------------===//

#define VC_EXTRALEAN
#include <afxwin.h>

/// \brief Class Accel Application
class CAccelApp: public CWinApp {
public:
    virtual BOOL InitInstance();
};

/// \brief Class Accel Main Window
class CAccelMainWnd: public CFrameWnd {
public:
    CAccelMainWnd();

protected:

    /// \brief On Create
    ///
    /// \sa ["CWnd::OnCreate"](https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#oncreate). *Microsoft® Docs*.
    afx_msg INT OnCreate(LPCREATESTRUCT lpCreateStruct);

    /// \brief On Size
    ///
    /// \sa ["CWnd::OnSize"](https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onsize). *Microsoft® Docs*.
    afx_msg VOID OnSize(UINT nType, INT cx, INT cy);

    afx_msg VOID OnPaint();

    /// \brief On Horizontal Scroll
    ///
    /// \sa ["CWnd::OnHScroll"](https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onhscroll). *Microsoft® Docs*.
    afx_msg VOID OnHScroll(UINT nCode, UINT nPos, CScrollBar *pScrollBar);

    afx_msg VOID OnVScroll(UINT nCode, UINT nPos, CScrollBar *pScrollBar);

    INT ribbon_width_;    ///< 行头宽度
    INT cell_width_;      ///< 单元格宽度
    INT cell_height_;     ///< 单元格高度
    INT sheet_width_;     ///< 表格宽度
    INT sheet_heigth_;    ///< 表格高度
    INT client_width_;    ///< 用户区宽度
    INT client_height_;   ///< 用户区高度
    INT hrz_scroll_pos_;  ///< 水平滚动条水平位置
    INT vrt_scroll_pos_;  ///< 垂直滚动条垂直位置

    DECLARE_MESSAGE_MAP()
};

/// @}
