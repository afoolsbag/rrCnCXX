/** \copyright The MIT License */
#include "FLVDemuxedADTSAudioUDPServerMediaSubsession.hpp"

#include <live555/MPEG4GenericRTPSink.hh>

#include "FLVDemuxedADTSAudioUDPSource.hpp"

namespace rrdemo {
namespace cdom {
namespace live555 {

FramedSource *FLVDemuxedADTSAudioUDPServerMediaSubsession::createNewStreamSource(
    unsigned /*clientSessionId*/, unsigned &estBitrate)
{
    estBitrate = 96/*kbps*/;
    return FLVDemuxedADTSAudioUDPSource::createNew(envir(), port);
}

RTPSink *FLVDemuxedADTSAudioUDPServerMediaSubsession::createNewRTPSink(
    Groupsock *rtpGroupsock, unsigned char rtpPayloadTypeIfDynamic, FramedSource *inputSource)
{
    auto *src = static_cast<FLVDemuxedADTSAudioUDPSource *>(inputSource);
    if (src->isInitialized())
        envir() << "FLVDemuxedADTSAudioUDPServerMediaSubsession: No MPEG4GenericRTPSink informations is available.\n";

    return MPEG4GenericRTPSink::createNew(
        envir(), rtpGroupsock, rtpPayloadTypeIfDynamic,
        src->getSamplingFrequency(), "audio", "AAC-hbr", src->getConfigurationString(), src->getChannelsNumber());
}

}// namespace live555
}// namespace cdom
}// namespace rrdemo
