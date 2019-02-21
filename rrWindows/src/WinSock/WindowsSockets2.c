/** \copyright Unlicense */

#define RRWINDOWS_EXPORTS
#include "rrWindows/WinSock/WindowsSockets2.h"

#include <WinSock2.h>
#pragma comment(lib, "Ws2_32.lib")
#include <iphlpapi.h>
#pragma comment(lib, "iphlpapi.lib")

RRWINDOWS_API
IN_ADDR
WINAPI
GetFirstAdapterUnicastIPv4InternetAddress(VOID)
{
    CONST ULONG RecommendedLength = 15 * 1000;

    IN_ADDR rv = {{{0}}};

    CONST ULONG flags =
        GAA_FLAG_SKIP_ANYCAST |
        GAA_FLAG_SKIP_MULTICAST |
        GAA_FLAG_SKIP_DNS_SERVER |
        GAA_FLAG_SKIP_FRIENDLY_NAME |
        GAA_FLAG_SKIP_DNS_INFO;

    PIP_ADAPTER_ADDRESSES CONST buf = HeapAlloc(GetProcessHeap(), 0, RecommendedLength);
    if (!buf) {
        SetLastError(ERROR_OUTOFMEMORY);
        return rv;
    }

    ULONG len = RecommendedLength;

    CONST ULONG ec = GetAdaptersAddresses(AF_INET, flags, NULL, buf, &len);
    if (ec != ERROR_SUCCESS) {
        HeapFree(GetProcessHeap(), 0, buf);
        SetLastError(ec);
        return rv;
    }

    for (PIP_ADAPTER_ADDRESSES adapter = buf; adapter; adapter = adapter->Next) {
        for (PIP_ADAPTER_UNICAST_ADDRESS unicast = adapter->FirstUnicastAddress; unicast; unicast = unicast->Next) {
            PSOCKADDR CONST socket = unicast->Address.lpSockaddr;
            if (socket->sa_family == AF_INET){
                PSOCKADDR_IN CONST socket4 = (PSOCKADDR_IN)socket;
                rv = socket4->sin_addr;
                goto break_loop;
            }
        }
    }
break_loop:

    HeapFree(GetProcessHeap(), 0, buf);
    return rv;
}
