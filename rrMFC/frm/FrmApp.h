//===-- Frame Application ---------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 框架应用（类）。
///
/// \version 2018-06-12
/// \since 2017-12-08
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

///
/// \brief 框架应用（类）。
///
class FrameApplication: public CWinApp {

#// Constructors
public:
    FrameApplication();
    virtual ~FrameApplication() override;

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
