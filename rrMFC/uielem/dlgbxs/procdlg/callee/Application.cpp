/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

#include "utils/dbgcon.h"

#include "resource.h"
#include "ui/HostDialog.h"
#include "ui/GuestDialog.h"

IMPLEMENT_DYNCREATE(Application, CWinApp)

#// Constructors

Application::
Application()
{
    NewDbgCon(LightRed, TEXT("Application::Constructor\n"));
}

#// Overridables

Application::
~Application()
{
    DelDbgCon(LightRed, TEXT("Application::Destructor\n"));
}

BOOL Application::
InitInstance()
{
    CWinApp::InitInstance();
    DbgConPrt(LightRed, TEXT("Application::InitInstance\n"));

    HWND hostHwnd = NULL;

    DbgConPrt(White, TEXT("Command Line: \"%s\"\n"), m_lpCmdLine);
    CONST CString args = m_lpCmdLine;
    INT pos = 0;
    CString token = TEXT("");
    while (TRUE) {
        token = args.Tokenize(TEXT("\t\n\r "), pos);
        if (token.IsEmpty())
            break;

        if (!token.CompareNoCase(TEXT("/host"))) {
            token = args.Tokenize(TEXT("\t\n\r "), pos);
            if (token.IsEmpty()) {
                DbgConPrt(White, TEXT("Missing value for /host in command line arguments\n"));
                return FALSE;
            }
            errno = 0;
            hostHwnd = reinterpret_cast<HWND>(_tcstol(token, NULL, 16));
            if (!hostHwnd || errno) {
                errno = 0;
                DbgConPrt(White, TEXT("Invalid value for /host in command line arguments: %s\n"), token);
                return FALSE;
            }
        }
    }

    HostDialog *hostDlg = NULL;
    if (!hostHwnd) {
        hostDlg = DEBUG_NEW HostDialog;
        HostDlgDecay = hostDlg;
        m_pMainWnd = m_pMainWnd ? m_pMainWnd : hostDlg;
        hostDlg->Create(HostDialog::IDD);

        hostHwnd = hostDlg->GetSafeHwnd();
    }

    GuestDialog *guestDlg = DEBUG_NEW GuestDialog;
    guestDlg->SetHostHwnd(hostHwnd);
    GuestDlgDecay = guestDlg;
    m_pMainWnd = m_pMainWnd ? m_pMainWnd : guestDlg;
    guestDlg->Create(GuestDialog::IDD, CWnd::FromHandle(hostHwnd));
    guestDlg->ShowWindow(m_nCmdShow);
    guestDlg->UpdateWindow();

    if (hostDlg) {
        hostDlg->ShowWindow(m_nCmdShow);
        hostDlg->UpdateWindow();
    }

    return TRUE;
}

INT Application::
ExitInstance()
{
    DbgConPrt(LightRed, TEXT("Application::ExitInstance\n"));

    HostDialog *hostDlg = dynamic_cast<HostDialog *>(HostDlgDecay);
    if (hostDlg) {
        hostDlg->DestroyWindow();
        delete hostDlg;
        HostDlgDecay = hostDlg = NULL;
    }

    GuestDialog *guestDlg = dynamic_cast<GuestDialog *>(GuestDlgDecay);
    if (guestDlg) {
        guestDlg->DestroyWindow();
        delete guestDlg;
        GuestDlgDecay = guestDlg = NULL;
    }

    return CWinApp::ExitInstance();
}
