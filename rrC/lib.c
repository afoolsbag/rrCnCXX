/** \copyright The MIT License */

#define RRC_EXPORTS
#include "lib.h"

#include "cfg.h"

void rrc_get_ver(struct rrc_ver *const pver)
{
	pver->major = RRC_VERSION_MAJOR;
	pver->minor = RRC_VERSION_MINOR;
	pver->patch = RRC_VERSION_PATCH;
	pver->tweak = RRC_VERSION_TWEAK;
}

time_t rrc_sigh(void)
{
	return (time_t)709444800;
}
