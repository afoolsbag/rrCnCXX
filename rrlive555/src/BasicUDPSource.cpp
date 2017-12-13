/** \copyright The MIT License */
#include "BasicUDPSource.hpp"

#include <thread>

namespace rrdemo {
namespace cdom {
namespace live555 {

const char * const BasicUDPSource::OBJECT_TYPE_NAME {"BasicUDPSource"};

IPv4UDPSinkPool BasicUDPSource::GlobalIPv4UDPSinkPool;

BasicUDPSource::BasicUDPSource(UsageEnvironment &env, const u_int16_t port) :
FramedSource(env), port {port}
{
    auto sink = GlobalIPv4UDPSinkPool.find(port);
    assert(sink);
    sink->insertProcessor(this);
}

BasicUDPSource::~BasicUDPSource()
{
    auto sink = GlobalIPv4UDPSinkPool.find(port);
    assert(sink);
    sink->eraseProcessor(this);
}

void BasicUDPSource::doGetNextFrame()
{
    /* 若当前处理缓存为空，则在缓存池中取缓存 */
    if (nullptr == currentFrameBuffer)
        while (nullptr == (currentFrameBuffer = frameBufferPool.pop()))
            std::this_thread::sleep_for(std::chrono::microseconds(100));

    /* 将当前处理缓存中的数据，按指定量，剪切到指定位置 */
    fFrameSize = fmin(currentFrameBuffer->getLoadLength(), fMaxSize);
    currentFrameBuffer->cutDataInto(fTo, fMaxSize, fFrameSize);

    /* 若当前处理缓存处理完毕，则将其回收 */
    if (currentFrameBuffer->isEmpty()) {
        frameBufferPool.recycle(currentFrameBuffer);
        currentFrameBuffer = nullptr;
    }

    /* 事件循环 */
    nextTask() = envir().taskScheduler().scheduleDelayedTask(
        0, reinterpret_cast<TaskFunc *>(afterGetting), this);
}

void BasicUDPSource::whenNewIPv4UDPPacketReceived(
    const IPv4UDPPacketData &pkt, const SOCKADDR_IN &, const SOCKADDR_IN &)
{
    BytesBuffer *buf;
    while (nullptr == (buf = frameBufferPool.allocateForce()))
        std::this_thread::sleep_for(std::chrono::microseconds(100));
    size_t discarded;
    if (0 != (discarded = buf->copyDataFrom(pkt.data, pkt.length)))
        envir() << getObjectTypeName() << ": A UDP pack size is too large for SrcBuf, "
        << discarded << " bytes data has been discarded.\n";
    frameBufferPool.push(buf);
}

void BasicUDPSource::initializeSourceBeforeEventLoop(u_int16_t port)
{
    GlobalIPv4UDPSinkPool.allocate(port);
}

}// namespace live555
}// namespace cdom
}// namespace rrdemo
