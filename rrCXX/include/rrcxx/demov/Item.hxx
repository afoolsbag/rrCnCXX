//===-- Item ----------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 物项。
///
/// \version 2018-09-10
/// \since 2018-09-10
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_ITEM_HXX_
#define RRCXX_ITEM_HXX_

#include <string>
#include <vector>

#include "MD5.hxx"
#include "MultimediaFormats.hxx"
#include "URI.hxx"
#include "UUID.hxx"

namespace rrcxx {
namespace demov {

///
/// \brief 物项。
/// \details Remote 1:n Local n:1/1:n Formatted 1:1 Recognized\n
///          实时策略：若可能，\n
///          .   远程物项以 5 秒钟分段下载为本地物项，提供实时的播放支持；\n
///          .   本地物项以 1 分钟整合为格式化物项并识别，提供识别支持。\n
///          平衡策略：若可能，\n
///          .   远程物项以 1 分钟分段下载为本地物项，提供播放支持；\n
///          .   本地物项以 10 分钟整合为格式化物项并识别，提供识别支持。\n
///          性能策略：若可能，\n
///          .   远程物项以 10 分钟分段下载为本地物项，提供播放支持；\n
///          .   本地物项以 60 分钟整合为格式化物项并识别，提供高质量的识别支持。
///
struct Item {
    /// \brief 类型。
    enum class Type {
        Remote,      ///< 远程的；
        Local,       ///< 本地的；
        Formatted,   ///< 格式化的；
        Recognized,  ///< 已识别的；
    };

    UUID              uuid;         ///< 标识符。
    URI               uri;          ///< 定位符。
    std::uint64_t     size;         ///< 物项大小（以 Byte 为单位）。
    MD5               md5;          ///< 校验信息摘要。

    std::vector<UUID> precursors;   ///< 前体。
    std::vector<UUID> postcursors;  ///< 后体。

    Type              type;         ///< 类型。
};

///
/// \brief 远程物项。
///
struct RemoteItem: public Item {
    /// \brief 状态。
    enum class Status {
        ReadyToUpload,               ///< 可上传；
        Uploading,                   ///< 在上传；
        Pausing,                     ///< 在暂停；
        Uploaded,                    ///< 已上传；
        Failed,
        Failed_WasCancelled,         ///< 失败：被取消；
        Failed_ResourceNotFound,     ///< 失败：资源未找到；
        Failed_AccessWasDenied,      ///< 失败：访问被拒绝；
        Failed_ConnectionWasBroken,  ///< 失败：连接被中断；
        Failed_OutOfStorage,         ///< 失败：存储不足；
    };

    // properties
    std::string username;  ///< 用户名。
    std::string password;  ///< 密码。

    // processing
    Status        status;    ///< 状态。
    unsigned long exerror;   ///< 扩展错误码。
    double        progress;  ///< 进度。
};

///
/// \brief 本地物项。
///
struct LocalItem: public Item {
    /// \brief 阶段。
    enum class Stage {
        Automatic,    ///< 自动转码；
        Forced,       ///< 强制转码；
        Traversed,    ///< 遍历转码；
        Incompetent,  ///< 不可转码；
    };

    /// \brief 方案。
    struct Scheme {
        PackageFormat fmt;      ///< 封装方式。
        AudioCoding   acodec;   ///< 音频编码方式。
        VideoCoding   vcodec;   ///< 视频编码方式。
        bool          invalid;  ///< 无效的。
    };

    /// \brief 状态。
    enum class Status {
        ReadyToTranscode,         ///< 可转码；
        Transcoding,              ///< 在转码；
        Pausing,                  ///< 在暂停；
        Transcoded,               ///< 已转码；
        Failed,
        Failed_WasCancelled,      ///< 失败：被取消；
        Failed_ResourceNotFound,  ///< 失败：资源未找到；
        Failed_OutOfStorage,      ///< 失败：存储不足；
    };

    /// \brief 分段限制。
    static constexpr std::size_t SegmentLimit {1'000'000};

    // properties
    std::size_t         sn;        ///< 序号。

    // processing
    Stage               stage;     ///< 阶段。
    std::vector<Scheme> schemes;   ///< 方案。
    Status              status;    ///< 状态。
    unsigned long       exerror;   ///< 扩展错误码。
    double              progress;  ///< 进度。
};

///
/// \brief 规格化物项。
///
struct NormalizedItem: public Item {
    /// \brief 状态。
    enum class Status {
        ReadyToRecognize,            ///< 可识别；
        Recognizing,                 ///< 在识别；
        Pausing,                     ///< 在暂停；
        Recognized,                  ///< 已识别；
        Failed,
        Failed_WasCancelled,         ///< 失败：被取消；
        Failed_ResourceNotFound,     ///< 失败：资源未找到；
        Failed_OutOfStorage,         ///< 失败：存储不足；
        Failed_OutOfMemory,          ///< 失败：内存不足；
        Failed_OutOfGraphicsMemory,  ///< 失败：显存不足；
        Failed_UnsupportedFormat,    ///< 失败：不支持的格式；
    };

    /// \brief 分段限制。
    static constexpr std::size_t SegmentLimit {1'000'000};

    // properties
    std::size_t   sn;        ///< 序号。
    PackageFormat fmt;       ///< 封装方式。
    AudioCoding   acodec;    ///< 音频编码方式。
    VideoCoding   vcodec;    ///< 视频编码方式。

    // processing
    Status        status;    ///< 状态。
    unsigned long exerror;   ///< 扩展错误码。
    double        progress;  ///< 进度。
};

///
/// \brief 标签化物项。
///
struct LabeledItem: public Item {
    // properties
};

}//namespace demov
}//namespace rrcxx

#endif//RRCXX_ITEM_HXX_
