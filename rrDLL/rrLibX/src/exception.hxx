//===-- Exception -----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 异常类。
///
/// \version 2019-06-20
/// \since 2019-05-14
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRLIBX_EXECEPTION_HXX_
#define RRLIBX_EXECEPTION_HXX_

#include <exception>
#include <stdexcept>
#include <thread>

#include "rrlibx/rrlibx.h"

namespace rrlibx {

using status = rrlibx_status_t;  ///< 状态码

/// \brief 状态码包装异常。
class exception final : public std::exception {
public:
    explicit exception(status status) : status_ {status} {}
    [[nodiscard]] status status() const { return status_; }
private:
    rrlibx::status status_;
};

}

/// \def RRDLLX_EXCEPTION_TO_STATUS_TRY
/// \def RRDLLX_EXCEPTION_TO_STATUS_CATCH_ALL
/// \brief 异常转状态码
#define RRDLLX_EXCEPTION_TO_STATUS_TRY                                         \
    try {
#define RRDLLX_EXCEPTION_TO_STATUS_CATCH_ALL                                   \
    } catch (const rrlibx::exception &e) {                                     \
        return e.status();                                                     \
    } catch (const std::invalid_argument &) {                                  \
        return rrlibx_invalid_argument;                                        \
    } catch (const std::domain_error &) {                                      \
        return rrlibx_domain_error;                                            \
    } catch (const std::length_error &) {                                      \
        return rrlibx_length_error;                                            \
    } catch (const std::out_of_range &) {                                      \
        return rrlibx_out_of_range;                                            \
    } catch (const std::logic_error &) {                                       \
        return rrlibx_logic_error;                                             \
    } catch (const std::range_error &) {                                       \
        return rrlibx_range_error;                                             \
    } catch (const std::overflow_error &) {                                    \
        return rrlibx_overflow_error;                                          \
    } catch (const std::underflow_error &) {                                   \
        return rrlibx_underflow_error;                                         \
    } catch (const std::runtime_error &) {                                     \
        return rrlibx_runtime_error;                                           \
    } catch (const std::bad_typeid &) {                                        \
        return rrlibx_bad_typeid;                                              \
    } catch (const std::bad_cast &) {                                          \
        return rrlibx_bad_cast;                                                \
    } catch (const std::bad_alloc &) {                                         \
        return rrlibx_bad_alloc;                                               \
    } catch (const std::bad_exception &) {                                     \
        return rrlibx_bad_exception;                                           \
    } catch (const std::exception &) {                                         \
        return rrlibx_exception;                                               \
    } catch (...) {                                                            \
        return rrlibx_unexpected_exception;                                    \
    }

#endif
