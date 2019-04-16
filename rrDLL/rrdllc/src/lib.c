/**
 * copyright Unlicense
 */

#define RRDLLC_EXPORTS
#include "rrdllc/lib.h"

#include <string.h>
#include <time.h>

#include "cfg.h"

RRDLLC_APIp enum rrdllc_status_t
RRDLLC_APIm rrdllc_version(struct rrdllc_version_t *pv)
RRDLLC_APIs
{
    if (!pv)
        return rrdllc_invalid_argument;

    pv->major = (int)project_version_major;
    pv->minor = (int)project_version_minor;
    pv->patch = (int)project_version_patch;
    pv->tweak = (int)project_version_tweak;

    return rrdllc_success;
}

RRDLLC_APIp enum rrdllc_status_t
RRDLLC_APIm rrdllc_sigh(time_t *pt)
RRDLLC_APIs
{
    if (!pt)
        return rrdllc_invalid_argument;

    struct tm ts;
    memset(&ts, 0x00, sizeof ts);
    ts.tm_year = 1992 - 1900;
    ts.tm_mon = 5 - 1;
    ts.tm_mday = 25;

    *pt = mktime(&ts);
    if (*pt == -1)
        return rrdllc_overflow_error;

    return rrdllc_success;
}
