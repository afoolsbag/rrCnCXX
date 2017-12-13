/** \copyright The MIT License */
#include "AudioDataTransportStreamFrame.hpp"

#include "../../prj-clib/src/parse_bit_stream.h"

namespace {
const unsigned SAMPLING_FREQUENCY_TABLE[16] {    ///< 采样率对应表
    96000, 88200, 64000, 48000, 44100, 32000, 24000, 22050, 16000, 12000, 11025, 8000, 7350, 0, 0, 0
};
const unsigned CHANNEL_CONFIGURATION_TABLE[8] {  ///< 声道配置对应表
    2, 1, 2, 3, 4, 5, 6, 8
};
}// namespace

namespace rrdemo {
namespace cdom {
namespace cpp_library {

unsigned AudioDataTransportStreamFrame::
getSamplingFrequency() const
{
    return SAMPLING_FREQUENCY_TABLE[getSamplingFrequencyIndex()];
}

unsigned AudioDataTransportStreamFrame::
getChannelsNumber() const
{
    return CHANNEL_CONFIGURATION_TABLE[getChannelConfiguration()];
}

bool AudioDataTransportStreamFrame::
Validate(const uint8_t * const data, const size_t size)
{
    AudioDataTransportStreamFrame tmp;
    return tmp.parse(data, size);
}

bool AudioDataTransportStreamFrame::
parse(const uint8_t * const data, const size_t size)
{
    size_t cursor {};
    if (size < 7) return false;
    // Fixed Header
    syncword = zrr_parse16bits(data, size, cursor, 12); cursor += 12;
    if (0xFFF != syncword) return false;
    id = zrr_parse8bits(data, size, cursor, 1); cursor += 1;
    if (0 != id) return false;
    layer = zrr_parse8bits(data, size, cursor, 2); cursor += 2;
    if (0 != layer) return false;
    protection_absent = zrr_parse8bits(data, size, cursor, 1); cursor += 1;
    if (1 != protection_absent) return false;
    profile = zrr_parse8bits(data, size, cursor, 2); cursor += 2;
    sampling_frequency_index = zrr_parse8bits(data, size, cursor, 4); cursor += 4;
    privete_bit = zrr_parse8bits(data, size, cursor, 1); cursor += 1;
    if (0 != privete_bit) return false;
    channel_configuration = zrr_parse8bits(data, size, cursor, 3); cursor += 3;
    original_copy = zrr_parse8bits(data, size, cursor, 1); cursor += 1;
    if (0 != original_copy) return false;
    home = zrr_parse8bits(data, size, cursor, 1); cursor += 1;
    if (0 != home) return false;
    // Variable Header
    copyright_identification_bit = zrr_parse8bits(data, size, cursor, 1); cursor += 1;
    if (0 != copyright_identification_bit) return false;
    copyright_identification_start = zrr_parse8bits(data, size, cursor, 1); cursor += 1;
    if (0 != copyright_identification_start) return false;
    aac_frame_length = zrr_parse16bits(data, size, cursor, 13); cursor += 13;
    adts_buffer_fullness = zrr_parse16bits(data, size, cursor, 11); cursor += 11;
    if (0x7FF != adts_buffer_fullness) return false;
    number_of_raw_data_blocks_in_frame = zrr_parse8bits(data, size, cursor, 2);
    if (0 != number_of_raw_data_blocks_in_frame) return false;
    return true;
}

}// namespace cpp_library
}// namespace cdom
}// namespace rrdemo
