/** \copyright The MIT License */
#include "FileRTSPServer.hpp"

#include <live555/BasicUsageEnvironment.hh>
#include <live555/liveMedia.hh>

namespace {

struct MatroskaDemuxCreationState {
    MatroskaFileServerDemux *demux;
    char watch;
};

struct OggDemuxCreationState {
    OggFileServerDemux* demux;
    char watchVariable;
};

const Boolean REUSE {False};
ServerMediaSession *CreateNewServerMediaSession(UsageEnvironment &env,
                                                char const *name,
                                                FILE *)
{
    const char *ext {strrchr(name, '.')};
    if (!ext) return nullptr;

    ServerMediaSession *sms = nullptr;
    if (!strcmp(ext, ".aac")) {
        sms->addSubsession(
            ADTSAudioFileServerMediaSubsession::createNew(env, name, REUSE));
    } else if (!strcmp(ext, ".amr")) {
        sms->addSubsession(
            AMRAudioFileServerMediaSubsession::createNew(env, name, REUSE));
    } else if (!strcmp(ext, ".ac3")) {
        sms->addSubsession(
            AC3AudioFileServerMediaSubsession::createNew(env, name, REUSE));
    } else if (!strcmp(ext, ".m4e")) {
        sms->addSubsession(
            MPEG4VideoFileServerMediaSubsession::createNew(env, name, REUSE));
    } else if (!strcmp(ext, ".264")) {
        OutPacketBuffer::maxSize = 100000;
        sms->addSubsession(
            H264VideoFileServerMediaSubsession::createNew(env, name, REUSE));
    } else if (!strcmp(ext, ".265")) {
        OutPacketBuffer::maxSize = 100000;
        sms->addSubsession(
            H265VideoFileServerMediaSubsession::createNew(env, name, REUSE));
    } else if (!strcmp(ext, ".mp3")) {
        sms->addSubsession(
            MP3AudioFileServerMediaSubsession::createNew(env, name, REUSE, False, nullptr));
    } else if (!strcmp(ext, ".mpg")) {
        MPEG1or2FileServerDemux *demux {
            MPEG1or2FileServerDemux::createNew(env, name, REUSE)};
        sms->addSubsession(demux->newAudioServerMediaSubsession());
        sms->addSubsession(demux->newVideoServerMediaSubsession());
    } else if (!strcmp(ext, ".vob")) {
        MPEG1or2FileServerDemux *demux {
            MPEG1or2FileServerDemux::createNew(env, name, REUSE)};
        sms->addSubsession(demux->newAC3AudioServerMediaSubsession());
        sms->addSubsession(demux->newVideoServerMediaSubsession());
    } else if (!strcmp(ext, ".ts")) {
        size_t idxlen {strlen(name) + 1/*x*/ + 1/*\n*/};
        char *idxname {new char[idxlen]};
        sprintf_s(idxname, idxlen, "%sx", name);
        sms->addSubsession(
            MPEG2TransportFileServerMediaSubsession::createNew(env, name, idxname, REUSE));
        delete[] idxname;
    } else if (!strcmp(ext, ".wav")) {
        sms->addSubsession(
            WAVAudioFileServerMediaSubsession::createNew(env, name, REUSE, False));
    } else if (!strcmp(ext, ".dv")) {
        OutPacketBuffer::maxSize = 300000;
        sms->addSubsession(
            DVVideoFileServerMediaSubsession::createNew(env, name, REUSE));
    } else if (!strcmp(ext, ".mkv") || !strcmp(ext, ".webm")) {
        OutPacketBuffer::maxSize = 100000;
        MatroskaDemuxCreationState creationState;
        creationState.watch = 0;
        MatroskaFileServerDemux::createNew(env, name, [](MatroskaFileServerDemux *demux, void *data) {
            MatroskaDemuxCreationState *state {
                static_cast<MatroskaDemuxCreationState*>(data)};
            state->demux = demux;
            state->watch = !0;
        }, &creationState);
        env.taskScheduler().doEventLoop(&creationState.watch);

        ServerMediaSubsession *smss;
        while ((smss = creationState.demux->newServerMediaSubsession())) {
            sms->addSubsession(smss);
        }
    } else if (!strcmp(ext, ".ogg") || !strcmp(ext, ".ogv") || !strcmp(ext, ".opus")) {
        OggDemuxCreationState creationState;
        creationState.watchVariable = 0;
        OggFileServerDemux::createNew(env, name, [](OggFileServerDemux *demux, void *data) {
            OggDemuxCreationState *state {
                static_cast<OggDemuxCreationState*>(data)};
            state->demux = demux;
            state->watchVariable = !0;
        }, &creationState);
        env.taskScheduler().doEventLoop(&creationState.watchVariable);
        ServerMediaSubsession* smss;
        while ((smss = creationState.demux->newServerMediaSubsession())) {
            sms->addSubsession(smss);
        }
    }

    return sms;
}
}// namespace

namespace rrdemo {
namespace cdom {
namespace live555 {

FileRTSPServer *FileRTSPServer::createNew(UsageEnvironment &env,
                                          Port port,
                                          UserAuthenticationDatabase *auth,
                                          unsigned recl)
{
    int skt {setUpOurSocket(env, port)};
    if (-1 == skt)
        return nullptr;

    return new FileRTSPServer(env, skt, port, auth, recl);
}

ServerMediaSession *FileRTSPServer::lookupServerMediaSession(char const *name,
                                                             Boolean first)
{
    FILE *fid;
    fopen_s(&fid, name, "rb");

    ServerMediaSession *sms {RTSPServer::lookupServerMediaSession(name)};

    if (!fid) {
        if (sms) removeServerMediaSession(sms);
        return nullptr;
    } else {
        if (sms && first) {
            removeServerMediaSession(sms);
            sms = nullptr;
        }
        if (!sms) {
            sms = CreateNewServerMediaSession(envir(), name, fid);
            addServerMediaSession(sms);
        }
        fclose(fid);
        return sms;
    }
}

}// namespace live555
}// namespace cdom
}// namespace rrdemo

namespace {
int Main(int, char *[])
{
    using FileRTSPServer = rrdemo::cdom::live555::FileRTSPServer;

    /* 创建任务调度器与使用环境 */
    TaskScheduler *schr {BasicTaskScheduler::createNew()};
    UsageEnvironment *env {BasicUsageEnvironment::createNew(*schr)};

    /* 创建用户认证数据库 */
    UserAuthenticationDatabase *auth {new UserAuthenticationDatabase};
    auth->addUserRecord("username", "password");

    /* 创建实时串流协议服务器 */
    if (FileRTSPServer::createNew(*env, 554, auth)) {
        *env << "Bind port 554.\n";
    } else if (FileRTSPServer::createNew(*env, 8554, auth)) {
        *env << "Bind port 8554.\n";
    } else {
        *env << "Failed to create RTSP server: " << env->getResultMsg() << "\n";
        return EXIT_FAILURE;
    }

    /* 启用事件循环 */
    env->taskScheduler().doEventLoop();// noreturn
    return EXIT_SUCCESS;
}
}// namespace

#ifdef ENTRY_SWITCH
int main(int argc, char *argv[]) { return Main(argc, argv); }
#endif// ENTRY SWITCH
