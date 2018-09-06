//===-- List Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 列表对话框类。
///
/// \sa https://docs.microsoft.com/cpp/mfc/using-clistctrl
/// \sa https://docs.microsoft.com/cpp/mfc/reference/clistctrl-class
///
/// \verison 2018-09-05
/// \since 2017-04-04
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

namespace rrMFC {

/// \brief 列表对话框类。
class ListDialog: public CDialog {

#// Constructors
public:
    ListDialog(CWnd *pParent = NULL);

#// Attributes
public:
    static const UINT IDD;
    enum ListColumn { Id, Name, Alias };

#// Operations
public:

#// Overridables
protected:
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult);
    virtual VOID DoDataExchange(CDataExchange *pDX);
    virtual BOOL OnInitDialog();

#// Implementation
protected:
    CListCtrl ListControl;

    VOID InsertListItem(CONST INT itemIndex, CONST DWORD_PTR itemData, CONST CString &id, CONST CString &name, CONST CString &alias);
    INT AppendListItem(CONST DWORD_PTR itemData, CONST CString &id, CONST CString &name, CONST CString &alias);

    VOID ClearListSelected();
    VOID SelectListItem(CONST INT itemIndex);

#// Message Handlers
protected:
    /// \brief LVN_ITEMCHANGED
    /// \sa https://msdn.microsoft.com/library/bb774845
    afx_msg VOID OnLvnItemchangedList(NMHDR *pNMHDR, LRESULT *pResult);

    /// \brief NM_CLICK
    /// \sa https://msdn.microsoft.com/library/bb774863
    afx_msg VOID OnNMClickList(NMHDR *pNMHDR, LRESULT *pResult);

    /// \brief NM_DBLCLK
    /// \sa https://msdn.microsoft.com/library/bb774867
    afx_msg VOID OnNMDblclkList(NMHDR *pNMHDR, LRESULT *pResult);

    /// \brief NM_RCLICK
    /// \sa https://msdn.microsoft.com/library/bb774873
    afx_msg VOID OnNMRClickList(NMHDR *pNMHDR, LRESULT *pResult);

    /// \brief NM_RDBLCLK
    /// \sa https://msdn.microsoft.com/library/bb774875
    afx_msg VOID OnNMRDblclkList(NMHDR *pNMHDR, LRESULT *pResult);

    afx_msg VOID OnBnClickedAppendLastButton();
    afx_msg VOID OnBnClickedDeleteFirstButton();

    DECLARE_MESSAGE_MAP()
};

}//namespace rrMFC
