//===-- List Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 列表对话框类。
///
/// \sa <https://docs.microsoft.com/cpp/mfc/using-clistctrl>
/// \sa <https://docs.microsoft.com/cpp/mfc/reference/clistctrl-class>
///
/// \verison 2018-09-14
/// \since 2017-04-04
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

namespace rrMFC {
namespace Test {

/// \brief 列表对话框类。
class ListDialog: public CDialog {

#// Constructors
public:
    ListDialog(CWnd *pParent = nullptr);

#// Attributes
public:
    static const unsigned IDD;
    enum ListColumn { Id, Name, Alias };

#// Operations
public:

#// Overridables
protected:
    BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult) final;
    void DoDataExchange(CDataExchange *pDX) final;
    BOOL OnInitDialog() final;

#// Implementation
protected:
    CListCtrl ListControl;

    void InsertListItem(const int itemIndex, const DWORD_PTR itemData, const CString &id, const CString &name, const CString &alias);
    INT AppendListItem(const DWORD_PTR itemData, const CString &id, const CString &name, const CString &alias);

    void ClearListSelected();
    void SelectListItem(const int itemIndex);

#// Message Handlers
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

}//namespace Test
}//namespace rrMFC
