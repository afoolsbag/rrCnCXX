//===-- Class Window Application --------------------------------*- C++ -*-===//
///
/// \file
/// \brief 窗口（主窗口）应用类
///
/// \author zhengrr
/// \date 2017-12-9 – 2018-2-11
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief Class (Window App) Application
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class
class CWindowApp: public CWinApp {
public:
    /// \brief Initialize Instance
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#initinstance
    virtual BOOL InitInstance();
};
