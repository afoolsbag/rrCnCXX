//===-- Double Buffer -------------------------------------------*- C++ -*-===//
///
/// \defgroup groupDoubleBuffer 双缓冲
/// \ingroup groupContainer
///
/// \version 2020-05-06
/// \since 2019-07-31
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_DOUBLE_BUFFER_HXX_
#define RRCXX_DOUBLE_BUFFER_HXX_

#include <cstddef>
#include <memory>
#include <mutex>
#include <shared_mutex>

namespace rrcxx::double_buffer {

/// \brief 数组项
/// \note  对于高性能场景，需要注意结构体的字节对齐要求
struct item_type {
    std::uint8_t uuid[16];
    float feature_vector[128];
};
constexpr std::size_t item_size {sizeof(item_type)};

class write_token;
class read_token;

/// \brief 双缓冲
/// \details
/// 1.  最初两个缓冲都在后台（back stage）；\n
///     此时写令牌（write token）可申领，读令牌（read token）不可申领。
/// 2.  用户首次申领写令牌，写令牌自动与任意一个缓冲绑定；\n
///     用户在缓冲中准备好数据，然后调用写令牌的“待用”函数（stand by），告知写令牌缓冲准备完毕；\n
///     用户交还写令牌，写令牌依据“待用”状态，自动将该缓冲切换到前台（front stage）；\n
///     此时有缓冲在前台，也有缓冲在后台，读令牌和写令牌都可申领。
/// 3.  用户再次申领写令牌，写令牌与后台缓冲绑定；\n
///     ……\n
///     用户交还写令牌，写令牌依据“待用”状态，自动将前、后台缓冲切换；\n
///     ……
/// 4.  后台缓冲可以申领写令牌，写令牌与其它令牌冲突，同缓冲同时只允许存在一个；\n
///     前台缓冲可以申领读令牌，读令牌之间不冲突，同缓冲同时可以存在多个；\n
///     缓冲切换后，刚刚切换的后台缓冲可能仍然存在写令牌，此时读令牌的申领将等待。
class double_buffer final {
public:
    friend class write_token;
    friend class read_token;

public:
    explicit double_buffer(std::size_t item_max);
    explicit double_buffer(const double_buffer &) = delete;
    double_buffer &operator=(const double_buffer &) = delete;
    explicit double_buffer(double_buffer &&) noexcept = delete;
    double_buffer &operator=(double_buffer &&) noexcept = delete;
    ~double_buffer() noexcept;

    [[nodiscard]] std::size_t item_max() const noexcept { return item_max_; }
    [[nodiscard]] std::size_t buffer_size() const noexcept { return item_max_ * item_size; }

    /// \brief 获取写令牌。
    /// \details 同缓冲同时最多只允许存在一个写令牌。
    [[nodiscard]] write_token get_write_token();

    /// \brief 获取读令牌。
    [[nodiscard]] read_token get_read_token();

private:
    const std::size_t item_max_;

    std::unique_ptr<item_type, void(*)(item_type *)> left_buf_;
    std::size_t left_cnt_ {0};
    std::shared_mutex left_mtx_;

    std::unique_ptr<item_type, void(*)(item_type *)> right_buf_;
    std::size_t right_cnt_ {0};
    std::shared_mutex right_mtx_;

    /// \brief 状态
    enum status_t {
        uu, // left unavailable right unavailable
        au, // left available right unavailable
        ua, // left unavailable right available
        de, // destructing
        sw, // auto switch
    };
    status_t stat_ {uu};
    std::mutex stat_write_mtx_;
    void change_status(status_t target = sw) noexcept;
};

/// \brief 写令牌。
class write_token {
public:
    friend double_buffer;

private:
    explicit write_token(item_type *buffer, std::size_t &item_count, double_buffer &owner, std::unique_lock<std::shared_mutex> &&lk) :
        buffer {buffer},
        item_count {item_count},
        owner_ {owner},
        lk_ {move(lk)}
    {}
public:
    explicit write_token(const write_token &) = delete;
    write_token &operator=(const write_token &) = delete;
    explicit write_token(write_token &&) noexcept = default;
    write_token &operator=(write_token &&rhv) noexcept = default;

    bool stand_by_ {false};
    void stand_by(bool to_be = true) { stand_by_ = to_be; }
    ~write_token() noexcept { if (stand_by_) owner_.change_status(); }

    [[nodiscard]] std::size_t item_max() const noexcept { return owner_.item_max(); }
    [[nodiscard]] std::size_t buffer_size() const noexcept { return owner_.buffer_size(); }

    item_type *const buffer;
    std::size_t &item_count;

private:
    double_buffer &owner_;
    std::unique_lock<std::shared_mutex> lk_;
};

/// \brief 读令牌
class read_token {
public:
    friend double_buffer;

private:
    explicit read_token(const item_type *buffer, std::size_t item_count, std::shared_lock<std::shared_mutex> &&lk) :
        buffer {buffer}, item_count {item_count}, lk_ {move(lk)} {}
public:
    explicit read_token(const read_token &) = delete;
    read_token &operator=(const read_token &) = delete;
    explicit read_token(read_token &&other) noexcept = default;
    read_token &operator=(read_token &&rhv) noexcept = default;
    ~read_token() noexcept = default;

    const item_type *const buffer;
    const std::size_t item_count;

private:
    std::shared_lock<std::shared_mutex> lk_;
};

}

#endif
