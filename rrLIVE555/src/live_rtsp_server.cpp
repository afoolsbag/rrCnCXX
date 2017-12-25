/** \file
 *  \author zhengrr
 *  \date 2016-12-15 – 2017-1-10
 *  \copyright The MIT License
 */
#include <thread>

#include <live555/BasicUsageEnvironment.hh>
#include <live555/liveMedia.hh>

#include "ADTSAudioUDPServerMediaSubsession.hpp"
#include "ADTSAudioUDPSource.hpp"
#include "H264VideoUDPServerMediaSubsession.hpp"
#include "H264VideoUDPSource.hpp"
#include "FLVDemuxedADTSAudioUDPServerMediaSubsession.hpp"
#include "FLVDemuxedADTSAudioUDPSource.hpp"
#include "FLVDemuxedH264VideoUDPServerMediaSubsession.hpp"
#include "FLVDemuxedH264VideoUDPSource.hpp"

namespace {
int Main(int, char *[])
{
    using rrdemo::cdom::live555::ADTSAudioUDPServerMediaSubsession;
    using rrdemo::cdom::live555::ADTSAudioUDPSource;
    using rrdemo::cdom::live555::H264VideoUDPServerMediaSubsession;
    using rrdemo::cdom::live555::H264VideoUDPSource;
    using rrdemo::cdom::live555::FLVDemuxedADTSAudioUDPServerMediaSubsession;
    using rrdemo::cdom::live555::FLVDemuxedADTSAudioUDPSource;
    using rrdemo::cdom::live555::FLVDemuxedH264VideoUDPServerMediaSubsession;
    using rrdemo::cdom::live555::FLVDemuxedH264VideoUDPSource;

    /* 创建任务调度器与使用环境 */
    TaskScheduler *schr {BasicTaskScheduler::createNew()};
    UsageEnvironment *env = BasicUsageEnvironment::createNew(*schr);

    /* 创建实时串流协议服务器 */
    RTSPServer *server {RTSPServer::createNew(*env)};
    if (nullptr == server) {
        *env << "Failed to create RTSP server: " << env->getResultMsg() << "\n";
        return EXIT_FAILURE;
    }
    *env << "ZHENGRR'S RTSP SERVER\n";
    *env << server->rtspURLPrefix() << "<stream name>\n";
    *env << "\n";

    *env << "Stream List:\n";

    /* ADTS (A) UDP */ {
        ServerMediaSession *sms {
            ServerMediaSession::createNew(*env, "adtsudp", "info", "desc")};
        ADTSAudioUDPSource::initializeSourceBeforeEventLoop(10096);
        sms->addSubsession(ADTSAudioUDPServerMediaSubsession::createNew(*env, 10096));
        server->addServerMediaSession(sms);
        *env << server->rtspURL(sms) << "\n";
        std::this_thread::sleep_for(std::chrono::microseconds(30));
    }

    /* H.264 ES (V) UDP */ {
        ServerMediaSession *sms {
            ServerMediaSession::createNew(*env, "h264udp", "info", "desc")};
        OutPacketBuffer::maxSize = 300000;
        H264VideoUDPSource::initializeSourceBeforeEventLoop(10097);
        sms->addSubsession(H264VideoUDPServerMediaSubsession::createNew(*env, 10097));
        server->addServerMediaSession(sms);
        *env << server->rtspURL(sms) << "\n";
        std::this_thread::sleep_for(std::chrono::microseconds(30));
    }

    /* FLV with ADTS and H.264 ES (A/V) UDP */ {
        ServerMediaSession *sms {
            ServerMediaSession::createNew(*env, "flvudp", "info", "desc")};
        OutPacketBuffer::maxSize = 300000;
        FLVDemuxedADTSAudioUDPSource::initializeSourceBeforeEventLoop(10098);
        FLVDemuxedH264VideoUDPSource::initializeSourceBeforeEventLoop(10098);
        sms->addSubsession(FLVDemuxedADTSAudioUDPServerMediaSubsession::createNew(*env, 10098));
        sms->addSubsession(FLVDemuxedH264VideoUDPServerMediaSubsession::createNew(*env, 10098));
        server->addServerMediaSession(sms);
        *env << server->rtspURL(sms) << "\n";
        std::this_thread::sleep_for(std::chrono::microseconds(30));
    }

    *env << "\n";

    /* 启用事件循环 */
    env->taskScheduler().doEventLoop();// noreturn
    return EXIT_SUCCESS;
}
}// namespace

#ifndef ENTRY_SWITCH
int main(int argc, char *argv[]) { return Main(argc, argv); }
#endif// ENTRY SWITCH
