//===-- Video ---------------------------------------------------*- C++ -*-===//
///
/// \defgroup gVideo 录像
/// \ingroup gDemoV
///
/// \version 2018-08-17
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
#include <mutex>

#include "Slice.hxx"

namespace rrcxx {
namespace demov {

/// @addtogroup gVideo
/// @{

///
/// \brief 录像。
///
struct Video {
    std::string               identifier;  ///< 标识。
    std::map<unsigned, Slice> slices;      ///< 分片。
    std::mutex                writeMutex;  ///< 写互斥量。

    /// \brief 构造函数。
    inline Video(const std::string &identifier, const std::string &path)
    {
        this->identifier = identifier;
        this->slices.insert(std::make_pair(0u, Slice::Original(path)));
    }

    /// \brief 是否包含某状态分片。
    inline bool containsSlices(const Slice::Status status) const
    {
        return std::any_of(slices.cbegin(), slices.cend(), [&](const std::pair<unsigned, Slice> &pair) -> bool {
            return pair.second.status == status;
        });
    }

    /// \brief 是否包含某阶段分片。
    inline bool containsSlices(const Slice::Stage stage) const
    {
        return std::any_of(slices.cbegin(), slices.cend(), [&](const std::pair<unsigned, Slice> &pair) -> bool {
            return pair.second.stage == stage;
        });
    }

    /// \brief 计数某状态分片。
    inline std::size_t countSlices(const Slice::Status statuc) const
    {
        return std::count_if(slices.cbegin(), slices.cend(), [&](const std::pair<unsigned, Slice> &pair) -> bool {
            return pair.second.status == statuc;
        });
    }

    /// \brief 计数某阶段分片。
    inline std::size_t countSlices(const Slice::Stage stage) const
    {
        return std::count_if(slices.cbegin(), slices.cend(), [&](const std::pair<unsigned, Slice> &pair) -> bool {
            return pair.second.stage == stage;
        });
    }

    /// \brief 是否仅包含某状态分片。
    inline bool onlyContainsSlices(const Slice::Status status) const
    {
        return std::all_of(slices.cbegin(), slices.cend(), [&](const std::pair<unsigned, Slice> &pair) -> bool {
            return pair.second.status == status;
        });
    }

    /// \brief 是否仅包含某阶段分片。
    inline bool onlyContainsSlices(const Slice::Stage stage) const
    {
        return std::all_of(slices.cbegin(), slices.cend(), [&](const std::pair<unsigned, Slice> &pair) -> bool {
            return pair.second.stage == stage;
        });
    }

    /// \brief 某阶段进度。
    inline double stageProgress(const Slice::Stage stage) const
    {
        assert(!slices.empty());
        double   numerator {0};
        unsigned denominator {0};
        for (const auto &pair : slices) {
            if (pair.second.stage == stage)
                numerator += pair.second.stageProgress;
            else if (stage < pair.second.stage)
                numerator++;
            denominator++;
        }
        return numerator / denominator;
    }

    /// \brief 获取一个可用分片序列号。
    inline std::pair<bool, unsigned> getAnAvailableSliceSerialNumber(const Slice::Status status, const Slice::Stage stage) const
    {
        for (const auto &pair : slices)
        {
            if (pair.second.status == status && pair.second.stage == stage)
                return std::make_pair(true, pair.second.serialNumber);
        }
        return std::make_pair(false, 0);
    }

    /// \brief 暂停。
    inline void pause()
    {
        std::lock_guard<std::mutex> lockGuard(writeMutex);
        for (auto &pair : slices) {
            pair.second.tryPause();
        }
    }

    /// \brief 恢复。
    inline void resume()
    {
        std::lock_guard<std::mutex> lockGuard(writeMutex);
        for (auto &pair : slices) {
            pair.second.tryResume();
        }
    }

    /// \brief 取消。
    inline void cancel()
    {
        std::lock_guard<std::mutex> lockGuard(writeMutex);
        for (auto &pair : slices) {
            pair.second.tryFail(Slice::Status::FAILED_CANCELED);
        }
    }

    /// \brief 重试。
    inline void retry()
    {
        std::lock_guard<std::mutex> lockGuard(writeMutex);
        for (auto &pair : slices) {
            pair.second.tryRetry();
        }
    }
};

/// @}

}//namespace demov
}//namespace rrcxx

#endif//RRCXX_VIDEO_HXX_
