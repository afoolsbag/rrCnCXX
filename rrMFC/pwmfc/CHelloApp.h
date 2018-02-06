//===-- Class Hello Application ---------------------------------*- C++ -*-===//
///
/// \defgroup g_pwmfc_hello 你好（§1.3）
/// \ingroup g_pwmfc
///
/// \sa \ref s_afx_and_mfc
/// \sa *Programming Windows with MFC* §1.3
///
/// \author zhengrr
/// \date 2017-12-8 – 2018-2-5
/// \copyright The MIT License
///
/// @{
//===----------------------------------------------------------------------===//

#define VC_EXTRALEAN
#include <afxwin.h>


/// \brief Class Hello Application
///
/// \sa ["CWinApp Class"](https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class). *Microsoft® Docs*.
class CHelloApp: public CWinApp {
public:

    /// \brief Initialize Instance
    ///
    /// \sa ["CWinApp::InitInstance"](https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#initinstance). *Microsoft® Docs*.
    virtual BOOL InitInstance();

    /// \brief Exit Instance
    ///
    /// \sa ["CWinApp::ExitInstance"](https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#exitinstance). *Microsoft® Docs*.
    virtual int ExitInstance();
};


/// \brief Class Hello Main Window
///
/// \sa \ref s_where_is_delete_cframewnd
/// \sa ["CFrameWnd Class"](https://docs.microsoft.com/cpp/mfc/reference/cframewnd-class). *Microsoft® Docs*.
class CHelloMainWnd: public CFrameWnd {
public:
    CHelloMainWnd();

protected:

    /// \brief On Paint
    ///
    /// \sa ["CWnd::OnPaint"](https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onpaint). *Microsoft® Docs*.
    afx_msg void OnPaint();

    DECLARE_MESSAGE_MAP()
};


/// @}
