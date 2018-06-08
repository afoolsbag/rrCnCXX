//===-- Thread Application --------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 线程应用（类）。
///
/// \verison 2018-06-08
/// \since 2018-04-28
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief 线程应用（类）。
class ThreadApplication: public CWinApp {
    DECLARE_DYNAMIC(ThreadApplication)

#// Constructors
public:
    ThreadApplication();
    virtual ~ThreadApplication() override;

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
