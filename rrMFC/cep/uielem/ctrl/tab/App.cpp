/// \copyright The MIT License

#include "stdafx.h"
#include "App.h"

#include "MainDlg.h"

IMPLEMENT_DYNCREATE(CApp, CWinApp)

//BEGIN_MESSAGE_MAP(CApp, CWinApp)
//END_MESSAGE_MAP()

BOOL CApp::InitInstance()
{
    CWinApp::InitInstance();

    CMainDlg main_dlg;
    m_pMainWnd = &main_dlg;
    switch (main_dlg.DoModal()) {
    case IDOK: break;
    case IDCANCEL: break;
    default: ASSERT(FALSE); break;
    }

    return FALSE;
}
