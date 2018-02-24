//===-- Class Shapes About Dialog -------------------------------*- C++ -*-===//
///
/// \file
/// \brief Shapes关于对话框类
///
/// \author zhengrr
/// \version 2018-2-23
/// \date 2018-2-23
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "resource.h"

/// \brief Class Shapes About Dialog
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cdialog-class
class CShapesAboutDlg: public CDialog {
public:
    CShapesAboutDlg();

    enum { IDD = IDD_ABOUT };

protected:
    /// \brief Do Data Exchange
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#dodataexchange
    virtual void DoDataExchange(CDataExchange *pDX);

    DECLARE_MESSAGE_MAP()
};
