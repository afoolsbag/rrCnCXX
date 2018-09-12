//===-- Transcoder ----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 转码器。
///
/// \version 2018-09-12
/// \since 2018-09-12
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_TRANSCODER_HXX_
#define RRCXX_TRANSCODER_HXX_

#include <functional>
#include <map>
#include <mutex>
#include <vector>

#include "MultimediaFormats.hxx"
#include "ServiceInterface.hxx"
#include "URI.hxx"
#include "UUID.hxx"

namespace rrcxx {
namespace demov {

///
/// \brief 转码器。
///
class Transcoder: public ServiceInterface {
public:
    /// \brief 任务。
    struct Task {
        /// \brief 策略。
        enum class Policy {};

        /// \brief 状态。
        enum class Status {};

        UUID             id;               ///< 标识。
//      std::vector<URI> sources;          ///< 源。
        PackageFormat    fmt;              ///< 解封装方式。
        AudioCoding      acodec;           ///< 音频解码方式。
        VideoCoding      vcodec;           ///< 视频解码方式。
//      Policy           policy;           ///< 策略。

//      Status           status;           ///< 状态。
        double           progress {0.0};   ///< 进度。

//      std::vector<URI> targets;          ///< 目标。
    };

    /// \brief 回调函数类型。
    using Callback = std::function<void(const Task &task)>;

    /// \brief 设置回调函数。
    inline void setCallback(const Callback &callback);

    /// \brief 新任务。
    UUID newTask();

    /// \brief 暂停任务。
    void pauseTask(const UUID &taskId) = delete;

    /// \brief 恢复任务。
    void resumeTask(const UUID &taskId) = delete;

    /// \brief 取消任务。
    void cancelTask(const UUID &taskId) = delete;

    /// \brief 重试任务。
    void retryTask(const UUID &taskId) = delete;

    /// \brief 查询任务。
    void queryTask(const UUID &taskId) = delete;

private:
    /// \brief 线程函数。
    void threadFunction() final;

    std::map<UUID, Task> tasksInventory;  ///< 任务清单。
    std::mutex           tasksMutex;      ///< 任务互斥量。

    /// \brief 回调函数。
    Callback callback {nullptr};

};

inline void Transcoder::setCallback(const Callback &callback)
{
    this->callback = callback;
}

}//namespace demov
}//namespace rrcxx

#endif//RRCXX_TRANSCODER_HXX_
