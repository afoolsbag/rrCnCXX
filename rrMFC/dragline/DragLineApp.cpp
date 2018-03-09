/// \copyright The MIT License

#include "stdafx.h"
#include "DragLineApp.h"

#include "DragLineMainWnd.h"

BOOL CDragLineApp::InitInstance()
{
    CWinApp::InitInstance();

    m_pMainWnd = new CDragLineMainWnd;
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();
    return TRUE;
}
