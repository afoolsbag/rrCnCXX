/** \file
 *  \author zhengrr
 *  \date 2017-1-4 – 10
 *  \copyright The MIT License
 */
#ifndef RRDEMO__CDOM__LIVE555__FLV_DEMUXED_H264_VIDEO_UDP_SERVER_MEDIA_SUBSESSION__HPP
#define RRDEMO__CDOM__LIVE555__FLV_DEMUXED_H264_VIDEO_UDP_SERVER_MEDIA_SUBSESSION__HPP

#include <live555/OnDemandServerMediaSubsession.hh>

namespace rrdemo {
namespace cdom {
namespace live555 {

class FLVDemuxedH264VideoUDPServerMediaSubsession : public OnDemandServerMediaSubsession {
public:
    static FLVDemuxedH264VideoUDPServerMediaSubsession *createNew(UsageEnvironment &env, const u_int16_t port)
    {
        return new FLVDemuxedH264VideoUDPServerMediaSubsession(env, port);  // leak
    }

protected:
    explicit FLVDemuxedH264VideoUDPServerMediaSubsession(UsageEnvironment &env, const u_int16_t port) :
        OnDemandServerMediaSubsession(env, True), port {port}
    {}

    ~FLVDemuxedH264VideoUDPServerMediaSubsession()
    {}

    FramedSource *createNewStreamSource(unsigned clientSessionId,
                                        unsigned &estBitrate) override;

    RTPSink *createNewRTPSink(Groupsock *rtpGroupsock,
                              unsigned char rtpPayloadTypeIfDynamic,
                              FramedSource *inputSource) override;

    u_int16_t port;

};// class FLVDemuxedH264VideoUDPServerMediaSubsession 

}// namespace live555
}// namespace cdom
}// namespace rrdemo

#endif// RRDEMO__CDOM__LIVE555__FLV_DEMUXED_H264_VIDEO_UDP_SERVER_MEDIA_SUBSESSION__HPP
