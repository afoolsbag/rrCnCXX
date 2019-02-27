/// \copyright Unlicense

#define RRX_EXPORTS
#include "rrx/lib.h"

#include <map>
#include <memory>

#include "cfg.hxx"

using namespace std;

struct rrx_t {
public:
    void plus(int n) { r += n; }
    void minus(int n) { r -= n; }
    int equals() { return r; };
private:
    int r {};
};

/// \brief 实例映射
/// \details 用于管理实例的生命周期
map<rrx_handle_t, unique_ptr<rrx_t>> inst_map;

RRX_DECORATING RRX_PORTING rrx_status_t RRX_CALLING
rrx_version(rrx_version_t *pv)
{
    if (!pv)
        return rrx_invalid_argument;

    pv->major = static_cast<int>(rrx::project_version_major);
    pv->minor = static_cast<int>(rrx::project_version_minor);
    pv->patch = static_cast<int>(rrx::project_version_patch);
    pv->tweak = static_cast<int>(rrx::project_version_tweak);

    return rrx_success;
}

RRX_DECORATING RRX_PORTING rrx_status_t RRX_CALLING
rrx_construct(rrx_handle_t *ph)
{
    if (!ph)
        return rrx_invalid_argument;

    auto mov = make_unique<rrx_t>();
    if (!mov)
        return rrx_bad_alloc;
    *ph = mov.get();

    auto tmp = make_pair(*ph, move(mov));
    inst_map.insert(move(tmp));
    return rrx_success;
}

RRX_DECORATING RRX_PORTING rrx_status_t RRX_CALLING
rrx_plus(rrx_handle_t h, int n)
{
    if (!inst_map.count(h))
        return rrx_out_of_range;
    h->plus(n);
    return rrx_success;
}

RRX_DECORATING RRX_PORTING rrx_status_t RRX_CALLING
rrx_minus(rrx_handle_t h, int n)
{
    if (!inst_map.count(h))
        return rrx_out_of_range;
    h->minus(n);
    return rrx_success;
}

RRX_DECORATING RRX_PORTING rrx_status_t RRX_CALLING
rrx_equals(rrx_handle_t h, int *pn)
{
    if (!pn)
        return rrx_invalid_argument;
    if (!inst_map.count(h))
        return rrx_out_of_range;
    *pn = h->equals();
    return rrx_success;
}

RRX_DECORATING RRX_PORTING rrx_status_t RRX_CALLING
rrx_destruct(rrx_handle_t h)
{
    if (!inst_map.count(h))
        return rrx_out_of_range;
    inst_map.erase(h);
    return rrx_success;
}
