//===-- Host Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 宿主对话框（类）。
///
/// \verison 2018-04-27
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
    VOID SetExePath(LPCTSTR CONST exePath);
    virtual ~HostDialog();

#// Attributes
public:
    enum { IDD = IDD_HOST_DIALOG };

#// Operations
public:

#// Overridables
public:

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

    afx_msg LRESULT OnGuestCreate(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnGuestSize(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnGuestDestroy(WPARAM wParam, LPARAM lParam);

    DECLARE_MESSAGE_MAP()
};
