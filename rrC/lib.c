/** \copyright The MIT License */

#define RRC_EXPORTS
#include "lib.h"

#include "cfg.h"

void rrc_get_ver(struct rrc_ver *const ver_ptr)
{
	ver_ptr->major = RRC_VERSION_MAJOR;
	ver_ptr->minor = RRC_VERSION_MINOR;
	ver_ptr->patch = RRC_VERSION_PATCH;
	ver_ptr->tweak = RRC_VERSION_TWEAK;
}

time_t rrc_sigh(void)
{
	return (time_t)709444800;
}
