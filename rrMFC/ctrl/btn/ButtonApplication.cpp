/// \copyright The MIT License

#include "stdafx.h"
#include "ButtonApplication.h"

#include "rrwindows/dbgcon.h"

#include "ui/ButtonDialog.h"

IMPLEMENT_DYNAMIC(ButtonApplication, CWinApp)

#// Constructors

ButtonApplication::
ButtonApplication()
{
    NewDbgCon();
    DbgConPrtMeth(Red);
}

ButtonApplication::
~ButtonApplication()
{
    DbgConPrtMeth(Red);
    DelDbgCon();
}

#// Overridables

BOOL ButtonApplication::
InitInstance()
{
    CWinApp::InitInstance();
    DbgConPrtMeth(Red);

    ButtonDialog mnDlg;
    m_pMainWnd = &mnDlg;
    mnDlg.DoModal();

    return FALSE;
}
