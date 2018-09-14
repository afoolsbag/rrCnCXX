//===-- Tab Dialog ----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 标签对话框类。
///
/// \verison 2018-09-14
/// \since 2017-04-04
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include "PageDialog.h"

namespace rrMFC {
namespace Test {

///
/// \brief 标签对话框类。
///
class TabDialog: public CDialog {

#// Constructors
public:
    TabDialog(CWnd *pParent = NULL);
    virtual ~TabDialog() override;

#// Attributes
public:
    static const UINT IDD;

#// Operations
public:

#// Overridables
public:
    virtual BOOL OnInitDialog() override;
protected:
    virtual VOID DoDataExchange(CDataExchange *pDX) override;
    virtual VOID OnOK() override { /*DONOTHING*/ }

#// Implementation
protected:
    CTabCtrl Tab;
    enum TabPageNo { TAB_PAGE_1, TAB_PAGE_2, TAB_PAGE_3 };
    PageDialog TabPg1;
    PageDialog TabPg2;
    PageDialog TabPg3;

    VOID CorrectTabPage(TabPageNo tabPageNo, PageDialog &tabPage) CONST;

#// Message Handlers
protected:
    afx_msg VOID OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);

    DECLARE_MESSAGE_MAP()
};

}//namespace Test
}//namespace rrMFC
