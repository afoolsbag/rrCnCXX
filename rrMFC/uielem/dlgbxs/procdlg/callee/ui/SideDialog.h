//===-- Main Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 侧对话框（类）。
///
/// \verison 2018-04-23
/// \since 2018-04-23
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief 侧对话框（类）。
class SideDialog: public CDialog {
    DECLARE_DYNCREATE(SideDialog)

#// Constructors
public:
    SideDialog(CWnd *pParent = NULL);

#// Attributes
public:
    enum { IDD = IDD_SIDE_DIALOG };

#// Operations
public:

#// Overridables
public:
    virtual ~SideDialog();

protected:
    virtual VOID DoDataExchange(CDataExchange *pDX);

#// Implementation
protected:

#// Message Handlers
protected:
    afx_msg INT OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg VOID OnDestroy();

    afx_msg VOID OnMove(INT x, INT y);

    DECLARE_MESSAGE_MAP()
};
