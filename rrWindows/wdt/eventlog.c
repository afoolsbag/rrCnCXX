/**
 * \copyright Unlicense
 */

#include "eventlog.h"

#include "service.h"

VOID WINAPI EventLog(WORD type, PCTSTR message)
{
    CONST HANDLE eventSource = RegisterEventSource(NULL, ServiceName);
    if (eventSource) {
        PCTSTR strings[2];
        strings[0] = ServiceName;
        strings[1] = message;

        ReportEvent(eventSource,
                    type, 0, 0, NULL,
                    2, 0,
                    strings, NULL);

        DeregisterEventSource(eventSource);
    }
}
