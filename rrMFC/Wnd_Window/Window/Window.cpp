/// \copyright The Unlicense

#include "stdafx.h"
#include "Window.h"

#include "Application.h"
#include "RegisteredMessages.h"

namespace rrMFC {

namespace PrivateMessages {
/// \brief 定制私有消息。
constexpr unsigned Custom {WM_USER + 1};
}//namespace PrivateMessages

BEGIN_MESSAGE_MAP(Window, CWnd)
    ON_WM_NCCREATE()
    ON_WM_CREATE()
    ON_WM_DESTROY()
    ON_WM_NCDESTROY()

    ON_WM_GETMINMAXINFO()
    ON_WM_ENTERSIZEMOVE()
    ON_WM_MOVING()
    ON_WM_SIZING()
    ON_WM_WINDOWPOSCHANGING()
    ON_WM_EXITSIZEMOVE()

    ON_WM_MOVE()
    ON_WM_NCCALCSIZE()
    ON_WM_SIZE()
    ON_WM_WINDOWPOSCHANGED()

    ON_WM_ACTIVATEAPP()
    ON_WM_NCACTIVATE()
    ON_WM_ACTIVATE()

    ON_WM_NCPAINT()
    ON_WM_ERASEBKGND()
    ON_WM_PAINT()

    ON_WM_TIMER()

    ON_MESSAGE(PrivateMessages::Custom, &Window::OnCustomPrivateMessage)
    ON_MESSAGE(ApplicationMessages::Custom, &Window::OnCustomApplicationMessage)
    ON_REGISTERED_MESSAGE(RegisteredMessages::Custom, &Window::OnCustomRegisteredMessage)
END_MESSAGE_MAP()

#// Constructors

Window::
Window()
{
    TRACE(__FUNCTION__ "\n");

    CONST CString windowClassName = AfxRegisterWndClass(
        CS_DBLCLKS,
        AfxGetApp()->LoadStandardCursor(IDC_ARROW),
        reinterpret_cast<HBRUSH>(COLOR_3DFACE + 1),
        AfxGetApp()->LoadStandardIcon(IDI_WINLOGO)
    );

    CreateEx(0, windowClassName, _T("微软基础类库窗口应用"),
             WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX | WS_THICKFRAME,
             CW_USEDEFAULT, CW_USEDEFAULT, 400, 300,
             NULL, NULL);
}

BOOL Window::
Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT &rect, CWnd *pParentWnd, unsigned nID, CCreateContext *pContext /*=NULL*/)
{
    TRACE(__FUNCTION__ "\n");
    return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

BOOL Window::
CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU nIDorHMenu, LPVOID lpParam /*=NULL*/)
{
    TRACE(__FUNCTION__ "\n");
    return CWnd::CreateEx(dwExStyle, lpszClassName, lpszWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, nIDorHMenu, lpParam);
}

BOOL Window::
CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT &rect, CWnd *pParentWnd, unsigned nID, LPVOID lpParam /*=NULL*/)
{
    TRACE(__FUNCTION__ "\n");
    return CWnd::CreateEx(dwExStyle, lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, lpParam);
}

#// Overridables

BOOL Window::
PreCreateWindow(CREATESTRUCT &cs)
{
    TRACE(__FUNCTION__ "\n");
    return CWnd::PreCreateWindow(cs);
}

BOOL Window::
OnCmdMsg(unsigned nID, int nCode, void *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo)
{
    TRACE(__FUNCTION__ "\n");
    return CWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

BOOL Window::
OnWndMsg(unsigned message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
    TRACE(__FUNCTION__ "\n");
    return CWnd::OnWndMsg(message, wParam, lParam, pResult);
}

void Window::
DoDataExchange(CDataExchange *pDX)
{
    CWnd::DoDataExchange(pDX);
    TRACE(__FUNCTION__ "\n");
}

void Window::
PostNcDestroy()
{
    TRACE(__FUNCTION__ "\n");
    CWnd::PostNcDestroy();
}

#// Message Handlers

BOOL Window::
OnNcCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (!CWnd::OnNcCreate(lpCreateStruct))
        return FALSE;
    TRACE(__FUNCTION__ "\n");
    return TRUE;
}

int Window::
OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CWnd::OnCreate(lpCreateStruct) == -1)
        return -1;
    TRACE(__FUNCTION__ "\n");
    return 0;
}

void Window::
OnDestroy()
{
    CWnd::OnDestroy();
    TRACE(__FUNCTION__ "\n");
}

void Window::
OnNcDestroy()
{
    CWnd::OnNcDestroy();
    TRACE(__FUNCTION__ "\n");
}

void Window::
OnGetMinMaxInfo(MINMAXINFO *lpMMI)
{
    TRACE(__FUNCTION__ "\n");
    CWnd::OnGetMinMaxInfo(lpMMI);
}

void Window::
OnEnterSizeMove()
{
    TRACE(__FUNCTION__ "\n");
    CWnd::OnEnterSizeMove();
}

void Window::
OnMoving(unsigned fwSide, LPRECT pRect)
{
    CWnd::OnMoving(fwSide, pRect);
    TRACE(__FUNCTION__ "\n");
}

void Window::
OnSizing(unsigned fwSide, LPRECT pRect)
{
    CWnd::OnSizing(fwSide, pRect);
    TRACE(__FUNCTION__ "\n");
}

void Window::
OnWindowPosChanging(WINDOWPOS *lpwndpos)
{
    CWnd::OnWindowPosChanging(lpwndpos);
    TRACE(__FUNCTION__ "\n");
}

void Window::
OnExitSizeMove()
{
    TRACE(__FUNCTION__ "\n");
    CWnd::OnExitSizeMove();
}

void Window::
OnMove(int x, int y)
{
    CWnd::OnMove(x, y);
    TRACE(__FUNCTION__ "\n");
}

void Window::
OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS *lpncsp)
{
    TRACE(__FUNCTION__ "\n");
    CWnd::OnNcCalcSize(bCalcValidRects, lpncsp);
}

void Window::
OnSize(unsigned nType, int cx, int cy)
{
    CWnd::OnSize(nType, cx, cy);
    TRACE(__FUNCTION__ "\n");
}

void Window::
OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
    CWnd::OnWindowPosChanged(lpwndpos);
    TRACE(__FUNCTION__ "\n");
}

void Window::
OnActivateApp(BOOL bActive, DWORD dwThreadID)
{
    CWnd::OnActivateApp(bActive, dwThreadID);
    TRACE(__FUNCTION__ "\n");
}

BOOL Window::
OnNcActivate(BOOL bActive)
{
    TRACE(__FUNCTION__ "\n");
    return CWnd::OnNcActivate(bActive);
}

void Window::
OnActivate(unsigned nState, CWnd* pWndOther, BOOL bMinimized)
{
    CWnd::OnActivate(nState, pWndOther, bMinimized);
    TRACE(__FUNCTION__ "\n");
}

void Window::
OnNcPaint()
{
    CWnd::OnNcPaint();
    TRACE(__FUNCTION__ "\n");
}

BOOL Window::
OnEraseBkgnd(CDC *pDC)
{
    TRACE(__FUNCTION__ "\n");
    return CWnd::OnEraseBkgnd(pDC);
}

void Window::
OnPaint()
{
    CWnd::OnPaint();
    TRACE(__FUNCTION__ "\n");
}

void Window::
OnTimer(UINT_PTR nIDEvent)
{
    TRACE(__FUNCTION__ "\n");
    switch (nIDEvent) {
    case Timer1: break;
    case Timer2: break;
    case Timer3: break;
    default: break;
    }
    CWnd::OnTimer(nIDEvent);
}

LRESULT Window::
OnCustomPrivateMessage(WPARAM wParam, LPARAM lParam)
{
    TRACE(__FUNCTION__ "\n");
    UNUSED(wParam);
    UNUSED(lParam);
    return 0;
}

LRESULT Window::
OnCustomApplicationMessage(WPARAM wParam, LPARAM lParam)
{
    TRACE(__FUNCTION__ "\n");
    UNUSED(wParam);
    UNUSED(lParam);
    return 0;
}

LRESULT Window::
OnCustomRegisteredMessage(WPARAM wParam, LPARAM lParam)
{
    TRACE(__FUNCTION__ "\n");
    UNUSED(wParam);
    UNUSED(lParam);
    return 0;
}

}//namespace rrMFC
