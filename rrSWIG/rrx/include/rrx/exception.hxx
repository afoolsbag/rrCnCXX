//===-- Exception -----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 异常类。
///
/// \version 2020-06-03
/// \since 2019-05-14
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRX_EXCEPTION_HXX_
#define RRX_EXCEPTION_HXX_
#ifdef __cplusplus

#include <exception>
#include <string>

namespace rrx {

/// \brief 内部异常（基异常）。
class internal_exception : public std::exception {
public:
    explicit internal_exception(const char *message)
        : message_ {message ? message : ""}
    {}
    [[nodiscard]] const char *what() const noexcept override { return message_.data(); }
private:
    std::string message_;
};

}

#endif
#endif
