//===-- Class Shapes Application --------------------------------*- C++ -*-===//
///
/// \file
/// \brief Shapes应用类
///
/// `resource.h`:
/// | prefix | Recommend Range | brief            | Required Range  |               |
/// |:------ | ---------------:|:---------------- | ---------------:| -------------:|
/// | `IDF`  |     `101–  285` | frame            |    `0x1–0x6FFF` |     `1–28671` |
/// | `IDR`  |   `101xx–285xx` | multiple         |    `0x1–0x6FFF` |     `1–28671` |
/// | `IDC`  |   `101xx–285xx` | cursors          |    `0x1–0x6FFF` |     `1–28671` |
/// | `IDI`  |   `101xx–285xx` | icons            |    `0x1–0x6FFF` |     `1–28671` |
/// | `IDM`  |   `101xx–285xx` | menus            |    `0x1–0x6FFF` |     `1–28671` |
/// | `IDA`  |   `101xx–285xx` | accelerator      |    `0x1–0x6FFF` |     `1–28671` |
/// | `IDD`  |   `101xx–285xx` | dialog templates |    `0x1–0x6FFF` |     `1–28671` |
/// | `IDB`  |   `101xx–285xx` | bitmaps          |    `0x1–0x6FFF` |     `1–28671` |
/// | `IDS`  |   `101xx–285xx` | strings          |    `0x1–0x7FFF` |     `1–32767` |
/// | `IDP`  |   `101xx–285xx` | prompts          |    `0x1–0x7FFF` |     `1–32767` |
/// | `ID`   |   `40001–49999` | commands         | `0x8000–0xDFFF` | `32768–57343` |
/// | `IDC`  |   `50001–57343` | controls         |    `0x8–0xDFFF` |     `8–57343` |
///
/// \sa *Programming Windows® with MFC* 4.2
/// \sa ["ID Naming and Numbering Conventions"](https://docs.microsoft.com/cpp/mfc/tn020-id-naming-and-numbering-conventions). *Microsoft® Docs*.
///
/// \author zhengrr
/// \version 2018-03-09
/// \since 2018-02-23
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "resource.h"

/// \brief Class Shapes Application
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class
class CShapesApp: public CWinApp {
public:
    CShapesApp();

    /// \brief Initialize Instance
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#initinstance
    virtual BOOL InitInstance();

protected:
    afx_msg void OnAppAbout();

    DECLARE_MESSAGE_MAP()
};
