//===-- C++ To C ------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief C++ 转换 C 工具。
///
/// \version 2020-06-03
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

/// \brief `clazz` 转 `handle` 包装类。
class clazz2handle final {
public:
    static rrx_handle_t alloc();
    static void free(rrx_handle_t h);
    static clazz2handle &ref(rrx_handle_t h);
private:
    static std::unordered_map<rrx_handle_t, std::unique_ptr<clazz2handle>> wrappers_owner_;

public:
    clazz content;
    clazz *operator->();

    void last_error_message(const std::string &value);
    [[nodiscard]] const std::string &last_error_message();
private:
    std::unordered_map<std::thread::id, std::string> last_error_message_;
};
inline clazz2handle &ref(rrx_handle_t handle) { return clazz2handle::ref(handle); }

/// \brief 异常转错误码包装函数。
rrx_status_t exception2status(rrx_handle_t handle, const std::function<rrx_status_t()> &lambda) noexcept;
inline rrx_status_t exception2status(const std::function<rrx_status_t()> &lambda) noexcept { return exception2status(nullptr, lambda); }

}

#endif