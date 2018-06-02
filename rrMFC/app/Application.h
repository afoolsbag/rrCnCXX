//===-- Application ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 应用（类）。
///
/// \version 2018-06-01
/// \since 2018-04-11
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief 应用（类）。
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class
class Application: public CWinApp {
    DECLARE_DYNAMIC(Application)

#// Constructors
public:
    /// \brief 构造函数。
    Application();

    /// \brief 析构函数。
    virtual ~Application() override;

#// Attributes
public:

#// Operations
public:

#// Overridables
public:
    /// \brief 调用以执行应用程序的一次性初始化。
    /// \deprecated 过时的。
    virtual BOOL InitApplication() override;

    /// \brief 调用以初始化应用程序或线程的新实例。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#initinstance
    virtual BOOL InitInstance() override;

    /// \brief 调用以退出应用程序或线程的该实例。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#exitinstance
    virtual INT ExitInstance() override;

#// Implementation
protected:

#// Message Handlers
protected:
};
