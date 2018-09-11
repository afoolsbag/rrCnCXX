//===-- Multimedia Formats --------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 多媒体格式。
///
/// \version 2018-09-11
/// \since 2018-09-11
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_MULTIMEDIA_FORMATS_HXX_
#define RRCXX_MULTIMEDIA_FORMATS_HXX_

namespace rrcxx {
namespace demov {

/// \brief 视频压缩格式。
enum class VideoCompressionFormat {
    /// ISO/IEC 11172 (MPEG-1) - Part 2: Video
    MPEG1,
    /// ISO/IEC 13818 (MEPG-2) - Part 2: Video
    MPEG2,
    /// ISO/IEC 14496 (MPEG-4) - Part 2: Visual
    MPEG4,
    /// ISO/IEC 14496 (MPEG-4) - Part 10: Advanced video coding
    AVC,
    /// ISO/IEC 23008 (MPEG-H) - Part 2: High efficiency video coding
    HEVC,

    /// H.120: Codecs for videoconferencing using primary digital group transmission
    H120,
    /// H.261: Video codec for audiovisual services at p x 64 kbit/s
    H261,
    /// H.262: Information technology - Generic coding of moving pictures and associated audio information: Video
    H262 = MPEG2,
    /// H.236: Video coding for low bit rate communication
    H263,
    /// H.264: Advanced video coding for generic audiovisual services
    H264 = AVC,
    /// H.265: High efficiency video coding
    H265 = HEVC,

    /// RFC 6386: VP8 Data Format and Decoding Guide
    VP8
};

/// \brief 音频压缩格式。
enum class AudioCompressionFormat {
    /// ISO/IEC 11172 (MPEG-1) - Part 3: Audio - Layer I\n
    /// ISO/IEC 13818 (MPEG-2) - Part 3: Audio - Layer I
    MP1,
    /// ISO/IEC 11172 (MPEG-1) - Part 3: Audio - Layer II\n
    /// ISO/IEC 13818 (MPEG-2) - Part 3: Audio - Layer II
    MP2,
    /// ISO/IEC 11172 (MPEG-1) - Part 3: Audio - Layer III\n
    /// ISO/IEC 13818 (MPEG-2) - Part 3: Audio - Layer III
    MP3,
    /// ISO/IEC 13818 (MPEG-2) - Part 7: Advanced audio coding
    AAC,
    /// ISO/IEC 14496 (MPEG-4) - Part 3: Audio - Audio lossless coding
    ALS,
    /// ISO/IEC 14496 (MPEG-4) - Part 3: Audio - Scalable lossless coding
    SLS,
    /// ISO/IEC 14496 (MPEG-4) - Part 3: Audio - Direct stream transfer
    DST,
    /// ISO/IEC 14496 (MPEG-4) - Part 3: Audio - Harmonic vector excitation coding
    HVXC,
    /// ISO/IEC 14496 (MPEG-4) - Part 3: Audio - Code-excited linear prediction
    CELP,
    /// ISO/IEC 23003 (MPEG-D) - Part 1: Surround (Spatial audio coding)
    SAC,
    /// ISO/IEC 23003 (MPEG-D) - Part 3: Unified speech and audio coding
    USAC,
    /// ISO/IEC 23008 (MPEG-H) - Part 3: 3D audio
    TDA,

    /// G.711: Pulse code modulation (PCM) of voice frequencies
    G711,
    /// G.718: Frame error robust narrow-band and wideband embedded variable bit-rate coding of speech and audio from 8-32 kbit/s
    G718,
    /// G.719: Low-complexity, full-band audio coding for high-quality, conversational applications
    G719,
    /// G.722: 7 kHz audio-coding within 64 kbit/s
    G722,
    /// G.722.1: Low-complexity coding at 24 and 32 kbit/s for hands-free operation in systems with low frame loss
    G722d1,
    /// G.722.2: Wideband coding of speech at around 16 kbit/s using Adaptive Multi-Rate Wideband (AMR-WB)
    G722d2,
    /// G.723: Extensions of Recommendation G.721 adaptive differential pulse code modulation to 24 and 40 kbit/s for digital circuit multiplication equipment application
    G723,
    /// G.723.1: Dual rate speech coder for multimedia communications transmitting at 5.3 and 6.3 kbit/s
    G723d1,
    /// G.726: 40, 32, 24, 16 kbit/s Adaptive Differential Pulse Code Modulation (ADPCM)
    G726,
    /// G.728: Coding of speech at 16 kbit/s using low-delay code excited linear prediction
    G728,
    /// G.729: Coding of speech at 8 kbit/s using conjugate-structure algebraic-code-excited linear prediction (CS-ACELP)
    G729,
    /// G.729.1: G.729-based embedded variable bit-rate coder: An 8-32 kbit/s scalable wideband coder bitstream interoperable with G.729
    G729d1,
};

/// \brief 图像压缩格式。
enum class ImageCompressingFormat {
    /// ISO/IEC 10918 (Joint photographic experts group)
    JPG,
    /// ISO/IEC 15444 (JPEG 2000)
    JP2,
    /// ISO/IEC 15948 (Portable network graphics)
    PNG,

    /// Graphics Interchange Format
    GIF,
};

/// \brief 容器格式。
enum class ContainersFormat {
    /// ISO/IEC 11172 (MPEG-1) - Part 3: Audio - Elementary stream\n
    /// ISO/IEC 13818 (MPEG-2) - Part 2: Video - Elementary stream
    ES,
    /// ISO/IEC 13818 (MPEG-2) - Part 1: Systems - Packetized elementary stream
    PES,
    /// ISO/IEC 11172 (MPEG-1) - Part 1: Systems - Program stream\n
    /// ISO/IEC 13818 (MPEG-2) - Part 1: Systems - Program stream
    PS,
    /// ISO/IEC 13818 (MPEG-2) - Part 1: Systems - Transport stream
    TS,
    /// ISO/IEC 14496 (MPEG-4) - Part 14: MP4 file format
    MP4,
    /// ISO/IEC 15444 (JPEG 2000) - Part 3: Motion JPEG 2000
    MJ2,
    /// ISO/IEC 21000 (MPEG-21) - Part 9: File format
    M21,
    /// ISO/IEC 23008 (MPEG-H) - Part 1: MPEG media transport
    MMT,
};

using VideoCoding = VideoCompressionFormat;  ///< 视频编码。
using AudioCoding = AudioCompressionFormat;  ///< 音频编码。
using ImageCoding = ImageCompressingFormat;  ///< 图像编码。
using PackageFormat = ContainersFormat;      ///< 封装格式。

}//namespace demov
}//namespace rrcxx

#endif//RRCXX_MULTIMEDIA_FORMATS_HXX_
