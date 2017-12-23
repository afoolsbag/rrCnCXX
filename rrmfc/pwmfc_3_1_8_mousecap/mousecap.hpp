/** \file
 *  \brief *Programming Windows with MFC* 3.1.8 MouseCap.
 *  \author zhengrr
 *  \date 2017-12-9 – 15
 *  \copyright The MIT License */

#include <afxwin.h>

/// Class MY APPlication.
class CMyApp : public CWinApp {
public:
    virtual BOOL InitInstance();
};

/// Class MAIN WINDOW.
class CMainWindow : public CFrameWnd {
public:
    CMainWindow();

protected:
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);

    BOOL m_bTracking;
    BOOL m_bCaptureEnabled;
    CPoint m_ptFrom;
    CPoint m_ptTo;

    void InvertLine(CDC *pDC, CPoint ptFrom, CPoint ptTo);

    DECLARE_MESSAGE_MAP()
};
