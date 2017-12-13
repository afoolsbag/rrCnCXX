/** \file
 *  \brief *Programming Windows with MFC* 2.2.1.
 *  \author zhengrr
 *  \date 2017-12-8 – 13
 *  \copyright The MIT License
 */
#include <math.h>
#include <afxwin.h>

#define SEGMENTS 500
#define PI 3.1415926

namespace {

/// CMyApp
class CMyApp : public CWinApp {
public:
    virtual BOOL InitInstance();
};

/// CMainWindow
class CMainWindow : public CFrameWnd {
public:
    CMainWindow();
protected:
    afx_msg void OnPaint();
    DECLARE_MESSAGE_MAP()
};

#ifdef RRMFC_PWMFC_2_2_1_CPP_
CMyApp myApp;
#endif

/// CMyApp::InitInstance
BOOL CMyApp::InitInstance()
{
    m_pMainWnd = new CMainWindow;
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();
    return TRUE;
}

BEGIN_MESSAGE_MAP(CMainWindow, CFrameWnd)
    ON_WM_PAINT()
END_MESSAGE_MAP()

/// CMainWindow::CMainWindow
CMainWindow::CMainWindow()
{
    Create(NULL, _T("The Hello Application"));
}

/// CMainWindow::OnPaint
void CMainWindow::OnPaint()
{
    CRect rect;
    GetClientRect(&rect);
    int nWidth = rect.Width();  // [WIDTH](https://docs.microsoft.com/cpp/atl-mfc-shared/reference/crect-class#width)
    int nHeight = rect.Height();  // [HEIGHT](https://docs.microsoft.com/cpp/atl-mfc-shared/reference/crect-class#height)

    CPoint aPoint[SEGMENTS];  // [Class POINT](https://docs.microsoft.com/cpp/atl-mfc-shared/reference/cpoint-class)
    for(int i = 0; i < SEGMENTS; ++i) {
        aPoint[i].x = (i * nWidth) / SEGMENTS;
        aPoint[i].y = (nHeight / 2) * ( 1 - (sin(2*PI*i/SEGMENTS)) );
    }

    CPaintDC dc(this);
    dc.Polyline(aPoint, SEGMENTS);  // [POLYLINE](https://docs.microsoft.com/cpp/mfc/reference/cdc-class#polyline)
}

}// namespace
