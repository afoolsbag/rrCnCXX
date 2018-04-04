//===-- Class Application ---------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 应用类。
///
/// \sa *Programming Windows? with MFC* §1.3
///
/// \version 2018-04-04
/// \since 2017-12-08
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief Class Application
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class
class CApp: public CWinApp {
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
