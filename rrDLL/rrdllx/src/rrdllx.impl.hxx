//===-- rrDLLx --------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 库 rrDLLx 的实现。
///
/// \version 2019-05-14
/// \since 2019-05-14
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRDLLX_RRDLLX_IMPL_HXX_
#define RRDLLX_RRDLLX_IMPL_HXX_

#include <cstdint>
#include <exception>
#include <functional>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

#include "rrdllx/rrdllx.intf.h"

namespace rrdllx {

using status_t = rrdllx_status_t;
using handle_t = rrdllx_handle_t;
using zstring_deref_t = rrdllx_zstring_deref_t;
using zstring_t = rrdllx_zstring_t;
using zstring_array_deref_t = rrdllx_zstring_array_deref_t;
using zstring_array_t = rrdllx_zstring_array_t;
using binary_deref_t = rrdllx_binary_deref_t;
using binary_t = rrdllx_binary_t;

class exception_t final: public std::exception {
public:
    explicit exception_t(status_t status): status_ {status} {}
    [[nodiscard]] status_t status() const { return status_; }
private:
    status_t status_;
};

class rrdllx_t final {
public:
    [[nodiscard]] static handle_t alloc_instance();
    static rrdllx_t &             instance(handle_t handle);
    static void                   free_instance(handle_t handle);

    [[nodiscard]] zstring_t       alloc_zstring(const std::string &value);
    void                          free_zstring(zstring_t zstring);

    [[nodiscard]] zstring_array_t alloc_zstring_array(const std::vector<std::string> &value);
    void                          free_zstring_array(zstring_array_t zstring_array);

    [[nodiscard]] binary_t        alloc_binary(const std::vector<std::uint8_t> &value);
    void                          free_binary(binary_t binary);

    void                          free_all();

private:
    static std::map<handle_t, std::unique_ptr<rrdllx_t>>              instance_map_;

    std::map<zstring_t, std::unique_ptr<zstring_deref_t>>             zstring_map_;

    std::map<zstring_array_t, std::unique_ptr<zstring_array_deref_t>> zstring_array_map_;
    std::map<const zstring_t *, std::unique_ptr<const zstring_t[]>>   zstring_array_vector_map_;

    std::map<binary_t, std::unique_ptr<binary_deref_t>>               binary_map_;
    std::map<const uint8_t *, std::unique_ptr<const uint8_t[]>>       binary_data_map_;

    using zstring_delete_t = std::function<void(zstring_t)>;
    const zstring_delete_t                                            zstring_delete_ {std::bind(&rrdllx_t::free_zstring, this, std::placeholders::_1)};
    std::unique_ptr<zstring_deref_t, zstring_delete_t>                zstring_unique_ptr_ {nullptr, zstring_delete_};
};//class rrdllx_t

}//namespace rrdllx

/// \def RRDLLX_ETS_TRY
/// \def RRDLLX_ETS_CATCH_ALL
/// \brief 异常转状态码（exception to status）
#define RRDLLX_ETS_TRY                                                         \
    try
#define RRDLLX_ETS_CATCH_ALL                                                   \
      catch (const rrdllx::exception_t &e) {                                   \
        return e.status();                                                     \
    } catch (const std::invalid_argument &) {                                  \
        return rrdllx_invalid_argument;                                        \
    } catch (const std::domain_error &) {                                      \
        return rrdllx_domain_error;                                            \
    } catch (const std::length_error &) {                                      \
        return rrdllx_length_error;                                            \
    } catch (const std::out_of_range &) {                                      \
        return rrdllx_out_of_range;                                            \
    } catch (const std::logic_error &) {                                       \
        return rrdllx_logic_error;                                             \
    } catch (const std::range_error &) {                                       \
        return rrdllx_range_error;                                             \
    } catch (const std::overflow_error &) {                                    \
        return rrdllx_overflow_error;                                          \
    } catch (const std::underflow_error &) {                                   \
        return rrdllx_underflow_error;                                         \
    } catch (const std::runtime_error &) {                                     \
        return rrdllx_runtime_error;                                           \
    } catch (const std::bad_typeid &) {                                        \
        return rrdllx_bad_typeid;                                              \
    } catch (const std::bad_cast &) {                                          \
        return rrdllx_bad_cast;                                                \
    } catch (const std::bad_alloc &) {                                         \
        return rrdllx_bad_alloc;                                               \
    } catch (const std::bad_exception &) {                                     \
        return rrdllx_bad_exception;                                           \
    } catch (const std::exception &) {                                         \
        return rrdllx_exception;                                               \
    } catch (...) {                                                            \
        return rrdllx_unexpected_exception;                                    \
    }

#endif//RRDLLX_RRDLLX_IMPL_HXX_
