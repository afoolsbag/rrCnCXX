/** \file
 *  \brief 音频数据传输流帧（ADTSF，Audio Data Transport Stream Frame）格式。
 *  \sa [ISO/IEC 13818-7:2006(en)](
 *          http://iso.org/obp/ui/#iso:std:iso-iec:13818:-7:ed-4:v1:en)
 *  \author zhengrr
 *  \date 2017-1-3 – 14
 *  \copyright The MIT License
 */
#ifndef RRDEMO__CDOM__CPP_LIBRARY__AUDIO_DATA_TRANSPORT_STREAM_FRAME__HPP
#define RRDEMO__CDOM__CPP_LIBRARY__AUDIO_DATA_TRANSPORT_STREAM_FRAME__HPP

#include <cstdint>

#include "api.hpp"

namespace rrdemo {
namespace cdom {
namespace cpp_library {

/// 音频数据传输流帧。
struct RRDEMO__CDOM__CPP_LIBRARY__API AudioDataTransportStreamFrame {
    /* Fixed Header */
    uint16_t syncword : 12;                           ///< 同步码，恒为 FFF(16)
    uint8_t  id : 1;                                  ///< 恒为 0
    uint8_t  layer : 2;                               ///< 恒为 0
    uint8_t  protection_absent : 1;                   ///< 恒为 1
    uint8_t  profile : 2;                             ///< 配置
    uint8_t  sampling_frequency_index : 4;            ///< 采样率下标
    uint8_t  privete_bit : 1;                         ///< 恒为 0
    uint8_t  channel_configuration : 3;               ///< 声道配置
    uint8_t  original_copy : 1;                       ///< 恒为 0
    uint8_t  home : 1;                                ///< 恒为 0
    /* Variable Header */
    uint8_t  copyright_identification_bit : 1;        ///< 恒为 0
    uint8_t  copyright_identification_start : 1;      ///< 恒为 0
    uint16_t aac_frame_length : 13;                   ///< 全帧长度
    uint16_t adts_buffer_fullness : 11;               ///< 恒为 7FF(16)
    uint8_t  number_of_raw_data_blocks_in_frame : 2;  ///< 恒为 0
    /* Data */
    uint8_t *aacData;                                 ///< AAC 数据

    uint8_t getProfile() const { return profile; }
    uint8_t getSamplingFrequencyIndex() const { return sampling_frequency_index; }
    unsigned getSamplingFrequency() const;
    uint8_t getChannelConfiguration() const { return  channel_configuration; }
    unsigned getChannelsNumber() const;

    /// 检验数据是否符合格式。
    static bool Validate(const uint8_t * const data, const size_t size);

    /// 解析数据。
    bool parse(const uint8_t * const data, const size_t size);

};// struct AudioDataTransportStreamFrame

}// namespace cpp_library
}// namespace cdom
}// namespace rrdemo

#endif// RRDEMO__CDOM__CPP_LIBRARY__AUDIO_DATA_TRANSPORT_STREAM_FRAME__HPP
