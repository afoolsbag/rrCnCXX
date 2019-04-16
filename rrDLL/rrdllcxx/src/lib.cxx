/// \copyright Unlicense

#define RRDLLCXX_EXPORTS
#include "rrdllcxx/lib.h"

#include <map>
#include <memory>

#include "cfg.hxx"

using namespace std;

//------------------------------------------------------------------------------
// C++ IMPLEMENTATION

struct rrdllcxx_t {
public:
    void plus(int n) noexcept { r += n; }
    void minus(int n) noexcept { r -= n; }
    int equals() const noexcept { return r; }
private:
    int r {};
};

//------------------------------------------------------------------------------
// C INTERFACE

/// \brief 实例映射
/// \details 用于管理实例的生命周期
map<rrdllcxx_handle_t, unique_ptr<rrdllcxx_t>> inst_map;

RRDLLCXX_APIp rrdllcxx_status_t
RRDLLCXX_APIm rrdllcxx_version(rrdllcxx_version_t *pv)
RRDLLCXX_APIs
{
    if (!pv)
        return rrdllcxx_invalid_argument;

    pv->major = static_cast<int>(rrdllcxx::project_version_major);
    pv->minor = static_cast<int>(rrdllcxx::project_version_minor);
    pv->patch = static_cast<int>(rrdllcxx::project_version_patch);
    pv->tweak = static_cast<int>(rrdllcxx::project_version_tweak);

    return rrdllcxx_success;
}

RRDLLCXX_APIp rrdllcxx_status_t
RRDLLCXX_APIm rrdllcxx_construct(rrdllcxx_handle_t *ph)
RRDLLCXX_APIs
{
    if (!ph)
        return rrdllcxx_invalid_argument;

    auto mov = make_unique<rrdllcxx_t>();
    if (!mov)
        return rrdllcxx_bad_alloc;
    *ph = mov.get();

    auto tmp = make_pair(*ph, move(mov));
    inst_map.insert(move(tmp));
    return rrdllcxx_success;
}

RRDLLCXX_APIp rrdllcxx_status_t
RRDLLCXX_APIm rrdllcxx_plus(rrdllcxx_handle_t h, int n)
RRDLLCXX_APIs
{
    if (!inst_map.count(h))
        return rrdllcxx_out_of_range;

    h->plus(n);
    return rrdllcxx_success;
}

RRDLLCXX_APIp rrdllcxx_status_t
RRDLLCXX_APIm rrdllcxx_minus(rrdllcxx_handle_t h, int n)
RRDLLCXX_APIs
{
    if (!inst_map.count(h))
        return rrdllcxx_out_of_range;

    h->minus(n);
    return rrdllcxx_success;
}

RRDLLCXX_APIp rrdllcxx_status_t
RRDLLCXX_APIm rrdllcxx_equals(rrdllcxx_handle_t h, int *pn)
RRDLLCXX_APIs
{
    if (!pn)
        return rrdllcxx_invalid_argument;
    if (!inst_map.count(h))
        return rrdllcxx_out_of_range;

    *pn = h->equals();
    return rrdllcxx_success;
}

RRDLLCXX_APIp rrdllcxx_status_t
RRDLLCXX_APIm rrdllcxx_destruct(rrdllcxx_handle_t h)
RRDLLCXX_APIs
{
    if (!inst_map.count(h))
        return rrdllcxx_out_of_range;

    inst_map.erase(h);
    return rrdllcxx_success;
}
