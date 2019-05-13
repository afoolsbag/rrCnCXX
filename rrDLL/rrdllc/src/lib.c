/**
 * copyright Unlicense
 */

#include "rrdllc/lib.h"

#include <string.h>
#include <time.h>

#include "cfg.h"

RRDLLC_APIp rrdllc_status_t
RRDLLC_APIm rrdllc_version(rrdllc_version_t *rv)
RRDLLC_APIs
{
    if (!rv)
        return rrdllc_invalid_argument;

    (*rv).major = (int)project_version_major;
    (*rv).minor = (int)project_version_minor;
    (*rv).patch = (int)project_version_patch;
    (*rv).tweak = (int)project_version_tweak;

    return rrdllc_success;
}

RRDLLC_APIp rrdllc_status_t
RRDLLC_APIm rrdllc_sigh(time_t *rt)
RRDLLC_APIs
{
    if (!rt)
        return rrdllc_invalid_argument;

    struct tm ts;
    memset(&ts, 0x00, sizeof ts);
    ts.tm_year = 1992 - 1900;
    ts.tm_mon = 5 - 1;
    ts.tm_mday = 25;

    const time_t tmp = mktime(&ts);
    if (tmp == -1)
        return rrdllc_overflow_error;

    (*rt) = tmp;
    return rrdllc_success;
}
