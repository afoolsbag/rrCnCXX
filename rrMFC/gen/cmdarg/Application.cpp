/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

IMPLEMENT_DYNCREATE(Application, CWinApp)

BOOL Application::InitInstance()
{
    CWinApp::InitInstance();

    TRACE(TEXT("%s\n"),GetCommandLine());

    return FALSE;
}
