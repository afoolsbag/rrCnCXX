//===-- Page Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief （标签）页对话框（类）。
///
/// \verison 2018-04-09
/// \since 2017-04-08
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief （标签）页对话框（类）。
class PageDialog: public CDialog {
    DECLARE_DYNCREATE(PageDialog)

// Constructors
public:
    PageDialog(CWnd *pParent = NULL);

// Attributes
public:

// Operations
public:

// Overridables
protected:
    virtual VOID DoDataExchange(CDataExchange *pDX);

// Implementation
protected:

// Message Handlers
protected:
};
