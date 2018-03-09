//===-- Class Hello Main Window ---------------------------------*- C++ -*-===//
///
/// \file
/// \brief Hello主窗口类
///
/// \author zhengrr
/// \verison 2018-2-12
/// \since 2017-12-8
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief Class Hello Main Window
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cframewnd-class
class CHelloMainWnd: public CFrameWnd {
public:
    CHelloMainWnd();

protected:
    /// \brief On Paint
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onpaint
    afx_msg VOID OnPaint();

    DECLARE_MESSAGE_MAP()
};
