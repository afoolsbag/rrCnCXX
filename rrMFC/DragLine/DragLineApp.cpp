/// \copyright The MIT License

#include "DragLine/stdafx.h"
#include "DragLine/DragLineApp.h"

#include "DragLine/DragLineMainWnd.h"

BOOL CDragLineApp::InitInstance()
{
    CWinApp::InitInstance();

    m_pMainWnd = new CDragLineMainWnd;
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();
    return TRUE;
}
