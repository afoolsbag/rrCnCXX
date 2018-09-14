//===-- Dialog --------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 对话框类。
///
/// \verison 2018-09-14
/// \since 2018-04-04
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

namespace rrMFC {
namespace Test {

/// \brief 对话框类。
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cdialog-class
class Dialog: public CDialog {

#// Constructors
public:
    Dialog(CWnd *pParent = nullptr);

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cdialog-class#create>
    BOOL Create(LPCTSTR lpszTemplateName, CWnd *pParentWnd = NULL) final;

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cdialog-class#create>
    BOOL Create(unsigned nIDTemplate, CWnd *pParentWnd = NULL) final;

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cdialog-class#createindirect>
    BOOL CreateIndirect(LPCDLGTEMPLATE lpDialogTemplate, CWnd *pParentWnd = NULL, void *lpDialogInit = NULL) final;

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cdialog-class#createindirect>
    BOOL CreateIndirect(HGLOBAL hDialogTemplate, CWnd *pParentWnd = NULL) final;

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cdialog-class#domodal>
    INT_PTR DoModal() final;

    ~Dialog() final;

#// Attributes
public:
    static const unsigned IDD;

#// Operations
public:

#// Overridables
public:
    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cdialog-class#oninitdialog>
    BOOL OnInitDialog() final;

    BOOL OnCmdMsg(unsigned nID, int nCode, void *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo) final;

protected:
    BOOL OnWndMsg(unsigned message, WPARAM wParam, LPARAM lParam, LRESULT *pResult) final;

    void PreInitDialog() final;

    void DoDataExchange(CDataExchange *pDX) final;

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cdialog-class#onok>
    void OnOK() final;

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cdialog-class#oncancel>
    void OnCancel() final;

#// Implementation
protected:

#// Message Handlers
protected:
    afx_msg void OnClose();

    afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedCancel();

    afx_msg void OnBnClickedAbort();
    afx_msg void OnBnClickedRetry();
    afx_msg void OnBnClickedIgnore();

    afx_msg void OnBnClickedYes();
    afx_msg void OnBnClickedNo();

    afx_msg void OnBnClickedClose();
    afx_msg void OnBnClickedHelp();

    DECLARE_MESSAGE_MAP()
};

}//namespace Test
}//namespace rrMFC
