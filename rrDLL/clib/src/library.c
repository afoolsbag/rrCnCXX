/** copyright Unlicense */

#define CLIB_EXPORTS
#include "clib/library.h"

#include "config.h"

CLIB_DECORATING CLIB_IMEXPORT clib_version_t CLIB_CALLING clib_version(void)
{
    clib_version_t v;
    v.major = (int)project_version_major;
    v.minor = (int)project_version_minor;
    v.patch = (int)project_version_patch;
    v.tweak = (int)project_version_tweak;
    return v;
}
