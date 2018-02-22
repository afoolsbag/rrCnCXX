//===-- Class HTTP File Application -----------------------------*- C++ -*-===//
///
/// \file
/// \brief HttpFile应用类
///
/// \author zhengrr
/// \version 2018-2-22
/// \since 2018-2-22
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief Class HttpFile Application
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class
class CHttpFileApp: public CWinApp {
public:
    /// \brief Initialize Instance
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#initinstance
    virtual BOOL InitInstance();
};
