//===-- Dialog --------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 对话框（类）。
///
/// \verison 2018-06-09
/// \since 2018-04-04
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "resource.h"

/// \brief 对话框（类）。
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cdialog-class
class Dialog: public CDialog {

#// Constructors
public:
    Dialog(CWnd *pParent = NULL);

    /// \brief 初始化 `CDialog` 对象。 创建无模式对话框，并将其附加到`CDialog`对象。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cdialog-class#create
    virtual BOOL Create(LPCTSTR lpszTemplateName, CWnd *pParentWnd = NULL) override;

    /// \brief 初始化 `CDialog` 对象。 创建无模式对话框，并将其附加到`CDialog`对象。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cdialog-class#create
    virtual BOOL Create(UINT nIDTemplate, CWnd *pParentWnd = NULL) override;

    /// \brief 从内存中的对话框模板 （而不是基于资源） 来创建无模式对话框。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cdialog-class#createindirect
    virtual BOOL CreateIndirect(LPCDLGTEMPLATE lpDialogTemplate, CWnd *pParentWnd = NULL, VOID *lpDialogInit = NULL) override;

    /// \brief 从内存中的对话框模板 （而不是基于资源） 来创建无模式对话框。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cdialog-class#createindirect
    virtual BOOL CreateIndirect(HGLOBAL hDialogTemplate, CWnd *pParentWnd = NULL) override;

    /// \brief 调用模式对话框并返回完成。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cdialog-class#domodal
    virtual INT_PTR DoModal() override;

    virtual ~Dialog() override;

#// Attributes
public:
    enum { IDD = IDD_DIALOG };

#// Operations
public:

#// Overridables
public:
    /// \brief 重写以增加对话框中初始化。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cdialog-class#oninitdialog
    virtual BOOL OnInitDialog() override;

    virtual BOOL OnCmdMsg(UINT nID, INT nCode, VOID *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo) override;

protected:
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult) override;

    /// \remark 没有说明的。
    virtual VOID PreInitDialog() override;

    virtual VOID DoDataExchange(CDataExchange *pDX) override;

    /// \brief 重写以执行模式对话框中的确定按钮的操作。 关闭对话框，默认值和DoModal返回IDOK。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cdialog-class#onok
    virtual VOID OnOK() override;

    /// \brief 重写以执行的取消按钮或 ESC 键操作。 关闭对话框，默认值和DoModal返回IDCANCEL。
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cdialog-class#oncancel
    virtual VOID OnCancel() override;

#// Implementation
protected:

#// Message Handlers
protected:

    afx_msg VOID OnClose();

    afx_msg VOID OnBnClickedOk();
    afx_msg VOID OnBnClickedCancel();

    afx_msg VOID OnBnClickedAbort();
    afx_msg VOID OnBnClickedRetry();
    afx_msg VOID OnBnClickedIgnore();

    afx_msg VOID OnBnClickedYes();
    afx_msg VOID OnBnClickedNo();

    afx_msg VOID OnBnClickedClose();
    afx_msg VOID OnBnClickedHelp();

    DECLARE_MESSAGE_MAP()
};
