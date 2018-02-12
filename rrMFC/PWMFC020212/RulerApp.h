//===-- Class Ruler Application ---------------------------------*- C++ -*-===//
///
/// \file
/// \brief Ruler应用类
///
/// \sa *Programming Windows® with MFC* 2.2.12
///
/// \author zhengrr
/// \date 2018-2-12
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief Class Ruler Application
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class
class CRulerApp: public CWinApp {
public:
    /// \brief Initialize Instance
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#initinstance
    virtual BOOL InitInstance();
};
