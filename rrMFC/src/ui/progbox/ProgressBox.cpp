/// \copyright The Unlicense

#include "stdafx.h"
#include "ProgressBox.h"
#include "ProgressBox.rc.h"

#include "rrwindows/rrwindows.h"

namespace rrMFC {

/// \brief 私有消息。
namespace PrivateMessages {

/// \brief 定制私有消息。
constexpr UINT Close {WM_USER + 1};

}//namespace PrivateMessages

const UINT ProgressBox::IDD {IDD_PROGRESS_DIALOG};

IMPLEMENT_DYNAMIC(ProgressBox, CDialog)

BEGIN_MESSAGE_MAP(ProgressBox, CDialog)
    ON_WM_TIMER()
    ON_MESSAGE(PrivateMessages::Close, &ProgressBox::OnClose)
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
    if (nullptr != self && self->IsKindOf(RUNTIME_CLASS(ProgressBox))) {
        CONST UINT rv = (nullptr != self->ThreadFunction) ? self->ThreadFunction(self) : EXIT_FAILURE;
        self->PostMessage(PrivateMessages::Close);
        return rv;
    } else {
        DpError(TEXT("The self isn't kind of ProgressDialog."));
        self->PostMessage(PrivateMessages::Close);
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
        DpErrorUSR(nIDEvent);
        break;
    }
}

LRESULT ProgressBox::
OnClose(WPARAM wParam, LPARAM lParam)
{
    UNUSED(wParam);
    UNUSED(lParam);
    KillTimer(REFRESH_UI);
    EndDialog(IDCLOSE);
    return NULL;
}

}//namespace rrMFC
