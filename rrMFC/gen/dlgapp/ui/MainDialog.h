//===-- Main Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 主对话框（类）。
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cdialog-class
///
/// \verison 2018-04-12
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
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
    virtual VOID DoDataExchange(CDataExchange *pDX);
    virtual BOOL OnInitDialog();

#// Implementation
protected:

#// Message Handlers
protected:
    afx_msg INT OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg VOID OnSize(UINT nType, INT cx, INT cy);
    afx_msg VOID OnClose();
    afx_msg VOID OnDestroy();

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
