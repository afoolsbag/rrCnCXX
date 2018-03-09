//===-- Class Shapes Child View ---------------------------------*- C++ -*-===//
///
/// \file
/// \brief Shapes子视图类
///
/// \author zhengrr
/// \version 2018-2-23
/// \date 2018-2-23
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "resource.h"

/// \brief Class Shapes Child View
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class
class CShapesChildView: public CWnd {
public:
    CShapesChildView();
    virtual ~CShapesChildView();

protected:
    INT m_nShape;

    /// \brief Pre Create Window
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#precreatewindow
    virtual BOOL PreCreateWindow(CREATESTRUCT &cs);

    /// \brief On Paint
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onpaint
    afx_msg VOID OnPaint();

    afx_msg VOID OnShapeCircle();
    afx_msg VOID OnShapeTriangle();
    afx_msg VOID OnShapeSquare();
    afx_msg VOID OnUpdateShapeCircle(CCmdUI* pCmdUI);
    afx_msg VOID OnUpdateShapeTriangle(CCmdUI* pCmdUI);
    afx_msg VOID OnUpdateShapeSquare(CCmdUI* pCmdUI);

    DECLARE_MESSAGE_MAP()
};
