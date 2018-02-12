/// \copyright The MIT License

#include "ComboBoxList/stdafx.h"
#include "ComboBoxList/ComboBoxListApp.h"

#include "ComboBoxList/ComboBoxListMainWnd.h"

BOOL CComboBoxListApp::InitInstance()
{
    CWinApp::InitInstance();

    m_pMainWnd = new CComboBoxListMainWnd;
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();
    return TRUE;
}
