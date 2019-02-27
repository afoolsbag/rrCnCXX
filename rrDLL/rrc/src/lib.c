/**
 * copyright Unlicense
 */

#define RRC_EXPORTS
#include "rrc/lib.h"

#include <string.h>
#include <time.h>

#include "cfg.h"

RRC_DECORATING RRC_PORTING enum rrc_status_t RRC_CALLING
rrc_version(struct rrc_version_t *pv)
{
    if (!pv)
        return rrc_invalid_argument;

    pv->major = (int)project_version_major;
    pv->minor = (int)project_version_minor;
    pv->patch = (int)project_version_patch;
    pv->tweak = (int)project_version_tweak;

    return rrc_success;
}

RRC_DECORATING RRC_PORTING enum rrc_status_t RRC_CALLING
rrc_sigh(time_t *pt)
{
    if (!pt)
        return rrc_invalid_argument;

    struct tm ts;
    memset(&ts, 0x00, sizeof ts);
    ts.tm_year = 1992 - 1900;
    ts.tm_mon = 5 - 1;
    ts.tm_mday = 25;

    *pt = mktime(&ts);
    if (*pt == -1)
        return rrc_overflow_error;

    return rrc_success;
}
