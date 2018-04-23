//===-- Main Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 宿主对话框（类）。
///
/// \verison 2018-04-23
/// \since 2018-04-23
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief 宿主对话框（类）。
class HostDialog: public CDialog {
    DECLARE_DYNCREATE(HostDialog)

#// Constructors
public:
    HostDialog(HWND hwndCallee = NULL, CWnd *pParent = NULL);

#// Attributes
public:
    enum { IDD = IDD_HOST_DIALOG };

#// Operations
public:

#// Overridables
public:
    virtual ~HostDialog();

protected:
    virtual VOID DoDataExchange(CDataExchange *pDX);
    virtual BOOL OnInitDialog();


#// Implementation
protected:
    HWND CalleeHwnd;

#// Message Handlers
protected:
    afx_msg INT OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg VOID OnDestroy();

    afx_msg LRESULT OnRrmfcProcessDialogCalleeCreating(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnRrmfcProcessDialogCalleeDestroying(WPARAM wParam, LPARAM lParam);

    DECLARE_MESSAGE_MAP()
};
