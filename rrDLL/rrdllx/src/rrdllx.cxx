/// \copyright Unlicense

#include "rrdllx/rrdllx.h"

#include "instance.hxx"
#include "cfg.hxx"

using namespace std;

RRDLLX_APIp enum rrdllx_status_t
RRDLLX_APIm rrdllx_get_version(struct rrdllx_version_t *rv)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
    if (!rv)
        return rrdllx_null_reference;
    rv->major = static_cast<int>(rrdllx::project_version_major);
    rv->minor = static_cast<int>(rrdllx::project_version_minor);
    rv->patch = static_cast<int>(rrdllx::project_version_patch);
    rv->tweak = static_cast<int>(rrdllx::project_version_tweak);
    return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp enum rrdllx_status_t
RRDLLX_APIm rrdllx_construct(rrdllx_handle_t *rh)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
    if (!rh)
        return rrdllx_null_reference;
    *rh = rrdllx::rrdllx_t::alloc_instance();
    return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_destruct(rrdllx_handle_t h)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
    if (!h)
        return rrdllx_null_handle;
    rrdllx::rrdllx_t::free_instance(h);
    return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp enum rrdllx_status_t
RRDLLX_APIm rrdllx_alloc_byte8_array(rrdllx_handle_t h, rrdllx_byte8_rarray_t v, size_t s, struct rrdllx_byte8_sarray_t *rbs)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
    if (!h)
        return rrdllx_null_handle;
    if (!v)
        return rrdllx_null_byte8_rarray;
    if (!rbs)
        return rrdllx_null_reference;
    tie(rbs->size, rbs->data) = rrdllx::rrdllx_t::instance(h).alloc_byte8_array({ v, v + s });
    return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp enum rrdllx_status_t
RRDLLX_APIm rrdllx_free_byte8_array(rrdllx_handle_t h, rrdllx_byte8_rarray_t br)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
    if (!h)
        return rrdllx_null_handle;
    rrdllx::rrdllx_t::instance(h).free_byte8_array(br);
    return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp enum rrdllx_status_t
RRDLLX_APIm rrdllx_alloc_char_array(rrdllx_handle_t h, rrdllx_char_rarray_t v, size_t s, struct rrdllx_char_sarray_t *rbs)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
    if (!h)
        return rrdllx_null_handle;
    if (!v)
        return rrdllx_null_byte8_rarray;
    if (!rbs)
        return rrdllx_null_reference;
    tie(rbs->size, rbs->data) = rrdllx::rrdllx_t::instance(h).alloc_char_array({ v, v + s });
    return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp enum rrdllx_status_t
RRDLLX_APIm rrdllx_free_char_array(rrdllx_handle_t h, rrdllx_char_rarray_t cr)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
    if (!h)
        return rrdllx_null_handle;
    rrdllx::rrdllx_t::instance(h).free_char_array(cr);
    return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_alloc_zstring(rrdllx_handle_t h, rrdllx_zstring_t v, rrdllx_zstring_t *rz)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
    if (!h)
        return rrdllx_null_handle;
    if (!v)
        return rrdllx_null_zstring;
    if (!rz)
        return rrdllx_null_reference;
    *rz = rrdllx::rrdllx_t::instance(h).alloc_zstring(v);
    return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_alloc_last_internal_error_zstring(rrdllx_handle_t h, rrdllx_zstring_t *rz)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
    if (!h)
        return rrdllx_null_handle;
    if (!rz)
        return rrdllx_null_reference;
    *rz = rrdllx::rrdllx_t::instance(h).alloc_last_internal_error_zstring();
    return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_free_zstring(rrdllx_handle_t h, rrdllx_zstring_t z)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
    if (!h)
        return rrdllx_null_handle;
    if (!z)
        return rrdllx_null_zstring;
    rrdllx::rrdllx_t::instance(h).free_zstring(z);
    return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_alloc_zstring_array(rrdllx_handle_t h, rrdllx_zstring_rarray_t v, size_t s, rrdllx_zstring_sarray_t *rzs)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
    if (!h)
        return rrdllx_null_handle;
    if (!v)
        return rrdllx_null_zstring_rarray;
    if (!rzs)
        return rrdllx_null_reference;
    tie(rzs->size, rzs->data) = rrdllx::rrdllx_t::instance(h).alloc_zstring_array({v,v + s});
    return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_free_zstring_array(rrdllx_handle_t h, rrdllx_zstring_rarray_t zr)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
    if (!h)
        return rrdllx_null_handle;
    rrdllx::rrdllx_t::instance(h).free_zstring_array(zr);
    return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_free_all(rrdllx_handle_t h)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
    if (!h)
        return rrdllx_null_handle;
    rrdllx::rrdllx_t::instance(h).free_all();
    return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}
