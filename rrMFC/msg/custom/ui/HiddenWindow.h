//===-- Main Window ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 隐藏的窗口（类）。
///
/// \verison 2018-04-11
/// \since 2018-04-10
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief 隐藏的窗口（类）。
class HiddenWindow: public CFrameWnd {
    DECLARE_DYNCREATE(HiddenWindow)

#// Constructors
public:
    HiddenWindow();

#// Attributes
public:

#// Operations
public:

#// Overridables
protected:

#// Implementation
protected:

#// Message Handlers
protected:
    afx_msg INT OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg LRESULT OnCustomPrivateMessage(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnCustomApplicationMessage(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnCustomRegisterMessage(WPARAM wParam, LPARAM lParam);

    DECLARE_MESSAGE_MAP()
public:
};
