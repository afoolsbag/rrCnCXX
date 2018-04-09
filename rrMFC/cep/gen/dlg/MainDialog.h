//===-- Main Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 主对话框（类）。
///
/// \verison 2018-04-09
/// \since 2018-04-04
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief 主对话框（类）。
class MainDialog: public CDialog {
    DECLARE_DYNCREATE(MainDialog)

// Constructors
public:
    MainDialog(CWnd *pParent = NULL);

// Attributes
public:

// Operations
public:

// Overridables
protected:
    virtual VOID DoDataExchange(CDataExchange *pDX);

// Implementation
protected:

// Message Handlers
protected:
    afx_msg VOID OnBnClickedOk();
    afx_msg VOID OnBnClickedCancel();

    DECLARE_MESSAGE_MAP()
};
