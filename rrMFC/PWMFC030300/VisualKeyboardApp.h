//===-- Class VisualKeyboard Application ------------------------*- C++ -*-===//
///
/// \file
/// \brief VisualKeyboard应用类
///
/// \sa *Programming Windows® with MFC* 3.3
///
/// \author zhengrr
/// \date 2018-2-9 – 12
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief Class VisualKeyboard Application
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class
class CVisualKeyboardApp: public CWinApp {
public:
    /// \brief Initialize Instance
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#initinstance
    virtual BOOL InitInstance();
};
