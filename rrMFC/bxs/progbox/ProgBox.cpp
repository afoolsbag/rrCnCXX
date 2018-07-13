/// \copyright The MIT License

#include "stdafx.h"
#include "ProgBox.h"

#include "rrwindows/dbgcon.h"
#include "rrwindows/dbgprt.h"

#// Private Message
#define PM_CLOSE (WM_USER + 1)

IMPLEMENT_DYNAMIC(ProgressBox, CDialog)

BEGIN_MESSAGE_MAP(ProgressBox, CDialog)
    ON_WM_TIMER()
    ON_MESSAGE(PM_CLOSE, &ProgressBox::OnClose)
END_MESSAGE_MAP()

#// Constructors

ProgressBox::
ProgressBox(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    DcMeth();
}

ProgressBox::
~ProgressBox()
{
    DcMeth();
}

#// Overridables

BOOL ProgressBox::
OnInitDialog()
{
    CDialog::OnInitDialog();
    DcMeth();
    AfxBeginThread(ProgressBox::ThreadWrapper, this);
    SetTimer(REFRESH_UI, 40, NULL);
    return TRUE;
}

BOOL ProgressBox::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DcWndMsg();
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID ProgressBox::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DcMeth();
    DDX_Text(pDX, IDC_TOTAL_TEXT, TotalText);
    DDX_Control(pDX, IDC_TOTAL_PROGRESS, TotalProgressControl);
    DDX_Text(pDX, IDC_CURRENT_TEXT, CurrentText);
    DDX_Control(pDX, IDC_CURRENT_PROGRESS, CurrentProgressControl);
}

UINT AFX_CDECL ProgressBox::
ThreadWrapper(LPVOID pParam)
{
    ProgressBox *CONST self = reinterpret_cast<ProgressBox *>(pParam);
    if (NULL != self && self->IsKindOf(RUNTIME_CLASS(ProgressBox))) {
        CONST UINT rv = (NULL != self->ThreadFunction) ? self->ThreadFunction(self) : EXIT_FAILURE;
        self->PostMessage(PM_CLOSE);
        return rv;
    } else {
        DpError(TEXT("The self isn't kind of ProgressDialog."));
        self->PostMessage(PM_CLOSE);
        return EXIT_FAILURE;
    }
}

#// Message Handlers

VOID ProgressBox::
OnTimer(UINT_PTR nIDEvent)
{
    switch (nIDEvent) {
    case REFRESH_UI:
        TotalText.Format(TEXT("%s (%i/%hd) ..."), static_cast<LPCTSTR>(TotDesc), TotProgPos, TotProgRngMax);
        TotalProgressControl.SetRange(TotProgRngMin, TotProgRngMax);
        TotalProgressControl.SetPos(TotProgPos);
        CurrentText.Format(TEXT("%s (%i/%hd)"), static_cast<LPCTSTR>(CurDesc), CurProgPos, CurProgRngMax);
        CurrentProgressControl.SetRange(CurProgRngMin, CurProgRngMax);
        CurrentProgressControl.SetPos(CurProgPos);
        UpdateData(FALSE);
        break;
    default:
        DpErrorSwitchUnknown(nIDEvent);
        break;
    }
}

LRESULT ProgressBox::
OnClose(WPARAM wParam, LPARAM lParam)
{
    UNUSED_ALWAYS(wParam);
    UNUSED_ALWAYS(lParam);
    KillTimer(REFRESH_UI);
    EndDialog(IDCLOSE);
    return NULL;
}