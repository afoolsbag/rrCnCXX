//===-- Class Text Application ----------------------------------*- C++ -*-===//
///
/// \defgroup g_pwmfc_text 文本（§2.2.6）
/// \ingroup g_pwmfc
///
/// \sa *Programming Windows with MFC* §2.2.6
///
/// \author zhengrr
/// \date 2017-12-8 – 2018-2-5
/// \copyright The MIT License
///
/// @{
//===----------------------------------------------------------------------===//

#define VC_EXTRALEAN
#include <afxwin.h>


/// \brief Class Text Application
class CTextApp: public CWinApp {
public:
    virtual BOOL InitInstance();
};


/// \brief Class Text Main Window
class CTextMainWnd: public CFrameWnd {
public:
    CTextMainWnd();

protected:
    afx_msg void OnPaint();

    DECLARE_MESSAGE_MAP()
};


/// @}
