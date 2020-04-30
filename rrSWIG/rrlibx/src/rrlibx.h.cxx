/// \copyright Unlicense

#include "rrlibx/rrlibx.h"

#include <cstring>

#include "cxx2c.hxx"

EXTERN_C RRLIBX_API enum rrlibx_status_t CDECL
rrlibx_get_version(int *r_major, int *r_minor, int *r_patch, int *r_tweak) NOEXCEPT
{
    return rrlibx::exception2status([&] {
        const auto version = rrlibx::version();
        if (r_major)
            *r_major = version.major;
        if (r_minor)
            *r_minor = version.minor;
        if (r_patch)
            *r_patch = version.patch;
        if (r_tweak)
            *r_tweak = version.tweak;
        return rrlibx_success;
    });
}

EXTERN_C RRLIBX_API enum rrlibx_status_t CDECL
rrlibx_construct(rrlibx_handle_t *r_handle) NOEXCEPT
{
    return rrlibx::exception2status([&] {
        if (!r_handle)
            return rrlibx_invalid_argument;
        *r_handle = rrlibx::clazz2handle::alloc();
        return rrlibx_success;
    });
}

EXTERN_C RRLIBX_API enum rrlibx_status_t CDECL
rrlibx_destruct(rrlibx_handle_t handle) NOEXCEPT
{
    return rrlibx::exception2status(handle, [&] {
        if (!handle)
            return rrlibx_invalid_argument;
        rrlibx::clazz2handle::free(handle);
        return rrlibx_success;
    });
}

EXTERN_C RRLIBX_API enum rrlibx_status_t CDECL
rrlibx_set_basic(rrlibx_handle_t handle, int value) NOEXCEPT
{
    return rrlibx::exception2status(handle, [&] {
        if (!handle)
            return rrlibx_invalid_argument;
        rrlibx::ref(handle)->basic(value);
        return rrlibx_success;
    });
}

EXTERN_C RRLIBX_API enum rrlibx_status_t CDECL
rrlibx_get_basic(rrlibx_handle_t handle, int *r_value) NOEXCEPT
{
    return rrlibx::exception2status(handle, [&] {
        if (!handle || !r_value)
            return rrlibx_invalid_argument;
        *r_value = rrlibx::ref(handle)->basic();
        return rrlibx_success;
    });
}

EXTERN_C RRLIBX_API enum rrlibx_status_t CDECL
rrlibx_set_array(rrlibx_handle_t handle, const uint8_t *data, size_t size) NOEXCEPT
{
    return rrlibx::exception2status(handle, [&] {
        if (!handle || !data || !size)
            return rrlibx_invalid_argument;
        rrlibx::ref(handle)->array({data, data + size});
        return rrlibx_success;
    });
}

EXTERN_C RRLIBX_API enum rrlibx_status_t CDECL
rrlibx_get_array(rrlibx_handle_t handle, uint8_t *buffer, size_t *r_size) NOEXCEPT
{
    return rrlibx::exception2status(handle, [&] {
        if (!handle || !r_size)
            return rrlibx_invalid_argument;
        const auto &array = rrlibx::ref(handle)->array();
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
    });
}

EXTERN_C RRLIBX_API enum rrlibx_status_t CDECL
rrlibx_get_array_cvr(rrlibx_handle_t handle, const uint8_t *(*r_data), size_t *r_size) NOEXCEPT
{
    return rrlibx::exception2status(handle, [&] {
        if (!handle || !r_data || !r_size)
            return rrlibx_invalid_argument;
        const auto &array = rrlibx::ref(handle)->array();
        *r_data = array.data();
        *r_size = array.size();
        return rrlibx_success;
    });
}

EXTERN_C RRLIBX_API enum rrlibx_status_t CDECL
rrlibx_set_string(rrlibx_handle_t handle, const char *string) NOEXCEPT
{
    return rrlibx::exception2status(handle, [&] {
        if (!handle || !string)
            return rrlibx_invalid_argument;
        rrlibx::ref(handle)->string(string);
        return rrlibx_success;
    });
}

EXTERN_C RRLIBX_API enum rrlibx_status_t CDECL
rrlibx_get_string_fsb(rrlibx_handle_t handle, char buffer[rrlibx_string_fsb_size]) NOEXCEPT
{
    return rrlibx::exception2status(handle, [&] {
        if (!handle || !buffer)
            return rrlibx_invalid_argument;
        const auto &string = rrlibx::ref(handle)->string();
        if (rrlibx_string_fsb_size < string.size() + 1)
            return rrlibx_range_error;
        std::memcpy(buffer, string.data(), string.size());
        buffer[string.size()] = '\0';
        return rrlibx_success;
    });
}

EXTERN_C RRLIBX_API enum rrlibx_status_t CDECL
rrlibx_get_string_cvr(rrlibx_handle_t handle, const char *(*r_string)) NOEXCEPT
{
    return rrlibx::exception2status(handle, [&] {
        if (!handle || !r_string)
            return rrlibx_invalid_argument;
        *r_string = rrlibx::ref(handle)->string().data();
        return rrlibx_success;
    });
}

EXTERN_C RRLIBX_API enum rrlibx_status_t CDECL
rrlibx_set_callback(rrlibx_handle_t handle, rrlibx_callback_t callback, void *p_user_data) NOEXCEPT
{
    return rrlibx::exception2status(handle, [&] {
        if (!handle || !callback)
            return rrlibx_invalid_argument;
        rrlibx::ref(handle)->set_callback(callback, p_user_data);
        return rrlibx_success;
    });
}

EXTERN_C RRLIBX_API enum rrlibx_status_t CDECL
rrlibx_invoke_callback(rrlibx_handle_t handle) NOEXCEPT
{
    return rrlibx::exception2status(handle, [&] {
        if (!handle)
            return rrlibx_invalid_argument;
        rrlibx::ref(handle)->invoke_callback();
        return rrlibx_success;
    });
}

EXTERN_C RRLIBX_API enum rrlibx_status_t CDECL
rrlibx_get_last_error_message(rrlibx_handle_t handle, char buffer[rrlibx_last_error_message_fsb_size]) NOEXCEPT
{
    return rrlibx::exception2status([&] {
        if (!handle || !buffer)
            return rrlibx_invalid_argument;
        const auto &string = rrlibx::ref(handle)->string();
        if (rrlibx_last_error_message_fsb_size < string.size() + 1)
            return rrlibx_range_error;
        std::memcpy(buffer, string.data(), string.size());
        buffer[string.size()] = '\0';
        return rrlibx_success;
    });
}
