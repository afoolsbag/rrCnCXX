/** \file
 *  \author zhengrr
 *  \date 2016-12-14 – 2017-1-4
 *  \copyright The MIT License
 */
#include <live555/BasicUsageEnvironment.hh>
#include <live555/liveMedia.hh>

namespace {

char newDemuxWatchVariable;
MatroskaFileServerDemux *matroskaDemux {nullptr};
OggFileServerDemux *oggDemux {nullptr};

// 点播实时串流协议服务器。
int Main(int, char *[])
{
    /* 创建任务调度器与使用环境 */
    TaskScheduler *schr {BasicTaskScheduler::createNew()};
    UsageEnvironment *env = BasicUsageEnvironment::createNew(*schr);

    /* 创建用户认证数据库 */
    UserAuthenticationDatabase *auth {new UserAuthenticationDatabase};
    auth->addUserRecord("username", "password");

    /* 创建实时串流协议服务器 */
    RTSPServer *rtspServer {RTSPServer::createNew(*env, 8554, auth)};
    if (!rtspServer) return -1;

    /* MPEG-4 ES (V) */ {
        ServerMediaSession *sms {
            ServerMediaSession::createNew(*env, "mpeg4es", "info", "desc")};
        sms->addSubsession(MPEG4VideoFileServerMediaSubsession
                           ::createNew(*env, "mpeg4es.m4e", /*共用源 */True));
        rtspServer->addServerMediaSession(sms);
    }

    /* H.264 ES (V) */ {
        ServerMediaSession *sms {
            ServerMediaSession::createNew(*env, "h264es", "info", "desc")};
        sms->addSubsession(H264VideoFileServerMediaSubsession
                           ::createNew(*env, "h264es.264", True));
        rtspServer->addServerMediaSession(sms);
    }

    /* H.265 ES (V) */ {
        ServerMediaSession *sms {
            ServerMediaSession::createNew(*env, "h265es", "info", "desc")};
        sms->addSubsession(H265VideoFileServerMediaSubsession
                           ::createNew(*env, "h265es.265", True));
        rtspServer->addServerMediaSession(sms);
    }

    /* MPEG-1/2 PS (A/V) */ {
        ServerMediaSession *sms {
            ServerMediaSession::createNew(*env, "mpeg12ps", "info", "desc")};
        MPEG1or2FileServerDemux *demux/* 解复用器 */ {
            MPEG1or2FileServerDemux::createNew(*env, "mpeg12ps.mpg", True)};
        sms->addSubsession(demux->newAudioServerMediaSubsession());
        sms->addSubsession(demux->newVideoServerMediaSubsession(/*仅关键帧 */True));
        rtspServer->addServerMediaSession(sms);
    }

    /* MPEG-1/2 ES (V) */ {
        ServerMediaSession *sms {
            ServerMediaSession::createNew(*env, "mpeg12es", "info", "desc")};
        sms->addSubsession(MPEG1or2VideoFileServerMediaSubsession
                           ::createNew(*env, "mpeg12es.mpg", True, True));
        rtspServer->addServerMediaSession(sms);
    }

    /* MP3 (A) */ {
        ServerMediaSession *sms {
            ServerMediaSession::createNew(*env, "mp3", "info", "desc")};
        sms->addSubsession(MP3AudioFileServerMediaSubsession
                           ::createNew(*env, "mp3.mp3", True, False, nullptr));
        rtspServer->addServerMediaSession(sms);
    }

    /* WAV (A) */ {
        ServerMediaSession *sms {
            ServerMediaSession::createNew(*env, "wav", "info", "desc")};
        sms->addSubsession(WAVAudioFileServerMediaSubsession
                           ::createNew(*env, "wav.wav", True, False));
        rtspServer->addServerMediaSession(sms);
    }

    /* AMR (A) */ {
        ServerMediaSession *sms {
            ServerMediaSession::createNew(*env, "amr", "info", "desc")};
        sms->addSubsession(AMRAudioFileServerMediaSubsession
                           ::createNew(*env, "amr.amr", True));
        rtspServer->addServerMediaSession(sms);
    }

    /* VOB (AC-3 with MPEG-2 PS) (A/V) */ {
        ServerMediaSession *sms {
            ServerMediaSession::createNew(*env, "vob", "info", "desc")};
        MPEG1or2FileServerDemux *demux {
            MPEG1or2FileServerDemux::createNew(*env, "vob.vob", True)};
        sms->addSubsession(demux->newAC3AudioServerMediaSubsession());
        sms->addSubsession(demux->newVideoServerMediaSubsession(False));
        rtspServer->addServerMediaSession(sms);
    }

    /* MPEG-2 TS */ {
        ServerMediaSession *sms {
            ServerMediaSession::createNew(*env, "mpeg2ts", "info", "desc")};
        sms->addSubsession(MPEG2TransportFileServerMediaSubsession
                           ::createNew(*env, "mpeg2ts.ts", "mpeg2ts.tsx", True));
        rtspServer->addServerMediaSession(sms);
    }

    /* AAC (A) */ {
        ServerMediaSession *sms {
            ServerMediaSession::createNew(*env, "aac", "info", "desc")};
        sms->addSubsession(ADTSAudioFileServerMediaSubsession
                           ::createNew(*env, "aac.aac", True));
        rtspServer->addServerMediaSession(sms);
    }

    /* DV (V) */ {
        OutPacketBuffer::maxSize = /*288000 < */300000;
        ServerMediaSession *sms {
            ServerMediaSession::createNew(*env, "dv", "info", "desc")};
        sms->addSubsession(DVVideoFileServerMediaSubsession
                           ::createNew(*env, "dv.dv", True));
        rtspServer->addServerMediaSession(sms);
    }

    /* AC-3 ES (A) */ {
        ServerMediaSession *sms {
            ServerMediaSession::createNew(*env, "ac3", "info", "desc")};
        sms->addSubsession(AC3AudioFileServerMediaSubsession
                           ::createNew(*env, "ac3es.ac3", True));
        rtspServer->addServerMediaSession(sms);
    }

    /* Matroska (A/V/S) */ {
        ServerMediaSession *sms {
            ServerMediaSession::createNew(*env, "matroska", "info", "desc")};

        newDemuxWatchVariable = 0;
        MatroskaFileServerDemux::createNew(*env, "mkv.mkv", [](MatroskaFileServerDemux *newDemux, void *) {
            matroskaDemux = newDemux;
            newDemuxWatchVariable = 1;
        }, nullptr);
        env->taskScheduler().doEventLoop(&newDemuxWatchVariable);

        Boolean sessionHasTracks {False};
        ServerMediaSubsession *smss;
        while (nullptr != (smss = matroskaDemux->newServerMediaSubsession())) {
            sms->addSubsession(smss);
            sessionHasTracks = True;
        }
        if (sessionHasTracks)
            rtspServer->addServerMediaSession(sms);
    }

    /* WebM (Special Matroska with Vorbis and VP8) (A/V) */ {
        ServerMediaSession *sms {
            ServerMediaSession::createNew(*env, "webm", "info", "desc")};

        newDemuxWatchVariable = 0;
        MatroskaFileServerDemux::createNew(*env, "webm.webm", [](MatroskaFileServerDemux *newDemux, void *) {
            matroskaDemux = newDemux;
            newDemuxWatchVariable = 1;
        }, nullptr);
        env->taskScheduler().doEventLoop(&newDemuxWatchVariable);

        Boolean sessionHasTracks {False};
        ServerMediaSubsession *smss;
        while ((smss = matroskaDemux->newServerMediaSubsession()) != nullptr) {
            sms->addSubsession(smss);
            sessionHasTracks = True;
        }
        if (sessionHasTracks)
            rtspServer->addServerMediaSession(sms);
    }

    /* Ogg (A/V) */ {
        ServerMediaSession *sms {
            ServerMediaSession::createNew(*env, "ogg", "info", "desc")};

        newDemuxWatchVariable = 0;
        OggFileServerDemux::createNew(*env, "ogg.ogg", [](OggFileServerDemux *demux, void *) {
            oggDemux = demux;
            newDemuxWatchVariable = 1;
        }, nullptr);
        env->taskScheduler().doEventLoop(&newDemuxWatchVariable);

        Boolean sessionHasTracks {False};
        ServerMediaSubsession *smss;
        while ((smss = oggDemux->newServerMediaSubsession()) != nullptr) {
            sms->addSubsession(smss);
            sessionHasTracks = True;
        }
        if (sessionHasTracks)
            rtspServer->addServerMediaSession(sms);
    }

    /* Opus (Special OGG) (A) */ {
        ServerMediaSession *sms {
            ServerMediaSession::createNew(*env, "opus", "info", "desc")};

        newDemuxWatchVariable = 0;
        OggFileServerDemux::createNew(*env, "opus.opus", [](OggFileServerDemux *demux, void *) {
            oggDemux = demux;
            newDemuxWatchVariable = 1;
        }, nullptr);
        env->taskScheduler().doEventLoop(&newDemuxWatchVariable);

        Boolean sessionHasTracks {False};
        ServerMediaSubsession *smss;
        while ((smss = oggDemux->newServerMediaSubsession()) != nullptr) {
            sms->addSubsession(smss);
            sessionHasTracks = True;
        }
        if (sessionHasTracks)
            rtspServer->addServerMediaSession(sms);
    }

    /* MPEG-2 TS UDP */ {
        ServerMediaSession *sms {
            ServerMediaSession::createNew(*env, "mpeg2tsudp", "info", "desc")};
        sms->addSubsession(MPEG2TransportUDPServerMediaSubsession
                           ::createNew(*env, "127.0.0.1", 1234, False));
        rtspServer->addServerMediaSession(sms);
    }

#ifdef ENABLE_RTSP_OVER_HTTP_TUNNELING
    /* 创建超文本传输协议服务器，提供 RTSP-over-HTTP 隧道功能 */
    if (rtspServer->setUpTunnelingOverHTTP(80) ||
        rtspServer->setUpTunnelingOverHTTP(8000) ||
        rtspServer->setUpTunnelingOverHTTP(8080)) {
        *env << "RTSP-over-HTTP tunneling port: " << rtspServer->httpServerPortNum() << " (optional).\n";
    } else {
        *env << "RTSP-over-HTTP tunneling is not available.\n";
    }
#endif

    /* 启用事件循环 */
    env->taskScheduler().doEventLoop();// noreturn
    return EXIT_SUCCESS;
}

}// namespace

#ifdef ENTRY_SWITCH
int main(int argc, char *argv[]) { return Main(argc, argv); }
#endif// ENTRY SWITCH
