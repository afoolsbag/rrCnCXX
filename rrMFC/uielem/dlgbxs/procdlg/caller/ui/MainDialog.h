//===-- Main Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 主对话框（类）。
///
/// \verison 2018-04-23
/// \since 2018-04-23
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
    virtual VOID DoDataExchange(CDataExchange *pDX);
    virtual VOID OnOK();
    virtual VOID OnCancel();

#// Implementation
protected:
    CEdit PathEdit;

#// Message Handlers
protected:
    afx_msg VOID OnBnClickedBrowseButton();

    afx_msg LRESULT OnRrmfcProcessDialogCalleeCreating(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnRrmfcProcessDialogCalleeDestroying(WPARAM wParam, LPARAM lParam);

    DECLARE_MESSAGE_MAP()
};
