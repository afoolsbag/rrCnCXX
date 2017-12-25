/** \file
 *  \author zhengrr
 *  \date 2016-12-15 – 2017-1-10
 *  \copyright The MIT License
 */
#ifndef RRDEMO__CDOM__LIVE555__H264_VIDEO_UDP_SERVER_MEDIA_SUBSESSION__HPP
#define RRDEMO__CDOM__LIVE555__H264_VIDEO_UDP_SERVER_MEDIA_SUBSESSION__HPP

#include <live555/OnDemandServerMediaSubsession.hh>

namespace rrdemo {
namespace cdom {
namespace live555 {

class H264VideoUDPServerMediaSubsession : public OnDemandServerMediaSubsession {
public:
    static H264VideoUDPServerMediaSubsession *createNew(UsageEnvironment &env, const u_int16_t port)
    {
        return new H264VideoUDPServerMediaSubsession(env, port);  // leak
    }

protected:
    explicit H264VideoUDPServerMediaSubsession(UsageEnvironment &env, const u_int16_t port) :
        OnDemandServerMediaSubsession(env, True), port {port}
    {}

    ~H264VideoUDPServerMediaSubsession()
    {}

    FramedSource *createNewStreamSource(unsigned clientSessionId,
                                        unsigned &estBitrate) override;

    RTPSink *createNewRTPSink(Groupsock *rtpGroupsock,
                              unsigned char rtpPayloadTypeIfDynamic,
                              FramedSource *inputSource) override;

    u_int16_t port;

};// class H264VideoUDPServerMediaSubsession 

}// namespace live555
}// namespace cdom
}// namespace rrdemo

#endif// RRDEMO__CDOM__LIVE555__H264_VIDEO_UDP_SERVER_MEDIA_SUBSESSION__HPP
