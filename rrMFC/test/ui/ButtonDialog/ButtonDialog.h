//===-- Button Dialog -------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 按钮对话框类。
///
/// \verison 2018-09-14
/// \since 2018-06-01
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

namespace rrMFC {
namespace Test {

/// \brief 按钮对话框类。
class ButtonDialog: public CDialog {

#// Constructors
public:
    ButtonDialog(CWnd *pParent = nullptr);
    ~ButtonDialog() final;

#// Attributes
public:
    static const unsigned IDD;

#// Operations
public:

#// Overridables
public:
    BOOL OnInitDialog() final;
protected:
    BOOL OnWndMsg(unsigned message, WPARAM wParam, LPARAM lParam, LRESULT *pResult) final;
    void DoDataExchange(CDataExchange *pDX) final;

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
    afx_msg void OnBnClickedButton();
    afx_msg void OnBnClickedMfcButton();

    DECLARE_MESSAGE_MAP()
};

}//namespace Test
}//namespace rrMFC
