//===-- Main Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 主对话框类
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
public:
    CMainDlg(CWnd *pParent = NULL);

    virtual BOOL OnInitDialog();

protected:
    virtual void DoDataExchange(CDataExchange *pDX);

    CTabCtrl ctrl_tab_;
    CPageDlg ctrl_tab_page_0_;
    CPageDlg ctrl_tab_page_1_;
    CPageDlg ctrl_tab_page_2_;

    afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);

    DECLARE_MESSAGE_MAP()
};
