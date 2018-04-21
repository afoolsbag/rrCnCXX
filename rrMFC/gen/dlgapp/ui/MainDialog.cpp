/// \copyright The MIT License

#include "stdafx.h"
#include "resource.h"
#include "MainDialog.h"

#include "utils/dbgcon.h"

IMPLEMENT_DYNCREATE(MainDialog, CDialog)

BEGIN_MESSAGE_MAP(MainDialog, CDialog)
    ON_WM_NCCREATE()
    ON_WM_CREATE()
    ON_WM_DESTROY()
    ON_WM_NCDESTROY()

    ON_WM_CHANGEUISTATE()
    ON_WM_UPDATEUISTATE()
    ON_WM_DWMNCRENDERINGCHANGED()
    ON_WM_SHOWWINDOW()

    ON_WM_ACTIVATEAPP()
    ON_WM_NCACTIVATE()
    ON_WM_ACTIVATE()

    ON_WM_WINDOWPOSCHANGING()
    ON_WM_NCCALCSIZE()
    ON_WM_SIZE()
    ON_WM_MOVE()
    ON_WM_WINDOWPOSCHANGED()

    ON_WM_NCPAINT()
    ON_WM_ERASEBKGND()
    ON_WM_PAINT()

    ON_WM_CLOSE()

    ON_BN_CLICKED(IDOK, &MainDialog::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &MainDialog::OnBnClickedCancel)
    ON_BN_CLICKED(IDABORT, &MainDialog::OnBnClickedAbort)
    ON_BN_CLICKED(IDRETRY, &MainDialog::OnBnClickedRetry)
    ON_BN_CLICKED(IDIGNORE, &MainDialog::OnBnClickedIgnore)
    ON_BN_CLICKED(IDYES, &MainDialog::OnBnClickedYes)
    ON_BN_CLICKED(IDNO, &MainDialog::OnBnClickedNo)
    ON_BN_CLICKED(IDCLOSE, &MainDialog::OnBnClickedClose)
    ON_BN_CLICKED(IDHELP, &MainDialog::OnBnClickedHelp)

    ON_BN_CLICKED(IDC_HAND_BUTTON, &MainDialog::OnBnClickedHandButton)
    ON_BN_CLICKED(IDC_QUESTION_BUTTON, &MainDialog::OnBnClickedQuestionButton)
    ON_BN_CLICKED(IDC_EXCLAMATION_BUTTON, &MainDialog::OnBnClickedExclamationButton)
    ON_BN_CLICKED(IDC_ASTERISK_BUTTON, &MainDialog::OnBnClickedAsteriskButton)
END_MESSAGE_MAP()

#// Constructors

MainDialog::
MainDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    DbgConPrt(LightYellow, TEXT("MainDialog::Constructor\n"));
}

#// Overridables

MainDialog::
~MainDialog()
{
    DbgConPrt(LightYellow, TEXT("MainDialog::Destructor\n"));
}

BOOL MainDialog::
PreCreateWindow(CREATESTRUCT &cs)
{
    DbgConPrt(LightYellow, TEXT("MainDialog::PreCreateWindow\n"));
    return CDialog::PreCreateWindow(cs);
}

BOOL MainDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConPrtWndMsg(Yellow, TEXT("MainDialog::OnWndMsg"), message, wParam, lParam, pResult);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID MainDialog::
PreInitDialog()
{
    DbgConPrt(LightYellow, TEXT("MainDialog::PreInitDialog\n"));
    CDialog::PreInitDialog();
}

VOID MainDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DbgConPrt(LightYellow, TEXT("MainDialog::DoDataExchange\n"));
}

BOOL MainDialog::
OnInitDialog()
{
    CDialog::OnInitDialog();
    DbgConPrt(LightYellow, TEXT("MainDialog::OnInitDialog\n"));
    return TRUE;
}

VOID MainDialog::OnOK()
{
    DbgConPrt(LightYellow, TEXT("MainDialog::OnOK\n"));
    CDialog::OnOK();
}

VOID MainDialog::OnCancel()
{
    DbgConPrt(LightYellow, TEXT("MainDialog::OnCancel\n"));
    CDialog::OnCancel();
}

VOID MainDialog::
PostNcDestroy()
{
    DbgConPrt(LightYellow, TEXT("MainDialog::PostNcDestroy\n"));
    CDialog::PostNcDestroy();
}

#// Message Handlers

BOOL MainDialog::
OnNcCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (!CDialog::OnNcCreate(lpCreateStruct))
        return FALSE;
    DbgConPrt(LightYellow, TEXT("MainDialog::OnNcCreate\n"));
    return TRUE;
}

INT MainDialog::
OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CDialog::OnCreate(lpCreateStruct) == -1)
        return -1;
    DbgConPrt(LightYellow, TEXT("MainDialog::OnCreate\n"));
    return 0;
}

VOID MainDialog::
OnDestroy()
{
    CDialog::OnDestroy();
    DbgConPrt(LightYellow, TEXT("MainDialog::OnDestroy\n"));
}

VOID MainDialog::
OnNcDestroy()
{
    CDialog::OnNcDestroy();
    DbgConPrt(LightYellow, TEXT("MainDialog::OnNcDestroy\n"));
}

VOID MainDialog::
OnChangeUIState(UINT nAction, UINT nUIElement)
{
    CDialog::OnChangeUIState(nAction, nUIElement);
    DbgConPrt(LightYellow, TEXT("MainDialog::OnChangeUIState\n"));
}

VOID MainDialog::
OnUpdateUIState(UINT nAction, UINT nUIElement)
{
    CDialog::OnUpdateUIState(nAction, nUIElement);
    DbgConPrt(LightYellow, TEXT("MainDialog::OnUpdateUIState\n"));
}

VOID MainDialog::
OnNcRenderingChanged(BOOL bIsRendering)
{
    DbgConPrt(LightYellow, TEXT("MainDialog::OnNcRenderingChanged\n"));
    CDialog::OnNcRenderingChanged(bIsRendering);
}

VOID MainDialog::
OnShowWindow(BOOL bShow, UINT nStatus)
{
    CDialog::OnShowWindow(bShow, nStatus);
    DbgConPrt(LightYellow, TEXT("MainDialog::OnShowWindow\n"));
}

VOID MainDialog::
OnActivateApp(BOOL bActive, DWORD dwThreadID)
{
    CDialog::OnActivateApp(bActive, dwThreadID);
    DbgConPrt(LightYellow, TEXT("MainDialog::OnActivateApp\n"));
}

BOOL MainDialog::
OnNcActivate(BOOL bActive)
{
    DbgConPrt(LightYellow, TEXT("MainDialog::OnNcActivate\n"));
    return CDialog::OnNcActivate(bActive);
}

VOID MainDialog::
OnActivate(UINT nState, CWnd *pWndOther, BOOL bMinimized)
{
    CDialog::OnActivate(nState, pWndOther, bMinimized);
    DbgConPrt(LightYellow, TEXT("MainDialog::OnActivate\n"));
}

VOID MainDialog::
OnWindowPosChanging(WINDOWPOS *lpwndpos)
{
    CDialog::OnWindowPosChanging(lpwndpos);
    DbgConPrt(LightYellow, TEXT("MainDialog::OnWindowPosChanging\n"));
}

VOID MainDialog::
OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS *lpncsp)
{
    DbgConPrt(LightYellow, TEXT("MainDialog::OnNcCalcSize\n"));
    CDialog::OnNcCalcSize(bCalcValidRects, lpncsp);
}

VOID MainDialog::
OnSize(UINT nType, INT cx, INT cy)
{
    CDialog::OnSize(nType, cx, cy);
    DbgConPrt(LightYellow, TEXT("MainDialog::OnSize\n"));
}

VOID MainDialog::
OnMove(INT x, INT y)
{
    CDialog::OnMove(x, y);
    DbgConPrt(LightYellow, TEXT("MainDialog::OnMove\n"));
}

VOID MainDialog::
OnWindowPosChanged(WINDOWPOS *lpwndpos)
{
    CDialog::OnWindowPosChanged(lpwndpos);
    DbgConPrt(LightYellow, TEXT("MainDialog::OnWindowPosChanged\n"));
}

VOID MainDialog::
OnNcPaint()
{
    CDialog::OnNcPaint();
    DbgConPrt(LightYellow, TEXT("MainDialog::OnNcPaint\n"));
}

BOOL MainDialog::
OnEraseBkgnd(CDC *pDC)
{
    DbgConPrt(LightYellow, TEXT("MainDialog::OnEraseBkgnd\n"));
    return CDialog::OnEraseBkgnd(pDC);
}

VOID MainDialog::
OnPaint()
{
    CDialog::OnPaint();
    DbgConPrt(LightYellow, TEXT("MainDialog::OnPaint\n"));
}

VOID MainDialog::
OnClose()
{
    DbgConPrt(LightYellow, TEXT("MainDialog::OnClose\n"));
    CDialog::OnClose();
}

VOID MainDialog::
OnBnClickedOk()
{
    DbgConPrt(LightYellow, TEXT("MainDialog::OnBnClickedOk\n"));
    CDialog::OnOK();
}

VOID MainDialog::
OnBnClickedCancel()
{
    DbgConPrt(LightYellow, TEXT("MainDialog::OnBnClickedCancel\n"));
    CDialog::OnCancel();
}

VOID MainDialog::
OnBnClickedAbort()
{
    DbgConPrt(LightYellow, TEXT("MainDialog::OnBnClickedAbort\n"));
    EndDialog(IDABORT);
}

VOID MainDialog::
OnBnClickedRetry()
{
    DbgConPrt(LightYellow, TEXT("MainDialog::OnBnClickedRetry\n"));
    EndDialog(IDRETRY);
}

VOID MainDialog::
OnBnClickedIgnore()
{
    DbgConPrt(LightYellow, TEXT("MainDialog::OnBnClickedIgnore\n"));
    EndDialog(IDIGNORE);
}

VOID MainDialog::
OnBnClickedYes()
{
    DbgConPrt(LightYellow, TEXT("MainDialog::OnBnClickedYes\n"));
    EndDialog(IDYES);
}

VOID MainDialog::
OnBnClickedNo()
{
    DbgConPrt(LightYellow, TEXT("MainDialog::OnBnClickedNo\n"));
    EndDialog(IDNO);
}

VOID MainDialog::
OnBnClickedClose()
{
    DbgConPrt(LightYellow, TEXT("MainDialog::OnBnClickedClose\n"));
    EndDialog(IDCLOSE);
}

VOID MainDialog::
OnBnClickedHelp()
{
    DbgConPrt(LightYellow, TEXT("MainDialog::OnBnClickedHelp\n"));
    EndDialog(IDHELP);
}

VOID MainDialog::
OnBnClickedHandButton()
{
    DbgConPrt(LightYellow, TEXT("MainDialog::OnBnClickedHandButton\n"));
    AfxMessageBox(TEXT("Hand"), MB_ICONHAND);
}

VOID MainDialog::
OnBnClickedQuestionButton()
{
    DbgConPrt(LightYellow, TEXT("MainDialog::OnBnClickedQuestionButton\n"));
    AfxMessageBox(TEXT("Question"), MB_ICONQUESTION);
}

VOID MainDialog::
OnBnClickedExclamationButton()
{
    DbgConPrt(LightYellow, TEXT("MainDialog::OnBnClickedExclamationButton\n"));
    AfxMessageBox(TEXT("Exclamation"), MB_ICONEXCLAMATION);
}

VOID MainDialog::
OnBnClickedAsteriskButton()
{
    DbgConPrt(LightYellow, TEXT("MainDialog::OnBnClickedAsteriskButton\n"));
    AfxMessageBox(TEXT("Asterisk"), MB_ICONASTERISK);
}
