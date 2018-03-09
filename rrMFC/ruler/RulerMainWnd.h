//===-- Class Ruler Main Window ---------------------------------*- C++ -*-===//
///
/// \file
/// \brief Ruler主窗口类
///
/// \author zhengrr
/// \date 2018-2-12
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief Class Ruler Main Window
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cframewnd-class
class CRulerMainWnd: public CFrameWnd {
public:
    CRulerMainWnd();

protected:
    /// \brief On Paint
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onpaint
    afx_msg VOID OnPaint();

    DECLARE_MESSAGE_MAP()
};
