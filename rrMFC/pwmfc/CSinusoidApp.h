//===-- Class Sinusoid Application ------------------------------*- C++ -*-===//
///
/// \defgroup g_pwmfc_sinusoid 正弦曲线（§2.2.1）
/// \ingroup g_pwmfc
///
/// \sa *Programming Windows with MFC* §2.2.1
///
/// \author zhengrr
/// \date 2017-12-8 – 2018-2-5
/// \copyright The MIT License
///
/// @{
//===----------------------------------------------------------------------===//

#define VC_EXTRALEAN
#include <afxwin.h>


/// \brief Class Sinusoid Application
class CSinusoidApp: public CWinApp {
public:
    virtual BOOL InitInstance();
};


/// \brief Class Sinusoid Main Window
class CSinusoidMainWnd: public CFrameWnd {
public:
    CSinusoidMainWnd();

protected:
    afx_msg void OnPaint();

    DECLARE_MESSAGE_MAP()
};


/// @}
