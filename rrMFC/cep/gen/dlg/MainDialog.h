//===-- Main Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 主对话框（类）。
///
/// \verison 2018-04-08
/// \since 2018-04-04
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief 主对话框（类）。
class MainDialog: public CDialog {
    DECLARE_DYNCREATE(MainDialog)
public:
    MainDialog(CWnd *pParent = NULL);

// Attributes
public:

// Operations
public:

// Overrides
public:
    virtual void DoDataExchange(CDataExchange *pDX);

// Implementation
public:

// Generated message map functions
protected:
    DECLARE_MESSAGE_MAP()

public:

protected:
    afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedCancel();
};
