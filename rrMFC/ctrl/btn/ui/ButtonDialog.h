//===-- Button Dialog -------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 按钮对话框（类）。
///
/// \verison 2018-06-01
/// \since 2018-06-01
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "resource.h"

/// \brief 按钮对话框（类）。
class ButtonDialog: public CDialog {
    DECLARE_DYNAMIC(ButtonDialog)

#// Constructors
public:
    ButtonDialog(CWnd *pParent = NULL);
    virtual ~ButtonDialog() override;

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
    CButton Button;
    CMFCButton MfcButton;
    CMFCColorButton MfcColorButton;
    COLORREF MfcColor = 0;
    CMFCLinkCtrl MfcLinkButton;
    CString MfcLink = TEXT("MfcLinkButton");
    CMFCMenuButton MfcMenuButton;

#// Message Handlers
protected:
    afx_msg VOID OnBnClickedButton();
    afx_msg VOID OnBnClickedMfcButton();

    DECLARE_MESSAGE_MAP()
};
