//===-- Main Frame ----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 主框架（类）。
///
/// \verison 2018-04-19
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
    // CREATE
    afx_msg BOOL OnNcCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg INT OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg VOID OnShowWindow(BOOL bShow, UINT nStatus);

    // AVTIVATE
    afx_msg VOID OnActivateApp(BOOL bActive, DWORD dwThreadID);
    afx_msg BOOL OnNcActivate(BOOL bActive);
    afx_msg VOID OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);

    // SIZE
    afx_msg VOID OnWindowPosChanging(WINDOWPOS *lpwndpos);
    afx_msg VOID OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS *lpncsp);
    afx_msg VOID OnSize(UINT nType, INT cx, INT cy);
    afx_msg VOID OnWindowPosChanged(WINDOWPOS* lpwndpos);

    // PAINT
    afx_msg VOID OnNcPaint();
    afx_msg BOOL OnEraseBkgnd(CDC *pDC);
    afx_msg VOID OnPaint();

    // MOVE
    // OnWindowPosChanging
    afx_msg VOID OnMove(INT x, INT y);
    // OnWindowPosChanged

    // DESTROY
    afx_msg VOID OnClose();
    // ShowWindow
    afx_msg VOID OnDestroy();
    afx_msg VOID OnNcDestroy();

    // OTHER
    afx_msg VOID OnNcRenderingChanged(BOOL bIsRendering);
    afx_msg VOID OnParentNotify(UINT message, LPARAM lParam);
    afx_msg VOID OnSetFocus(CWnd *pOldWnd);

    DECLARE_MESSAGE_MAP()
};
