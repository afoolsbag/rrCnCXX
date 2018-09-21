//===-- Multimedia Formats --------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 多媒体格式。
///
/// \version 2018-09-21
/// \since 2018-09-11
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_MULTIMEDIA_FORMATS_HXX_
#define RRCXX_MULTIMEDIA_FORMATS_HXX_

namespace rrcxx::prototypes::igcf2 {

/// \brief 视频压缩格式。
enum class video_compression_format {
    /// ISO/IEC 11172 (MPEG-1) - Part 2: Video
    mpeg1,
    /// ISO/IEC 13818 (MEPG-2) - Part 2: Video
    mpeg2,
    /// ISO/IEC 14496 (MPEG-4) - Part 2: Visual
    mpeg4,
    /// ISO/IEC 14496 (MPEG-4) - Part 10: Advanced video coding
    avc,
    /// ISO/IEC 23008 (MPEG-H) - Part 2: High efficiency video coding
    hevc,

    /// H.120: Codecs for videoconferencing using primary digital group transmission
    h120,
    /// H.261: Video codec for audiovisual services at p x 64 kbit/s
    h261,
    /// H.262: Information technology - Generic coding of moving pictures and associated audio information: Video
    h262 = mpeg2,
    /// H.236: Video coding for low bit rate communication
    h263,
    /// H.264: Advanced video coding for generic audiovisual services
    h264 = avc,
    /// H.265: High efficiency video coding
    h265 = hevc,

    /// RFC 6386: VP8 Data Format and Decoding Guide
    vp8
};

/// \brief 音频压缩格式。
enum class audio_compression_format {
    /// ISO/IEC 11172 (MPEG-1) - Part 3: Audio - Layer I\n
    /// ISO/IEC 13818 (MPEG-2) - Part 3: Audio - Layer I
    mp1,
    /// ISO/IEC 11172 (MPEG-1) - Part 3: Audio - Layer II\n
    /// ISO/IEC 13818 (MPEG-2) - Part 3: Audio - Layer II
    mp2,
    /// ISO/IEC 11172 (MPEG-1) - Part 3: Audio - Layer III\n
    /// ISO/IEC 13818 (MPEG-2) - Part 3: Audio - Layer III
    mp3,
    /// ISO/IEC 13818 (MPEG-2) - Part 7: Advanced audio coding
    aac,
    /// ISO/IEC 14496 (MPEG-4) - Part 3: Audio - Audio lossless coding
    als,
    /// ISO/IEC 14496 (MPEG-4) - Part 3: Audio - Scalable lossless coding
    sls,
    /// ISO/IEC 14496 (MPEG-4) - Part 3: Audio - Direct stream transfer
    dst,
    /// ISO/IEC 14496 (MPEG-4) - Part 3: Audio - Harmonic vector excitation coding
    hvxc,
    /// ISO/IEC 14496 (MPEG-4) - Part 3: Audio - Code-excited linear prediction
    celp,
    /// ISO/IEC 23003 (MPEG-D) - Part 1: Surround (Spatial audio coding)
    sac,
    /// ISO/IEC 23003 (MPEG-D) - Part 3: Unified speech and audio coding
    usac,
    /// ISO/IEC 23008 (MPEG-H) - Part 3: 3D audio
    tda,

    /// G.711: Pulse code modulation (PCM) of voice frequencies
    g711,
    /// G.718: Frame error robust narrow-band and wideband embedded variable bit-rate coding of speech and audio from 8-32 kbit/s
    g718,
    /// G.719: Low-complexity, full-band audio coding for high-quality, conversational applications
    g719,
    /// G.722: 7 kHz audio-coding within 64 kbit/s
    g722,
    /// G.722.1: Low-complexity coding at 24 and 32 kbit/s for hands-free operation in systems with low frame loss
    g722_1,
    /// G.722.2: Wideband coding of speech at around 16 kbit/s using Adaptive Multi-Rate Wideband (AMR-WB)
    g722_2,
    /// G.723: Extensions of Recommendation G.721 adaptive differential pulse code modulation to 24 and 40 kbit/s for digital circuit multiplication equipment application
    g723,
    /// G.723.1: Dual rate speech coder for multimedia communications transmitting at 5.3 and 6.3 kbit/s
    g723_1,
    /// G.726: 40, 32, 24, 16 kbit/s Adaptive Differential Pulse Code Modulation (ADPCM)
    g726,
    /// G.728: Coding of speech at 16 kbit/s using low-delay code excited linear prediction
    g728,
    /// G.729: Coding of speech at 8 kbit/s using conjugate-structure algebraic-code-excited linear prediction (CS-ACELP)
    g729,
    /// G.729.1: G.729-based embedded variable bit-rate coder: An 8-32 kbit/s scalable wideband coder bitstream interoperable with G.729
    g729_1,
};

/// \brief 图像压缩格式。
enum class image_compressing_format {
    /// ISO/IEC 10918 (Joint photographic experts group)
    jpg,
    /// ISO/IEC 15444 (JPEG 2000)
    jp2,
    /// ISO/IEC 15948 (Portable network graphics)
    png,

    /// Graphics Interchange Format
    gif,
};

/// \brief 容器格式。
enum class containers_format {
    /// ISO/IEC 11172 (MPEG-1) - Part 3: Audio - Elementary stream\n
    /// ISO/IEC 13818 (MPEG-2) - Part 2: Video - Elementary stream
    es,
    /// ISO/IEC 13818 (MPEG-2) - Part 1: Systems - Packetized elementary stream
    pes,
    /// ISO/IEC 11172 (MPEG-1) - Part 1: Systems - Program stream\n
    /// ISO/IEC 13818 (MPEG-2) - Part 1: Systems - Program stream
    ps,
    /// ISO/IEC 13818 (MPEG-2) - Part 1: Systems - Transport stream
    ts,
    /// ISO/IEC 14496 (MPEG-4) - Part 14: MP4 file format
    mp4,
    /// ISO/IEC 15444 (JPEG 2000) - Part 3: Motion JPEG 2000
    mj2,
    /// ISO/IEC 21000 (MPEG-21) - Part 9: File format
    m21,
    /// ISO/IEC 23008 (MPEG-H) - Part 1: MPEG media transport
    mmt,
};

}//namespace rrcxx::prototypes::igcf2

#endif//RRCXX_MULTIMEDIA_FORMATS_HXX_
