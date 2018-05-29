//===-- Progress Dialog -----------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 进度对话框（类）。
///
/// \verison 2018-05-29
/// \since 2018-05-29
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include <functional>

#include "progdlg.h"

/// \brief 进度对话框（类）。
class ProgressDialog: public CDialog {
    DECLARE_DYNCREATE(ProgressDialog)

#// Constructors
public:
    ProgressDialog(CWnd *pParent = NULL);

    VOID SetThreadFunction(std::function<UINT(ProgressDialog *CONST)> CONST function)
    {
        ThreadFunction = function;
    }

    virtual ~ProgressDialog() override;

#// Attributes
public:
    enum { IDD = IDD_PROGRESS_DIALOG };

#// Operations
public:
    inline VOID SetTotalDescription(LPCTSTR CONST text)
    {
        TotalDescription = text;
    }

    inline VOID SetTotalProgressRange(CONST SHORT min, CONST SHORT max)
    {
        TotalProgressRangeMin = min;
        TotalProgressRangeMax = max;
    }

    inline VOID SetTotalProgressPosition(CONST INT position)
    {
        TotalProgressPosition = position;
    }

    inline VOID SetCurrentDescription(LPCTSTR CONST text)
    {
        CurrentDescription = text;
    }

    inline VOID SetCurrentProgressRange(CONST SHORT min, CONST SHORT max)
    {
        CurrentProgressRangeMin = min;
        CurrentProgressRangeMax = max;
    }

    inline VOID SetCurrentProgressPosition(CONST INT position)
    {
        CurrentProgressPosition = position;
    }

#// Overridables
public:
    virtual BOOL OnInitDialog() override;
    virtual BOOL PreTranslateMessage(MSG *pMsg) override;
protected:
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult) override;
    virtual VOID DoDataExchange(CDataExchange *pDX) override;

#// Implementation
protected:
    enum TimerId { ZERO = 0, REFRESH_UI };

    CString TotalText;
    CProgressCtrl TotalProgressControl;
    CString CurrentText;
    CProgressCtrl CurrentProgressControl;

    CString TotalDescription = TEXT("Total");
    SHORT TotalProgressRangeMin = 0;
    SHORT TotalProgressRangeMax = 100;
    INT TotalProgressPosition = 1;
    CString CurrentDescription = TEXT("Current");
    SHORT CurrentProgressRangeMin = 0;
    SHORT CurrentProgressRangeMax = 100;
    INT CurrentProgressPosition = 1;

    std::function<UINT(ProgressDialog *CONST)> ThreadFunction = NULL;
    static UINT ThreadWrapper(LPVOID pParam);

#// Message Handlers
protected:
    afx_msg VOID OnTimer(UINT_PTR nIDEvent);

    LRESULT OnClose(WPARAM wParam, LPARAM lParam);

    DECLARE_MESSAGE_MAP()
};
