//===-- Main Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 主对话框（类）。
///
/// \verison 2018-04-09
/// \since 2017-04-04
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "PageDialog.h"

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

    /// \brief On Initialize Dialog
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cdialog-class#oninitdialog
    virtual BOOL OnInitDialog();

// Implementation
protected:
    CTabCtrl TabControl;
    PageDialog TabPage0Control;
    PageDialog TabPage1Control;
    PageDialog TabPage2Control;

// Message Handlers
protected:
    afx_msg VOID OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);

    DECLARE_MESSAGE_MAP()
};
