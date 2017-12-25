/** \file
 *  \brief *Programming Windows with MFC* 1.3 Hello.
 *  \author zhengrr
 *  \date 2017-12-8 – 15
 *  \copyright The MIT License */

/* 议题：为什么是 AFX：
 *
 * 　　一言蔽之，历史遗留问题。"Microsoft Foundation Class Library" 提出太晚，而
 * 之前她的名字是 "Application Framework eXtensions"。
 *
 * 参见：<https://wikipedia.org/wiki/Application_Framework_eXtensions>。 */

#include <afxwin.h>

/// Class My Application.
/** \sa <https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class>. */
class CMyApp : public CWinApp {
public:
    virtual BOOL InitInstance();
    virtual int ExitInstance();
};


/// Class Main Window.
/** \sa <https://docs.microsoft.com/cpp/mfc/reference/cframewnd-class>. */
class CMainWindow : public CFrameWnd {
public:
    CMainWindow();

protected:
    afx_msg void OnPaint();

    DECLARE_MESSAGE_MAP()
};
