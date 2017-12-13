/** \file
 *  \author zhengrr
 *  \date 2017-1-3 – 10
 *  \copyright The MIT License
 */
#ifndef RRDEMO__CDOM__LIVE555__ADTS_AUDIO_UDP_SOURCE__HPP
#define RRDEMO__CDOM__LIVE555__ADTS_AUDIO_UDP_SOURCE__HPP

#include "formats/AudioDataTransportStreamFrame.hpp"
#include "BasicUDPSource.hpp"

namespace rrdemo {
namespace cdom {
namespace live555 {

class ADTSAudioUDPSource : public BasicUDPSource {
protected:
    static const char * const OBJECT_TYPE_NAME;
    const char *getObjectTypeName() const override { return OBJECT_TYPE_NAME; }

public:
    /// 创建新的 ADTSAudioUDPSource 实例。
    static ADTSAudioUDPSource *createNew(UsageEnvironment &env, const u_int16_t port)
    {
        return new ADTSAudioUDPSource(env, port);  // leak
    }

protected:
    /// 构造函数。
    explicit ADTSAudioUDPSource(UsageEnvironment &env, const u_int16_t port) :
        BasicUDPSource(env, port)
    {}

    /// 析构函数。
    ~ADTSAudioUDPSource()
    {}

public:
    /// 检查 ATDS 头信息是否初始化。
    bool isInitialized() const;
    /// 获取采样频率。
    unsigned getSamplingFrequency() const;
    /// 获取采样周期（微秒/帧）。
    unsigned getSamplingCycle() const;
    /// 通道数。
    unsigned getChannelsNumber() const;
    /// 特别配置。
    const char *getConfigurationString();

protected:
    boolean initialized {false};
    char configurationString[5];

public:
    /// 重写的 whenNewIPv4UDPPacketReceived 函数。
    void whenNewIPv4UDPPacketReceived(
        const IPv4UDPPacketData &packetData,
        const SOCKADDR_IN &receiverAddress,
        const SOCKADDR_IN &senderAddress) override;

protected:
    ADTSFHeader adtsfHeader;  ///< 音频数据传输流帧头；

    /// 音频数据传输流帧缓存。
    struct AudioDataTransportStreamFrameBuffer {
        static const size_t SIZE {500000};  ///< 缓存尺寸，百兆网 25FPS 帧最大尺寸；
        u_int8_t data[SIZE];                ///< 缓存数据；
        size_t length {};                   ///< 负载量；
        size_t packetCount {};              ///< 缓存内含用户数据报协议包的数量。
    } adtsfBuffer;            ///< 音频数据传输流帧缓存。

    /// 当新的 ADTSF Buffer 准备完毕时（的回调函数）。
    void whenNewADTSFBufferReady(AudioDataTransportStreamFrameBuffer &buffer);

};// class ADTSAudioUDPSource

}// namespace live555
}// namespace cdom
}// namespace rrdemo

#endif// RRDEMO__CDOM__LIVE555__ADTS_AUDIO_UDP_SOURCE__HPP
