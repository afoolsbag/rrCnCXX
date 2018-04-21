/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

#include "utils/dbgcon.h"

#include "resource.h"
#include "ui/MainDialog.h"

IMPLEMENT_DYNCREATE(Application, CWinApp)

#// Constructors

Application::Application()
{
    NewDbgCon(LightRed, TEXT("Application::Constructor\n"));
}

#// Overridables

Application::~Application()
{
    DelDbgCon(LightRed, TEXT("Application::Destructor\n"));
}

BOOL Application::InitInstance()
{
    CWinApp::InitInstance();

    MainDialog mainDlg;
    m_pMainWnd = &mainDlg;
    mainDlg.DoModal();

    return FALSE;
}
