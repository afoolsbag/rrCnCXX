//===-- Class Main Dialog ---------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 主对话框类
///
/// \verison 2018-04-04
/// \since 2017-04-04
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief Class Main Dialog
class CMainDlg: public CDialog {
public:
    CMainDlg(CWnd *pParent = NULL);

    virtual BOOL OnInitDialog();

protected:
    virtual void DoDataExchange(CDataExchange *pDX);

    CTabCtrl ctrl_tab_;
    CDialog ctrl_tab_page_0_;
    CDialog ctrl_tab_page_1_;
    CDialog ctrl_tab_page_2_;

    DECLARE_MESSAGE_MAP()
};
