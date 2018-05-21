//===-- Main Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 主对话框（类）。
///
/// \sa https://docs.microsoft.com/cpp/mfc/using-ctreectrl
/// \sa https://docs.microsoft.com/cpp/mfc/reference/ctreectrl-class
///
/// \verison 2018-05-19
/// \since 2017-04-20
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "resource.h"

/// \brief 主对话框（类）。
class MainDialog: public CDialog {
    DECLARE_DYNCREATE(MainDialog)

#// Constructors
public:
    MainDialog(CWnd *pParent = NULL);
    virtual ~MainDialog() override;

#// Attributes
public:
    enum { IDD = IDD_MAIN_DIALOG };

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

    DECLARE_MESSAGE_MAP()
};
