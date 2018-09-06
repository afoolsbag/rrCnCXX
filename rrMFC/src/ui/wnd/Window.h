//===-- Window --------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 窗口类。
///
/// \verison 2018-09-06
/// \since 2018-04-27
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

namespace rrMFC {

///
/// \brief 窗口类。
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class
///
class Window: public CWnd {

#// Constructors
public:
    /// \brief 构造函数。
    Window();

    /// \brief 创建Windows子窗口。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#create
    virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT &rect, CWnd *pParentWnd, UINT nID, CCreateContext *pContext = NULL) override;

    /// \brief 创建Windows子窗口。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#createex
    virtual BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, INT x, INT y, INT nWidth, INT nHeight, HWND hWndParent, HMENU nIDorHMenu, LPVOID lpParam = NULL) override;

    /// \brief 创建Windows子窗口。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#createex
    virtual BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT &rect, CWnd *pParentWnd, UINT nID, LPVOID lpParam = NULL) override;

    /// \brief 析构函数。
    virtual ~Window() override;

#// Attributes
public:

#// Operations
public:

#// Overridables
public:
    /// \brief 在创建Windows窗口之前调用。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#precreatewindow
    virtual BOOL PreCreateWindow(CREATESTRUCT &cs) override;

    /// \brief 调用以路由和调度命令消息。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/ccmdtarget-class#oncmdmsg
    virtual BOOL OnCmdMsg(UINT nID, INT nCode, void *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo) override;

protected:
    /// \brief 调用以调度窗口消息。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onwndmsg
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult) override;

    /// \brief 调用以交换和验证对话框数据。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class
    virtual void DoDataExchange(CDataExchange *pDX) override;

    /// \brief 在销毁窗口后调用。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#postncdestroy
    virtual void PostNcDestroy() override;

#// Implementation
protected:

    enum TimerId { ZERO = 0, ALPHA, BETA, GAMMA };

#// Message Handlers
protected:

    /// \brief 指示正在创建非工作区。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onnccreate
    afx_msg BOOL OnNcCreate(LPCREATESTRUCT lpCreateStruct);

    /// \brief 指示正在创建窗口。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#oncreate
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

    /// \brief 指示窗口即将销毁。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#ondestroy
    afx_msg void OnDestroy();

    /// \brief 指示正在销毁非工作区。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onncdestroy
    afx_msg void OnNcDestroy();

    /// \brief 检索尺寸调整最小和最大的信息。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#ongetminmaxinfo
    afx_msg void OnGetMinMaxInfo(MINMAXINFO *lpMMI);

    /// \brief 指示窗口进入移动或尺寸调整循环。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onentersizemove
    afx_msg void OnEnterSizeMove();

    /// \brief 指示用户正在移动 `CWnd` 对象。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onmoving
    afx_msg void OnMoving(UINT fwSide, LPRECT pRect);

    /// \brief 指示用户正在调整矩形大小。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onsizing
    afx_msg void OnSizing(UINT fwSide, LPRECT pRect);

    /// \brief 当大小、位置或 Z 顺序即将会因调用而更改时调用`SetWindowPos`或另一个窗口管理函数。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onwindowposchanging
    afx_msg void OnWindowPosChanging(WINDOWPOS *lpwndpos);

    /// \brief 指示窗口退出移动或尺寸调整循环。。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onexitsizemove
    afx_msg void OnExitSizeMove();

    /// \brief 在 `CWnd` 的位置已更改之后调用。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onmove
    afx_msg void OnMove(INT x, INT y);

    /// \brief 当需要计算工作区的大小和位置时调用。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onnccalcsize
    afx_msg void OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS *lpncsp);

    /// \brief 在 `CWnd` 的大小已更改之后调用。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onsize
    afx_msg void OnSize(UINT nType, INT cx, INT cy);

    /// \brief 当大小、位置或 Z 顺序已因调用而更改时调用`SetWindowPos`或另一个窗口管理函数。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onwindowposchanged
    afx_msg void OnWindowPosChanged(WINDOWPOS *lpwndpos);

    /// \brief 要激活或停用应用程序时调用。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onactivateapp
    afx_msg void OnActivateApp(BOOL bActive, DWORD dwThreadID);

    /// \brief 当需要更改非工作区以指示活动或非活动状态时调用。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onncactivate
    afx_msg BOOL OnNcActivate(BOOL bActive);

    /// \brief 当正在激活或停用 `CWnd` 时调用。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onactivate
    afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);

    /// \brief 当需要绘制非工作区时调用。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onncpaint
    afx_msg void OnNcPaint();

    /// \brief 当窗口背景需要擦除时调用。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onerasebkgnd
    afx_msg BOOL OnEraseBkgnd(CDC *pDC);

    /// \brief 调用以重新绘制窗口的一部分。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onpaint
    afx_msg void OnPaint();

    /// \brief 指示计时器的超时间隔已过。
    /// \details `SetTimer(TimerId::ALPHA, 1000, NULL);`\n
    ///          `KillTimer(TimerId::ALPHA);`
    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#ontimer>
    afx_msg void OnTimer(UINT_PTR nIDEvent);

    /// \brief 自定义消息处理。
    /// \details `PostMessage(PM_CUSTOM_PRIVATE_MESSAGE);`。
    afx_msg LRESULT OnCustomPrivateMessage(WPARAM wParam, LPARAM lParam);

    /// \brief 自定义消息处理。
    /// \details `PostMessage(AM_CUSTOM_APPLICATION_MESSAGE);`。
    afx_msg LRESULT OnCustomApplicationMessage(WPARAM wParam, LPARAM lParam);

    /// \brief 自定义消息处理。
    /// \details `::PostMessage(HWND_BROADCAST, RM_CUSTOM_REGISTER_MESSAGE, NULL, NULL);`。
    afx_msg LRESULT OnCustomRegisteredMessage(WPARAM wParam, LPARAM lParam);

    DECLARE_MESSAGE_MAP()
};

}//namespace rrMFC
