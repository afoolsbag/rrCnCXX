/// \copyright Unlicense

#include "rrlibx/rrlibx.h"

#include <cstring>

#include "exception.hxx"
#include "impl.hxx"
#include "cfg.hxx"

RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_get_version(int *r_major, int *r_minor, int *r_patch, int *r_tweak)
RRLIBX_APIs
{
    RRDLLX_EXCEPTION_TO_STATUS_TRY;
    if (r_major)
        *r_major = static_cast<int>(rrlibx::project_version_major);
    if (r_minor)
        *r_minor = static_cast<int>(rrlibx::project_version_minor);
    if (r_patch)
        *r_patch = static_cast<int>(rrlibx::project_version_patch);
    if (r_tweak)
        *r_tweak = static_cast<int>(rrlibx::project_version_tweak);
    return rrlibx_success;
    RRDLLX_EXCEPTION_TO_STATUS_CATCH;
}

RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_construct(rrlibx_handle_t *r_handle)
RRLIBX_APIs
{
    RRDLLX_EXCEPTION_TO_STATUS_TRY;
    if (!r_handle)
        return rrlibx_invalid_argument;
    *r_handle = rrlibx::impl::alloc();
    return rrlibx_success;
    RRDLLX_EXCEPTION_TO_STATUS_CATCH;
}

RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_destruct(rrlibx_handle_t handle)
RRLIBX_APIs
{
    RRDLLX_EXCEPTION_TO_STATUS_TRY;
    if (!handle)
        return rrlibx_invalid_argument;
    rrlibx::impl::free(handle);
    return rrlibx_success;
    RRDLLX_EXCEPTION_TO_STATUS_CATCH;
}

RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_set_basic(rrlibx_handle_t handle, int value)
RRLIBX_APIs
{
    RRDLLX_EXCEPTION_TO_STATUS_TRY;
    if (!handle)
        return rrlibx_invalid_argument;
    rrlibx::implref(handle).basic = value;
    return rrlibx_success;
    RRDLLX_EXCEPTION_TO_STATUS_CATCH;
}

RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_get_basic(rrlibx_handle_t handle, int *r_value)
RRLIBX_APIs
{
    RRDLLX_EXCEPTION_TO_STATUS_TRY;
    if (!handle || !r_value)
        return rrlibx_invalid_argument;
    *r_value = rrlibx::implref(handle).basic;
    return rrlibx_success;
    RRDLLX_EXCEPTION_TO_STATUS_CATCH;
}

RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_set_array(rrlibx_handle_t handle, const uint8_t data[], size_t size)
RRLIBX_APIs
{
    RRDLLX_EXCEPTION_TO_STATUS_TRY;
    if (!handle || !data || !size)
        return rrlibx_invalid_argument;
    rrlibx::implref(handle).array = {data, data + size};
    return rrlibx_success;
    RRDLLX_EXCEPTION_TO_STATUS_CATCH;
}

RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_get_array(rrlibx_handle_t handle, uint8_t buffer[], size_t *r_size)
RRLIBX_APIs
{
    RRDLLX_EXCEPTION_TO_STATUS_TRY;
    if (!handle || !r_size)
        return rrlibx_invalid_argument;
    const auto &array = rrlibx::implref(handle).array;
    if (!buffer) {
        *r_size = array.size();
        return rrlibx_success;
    }
    if (*r_size < array.size()) {
        *r_size = array.size();
        return rrlibx_range_error;
    }
    std::memcpy(buffer, array.data(), array.size());
    *r_size = array.size();
    return rrlibx_success;
    RRDLLX_EXCEPTION_TO_STATUS_CATCH;
}

RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_get_array_cvr(rrlibx_handle_t handle, const uint8_t *(*r_data), size_t *r_size)
RRLIBX_APIs
{
    RRDLLX_EXCEPTION_TO_STATUS_TRY;
    if (!handle || !r_data || !r_size)
        return rrlibx_invalid_argument;
    const auto &array = rrlibx::implref(handle).array;
    *r_data = array.data();
    *r_size = array.size();
    return rrlibx_success;
    RRDLLX_EXCEPTION_TO_STATUS_CATCH;
}

RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_set_string(rrlibx_handle_t handle, const char string[])
RRLIBX_APIs
{
    RRDLLX_EXCEPTION_TO_STATUS_TRY;
    if (!handle || !string)
        return rrlibx_invalid_argument;
    rrlibx::implref(handle).string = string;
    return rrlibx_success;
    RRDLLX_EXCEPTION_TO_STATUS_CATCH;
}

RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_get_string_fsb(rrlibx_handle_t handle, char buffer[rrlibx_string_fsb_size])
RRLIBX_APIs
{
    RRDLLX_EXCEPTION_TO_STATUS_TRY;
    if (!handle || !buffer)
        return rrlibx_invalid_argument;
    const auto &string = rrlibx::implref(handle).string;
    if (rrlibx_string_fsb_size < string.size() + 1)
        return rrlibx_range_error;
    std::memcpy(buffer, string.data(), string.size());
    buffer[string.size()] = '\0';
    return rrlibx_success;
    RRDLLX_EXCEPTION_TO_STATUS_CATCH;
}

RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_get_string_cvr(rrlibx_handle_t handle, const char *(*r_string))
RRLIBX_APIs
{
    RRDLLX_EXCEPTION_TO_STATUS_TRY;
    if (!handle || !r_string)
        return rrlibx_invalid_argument;
    *r_string = rrlibx::implref(handle).string.data();
    return rrlibx_success;
    RRDLLX_EXCEPTION_TO_STATUS_CATCH;
}

RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_non_blocking(rrlibx_handle_t handle, rrlibx_non_blocking_callback_t callback, void *p_user_data)
RRLIBX_APIs
{
    RRDLLX_EXCEPTION_TO_STATUS_TRY;
    if (!handle || !callback)
        return rrlibx_invalid_argument;
    std::thread {[callback, p_user_data] {
        std::this_thread::yield();
        callback(p_user_data);
    }}.detach();
    return rrlibx_success;
    RRDLLX_EXCEPTION_TO_STATUS_CATCH;
}

RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_get_last_internal_error_message(rrlibx_handle_t handle, char buffer[rrlibx_last_internal_error_message_fsb_size])
RRLIBX_APIs
{
    RRDLLX_EXCEPTION_TO_STATUS_TRY;
    if (!handle || !buffer)
        return rrlibx_invalid_argument;
    const auto &string = rrlibx::implref(handle).string;
    if (rrlibx_last_internal_error_message_fsb_size < string.size() + 1)
        return rrlibx_range_error;
    std::memcpy(buffer, string.data(), string.size());
    buffer[string.size()] = '\0';
    return rrlibx_success;
    RRDLLX_EXCEPTION_TO_STATUS_CATCH;
}
