//===-- Class Frame Main Window ---------------------------------*- C++ -*-===//
///
/// \file
/// \brief 框架（主窗口）主窗口类
///
/// \author zhengrr
/// \date 2017-12-8 – 2018-2-11
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief Class (Frame App) Main Window
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cframewnd-class
class CFrameMainWnd: public CFrameWnd {
public:
    CFrameMainWnd();

protected:
    /// \brief On Paint
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onpaint
    afx_msg VOID OnPaint();

    DECLARE_MESSAGE_MAP()
};
