/** \file
 *  \author zhengrr
 *  \date 2016-12-14
 *  \copyright The MIT License
 */
#include <live555/BasicUsageEnvironment.hh>
#include <live555/GroupsockHelper.hh>
#include <live555/liveMedia.hh>

namespace {

/// 复制器。
int Main(int, char *[])
{
    /* 创建任务调度器与使用环境 */
    TaskScheduler *schr {BasicTaskScheduler::createNew()};
    UsageEnvironment *env = BasicUsageEnvironment::createNew(*schr);

    /* 创建组播套接字，封装为源，并为其创建复制器 */
    struct in_addr inAddr;
    inAddr.s_addr = our_inet_addr("127.0.0.1");
    Groupsock inGrpSkt(*env,
                       /*网际协议地址 */inAddr,
                       /*传输层端口 */Port(8888),
                       /*生存跳数 */static_cast<u_int8_t>(0));
    FramedSource *src {BasicUDPSource::createNew(*env, &inGrpSkt)};
    StreamReplicator *repr {StreamReplicator::createNew(*env, src)};

    /* 将源转发 */
    {
        FramedSource *srcr {repr->createStreamReplica()};

        struct in_addr outAddr;
        outAddr.s_addr = our_inet_addr("192.168.0.9");
        Groupsock *outGrpSkt {new Groupsock(*env, outAddr, Port(4444), static_cast<u_int8_t>(255))};
        MediaSink *sink {BasicUDPSink::createNew(*env, outGrpSkt, static_cast<unsigned>(65536))};

        sink->startPlaying(*srcr, nullptr, nullptr);
    }

    /* 将源转存 */
    {
        FramedSource *srcr {repr->createStreamReplica()};

        MediaSink *sink {FileSink::createNew(*env, "udpsave.out")};
        if (!sink) return -1;

        sink->startPlaying(*srcr, nullptr, nullptr);
    }

    /* 启用事件循环 */
    env->taskScheduler().doEventLoop();// noreturn
    return EXIT_SUCCESS;
}

}// namespace

#ifdef ENTRY_SWITCH
int main(int argc, char *argv[]) { return Main(argc, argv); }
#endif// ENTRY SWITCH
