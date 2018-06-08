//===-- Custom Message Application ------------------------------*- C++ -*-===//
///
/// \file
/// \brief 自定义消息应用（类）。
///
/// \verison 2018-06-08
/// \since 2018-04-10
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#// Register Messages
extern UINT RM_CUSTOM_REGISTER_MESSAGE;

#// Application Messages
#define AM_CUSTOM_APPLICATION_MESSAGE (WM_APP + 1)

/// \brief 自定义消息应用（类）。
class CustomMessageApplication: public CWinApp {
    DECLARE_DYNAMIC(CustomMessageApplication)

#// Constructors
public:
    CustomMessageApplication();
    virtual ~CustomMessageApplication() override;

#// Attributes
public:

#// Operations
public:

#// Overridables
protected:
    virtual BOOL InitInstance() override;

#// Implementation
protected:

#// Message Handlers
protected:
};
