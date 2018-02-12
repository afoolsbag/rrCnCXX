//===-- Class Window Main Window --------------------------------*- C++ -*-===//
///
/// \file
/// \brief 窗口（主窗口）主窗口类
///
/// \author zhengrr
/// \date 2017-12-9 – 2018-2-11
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief Class (Window App) Main Window
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cframewnd-class
class CWindowMainWnd: public CFrameWnd {
public:
    CWindowMainWnd();

protected:
    /// \brief Post Non-Client Destroy
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#postncdestroy
    virtual VOID PostNcDestroy();

    /// \brief On Paint
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onpaint
    afx_msg VOID OnPaint();

    DECLARE_MESSAGE_MAP()
};
