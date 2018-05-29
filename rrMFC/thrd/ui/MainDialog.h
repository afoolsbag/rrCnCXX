//===-- Main Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 主对话框（类）。
///
/// \verison 2018-05-28
/// \since 2018-05-28
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "resource.h"

/// \brief 主对话框（类）。
class MainDialog: public CDialog {
    DECLARE_DYNCREATE(MainDialog)

#// Constructors
public:
    MainDialog(CWnd *pParent = NULL);
    virtual ~MainDialog() override;

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
public:
protected:
    enum TimerId { ZERO = 0, REFRESH_UI, UPDATE_NUMBER_REFRESH_UI };

    CStatic NumberStaticControl;
    INT Number = 0;

    INT Count = 0;
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
