/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

#include "rrwindows/dbgcon.h"

IMPLEMENT_DYNCREATE(Application, CWinApp)

#// Constructors

BOOL Application::InitInstance()
{
    CWinApp::InitInstance();

    CONST CTime befor = CTime::GetCurrentTime();
    DbgConPrt(White, TEXT("befor: %s\n"), befor.Format(TEXT("%F %T")));

    Sleep(1337/*ms*/);

    CONST CTime after = CTime::GetCurrentTime();
    DbgConPrt(White, TEXT("after: %s\n"), after.Format(TEXT("%F %T")));

    CONST CTimeSpan interval = after - befor;
    DbgConPrt(White, TEXT("interval: %lld\n"), interval.GetTotalSeconds());

    return FALSE;
}
