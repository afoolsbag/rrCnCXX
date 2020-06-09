/// \copyright Unlicense

#include "rrx/rrx.h"

#include <cstring>

#include "cxx2c.hxx"

EXTERN_C RRX_API enum rrx_status_t CDECL
rrx_get_version(int *r_major, int *r_minor, int *r_patch, int *r_tweak) NOEXCEPT
{
    return rrx::exception2status([&] {
        const auto version = rrx::version();
        if (r_major)
            *r_major = version.major;
        if (r_minor)
            *r_minor = version.minor;
        if (r_patch)
            *r_patch = version.patch;
        if (r_tweak)
            *r_tweak = version.tweak;
        return rrx_success;
    });
}

EXTERN_C RRX_API enum rrx_status_t CDECL
rrx_construct(rrx_handle_t *r_handle) NOEXCEPT
{
    return rrx::exception2status([&] {
        if (!r_handle)
            return rrx_invalid_argument;
        *r_handle = rrx::clazz2handle::alloc();
        return rrx_success;
    });
}

EXTERN_C RRX_API enum rrx_status_t CDECL
rrx_destruct(rrx_handle_t handle) NOEXCEPT
{
    return rrx::exception2status(handle, [&] {
        if (!handle)
            return rrx_invalid_argument;
        rrx::clazz2handle::free(handle);
        return rrx_success;
    });
}

EXTERN_C RRX_API enum rrx_status_t CDECL
rrx_set_basic(rrx_handle_t handle, int value) NOEXCEPT
{
    return rrx::exception2status(handle, [&] {
        if (!handle)
            return rrx_invalid_argument;
        rrx::ref(handle)->basic(value);
        return rrx_success;
    });
}

EXTERN_C RRX_API enum rrx_status_t CDECL
rrx_get_basic(rrx_handle_t handle, int *r_value) NOEXCEPT
{
    return rrx::exception2status(handle, [&] {
        if (!handle || !r_value)
            return rrx_invalid_argument;
        *r_value = rrx::ref(handle)->basic();
        return rrx_success;
    });
}

EXTERN_C RRX_API enum rrx_status_t CDECL
rrx_set_array(rrx_handle_t handle, const uint8_t *data, size_t size) NOEXCEPT
{
    return rrx::exception2status(handle, [&] {
        if (!handle || !data || !size)
            return rrx_invalid_argument;
        rrx::ref(handle)->array({data, data + size});
        return rrx_success;
    });
}

EXTERN_C RRX_API enum rrx_status_t CDECL
rrx_get_array(rrx_handle_t handle, uint8_t *buffer, size_t *r_size) NOEXCEPT
{
    return rrx::exception2status(handle, [&] {
        if (!handle || !r_size)
            return rrx_invalid_argument;
        const auto &array = rrx::ref(handle)->array();
        if (!buffer) {
            *r_size = array.size();
            return rrx_success;
        }
        if (*r_size < array.size()) {
            *r_size = array.size();
            return rrx_range_error;
        }
        std::memcpy(buffer, array.data(), array.size());
        *r_size = array.size();
        return rrx_success;
    });
}

EXTERN_C RRX_API enum rrx_status_t CDECL
rrx_get_array_cvr(rrx_handle_t handle, const uint8_t *(*r_data), size_t *r_size) NOEXCEPT
{
    return rrx::exception2status(handle, [&] {
        if (!handle || !r_data || !r_size)
            return rrx_invalid_argument;
        const auto &array = rrx::ref(handle)->array();
        *r_data = array.data();
        *r_size = array.size();
        return rrx_success;
    });
}

EXTERN_C RRX_API enum rrx_status_t CDECL
rrx_set_string(rrx_handle_t handle, const char *string) NOEXCEPT
{
    return rrx::exception2status(handle, [&] {
        if (!handle || !string)
            return rrx_invalid_argument;
        rrx::ref(handle)->string(string);
        return rrx_success;
    });
}

EXTERN_C RRX_API enum rrx_status_t CDECL
rrx_get_string_fsb(rrx_handle_t handle, char buffer[rrx_string_fsb_size]) NOEXCEPT
{
    return rrx::exception2status(handle, [&] {
        if (!handle || !buffer)
            return rrx_invalid_argument;
        const auto &string = rrx::ref(handle)->string();
        if (rrx_string_fsb_size < string.size() + 1)
            return rrx_range_error;
        std::memcpy(buffer, string.data(), string.size());
        buffer[string.size()] = '\0';
        return rrx_success;
    });
}

EXTERN_C RRX_API enum rrx_status_t CDECL
rrx_get_string_cvr(rrx_handle_t handle, const char *(*r_string)) NOEXCEPT
{
    return rrx::exception2status(handle, [&] {
        if (!handle || !r_string)
            return rrx_invalid_argument;
        *r_string = rrx::ref(handle)->string().data();
        return rrx_success;
    });
}

EXTERN_C RRX_API enum rrx_status_t CDECL
rrx_set_callback(rrx_handle_t handle, rrx_callback_t callback, void *p_user_data) NOEXCEPT
{
    return rrx::exception2status(handle, [&] {
        if (!handle || !callback)
            return rrx_invalid_argument;
        rrx::ref(handle)->set_callback(callback, p_user_data);
        return rrx_success;
    });
}

EXTERN_C RRX_API enum rrx_status_t CDECL
rrx_invoke_callback(rrx_handle_t handle) NOEXCEPT
{
    return rrx::exception2status(handle, [&] {
        if (!handle)
            return rrx_invalid_argument;
        rrx::ref(handle)->invoke_callback();
        return rrx_success;
    });
}

EXTERN_C RRX_API enum rrx_status_t CDECL
rrx_get_last_error_message(rrx_handle_t handle, char buffer[rrx_last_error_message_fsb_size]) NOEXCEPT
{
    return rrx::exception2status([&] {
        if (!handle || !buffer)
            return rrx_invalid_argument;
        const auto &string = rrx::ref(handle)->string();
        if (rrx_last_error_message_fsb_size < string.size() + 1)
            return rrx_range_error;
        std::memcpy(buffer, string.data(), string.size());
        buffer[string.size()] = '\0';
        return rrx_success;
    });
}
