//===-- Slice ---------------------------------------------------*- C++ -*-===//
///
/// \defgroup gSlice 分片
/// \ingroup gDemoV
///
/// \version 2018-07-31
/// \since 2018-07-31
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_SLICE_HXX_
#define RRCXX_SLICE_HXX_

#include <cassert>
#include <string>

namespace rrcxx {
namespace demov {

/// @addtogroup gVideo
/// @{

///
/// \brief 分片。
///
struct Slice {
    /// \brief 分片类型。
    enum class Type {
        UNKNOWN,   ///< 未知。
        COMPLETE,  ///< 完整。
        INDEX,     ///< 索引。
        CLIP       ///< 片段。
    };

    /// \brief 分片阶段。
    enum class Stage {
        PREPARING,           ///< 筹备中。
        READY_TO_UPLOAD,     ///< 可以上传。
        UPLOADING,           ///< 上传中。
        READY_TO_TRANSCODE,  ///< 可以转码。
        TRANSCODING,         ///< 转码中。
        READY_TO_EXTRACT,    ///< 可以提取（特征）。
        EXTRACTING,          ///< 提取中。
        READY_TO_DETECT,     ///< 可以检测（分割）。
        DETECTING,           ///< 检测中。
        READY_TO_RECOGNIZE,  ///< 可以识别（分类）。
        RECOGNIZING,         ///< 识别中。
        FINISHED             ///< 结束。
    };

    /// \brief 分片状态。
    enum class Status {
        WELL,                          ///< 顺利。
        PAUSED,                        ///< 暂停。
        FAILED_UNKNOWN,                ///< 失败：未知原因。
        FAILED_CANCELED,               ///< 失败：人为取消。
        FAILED_ACCESS_DENIED,          ///< 失败：拒绝访问。
        FAILED_CONNECTION_BROKEN,      ///< 失败：连接中断。
        FAILED_OUT_OF_STORAGE,         ///< 失败：存储不足。
        FAILED_OUT_OF_MEMORY,          ///< 失败：内存不足。
        FAILED_OUT_OF_GRAPHICS_MEMORY  ///< 失败：显存不足。
    };

    unsigned sn;                      ///< 序列号（serial number）。
    Type     type;                    ///< 类型。
    Stage    stg = Stage::PREPARING;  ///< 阶段（stage）。
    double   stgprog = 0;             ///< 阶段进度（stage progress）。
    Status   stus = Status::WELL;     ///< 状态（status）。

    std::string path;              ///< 路径。

private:
    inline Slice(const unsigned sn, const Type type, const std::string &path)
    {
        this->sn = sn;
        this->type = type;
        this->path = path;
    }

public:
    /// \brief 未知分片。
    inline static Slice Unknown(const std::string &path)
    {
        return Slice(0, Type::UNKNOWN, path);
    }

    /// \brief 完整分片。
    inline static Slice Complete(const std::string &path)
    {
        return Slice(0, Type::COMPLETE, path);
    }

    /// \brief 索引分片。
    inline static Slice Index(const std::string &path)
    {
        return Slice(0, Type::INDEX, path);
    }

    /// \brief 片段分片。
    inline static Slice Clip(const unsigned sn, const std::string &path)
    {
        assert(0 < sn);
        return Slice(sn, Type::CLIP, path);
    }

    /// \brief 暂停。
    /// \details 为防止资源搁置，暂停将回退到上一阶段并释放相应资源，不允许执行进程暂停。
    inline void pause()
    {
        if (stus != Status::WELL)
            return;

        switch (stg) {
        case Stage::UPLOADING:   stg = Stage::READY_TO_UPLOAD;    break;
        case Stage::TRANSCODING: stg = Stage::READY_TO_TRANSCODE; break;
        case Stage::EXTRACTING:  stg = Stage::READY_TO_EXTRACT;   break;
        case Stage::DETECTING:   stg = Stage::READY_TO_DETECT;    break;
        case Stage::RECOGNIZING: stg = Stage::READY_TO_RECOGNIZE; break;
        default:                                                  break;
        }
        stgprog = 0;
        stus = Status::PAUSED;
    }

    /// \brief 恢复。
    inline void resume()
    {
        if (stus != Status::PAUSED)
            return;

        stus = Status::WELL;
    }

    /// \brief 取消。
    inline void cancel()
    {
        if (Status::FAILED_UNKNOWN <= stus)
            return;

        stus = Status::FAILED_CANCELED;
    }

    /// \brief 重试。
    inline void retry()
    {
        if (stus < Status::FAILED_UNKNOWN)
            return;

        stg = Stage::PREPARING;
        stgprog = 0;
        stus = Status::WELL;
    }
};

/// @}

}//namespace demov
}//namespace rrcxx

#endif//RRCXX_SLICE_HXX_
