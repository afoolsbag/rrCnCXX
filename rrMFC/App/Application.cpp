/// \copyright The Unlicense

#include "stdafx.h"
#include "Application.h"

namespace rrMFC {

// Overridables

BOOL Application::
InitInstance()
{
    CWinApp::InitInstance();
    TRACE(__FUNCTION__ "\n");
    return FALSE;
}

int Application::
ExitInstance()
{
    TRACE(__FUNCTION__ "\n");
    return CWinApp::ExitInstance();
}

}//namespace rrMFC
