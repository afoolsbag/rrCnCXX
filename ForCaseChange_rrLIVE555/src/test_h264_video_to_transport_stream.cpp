/** \file
 *  \author zhengrr
 *  \date 2016-12-9 – 14
 *  \copyright The MIT License
 */
#include <live555/BasicUsageEnvironment.hh>
#include <live555/liveMedia.hh>

namespace {

/// 将 H.264 基本流（Elementary Stream）转换为传输流（Transport Stream）。
int Main(int, char *[])
{
    /* 创建任务调度器与使用环境 */
    TaskScheduler *schr {BasicTaskScheduler::createNew()};
    UsageEnvironment *env = BasicUsageEnvironment::createNew(*schr);

    /* 创建源 */
    // 源
    FramedSource *src {ByteStreamFileSource::createNew(*env, "in.264")};
    if (!src) return -1;
    // 成帧器
    H264VideoStreamFramer *framer {H264VideoStreamFramer::createNew(*env, src, True)};
    // 多路复用器
    MPEG2TransportStreamFromESSource *mplexor {MPEG2TransportStreamFromESSource::createNew(*env)};
    mplexor->addNewVideoSource(framer, 5/*H.264*/);

    /* 创建接收器 */
    MediaSink *sink {FileSink::createNew(*env, "out.ts")};
    if (!sink) return -2;

    /* 执行转换 */
    sink->startPlaying(*mplexor, [](void *) {
        exit(EXIT_SUCCESS);
    }, nullptr);

    /* 启用事件循环 */
    env->taskScheduler().doEventLoop();// noreturn
    return EXIT_SUCCESS;
}

}// namespace

#ifdef ENTRY_SWITCH
int main(int argc, char *argv[]) { return Main(argc, argv); }
#endif// ENTRY SWITCH
