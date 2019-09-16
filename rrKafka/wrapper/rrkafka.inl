/// \copyright Unlicense

#pragma once
#ifndef RRKAFKA_KAFKA_INL_
#define RRKAFKA_KAFKA_INL_

#include "rrkafka.hxx"

#include <cassert>

namespace rrkafka {

inline producer::producer(const std::string &broker_list, const std::string &topic)
{
    using namespace std;

    string errstr;

    // -------------------------------------------------------------------------
    // PRODUCER

    unique_ptr<RdKafka::Conf> gcfg {RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL)};
    if (!gcfg)
        throw exception {"RdKafka::Conf::create(*) failed"};

    // metadata.broker.list
    // Initial list of brokers as a CSV list of broker host or host:port. The application may also use rd_kafka_brokers_add() to add brokers during runtime.
    // Type: string
    if (gcfg->set("metadata.broker.list", broker_list, errstr) != RdKafka::Conf::CONF_OK)
        throw exception {"RdKafka::Conf::set(*) failed: "s.append(errstr)};

    rd_producer_.reset(RdKafka::Producer::create(gcfg.get(), errstr));
    if (!rd_producer_)
        throw exception {"RdKafka::Producer::create(*) failed: "s.append(errstr)};

    gcfg.reset();

    // -------------------------------------------------------------------------
    // TOPIC

    unique_ptr<RdKafka::Conf> tcfg {RdKafka::Conf::create(RdKafka::Conf::CONF_TOPIC)};
    if (!tcfg)
        throw exception {"RdKafka::Conf::create(*) failed"};

    rd_topic_.reset(RdKafka::Topic::create(rd_producer_.get(), topic, tcfg.get(), errstr));
    if (!rd_topic_)
        throw exception {"RdKafka::Topic::create(*) failed: "s.append(errstr)};
}

inline void producer::produce(const std::optional<std::string> &key, const void *value_data, std::size_t value_size, std::int32_t partition)
{
    using namespace std;

    assert(rd_producer_);
    assert(rd_topic_);

    const auto ec = rd_producer_->produce(rd_topic_.get(),
                                          partition,
                                          RdKafka::Producer::RK_MSG_COPY,
                                          const_cast<void *>(value_data),
                                          value_size,
                                          key.has_value() ? &key.value() : nullptr,
                                          nullptr);

    // 轮询事件以触发回调
    rd_producer_->poll(100);

    if (ec != RdKafka::ERR_NO_ERROR)
        throw exception {ec, "RdKafka::Producer::produce(*) failed"};

}

inline consumer::consumer(const std::string &broker_list, const std::string &topic, std::int32_t partition, std::int64_t offset) :
    partition_ {partition}
{
    using namespace std;

    string errstr;

    // -------------------------------------------------------------------------
    // CONSUMER

    unique_ptr<RdKafka::Conf> gcfg {RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL)};
    if (!gcfg)
        throw exception {"RdKafka::Conf::create(*) failed"};

    // metadata.broker.list
    // Initial list of brokers as a CSV list of broker host or host:port. The application may also use rd_kafka_brokers_add() to add brokers during runtime.
    // Type: string
    if (gcfg->set("metadata.broker.list", broker_list, errstr) != RdKafka::Conf::CONF_OK)
        throw exception {"RdKafka::Conf::set(*) failed: "s.append(errstr)};

    rd_consumer_.reset(RdKafka::Consumer::create(gcfg.get(), errstr));
    if (!rd_consumer_)
        throw exception {"RdKafka::Consumer::create(*) failed: "s.append(errstr)};

    // -------------------------------------------------------------------------
    // TOPIC

    unique_ptr<RdKafka::Conf> tcfg {RdKafka::Conf::create(RdKafka::Conf::CONF_TOPIC)};
    if (!tcfg)
        throw exception {"RdKafka::Conf::create(*) failed"};

    rd_topic_.reset(RdKafka::Topic::create(rd_consumer_.get(), topic, tcfg.get(), errstr));
    if (!rd_topic_)
        throw exception {"RdKafka::Topic::create(*) failed: "s.append(errstr)};

    // -------------------------------------------------------------------------

    const auto ec = rd_consumer_->start(rd_topic_.get(), partition_, offset);
    if (ec != RdKafka::ERR_NO_ERROR)
        throw exception {ec, "RdKafka::Consumer::start(*) failed"};
}

inline consumer::~consumer() noexcept
{
    rd_consumer_->stop(rd_topic_.get(), partition_);

    // 轮询事件以触发回调
    rd_consumer_->poll(100);
}

inline std::tuple<std::int64_t, std::optional<std::string>, std::vector<std::uint8_t>> consumer::consume(int timeout_ms)
{
    using namespace std;

    assert(rd_consumer_);
    assert(rd_topic_);

    const unique_ptr<RdKafka::Message> message {rd_consumer_->consume(rd_topic_.get(), partition_, timeout_ms)};

    // 轮询事件以触发回调
    rd_consumer_->poll(100);

    if (!message)
        throw exception {"RdKafka::Consumer::consume(*) failed"};
    if (message->err() != RdKafka::ERR_NO_ERROR)
        throw exception {message->err(), "RdKafka::Consumer::consume(*) failed"};

    return make_tuple<int64_t, optional<string>, vector<uint8_t>>(
        message->offset(),
        message->key() ? optional {*message->key()} : nullopt,
        {reinterpret_cast<uint8_t *>(message->payload()), reinterpret_cast<uint8_t *>(message->payload()) + message->len()}
    );
}

inline kafka_consumer::kafka_consumer(const std::string &broker_list, const std::string &topic, const std::string &group_id)
{
    using namespace std;

    string errstr;

    // -------------------------------------------------------------------------
    // DEFAULT TOPIC

    unique_ptr<RdKafka::Conf> tcfg {RdKafka::Conf::create(RdKafka::Conf::CONF_TOPIC)};
    if (!tcfg)
        throw exception {"RdKafka::Conf::create(*) failed"};

    // auto.offset.reset
    // Action to take when there is no initial offset in offset store or the desired offset is out of range: 'smallest','earliest' - automatically reset the offset to the smallest offset, 'largest','latest' - automatically reset the offset to the largest offset, 'error' - trigger an error which is retrieved by consuming messages and checking 'message->err'.
    // Type: enum value
    if (tcfg->set("auto.offset.reset", "earliest", errstr) != RdKafka::Conf::CONF_OK)
        throw exception {"RdKafka::Conf::set(*) failed: "s.append(errstr)};

    // -------------------------------------------------------------------------
    // KAFKA CONSUMER

    unique_ptr<RdKafka::Conf> gcfg {RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL)};
    if (!gcfg)
        throw exception {"RdKafka::Conf::create(*) failed"};

    // metadata.broker.list
    // Initial list of brokers as a CSV list of broker host or host:port. The application may also use rd_kafka_brokers_add() to add brokers during runtime.
    // Type: string
    if (gcfg->set("metadata.broker.list", broker_list, errstr) != RdKafka::Conf::CONF_OK)
        throw exception {"RdKafka::Conf::set(*) failed: "s.append(errstr)};

    // default_topic_conf
    // Default topic configuration for automatically subscribed topics.
    // Type: pointer
    if (gcfg->set("default_topic_conf", tcfg.get(), errstr) != RdKafka::Conf::CONF_OK)
        throw exception {"RdKafka::Conf::set(*) failed: "s.append(errstr)};

    // group.id
    // Client group id string. All clients sharing the same group.id belong to the same group.
    // Type: string
    if (gcfg->set("group.id", group_id, errstr) != RdKafka::Conf::CONF_OK)
        throw exception {"RdKafka::Conf::set(*) failed: "s.append(errstr)};

    // enable.partition.eof
    // Emit RD_KAFKA_RESP_ERR__PARTITION_EOF event whenever the consumer reaches the end of a partition.
    // Type: boolean
    if (gcfg->set("enable.partition.eof", "false", errstr) != RdKafka::Conf::CONF_OK)
        throw exception {"RdKafka::Conf::set(*) failed: "s.append(errstr)};

    rd_kafka_consumer_.reset(RdKafka::KafkaConsumer::create(gcfg.get(), errstr));
    if (!rd_kafka_consumer_)
        throw exception {"RdKafka::KafkaConsumer::create(*) failed: "s.append(errstr)};

    vector<string> topics;
    topics.push_back(topic);
    rd_kafka_consumer_->subscribe(topics);
}

inline kafka_consumer::~kafka_consumer() noexcept
{
    rd_kafka_consumer_->close();
}

inline std::pair<std::optional<std::string>, std::vector<std::uint8_t>> kafka_consumer::consume(int timeout_ms)
{
    using namespace std;

    assert(rd_kafka_consumer_);

    const unique_ptr<RdKafka::Message> message {rd_kafka_consumer_->consume(timeout_ms)};

    if (!message)
        throw exception {"RdKafka::KafkaConsumer::consume(*) failed"};
    if (message->err() != RdKafka::ERR_NO_ERROR)
        throw exception {message->err(), "RdKafka::KafkaConsumer::consume(*) failed"};

    const auto ec = rd_kafka_consumer_->commitSync(message.get());
    if (ec != RdKafka::ERR_NO_ERROR)
        throw exception {ec, "RdKafka::KafkaConsumer::commitSync(*) failed"};

    return make_pair<std::optional<std::string>, std::vector<std::uint8_t>>(
        message->key() ? optional {*message->key()} : nullopt,
        {reinterpret_cast<uint8_t *>(message->payload()), reinterpret_cast<uint8_t *>(message->payload()) + message->len()}
    );
}

}

#endif
