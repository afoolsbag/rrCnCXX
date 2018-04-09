//===-- Main Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 主对话框（类）。
///
/// \verison 2018-04-09
/// \since 2018-04-09
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief 主对话框（类）。
class MainDialog: public CDialog {
    DECLARE_DYNCREATE(MainDialog)

// Constructors
public:
    MainDialog(CWnd *pParent = NULL);

// Attributes
public:

// Operations
public:

// Overridables
protected:
    virtual VOID DoDataExchange(CDataExchange *pDX);

    /// \brief On Initialize Dialog
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cdialog-class#oninitdialog
    virtual BOOL OnInitDialog();

// Implementation
protected:
    enum TimerId { Zero = 0, Increase };

    CStatic ContextControl;

// Message Handlers
protected:
    afx_msg VOID OnTimer(UINT_PTR nIDEvent);

    DECLARE_MESSAGE_MAP()
};
