//===-- Button Dialog -------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 按钮对话框类。
///
/// \verison 2018-10-25
/// \since 2018-06-01
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

namespace rrMFC {

///
/// \brief 按钮对话框类。
///
class ButtonDialog: public CDialog {

// Constructors
public:
    ButtonDialog(CWnd *pParent = nullptr)
        : CDialog(IDD, pParent)
    {}

// Attributes
public:
    static const unsigned IDD;

// Overridables
protected:
    void DoDataExchange(CDataExchange *pDX) final;

// Implementation
protected:
    CButton         Button;

    CMFCButton      MfcButton;

    CMFCColorButton MfcColorButton;
    COLORREF        MfcColor = 0;

    CMFCLinkCtrl    MfcLinkButton;
    CString         MfcLink = _T("MfcLinkButton");

    CMFCMenuButton  MfcMenuButton;

// Message Handlers
protected:
    afx_msg void OnBnClickedButton();
    afx_msg void OnBnClickedMfcButton();

    DECLARE_MESSAGE_MAP()
};

}//namespace rrMFC
