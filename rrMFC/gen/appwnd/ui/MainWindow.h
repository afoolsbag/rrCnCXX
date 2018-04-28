//===-- Main Window ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 主窗口（类）。
///
/// \verison 2018-04-28
/// \since 2018-04-27
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief 主窗口（类）。
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class
class MainWindow: public CWnd {
    DECLARE_DYNCREATE(MainWindow)

#// Constructors
public:
    MainWindow();

    /// \brief 创建并初始化与 `CWnd` 对象关联的子窗口。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#create
    virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, CONST RECT &rect, CWnd *pParentWnd, UINT nID, CCreateContext *pContext = NULL) override;

    /// \brief 创建 Windows 重叠、弹出或子窗口，并将它附加到 `CWnd` 对象。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#createex
    virtual BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, INT x, INT y, INT nWidth, INT nHeight, HWND hWndParent, HMENU nIDorHMenu, LPVOID lpParam = NULL) override;

    /// \brief 创建 Windows 重叠、弹出或子窗口，并将它附加到 `CWnd` 对象。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#createex
    virtual BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, CONST RECT &rect, CWnd *pParentWnd, UINT nID, LPVOID lpParam = NULL) override;

    virtual ~MainWindow() override;

#// Attributes
public:

#// Operations
public:

#// Overridables
public:
    /// \brief 在创建附加到此 `CWnd` 对象的 Windows 窗口之前调用。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#precreatewindow
    virtual BOOL PreCreateWindow(CREATESTRUCT &cs) override;

    /// \brief 路由和调度命令消息。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/ccmdtarget-class#oncmdmsg
    virtual BOOL OnCmdMsg(UINT nID, INT nCode, VOID *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo) override;

protected:
    /// \brief 指示是否处理了 Windows 消息。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onwndmsg
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult) override;

    /// \brief 用于对话框数据交换和验证。 由 `UpdateData` 调用。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class
    virtual VOID DoDataExchange(CDataExchange *pDX) override;

    /// \brief 默认情况下调用此虚拟函数`OnNcDestroy`函数在窗口已销毁之后。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#postncdestroy
    virtual VOID PostNcDestroy() override;

#// Implementation
protected:

#// Message Handlers
protected:

    // CREATE & DESTROY

    /// \brief 之前调用OnCreate的非工作区在创建时。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onnccreate
    afx_msg BOOL OnNcCreate(LPCREATESTRUCT lpCreateStruct);

    /// \brief 在窗口创建过程中调用。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#oncreate
    afx_msg INT OnCreate(LPCREATESTRUCT lpCreateStruct);

    /// \brief 当销毁 `CWnd` 时调用。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#ondestroy
    afx_msg VOID OnDestroy();

    /// \brief 当销毁非工作区时调用。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onncdestroy
    afx_msg VOID OnNcDestroy();

    // MOVE & SIZE

    /// \brief 每当 Windows 需要知道最大化位置或尺寸或是最小或最大跟踪大小时调用。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#ongetminmaxinfo
    afx_msg VOID OnGetMinMaxInfo(MINMAXINFO *lpMMI);

    /// \brief 在受影响的窗口进入移动或大小调整模式循环之后调用。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onentersizemove
    afx_msg VOID OnEnterSizeMove();

    /// \brief 指示用户正在移动 `CWnd` 对象。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onmoving
    afx_msg VOID OnMoving(UINT fwSide, LPRECT pRect);

    /// \brief 指示用户正在调整矩形大小。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onsizing
    afx_msg VOID OnSizing(UINT fwSide, LPRECT pRect);

    /// \brief 当大小、位置或 Z 顺序即将会因调用而更改时调用`SetWindowPos`或另一个窗口管理函数。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onwindowposchanging
    afx_msg VOID OnWindowPosChanging(WINDOWPOS *lpwndpos);

    /// \brief 在受影响的窗口退出移动或大小调整模式循环之后调用。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onexitsizemove
    afx_msg VOID OnExitSizeMove();

    /// \brief 在 `CWnd` 的位置已更改之后调用。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onmove
    afx_msg VOID OnMove(INT x, INT y);

    /// \brief 当需要计算工作区的大小和位置时调用。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onnccalcsize
    afx_msg VOID OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS *lpncsp);

    /// \brief 在 `CWnd` 的大小已更改之后调用。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onsize
    afx_msg VOID OnSize(UINT nType, INT cx, INT cy);

    /// \brief 当大小、位置或 Z 顺序已因调用而更改时调用`SetWindowPos`或另一个窗口管理函数。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onwindowposchanged
    afx_msg VOID OnWindowPosChanged(WINDOWPOS *lpwndpos);

    // STATE & STATUS

    /// \brief 要激活或停用应用程序时调用。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onactivateapp
    afx_msg VOID OnActivateApp(BOOL bActive, DWORD dwThreadID);

    /// \brief 当需要更改非工作区以指示活动或非活动状态时调用。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onncactivate
    afx_msg BOOL OnNcActivate(BOOL bActive);

    /// \brief 当正在激活或停用 `CWnd` 时调用。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onactivate
    afx_msg VOID OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);

    // PAINT

    /// \brief 当需要绘制非工作区时调用。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onncpaint
    afx_msg VOID OnNcPaint();

    /// \brief 当窗口背景需要擦除时调用。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onerasebkgnd
    afx_msg BOOL OnEraseBkgnd(CDC *pDC);

    /// \brief 调用以重新绘制窗口的一部分。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onpaint
    afx_msg VOID OnPaint();

    DECLARE_MESSAGE_MAP()
};
