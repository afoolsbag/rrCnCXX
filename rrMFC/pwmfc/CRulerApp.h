//===-- Class Ruler Application ---------------------------------*- C++ -*-===//
///
/// \defgroup g_pwmfc_ruler 尺（§2.2.12）
/// \ingroup g_pwmfc
///
/// \sa *Programming Windows with MFC* §2.2.12
///
/// \author zhengrr
/// \date 2017-12-8 – 2018-2-6
/// \copyright The MIT License
///
/// @{
//===----------------------------------------------------------------------===//

#define VC_EXTRALEAN
#include <afxwin.h>


/// \brief Class Ruler Application
class CRulerApp: public CWinApp {
public:
    virtual BOOL InitInstance();
};


/// \brief Class Ruler Main Window
class CRulerMainWnd: public CFrameWnd {
public:
    CRulerMainWnd();

protected:
    afx_msg void OnPaint();

    DECLARE_MESSAGE_MAP()
};


/// @}
