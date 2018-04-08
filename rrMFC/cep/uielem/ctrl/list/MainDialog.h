//===-- Main Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 主对话框（类）。

///
/// \verison 2018-04-08
/// \since 2017-04-04
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief 主对话框（类）。
class MainDialog: public CDialog {
    DECLARE_DYNCREATE(MainDialog)
public:
    MainDialog(CWnd *pParent = NULL);

    enum ListColumn { Id = 0, Name, Alias };

// Attributes
public:

private:
    CListCtrl ListCtrl;

// Operations
public:

// Overrides
public:
    virtual BOOL OnInitDialog();

protected:
    virtual void DoDataExchange(CDataExchange *pDX);

// Implementation
public:

// Generated message map functions
protected:
    DECLARE_MESSAGE_MAP()

public:
    afx_msg void OnBnClickedInsertOneButton();
};
