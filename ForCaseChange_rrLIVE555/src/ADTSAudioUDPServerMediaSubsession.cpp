/** \copyright The MIT License */
#include "ADTSAudioUDPServerMediaSubsession.hpp"

#include <live555/MPEG4GenericRTPSink.hh>

#include "ADTSAudioUDPSource.hpp"

namespace rrdemo {
namespace cdom {
namespace live555 {

FramedSource *ADTSAudioUDPServerMediaSubsession::createNewStreamSource(
    unsigned /*clientSessionId*/, unsigned &estBitrate)
{
    estBitrate = 96/*kbps*/;
    return ADTSAudioUDPSource::createNew(envir(), port);
}

RTPSink *ADTSAudioUDPServerMediaSubsession::createNewRTPSink(
    Groupsock *rtpGroupsock, unsigned char rtpPayloadTypeIfDynamic, FramedSource *inputSource)
{
    auto *src = static_cast<ADTSAudioUDPSource *>(inputSource);
    if (src->isInitialized())
        envir() << "ADTSAudioUDPServerMediaSubsession: No MPEG4GenericRTPSink informations is available.\n";

    return MPEG4GenericRTPSink::createNew(
        envir(), rtpGroupsock, rtpPayloadTypeIfDynamic,
        src->getSamplingFrequency(), "audio", "AAC-hbr", src->getConfigurationString(), src->getChannelsNumber());
}

}// namespace live555
}// namespace cdom
}// namespace rrdemo
