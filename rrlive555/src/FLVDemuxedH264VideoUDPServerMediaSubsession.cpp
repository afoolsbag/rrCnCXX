/** \copyright The MIT License */
#include "FLVDemuxedH264VideoUDPServerMediaSubsession.hpp"

#include <live555/H264VideoRTPSink.hh>
#include <live555/H264VideoStreamFramer.hh>

#include "FLVDemuxedH264VideoUDPSource.hpp"

namespace rrdemo {
namespace cdom {
namespace live555 {

FramedSource *FLVDemuxedH264VideoUDPServerMediaSubsession::createNewStreamSource(
    unsigned /*clientSessionId*/, unsigned &estBitrate)
{
    estBitrate = 500/*kbps*/;
    FramedSource *src = FLVDemuxedH264VideoUDPSource::createNew(envir(), port);
    return H264VideoStreamFramer::createNew(envir(), src);
}

RTPSink *FLVDemuxedH264VideoUDPServerMediaSubsession::createNewRTPSink(
    Groupsock* rtpGroupsock, unsigned char /*rtpPayloadTypeIfDynamic*/, FramedSource */*inputSource*/)
{
    return H264VideoRTPSink::createNew(envir(), rtpGroupsock, 96);
}

}// namespace live555
}// namespace cdom
}// namespace rrdemo
