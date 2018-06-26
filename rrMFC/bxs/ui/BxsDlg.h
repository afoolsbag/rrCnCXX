//===-- Boxes Dialog --------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 盒子对话框（类）。
///
/// \verison 2018-06-04
/// \since 2018-05-29
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "progdlg/ProgDlg.h"

#include "resource.h"

/// \brief 盒子对话框（类）。
class BoxesDialog: public CDialog {

#// Constructors
public:
    BoxesDialog(CWnd *pParent = NULL);
    virtual ~BoxesDialog() override;

#// Attributes
public:
    enum { IDD = IDD_BOXES_DIALOG };

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