/** \file
 *  \brief *Programming Windows with MFC* 2.3.6 Accel.
 *  \author zhengrr
 *  \date 2017-12-8 – 15
 *  \copyright The MIT License
 */

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
    afx_msg void OnPaint();
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg void OnHScroll(UINT nCode, UINT nPos, CScrollBar *pScrollBar);
    afx_msg void OnVScroll(UINT nCode, UINT nPos, CScrollBar *pScrollBar);

    int m_nCellWidth;    ///< 单元格宽度；
    int m_nCellHeight;   ///< 单元格高度；
    int m_nRibbonWidth;  ///< 行头宽度；
    int m_nViewWidth;    ///< 工作区宽度；
    int m_nViewHeight;   ///< 工作区高度；
    int m_nHScrollPos;   ///< 水平滚动条位置；
    int m_nVScrollPos;   ///< 垂直滚动条位置；
    int m_nHPageSize;    ///< 页面宽度；
    int m_nVPageSize;    ///< 页面高度。

    DECLARE_MESSAGE_MAP()
};
