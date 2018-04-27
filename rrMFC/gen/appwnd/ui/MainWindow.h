//===-- Main Window ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief �����ڣ��ࣩ��
///
/// \verison 2018-04-27
/// \since 2018-04-27
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief �����ڣ��ࣩ��
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class
class MainWindow: public CWnd {
    DECLARE_DYNCREATE(MainWindow)

#// Constructors
public:
    MainWindow();

    /// \brief ��������ʼ���� `CWnd` ����������Ӵ��ڡ�
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#create
    virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, CONST RECT &rect, CWnd *pParentWnd, UINT nID, CCreateContext *pContext = NULL) override;

    /// \brief ���� Windows �ص����������Ӵ��ڣ����������ӵ� `CWnd` ����
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#createex
    virtual BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, INT x, INT y, INT nWidth, INT nHeight, HWND hWndParent, HMENU nIDorHMenu, LPVOID lpParam = NULL) override;

    /// \brief ���� Windows �ص����������Ӵ��ڣ����������ӵ� `CWnd` ����
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#createex
    virtual BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, CONST RECT &rect, CWnd *pParentWnd, UINT nID, LPVOID lpParam = NULL) override;

    virtual ~MainWindow();

#// Attributes
public:

#// Operations
public:

#// Overridables
public:
    /// \brief �ڴ������ӵ��� `CWnd` ����� Windows ����֮ǰ���á�
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#precreatewindow
    virtual BOOL PreCreateWindow(CREATESTRUCT &cs) override;

    /// \brief ·�ɺ͵���������Ϣ��
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/ccmdtarget-class#oncmdmsg
    virtual BOOL OnCmdMsg(UINT nID, INT nCode, VOID *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo) override;

protected:
    /// \brief ָʾ�Ƿ����� Windows ��Ϣ��
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onwndmsg
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult) override;

#// Implementation
protected:

#// Message Handlers
protected:

    // CREATE & DESTROY

    /// \brief ֮ǰ����OnCreate�ķǹ������ڴ���ʱ��
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onnccreate
    afx_msg BOOL OnNcCreate(LPCREATESTRUCT lpCreateStruct);

    /// \brief �ڴ��ڴ��������е��á�
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#oncreate
    afx_msg INT OnCreate(LPCREATESTRUCT lpCreateStruct);

    /// \brief ������ `CWnd` ʱ���á�
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#ondestroy
    afx_msg VOID OnDestroy();

    /// \brief �����ٷǹ�����ʱ���á�
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onncdestroy
    afx_msg VOID OnNcDestroy();

    // MOVE & SIZE

    /// \brief ÿ�� Windows ��Ҫ֪�����λ�û�ߴ������С�������ٴ�Сʱ���á�
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#ongetminmaxinfo
    afx_msg VOID OnGetMinMaxInfo(MINMAXINFO *lpMMI);

    /// \brief ����Ӱ��Ĵ��ڽ����ƶ����С����ģʽѭ��֮����á�
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onentersizemove
    afx_msg VOID OnEnterSizeMove();

    /// \brief ָʾ�û������ƶ� `CWnd` ����
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onmoving
    afx_msg VOID OnMoving(UINT fwSide, LPRECT pRect);

    /// \brief ָʾ�û����ڵ������δ�С��
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onsizing
    afx_msg VOID OnSizing(UINT fwSide, LPRECT pRect);

    /// \brief ����С��λ�û� Z ˳�򼴽�������ö�����ʱ����`SetWindowPos`����һ�����ڹ�������
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onwindowposchanging
    afx_msg VOID OnWindowPosChanging(WINDOWPOS *lpwndpos);

    /// \brief ����Ӱ��Ĵ����˳��ƶ����С����ģʽѭ��֮����á�
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onexitsizemove
    afx_msg VOID OnExitSizeMove();

    /// \brief �� `CWnd` ��λ���Ѹ���֮����á�
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onmove
    afx_msg VOID OnMove(INT x, INT y);

    /// \brief ����Ҫ���㹤�����Ĵ�С��λ��ʱ���á�
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onnccalcsize
    afx_msg VOID OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS *lpncsp);

    /// \brief �� `CWnd` �Ĵ�С�Ѹ���֮����á�
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onsize
    afx_msg VOID OnSize(UINT nType, INT cx, INT cy);

    /// \brief ����С��λ�û� Z ˳��������ö�����ʱ����`SetWindowPos`����һ�����ڹ�������
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onwindowposchanged
    afx_msg VOID OnWindowPosChanged(WINDOWPOS *lpwndpos);
    
    // STATE & STATUS

    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnActivateApp(BOOL bActive, DWORD dwThreadID);
    afx_msg BOOL OnNcActivate(BOOL bActive);
    afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
};
