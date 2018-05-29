/// \copyright The MIT License

#include "stdafx.h"
#include "ProgressDialog.h"

#include "rrwindows/dbgcon.h"
#include "rrwindows/dbgprt.h"

#// Private Message
#define PM_CLOSE (WM_USER + 1)

IMPLEMENT_DYNCREATE(ProgressDialog, CDialog)

BEGIN_MESSAGE_MAP(ProgressDialog, CDialog)
    ON_WM_TIMER()
    ON_MESSAGE(PM_CLOSE, &ProgressDialog::OnClose)
END_MESSAGE_MAP()

#// Constructors

ProgressDialog::
ProgressDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    DbgConPrtMeth(Green);
}

ProgressDialog::
~ProgressDialog()
{
    DbgConPrtMeth(Green);
}

#// Overridables

BOOL ProgressDialog::
OnInitDialog()
{
    CDialog::OnInitDialog();
    DbgConPrtMeth(Green);
    AfxBeginThread(ProgressDialog::ThreadWrapper, this);
    SetTimer(REFRESH_UI, 40, NULL);
    return TRUE;
}

BOOL ProgressDialog::
PreTranslateMessage(MSG *pMsg)
{
    DbgConPrtMeth(Green);
    switch (pMsg->message) {
    case WM_KEYDOWN: {
        switch (pMsg->wParam) {
        case VK_RETURN:  //fallthrough
        case VK_ESCAPE:
            return TRUE;
            break;
        default:
            break;
        }
    } break;
    default:
        break;
    }
    return CDialog::PreTranslateMessage(pMsg);
}

BOOL ProgressDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConPrtMethWndMsg(Green);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID ProgressDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DbgConPrtMeth(Green);
    DDX_Text(pDX, IDC_TOTAL_TEXT, TotalText);
    DDX_Control(pDX, IDC_TOTAL_PROGRESS, TotalProgressControl);
    DDX_Text(pDX, IDC_CURRENT_TEXT, CurrentText);
    DDX_Control(pDX, IDC_CURRENT_PROGRESS, CurrentProgressControl);
}

UINT ProgressDialog::
ThreadWrapper(LPVOID pParam)
{
    ProgressDialog *CONST self = reinterpret_cast<ProgressDialog *>(pParam);
    ASSERT(self->ThreadFunction);
    if (!self->ThreadFunction)
        return EXIT_FAILURE;
    CONST UINT rv = self->ThreadFunction(self);
    self->PostMessage(PM_CLOSE);
    return rv;
}

#// Message Handlers

VOID ProgressDialog::
OnTimer(UINT_PTR nIDEvent)
{
    switch (nIDEvent) {
    case REFRESH_UI:
        TotalText.Format(TEXT("%s (%i/%hd) ..."), static_cast<LPCTSTR>(TotalDescription), TotalProgressPosition, TotalProgressRangeMax);
        TotalProgressControl.SetRange(TotalProgressRangeMin, TotalProgressRangeMax);
        TotalProgressControl.SetPos(TotalProgressPosition);
        CurrentText.Format(TEXT("%s (%i/%hd)"), static_cast<LPCTSTR>(CurrentDescription), CurrentProgressPosition, CurrentProgressRangeMax);
        CurrentProgressControl.SetRange(CurrentProgressRangeMin, CurrentProgressRangeMax);
        CurrentProgressControl.SetPos(CurrentProgressPosition);
        SetWindowText(TotalText);
        UpdateData(FALSE);
        break;
    default:
        ASSERT(FALSE);
        DbgConPrt(White, TEXT("Unknown TimerId(%u) in MainDialog::OnTimer switch-case-default.\n"), nIDEvent);
        DbgPrtD(TEXT("Unknown TimerId(%u) in MainDialog::OnTimer switch-case-default.\n"), nIDEvent);
        break;
    }
}

LRESULT ProgressDialog::
OnClose(WPARAM wParam, LPARAM lParam)
{
    UNUSED_ALWAYS(wParam);
    UNUSED_ALWAYS(lParam);
    KillTimer(REFRESH_UI);
    EndDialog(IDCLOSE);
    return NULL;
}
