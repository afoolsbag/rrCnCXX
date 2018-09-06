//===-- Page Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 标签页对话框类。
///
/// \verison 2018-09-05
/// \since 2017-04-08
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

namespace rrMFC {

///
/// \brief 标签页对话框类。
///
class PageDialog: public CDialog {

#// Constructors
public:
    PageDialog(CWnd *pParent = NULL);
    virtual ~PageDialog() override;

#// Attributes
public:
    static const UINT IDD;

#// Operations
public:

#// Overridables
protected:
    virtual VOID DoDataExchange(CDataExchange *pDX) override;
    virtual VOID OnOK() override { /*DONOTHING*/ }
    virtual VOID OnCancel() override { /*DONOTHING*/ }

#// Implementation
protected:

#// Message Handlers
protected:
};

}//namespace rrMFC
