//===-- Class Drag Line Application -----------------------------*- C++ -*-===//
///
/// \file
/// \brief 拖拽划线应用类
///
/// \author zhengrr
/// \date 2018-2-9 – 11
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief Class (Drag Line App) Application
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class
class CDragLineApp: public CWinApp {
public:
    /// \brief Initialize Instance
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#initinstance
    virtual BOOL InitInstance();
};
