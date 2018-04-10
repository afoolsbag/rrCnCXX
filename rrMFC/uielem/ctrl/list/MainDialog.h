//===-- Main Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 主对话框（类）。
///
/// \sa https://docs.microsoft.com/cpp/mfc/using-clistctrl
/// \sa https://docs.microsoft.com/cpp/mfc/reference/clistctrl-class
///
/// \verison 2018-04-10
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
    /// \brief LVN_ITEMCHANGED
    /// \sa https://msdn.microsoft.com/library/bb774845
    afx_msg void OnLvnItemchangedList(NMHDR *pNMHDR, LRESULT *pResult);

    /// \brief NM_CLICK
    /// \sa https://msdn.microsoft.com/library/bb774863
    afx_msg void OnNMClickList(NMHDR *pNMHDR, LRESULT *pResult);

    /// \brief NM_DBLCLK
    /// \sa https://msdn.microsoft.com/library/bb774867
    afx_msg void OnNMDblclkList(NMHDR *pNMHDR, LRESULT *pResult);
    
    /// \brief NM_RCLICK
    /// \sa https://msdn.microsoft.com/library/bb774873
    afx_msg void OnNMRClickList(NMHDR *pNMHDR, LRESULT *pResult);

    /// \brief NM_RDBLCLK
    /// \sa https://msdn.microsoft.com/library/bb774875
    afx_msg void OnNMRDblclkList(NMHDR *pNMHDR, LRESULT *pResult);

    afx_msg void OnBnClickedAppendLastButton();
    afx_msg void OnBnClickedDeleteFirstButton();

    DECLARE_MESSAGE_MAP()
};
