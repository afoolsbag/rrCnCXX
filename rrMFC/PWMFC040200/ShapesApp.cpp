/// \copyright The MIT License

#include "stdafx.h"
#include "ShapesApp.h"

#include "ShapesMainFrm.h"
#include "ShapesAboutDlg.h"

BEGIN_MESSAGE_MAP(CShapesApp, CWinApp)
    ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
END_MESSAGE_MAP()

CShapesApp::CShapesApp()
{
    ;
}

BOOL CShapesApp::InitInstance()
{
    CWinApp::InitInstance();

    CShapesMainFrm *mainfrm = new CShapesMainFrm;
    m_pMainWnd = mainfrm;

    mainfrm->LoadFrame(IDR_MAINFRAME,
                       WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
                       NULL);
    mainfrm->ShowWindow(SW_SHOW);
    mainfrm->UpdateWindow();

    return TRUE;
}

void CShapesApp::OnAppAbout()
{
    CShapesAboutDlg aboutDlg;
    aboutDlg.DoModal();
}
