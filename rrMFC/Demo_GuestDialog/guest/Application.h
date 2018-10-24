//===-- Application ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 应用（类）。
///
/// \verison 2018-04-28
/// \since 2018-04-23
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "ui/GuestDialog.h"

/// \brief 应用（类）。
class Application: public CWinApp {
    DECLARE_DYNCREATE(Application)

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
