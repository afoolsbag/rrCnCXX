//===-- Class Rotate Text Application ---------------------------*- C++ -*-===//
///
/// \defgroup g_pwmfc_rotatetext 旋转文本（§2.2.8）
/// \ingroup g_pwmfc
///
/// \sa *Programming Windows with MFC* §2.2.8
///
/// \author zhengrr
/// \date 2017-12-8 – 2018-2-5
/// \copyright The MIT License
///
/// @{
//===----------------------------------------------------------------------===//

#define VC_EXTRALEAN
#include <afxwin.h>


/// \brief Class Rotate Text Application
class CRotateTextApp: public CWinApp {
public:
    virtual BOOL InitInstance();
};


/// \brief Class Rotate Text Main Window
class CRotateTextMainWnd: public CFrameWnd {
public:
    CRotateTextMainWnd();

protected:
    afx_msg void OnPaint();

    DECLARE_MESSAGE_MAP()
};


/// @}
