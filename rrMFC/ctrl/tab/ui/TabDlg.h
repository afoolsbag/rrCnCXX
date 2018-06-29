//===-- Tab Dialog ----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 标签对话框（类）。
///
/// \verison 2018-06-29
/// \since 2017-04-04
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "resource.h"
#include "ui/PgDlg.h"

///
/// \brief 标签对话框（类）。
///
class TabDialog: public CDialog {

#// Constructors
public:
    TabDialog(CWnd *pParent = NULL);
    virtual ~TabDialog() override;

#// Attributes
public:
    enum { IDD = IDD_TAB_DIALOG };

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
    enum TabPageNo { TAB_PAGE_1 = 0, TAB_PAGE_2, TAB_PAGE_3 };
    PageDialog TabPg1;
    PageDialog TabPg2;
    PageDialog TabPg3;

    VOID CorrectTabPage(TabPageNo tabPageNo, PageDialog &tabPage) CONST;

#// Message Handlers
protected:
    afx_msg VOID OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);

    DECLARE_MESSAGE_MAP()
};
