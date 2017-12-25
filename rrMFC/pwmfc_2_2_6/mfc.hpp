/** \file
 *  \brief *Programming Windows with MFC* 2.2.6.
 *  \author zhengrr
 *  \date 2017-12-8 – 15
 *  \copyright The MIT License
 */

#include <afxwin.h>

/// Class My Application.
class CMyApp : public CWinApp {
public:
    virtual BOOL InitInstance();
};


/// Class Main Window.
class CMainWindow : public CFrameWnd {
public:
    CMainWindow();

protected:
    afx_msg void OnPaint();

DECLARE_MESSAGE_MAP()
};
