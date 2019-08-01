//===-- Double Huge Buffer --------------------------------------*- C++ -*-===//
///
/// \defgroup gDoubleHugeBuffer 双－巨－缓冲
/// \ingroup gContainer
///
/// \version 2019-07-31
/// \since 2019-07-31
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_DOUBLE_HUGE_BUFFER_HXX_
#define RRCXX_DOUBLE_HUGE_BUFFER_HXX_

#include <cstddef>
#include <memory>
#include <mutex>
#include <shared_mutex>

namespace rrcxx::double_huge_buffer {

/// \brief 数组项
/// \note  对于高性能场景，需要注意结构体的字节对齐要求
struct item_type {
    std::uint8_t uuid[16];
    float feature_vector[128];
};
constexpr std::size_t item_size {sizeof(item_type)};

class write_reference;
class read_reference;

/// \brief 双－巨－缓冲
class double_huge_buffer final {
public:
    friend class write_reference;
    friend class read_reference;

public:
    explicit double_huge_buffer(std::size_t item_max_count);
    explicit double_huge_buffer(const double_huge_buffer &) = delete;
    double_huge_buffer &operator=(const double_huge_buffer &) = delete;
    explicit double_huge_buffer(double_huge_buffer &&) noexcept = delete;
    double_huge_buffer &operator=(double_huge_buffer &&) noexcept = delete;
    ~double_huge_buffer() noexcept;

    const std::size_t item_max_count;
    [[nodiscard]] std::size_t buffer_size() const noexcept { return item_max_count * item_size; }

private:
    std::unique_ptr<item_type, void(*)(item_type *)> lbuf_;
    std::shared_mutex lmtx_;
    std::size_t lcnt_ {};
    std::unique_ptr<item_type, void(*)(item_type *)> rbuf_;
    std::shared_mutex rmtx_;
    std::size_t rcnt_ {};

    enum { both_unavailable, available_unavailable, unavailable_available } available_ {both_unavailable};  ///< 可用标志。
    bool destructing_ {false};  ///< 析构标志，仅在析构开始时设置为真。若为真则不应再派出引用，待收回所有引用后，销毁缓冲。

public:
    /// \brief 获取写引用，同一缓冲、同一时间至多只允许存在一个写引用实例。
    [[nodiscard]] write_reference &&get_reference_for_write_buffer();

    /// \brief 获取读引用。
    [[nodiscard]] read_reference &&get_reference_for_read_buffer();
};

/// \brief 写引用
class write_reference {
public:
    friend double_huge_buffer;

private:
    explicit write_reference(item_type *buffer, std::size_t item_count, double_huge_buffer &owner, std::unique_lock<std::shared_mutex> &&lk) :
        item_max_count {owner.item_max_count},
        buffer {buffer},
        item_count {item_count},
        owner_ {owner},
        lk_ {move(lk)}
    {}
public:
    explicit write_reference(const write_reference &) = delete;
    write_reference &operator=(const write_reference &) = delete;
    explicit write_reference(write_reference &&) noexcept = default;
    write_reference &operator=(write_reference &&rhv) noexcept = default;
    ~write_reference() noexcept;

    const std::size_t item_max_count;
    [[nodiscard]] std::size_t buffer_size() const noexcept { return item_max_count * item_size; }

    item_type *const buffer;
    std::size_t item_count;

private:
    double_huge_buffer &owner_;
    std::unique_lock<std::shared_mutex> lk_;
};

/// \brief 读引用
class read_reference {
public:
    friend double_huge_buffer;

private:
    explicit read_reference(const item_type *buffer, std::size_t item_count, std::shared_lock<std::shared_mutex> &&lk) :
        buffer {buffer}, item_count {item_count}, lk_ {move(lk)} {}
public:
    explicit read_reference(const read_reference &) = delete;
    read_reference &operator=(const read_reference &) = delete;
    explicit read_reference(read_reference &&other) noexcept = default;
    read_reference &operator=(read_reference &&rhv) noexcept = default;
    ~read_reference() noexcept = default;

    const item_type *const buffer;
    const std::size_t item_count;

private:
    std::shared_lock<std::shared_mutex> lk_;
};

}

#endif
