//===-- Application ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 应用（类）。
///
/// \version 2018-04-27
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
    /// \brief 构造函数。
    Application();

    /// \brief 析构函数。
    virtual ~Application();

#// Attributes
public:

#// Operations
public:

#// Overridables
public:
    /// \remark 没有说明的。
    virtual BOOL InitApplication() override;

    /// \brief 重写以执行 Windows 实例初始化，如创建窗口对象。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#initinstance
    virtual BOOL InitInstance() override;

    /// \brief 重写以清理，当你的应用程序终止时。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#exitinstance
    virtual INT ExitInstance() override;

#// Implementation
protected:

#// Message Handlers
protected:
};
