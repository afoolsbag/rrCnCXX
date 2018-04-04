//===-- Class Shapes Application --------------------------------*- C++ -*-===//
///
/// \file
/// \brief Shapes应用类
///
/// \sa *Programming Windows® with MFC* 4.2
/// \sa ["ID Naming and Numbering Conventions"](https://docs.microsoft.com/cpp/mfc/tn020-id-naming-and-numbering-conventions). *Microsoft® Docs*.
///
/// \author zhengrr
/// \version 2018-03-09
/// \since 2018-02-23
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "resource.h"

/// \brief Class Shapes Application
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class
class CShapesApp: public CWinApp {
public:
    CShapesApp();

    /// \brief Initialize Instance
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#initinstance
    virtual BOOL InitInstance();

protected:
    afx_msg void OnAppAbout();

    DECLARE_MESSAGE_MAP()
};
