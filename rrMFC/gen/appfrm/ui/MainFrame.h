//===-- Main Frame ----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 主框架（类）。
///
/// \verison 2018-04-23
/// \since 2017-12-08
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "resource.h"
#include "MainView.h"

/// \brief 主框架（类）。
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cframewnd-class
class MainFrame: public CFrameWnd {
    DECLARE_DYNCREATE(MainFrame)

#// Constructors
public:
    MainFrame();

#// Attributes
public:
    enum {IDR = IDR_MAIN_FRAME};

#// Operations
public:

#// Overridables
public:
    virtual ~MainFrame();

protected:
    virtual BOOL PreCreateWindow(CREATESTRUCT &cs);
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult);
    virtual BOOL OnCmdMsg(UINT nID, INT nCode, VOID *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo);

#// Implementation
protected:
    MainView View;

#// Message Handlers
protected:
    afx_msg INT OnCreate(LPCREATESTRUCT lpCreateStruct);

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

    // ACTIVATE

    /// \brief Called when the application is about to be activated or deactivated.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onactivateapp
    afx_msg VOID OnActivateApp(BOOL bActive, DWORD dwThreadID);

    /// \brief Called when the non-client area needs to be changed to indicate an active or inactive state.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onncactivate
    afx_msg BOOL OnNcActivate(BOOL bActive);

    /// \brief Called when `CWnd` is being activated or deactivated.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onactivate
    afx_msg VOID OnActivate(UINT nState, CWnd *pWndOther, BOOL bMinimized);

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

    // SUB-WINDOW

    /// \brief Called after CWnd gains the input focus.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#precreatewindow
    afx_msg VOID OnSetFocus(CWnd *pOldWnd);

    /// \brief Called when a child window is created or destroyed, or when the user clicks a mouse button while the cursor is over the child window.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onparentnotify
    afx_msg VOID OnParentNotify(UINT message, LPARAM lParam);

    // ACTION: CLOSE

    /// \brief Called as a signal that `CWnd` should be closed.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onclose
    afx_msg VOID OnClose();

    DECLARE_MESSAGE_MAP()
};
