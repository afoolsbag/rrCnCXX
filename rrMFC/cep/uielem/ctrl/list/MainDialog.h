//===-- Main Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 主对话框（类）。

///
/// \verison 2018-04-09
/// \since 2017-04-04
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
    enum ListColumn { Id = 0, Name, Alias };

// Operations
public:

// Overridables
protected:
    virtual VOID DoDataExchange(CDataExchange *pDX);

    virtual BOOL OnInitDialog();

// Implementation
protected:
    CListCtrl ListControl;

    VOID InsertListItem(CONST INT itemIndex, CONST DWORD_PTR itemData, CONST CString &id, CONST CString &name, CONST CString &alias);
    INT AppendListItem(CONST DWORD_PTR itemData, CONST CString &id, CONST CString &name, CONST CString &alias);

    VOID ClearListSelected();
    VOID SelectListItem(CONST INT itemIndex);

// Generated message map functions
protected:
    afx_msg void OnBnClickedAppendLastButton();
    afx_msg void OnBnClickedDeleteFirstButton();

    DECLARE_MESSAGE_MAP()
};
