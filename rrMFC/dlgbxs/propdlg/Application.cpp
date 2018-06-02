/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

#include "rrwindows/dbgcon.h"

#include "ui/PropertyPage1.h"
#include "ui/PropertyPage2.h"
#include "ui/PropertyPage3.h"

IMPLEMENT_DYNAMIC(Application, CWinApp)

#// Constructors

Application::
Application()
{
    NewDbgCon();
    DbgConPrtMeth(Red);
}

Application::
~Application()
{
    DbgConPrtMeth(Red);
    DelDbgCon();
}

#// Overridables

BOOL Application::
InitInstance()
{
    CWinApp::InitInstance();
    DbgConPrtMeth(Red);

    CPropertySheet propertySheetDialog(TEXT("Sheet"));
    m_pMainWnd = &propertySheetDialog;

    PropertyPage1 propertyPage1;
    PropertyPage2 propertyPage2;
    PropertyPage3 propertyPage3;

    propertySheetDialog.AddPage(&propertyPage1);
    propertySheetDialog.AddPage(&propertyPage2);
    propertySheetDialog.AddPage(&propertyPage3);

    CONST INT_PTR result = propertySheetDialog.DoModal();
    switch (result) {
    case IDOK:
        break;
    case IDCANCEL:
        break;
    default:
        TRACE1("Unknown switch-case-route with condition %d.", result); ASSERT(FALSE); break;
    }

    return FALSE;
}
