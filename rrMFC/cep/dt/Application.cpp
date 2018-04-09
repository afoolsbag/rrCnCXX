/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

IMPLEMENT_DYNCREATE(Application, CWinApp)

BOOL Application::InitInstance()
{
    CWinApp::InitInstance();

    CONST CTime befor = CTime::GetCurrentTime();
    TRACE(TEXT("befor: %s\n"), befor.Format(TEXT("%F %T")));

    Sleep(1337/*ms*/);

    CONST CTime after = CTime::GetCurrentTime();
    TRACE(TEXT("after: %s\n"), after.Format(TEXT("%F %T")));

    CONST CTimeSpan interval = after - befor;
    TRACE(TEXT("interval: %lld\n"), interval.GetTotalSeconds());

    return FALSE;
}
