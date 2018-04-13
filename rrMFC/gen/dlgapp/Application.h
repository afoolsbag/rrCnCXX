//===-- Application ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 应用（类）。
///
/// \verison 2018-04-13
/// \since 2018-04-04
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

#// Operations
public:

#// Overridables
public:
    virtual ~Application();
protected:
    virtual BOOL InitApplication();
    virtual BOOL InitInstance();
    virtual INT ExitInstance();

#// Implementation
protected:

#// Message Handlers
protected:
};
