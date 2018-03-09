//===-- Class TicTacToe Application -----------------------------*- C++ -*-===//
///
/// \file
/// \brief TicTacToe应用类
///
/// \sa *Programming Windows® with MFC* 3.1.2
///
/// \author zhengrr
/// \date 2018-2-12
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief Class TicTacToe Application
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class
class CTicTacToeApp: public CWinApp {
public:
    /// \brief Initialize Instance
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#initinstance
    virtual BOOL InitInstance();
};
