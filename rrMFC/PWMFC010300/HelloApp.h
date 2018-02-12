//===-- Class Hello Application ---------------------------------*- C++ -*-===//
///
/// \file
/// \brief Hello应用类
///
/// \sa *Programming Windows® with MFC* §1.3
///
/// \author zhengrr
/// \date 2017-12-8 – 2018-2-12
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief Class Hello Application
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class
class CHelloApp: public CWinApp {
public:
    /// \brief Initialize Instance
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#initinstance
    virtual BOOL InitInstance();

    /// \brief Exit Instance
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#exitinstance
    virtual INT ExitInstance();
};
