//===-- Main Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 宾对话框（类）。
///
/// \verison 2018-04-23
/// \since 2018-04-23
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "resource.h"
#include "ui/SideDialog.h"

/// \brief 宾对话框（类）。
class GuestDialog: public CDialog {
    DECLARE_DYNCREATE(GuestDialog)

#// Constructors
public:
    GuestDialog(CWnd *pParent = NULL);
    VOID SetHostHwnd(CONST HWND hostHwnd);

#// Attributes
public:
    enum { IDD = IDD_GUEST_DIALOG };

#// Operations
public:

#// Overridables
public:
    virtual ~GuestDialog();

protected:
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult);
    virtual VOID DoDataExchange(CDataExchange *pDX);
    virtual BOOL OnInitDialog();
    virtual VOID OnCancel();

#// Implementation
protected:
    HWND HostHwnd = NULL;
    CEdit PathEdit;
    SideDialog SideDialog;

#// Message Handlers
protected:
    afx_msg INT OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg VOID OnDestroy();

    afx_msg VOID OnSize(UINT nType, INT cx, INT cy);

    afx_msg LRESULT OnRrmfcHostMoving(WPARAM wParam, LPARAM lParam);

    afx_msg VOID OnBnClickedToggleSideDialogButton();

    DECLARE_MESSAGE_MAP()
public:
};
