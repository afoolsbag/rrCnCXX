//===-- Window --------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 窗口类。
///
/// \verison 2018-09-14
/// \since 2018-04-27
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

namespace rrMFC {
namespace Test {

///
/// \brief 窗口类。
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class
///
class Window: public CWnd {

#// Constructors
public:
    /// \brief 构造函数。
    explicit Window();

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#create>
    BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT &rect, CWnd *pParentWnd, unsigned nID, CCreateContext *pContext = NULL) final;

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#createex>
    BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU nIDorHMenu, LPVOID lpParam = NULL) final;

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#createex>
    BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT &rect, CWnd *pParentWnd, unsigned nID, LPVOID lpParam = NULL) final;

    /// \brief 析构函数。
    ~Window() final;

#// Attributes
public:

#// Operations
public:

#// Overridables
public:
    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#precreatewindow>
    BOOL PreCreateWindow(CREATESTRUCT &cs) final;

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/ccmdtarget-class#oncmdmsg>
    BOOL OnCmdMsg(unsigned nID, int nCode, void *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo) final;

protected:
    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onwndmsg>
    BOOL OnWndMsg(unsigned message, WPARAM wParam, LPARAM lParam, LRESULT *pResult) final;

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class>
    void DoDataExchange(CDataExchange *pDX) final;

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#postncdestroy>
    void PostNcDestroy() final;

#// Implementation
protected:

    enum Timer: UINT_PTR { Allocate = 0uLL, Alpha, Beta, Gamma };

#// Message Handlers
protected:

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onnccreate>
    afx_msg BOOL OnNcCreate(LPCREATESTRUCT lpCreateStruct);

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#oncreate>
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#ondestroy>
    afx_msg void OnDestroy();

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onncdestroy>
    afx_msg void OnNcDestroy();


    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#ongetminmaxinfo>
    afx_msg void OnGetMinMaxInfo(MINMAXINFO *lpMMI);

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onentersizemove>
    afx_msg void OnEnterSizeMove();

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onmoving>
    afx_msg void OnMoving(unsigned fwSide, LPRECT pRect);

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onsizing>
    afx_msg void OnSizing(unsigned fwSide, LPRECT pRect);

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onwindowposchanging>
    afx_msg void OnWindowPosChanging(WINDOWPOS *lpwndpos);

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onexitsizemove>
    afx_msg void OnExitSizeMove();

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onmove>
    afx_msg void OnMove(int x, int y);

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onnccalcsize>
    afx_msg void OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS *lpncsp);

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onsize>
    afx_msg void OnSize(unsigned nType, int cx, int cy);

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onwindowposchanged>
    afx_msg void OnWindowPosChanged(WINDOWPOS *lpwndpos);


    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onactivateapp>
    afx_msg void OnActivateApp(BOOL bActive, DWORD dwThreadID);

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onncactivate>
    afx_msg BOOL OnNcActivate(BOOL bActive);

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onactivate>
    afx_msg void OnActivate(unsigned nState, CWnd *pWndOther, BOOL bMinimized);


    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onncpaint>
    afx_msg void OnNcPaint();

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onerasebkgnd>
    afx_msg BOOL OnEraseBkgnd(CDC *pDC);

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onpaint>
    afx_msg void OnPaint();


    /// \remarks `SetTimer(Timer::Alpha, 1000, nullptr);`\n
    ///          `KillTimer(Timer::Alpha);`
    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#ontimer>
    afx_msg void OnTimer(UINT_PTR nIDEvent);


    /// \remarks `PostMessage(CUSTOM_PRIVATE_MESSAGE);`。
    afx_msg LRESULT OnCustomPrivateMessage(WPARAM wParam, LPARAM lParam);

    /// \remarks `PostMessage(CUSTOM_APPLICATION_MESSAGE);`。
    afx_msg LRESULT OnCustomApplicationMessage(WPARAM wParam, LPARAM lParam);

    /// \remarks `::PostMessage(HWND_BROADCAST, CUSTOM_REGISTER_MESSAGE, NULL, NULL);`。
    afx_msg LRESULT OnCustomRegisteredMessage(WPARAM wParam, LPARAM lParam);

    DECLARE_MESSAGE_MAP()
};

}//namespace Test
}//namespace rrMFC
