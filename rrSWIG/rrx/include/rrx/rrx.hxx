//===-- C++ Interface -------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief C++ 接口。
///
/// \sa [PImpl](https://zh.cppreference.com/w/cpp/language/pimpl)
///
/// \version 2020-06-03
/// \since 2019-05-14
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRX_RRX_HXX_
#define RRX_RRX_HXX_
#ifdef __cplusplus

#include <cstdint>
#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "api.h"

namespace rrx {

struct version_t {
    int major;
    int minor;
    int patch;
    int tweak;
};

/// \brief 版本。
RRX_API version_t STDCALL version();

/// \brief 类。
class clazz final {
public:
    RRX_API explicit clazz();
    RRX_API clazz(const clazz &) = delete;
    RRX_API clazz &operator=(const clazz &) = delete;
    RRX_API clazz(clazz &&) noexcept;
    RRX_API clazz &operator=(clazz &&) noexcept;
    RRX_API ~clazz() noexcept;

    /// \brief 基础赋值。
    RRX_API void basic(int value);
    /// \brief 基础取值。
    [[nodiscard]] RRX_API int basic() const;

    using array_t = std::vector<std::uint8_t>;
    /// \brief 数组赋值。
    RRX_API void array(const array_t &value);
    /// \brief 数组取值。
    [[nodiscard]] RRX_API const array_t &array() const;

    /// \brief 字串赋值。
    RRX_API void string(const std::string &value);
    /// \brief 字串取值。
    [[nodiscard]] RRX_API const std::string &string() const;

    using callback_t = std::function<void(void *)>;
    /// \brief 回调设置。
    RRX_API void set_callback(const callback_t &callback, void *p_user_data);
    /// \brief 回调调用。
    RRX_API void invoke_callback() const;

private:
    class impl;
    std::unique_ptr<impl> impl_;
};

}

#endif
#endif
