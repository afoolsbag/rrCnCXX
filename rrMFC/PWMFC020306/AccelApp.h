//===-- Class Accel Application ---------------------------------*- C++ -*-===//
///
/// \file
/// \brief Accel应用类
///
/// \sa *Programming Windows® with MFC* 2.3.6
///
/// \author zhengrr
/// \date 2018-2-12
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief Class Accel Application
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class
class CAccelApp: public CWinApp {
public:
    /// \brief Initialize Instance
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#initinstance
    virtual BOOL InitInstance();
};
