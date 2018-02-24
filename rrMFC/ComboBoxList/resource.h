//===-- Resource Header -----------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 资源头文件
///
/// \sa ["ID Naming and Numbering Conventions"](https://docs.microsoft.com/cpp/mfc/tn020-id-naming-and-numbering-conventions). *Microsoft® Docs*.
///
/// \author zhengrr
/// \version 2018-2-24
/// \since 2018-2-8
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

// IDR multiple
// 0x   1–0x6FFF     1–28671
//                 100– 5000

// IDD dialog templates
// 0x   1–0x6FFF     1–28671
//                5000–10000

// IDC cursors
// 0x   1–0x6FFF     1–28671
//               10001–15000

// IDI icons
// 0x   1–0x6FFF     1–28671
//               15001–20000

// IDB bitmaps
// 0x   1–0x6FFF     1–28671
//               20001–25000

// IDS strings
// 0x   1–0x7FFF     1–32767
//               25001–30000

// IDP prompts
// 0x   1–0x7FFF     1–32767
//               30001–32767

// ID commands
// 0x8000–0xDFFF 32768–57343
//               35001–40000

// IDC controls
// 0x   8–0xDFFF     8–57343
//               40001–45000

#define IDC_COMBO_BOX_LIST 100
