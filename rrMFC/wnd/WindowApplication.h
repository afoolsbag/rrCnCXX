//===-- Window Application --------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 窗口应用（类）。
///
/// \version 2018-06-01
/// \since 2018-04-27
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief 窗口应用（类）。
class WindowApplication: public CWinApp {
    DECLARE_DYNAMIC(WindowApplication)

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
