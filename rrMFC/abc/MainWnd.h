//===-- Class Main Window ---------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 主窗口类。
///
/// \verison 2018-04-04
/// \since 2017-12-08
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief Class Main Window
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cframewnd-class
class CMainWnd: public CFrameWnd {
public:
    CMainWnd();

protected:
    /// \brief On Paint
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onpaint
    afx_msg VOID OnPaint();

    DECLARE_MESSAGE_MAP()
};
