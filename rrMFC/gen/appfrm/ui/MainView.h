//===-- Main View -----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 主视图（类）。
///
/// \verison 2018-04-19
/// \since 2018-04-11
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief 主视图（类）。
class MainView: public CWnd {
    DECLARE_DYNCREATE(MainView)

#// Constructors
public:
    MainView();

#// Attributes
public:

#// Operations
public:

#// Overridables
public:
    virtual ~MainView();
protected:
    /// \brief Called before the creation of the Windows window attached to this `CWnd` object.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#precreatewindow
    virtual BOOL PreCreateWindow(CREATESTRUCT &cs);

    /// \brief Indicates if a windows message was handled.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onwndmsg
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult);

    /// \brief This virtual function is called by the default `OnNcDestroy` function after the window has been destroyed.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#postncdestroy
    virtual VOID PostNcDestroy();

#// Implementation
protected:

#// Message Handlers
protected:
    // CREATE & DESTROY

    /// \brief Called prior to `OnCreate` when the non-client area is being created.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onnccreate
    afx_msg BOOL OnNcCreate(LPCREATESTRUCT lpCreateStruct);

    /// \brief Called as a part of window creation.
    ///        For initialize resoueces and sub-windows.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#oncreate
    afx_msg INT OnCreate(LPCREATESTRUCT lpCreateStruct);

    /// \brief Called when `CWnd` is being destroyed.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#ondestroy
    afx_msg VOID OnDestroy();

    /// \brief Called when the non-client area is being destroyed.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onncdestroy
    afx_msg VOID OnNcDestroy();

    // STATE & STATUS

    /// \brief Called when the user interface (UI) state should be changed.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onchangeuistate
    afx_msg VOID OnChangeUIState(UINT nAction, UINT nUIElement);

    /// \brief Called to change the user interface (UI) state for the specified window and all its child windows.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onupdateuistate
    afx_msg VOID OnUpdateUIState(UINT nAction, UINT nUIElement);

    /// \brief Called when the rendering policy for the non-client area has changed.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onncrenderingchanged
    afx_msg VOID OnNcRenderingChanged(BOOL bIsRendering);

    /// \brief Called when `CWnd` is to be hidden or shown.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onshowwindow
    afx_msg VOID OnShowWindow(BOOL bShow, UINT nStatus);

    // SIZE & MOVE

    /// \brief Called when the size, position, or Z-order is about to change as a result of a call to SetWindowPos or another window-management function.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onwindowposchanging
    afx_msg VOID OnWindowPosChanging(WINDOWPOS *lpwndpos);

    /// \brief Called when the size and position of the client area need to be calculated.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onnccalcsize.
    afx_msg VOID OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS *lpncsp);

    /// \brief Called after the size of `CWnd` has changed.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onsize
    afx_msg VOID OnSize(UINT nType, INT cx, INT cy);

    /// \brief Called after the position of the `CWnd` has been changed.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onmove
    afx_msg VOID OnMove(INT x, INT y);

    /// \brief Called when the size, position, or Z-order has changed as a result of a call to SetWindowPos or another window-management function.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onwindowposchanged
    afx_msg VOID OnWindowPosChanged(WINDOWPOS *lpwndpos);

    // PAINT

    /// \brief Called when the non-client area needs painting.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onncpaint
    afx_msg VOID OnNcPaint();

    /// \brief Called when the window background needs erasing.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onerasebkgnd
    afx_msg BOOL OnEraseBkgnd(CDC *pDC);

    /// \brief Called to repaint a portion of the window.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onpaint
    afx_msg VOID OnPaint();

    // ACTION

    /// \brief Called when the user clicks the right mouse button in the window.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#oncontextmenu
    afx_msg VOID OnContextMenu(CWnd *pWnd, CPoint point);

    // COMMAND
    afx_msg VOID OnCommand5();
    afx_msg VOID OnUpdateCommand5(CCmdUI *pCmdUI);
    afx_msg VOID OnCommand6();
    afx_msg VOID OnUpdateCommand6(CCmdUI *pCmdUI);
    afx_msg VOID OnCommand7();
    afx_msg VOID OnUpdateCommand7(CCmdUI *pCmdUI);
    afx_msg VOID OnUndefined(UINT nID);
    afx_msg VOID OnUpdateUndefined(CCmdUI *pCmdUI);
    
    DECLARE_MESSAGE_MAP()
};
