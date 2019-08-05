//===-- rrKafka Kafka Wrapper -----------------------------------*- C++ -*-===//
///
/// \file
///
/// \version 2019-07-30
/// \since 2019-07-30
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRKAFKA_KAFKA_HXX_
#define RRKAFKA_KAFKA_HXX_

#include <cstdint>
#include <exception>
#include <memory>
#include <optional>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#include <librdkafka/rdkafkacpp.h>

namespace rrkafka {

class exception : public std::exception {
public:
    explicit exception(RdKafka::ErrorCode code, const std::string &what_arg) :
        code_ {code},
        text_ {what_arg.empty() ? RdKafka::err2str(code) : what_arg + std::string {": "}.append(RdKafka::err2str(code))} {}
    explicit exception(RdKafka::ErrorCode code, const char *what_arg) :
        code_ {code},
        text_ {what_arg && *what_arg ? std::string {what_arg}.append(": ").append(RdKafka::err2str(code)) : RdKafka::err2str(code)} {}
    explicit exception(const std::string &what_arg) :
        code_ {RdKafka::ERR_UNKNOWN},
        text_ {what_arg} {}
    explicit exception(const char *what_arg) :
        code_ {RdKafka::ERR_UNKNOWN},
        text_ {what_arg ? what_arg : ""} {}
    [[nodiscard]] const char *what() const noexcept override { return text_.data(); }
    [[nodiscard]] RdKafka::ErrorCode code() const { return code_; }
private:
    const RdKafka::ErrorCode code_;
    const std::string text_;
};

class producer final {
public:
    /// \brief 构造
    ///
    /// \param broker_list 服务器列表，形如 `"10.0.0.1:9092, 10.0.0.2:9092"`
    /// \param topic       主题
    ///
    /// \sa [*Configuration properties*](https://github.com/edenhill/librdkafka/blob/master/CONFIGURATION.md)
    inline explicit producer(const std::string &broker_list, const std::string &topic);

    /// \brief 生产
    /// \details 异步的。
    ///
    /// \param key        键
    /// \param value_data 值数据
    /// \param value_size 值尺寸
    /// \param partition  分区
    inline void produce(const std::optional<std::string> &key, const void *value_data, std::size_t value_size, std::int32_t partition = RdKafka::Topic::PARTITION_UA);
    inline void produce(const void *value_data, std::size_t value_size, int partition = RdKafka::Topic::PARTITION_UA)
    {
        return produce(std::nullopt, value_data, value_size, partition);
    }

    inline void produce(const std::optional<std::string> &key, const std::string &value, std::int32_t partition = RdKafka::Topic::PARTITION_UA)
    {
        return produce(key, reinterpret_cast<const void *>(value.data()), static_cast<std::int64_t>(value.size() * sizeof(char)), partition);
    }
    inline void produce(const std::string &value, std::int32_t partition = RdKafka::Topic::PARTITION_UA)
    {
        return produce(std::nullopt, reinterpret_cast<const void *>(value.data()), static_cast<std::int64_t>(value.size() * sizeof(char)), partition);
    }

    inline void produce(const std::optional<std::string> &key, const std::vector<std::uint8_t> &value, std::int32_t partition = RdKafka::Topic::PARTITION_UA)
    {
        return produce(key, reinterpret_cast<const void *>(value.data()), static_cast<std::int64_t>(value.size() * sizeof(std::uint8_t)), partition);
    }
    inline void produce(const std::vector<std::uint8_t> &value, std::int32_t partition = RdKafka::Topic::PARTITION_UA)
    {
        return produce(std::nullopt, reinterpret_cast<const void *>(value.data()), static_cast<std::int64_t>(value.size() * sizeof(std::uint8_t)), partition);
    }

private:
    std::unique_ptr<RdKafka::Producer> rd_producer_ {nullptr};
    std::unique_ptr<RdKafka::Topic> rd_topic_ {nullptr};
};

class consumer final {
public:
    /// \brief 构造
    ///
    /// \param broker_list 服务器列表，形如 `"10.0.0.1:9092, 10.0.0.2:9092"`
    /// \param topic       主题
    /// \param partition   分区
    /// \param offset      偏移量
    ///
    /// \sa [*Configuration properties*](https://github.com/edenhill/librdkafka/blob/master/CONFIGURATION.md)
    inline explicit consumer(const std::string &broker_list, const std::string &topic, std::int32_t partition = 0, std::int64_t offset = 0);

    inline ~consumer() noexcept;

    /// \brief 消费
    ///
    /// \returns 消息的“偏移量－键－值”元组
    inline std::tuple<std::int64_t, std::optional<std::string>, std::vector<std::uint8_t>> consume();

private:
    std::unique_ptr<RdKafka::Consumer> rd_consumer_ {nullptr};
    std::unique_ptr<RdKafka::Topic> rd_topic_ {nullptr};
    std::int32_t partition_;
};

class kafka_consumer final {
public:
    /// \sa [*Configuration properties*](https://github.com/edenhill/librdkafka/blob/master/CONFIGURATION.md)
    inline explicit kafka_consumer(const std::string &broker_list, const std::string &topic, const std::string &group_id = "default");

    inline ~kafka_consumer() noexcept;

    /// \brief 消费
    ///
    /// \returns 消息的“键－值”对
    inline std::pair<std::optional<std::string>, std::vector<std::uint8_t>> consume();

private:
    std::unique_ptr<RdKafka::KafkaConsumer> rd_kafka_consumer_ {nullptr};
};

}

#include "kafka.inl"

#endif
