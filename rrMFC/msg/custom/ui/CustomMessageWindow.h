//===-- Custom Message Window -----------------------------------*- C++ -*-===//
///
/// \file
/// \brief 自定义消息窗口（类）。
///
/// \verison 2018-06-08
/// \since 2018-04-10
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief 自定义消息窗口（类）。
class CustomMessageWindow: public CWnd {
    DECLARE_DYNAMIC(CustomMessageWindow)

#// Constructors
public:
    CustomMessageWindow();
    virtual ~CustomMessageWindow() override;

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
};
