//===-- Main Window ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 主窗口（类）。
///
/// \verison 2018-04-11
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

// Constructors
public:
    MainWindow();

// Attributes
public:

// Operations
public:

// Overridables
protected:

// Implementation
protected:

// Message Handlers
protected:
    /// \brief On Paint
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onpaint
    afx_msg VOID OnPaint();

    DECLARE_MESSAGE_MAP()
};
