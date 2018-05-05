/** \copyright The MIT License */

#define RRC_EXPORTS
#include "lib.h"

#include "cfg.h"

RRC_API void
rrc_get_version(struct rrc_version_t *const version_ptr)
{
	version_ptr->major = RRC_VERSION_MAJOR;
	version_ptr->minor = RRC_VERSION_MINOR;
	version_ptr->patch = RRC_VERSION_PATCH;
	version_ptr->tweak = RRC_VERSION_TWEAK;
}

RRC_API time_t
rrc_sigh(void)
{
	return (time_t)709444800;
}
