//===-- Class Combo Box List Main Window ------------------------*- C++ -*-===//
///
/// \file
/// \brief 组合框列表主窗口类
///
/// \author zhengrr
/// \date 2018-2-8 – 11
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "ComboBoxList/ComboBoxListCtrl.h"

/// \brief Class (Combo Box List App) Main Window
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cframewnd-class
class CComboBoxListMainWnd: public CFrameWnd {
public:
    CComboBoxListMainWnd();

protected:
    /// \brief On Create
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#oncreate
    afx_msg INT OnCreate(LPCREATESTRUCT lpCreateStruct);

    CComboBoxListCtrl combo_box_list_ctrl_;

    DECLARE_MESSAGE_MAP()
};
