/** \file
 *  \author zhengrr
 *  \date 2016-12-30 – 2017-1-10
 *  \copyright The MIT License
 */
#ifndef RRDEMO__CDOM__LIVE555__BASIC_UDP_SOURCE_HPP
#define RRDEMO__CDOM__LIVE555__BASIC_UDP_SOURCE_HPP

#include <live555/FramedSource.hh>

#include "tools/BytesBuffer.hpp"
#include "tools/DoubleQueuePool.hpp"
#include "tools/UDPSinkPool.hpp"

namespace rrdemo {
namespace cdom {
namespace live555 {

class BasicUDPSource : public FramedSource, public IPv4UDPProcessor {
protected:
    static const char * const OBJECT_TYPE_NAME;
    virtual const char *getObjectTypeName() const { return OBJECT_TYPE_NAME; }

public:
    /// 创建新的 BasicUDPSource 实例。
    static BasicUDPSource *createNew(UsageEnvironment &env, u_int16_t port)
    {
        return new BasicUDPSource(env, port);
    }

protected:
    /// 构造函数。
    explicit BasicUDPSource(UsageEnvironment &env, const u_int16_t port);

    /// 析构函数。
    ~BasicUDPSource();

    /// 重写的 doGetNextFrame 函数。
    void doGetNextFrame() override;

    DoubleQueuePool<BytesBuffer> frameBufferPool {3};  ///< 帧缓存池。
    BytesBuffer *currentFrameBuffer {};                ///< 当前处理帧缓存；

public:
    /// 重写的 whenNewIPv4UDPPacketReceived 函数。
    void whenNewIPv4UDPPacketReceived(
        const IPv4UDPPacketData &packetData,
        const SOCKADDR_IN &receiverAddress,
        const SOCKADDR_IN &senderAddress) override;

    /// 于 LIVE555 事件循环前，手动初始化源。
    /** 受 LIVE555 机制影响，于回调函数中创建的 WinSock 无法接收到数据，原因尚不明；
     *  因而临时提供此函数，用以在事件循环之前手动初始化源。
     *  \param port 绑定端口，主机序。
     */
    static void initializeSourceBeforeEventLoop(u_int16_t port);

private:
    static IPv4UDPSinkPool GlobalIPv4UDPSinkPool;  ///< 全局 IPv4 UDP Sink Pool。

    u_int16_t port;  ///< 用户数据报协议收流端口。

};// H264VideoUdpSource

}// namespace live555
}// namespace cdom
}// namespace rrdemo

#endif// RRDEMO__CDOM__LIVE555__BASIC_UDP_SOURCE_HPP
