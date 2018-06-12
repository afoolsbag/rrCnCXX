//===-- Window Application --------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 窗口应用（类）。
///
/// \version 2018-06-12
/// \since 2018-04-27
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#// Register Messages

/// \brief 定制注册消息。
extern UINT RM_CUSTOM_REGISTER_MESSAGE;

#// Application Messages

/// \brief 定制应用消息。
#define AM_CUSTOM_APPLICATION_MESSAGE (WM_APP + 1)

///
/// \brief 窗口应用（类）。
///
class WindowApplication: public CWinApp {

#// Constructors
public:
    WindowApplication();
    virtual ~WindowApplication() override;

#// Attributes
public:

#// Operations
public:

#// Overridables
public:
    virtual BOOL InitInstance() override;

#// Implementation
protected:

#// Message Handlers
protected:

};
