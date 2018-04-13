/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

#include "resource.h"
#include "ui/MainDialog.h"

IMPLEMENT_DYNCREATE(Application, CWinApp)

Application::~Application()
{}

BOOL Application::InitInstance()
{
    CWinApp::InitInstance();

#ifdef DEBUG
    if (!AllocConsole())
        AfxMessageBox("Allocate console failed!", MB_ICONEXCLAMATION);
#endif

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
#ifdef DEBUG
    AfxDebugBreak();
    if (!FreeConsole())
        AfxMessageBox("Free console failed!", MB_ICONEXCLAMATION);
#endif

    return CWinApp::ExitInstance();
}
