//===-- Frame ---------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 框架类。
///
/// \verison 2018-10-24
/// \since 2017-12-08
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include "View.h"

namespace rrMFC {

///
/// \brief 框架类。
/// \sa <https://docs.microsoft.com/cpp/mfc/reference/cframewnd-class>
///
class Frame: public CFrameWnd {

// Attributes
public:
    static const unsigned IDR;

// Overridables
public:
    BOOL PreCreateWindow(CREATESTRUCT &cs) final;
    BOOL OnCmdMsg(unsigned nID, int nCode, void *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo) final;

// Implementation
protected:
    View View;

// Message Handlers
protected:
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnSetFocus(CWnd *pOldWnd);

    DECLARE_MESSAGE_MAP()
};

}//namespace rrMFC
