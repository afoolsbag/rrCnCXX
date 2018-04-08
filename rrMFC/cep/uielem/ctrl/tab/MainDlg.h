//===-- Main Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 主对话框类。
///
/// \verison 2018-04-08
/// \since 2017-04-04
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "PageDlg.h"

/// \brief Class Main Dialog
class CMainDlg: public CDialog {
    DECLARE_DYNCREATE(CMainDlg)
public:
    CMainDlg(CWnd *pParent = NULL);

// Attributes
public:
private:
    CTabCtrl tab_ctrl_;
    CPageDlg tab_page_0_ctrl_;
    CPageDlg tab_page_1_ctrl_;
    CPageDlg tab_page_2_ctrl_;

// Operations
public:

// Overrides
public:
    virtual BOOL OnInitDialog();

protected:
    virtual void DoDataExchange(CDataExchange *pDX);

// Implementation
public:

// Generated message map functions
protected:
    DECLARE_MESSAGE_MAP()

public:

protected:
    afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
};
