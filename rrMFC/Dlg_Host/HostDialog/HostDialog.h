//===-- Host Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 宿主对话框类。
///
/// \verison 2018-09-14
/// \since 2018-04-23
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

namespace rrMFC {
namespace Test {

///
/// \brief 宿主对话框类。
///
class HostDialog: public CDialog {

#// Constructors
public:
    HostDialog(CWnd *pParent = nullptr);
    void SetExePath(LPCTSTR const exePath) { ExePath = exePath; }

    ~HostDialog() final;

#// Attributes
public:
    static const unsigned IDD;

#// Operations
public:

#// Overridables
public:
    BOOL OnInitDialog() final;

protected:
    BOOL OnWndMsg(unsigned message, WPARAM wParam, LPARAM lParam, LRESULT *pResult) final;

#// Implementation
protected:
    enum Timer: UINT_PTR { Allocate = 0uLL, CheckGuestAlive };

    CString ExePath;
    CString ExeParameters;
    HWND GuestHwnd = nullptr;

#// Message Handlers
protected:
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnMove(int x, int y);

    afx_msg LRESULT OnGuestCreate(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnGuestSize(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnGuestShowWindow(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnGuestDestroy(WPARAM wParam, LPARAM lParam);

    afx_msg void OnTimer(UINT_PTR nIDEvent);

    DECLARE_MESSAGE_MAP()
};

}//namespace Test
}//namespace rrMFC
