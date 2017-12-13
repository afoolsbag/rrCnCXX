/** \copyright The MIT License */
#include "ADTSAudioUDPSource.hpp"

#include <thread>

namespace {
using rrdemo::cdom::live555::AudioDataTransportStreamFrame;
auto &SAMPLING_FREQUENCY_TABLE = AudioDataTransportStreamFrame::SAMPLING_FREQUENCY_TABLE;
auto &CHANNEL_CONFIGURATION_TABLE = AudioDataTransportStreamFrame::CHANNEL_CONFIGURATION_TABLE;

}// namespace

namespace rrdemo {
namespace cdom {
namespace live555 {

const char * const BasicUDPSource::OBJECT_TYPE_NAME {"ADTSAudioUDPSource"};

bool ADTSAudioUDPSource::
isInitialized() const
{
    return initialized;
}

unsigned ADTSAudioUDPSource::
getSamplingFrequency() const
{
    return SAMPLING_FREQUENCY_TABLE[adtsfHeader.sampling_frequency_index];
}

unsigned ADTSAudioUDPSource::
getSamplingCycle() const
{
    return 1024. / getSamplingFrequency() * 1000 * 1000;
}

unsigned ADTSAudioUDPSource::
getChannelsNumber() const
{
    return CHANNEL_CONFIGURATION_TABLE[adtsfHeader.channel_configuration];
}

const char* ADTSAudioUDPSource::getConfigurationString()
{
    sprintf_s(configurationString, sizeof configurationString, "%02X%02x",
              static_cast<uint8_t>(adtsfHeader.profile + 1 << 3 | adtsfHeader.sampling_frequency_index >> 1),
              static_cast<uint8_t>(adtsfHeader.sampling_frequency_index << 7 | adtsfHeader.channel_configuration << 3));
    return configurationString;
}

void ADTSAudioUDPSource::
whenNewIPv4UDPPacketReceived(
const IPv4UDPPacketData &pkt, const SOCKADDR_IN &, const SOCKADDR_IN &)
{
    auto isReadyHalf = false;
    if (!AudioDataTransportStreamFrame::ParseHeader(adtsfHeader, pkt.data, pkt.length))
        /*skip*/;
    else if (3 == adtsfHeader.profile)
        envir() << getObjectTypeName() << ": Bad profile.\n";
    else if (0 == SAMPLING_FREQUENCY_TABLE[adtsfHeader.sampling_frequency_index])
        envir() << getObjectTypeName() << ": Bad sampling_frequency_index.\n";
    else if (0 == CHANNEL_CONFIGURATION_TABLE[adtsfHeader.channel_configuration])
        envir() << getObjectTypeName() << ": Bad channel_configuration.\n";
    else {
        isReadyHalf = true;
        initialized = true;
    }

    if (isReadyHalf && 0 < adtsfBuffer.length) {
        whenNewADTSFBufferReady(adtsfBuffer);
        adtsfBuffer.length = 0;
        adtsfBuffer.packetCount = 0;
    } else
        if (500 < ++adtsfBuffer.packetCount)
            envir() << getObjectTypeName() << ": " << adtsfBuffer.packetCount
            << " consecutive packets without ADTS syncwork, the port is receiving audio data transport stream?";

    const size_t actlen = fmin(pkt.length, adtsfBuffer.SIZE - adtsfBuffer.length);  // actual length
    memcpy_s(adtsfBuffer.data + adtsfBuffer.length, actlen, pkt.data, actlen);
    adtsfBuffer.length += actlen;
    const auto dsclen = pkt.length - actlen;
    if (0 < dsclen)
        envir() << getObjectTypeName() << ": A ADTSF size is too large for ADTSF buffer, "
        << dsclen << " bytes data has been discarded.\n";
}

void ADTSAudioUDPSource::
whenNewADTSFBufferReady(AudioDataTransportStreamFrameBuffer &adtsfBuf)
{
    BytesBuffer *frameBuf;
    while (nullptr == (frameBuf = frameBufferPool.allocateForce()))
        std::this_thread::sleep_for(std::chrono::microseconds(100));
    const auto dsclen = frameBuf->copyDataFrom(adtsfBuf.data, adtsfBuf.length);  // discarded length
    if (0 < dsclen)
        envir() << getObjectTypeName() << ": A ADTSF buffer size is too large for frame buffer, "
        << dsclen << " bytes data has been discarded.\n";
    frameBufferPool.push(frameBuf);
}

}// namespace live555
}// namespace cdom
}// namespace rrdemo
