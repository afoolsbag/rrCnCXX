/** \copyright The MIT License */
#include "H264VideoUDPSource.hpp"

#include <thread>

#include "formats/NetworkAbstractLayerUnit.hpp"

namespace rrdemo {
namespace cdom {
namespace live555 {

const char * const BasicUDPSource::OBJECT_TYPE_NAME {"H264VideoUDPSource"};

void H264VideoUDPSource::
whenNewIPv4UDPPacketReceived(const IPv4UDPPacketData &pkt, const SOCKADDR_IN &, const SOCKADDR_IN &)
{
    auto isReadyHalf = NetworkAbstractLayerUnit::IsHeader(pkt.data, pkt.length);

    if (isReadyHalf && 0 < naluBuffer.length) {
        whenNewNALUBufferReady(naluBuffer);
        naluBuffer.length = 0;
        naluBuffer.packetCount = 0;
    } else
        if (500 <= ++naluBuffer.packetCount)
            envir() << getObjectTypeName() << ": " << naluBuffer.packetCount
            << " consecutive packets without NALU start_codes, the port is receiving H.264 elementary stream?";

    const size_t actlen = fmin(pkt.length, naluBuffer.SIZE - naluBuffer.length);  // actual length
    memcpy_s(naluBuffer.data + naluBuffer.length, actlen, pkt.data, actlen);
    naluBuffer.length += actlen;
    const auto dsclen = pkt.length - actlen;
    if (0 < dsclen)
        envir() << getObjectTypeName() << ": A NALU size is too large for NALU buffer, "
        << dsclen << " bytes data has been discarded.\n";
}

void H264VideoUDPSource::
whenNewNALUBufferReady(NetworkAbstractionLayerUnitBuffer &naluBuf)
{
    BytesBuffer *frameBuf;
    while (nullptr == (frameBuf = frameBufferPool.allocateForce()))
        std::this_thread::sleep_for(std::chrono::microseconds(100));
    const auto dsclen = frameBuf->copyDataFrom(naluBuf.data, naluBuf.length);  // discarded length
    if (0 < dsclen)
        envir() << getObjectTypeName() << ": A NALU buffer size is too large for frame buffer, "
        << dsclen << " bytes data has been discarded.\n";
    frameBufferPool.push(frameBuf);
}


}// namespace live555
}// namespace cdom
}// namespace rrdemo
