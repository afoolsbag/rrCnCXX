//===-- Application ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 应用（类）。
///
/// \verison 2018-04-10
/// \since 2018-04-10
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#// Application Messages
#define AM_CUSTOM_APPLICATION_MESSAGE (WM_APP + 1)

/// \brief 应用（类）。
class Application: public CWinApp {
    DECLARE_DYNCREATE(Application)

#// Constructors
public:

#// Attributes
public:

#// Operations
public:

#// Overridables
protected:
    virtual BOOL InitInstance();

#// Implementation
protected:

#// Message Handlers
protected:
};
