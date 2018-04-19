//===-- Main Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 主对话框（类）。
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cdialog-class
///
/// \verison 2018-04-19
/// \since 2018-04-04
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief 主对话框（类）。
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
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult);

    /// \brief Pre-Initialize Dialog.
    virtual VOID PreInitDialog();

    virtual VOID DoDataExchange(CDataExchange *pDX);

    /// \brief On Initialize Dialog.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cdialog-class#oninitdialog
    virtual BOOL OnInitDialog();

    virtual VOID PostNcDestroy();
#// Implementation
protected:

#// Message Handlers
protected:
    // CREATE

    /// \brief On Non-client Create.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onnccreate
    afx_msg BOOL OnNcCreate(LPCREATESTRUCT lpCreateStruct);

    /// \brief On Create.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#oncreate
    afx_msg INT OnCreate(LPCREATESTRUCT lpCreateStruct);

    /// \brief On Show (or Hide) Window.
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onshowwindow
    afx_msg VOID OnShowWindow(BOOL bShow, UINT nStatus);

    // ACTIVATE
    afx_msg VOID OnActivateApp(BOOL bActive, DWORD dwThreadID);
    afx_msg BOOL OnNcActivate(BOOL bActive);
    afx_msg VOID OnActivate(UINT nState, CWnd *pWndOther, BOOL bMinimized);

    // SIZE & MOVE
    afx_msg VOID OnWindowPosChanging(WINDOWPOS *lpwndpos);
    afx_msg VOID OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS *lpncsp);
    afx_msg VOID OnSize(UINT nType, INT cx, INT cy);
    afx_msg VOID OnMove(INT x, INT y);
    afx_msg VOID OnWindowPosChanged(WINDOWPOS *lpwndpos);

    // PAINT
    afx_msg VOID OnNcPaint();
    afx_msg BOOL OnEraseBkgnd(CDC *pDC);
    afx_msg VOID OnPaint();

    // DESTROY
    afx_msg VOID OnClose();
    afx_msg VOID OnDestroy();
    afx_msg VOID OnNcDestroy();

    // OTHER
    afx_msg VOID OnChangeUIState(UINT nAction, UINT nUIElement);
    afx_msg VOID OnNcRenderingChanged(BOOL bIsRendering);

    // CONTROL
    afx_msg VOID OnBnClickedOk();
    afx_msg VOID OnBnClickedCancel();
    afx_msg VOID OnBnClickedAbort();
    afx_msg VOID OnBnClickedRetry();
    afx_msg VOID OnBnClickedIgnore();
    afx_msg VOID OnBnClickedYes();
    afx_msg VOID OnBnClickedNo();
    afx_msg VOID OnBnClickedClose();
    afx_msg VOID OnBnClickedHelp();

    afx_msg VOID OnBnClickedHandButton();
    afx_msg VOID OnBnClickedQuestionButton();
    afx_msg VOID OnBnClickedExclamationButton();
    afx_msg VOID OnBnClickedAsteriskButton();

    DECLARE_MESSAGE_MAP()
};
