/**
 * copyright Unlicense
 */

#include "rrlibc/rrlibc.h"

#include <string.h>
#include <time.h>

#include "cfg.h"

RRLIBC_APIp enum rrlibc_status_t
RRLIBC_APIm rrlibc_get_version(int *r_major, int *r_minor, int *r_patch, int *r_tweak)
RRLIBC_APIs
{
    if (r_major)
        *r_major = (int)project_version_major;
    if (r_minor)
        *r_minor = (int)project_version_minor;
    if (r_patch)
        *r_patch = (int)project_version_patch;
    if (r_tweak)
        *r_tweak = (int)project_version_tweak;
    return rrlibc_success;
}

RRLIBC_APIp enum rrlibc_status_t
RRLIBC_APIm rrlibc_sigh(time_t *r_time)
RRLIBC_APIs
{
    if (!r_time)
        return rrlibc_invalid_argument;

    struct tm ts;
    memset(&ts, 0x00, sizeof ts);
    ts.tm_year = 1992 - 1900;
    ts.tm_mon = 5 - 1;
    ts.tm_mday = 25;

    const time_t tmp = mktime(&ts);
    if (tmp == -1)
        return rrlibc_overflow_error;

    *r_time = tmp;
    return rrlibc_success;
}
