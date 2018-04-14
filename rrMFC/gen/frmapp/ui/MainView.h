//===-- Main View -----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 主视图（类）。
///
/// \verison 2018-04-14
/// \since 2018-04-11
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief 主视图（类）。
class MainView: public CWnd {
    DECLARE_DYNCREATE(MainView)

#// Constructors
public:
    MainView();

#// Attributes
public:

#// Operations
public:

#// Overridables
public:
    virtual ~MainView();
protected:
    virtual BOOL PreCreateWindow(CREATESTRUCT &cs);
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult);
    virtual VOID PostNcDestroy();

#// Implementation
protected:

#// Message Handlers
protected:
    // CREATE
    afx_msg BOOL OnNcCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg INT OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg VOID OnShowWindow(BOOL bShow, UINT nStatus);

    // SIZE
    afx_msg VOID OnWindowPosChanging(WINDOWPOS *lpwndpos);
    afx_msg VOID OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp);
    afx_msg VOID OnSize(UINT nType, INT cx, INT cy);
    afx_msg VOID OnWindowPosChanged(WINDOWPOS *lpwndpos);

    // PAINT
    afx_msg VOID OnNcPaint();
    afx_msg BOOL OnEraseBkgnd(CDC *pDC);
    afx_msg VOID OnPaint();

    // MOVE
    // OnWindowPosChanging
    afx_msg VOID OnMove(INT x, INT y);
    // OnWindowPosChanged

    // DESTROY
    afx_msg VOID OnDestroy();
    afx_msg VOID OnNcDestroy();

    // COMMAND
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
