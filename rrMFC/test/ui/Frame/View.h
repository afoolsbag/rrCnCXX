//===-- View ----------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 视图类。
///
/// \verison 2018-09-14
/// \since 2018-04-11
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

namespace rrMFC {
namespace Test {

/// \brief 视图类。
class View: public CWnd {

#// Constructors
public:
    View();
    ~View() final;

#// Attributes
public:

#// Operations
public:

#// Overridables
public:
    BOOL OnCmdMsg(unsigned nID, int nCode, void *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo) final;

protected:
    BOOL OnWndMsg(unsigned message, WPARAM wParam, LPARAM lParam, LRESULT *pResult) final;

#// Implementation
protected:

#// Message Handlers
protected:
    afx_msg void OnContextMenu(CWnd *pWnd, CPoint point);

    afx_msg void OnCommand5();
    afx_msg void OnUpdateCommand5(CCmdUI *pCmdUI);
    afx_msg void OnCommand6();
    afx_msg void OnUpdateCommand6(CCmdUI *pCmdUI);
    afx_msg void OnCommand7();
    afx_msg void OnUpdateCommand7(CCmdUI *pCmdUI);
    afx_msg void OnUndefined(unsigned nID);
    afx_msg void OnUpdateUndefined(CCmdUI *pCmdUI);
    
    DECLARE_MESSAGE_MAP()
};

}//namespace Test
}//namespace rrMFC
