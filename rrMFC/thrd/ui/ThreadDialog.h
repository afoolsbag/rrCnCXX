//===-- Thread Dialog -------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 线程对话框（类）。
///
/// \verison 2018-06-08
/// \since 2018-05-28
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "resource.h"

/// \brief 线程对话框（类）。
class ThreadDialog: public CDialog {
    DECLARE_DYNAMIC(ThreadDialog)

#// Constructors
public:
    ThreadDialog(CWnd *pParent = NULL);
    virtual ~ThreadDialog() override;

#// Attributes
public:
    enum { IDD = IDD_THREAD_DIALOG };

#// Operations
public:

#// Overridables
public:
    virtual BOOL OnInitDialog() override;
protected:
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult) override;
    virtual VOID DoDataExchange(CDataExchange *pDX) override;

#// Implementation
public:
protected:
    enum TimerId { ZERO = 0, REFRESH_UI };

    CStatic NumberStaticControl;
    INT Number = 0;

    UINT CountThreadFunction(LPVOID pParam);
    BOOL CountThreadLoopFlag = FALSE;
    static UINT CountThreadWrapper(LPVOID pObject);
    CWinThread *CountThread = NULL;

#// Message Handlers
protected:
    afx_msg VOID OnTimer(UINT_PTR nIDEvent);

    afx_msg VOID OnBnClickedStartButton();
    afx_msg VOID OnBnClickedStopButton();

    DECLARE_MESSAGE_MAP()
};
