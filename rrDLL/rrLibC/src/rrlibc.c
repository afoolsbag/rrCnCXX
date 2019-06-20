/**
 * copyright Unlicense
 */

#include "rrlibc/rrlibc.h"

#include <string.h>
#include <time.h>

#include "cfg.h"

RRLIBC_APIp enum rrlibc_status_t
RRLIBC_APIm rrlibc_get_version(int *ref_major, int *ref_minor, int *ref_patch, int *ref_tweak)
RRLIBC_APIs
{
    if (ref_major)
        *ref_major = (int)project_version_major;
    if (ref_minor)
        *ref_minor = (int)project_version_minor;
    if (ref_patch)
        *ref_patch = (int)project_version_patch;
    if (ref_tweak)
        *ref_tweak = (int)project_version_tweak;
    return rrlibc_success;
}

RRLIBC_APIp enum rrlibc_status_t
RRLIBC_APIm rrlibc_sigh(time_t *ref_time)
RRLIBC_APIs
{
    if (!ref_time)
        return rrlibc_invalid_argument;

    struct tm ts;
    memset(&ts, 0x00, sizeof ts);
    ts.tm_year = 1992 - 1900;
    ts.tm_mon = 5 - 1;
    ts.tm_mday = 25;

    const time_t tmp = mktime(&ts);
    if (tmp == -1)
        return rrlibc_overflow_error;

    *ref_time = tmp;
    return rrlibc_success;
}
