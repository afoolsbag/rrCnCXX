/// \copyright Unlicense

#include "rrlibx/rrlibx.h"

#include <cstring>

#include "exception.hxx"
#include "impl.hxx"
#include "cfg.hxx"

RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_get_version(int *ref_major, int *ref_minor, int *ref_patch, int *ref_tweak)
RRLIBX_APIs
{
    RRDLLX_EXCEPTION_TO_STATUS_TRY;
    if (ref_major)
        *ref_major = static_cast<int>(rrlibx::project_version_major);
    if (ref_minor)
        *ref_minor = static_cast<int>(rrlibx::project_version_minor);
    if (ref_patch)
        *ref_patch = static_cast<int>(rrlibx::project_version_patch);
    if (ref_tweak)
        *ref_tweak = static_cast<int>(rrlibx::project_version_tweak);
    return rrlibx_success;
    RRDLLX_EXCEPTION_TO_STATUS_CATCH_ALL;
}

RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_construct(rrlibx_handle_t *ref_handle)
RRLIBX_APIs
{
    RRDLLX_EXCEPTION_TO_STATUS_TRY;
    if (!ref_handle)
        return rrlibx_invalid_argument;
    *ref_handle = rrlibx::impl::alloc();
    return rrlibx_success;
    RRDLLX_EXCEPTION_TO_STATUS_CATCH_ALL;
}

RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_destruct(rrlibx_handle_t h)
RRLIBX_APIs
{
    RRDLLX_EXCEPTION_TO_STATUS_TRY;
    if (!h)
        return rrlibx_invalid_argument;
    rrlibx::impl::free(h);
    return rrlibx_success;
    RRDLLX_EXCEPTION_TO_STATUS_CATCH_ALL;
}

RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_set_basic(rrlibx_handle_t h, int value)
RRLIBX_APIs
{
    RRDLLX_EXCEPTION_TO_STATUS_TRY;
    if (!h)
        return rrlibx_invalid_argument;
    rrlibx::implref(h).basic = value;
    return rrlibx_success;
    RRDLLX_EXCEPTION_TO_STATUS_CATCH_ALL;
}

RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_get_basic(rrlibx_handle_t h, int *ref_value)
RRLIBX_APIs
{
    RRDLLX_EXCEPTION_TO_STATUS_TRY;
    if (!h || !ref_value)
        return rrlibx_invalid_argument;
    *ref_value = rrlibx::implref(h).basic;
    return rrlibx_success;
    RRDLLX_EXCEPTION_TO_STATUS_CATCH_ALL;
}

RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_set_array(rrlibx_handle_t h, const uint8_t *data, size_t size)
RRLIBX_APIs
{
    RRDLLX_EXCEPTION_TO_STATUS_TRY;
    if (!h || !data || !size)
        return rrlibx_invalid_argument;
    rrlibx::implref(h).array = {data, data + size};
    return rrlibx_success;
    RRDLLX_EXCEPTION_TO_STATUS_CATCH_ALL;
}

RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_get_array(rrlibx_handle_t h, uint8_t *buffer, size_t *ref_size)
RRLIBX_APIs
{
    RRDLLX_EXCEPTION_TO_STATUS_TRY;
    if (!h || !ref_size)
        return rrlibx_invalid_argument;
    const auto &array = rrlibx::implref(h).array;
    if (!buffer) {
        *ref_size = array.size();
        return rrlibx_success;
    }
    if (*ref_size < array.size()) {
        *ref_size = array.size();
        return rrlibx_range_error;
    }
    std::memcpy(buffer, array.data(), array.size());
    *ref_size = array.size();
    return rrlibx_success;
    RRDLLX_EXCEPTION_TO_STATUS_CATCH_ALL;
}

RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_get_array_volatile_readonly_reference(rrlibx_handle_t h, const uint8_t **ref_data, size_t *ref_size)
RRLIBX_APIs
{
    RRDLLX_EXCEPTION_TO_STATUS_TRY;
    if (!h || !ref_data || !ref_size)
        return rrlibx_invalid_argument;
    const auto &array = rrlibx::implref(h).array;
    *ref_data = array.data();
    *ref_size = array.size();
    return rrlibx_success;
    RRDLLX_EXCEPTION_TO_STATUS_CATCH_ALL;
}

RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_set_string(rrlibx_handle_t h, const char *string)
RRLIBX_APIs
{
    RRDLLX_EXCEPTION_TO_STATUS_TRY;
    if (!h || !string)
        return rrlibx_invalid_argument;
    rrlibx::implref(h).string = string;
    return rrlibx_success;
    RRDLLX_EXCEPTION_TO_STATUS_CATCH_ALL;
}

RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_get_string_fixed_size(rrlibx_handle_t h, char buffer[rrlibx_string_fixed_size])
RRLIBX_APIs
{
    RRDLLX_EXCEPTION_TO_STATUS_TRY;
    if (!h || !buffer)
        return rrlibx_invalid_argument;
    const auto &string = rrlibx::implref(h).string;
    if (rrlibx_string_fixed_size < string.size() + 1)
        return rrlibx_range_error;
    std::memcpy(buffer, string.data(), string.size());
    buffer[string.size()] = '\0';
    return rrlibx_success;
    RRDLLX_EXCEPTION_TO_STATUS_CATCH_ALL;
}

RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_get_string_volatile_readonly_reference(rrlibx_handle_t h, const char **ref_string)
RRLIBX_APIs
{
    RRDLLX_EXCEPTION_TO_STATUS_TRY;
    if (!h || !ref_string)
        return rrlibx_invalid_argument;
    *ref_string = rrlibx::implref(h).string.c_str();
    return rrlibx_success;
    RRDLLX_EXCEPTION_TO_STATUS_CATCH_ALL;
}

RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_get_last_internal_error_message(rrlibx_handle_t h, char buffer[rrlibx_error_message_size])
RRLIBX_APIs
{
    RRDLLX_EXCEPTION_TO_STATUS_TRY;
    if (!h || !buffer)
        return rrlibx_invalid_argument;
    const auto &string = rrlibx::implref(h).string;
    if (rrlibx_error_message_size < string.size() + 1)
        return rrlibx_range_error;
    std::memcpy(buffer, string.data(), string.size());
    buffer[string.size()] = '\0';
    return rrlibx_success;
    RRDLLX_EXCEPTION_TO_STATUS_CATCH_ALL;
}
