//===-- Application ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 应用（类）。
///
/// \version 2018-04-23
/// \since 2018-04-11
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief 应用（类）。
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class
class Application: public CWinApp {
    DECLARE_DYNCREATE(Application)

#// Constructors
public:
    Application();

#// Attributes
public:
    HWND MessageHwnd;

#// Operations
public:

#// Overridables
public:
    virtual ~Application();

protected:
    /// \brief InitApplication.
    /// \remark 隐藏的。
    virtual BOOL InitApplication();

    /// \brief Override to perform Windows instance initialization, such as creating your window objects.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#initinstance
    virtual BOOL InitInstance();

    /// \brief Override to clean up when your application terminates.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#exitinstance
    virtual INT ExitInstance();

#// Implementation
protected:

#// Message Handlers
protected:
};
