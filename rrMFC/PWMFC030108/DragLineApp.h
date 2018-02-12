//===-- Class DragLine Application ------------------------------*- C++ -*-===//
///
/// \file
/// \brief DragLine应用类
///
/// \author zhengrr
/// \date 2018-2-9 – 12
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief Class DragLine Application
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class
class CDragLineApp: public CWinApp {
public:
    /// \brief Initialize Instance
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#initinstance
    virtual BOOL InitInstance();
};
