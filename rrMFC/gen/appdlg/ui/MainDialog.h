//===-- Main Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 主对话框（类）。
///
/// \verison 2018-04-23
/// \since 2018-04-04
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief 主对话框（类）。
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cdialog-class
class MainDialog: public CDialog {
    DECLARE_DYNCREATE(MainDialog)

#// Constructors
public:
    MainDialog(CWnd *pParent = NULL);

#// Attributes
public:
    enum { IDD = IDD_MAIN_DIALOG };

#// Operations
public:

#// Overridables
public:
    virtual ~MainDialog();

protected:
    /// \brief Called before the creation of the Windows window attached to this `CWnd` object.
    /// \deprecated `Dialog`中无效的。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#precreatewindow
    virtual BOOL PreCreateWindow(CREATESTRUCT &cs);

    /// \brief Indicates if a windows message was handled.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onwndmsg
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult);

    /// \brief PreInitDialog.
    /// \remark 隐藏的。
    virtual VOID PreInitDialog();

    /// \brief For dialog data exchange and validation. Called by `UpdateData`.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#dodataexchange
    virtual VOID DoDataExchange(CDataExchange *pDX);

    /// \brief Override to augment dialog-box initialization.
    ///        For initialize UI.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cdialog-class#oninitdialog
    virtual BOOL OnInitDialog();

    /// \brief Override to perform the OK button action in a modal dialog box. The default closes the dialog box and `DoModal` returns `IDOK`.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cdialog-class#onok
    virtual VOID OnOK();

    /// \brief Override to perform the Cancel button or ESC key action. The default closes the dialog box and `DoModal` returns `IDCANCEL`.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cdialog-class#oncancel
    virtual VOID OnCancel();

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

    // ACTION: CLOSE

    /// \brief Called as a signal that `CWnd` should be closed.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onclose
    afx_msg VOID OnClose();

    // ACTION: SYSTEN ID BUTTON
    afx_msg VOID OnBnClickedOk();
    afx_msg VOID OnBnClickedCancel();

    afx_msg VOID OnBnClickedAbort();
    afx_msg VOID OnBnClickedRetry();
    afx_msg VOID OnBnClickedIgnore();

    afx_msg VOID OnBnClickedYes();
    afx_msg VOID OnBnClickedNo();

    afx_msg VOID OnBnClickedClose();
    afx_msg VOID OnBnClickedHelp();

    DECLARE_MESSAGE_MAP()
};
