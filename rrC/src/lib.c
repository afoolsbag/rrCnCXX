/** \copyright The MIT License */

#define RRC_EXPORTS
#include "rrc/lib.h"

#include "cfg.h"

RRC_API struct rrc_version_t
rrc_version(void)
{
    return (struct rrc_version_t) {
        .major = (uint16_t)RRC_VERSION_MAJOR,
        .minor = (uint16_t)RRC_VERSION_MINOR,
        .patch = (uint16_t)RRC_VERSION_PATCH,
        .tweak = (uint16_t)RRC_VERSION_TWEAK};
}

RRC_API time_t
rrc_sigh(void)
{
    return (time_t)709444800L;
}
