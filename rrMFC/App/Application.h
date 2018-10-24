//===-- Application ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 应用类。
///
/// \sa <https://docs.microsoft.com/cpp/mfc/controls-mfc>
///
/// \version 2018-10-24
/// \since 2018-04-11
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

namespace rrMFC {

///
/// \brief 应用类。
/// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class>
///
class Application: public CWinApp {

// Overridables
public:
    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#initinstance>
    BOOL InitInstance() final;

    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#exitinstance>
    int ExitInstance() final;

};

}//namespace rrMFC
