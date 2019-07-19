/// \copyright Unlicense

#include "rrlx/rrlx.h"

#include <cstring>

#include "wrapper.hxx"

EXTERN_C RRLX_API enum rrlx_status_t CDECL
rrlx_get_version(int *r_major, int *r_minor, int *r_patch, int *r_tweak) NOEXCEPT
{
    return rrlx::exception_to_status([&]() -> rrlx_status_t {
        const auto version = rrlx::version();
        if (r_major)
            *r_major = version.major;
        if (r_minor)
            *r_minor = version.minor;
        if (r_patch)
            *r_patch = version.patch;
        if (r_tweak)
            *r_tweak = version.tweak;
        return rrlx_success;
    });
}

EXTERN_C RRLX_API enum rrlx_status_t CDECL
rrlx_construct(rrlx_handle_t *r_handle) NOEXCEPT
{
    return rrlx::exception_to_status([&] {
        if (!r_handle)
            return rrlx_invalid_argument;
        *r_handle = rrlx::wrapper::alloc();
        return rrlx_success;
    });
}

EXTERN_C RRLX_API enum rrlx_status_t CDECL
rrlx_destruct(rrlx_handle_t handle) NOEXCEPT
{
    return rrlx::exception_to_status(handle, [&] {
        if (!handle)
            return rrlx_invalid_argument;
        rrlx::wrapper::free(handle);
        return rrlx_success;
    });
}

EXTERN_C RRLX_API enum rrlx_status_t CDECL
rrlx_set_basic(rrlx_handle_t handle, int value) NOEXCEPT
{
    return rrlx::exception_to_status(handle, [&] {
        if (!handle)
            return rrlx_invalid_argument;
        rrlx::ref(handle)->basic(value);
        return rrlx_success;
    });
}

EXTERN_C RRLX_API enum rrlx_status_t CDECL
rrlx_get_basic(rrlx_handle_t handle, int *r_value) NOEXCEPT
{
    return rrlx::exception_to_status(handle, [&] {
        if (!handle || !r_value)
            return rrlx_invalid_argument;
        *r_value = rrlx::ref(handle)->basic();
        return rrlx_success;
    });
}

EXTERN_C RRLX_API enum rrlx_status_t CDECL
rrlx_set_array(rrlx_handle_t handle, const uint8_t data[], size_t size) NOEXCEPT
{
    return rrlx::exception_to_status(handle, [&] {
        if (!handle || !data || !size)
            return rrlx_invalid_argument;
        rrlx::ref(handle)->array({data, data + size});
        return rrlx_success;
    });
}

EXTERN_C RRLX_API enum rrlx_status_t CDECL
rrlx_get_array(rrlx_handle_t handle, uint8_t buffer[], size_t *r_size) NOEXCEPT
{
    return rrlx::exception_to_status(handle, [&] {
        if (!handle || !r_size)
            return rrlx_invalid_argument;
        const auto &array = rrlx::ref(handle)->array();
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
    });
}

EXTERN_C RRLX_API enum rrlx_status_t CDECL
rrlx_get_array_cvr(rrlx_handle_t handle, const uint8_t *(*r_data), size_t *r_size) NOEXCEPT
{
    return rrlx::exception_to_status(handle, [&] {
        if (!handle || !r_data || !r_size)
            return rrlx_invalid_argument;
        const auto &array = rrlx::ref(handle)->array();
        *r_data = array.data();
        *r_size = array.size();
        return rrlx_success;
    });
}

EXTERN_C RRLX_API enum rrlx_status_t CDECL
rrlx_set_string(rrlx_handle_t handle, const char string[]) NOEXCEPT
{
    return rrlx::exception_to_status(handle, [&] {
        if (!handle || !string)
            return rrlx_invalid_argument;
        rrlx::ref(handle)->string(string);
        return rrlx_success;
    });
}

EXTERN_C RRLX_API enum rrlx_status_t CDECL
rrlx_get_string_fsb(rrlx_handle_t handle, char buffer[rrlx_string_fsb_size]) NOEXCEPT
{
    return rrlx::exception_to_status(handle, [&] {
        if (!handle || !buffer)
            return rrlx_invalid_argument;
        const auto &string = rrlx::ref(handle)->string();
        if (rrlx_string_fsb_size < string.size() + 1)
            return rrlx_range_error;
        std::memcpy(buffer, string.data(), string.size());
        buffer[string.size()] = '\0';
        return rrlx_success;
    });
}

EXTERN_C RRLX_API enum rrlx_status_t CDECL
rrlx_get_string_cvr(rrlx_handle_t handle, const char *(*r_string)) NOEXCEPT
{
    return rrlx::exception_to_status(handle, [&] {
        if (!handle || !r_string)
            return rrlx_invalid_argument;
        *r_string = rrlx::ref(handle)->string().data();
        return rrlx_success;
    });
}

EXTERN_C RRLX_API enum rrlx_status_t CDECL
rrlx_set_callback(rrlx_handle_t handle, rrlx_callback_t callback, void *p_user_data) NOEXCEPT
{
    return rrlx::exception_to_status(handle, [&] {
        if (!handle || !callback)
            return rrlx_invalid_argument;
        rrlx::ref(handle)->set_callback(callback, p_user_data);
        return rrlx_success;
    });
}

EXTERN_C RRLX_API enum rrlx_status_t CDECL
rrlx_invoke_callback(rrlx_handle_t handle) NOEXCEPT
{
    return rrlx::exception_to_status(handle, [&] {
        if (!handle)
            return rrlx_invalid_argument;
        rrlx::ref(handle)->invoke_callback();
        return rrlx_success;
    });
}

EXTERN_C RRLX_API enum rrlx_status_t CDECL
rrlx_get_last_error_message(rrlx_handle_t handle, char buffer[rrlx_last_error_message_fsb_size]) NOEXCEPT
{
    return rrlx::exception_to_status([&] {
        if (!handle || !buffer)
            return rrlx_invalid_argument;
        const auto &string = rrlx::ref(handle)->string();
        if (rrlx_last_error_message_fsb_size < string.size() + 1)
            return rrlx_range_error;
        std::memcpy(buffer, string.data(), string.size());
        buffer[string.size()] = '\0';
        return rrlx_success;
    });
}
