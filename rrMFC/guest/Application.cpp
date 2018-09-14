/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

#include "rrwindows/dbgcon.h"

#include "ui/GuestDialog.h"

IMPLEMENT_DYNCREATE(Application, CWinApp)

#// Constructors

Application::
Application()
{
    NewDbgCon();
    DbgConPrtMeth(Red);
}

Application::
~Application()
{
    DbgConPrtMeth(Red);
    DelDbgCon();
}

#// Overridables

BOOL Application::
InitInstance()
{
    CWinApp::InitInstance();
    DbgConPrtMeth(Red);

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
                DbgConPrt(White, TEXT("Invalid value for /host in command line arguments: %s\n"), static_cast<LPCTSTR>(token));
                return FALSE;
            }
        }
    }

    if (!hostHwnd) {
        DbgConPrt(White, TEXT("Missing command line arguments: /host <HostHwnd>\n"));
        return FALSE;
    }

    GuestDialog *CONST dlg = DEBUG_NEW GuestDialog;
    dlg->SetHostHwnd(hostHwnd);
    m_pMainWnd = dlg;
    dlg->Create(GuestDialog::IDD, CWnd::FromHandle(hostHwnd));
    dlg->ShowWindow(m_nCmdShow);
    dlg->UpdateWindow();

    return TRUE;
}
