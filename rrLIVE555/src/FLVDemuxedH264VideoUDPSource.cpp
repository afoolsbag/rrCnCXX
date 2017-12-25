/** \copyright The MIT License */
#include "FLVDemuxedH264VideoUDPSource.hpp"

#include "formats/FlashVideo.hpp"

namespace rrdemo {
namespace cdom {
namespace live555 {

const char * const BasicUDPSource::OBJECT_TYPE_NAME {"FLVDemuxedH264VideoUDPSource"};

void FLVDemuxedH264VideoUDPSource::
whenNewIPv4UDPPacketReceived(const IPv4UDPPacketData &pkt, const SOCKADDR_IN &, const SOCKADDR_IN &)
{
    if (FLVTagHeader::IsTagHeader(pkt.data, pkt.length) && 0 < flvBuffer.length) {
        whenNewFLVBufferReady(flvBuffer);
        flvBuffer.length = 0;
        flvBuffer.packetCount = 0;
    } else {
        if (500 <= ++flvBuffer.packetCount)
            envir() << getObjectTypeName() << ": " << flvBuffer.packetCount
            << " consecutive packets without FLV tag header, the port is receiving FLV stream?";
    }

    const size_t actlen = fmin(pkt.length, flvBuffer.SIZE - flvBuffer.length);  // actual length
    memcpy_s(flvBuffer.data + flvBuffer.length, actlen, pkt.data, actlen);
    flvBuffer.length += actlen;
    if (0 < pkt.length - actlen)
        envir() << getObjectTypeName() << ": A FLV tag size is too large for FLV buffer, "
        << pkt.length - actlen << " bytes data has been discarded.\n";
}

void FLVDemuxedH264VideoUDPSource::
whenNewFLVBufferReady(FlashVideoBuffer &flvBuf)
{
    const auto &TAG_HEADER_SIZE = FLVTagHeader::TAG_HEADER_SIZE;
    const auto &PREVIOUS_TAG_SIZE_SIZE = FLVPreviousTagSize::PREVIOUS_TAG_SIZE_SIZE;

    FLVTagHeader tagHeader;
    if (!tagHeader.parse(flvBuf.data, flvBuf.length)) {
        envir() << getObjectTypeName() << ": Bad tag header.\n";
        return;
    }
    if (!tagHeader.isVideo())
        return;
    const auto tagSize = TAG_HEADER_SIZE + tagHeader.getDataSize();
    if (flvBuf.length != tagSize + PREVIOUS_TAG_SIZE_SIZE) {
        envir() << getObjectTypeName() << ": Bad DataSize.\n";
        return;
    }

    FLVTagDataVideo tagData;
    if (!tagData.parse(flvBuf.data + TAG_HEADER_SIZE, flvBuf.length - TAG_HEADER_SIZE)) {
        envir() << getObjectTypeName() << ": Bad tag data (video).\n";
        return;
    }
    if (!tagData.isAVC()) {
        envir() << getObjectTypeName() << ": Bad CodecID.\n";
        return;
    }

    size_t cur {};  // cursor
    if (tagData.isAVCSequenceHeader()) {
        /* AVC Sequence Header */

    } else if (tagData.isAVCNALU()) {
        /* AVC NAL Unit */

    } else if (tagData.isAVCEndOfSequence()) {
        /* AVC End of Sequence */

    } else {
        envir() << getObjectTypeName() << ": Bad AVCPacketType.\n";
        return;
    }

    whenNewNALUBufferReady(naluBuffer);

    FLVPreviousTagSize preTagSize;
    if (!preTagSize.parse(flvBuf.data + tagSize, flvBuf.length - tagSize)) {
        envir() << getObjectTypeName() << ": Bad previous tag size.\n";
        return;
    }
    if (tagSize != preTagSize.getSize())
        envir() << getObjectTypeName() << ": Bad PreviousTagSize.\n";
}

}// namespace live555
}// namespace cdom
}// namespace rrdemo
