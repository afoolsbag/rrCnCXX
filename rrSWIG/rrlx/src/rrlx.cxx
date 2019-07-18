/// \copyright Unlicense

#include "rrlx/rrlx.h"

#include <cstring>

#include "cfg.hxx"
#include "exception.hxx"
#include "impl.hxx"

RRLX_APIp enum rrlx_status_t
RRLX_APIm rrlx_get_version(int *r_major, int *r_minor, int *r_patch, int *r_tweak)
RRLX_APIs
{
    RRLX_EXCEPTION_TO_STATUS_TRY;
    if (r_major)
        *r_major = static_cast<int>(rrlx::project_version_major);
    if (r_minor)
        *r_minor = static_cast<int>(rrlx::project_version_minor);
    if (r_patch)
        *r_patch = static_cast<int>(rrlx::project_version_patch);
    if (r_tweak)
        *r_tweak = static_cast<int>(rrlx::project_version_tweak);
    return rrlx_success;
    RRLX_EXCEPTION_TO_STATUS_CATCH;
}

RRLX_APIp enum rrlx_status_t
RRLX_APIm rrlx_construct(rrlx_handle_t *r_handle)
RRLX_APIs
{
    RRLX_EXCEPTION_TO_STATUS_TRY;
    if (!r_handle)
        return rrlx_invalid_argument;
    *r_handle = rrlx::impl::alloc();
    return rrlx_success;
    RRLX_EXCEPTION_TO_STATUS_CATCH;
}

RRLX_APIp enum rrlx_status_t
RRLX_APIm rrlx_destruct(rrlx_handle_t handle)
RRLX_APIs
{
    RRLX_EXCEPTION_TO_STATUS_TRY;
    if (!handle)
        return rrlx_invalid_argument;
    rrlx::impl::free(handle);
    return rrlx_success;
    RRLX_EXCEPTION_TO_STATUS_CATCH;
}

RRLX_APIp enum rrlx_status_t
RRLX_APIm rrlx_set_basic(rrlx_handle_t handle, int value)
RRLX_APIs
{
    RRLX_EXCEPTION_TO_STATUS_TRY;
    if (!handle)
        return rrlx_invalid_argument;
    rrlx::implref(handle).basic = value;
    return rrlx_success;
    RRLX_EXCEPTION_TO_STATUS_CATCH;
}

RRLX_APIp enum rrlx_status_t
RRLX_APIm rrlx_get_basic(rrlx_handle_t handle, int *r_value)
RRLX_APIs
{
    RRLX_EXCEPTION_TO_STATUS_TRY;
    if (!handle || !r_value)
        return rrlx_invalid_argument;
    *r_value = rrlx::implref(handle).basic;
    return rrlx_success;
    RRLX_EXCEPTION_TO_STATUS_CATCH;
}

RRLX_APIp enum rrlx_status_t
RRLX_APIm rrlx_set_array(rrlx_handle_t handle, const uint8_t data[], size_t size)
RRLX_APIs
{
    RRLX_EXCEPTION_TO_STATUS_TRY;
    if (!handle || !data || !size)
        return rrlx_invalid_argument;
    rrlx::implref(handle).array = {data, data + size};
    return rrlx_success;
    RRLX_EXCEPTION_TO_STATUS_CATCH;
}

RRLX_APIp enum rrlx_status_t
RRLX_APIm rrlx_get_array(rrlx_handle_t handle, uint8_t buffer[], size_t *r_size)
RRLX_APIs
{
    RRLX_EXCEPTION_TO_STATUS_TRY;
    if (!handle || !r_size)
        return rrlx_invalid_argument;
    const auto &array = rrlx::implref(handle).array;
    if (!buffer) {
        *r_size = array.size();
        return rrlx_success;
    }
    if (*r_size < array.size()) {
        *r_size = array.size();
        return rrlx_range_error;
    }
    std::memcpy(buffer, array.data(), array.size());
    *r_size = array.size();
    return rrlx_success;
    RRLX_EXCEPTION_TO_STATUS_CATCH;
}

RRLX_APIp enum rrlx_status_t
RRLX_APIm rrlx_get_array_cvr(rrlx_handle_t handle, const uint8_t *(*r_data), size_t *r_size)
RRLX_APIs
{
    RRLX_EXCEPTION_TO_STATUS_TRY;
    if (!handle || !r_data || !r_size)
        return rrlx_invalid_argument;
    const auto &array = rrlx::implref(handle).array;
    *r_data = array.data();
    *r_size = array.size();
    return rrlx_success;
    RRLX_EXCEPTION_TO_STATUS_CATCH;
}

RRLX_APIp enum rrlx_status_t
RRLX_APIm rrlx_set_string(rrlx_handle_t handle, const char string[])
RRLX_APIs
{
    RRLX_EXCEPTION_TO_STATUS_TRY;
    if (!handle || !string)
        return rrlx_invalid_argument;
    rrlx::implref(handle).string = string;
    return rrlx_success;
    RRLX_EXCEPTION_TO_STATUS_CATCH;
}

RRLX_APIp enum rrlx_status_t
RRLX_APIm rrlx_get_string_fsb(rrlx_handle_t handle, char buffer[rrlx_string_fsb_size])
RRLX_APIs
{
    RRLX_EXCEPTION_TO_STATUS_TRY;
    if (!handle || !buffer)
        return rrlx_invalid_argument;
    const auto &string = rrlx::implref(handle).string;
    if (rrlx_string_fsb_size < string.size() + 1)
        return rrlx_range_error;
    std::memcpy(buffer, string.data(), string.size());
    buffer[string.size()] = '\0';
    return rrlx_success;
    RRLX_EXCEPTION_TO_STATUS_CATCH;
}

RRLX_APIp enum rrlx_status_t
RRLX_APIm rrlx_get_string_cvr(rrlx_handle_t handle, const char *(*r_string))
RRLX_APIs
{
    RRLX_EXCEPTION_TO_STATUS_TRY;
    if (!handle || !r_string)
        return rrlx_invalid_argument;
    *r_string = rrlx::implref(handle).string.data();
    return rrlx_success;
    RRLX_EXCEPTION_TO_STATUS_CATCH;
}

RRLX_APIp enum rrlx_status_t
RRLX_APIm rrlx_non_blocking(rrlx_handle_t handle, rrlx_non_blocking_callback_t callback, void *p_user_data)
RRLX_APIs
{
    RRLX_EXCEPTION_TO_STATUS_TRY;
    if (!handle || !callback)
        return rrlx_invalid_argument;
    std::thread {[callback, p_user_data] {
        std::this_thread::yield();
        callback(p_user_data);
    }}.detach();
    return rrlx_success;
    RRLX_EXCEPTION_TO_STATUS_CATCH;
}

RRLX_APIp enum rrlx_status_t
RRLX_APIm rrlx_get_last_internal_error_message(rrlx_handle_t handle, char buffer[rrlx_last_internal_error_message_fsb_size])
RRLX_APIs
{
    RRLX_EXCEPTION_TO_STATUS_TRY;
    if (!handle || !buffer)
        return rrlx_invalid_argument;
    const auto &string = rrlx::implref(handle).string;
    if (rrlx_last_internal_error_message_fsb_size < string.size() + 1)
        return rrlx_range_error;
    std::memcpy(buffer, string.data(), string.size());
    buffer[string.size()] = '\0';
    return rrlx_success;
    RRLX_EXCEPTION_TO_STATUS_CATCH;
}
