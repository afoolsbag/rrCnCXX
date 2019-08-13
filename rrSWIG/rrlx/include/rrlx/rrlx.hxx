//===-- C++ Interface -------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief C++ 接口。
///
/// \sa [PImpl](https://zh.cppreference.com/w/cpp/language/pimpl)
///
/// \version 2019-07-19
/// \since 2019-05-14
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRLX_RRLX_HXX_
#define RRLX_RRLX_HXX_
#ifdef __cplusplus

#include <cstdint>
#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "api.h"

namespace rrlx {

struct version_t {
    int major;
    int minor;
    int patch;
    int tweak;
};

/// \brief 版本。
RRLX_API version_t STDCALL version();

/// \brief 类。
class clazz final {
public:
    RRLX_API explicit clazz();
    RRLX_API clazz(const clazz &) = delete;
    RRLX_API clazz &operator=(const clazz &) = delete;
    RRLX_API clazz(clazz &&) noexcept;
    RRLX_API clazz &operator=(clazz &&) noexcept;
    RRLX_API ~clazz() noexcept;

    /// \brief 基础赋值。
    RRLX_API void basic(int value);
    /// \brief 基础取值。
    [[nodiscard]] RRLX_API int basic() const;

    using array_t = std::vector<std::uint8_t>;
    /// \brief 数组赋值。
    RRLX_API void array(const array_t &value);
    /// \brief 数组取值。
    [[nodiscard]] RRLX_API const array_t &array();

    /// \brief 字串赋值。
    RRLX_API void string(const std::string &value);
    /// \brief 字串取值。
    [[nodiscard]] RRLX_API const std::string &string() const;

    using callback_t = std::function<void(void *)>;
    /// \brief 回调设置。
    RRLX_API void set_callback(const callback_t &callback, void *p_user_data);
    /// \brief 回调调用。
    RRLX_API void invoke_callback() const;

private:
    class impl;
    std::unique_ptr<impl> impl_;
};

}

#endif
#endif
