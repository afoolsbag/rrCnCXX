//===-- Main Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 主对话框（类）。
///
/// \verison 2018-05-29
/// \since 2018-05-29
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "progdlg/ProgressDialog.h"

#include "resource.h"

/// \brief 主对话框（类）。
class MainDialog: public CDialog {
    DECLARE_DYNCREATE(MainDialog)

#// Constructors
public:
    MainDialog(CWnd *pParent = NULL);
    virtual ~MainDialog() override;

#// Attributes
public:
    enum { IDD = IDD_MAIN_DIALOG };

#// Operations
public:

#// Overridables
public:
    virtual BOOL OnInitDialog() override;
protected:
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult) override;
    virtual VOID DoDataExchange(CDataExchange *pDX) override;

#// Implementation
protected:
    UINT ThreadFunction(ProgressDialog *CONST pProgressDialog);
    BOOL ThreadLoopFlag = FALSE;

#// Message Handlers
protected:
    afx_msg VOID OnBnClickedButton();

    DECLARE_MESSAGE_MAP()
};
