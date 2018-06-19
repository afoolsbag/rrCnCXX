/** \copyright The MIT License */

#define RRC_EXPORTS
#include "rrclib.h"

#include "rrc/rrccfg.h"

RRC_API struct rrc_version_t
rrc_version(void)
{
	return (struct rrc_version_t) {
		.major = RRC_VERSION_MAJOR,
		.minor = RRC_VERSION_MINOR,
		.patch = RRC_VERSION_PATCH,
		.tweak = RRC_VERSION_TWEAK
	};
}

RRC_API time_t
sigh(void)
{
	return (time_t) 709444800L;
}
