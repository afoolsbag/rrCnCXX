//===-- C++ Interface of zhengrr's Library in C++ ---------------*- C++ -*-===//
///
/// \file
/// \brief 由 C++ 编写的 zhengrr 库的 C++ 接口。
///
/// \sa [PImpl](https://zh.cppreference.com/w/cpp/language/pimpl)
///
/// \version 2021-04-16
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

/// \brief 库的命名空间。
namespace rrx {

/// \brief 版本信息结构体。
struct version_t {
    int major;
    int minor;
    int patch;
    int tweak;
};

/// \brief 获取库的版本信息。
/// \returns 返回一个存有版本信息的结构体。
RRX_API version_t STDCALL version();

/// \brief 库导出类。
/// \note 库导出类的实例不应存在副本，所以禁用其复制构造函数和复制赋值函数。
///       同时，为避免暴露内部构造，导出类仅提供必要接口，具体实现由实现类（`impl`）实现。
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

    /// \brief 回调函数类型。
    using callback_t = std::function<void(void *)>;
    /// \brief 回调设置。
    RRX_API void set_callback(const callback_t &callback, void *p_user_data);
    /// \brief 回调调用。
    RRX_API void invoke_callback() const;

private:
    /// \brief 库实现类。
    class impl;
    /// \brief 库导出类实例持有的库实现类实例。
    std::unique_ptr<impl> impl_;
};

}

#endif
#endif
