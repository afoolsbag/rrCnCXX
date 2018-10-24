//===-- Page Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 标签页对话框类。
///
/// \verison 2018-10-24
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

// Constructors
public:
    PageDialog(CWnd *pParent = nullptr)
        : CDialog(IDD, pParent)
    {}

// Attributes
public:
    static const unsigned IDD;

// Overridables
protected:
    void OnOK() override {}
    void OnCancel() override {}

};

}//namespace rrMFC
