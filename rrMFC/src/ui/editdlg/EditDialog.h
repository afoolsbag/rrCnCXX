//===-- Edit Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 编辑框对话框类。
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cedit-class
///
/// \verison 2018-09-05
/// \since 2018-05-28
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

namespace rrMFC {

///
/// \brief 编辑框对话框类。
///
class EditDialog: public CDialog {

#// Constructors
public:
    EditDialog(CWnd *pParent = nullptr);
    virtual ~EditDialog() override;

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
    virtual void DoDataExchange(CDataExchange *pDX) override;

#// Implementation
protected:
    CEdit EditControl;

#// Message Handlers
protected:
    /// \sa https://msdn.microsoft.com/library/bb761676
    afx_msg void OnEnChangeEdit();

    DECLARE_MESSAGE_MAP()
};

}//namespace rrMFC
