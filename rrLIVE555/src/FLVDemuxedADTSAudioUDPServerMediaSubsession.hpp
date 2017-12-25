/** \file
 *  \author zhengrr
 *  \date 2017-1-4
 *  \copyright The MIT License
 */
#ifndef RRDEMO__CDOM__LIVE555_FLV_DEMUXED_ADTS_AUDIO_UDP_SERVER_MEDIA_SUBSESSION__HPP
#define RRDEMO__CDOM__LIVE555_FLV_DEMUXED_ADTS_AUDIO_UDP_SERVER_MEDIA_SUBSESSION__HPP

#include <live555/OnDemandServerMediaSubsession.hh>

namespace rrdemo {
namespace cdom {
namespace live555 {

class FLVDemuxedADTSAudioUDPServerMediaSubsession : public OnDemandServerMediaSubsession {
public:
    static FLVDemuxedADTSAudioUDPServerMediaSubsession *createNew(UsageEnvironment &env, const u_int16_t port)
    {
        return new FLVDemuxedADTSAudioUDPServerMediaSubsession(env, port);  // leak
    }

protected:
    explicit FLVDemuxedADTSAudioUDPServerMediaSubsession(UsageEnvironment &env, const u_int16_t port) :
        OnDemandServerMediaSubsession(env, True), port {port}
    {}

    ~FLVDemuxedADTSAudioUDPServerMediaSubsession()
    {};

    FramedSource *createNewStreamSource(unsigned clientSessionId,
                                        unsigned &estBitrate) override;

    RTPSink *createNewRTPSink(Groupsock *rtpGroupsock,
                              unsigned char rtpPayloadTypeIfDynamic,
                              FramedSource *inputSource) override;

    u_int16_t port;

};// class FLVDemuxedADTSAudioUDPServerMediaSubsession

}// namespace live555
}// namespace cdom
}// namespace rrdemo

#endif// RRDEMO__CDOM__LIVE555_FLV_DEMUXED_ADTS_AUDIO_UDP_SERVER_MEDIA_SUBSESSION__HPP
