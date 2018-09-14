//===-- Frame ---------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 框架类。
///
/// \verison 2018-09-14
/// \since 2017-12-08
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include "View.h"

namespace rrMFC {
namespace Test {

/// \brief 框架类。
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cframewnd-class
class Frame: public CFrameWnd {

#// Constructors
public:
    Frame();
    ~Frame() final;

#// Attributes
public:
    static const unsigned IDR;

#// Operations
public:

#// Overridables
public:
    BOOL PreCreateWindow(CREATESTRUCT &cs) final;
    BOOL OnCmdMsg(unsigned nID, int nCode, void *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo) final;

protected:
    BOOL OnWndMsg(unsigned message, WPARAM wParam, LPARAM lParam, LRESULT *pResult) final;

#// Implementation
protected:
    View View;

#// Message Handlers
protected:
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnSetFocus(CWnd *pOldWnd);

    DECLARE_MESSAGE_MAP()
};

}//namespace Test
}//namespace rrMFC
