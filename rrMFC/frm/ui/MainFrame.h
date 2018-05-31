//===-- Main Frame ----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 主框架（类）。
///
/// \verison 2018-04-28
/// \since 2017-12-08
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "resource.h"
#include "MainView.h"

/// \brief 主框架（类）。
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cframewnd-class
class MainFrame: public CFrameWnd {
    DECLARE_DYNCREATE(MainFrame)

#// Constructors
public:
    MainFrame();
    virtual ~MainFrame() override;

#// Attributes
public:
    enum { IDR = IDR_MAIN_FRAME };

#// Operations
public:

#// Overridables
public:
    virtual BOOL PreCreateWindow(CREATESTRUCT &cs) override;
    virtual BOOL OnCmdMsg(UINT nID, INT nCode, VOID *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo) override;

protected:
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult) override;

#// Implementation
protected:
    MainView View;

#// Message Handlers
protected:
    afx_msg INT OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg VOID OnSetFocus(CWnd *pOldWnd);

    DECLARE_MESSAGE_MAP()
};
