//===-- Exception -----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 异常类。
///
/// \version 2019-07-18
/// \since 2019-05-14
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRLX_EXECEPTION_HXX_
#define RRLX_EXECEPTION_HXX_

#include <exception>
#include <stdexcept>
#include <thread>

#include "rrlx/rrlx.h"

namespace rrlx {

using status = rrlx_status_t;  ///< 状态码

/// \brief 状态码包装异常。
class exception final : public std::exception {
public:
    explicit exception(rrlx::status status) : status_ {status} {}
    [[nodiscard]] rrlx::status status() const { return status_; }
private:
    rrlx::status status_;
};

}

/// \def RRLX_EXCEPTION_TO_STATUS_TRY
/// \def RRLX_EXCEPTION_TO_STATUS_CATCH_ALL
/// \brief 异常转状态码
#define RRLX_EXCEPTION_TO_STATUS_TRY                                           \
    try {
#define RRLX_EXCEPTION_TO_STATUS_CATCH                                         \
    } catch (const rrlx::exception &e) {                                       \
        return e.status();                                                     \
    } catch (const std::invalid_argument &) {                                  \
        return rrlx_invalid_argument;                                          \
    } catch (const std::domain_error &) {                                      \
        return rrlx_domain_error;                                              \
    } catch (const std::length_error &) {                                      \
        return rrlx_length_error;                                              \
    } catch (const std::out_of_range &) {                                      \
        return rrlx_out_of_range;                                              \
    } catch (const std::logic_error &) {                                       \
        return rrlx_logic_error;                                               \
    } catch (const std::range_error &) {                                       \
        return rrlx_range_error;                                               \
    } catch (const std::overflow_error &) {                                    \
        return rrlx_overflow_error;                                            \
    } catch (const std::underflow_error &) {                                   \
        return rrlx_underflow_error;                                           \
    } catch (const std::runtime_error &) {                                     \
        return rrlx_runtime_error;                                             \
    } catch (const std::bad_typeid &) {                                        \
        return rrlx_bad_typeid;                                                \
    } catch (const std::bad_cast &) {                                          \
        return rrlx_bad_cast;                                                  \
    } catch (const std::bad_alloc &) {                                         \
        return rrlx_bad_alloc;                                                 \
    } catch (const std::bad_exception &) {                                     \
        return rrlx_bad_exception;                                             \
    } catch (const std::exception &) {                                         \
        return rrlx_exception;                                                 \
    } catch (...) {                                                            \
        return rrlx_unexpected_exception;                                      \
    }

#endif
