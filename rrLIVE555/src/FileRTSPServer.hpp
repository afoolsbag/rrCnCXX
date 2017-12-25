/** \file
 *  \author zhengrr
 *  \date 2016-11-2 – 12-27
 *  \copyright The MIT License
 */
#ifndef _RRDEMOCDOMLIVE555_FILERTSPSERVER_HPP
#define _RRDEMOCDOMLIVE555_FILERTSPSERVER_HPP

#include <live555/RTSPServer.hh>

namespace rrdemo {
namespace cdom {
namespace live555 {

class FileRTSPServer : public RTSPServer {
public:
    static FileRTSPServer *createNew(UsageEnvironment &env,
                                     Port rtspPort = 554,
                                     UserAuthenticationDatabase *authDatabase = nullptr,
                                     unsigned reclamationTestSeconds = 65);

protected:
    explicit FileRTSPServer(
        UsageEnvironment &env, int skt, Port port,
        UserAuthenticationDatabase *auth, unsigned recl) :
        RTSPServer(env, skt, port, auth, recl)
    {};

    ~FileRTSPServer() = default;

    ServerMediaSession *lookupServerMediaSession(
        char const *streamName, Boolean isFirstLookupInSession) override;
};

}// namespace live555
}// namespace cdom
}// namespace rrdemo

#endif// _RRDEMOCDOMLIVE555_FILERTSPSERVER_HPP
