/// \copyright Unlicense

#define CXXLIB_EXPORTS
#include "cxxlib/library.hxx"

#include "config.hxx"

using namespace std;

class cxxlib_impl {
public:
    void plus(int n) { r += n; }
    void minus(int n) { r -= n; }
    int equals() const { return r; }
private:
    int r {0};
};

CXXLIB_DECORATING CXXLIB_IMEXPORT cxxlib_error_code_t CXXLIB_CALLING cxxlib_construct(cxxlib_handle_t *out)
{
    if (!out)
        return cxxlib_invalid_parameter;
    if (*out)
        return cxxlib_invalid_handle;
    *out = reinterpret_cast<void *>(new cxxlib_impl);
    return cxxlib_success;
}

CXXLIB_DECORATING CXXLIB_IMEXPORT cxxlib_error_code_t CXXLIB_CALLING cxxlib_plus(cxxlib_handle_t handle, int n)
{
    if (!handle)
        return cxxlib_invalid_handle;
    auto const p = reinterpret_cast<cxxlib_impl *>(handle);
    p->plus(n);
    return cxxlib_success;
}

CXXLIB_DECORATING CXXLIB_IMEXPORT cxxlib_error_code_t CXXLIB_CALLING cxxlib_minus(cxxlib_handle_t handle, int n)
{
    if (!handle)
        return cxxlib_invalid_handle;
    auto const p = reinterpret_cast<cxxlib_impl *>(handle);
    p->minus(n);
    return cxxlib_success;
}

CXXLIB_DECORATING CXXLIB_IMEXPORT cxxlib_error_code_t CXXLIB_CALLING cxxlib_equals(cxxlib_handle_t handle, int *out)
{
    if (!handle)
        return cxxlib_invalid_handle;
    if (!out)
        return cxxlib_invalid_parameter;
    auto const p = reinterpret_cast<cxxlib_impl *>(handle);
    *out = p->equals();
    return cxxlib_success;
}

CXXLIB_DECORATING CXXLIB_IMEXPORT cxxlib_error_code_t CXXLIB_CALLING cxxlib_destruct(cxxlib_handle_t handle)
{
    if (!handle)
        return cxxlib_invalid_handle;
    auto const p = reinterpret_cast<cxxlib_impl *>(handle);
    delete p;
    return cxxlib_success;
}
