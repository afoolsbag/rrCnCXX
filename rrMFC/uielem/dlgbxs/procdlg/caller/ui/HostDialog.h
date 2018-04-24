//===-- Main Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 宿主对话框（类）。
///
/// \verison 2018-04-24
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
    HostDialog(CWnd *pParent = NULL);

#// Attributes
public:
    enum { IDD = IDD_HOST_DIALOG };

#// Operations
public:

#// Overridables
public:
    virtual ~HostDialog();
    VOID SetExePath(CONST LPCTSTR exePath);

protected:
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult);
    virtual VOID DoDataExchange(CDataExchange *pDX);
    virtual BOOL OnInitDialog();
    virtual VOID OnCancel();

#// Implementation
protected:
    CString ExePath;
    HWND GuestHwnd = NULL;

#// Message Handlers
protected:
    afx_msg INT OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg VOID OnDestroy();

    afx_msg VOID OnMove(INT x, INT y);

    afx_msg LRESULT OnRrmfcGuestCreating(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnRrmfcGuestSizing(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnRrmfcGuestDestroying(WPARAM wParam, LPARAM lParam);

    DECLARE_MESSAGE_MAP()
};
