/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

#include <conio.h>

#include "resource.h"
#include "ui/MainDialog.h"

IMPLEMENT_DYNCREATE(Application, CWinApp)

Application::Application()
{
#ifdef DEBUG
    if (!AllocConsole())
        AfxMessageBox("Allocate console failed!", MB_ICONEXCLAMATION);
#endif//DEBUG
    _cputts(TEXT("Application::Constructor\n"));
}

Application::~Application()
{
    _cputts(TEXT("Application::Destructor\n"));
#ifdef DEBUG
    AfxDebugBreak();
    if (!FreeConsole())
        AfxMessageBox("Free console failed!", MB_ICONEXCLAMATION);
#endif//DEBUG
}

BOOL Application::InitApplication()
{
    _cputts(TEXT("Application::InitApplication\n"));
    return CWinApp::InitApplication();
}

BOOL Application::InitInstance()
{
    CWinApp::InitInstance();
    _cputts(TEXT("Application::InitInstance\n"));

    MainDialog mainDlg;
    m_pMainWnd = &mainDlg;
    switch (mainDlg.DoModal()) {
    case IDOK: break;
    case IDCANCEL: break;
    default: ASSERT(FALSE); break;
    }

    return FALSE;
}

INT Application::ExitInstance()
{
    _cputts(TEXT("Application::ExitInstance\n"));
    return CWinApp::ExitInstance();
}
