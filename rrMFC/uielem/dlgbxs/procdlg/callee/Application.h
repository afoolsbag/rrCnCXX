//===-- Application ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 应用（类）。
///
/// \verison 2018-04-24
/// \since 2018-04-23
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief 应用（类）。
class Application: public CWinApp {
    DECLARE_DYNCREATE(Application)

#// Constructors
public:
    Application();

#// Attributes
public:
    CObject *HostDlgDecay = NULL;
    CObject *GuestDlgDecay = NULL;

#// Operations
public:

#// Overridables
public:
    virtual ~Application();

protected:
    virtual BOOL InitInstance();
    virtual INT ExitInstance();

#// Implementation
protected:

#// Message Handlers
protected:
};
