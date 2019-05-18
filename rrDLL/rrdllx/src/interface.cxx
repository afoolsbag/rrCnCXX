/// \copyright Unlicense

#include "rrdllx/rrdllx.h"

#include "instance.hxx"
#include "cfg.hxx"

using namespace std;

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_get_version(rrdllx_version_t *rv)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY{
    if (!rv)
        return rrdllx_null_reference;
    rv->major = static_cast<int>(rrdllx::project_version_major);
    rv->minor = static_cast<int>(rrdllx::project_version_minor);
    rv->patch = static_cast<int>(rrdllx::project_version_patch);
    rv->tweak = static_cast<int>(rrdllx::project_version_tweak);
    return rrdllx_success;
    }RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_construct(rrdllx_handle_t *rh)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY{
    if (!rh)
        return rrdllx_null_reference;
    if (*rh != nullptr)
        return rrdllx_dereference_not_initialized;
    *rh = rrdllx::rrdllx_t::alloc_instance();
    return rrdllx_success;
    }RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_destruct(rrdllx_handle_t h)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY{
    rrdllx::rrdllx_t::free_instance(h);
    return rrdllx_success;
    }RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_alloc_zstring(rrdllx_handle_t h, rrdllx_zstring_t v, rrdllx_zstring_t *rz)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY{
    if (!h || !v)
        return rrdllx_null_pointer;
    if (!rz)
        return rrdllx_null_reference;
    if (*rz != nullptr)
        return rrdllx_dereference_not_initialized;
    *rz = rrdllx::rrdllx_t::instance(h).alloc_zstring(v);
    return rrdllx_success;
    }RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_free_zstring(rrdllx_handle_t h, rrdllx_zstring_t z)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY{
    if (!h || !z)
        return rrdllx_null_pointer;
    rrdllx::rrdllx_t::instance(h).free_zstring(z);
    return rrdllx_success;
    }RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_alloc_zstring_array(rrdllx_handle_t h, const rrdllx_zstring_t v[], size_t c, rrdllx_zstring_array_t *rza)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY{
    if (!h || !v)
        return rrdllx_null_pointer;
    if (!rza)
        return rrdllx_null_reference;
    if (*rza != nullptr)
        return rrdllx_dereference_not_initialized;
    *rza = rrdllx::rrdllx_t::instance(h).alloc_zstring_array({v,v + c});
    return rrdllx_success;
    }RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_free_zstring_array(rrdllx_handle_t h, rrdllx_zstring_array_t za)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY{
    if (!h || !za)
        return rrdllx_null_pointer;
    rrdllx::rrdllx_t::instance(h).free_zstring_array(za);
    return rrdllx_success;
    }RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_alloc_binary(rrdllx_handle_t h, const uint8_t *v, size_t s, rrdllx_binary_t *rb)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY{
    if (!h || !v)
        return rrdllx_null_pointer;
    if (!rb)
        return rrdllx_null_reference;
    if (*rb != nullptr)
        return rrdllx_dereference_not_initialized;
    *rb = rrdllx::rrdllx_t::instance(h).alloc_binary({ v, v + s });
    return rrdllx_success;
    }RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_free_binary(rrdllx_handle_t h, rrdllx_binary_t b)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY{
    if (!h || !b)
        return rrdllx_null_pointer;
    rrdllx::rrdllx_t::instance(h).free_binary(b);
    return rrdllx_success;
    }RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_free_all(rrdllx_handle_t h)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY{
    if (!h)
        return rrdllx_null_pointer;
    rrdllx::rrdllx_t::instance(h).free_all();
    return rrdllx_success;
    }RRDLLX_ETS_CATCH_ALL
}
