/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

#include "utils/dbgcon.h"

IMPLEMENT_DYNCREATE(Application, CWinApp)

#// Constructors

Application::
Application()
{
    NewDbgCon(LightRed, TEXT("Application::Constructor\n"));
    MessageHwnd = NULL;
}

#// Overridables

Application::
~Application()
{
    DelDbgCon(LightRed, TEXT("Application::Destructor\n"));
}

BOOL Application::
InitApplication()
{
    DbgConPrt(LightRed, TEXT("Application::InitApplication\n"));
    return CWinApp::InitApplication();
}

BOOL Application::
InitInstance()
{
    CWinApp::InitInstance();
    DbgConPrt(LightRed, TEXT("Application::InitInstance\n"));

    CString arg = m_lpCmdLine;
    CString token;
    INT pos = 0;

    while (TRUE) {
        token = arg.Tokenize(TEXT("\t\n\r "), pos);
        if (token.IsEmpty())
            break;

        if (token == TEXT("/?") || token == TEXT("-?") ||
            token.CompareNoCase(TEXT("/h")) || token.CompareNoCase(TEXT("-h")) ||
            !token.CompareNoCase(TEXT("/help")) || !token.CompareNoCase(TEXT("-help"))) {
            CString text =
                TEXT("Usage:\n")
                TEXT("    theapp.exe /mhwnd <MessageHwnd>\n")
                TEXT("\n")
                TEXT("Parameters:\n")
                TEXT("    /? /h /help \t this message.\n")
                TEXT("    /mhwnd      \t message hwnd, for inter-process communication.\n")
                TEXT("\n");
            AfxMessageBox(text);
            return FALSE;
        }

        if (token.CompareNoCase(TEXT("/mhwnd")) || token.CompareNoCase(TEXT("-mhwnd"))) {
            token = arg.Tokenize(TEXT("\t\n\r "), pos);
            if (token.IsEmpty()) {
                AfxMessageBox(TEXT("Missing value for /mhwnd or -mhwnd in command line arguments."));
                return FALSE;
            }
            errno = 0;
            MessageHwnd = reinterpret_cast<HWND>(_tcstol(token, NULL, 0));
            if (!MessageHwnd || errno) {
                errno = 0;
                CString text;
                text.Format(TEXT("Invalid value for /mhwnd or -mhwnd in command line arguments: %s."), token);
                AfxMessageBox(text);
                return FALSE;
            }
        }
    }

    if (!MessageHwnd) {
        AfxMessageBox(
            TEXT("Missing <MessageHwnd> in command line arguments.\n")
            TEXT("Use /help to print usage."));
        return FALSE;
    }

    return FALSE;
}

INT Application::
ExitInstance()
{
    DbgConPrt(LightRed, TEXT("Application::ExitInstance\n"));
    return CWinApp::ExitInstance();
}
