/// \copyright The Unlicense

#include "stdafx.h"
#include "ProgressBox.h"
#include "ProgressBox.rc.h"

#include "rrwindows/rrwindows.h"

namespace {

/// \brief 私有消息。
namespace PrivateMessages {

/// \brief 关闭。
constexpr unsigned Close {WM_USER + 1};

}//namespace PrivateMessages

}//namespace

namespace rrMFC {

const unsigned ProgressBox::IDD {IDD_PROGRESS_DIALOG};

IMPLEMENT_DYNAMIC(ProgressBox, CDialog)

BEGIN_MESSAGE_MAP(ProgressBox, CDialog)
    ON_WM_TIMER()
    ON_MESSAGE(PrivateMessages::Close, &ProgressBox::OnClose)
END_MESSAGE_MAP()

#// Constructors

ProgressBox::
ProgressBox(CWnd *pParent /*=nullptr*/)
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
    SetTimer(Refresh, 1000 / 25, nullptr);
    return TRUE;
}

BOOL ProgressBox::
OnWndMsg(unsigned message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DcWndMsg();
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

void ProgressBox::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DcMeth();
    DDX_Text(pDX, IDC_TOTAL_TEXT, TotalText);
    DDX_Control(pDX, IDC_TOTAL_PROGRESS, TotalProgressControl);
    DDX_Text(pDX, IDC_CURRENT_TEXT, CurrentText);
    DDX_Control(pDX, IDC_CURRENT_PROGRESS, CurrentProgressControl);
}

unsigned AFX_CDECL ProgressBox::
ThreadWrapper(LPVOID pParam)
{
    ProgressBox *const self = reinterpret_cast<ProgressBox *>(pParam);
    if (self == nullptr)
        return EXIT_FAILURE;
    if (!self->IsKindOf(RUNTIME_CLASS(ProgressBox)))
        return EXIT_FAILURE;
    if (self->ThreadFunction == nullptr) {
        self->PostMessage(PrivateMessages::Close);
        return EXIT_FAILURE;
    }
    const unsigned rv = self->ThreadFunction(*self);
    self->PostMessage(PrivateMessages::Close);
    return rv;
}

#// Message Handlers

void ProgressBox::
OnTimer(UINT_PTR nIDEvent)
{
    switch (nIDEvent) {
    case Refresh:
        TotalText.Format(TEXT("%s (%i/%hd) ..."), static_cast<LPCTSTR>(TDesc), TPos - TMin, TMax - TMin);
        TotalProgressControl.SetRange(TMin, TMax);
        TotalProgressControl.SetPos(TPos);
        CurrentText.Format(TEXT("%s (%i/%hd)"), static_cast<LPCTSTR>(CDesc), CPos - CMin, CMax - CMin);
        CurrentProgressControl.SetRange(CMin, CMax);
        CurrentProgressControl.SetPos(CPos);
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
    UNUSED_ALWAYS(wParam);
    UNUSED_ALWAYS(lParam);

    KillTimer(Refresh);
    EndDialog(IDCLOSE);
    return NULL;
}

}//namespace rrMFC
