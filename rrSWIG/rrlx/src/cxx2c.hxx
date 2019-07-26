//===-- C++ To C ------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief C++ 转换 C 工具。
///
/// \version 2019-07-26
/// \since 2019-05-14
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRLX_CXX2C_HXX_
#define RRLX_CXX2C_HXX_

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <thread>

#include "rrlx/rrlx.h"
#include "rrlx/rrlx.hxx"
#include "rrlx/status.h"

namespace rrlx {

/// \brief `clazz` 转 `handle` 包装类。
class clazz2handle final {
public:
    static rrlx_handle_t alloc();
    static void free(rrlx_handle_t h);
    static clazz2handle &ref(rrlx_handle_t h);
private:
    static std::unordered_map<rrlx_handle_t, std::unique_ptr<clazz2handle>> wrappers_owner_;

public:
    clazz content;
    clazz *operator->();

    void last_error_message(const std::string &value);
    [[nodiscard]] const std::string &last_error_message();
private:
    std::unordered_map<std::thread::id, std::string> last_error_message_;
};
inline clazz2handle &ref(rrlx_handle_t handle) { return clazz2handle::ref(handle); }

/// \brief 异常转错误码包装函数。
rrlx_status_t exception2status(rrlx_handle_t handle, const std::function<rrlx_status_t()> &lambda) noexcept;
inline rrlx_status_t exception2status(const std::function<rrlx_status_t()> &lambda) noexcept { return exception2status(nullptr, lambda); }

}

#endif