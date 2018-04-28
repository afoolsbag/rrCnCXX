//===-- Main Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 侧对话框（类）。
///
/// \verison 2018-04-28
/// \since 2018-04-23
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "resource.h"

/// \brief 侧对话框（类）。
class SideDialog: public CDialog {
    DECLARE_DYNCREATE(SideDialog)

#// Constructors
public:
    SideDialog(CWnd *pParent = NULL);
    virtual ~SideDialog() override;

#// Attributes
public:
    enum { IDD = IDD_SIDE_DIALOG };

#// Operations
public:

#// Overridables
protected:
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult);

#// Implementation
protected:

#// Message Handlers
protected:
    afx_msg VOID OnMove(INT x, INT y);

    DECLARE_MESSAGE_MAP()
};
