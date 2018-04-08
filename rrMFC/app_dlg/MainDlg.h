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

protected:
    virtual void DoDataExchange(CDataExchange *pDX);

    afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedCancel();

    DECLARE_MESSAGE_MAP()
};
