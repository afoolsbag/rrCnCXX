/** \copyright The MIT License */
#include "UDPSink.hpp"

namespace {

using rrdemo::cdom::cpp_library::UDPSink;
using rrdemo::cdom::cpp_library::UserDatagram;

/// 用户数据报协议收流线程函数。
void UDPSinkReceiverThreadFunction(UDPSink * const sink)
{
    SOCKET skt;  // socket
    skt = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (INVALID_SOCKET == skt) {
        WSAGetLastError();
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    SOCKADDR_IN rcvAddr {};  // receiver address
    rcvAddr.sin_family = AF_INET;
    rcvAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    rcvAddr.sin_port = htons(sink->port);
    if (SOCKET_ERROR == bind(skt, reinterpret_cast<PSOCKADDR>(&rcvAddr), sizeof rcvAddr)) {
        WSAGetLastError();
        closesocket(skt);
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    ULONG soRcvBuf {32 /*KiB*/ * 1024};
    if (SOCKET_ERROR == setsockopt(skt, SOL_SOCKET, SO_RCVBUF, reinterpret_cast<const char *>(&soRcvBuf), sizeof soRcvBuf)) {
        WSAGetLastError();
        exit(EXIT_FAILURE);
    }

    TIMEVAL timer {};
    FD_SET set {};
    SOCKADDR_IN sndAddr {};           // sender address
    int sndAddrLen {sizeof sndAddr};  // sender address length
    UserDatagram usrDgram;            // user datagram

    while (sink->receiverThreadLoopFlag) {
        while (sink->processorSet.empty())
            std::this_thread::sleep_for(std::chrono::milliseconds(100));

        timerclear(&timer);
        timer.tv_sec = 1;
        timer.tv_usec = 0;

        FD_ZERO(&set);
        FD_SET(skt, &set);
        if (select(0, &set, nullptr, nullptr, &timer) <= 0)
            continue;
        if (!FD_ISSET(skt, &set))
            continue;

        usrDgram.length = recvfrom(skt, reinterpret_cast<char *>(usrDgram.data), usrDgram.DATA_MAXIMUM_SIZE, 0, reinterpret_cast<SOCKADDR *>(&sndAddr), &sndAddrLen);
        if (SOCKET_ERROR == usrDgram.length) {
            WSAGetLastError();
            continue;
        }

        sink->processorSetMutex.lock(); {
            for (auto dest : sink->processorSet)
                dest->whenNewUserDatagramReceived(usrDgram, rcvAddr, sndAddr);
        } sink->processorSetMutex.unlock();
    }

    closesocket(skt);

}// function UDPSinkReceiverThreadFunction

}// namespace

namespace rrdemo {
namespace cdom {
namespace cpp_library {

UDPSink::
UDPSink(const uint16_t port):
    port {port}
{
    receiverThreadLoopFlag = true;
    receiverThread = new std::thread(UDPSinkReceiverThreadFunction, this);
}

UDPSink::
~UDPSink()
{
    receiverThreadLoopFlag = false;
    receiverThread->join();
}

void UDPSink::
insertProcessor(UDPProcessor * const processor)
{
    processorSetMutex.lock(); {
        processorSet.insert(processor);
    } processorSetMutex.unlock();
}

void UDPSink::
eraseProcessor(UDPProcessor * const processor)
{
    processorSetMutex.lock(); {
        processorSet.erase(processor);
    } processorSetMutex.unlock();
}

}// namespace cpp_library
}// namespace cdom
}// namespace rrdemo
