//===-- Application ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 应用（类）。
///
/// \verison 2018-06-01
/// \since 2018-04-04
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief 应用（类）。
class Application: public CWinApp {
    DECLARE_DYNAMIC(Application)

#// Constructors
public:
    Application();
    virtual ~Application() override;

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
