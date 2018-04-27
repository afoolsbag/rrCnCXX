//===-- Application ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 应用（类）。
///
/// \version 2018-04-27
/// \since 2018-04-27
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

    virtual ~Application();

#// Attributes
public:

#// Operations
public:

#// Overridables
public:
    virtual BOOL InitInstance();

#// Implementation
protected:

#// Message Handlers
protected:
};
