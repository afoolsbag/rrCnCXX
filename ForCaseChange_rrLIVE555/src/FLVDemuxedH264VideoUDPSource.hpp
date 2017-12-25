/** \file
 *  \author zhengrr
 *  \date 2017-1-4 – 10
 *  \copyright The MIT License
 */
#ifndef RRDEMO__CDOM__LIVE555__FLV_DEMUXED_H264_VIDEO_UDP_SOURCE__HPP
#define RRDEMO__CDOM__LIVE555__FLV_DEMUXED_H264_VIDEO_UDP_SOURCE__HPP

#include "formats/AdvancedVideoCoding.hpp"
#include "H264VideoUDPSource.hpp"

namespace rrdemo {
namespace cdom {
namespace live555 {

class FLVDemuxedH264VideoUDPSource : public H264VideoUDPSource {
protected:
    static const char * const OBJECT_TYPE_NAME;
    const char *getObjectTypeName() const override { return OBJECT_TYPE_NAME; }

public:
    /// 创建新的 H264VideoUDPSource 实例。
    static FLVDemuxedH264VideoUDPSource *createNew(
        UsageEnvironment &env, const u_int16_t port)
    {
        return new FLVDemuxedH264VideoUDPSource(env, port);
    }

protected:
    /// 构造函数。
    explicit FLVDemuxedH264VideoUDPSource(UsageEnvironment &env, const u_int16_t port) :
        H264VideoUDPSource(env, port)
    {}

    /// 析构函数。
    ~FLVDemuxedH264VideoUDPSource() = default;

public:
    /// 重写的 whenNewIPv4UDPPacketReceived 函数。
    void whenNewIPv4UDPPacketReceived(
        const IPv4UDPPacketData &packetData,
        const SOCKADDR_IN &receiverAddress,
        const SOCKADDR_IN &senderAddress) override;

protected:
    AVCSequenceHeader avcSequenceHeader;  ///< 高级视频编码序列头。

    /// FLV 缓存。
    struct FlashVideoBuffer {
        static const size_t SIZE {500000};  ///< 缓存尺寸，百兆网 25FPS 帧最大尺寸；
        u_int8_t data[SIZE];                ///< 缓存数据；
        size_t length {};                   ///< 负载量；
        size_t packetCount {};              ///< 缓存内含用户数据报协议包计数。
    } flvBuffer;  ///< FLV 缓存。

    /// 当新的 NALU Buffer 准备完毕时（的回调函数）。
    void whenNewFLVBufferReady(FlashVideoBuffer &buffer);

};// class FLVDemuxedH264VideoUDPSource

}// namespace live555
}// namespace cdom
}// namespace rrdemo

#endif// RRDEMO__CDOM__LIVE555__FLV_DEMUXED_H264_VIDEO_UDP_SOURCE__HPP
