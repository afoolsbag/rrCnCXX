//===-- Edit Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 编辑框对话框类。
///
/// \sa <https://docs.microsoft.com/cpp/mfc/reference/cedit-class>
///
/// \verison 2018-09-14
/// \since 2018-05-28
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

namespace rrMFC {
namespace Test {

///
/// \brief 编辑框对话框类。
///
class EditDialog: public CDialog {

#// Constructors
public:
    EditDialog(CWnd *pParent = nullptr);
    ~EditDialog() final;

#// Attributes
public:
    static const unsigned IDD;

#// Operations
public:

#// Overridables
public:
    BOOL OnInitDialog() final;
protected:
    BOOL OnWndMsg(unsigned message, WPARAM wParam, LPARAM lParam, LRESULT *pResult) final;
    void DoDataExchange(CDataExchange *pDX) final;

#// Implementation
protected:
    CEdit EditControl;

#// Message Handlers
protected:
    /// \sa https://msdn.microsoft.com/library/bb761676
    afx_msg void OnEnChangeEdit();

    DECLARE_MESSAGE_MAP()
};

}//namespace Test
}//namespace rrMFC
