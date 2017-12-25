/** \file
 *  \brief Flash 视频（FLV、F4V，Flash Video）格式。
 *  \sa [Adobe Flash Video File Format Specification Version 10.1](
 *          http://download.macromedia.com/f4v/video_file_format_spec_v10_1.pdf)
 *  \author zhengrr
 *  \date 2017-1-4 – 16
 *  \copyright The MIT License
 */
#ifndef RRDEMO__CDOM__CPP_LIBRARY__FLASH_VIDEO__HPP
#define RRDEMO__CDOM__CPP_LIBRARY__FLASH_VIDEO__HPP

#include <cstdint>

#include "api.hpp"

namespace rrdemo {
namespace cdom {
namespace cpp_library {

struct RRDEMO__CDOM__CPP_LIBRARY__API FLVTagDataAudio {
    uint8_t soundFormat : 4;            ///< 格式
    uint8_t soundRate : 2;              ///< 采样率
    uint8_t soundSize : 1;              ///< 采样尺寸
    uint8_t soundType : 1;              ///< 单声道或立体声
    union {
        struct {
            uint8_t aacPacketType : 8;  ///< AAC 包类型
            uint8_t *aacData;           ///< AAC 数据
        };
        uint8_t *soundData;             ///< 数据
    };

    bool isLinearPCMPlatformEndian() const { return 0 == soundFormat; }
    bool isADPCM() const { return 1 == soundFormat; }
    bool isMP3() const { return 2 == soundFormat; }
    bool isLinearPCMLittleEndian() const { return 3 == soundFormat; }
    bool isNellymoser16kHzMono() const { return 4 == soundFormat; }
    bool isNellymoser8kHzMono() const { return 5 == soundFormat; }
    bool isNellymoser() const { return 6 == soundFormat; }
    bool isG711AlawLogarithmicPCM() const { return 7 == soundFormat; }
    bool isG711mulawLogarithmicPCM() const { return 8 == soundFormat; }
    bool isAAC() const { return 0xA == soundFormat; }
    bool isSpeex() const { return 0xB == soundFormat; }
    bool isMP38kHz() const { return 0xE == soundFormat; }
    bool isDeviceSpecificSound() const { return 0xF == soundFormat; }
    bool is5d5kHz() const { return 0 == soundRate; }
    bool is11kHz() const { return 1 == soundRate; }
    bool is22kHz() const { return 2 == soundRate; }
    bool is44kHz() const { return 3 == soundRate; }
    bool isSnd8Bit() const { return 0 == soundSize; }
    bool isSnd16Bit() const { return 1 == soundSize; }
    bool isSndMono() const { return 0 == soundType; }
    bool isSndStereo() const { return 1 == soundType; }
    bool isAACSequenceHeader() const { return isAAC() && 0 == aacPacketType; }
    bool isAACRaw() const { return isAAC() && 1 == aacPacketType; }

    /// 解析数据。
    bool parse(const uint8_t * const data, const size_t size);

};// struct FLVTagDataAudio

struct RRDEMO__CDOM__CPP_LIBRARY__API FLVTagDataVideo {
    uint8_t frameType : 4;                    ///< 帧类型
    uint8_t codecID : 4;                      ///< 格式
    union {
        struct {
            uint8_t avcPacketType : 8;        ///< AVC 包类型
            int32_t avcCompositionTime : 24;  ///< AVC 合成时间
            uint8_t *avcData;                 ///< AVC 数据
        };
        uint8_t *videoData;                   ///< 数据
    };

    bool isKeyframe() const { return 1 == frameType; }
    bool isInterFrame() const { return 2 == frameType; }
    bool isDisposableInterFrame() const { return 3 == frameType; }
    bool isGeneratedKeyframe() const { return 4 == frameType; }
    bool isVideoInfoCommandFrame() const { return 5 == frameType; }
    bool isJPEG() const { return 1 == codecID; }
    bool isSorensonH263() const { return 2 == codecID; }
    bool isScreenVideo() const { return 3 == codecID; }
    bool isOn2VP6() const { return 4 == codecID; }
    bool isOn2VP6WithAlphaChannel() const { return 5 == codecID; }
    bool isScreenVideoVersion2() const { return 6 == codecID; }
    bool isAVC() const { return 7 == codecID; }
    bool isAVCSequenceHeader() const { return isAVC() && 0 == avcPacketType; }
    bool isAVCNALU() const { return isAVC() && 1 == avcPacketType; }
    bool isAVCEndOfSequence() const { return isAVC() && 2 == avcPacketType; }
    int32_t getCompositionTime() const { return isAVCNALU() ? avcCompositionTime : 0; }

    /// 解析数据。
    bool parse(const uint8_t * const data, const size_t size);

};// struct FLVTagDataVideo

struct RRDEMO__CDOM__CPP_LIBRARY__API FLVTagDataScript {
    struct Object {
        struct {
            uint16_t length : 16;
            uint8_t *data;
        } name;
        struct {
            uint8_t type : 8;
            union {} value;
        } data;
    } *objects;
    uint32_t end : 32;

};// struct FLVTagDataScript

struct RRDEMO__CDOM__CPP_LIBRARY__API FLVTag {
    /* Tag Header */
    uint8_t  reserved2 : 2;          ///< 保留位，恒为 0
    uint8_t  filter : 1;             ///< 预处理标志位
    uint8_t  tagType : 5;            ///< Tag 类型
    uint32_t dataSize : 24;          ///< 数据区尺寸
    uint32_t timestamp : 24;         ///< 时间戳
    uint8_t  timestampExtended : 8;  ///< 时间戳扩展
    uint32_t streamID : 24;          ///< 恒为 0
    /* Tag Data */
    union {
        FLVTagDataAudio dataAudio;
        FLVTagDataVideo dataVideo;
        FLVTagDataScript dataScript;
    };
    /* Tag Size */
    uint32_t previousTagSize : 32;   ///< 后置尺寸

    bool isAudio() const { return 0x08 == tagType; }
    bool isVideo() const { return 0x09 == tagType; }
    bool isScript() const { return 0x12 == tagType; }
    uint32_t getDataSize() const { return dataSize; }
    uint32_t getTimestamp() const { return static_cast<uint32_t>(timestampExtended) << 24 | static_cast<uint32_t>(timestamp); }

    /// 检验数据是否符合格式。
    static bool Validate(const uint8_t * const data, const size_t size);

    /// 解析数据。
    bool parse(const uint8_t * const data, const size_t size);

};// struct FLVTag

struct RRDEMO__CDOM__CPP_LIBRARY__API FLV {
    /* Header */
    uint32_t signature : 24;          ///< 签名，恒为 'F'(0x46) 'L'(0x4C) 'V'(0x56)
    uint8_t  version : 8;             ///< 版本号
    uint8_t  typeFlagsReserved5 : 5;  ///< 保留位，恒为 0
    uint8_t  typeFlagsAudio : 1;      ///< 音频标志位
    uint8_t  typeFlagsReserved1 : 1;  ///< 保留位，恒为 0
    uint8_t  typeFlagsVideo : 1;      ///< 视频标志位
    uint32_t dataOffset : 32;         ///< 数据偏移量，通常为 9
    /* Header Size */
    uint32_t previousTagSize0 : 32;   ///< 头的后置尺寸，恒为 0
    /* Tags */
    FLVTag *tags;

    uint8_t getVersion() const { return version; }
    bool hasAudio() const { return 1 == typeFlagsAudio; }
    bool hasVideo() const { return 1 == typeFlagsVideo; }
    uint32_t getOffset() const { return dataOffset; }

    /// 检验数据是否符合格式。
    static bool Validate(const uint8_t * const data, const size_t size);

    /// 解析数据。
    bool parse(const uint8_t * const data, const size_t size);

};// struct FLV

}// namespace cpp_library
}// namespace cdom
}// namespace rrdemo

#endif// RRDEMO__CDOM__CPP_LIBRARY__FLASH_VIDEO__HPP
