//===-- Studio --------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 工作室。
///
/// \version 2018-09-12
/// \since 2018-09-10
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_STUDIO_HXX_
#define RRCXX_STUDIO_HXX_

#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <string>

#include "Downloader.hxx"
#include "MD5.hxx"
#include "Recognizer.hxx"
#include "ServiceInterface.hxx"
#include "Transcoder.hxx"
#include "URI.hxx"
#include "UUID.hxx"

namespace rrcxx {
namespace demov {

///
/// \brief 工作室。
///
class Studio: public ServiceInterface {
public:
    /// \brief 订单。
    struct Order {
        /// \brief 物项。
        struct Item {
            /// \brief 类型。
            enum class Type {
                Remote,      ///< 远程的；
                Local,       ///< 本地的；
                Normalized,  ///< 规格化的；
                Labeled,     ///< 标签化的；
            };

            UUID              id {};        ///< 标识符。
            URL               url;          ///< 定位符。
            std::vector<UUID> precursors;   ///< 前体。
            std::vector<UUID> postcursors;  ///< 后体。

            virtual Type type() = 0;
            virtual ~Item() = default;
        };
        /// \brief 远程物项。
        struct RemoteItem: public Item {
            /// \brief 状态。
            enum class Status {
                Ready,      ///< 就绪；
                Streaming,  ///< 正在串流；
                Losing,     ///< 正在丢失（对于实时流）；
                Pausing,    ///< 正在暂停（对于存档流）；
                Ended,      ///< 结束；
                Failed,
                Failed_Cancelled,         ///< 失败：被取消；
                Failed_NotFound,          ///< 失败：未找到；
                Failed_AccessDenied,      ///< 失败：拒绝访问；
                Failed_ConnectionBroken,  ///< 失败：连接中断；
                Failed_OutOfStorage,      ///< 失败：存储不足；
            };

            std::string username;  ///< 用户名。
            std::string password;  ///< 密码。
            Status      status;    ///< 状态。
            double      progress;  ///< 进度。

            Type type() override final { return Type::Remote; }
            virtual ~RemoteItem() = default;
        };
        /// \brief 本地物项。
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

            Type type() override final { return Type::Local; }
            virtual ~LocalItem() = default;
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

            Type type() override final { return Type::Normalized; }
            virtual ~NormalizedItem() = default;
        };

        ///
        /// \brief 标签化物项。
        ///
        struct LabeledItem: public Item {
            // properties

            Type type() override final { return Type::Labeled; }
            virtual ~LabeledItem() = default;
        };
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

        UUID                                  id;     ///< 标识符。
        std::map<UUID, std::shared_ptr<Item>> items;  ///< 物项。

        bool isAllCompleted();
    };

        /// \brief 下订单。
    UUID placeOrder(const URI &rawItemUri, const std::string &username = "", const std::string &password = "");

    /// \brief 暂停订单。
    void pauseOrder(const UUID &orderId) = delete;

    /// \brief 恢复订单。
    void resumeOrder(const UUID &orderId) = delete;

    /// \brief 取消订单。
    void cancelOrder(const UUID &orderId) = delete;

    /// \brief 重试订单。
    void retryOrder(const UUID &orderId) = delete;

    /// \brief 查询订单。
    void queryOrder(const UUID &orderId);

private:
    std::map<UUID, Order> ordersInventory;  ///< 订单清单。
    std::list<UUID>       pendingList;      ///< 未完成列表。
    std::mutex            ordersMutex;      ///< 订单互斥量。

    /// \brief 线程函数。
    void threadFunction() override final;

    std::unique_ptr<Downloader> downloader {nullptr};       ///< 下载器。
    void downloaderCallback(const Downloader::Task &tast);  ///< 下载回调。

    std::unique_ptr<Transcoder> transcoder {nullptr};       ///< 转码器。
    void transcoderCallback(const Transcoder::Task &task);  ///< 转码回调。

    std::unique_ptr<Recognizer> recognizer {nullptr};       ///< 识别器。
    void recognizerCallback(const Recognizer::Task &task);  ///< 识别回调。
};

}//namespace demov
}//namespace rrcxx

#endif//RRCXX_STUDIO_HXX_
