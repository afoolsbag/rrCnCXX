//===-- Wrapper -------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 包装类。
///
/// \version 2019-07-19
/// \since 2019-05-14
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRLX_WRAPPER_HXX_
#define RRLX_WRAPPER_HXX_

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <thread>

#include "rrlx/rrlx.h"
#include "rrlx/rrlx.hxx"
#include "rrlx/status.h"

namespace rrlx {

/// \brief 包装类。
class wrapper final {
public:
    static rrlx_handle_t alloc();
    static void free(rrlx_handle_t h);
    static wrapper &ref(rrlx_handle_t h);
private:
    static std::unordered_map<rrlx_handle_t, std::unique_ptr<wrapper>> wrapper_owner_;

public:
    clazz content;
    clazz *operator->();

    void last_error_message(const std::string &value);
    void last_error_message(std::string &&value);
    [[nodiscard]] const std::string &last_error_message();
private:
    std::unordered_map<std::thread::id, std::string> last_error_message_;
};

inline wrapper &ref(rrlx_handle_t handle) { return wrapper::ref(handle); }

rrlx_status_t exception_to_status(std::function<rrlx_status_t()> &&lambda) noexcept;
rrlx_status_t exception_to_status(rrlx_handle_t handle, std::function<rrlx_status_t()> &&lambda) noexcept;

}

#endif