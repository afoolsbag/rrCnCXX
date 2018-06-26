//===-- Frame ---------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 框架（类）。
///
/// \verison 2018-06-12
/// \since 2017-12-08
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "resource.h"
#include "Vw.h"

/// \brief 框架（类）。
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cframewnd-class
class Frame: public CFrameWnd {

#// Constructors
public:
    Frame();
    virtual ~Frame() override;

#// Attributes
public:
    enum { IDR = IDR_FRAME };

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
    View View;

#// Message Handlers
protected:
    afx_msg INT OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg VOID OnSetFocus(CWnd *pOldWnd);

    DECLARE_MESSAGE_MAP()
};