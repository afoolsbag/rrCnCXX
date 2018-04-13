//===-- Main Frame ----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 主框架（类）。
///
/// \verison 2018-04-13
/// \since 2017-12-08
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "MainView.h"

/// \brief 主框架（类）。
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cframewnd-class
class MainFrame: public CFrameWnd {
    DECLARE_DYNCREATE(MainFrame)

#// Constructors
public:
    MainFrame();

#// Attributes
public:

#// Operations
public:

#// Overridables
public:
    virtual ~MainFrame();
protected:
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult);
    virtual BOOL PreCreateWindow(CREATESTRUCT &cs);
    virtual BOOL OnCmdMsg(UINT nID, INT nCode, VOID *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo);

#// Implementation
protected:
    MainView View;

#// Message Handlers
protected:
    afx_msg INT OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg VOID OnSetFocus(CWnd *pOldWnd);

    DECLARE_MESSAGE_MAP()
};
