//===-- Progress Box --------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 进度框类。
///
/// \verison 2018-09-05
/// \since 2018-05-30
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include <functional>

namespace rrMFC {

///
/// \brief 进度框类。
///
class ProgressBox: public CDialog {
    DECLARE_DYNAMIC(ProgressBox)

#// Constructors
public:
    ProgressBox(CWnd *pParent = NULL);

    VOID SetThreadFunction(std::function<UINT(ProgressBox *const)> const func)
    {
        ThreadFunction = func;
    }

    virtual ~ProgressBox() override;

#// Attributes
public:
    static const UINT IDD;

#// Operations
public:
    inline VOID SetTitle(LPCTSTR CONST text)
    {
        SetWindowText(text);
    }

    inline VOID SetTotal(LPCTSTR CONST text)
    {
        TotDesc = text;
    }

    inline VOID SetTotal(CONST SHORT min, CONST SHORT max)
    {
        ASSERT(0 <= min && min <= max);
        TotProgRngMin = min;
        TotProgRngMax = max;
    }

    inline VOID SetTotal(CONST INT position)
    {
        ASSERT(TotProgRngMin <= position && position <= TotProgRngMax);
        TotProgPos = position;
    }

    inline VOID SetCurrent(LPCTSTR CONST text)
    {
        CurDesc = text;
    }

    inline VOID SetCurrent(CONST SHORT min, CONST SHORT max)
    {
        ASSERT(0 <= min && min <= max);
        CurProgRngMin = min;
        CurProgRngMax = max;
    }

    inline VOID SetCurrent(CONST INT position)
    {
        ASSERT(CurProgRngMin <= position && position <= CurProgRngMax);
        CurProgPos = position;
    }

#// Overridables
public:
    virtual BOOL OnInitDialog() override;
protected:
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult) override;
    virtual VOID DoDataExchange(CDataExchange *pDX) override;
    virtual VOID OnOK() override { /*DONOTHING*/ }
    virtual VOID OnCancel() override { /*DONOTHING*/ }

#// Implementation
protected:
    enum TimerId { ZERO = 0, REFRESH_UI };

    CString       TotalText;
    CProgressCtrl TotalProgressControl;
    CString       CurrentText;
    CProgressCtrl CurrentProgressControl;

    CString TotDesc = TEXT("Total");    ///< Total Description.
    SHORT   TotProgRngMin = 0;          ///< Total Progress Range Min.
    SHORT   TotProgRngMax = 1;          ///< Total Progress Range Max.
    INT     TotProgPos = 0;             ///< Total Progress Position.
    CString CurDesc = TEXT("Current");  ///< Current Description.
    SHORT   CurProgRngMin = 0;          ///< Current Progress Range Min.
    SHORT   CurProgRngMax = 1;          ///< Current Progress Range Max.
    INT     CurProgPos = 0;             ///< Current Progress Position.

    std::function<UINT(ProgressBox *CONST)> ThreadFunction = NULL;
    static UINT AFX_CDECL ThreadWrapper(LPVOID pParam);

#// Message Handlers
protected:
    afx_msg VOID OnTimer(UINT_PTR nIDEvent);

    LRESULT OnClose(WPARAM wParam, LPARAM lParam);

    DECLARE_MESSAGE_MAP()
};

}//namespace rrMFC
