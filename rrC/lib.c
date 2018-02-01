/** \copyright The MIT License */

#define RRCLANG_EXPORTS
#include "lib.h"

#include "cfg.h"

void rrc_get_ver(struct rrc_ver *const pver)
{
	pver->major = RRCLANG_VER_MAJOR;
	pver->minor = RRCLANG_VER_MINOR;
	pver->patch = RRCLANG_VER_PATCH;
	pver->tweak = RRCLANG_VER_TWEAK;
}

time_t rrc_sigh(void)
{
	return (time_t)709444800;
}
