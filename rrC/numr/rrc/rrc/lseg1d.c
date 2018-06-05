/** \copyright The MIT License */

#define RRC_EXPORTS
#include "lseg1d.h"

RRC_API struct rrc_lseg1d_t
rrc_lseg1d_and(
	const struct rrc_lseg1d_t l, const struct rrc_lseg1d_t n)
{
	struct rrc_lseg1d_t lhs = l;
	if (lhs.b.x < lhs.a.x) {
		const grad_t tmp = lhs.a.x;
		lhs.a.x = lhs.b.x;
		lhs.b.x = tmp;
	}

	struct rrc_lseg1d_t rhs = n;
	if (rhs.b.x < rhs.a.x) {
		const grad_t tmp = rhs.a.x;
		rhs.a.x = rhs.b.x;
		rhs.b.x = tmp;
	}

	if (rhs.a.x < lhs.a.x) {
		const struct rrc_lseg1d_t tmp = lhs;
		lhs = rhs;
		rhs = tmp;
	}

	if (lhs.b.x < rhs.a.x)
		return (struct rrc_lseg1d_t) {{0}, {0}};
	else if (rhs.b.x < lhs.b.x)
		return rhs;
	else
		return (struct rrc_lseg1d_t) {{rhs.a.x}, {lhs.b.x}};
}
