/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

IMPLEMENT_DYNCREATE(Application, CWinApp)

Application::Application()
{
    MessageHwnd = NULL;
}

BOOL Application::InitInstance()
{
    CWinApp::InitInstance();

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
