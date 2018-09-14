//===-- Progress Box --------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 进度框类。
///
/// \verison 2018-09-14
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
    ProgressBox(CWnd *pParent = nullptr);

    using ThreadFunctionType = std::function<unsigned(ProgressBox &)>;
    void SetThreadFunction(const ThreadFunctionType func)
    {
        ThreadFunction = func;
    }

    ~ProgressBox() final;

#// Attributes
public:
    static const unsigned IDD;

#// Operations
public:
    void Title(LPCTSTR const title)
    {
        SetWindowText(title);
    }

    void Total(LPCTSTR const description)
    {
        TDesc = description;
    }

    void Total(const short min, const short max)
    {
        ASSERT(0 <= min && min <= max);
        TMin = min;
        TMax = max;
    }

    void Total(const int position)
    {
        ASSERT(TMin <= position && position <= TMax);
        TPos = position;
    }

    void Current(LPCTSTR const description)
    {
        CDesc = description;
    }

    void Current(const short min, const short max)
    {
        ASSERT(0 <= min && min <= max);
        CMin = min;
        CMax = max;
    }

    void Current(const int position)
    {
        ASSERT(CMin <= position && position <= CMax);
        CPos = position;
    }

#// Overridables
public:
    BOOL OnInitDialog() final;
protected:
    BOOL OnWndMsg(unsigned message, WPARAM wParam, LPARAM lParam, LRESULT *pResult) final;
    void DoDataExchange(CDataExchange *pDX) final;
    void OnOK() final { /*DONOTHING*/ }
    void OnCancel() final { /*DONOTHING*/ }

#// Implementation
protected:
    enum Timer: UINT_PTR { Allocate = 0uLL, Refresh };

    CString       TotalText;
    CProgressCtrl TotalProgressControl;
    CString       CurrentText;
    CProgressCtrl CurrentProgressControl;

    CString TDesc {TEXT("Total")};    ///< Total Description.
    short   TMin {0};                 ///< Total Progress Range Min.
    short   TMax {1};                 ///< Total Progress Range Max.
    int     TPos {0};                 ///< Total Progress Position.
    CString CDesc {TEXT("Current")};  ///< Current Description.
    short   CMin {0};                 ///< Current Progress Range Min.
    short   CMax {1};                 ///< Current Progress Range Max.
    int     CPos {0};                 ///< Current Progress Position.

    static unsigned AFX_CDECL ThreadWrapper(LPVOID pParam);
    ThreadFunctionType ThreadFunction = nullptr;

#// Message Handlers
protected:
    afx_msg void OnTimer(UINT_PTR nIDEvent);

    LRESULT OnClose(WPARAM wParam, LPARAM lParam);

    DECLARE_MESSAGE_MAP()
};

}//namespace rrMFC
