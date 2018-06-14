//===-- View ----------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 视图（类）。
///
/// \verison 2018-06-12
/// \since 2018-04-11
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief 视图（类）。
class View: public CWnd {

#// Constructors
public:
    View();
    virtual ~View() override;

#// Attributes
public:

#// Operations
public:

#// Overridables
public:
    virtual BOOL OnCmdMsg(UINT nID, INT nCode, VOID *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo) override;

protected:
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult) override;

#// Implementation
protected:

#// Message Handlers
protected:

    afx_msg VOID OnContextMenu(CWnd *pWnd, CPoint point);

    afx_msg VOID OnCommand5();
    afx_msg VOID OnUpdateCommand5(CCmdUI *pCmdUI);
    afx_msg VOID OnCommand6();
    afx_msg VOID OnUpdateCommand6(CCmdUI *pCmdUI);
    afx_msg VOID OnCommand7();
    afx_msg VOID OnUpdateCommand7(CCmdUI *pCmdUI);
    afx_msg VOID OnUndefined(UINT nID);
    afx_msg VOID OnUpdateUndefined(CCmdUI *pCmdUI);
    
    DECLARE_MESSAGE_MAP()
};
