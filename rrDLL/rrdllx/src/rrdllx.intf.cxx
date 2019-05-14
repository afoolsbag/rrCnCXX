/// \copyright Unlicense

#include "rrdllx/rrdllx.intf.h"
#include "rrdllx.impl.hxx"

#include "cfg.hxx"

using namespace std;

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_get_version(rrdllx_version_t *rv)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
        if (!rv)
            return rrdllx_invalid_argument_nullptr;
        rv->major = static_cast<int>(rrdllx::project_version_major);
        rv->minor = static_cast<int>(rrdllx::project_version_minor);
        rv->patch = static_cast<int>(rrdllx::project_version_patch);
        rv->tweak = static_cast<int>(rrdllx::project_version_tweak);
        return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_construct(rrdllx_handle_t *rh)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
        if (!rh)
            return rrdllx_invalid_argument_nullptr;
        if (*rh != nullptr)
            return rrdllx_invalid_argument_reference_to_notnull;
        *rh = rrdllx::rrdllx_t::alloc_instance();
        return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_destruct(rrdllx_handle_t h)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
        rrdllx::rrdllx_t::free_instance(h);
        return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_alloc_zstring(rrdllx_handle_t h, rrdllx_zstring_t *rz)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
        if (!rz)
            return rrdllx_invalid_argument_nullptr;
        if (*rz != nullptr)
            return rrdllx_invalid_argument_reference_to_notnull;
        *rz = rrdllx::rrdllx_t::instance(h).alloc_zstring("Test zstring.");
        return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_free_zstring(rrdllx_handle_t h, rrdllx_zstring_t z)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
        rrdllx::rrdllx_t::instance(h).free_zstring(z);
        return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_alloc_zstring_array(rrdllx_handle_t h, rrdllx_zstring_array_t *rza)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
        if (!rza)
            return rrdllx_invalid_argument_nullptr;
        if (*rza != nullptr)
            return rrdllx_invalid_argument_reference_to_notnull;
        *rza = rrdllx::rrdllx_t::instance(h).alloc_zstring_array({"Test zstring 1/3.", "Test zstring 2/3.", "Test zstring 3/3."});
        return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_free_zstring_array(rrdllx_handle_t h, rrdllx_zstring_array_t za)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
        rrdllx::rrdllx_t::instance(h).free_zstring_array(za);
        return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_alloc_binary(rrdllx_handle_t h, rrdllx_binary_t *rb)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
        if (!rb)
            return rrdllx_invalid_argument_nullptr;
        if (*rb != nullptr)
            return rrdllx_invalid_argument_reference_to_notnull;
        *rb = rrdllx::rrdllx_t::instance(h).alloc_binary({1, 2, 3, 4, 5, 6, 7, 8});
        return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_free_binary(rrdllx_handle_t h, rrdllx_binary_t b)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
        rrdllx::rrdllx_t::instance(h).free_binary(b);
        return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_free_all(rrdllx_handle_t h)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
        rrdllx::rrdllx_t::instance(h).free_all();
        return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}
