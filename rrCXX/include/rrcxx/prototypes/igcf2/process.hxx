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
        failed_mismatched_format,       ///< 失败：不匹配的格式。
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
};

/// \brief 下载工序。
struct download_process: process_base {
    static constexpr auto static_type {type::download};

    enum class type type() const final
    {
        return static_type;
    }

    ~download_process() final = default;
};

/// \brief 转码工序。
struct transcode_process: process_base {
    static constexpr auto static_type {type::transcode};

    enum class type type() const final
    {
        return static_type;
    }

    ~transcode_process() final = default;
};

/// \brief 识别工序。
struct recognize_process: process_base {
    /// \brief 阶段。
    enum class stage {
        qndvna_transcode,    ///< QnDvna 转码。
        ffmpeg_transcode,    ///< FFmpeg 转码。
        traverse_transcode,  ///< 遍历转码。
    };

    static constexpr auto static_type {type::recognize};

    enum class type type() const final
    {
        return static_type;
    }

    ~recognize_process() final = default;

    stage stage {stage::qndvna_transcode};  ///< 转码方式、阶段。

    std::vector<multimedia_format> possible_format_list;
};

}//namespace rrcxx::prototypes::igcf2

#endif//RRCXX_PROCESS_HXX_
