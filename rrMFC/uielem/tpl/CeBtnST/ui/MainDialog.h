//===-- Main Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 主对话框（类）。
///
/// \verison 2018-05-02
/// \since 2017-05-02
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "tpl/CeBtnST.h"

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
    CCeButtonST StandardButton;
    CCeButtonST SearchButton;
    CCeButtonST KeysButton;
    CCeButtonST DisabledButton;
    CCeButtonST LampButton;
    CCeButtonST CheckboxButton;
    CCeButtonST WebButton;
    CCeButtonST EMailButton;

#// Message Handlers
protected:

    //DECLARE_MESSAGE_MAP()
};
