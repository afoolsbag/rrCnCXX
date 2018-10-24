//===-- Tree Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 树对话框类。
///
/// \sa <https://docs.microsoft.com/cpp/mfc/using-ctreectrl>
/// \sa <https://docs.microsoft.com/cpp/mfc/reference/ctreectrl-class>
///
/// \verison 2018-10-24
/// \since 2017-04-20
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

namespace rrMFC {

///
/// \brief 树对话框类。
///
class TreeDialog: public CDialog {

// Constructors
public:
    TreeDialog(CWnd *pParent = nullptr)
        : CDialog(IDD, pParent)
    {}

// Attributes
public:
    static const unsigned IDD;

// Overridables
public:
    BOOL OnInitDialog() override;
protected:
    void DoDataExchange(CDataExchange *pDX) override;

// Implementation
protected:
    CTreeCtrl TreeControl;
    void SyncChildCheck(HTREEITEM const item);
    void SyncParentCheck(HTREEITEM const item);
    HTREEITEM FindMatchedItem(const CString &token) const;
    HTREEITEM FindMatchedItem(const CString &token, HTREEITEM const itemTih) const;
    CEdit FindEditControl;

// Message Handlers
protected:
    /// \sa <https://msdn.microsoft.com/library/bb773466>
    afx_msg void OnNMClickTree(NMHDR *pNMHDR, LRESULT *pResult);

    /// \sa <https://msdn.microsoft.com/library/bb773475>
    afx_msg void OnNMDblclkTree(NMHDR *pNMHDR, LRESULT *pResult);

    /// \sa <https://msdn.microsoft.com/library/bb773540>
    afx_msg void OnTvnKeydownTree(NMHDR *pNMHDR, LRESULT *pResult);

    /// \sa <https://msdn.microsoft.com/library/bb773547>
    afx_msg void OnTvnSelchangingTree(NMHDR *pNMHDR, LRESULT *pResult);
    /// \sa <https://msdn.microsoft.com/library/bb773544>
    afx_msg void OnTvnSelchangedTree(NMHDR *pNMHDR, LRESULT *pResult);

    /// \sa <https://msdn.microsoft.com/library/bb773530>
    afx_msg void OnTvnItemChangingTree(NMHDR *pNMHDR, LRESULT *pResult);
    /// \sa <https://msdn.microsoft.com/library/bb773526>
    afx_msg void OnTvnItemChangedTree(NMHDR *pNMHDR, LRESULT *pResult);

    afx_msg void OnEnChangeFindEdit();

    DECLARE_MESSAGE_MAP()
};

}//namespace rrMFC
