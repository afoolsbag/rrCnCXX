/** copyright Unlicense */

#define RRDLL_LWIC_EXPORTS
#include "lwic/library.h"

#include <string.h>

#include "config.h"

EXTERN_C
RRDLL_LWIC_API
rrdll_lwic_version_t
APIENTRY
rrdll_lwic_version(void)
{
    rrdll_lwic_version_t v;
    v.major = (int)project_version_major;
    v.minor = (int)project_version_minor;
    v.patch = (int)project_version_patch;
    v.tweak = (int)project_version_tweak;
    return v;
}
