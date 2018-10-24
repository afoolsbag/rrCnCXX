//===-- Tab Dialog ----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 标签对话框类。
///
/// \verison 2018-10-24
/// \since 2017-04-04
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include "PageDialog.h"

namespace rrMFC {

///
/// \brief 标签对话框类。
///
class TabDialog: public CDialog {

// Constructors
public:
    TabDialog(CWnd *pParent = nullptr)
        : CDialog(IDD, pParent)
    {}

// Attributes
public:
    static const unsigned IDD;

// Overridables
public:
    BOOL OnInitDialog() override;
protected:
    void DoDataExchange(CDataExchange *pDX) override;
    void OnOK() override {}

// Implementation
protected:
    CTabCtrl Tab;
    enum TabPageNo { TabPage1, TabPage2, TabPage3 };
    PageDialog TabPg1;
    PageDialog TabPg2;
    PageDialog TabPg3;

    void CorrectTabPage(TabPageNo tabPageNo, PageDialog &tabPage) const;

// Message Handlers
protected:
    afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);

    DECLARE_MESSAGE_MAP()
};

}//namespace rrMFC
