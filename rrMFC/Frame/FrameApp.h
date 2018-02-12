//===-- Class Frame Application ---------------------------------*- C++ -*-===//
///
/// \file
/// \brief 框架（主窗口）应用类
///
/// \author zhengrr
/// \date 2017-12-8 – 2018-2-11
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief Class (Frame App) Application
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class
class CFrameApp: public CWinApp {
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
