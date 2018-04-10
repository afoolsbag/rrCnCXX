/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

#include "MainDialog.h"

IMPLEMENT_DYNCREATE(Application, CWinApp)

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
