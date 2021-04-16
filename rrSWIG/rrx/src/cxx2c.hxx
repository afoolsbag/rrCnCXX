//===-- C++ To C ------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief C++ 转换 C 工具。
///
/// \version 2021-04-16
/// \since 2019-05-14
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRX_CXX2C_HXX_
#define RRX_CXX2C_HXX_

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <thread>

#include "rrx/rrx.h"
#include "rrx/rrx.hxx"
#include "rrx/status.h"

namespace rrx {
 
/// \brief 将 C++ 导出类的实例（`clazz`）转换为 C 句柄（`handle`）的包装类。
/// \details 该包装类的实例持有导出类的实例，以及……
class clazz2handle final {
public:
    /// \brief 请求分配一个包装类的实例。
    /// \returns 返回该包装类实例的 C 句柄。
    static rrx_handle_t alloc();

    /// \brief 请求销毁一个包装类的实例。
    /// \param h 该包装类实例对应的 C 导出句柄。
    static void free(rrx_handle_t h);

    /// \brief 通过
    static clazz2handle &ref(rrx_handle_t h);
private:
    /// \brief 包装持有者。
    /// \details 持有所有“C 导出句柄、C++ 包装实例”键值对的静态变量，并管理 C++ 包装实例的生存期。
    static std::unordered_map<rrx_handle_t, std::unique_ptr<clazz2handle>> wrappers_owner_;

public:
    /// \brief 重载 `->` 操作符，以便于快速访问其持有的导出类实例。
    clazz *operator->() { return &content; }

    void last_error_message(const std::string &value);
    [[nodiscard]] const std::string &last_error_message();
private:
    /// \brief 持有的导出类的实例。
    clazz content;
    std::unordered_map<std::thread::id, std::string> last_error_message_;
};
inline clazz2handle &ref(rrx_handle_t handle) { return clazz2handle::ref(handle); }

/// \brief 异常转错误码包装函数。
rrx_status_t exception2status(rrx_handle_t handle, const std::function<rrx_status_t()> &lambda) noexcept;
inline rrx_status_t exception2status(const std::function<rrx_status_t()> &lambda) noexcept { return exception2status(nullptr, lambda); }

}

#endif