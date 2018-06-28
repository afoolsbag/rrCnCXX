//===-- Page Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief （标签）页对话框（类）。
///
/// \verison 2018-06-28
/// \since 2017-04-08
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "resource.h"

///
/// \brief （标签）页对话框（类）。
///
class PageDialog: public CDialog {

#// Constructors
public:
    PageDialog(CWnd *pParent = NULL);
    virtual ~PageDialog() override;

#// Attributes
public:
    enum { IDD = IDD_PAGE_DIALOG };

#// Operations
public:

#// Overridables
protected:
    virtual VOID DoDataExchange(CDataExchange *pDX) override;

#// Implementation
protected:

#// Message Handlers
protected:
};
