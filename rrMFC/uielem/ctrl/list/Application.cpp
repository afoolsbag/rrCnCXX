/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

#include "utils/dbgcon.inl"

#include "resource.h"
#include "ui/MainDialog.h"

IMPLEMENT_DYNCREATE(Application, CWinApp)

Application::Application()
{
    NewDbgCon(LightRed, TEXT("Application::Constructor\n"));
}

Application::~Application()
{
    DelDbgCon(LightRed, TEXT("Application::Destructor\n"));
}

BOOL Application::InitInstance()
{
    CWinApp::InitInstance();

    MainDialog mainDlg;
    m_pMainWnd = &mainDlg;
    switch (mainDlg.DoModal()) {
    case IDOK: break;
    case IDCANCEL: break;
    default: ASSERT(FALSE); break;
    }

    return FALSE;
}
