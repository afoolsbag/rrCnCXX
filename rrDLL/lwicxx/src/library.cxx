/// \copyright Unlicense

#define RRDLL_LWICXX_EXPORTS
#include "lwicxx/library.hxx"

#include "config.hxx"

using namespace std;

class rrdll_lwicxx {
public:
    void plus(int n) { r += n; }
    void minus(int n) { r -= n; }
    int equals() const { return r; }
private:
    int r {0};
};

EXTERN_C
RRDLL_LWICXX_API
rrdll_lwicxx_error_code_t
APIENTRY
rrdll_lwicxx_construct(rrdll_lwicxx_handle_t *pout)
{
    if (!pout)
        return rrdll_lwicxx_invalid_parameter;
    if (*pout)
        return rrdll_lwicxx_invalid_handle;
    *pout = reinterpret_cast<void *>(new rrdll_lwicxx);
    return rrdll_lwicxx_success;
}

EXTERN_C
RRDLL_LWICXX_API
rrdll_lwicxx_error_code_t
APIENTRY
rrdll_lwicxx_plus(rrdll_lwicxx_handle_t handle, int n)
{
    if (!handle)
        return rrdll_lwicxx_invalid_handle;
    auto const p = reinterpret_cast<rrdll_lwicxx *>(handle);
    p->plus(n);
    return rrdll_lwicxx_success;
}

EXTERN_C
RRDLL_LWICXX_API
rrdll_lwicxx_error_code_t
APIENTRY
rrdll_lwicxx_minus(rrdll_lwicxx_handle_t handle, int n)
{
    if (!handle)
        return rrdll_lwicxx_invalid_handle;
    auto const p = reinterpret_cast<rrdll_lwicxx *>(handle);
    p->minus(n);
    return rrdll_lwicxx_success;
}

EXTERN_C
RRDLL_LWICXX_API
rrdll_lwicxx_error_code_t
APIENTRY
rrdll_lwicxx_equals(rrdll_lwicxx_handle_t handle, int *pout)
{
    if (!handle)
        return rrdll_lwicxx_invalid_handle;
    if (!pout)
        return rrdll_lwicxx_invalid_parameter;
    auto const p = reinterpret_cast<rrdll_lwicxx *>(handle);
    *pout = p->equals();
    return rrdll_lwicxx_success;
}

EXTERN_C
RRDLL_LWICXX_API
rrdll_lwicxx_error_code_t
APIENTRY
rrdll_lwicxx_destruct(rrdll_lwicxx_handle_t handle)
{
    if (!handle)
        return rrdll_lwicxx_invalid_handle;
    auto const p = reinterpret_cast<rrdll_lwicxx *>(handle);
    delete p;
    return rrdll_lwicxx_success;
}
