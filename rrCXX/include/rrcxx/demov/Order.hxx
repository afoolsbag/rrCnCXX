//===-- Order ---------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 订单。
///
/// \version 2018-09-10
/// \since 2018-09-10
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_ORDER_HXX_
#define RRCXX_ORDER_HXX_

#include <map>
#include <memory>

#include "Item.hxx"
#include "URI.hxx"
#include "UUID.hxx"

namespace rrcxx {
namespace demov {

///
/// \brief 订单。
///
struct Order {
    /// \brief 上传状态。
    enum class UploadStatus {
        NotYetUpload,   ///< 尚未上传；
        HaveUploading,  ///< 正在上传；
        UploadWaiting,  ///< 上传等待；
        AllUploaded,    ///< 上传完毕；
        HaveFailed,     ///< 上传失败；
    };

    /// \brief 转码状态。
    enum class TranscodeStatus {
        NotYetTranscode,            ///< 尚未转码；

        HaveTranscoding,            ///< 正在转码；
        TranscodeWaiting,           ///< 转码等待；
        AllTranscoded,              ///< 转码完毕；

        HaveTranscodingForced,      ///< 正在强制转码；
        TranscodeForcedWaiting,     ///< 强制转码等待；
        AllTranscodedForced,        ///< 强制转码完毕；

        HaveTranscodingTraversed,   ///< 正在遍历转码；
        TranscodeTraversedWaiting,  ///< 遍历转码等待；
        AllTranscodedTraversed,     ///< 遍历转码完毕；

        HaveFailed,                 ///< 转码失败；
        Incompetent,                ///< 不可转码；
    };

    /// \brief 识别状态。
    enum class RecognizeStatus {
        NotYetRecognize,   ///< 尚未识别；
        HaveRecognizing,   ///< 正在识别；
        RecognizeWaiting,  ///< 识别等待；
        AllRecognized,     ///< 识别完毕；
        HaveFailed,        ///< 识别失败；
    };

    bool paused;  ///< 暂停的。

    UUID                                  uuid;   ///< 标识符。
    std::map<UUID, std::shared_ptr<Item>> items;  ///< 物项。
};

}//namespace demov
}//namespace rrcxx

#endif//RRCXX_ORDER_HXX_
