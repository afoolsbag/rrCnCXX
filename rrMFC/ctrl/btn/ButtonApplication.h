//===-- Button Application --------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 按钮应用（类）。
///
/// \verison 2018-06-01
/// \since 2018-06-01
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief 按钮应用（类）。
class ButtonApplication: public CWinApp {
    DECLARE_DYNAMIC(ButtonApplication)

#// Constructors
public:
    ButtonApplication();
    virtual ~ButtonApplication() override;

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
