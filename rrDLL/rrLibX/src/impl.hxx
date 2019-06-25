//===-- Implement -----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief rrLibX 的 C++ 实现。
///
/// \version 2019-06-20
/// \since 2019-05-14
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRDLLX_IMPL_HXX_
#define RRDLLX_IMPL_HXX_

#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include <thread>

#include "exception.hxx"

namespace rrlibx {

using handle = rrlibx_handle_t;  ///< 实例句柄

class impl final {
public:
    static handle alloc();
    static void free(handle h);
    static impl &ref(handle h);
private:
    static std::unordered_map<handle, std::unique_ptr<impl>> instances_owner_;
    explicit impl() = default;

public:
    int basic {};
    std::vector<std::uint8_t> array;
    std::string string;
    void last_internal_error_message(const std::string &val);
    [[nodiscard]] const std::string &last_internal_error_message();
private:
    std::unordered_map<std::thread::id, std::string> last_internal_error_message_;
};

inline impl &implref(handle h) { return impl::ref(h); }

}

#endif
