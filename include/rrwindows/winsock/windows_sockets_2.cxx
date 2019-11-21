/// \copyright Unlicense

#include "rrwindows/winsock/windows_sockets_2.hxx"

#include <memory>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <WinSock2.h>
#pragma comment(lib, "Ws2_32.lib")
#include <WS2tcpip.h>
#include <iphlpapi.h>
#pragma comment(lib, "iphlpapi.lib")

#include "rrwindows/debug/error_handling.hxx"

using namespace std;

namespace rrwindows {

RRWINDOWS_API vector<string> RRWINDOWS_CALL query_adapter_unicast_internet_address()
{
    CONST ULONG ulRecommendedLength {15 * 1000};
    const auto buf = make_unique<BYTE[]>(ulRecommendedLength);

    CONST ULONG flags {
        GAA_FLAG_SKIP_ANYCAST |
        GAA_FLAG_SKIP_MULTICAST |
        GAA_FLAG_SKIP_DNS_SERVER |
        GAA_FLAG_SKIP_FRIENDLY_NAME |
        GAA_FLAG_SKIP_DNS_INFO};
    ULONG ulLen = ulRecommendedLength;
    CONST ULONG ulError = GetAdaptersAddresses(AF_INET,
                                               flags,
                                               nullptr,
                                               reinterpret_cast<PIP_ADAPTER_ADDRESSES>(buf.get()),
                                               &ulLen);
    if (ulError != ERROR_SUCCESS)
        throw system_error_exception("GetAdaptersAddresses failed", ulError);

    vector<string> rv;

    CHAR acIpv4Ipv6Buf[max(max_ipv4_len, max_ipv6_len)];
    for (PIP_ADAPTER_ADDRESSES pstAdapter = reinterpret_cast<PIP_ADAPTER_ADDRESSES>(buf.get()); pstAdapter; pstAdapter = pstAdapter->Next) {
        for (PIP_ADAPTER_UNICAST_ADDRESS pstUnicast = pstAdapter->FirstUnicastAddress; pstUnicast; pstUnicast = pstUnicast->Next) {
            CONST PSOCKADDR pstSocket = pstUnicast->Address.lpSockaddr;
            switch (pstSocket->sa_family) {
            case AF_INET: {
                CONST PSOCKADDR_IN pstSocket4 = reinterpret_cast<PSOCKADDR_IN>(pstSocket);
                if (InetNtopA(AF_INET, &pstSocket4->sin_addr, acIpv4Ipv6Buf, _countof(acIpv4Ipv6Buf)) == nullptr)
                    throw system_error_exception("InetNtopA failed", WSAGetLastError());
                rv.emplace_back(acIpv4Ipv6Buf);
                break;
            }
            case AF_INET6: {
                CONST PSOCKADDR_IN6 pstSocket6 = reinterpret_cast<PSOCKADDR_IN6>(pstSocket);
                if (InetNtopA(AF_INET6, &pstSocket6->sin6_addr, acIpv4Ipv6Buf, _countof(acIpv4Ipv6Buf)) == nullptr)
                    throw system_error_exception("InetNtopA failed", WSAGetLastError());
                rv.emplace_back(acIpv4Ipv6Buf);
                break;
            }
            default:
                break;
            }
        }
    }

    return rv;
}

}
