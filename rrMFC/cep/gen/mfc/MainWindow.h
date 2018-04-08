//===-- Main Window ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 主窗口（类）。
///
/// \verison 2018-04-08
/// \since 2017-12-08
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief 主窗口（类）。
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cframewnd-class
class MainWindow: public CFrameWnd {
    DECLARE_DYNCREATE(MainWindow)
public:
    MainWindow();

// Attributes
public:

// Operations
public:

// Overrides
public:

// Implementation
public:

// Generated message map functions
protected:
    DECLARE_MESSAGE_MAP()
public:
    /// \brief On Paint
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onpaint
    afx_msg VOID OnPaint();
};
