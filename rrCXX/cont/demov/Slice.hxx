//===-- Slice ---------------------------------------------------*- C++ -*-===//
///
/// \defgroup gSlice 分片
/// \ingroup gDemoV
///
/// \version 2018-08-21
/// \since 2018-07-31
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_SLICE_HXX_
#define RRCXX_SLICE_HXX_

#include <string>

namespace rrcxx {
namespace demov {

/// @addtogroup gSlice
/// @{

///
/// \brief 分片。
///
class Slice {
public:
    /// \brief 状态。
    enum class Status {
        ACTIVE,                         ///< 活动。
        PAUSING,                        ///< 暂停。
        FINISHED,                       ///< 完毕。
        FAILED_CANCELED,                ///< 失败：人为取消。
        FAILED_ACCESS_DENIED,           ///< 失败：拒绝访问。
        FAILED_CONNECTION_BROKEN,       ///< 失败：连接中断。
        FAILED_OUT_OF_STORAGE,          ///< 失败：存储不足。
        FAILED_OUT_OF_MEMORY,           ///< 失败：内存不足。
        FAILED_OUT_OF_GRAPHICS_MEMORY,  ///< 失败：显存不足。
        FAILED_UNKNOWN                  ///< 失败：未知原因。
    };

    /// \brief 阶段。
    enum class Stage {
        ORIGINAL,               ///< 原始的。
        UPLOADING,              ///< 上传中。
        UPLOADED,               ///< 已上传。
        TRANSCODING,            ///< 转码中。
        TRANSCODED,             ///< 已转码。
        EXTRACTING,             ///< 提取中。
        EXTRACTED,              ///< 已提取。
        DETECTING,              ///< 检测中。
        DETECTED,               ///< 已检测。
        RECOGNIZING,            ///< 识别中。
        RECOGNIZED,             ///< 已识别。
        PROCESSED               ///< 已处理。
    };

private:
    unsigned serialNumber_;   ///< 序列号。
    Status   status_;         ///< 状态。
    Stage    stage_;          ///< 阶段。
    double   stageProgress_;  ///< 阶段进度。

    std::string path_;        ///< 路径。

public:
    inline const unsigned    &serialNumber()  const { return serialNumber_; }
    inline const Status      &status()        const { return status_; }
    inline const Stage       &stage()         const { return stage_; }
    inline const double      &stegeProgress() const { return stageProgress_; }
    inline const std::string &path()          const { return path_; }

private:
    /// \brief 构造函数。
    inline Slice(const unsigned serialNumber, const Stage stage, const std::string &path)
    {
        serialNumber_ = serialNumber;
        status_ = Status::ACTIVE;
        stage_ = stage;
        stageProgress_ = 0;
        path_ = path;
    }

public:
    /// \brief 原始分片。
    inline static Slice Original(const std::string &path)
    {
        return Slice(0, Stage::ORIGINAL, path);
    }

    /// \brief 片段分片。
    inline static Slice Fragment(const unsigned serialNumber, const std::string &path)
    {
        return Slice(serialNumber, Stage::TRANSCODED, path);
    }

    /// \brief 暂停。
    /// \details 为防止资源搁置，暂停将回退正在进行的处理。
    bool pause();

    /// \brief 恢复。
    bool resume();

    /// \brief 失败。
    /// \details 失败将回退正在进行的处理。
    bool fail(const Status failedStatus);

    /// \brief 重试。
    bool retry();

    /// \brief 上传。
    bool upload(const double progress, const bool finished = false, const std::string &newPath = "");

    /// \brief 转码。
    bool transcode(const double progress, const bool finished = false);

    /// \brief 提取（特征）。
    bool extract(const double progress, const bool finished = false);

    /// \brief 检测（分割）。
    bool detect(const double progress, const bool finished = false);

    /// \brief 识别（分类）。
    bool recognize(const double progress, const bool finished = false);
};

/// @}

}//namespace demov
}//namespace rrcxx

#endif//RRCXX_SLICE_HXX_
