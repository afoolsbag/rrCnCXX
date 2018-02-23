//===-- Class Shapes Main Frame ---------------------------------*- C++ -*-===//
///
/// \file
/// \brief Shapes主框架类
///
/// \author zhengrr
/// \version 2018-2-23
/// \date 2018-2-23
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "ShapesChildView.h"

/// \brief Class Shapes Main Frame
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cframewnd-class
class CShapesMainFrm: public CFrameWnd {
    DECLARE_DYNAMIC(CShapesMainFrm)

public:
    CShapesMainFrm();
    virtual ~CShapesMainFrm();

    /// \brief Pre Create Window
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#precreatewindow
    virtual BOOL PreCreateWindow(CREATESTRUCT &cs);

    /// \brief On Cmd Msg
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/ccmdtarget-class#oncmdmsg
    virtual BOOL OnCmdMsg(UINT nID, INT nCode, VOID *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo);

    CShapesChildView m_wndView;

protected:
    /// \brief On Create
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#oncreate
    afx_msg INT OnCreate(LPCREATESTRUCT lpCreateStruct);

    /// \brief On Set Focus
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onsetfocus
    afx_msg VOID OnSetFocus(CWnd *pOldWnd);

    DECLARE_MESSAGE_MAP()
};
