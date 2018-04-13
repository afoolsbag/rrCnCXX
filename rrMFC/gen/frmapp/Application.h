//===-- Application ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 应用（类）。
///
/// \version 2018-04-13
/// \since 2017-12-08
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

#// Operations
public:

#// Overridables
public:
    virtual ~Application();

protected:
    /// \brief Initialize Instance
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#initinstance
    virtual BOOL InitInstance();

    /// \brief Exit Instance
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#exitinstance
    virtual INT ExitInstance();

#// Implementation
protected:

#// Message Handlers
protected:
};
