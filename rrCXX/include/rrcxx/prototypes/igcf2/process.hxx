//===-- Process -------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 工序。
///
/// \version 2018-09-21
/// \since 2018-09-21
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_PROCESS_HXX_
#define RRCXX_PROCESS_HXX_

#include <chrono>
#include <vector>

#include "multimedia_formats.hxx"
#include "uuid.hxx"

namespace rrcxx::prototypes::igcf2 {

///
/// \brief 工序基类。
///
struct process_base {
    /// \brief 工序种类。
    enum class type {
        download,   ///< 下载。
        transcode,  ///< 转码。
        recognize,  ///< 识别。
    };

    /// \brief 工序状态。
    enum class status {
        ready,                          ///< 就绪。
        running,                        ///< 运行中。
        pausing,                        ///< 暂停中。
        succeeded,                      ///< 成功。
        failed,                         ///< 失败。
        failed_cancel,                  ///< 失败：取消
        failed_not_found,               ///< 失败：资源未找到。
        failed_access_denied,           ///< 失败：拒绝访问。
        failed_connection_broken,       ///< 失败：连接中断。
        failed_out_of_storage,          ///< 失败：存储不足。
        failed_out_of_memory,           ///< 失败：内存不足。
        failed_out_of_graphics_memory,  ///< 失败：显存不足。
        failed_unsupported_format,      ///< 失败：不支持的格式。
    };

    /// \brief 获取工序种类。
    virtual type type() const = 0;

    virtual ~process_base() = default;

    uuid              id {};         ///< 标识符。
    std::vector<uuid> material_ids;  ///< 物料。
    status            status;        ///< 状态。
    double            progress;      ///< 进度。
    std::vector<uuid> product_ids;   ///< 产品。



    uuid              retry_process;  ///< 重试工序。
};

/// \brief 下载工序。
struct download_process: process_base {
    enum class type type() const final
    {
        return type::download;
    }

    ~download_process() final = default;
};

/// \brief 转码工序。
struct transcode_process: process_base {
    enum class type type() const final
    {
        return type::transcode;
    }

    ~transcode_process() final = default;
};

/// \brief 识别工序。
struct recognize_process: process_base {
    enum class type type() const final
    {
        return type::recognize;
    }

    ~recognize_process() final = default;

    video_compression_format vc;   ///< 视频编码。
    audio_compression_format ac;   ///< 音频编码。
    containers_format        fmt;  ///< 包装格式。
};

}//namespace rrcxx::prototypes::igcf2

#endif//RRCXX_PROCESS_HXX_
