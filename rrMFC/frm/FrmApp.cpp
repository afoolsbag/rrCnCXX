/// \copyright The MIT License

#include "stdafx.h"
#include "FrmApp.h"

#include "rrwindows/dbgcon.h"

#include "ui/Frm.h"

#// Constructors

FrameApplication::
FrameApplication()
{
    AllocDebugConsole();
    DcMeth();
}

FrameApplication::
~FrameApplication()
{
    DcMeth();
    FreeDebugConsole();
}

#// Overridables

BOOL FrameApplication::
InitInstance()
{
    CWinApp::InitInstance();
    DcMeth();

    m_pMainWnd = DEBUG_NEW Frame;
    dynamic_cast<Frame *>(m_pMainWnd)->LoadFrame(Frame::IDR);
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();

    return TRUE;
}
