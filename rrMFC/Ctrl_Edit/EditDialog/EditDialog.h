//===-- Edit Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 编辑框对话框类。
///
/// \sa <https://docs.microsoft.com/cpp/mfc/reference/cedit-class>
///
/// \verison 2018-10-24
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

// Constructors
public:
    EditDialog(CWnd *pParent = nullptr)
        : CDialog(IDD, pParent)
    {}

// Attributes
public:
    static const unsigned IDD;

// Overridables
protected:
    void DoDataExchange(CDataExchange *pDX) final;

// Implementation
protected:
    CEdit EditControl;

// Message Handlers
protected:
    /// \sa <https://msdn.microsoft.com/library/bb761676>
    afx_msg void OnEnChangeEdit();

    DECLARE_MESSAGE_MAP()
};

}//namespace rrMFC
