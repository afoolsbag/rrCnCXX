//===-- Button Dialog -------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 按钮对话框类。
///
/// \verison 2018-09-05
/// \since 2018-06-01
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include "ButtonDialog.rc.h"

namespace rrMFC {

/// \brief 按钮对话框类。
class ButtonDialog: public CDialog {

#// Constructors
public:
    ButtonDialog(CWnd *pParent = NULL);
    virtual ~ButtonDialog() override;

#// Attributes
public:
    enum { IDD = IDD_BUTTON_DIALOG };

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
    CButton         Button;
    CMFCButton      MfcButton;
    CMFCColorButton MfcColorButton;
    COLORREF        MfcColor = 0;
    CMFCLinkCtrl    MfcLinkButton;
    CString         MfcLink = TEXT("MfcLinkButton");
    CMFCMenuButton  MfcMenuButton;

#// Message Handlers
protected:
    afx_msg VOID OnBnClickedButton();
    afx_msg VOID OnBnClickedMfcButton();

    DECLARE_MESSAGE_MAP()
};

}//namespace rrMFC
