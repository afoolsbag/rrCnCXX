/** \file
 *  \author zhengrr
 *  \date 2017-1-3 – 10
 *  \copyright The MIT License
 */
#ifndef RRDEMO__CDOM__LIVE555__ADTS_AUDIO_UDP_SERVER_MEDIA_SUBSESSION__HPP
#define RRDEMO__CDOM__LIVE555__ADTS_AUDIO_UDP_SERVER_MEDIA_SUBSESSION__HPP

#include <live555/OnDemandServerMediaSubsession.hh>

namespace rrdemo {
namespace cdom {
namespace live555 {

class ADTSAudioUDPServerMediaSubsession : public OnDemandServerMediaSubsession {
public:
    static ADTSAudioUDPServerMediaSubsession *createNew(UsageEnvironment &env, const u_int16_t port)
    {
        return new ADTSAudioUDPServerMediaSubsession(env, port);  // leak
    }

protected:
    explicit ADTSAudioUDPServerMediaSubsession(UsageEnvironment &env, const u_int16_t port) :
        OnDemandServerMediaSubsession(env, True), port {port}
    {}

    ~ADTSAudioUDPServerMediaSubsession()
    {};

    FramedSource *createNewStreamSource(unsigned clientSessionId,
                                        unsigned &estBitrate) override;

    RTPSink *createNewRTPSink(Groupsock *rtpGroupsock,
                              unsigned char rtpPayloadTypeIfDynamic,
                              FramedSource *inputSource) override;

    u_int16_t port;

};// class ADTSAudioUDPServerMediaSubsession

}// namespace live555
}// namespace cdom
}// namespace rrdemo

#endif// RRDEMO__CDOM__LIVE555__ADTS_AUDIO_UDP_SERVER_MEDIA_SUBSESSION__HPP
