//===-- Tree Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 树对话框类。
///
/// \sa https://docs.microsoft.com/cpp/mfc/using-ctreectrl
/// \sa https://docs.microsoft.com/cpp/mfc/reference/ctreectrl-class
///
/// \verison 2018-09-14
/// \since 2017-04-20
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

namespace rrMFC {
namespace Test {

///
/// \brief 主对话框（类）。
///
class TreeDialog: public CDialog {

#// Constructors
public:
    TreeDialog(CWnd *pParent = NULL);
    virtual ~TreeDialog() override;

#// Attributes
public:
    static const UINT IDD;

#// Operations
public:

#// Overridables
public:
    virtual BOOL OnInitDialog() override;
protected:
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult) override;
    virtual VOID DoDataExchange(CDataExchange *pDX) override;

#// Implementation
protected:
    CTreeCtrl TreeControl;
    VOID SyncChildCheck(HTREEITEM CONST item);
    VOID SyncParentCheck(HTREEITEM CONST item);
    HTREEITEM FindMatchedItem(CONST CString &token) CONST;
    HTREEITEM FindMatchedItem(CONST CString &token, HTREEITEM CONST itemTih) CONST;
    CEdit FindEditControl;

#// Message Handlers
protected:
    /// \sa https://msdn.microsoft.com/library/bb773466
    afx_msg VOID OnNMClickTree(NMHDR *pNMHDR, LRESULT *pResult);

    /// \sa https://msdn.microsoft.com/library/bb773475
    afx_msg VOID OnNMDblclkTree(NMHDR *pNMHDR, LRESULT *pResult);

    /// \sa https://msdn.microsoft.com/library/bb773540
    afx_msg VOID OnTvnKeydownTree(NMHDR *pNMHDR, LRESULT *pResult);

    /// \sa https://msdn.microsoft.com/library/bb773547
    afx_msg VOID OnTvnSelchangingTree(NMHDR *pNMHDR, LRESULT *pResult);
    /// \sa https://msdn.microsoft.com/library/bb773544
    afx_msg VOID OnTvnSelchangedTree(NMHDR *pNMHDR, LRESULT *pResult);

    /// \sa https://msdn.microsoft.com/library/bb773530
    afx_msg VOID OnTvnItemChangingTree(NMHDR *pNMHDR, LRESULT *pResult);
    /// \sa https://msdn.microsoft.com/library/bb773526
    afx_msg VOID OnTvnItemChangedTree(NMHDR *pNMHDR, LRESULT *pResult);

    afx_msg VOID OnEnChangeFindEdit();

    DECLARE_MESSAGE_MAP()
};

}//namespace Test
}//namespace rrMFC
