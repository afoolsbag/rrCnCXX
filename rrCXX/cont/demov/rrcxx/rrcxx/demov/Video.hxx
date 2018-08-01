//===-- Video ---------------------------------------------------*- C++ -*-===//
///
/// \defgroup gVideo 录像
/// \ingroup gDemoV
///
/// \version 2018-08-01
/// \since 2018-07-31
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_VIDEO_HXX_
#define RRCXX_VIDEO_HXX_

#include <algorithm>
#include <map>

#include "slice.hxx"

namespace rrcxx {
namespace demov {

/// @addtogroup gVideo
/// @{

///
/// \brief 录像。
///
struct Video {
    std::string               id;      ///< 标识（identifier）。
    std::map<unsigned, Slice> slices;  ///< 分片。

private:
    inline Video(const std::string &id)
    {
        this->id = id;
    }

public:
    /// \brief 未知录像。
    inline static Video Unknown(const std::string &id, const std::string &path)
    {
        Video tmp(id);
        tmp.slices.insert(std::make_pair(0u, Slice::Unknown(path)));
        return tmp;
    }

    /// \brief 独一录像。
    inline static Video Single(const std::string &id, const std::string &path)
    {
        Video tmp(id);
        tmp.slices.insert(std::make_pair(0u, Slice::Single(path)));
        return tmp;
    }

    /// \brief 分段录像。
    inline static Video Fragmented(const std::string &id, const std::string &path)
    {
        Video tmp(id);
        tmp.slices.insert(std::make_pair(0u, Slice::Index(path)));
        return tmp;
    }

    /// \brief 是否是未知录像。
    inline bool isUnknown() const
    {
        assert(slices.count(0u));
        return Slice::Type::UNKNOWN == slices.at(0u).type;
    }

    /// \brief 是否是独一录像。
    inline bool isSingle() const
    {
        assert(slices.count(0u));
        return Slice::Type::SINGLE == slices.at(0u).type;
    }

    /// \brief 是否是分段录像。
    inline bool isFragmented() const
    {
        assert(slices.count(0u));
        return Slice::Type::INDEX == slices.at(0u).type;
    }

    /// \brief 是否含有某状态（分片）。
    template<constexpr Slice::Status STATUS>
    inline bool haveStatus() const
    {
        return std::any_of(
            slices.cbegin(),
            slices.cend(),
            [](const std::pair<unsigned, Slice> &pair) -> bool {
            return pair.second.stus == STATUS; });
    }

    /// \brief 计数某状态（分片）。
    template<constexpr Slice::Status STATUS>
    inline std::size_t countStatus() const
    {
        return std::count_if(
            slices.cbegin(),
            slices.cend(),
            [](const std::pair<unsigned, Slice> &pair) -> bool {
            return pair.second.stus == STATUS; });
    }

    /// \brief 某阶段进度。
    template<constexpr Slice::Stage STAGE>
    inline double stageProgress() const
    {
        assert(slices.size());

        double   numerator {0};
        unsigned denominator {0};

        for (const auto &pair : slices) {
            if (pair.second.stg == STAGE)
                numerator += pair.second.stgprog;
            else if (STAGE < pair.second.stg)
                ++numerator;
            ++denominator;
        }

        return numerator / denominator;
    }
    /// \brief 上传进度。
    inline double uploadProgress()    const { return stageProgress<Slice::Stage::UPLOADING>(); }
    /// \brief 转码进度。
    inline double transcodeProgress() const { return stageProgress<Slice::Stage::TRANSCODING>(); }
    /// \brief 提取进度。
    inline double extractProgress()   const { return stageProgress<Slice::Stage::EXTRACTING>(); }
    /// \brief 检测进度。
    inline double detectProgress()    const { return stageProgress<Slice::Stage::DETECTING>(); }
    /// \brief 识别进度。
    inline double recognizeProgress() const { return stageProgress<Slice::Stage::RECOGNIZING>(); }

    /// \brief 暂停。
    inline void pause()
    {
        for (auto &pair : slices) {
            pair.second.pause();
        }
    }

    /// \brief 恢复。
    inline void resume()
    {
        for (auto &pair : slices) {
            pair.second.resume();
        }
    }

    /// \brief 取消。
    inline void cancel()
    {
        for (auto &pair : slices) {
            pair.second.cancel();
        }
    }

    /// \brief 重试。
    inline void retry()
    {
        for (auto &pair : slices) {
            pair.second.retry();
        }
    }
};

/// @}

}//namespace demov
}//namespace rrcxx

#endif//RRCXX_VIDEO_HXX_
