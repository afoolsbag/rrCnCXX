/**
 * copyright Unlicense
 */

#include "rrc/rrc.h"

#include <stdbool.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include <Windows.h>
#endif

#include "cfg.h"

#ifdef _WIN32
BOOL WINAPI DllMain(_In_ HINSTANCE hinstDLL, _In_ DWORD fdwReason, _In_ LPVOID lpvReserved)
{
    UNREFERENCED_PARAMETER(hinstDLL);
    switch (fdwReason) {
    case DLL_PROCESS_DETACH: {
        const bool is_unloading = lpvReserved == NULL;
        const bool is_terminating = lpvReserved != NULL;
        UNREFERENCED_PARAMETER(is_unloading);
        UNREFERENCED_PARAMETER(is_terminating);
        return TRUE;
    }
    case DLL_PROCESS_ATTACH: {
        const bool is_dynamic_loading = lpvReserved == NULL;
        const bool is_static_loading = lpvReserved != NULL;
        UNREFERENCED_PARAMETER(is_dynamic_loading);
        UNREFERENCED_PARAMETER(is_static_loading);
        return TRUE;
    }
    case DLL_THREAD_ATTACH: {
        return TRUE;
    }
    case DLL_THREAD_DETACH: {
        return TRUE;
    }
    default:
        return FALSE;
    }
}
#endif

#ifdef __linux__
EXTERN_C void __attribute__ ((constructor)) init(void)
{

}
EXTERN_C void __attribute__ ((destructor)) fini(void)
{

}
#endif

EXTERN_C RRC_API enum rrc_status_t CDECL
rrc_get_version(int *r_major, int *r_minor, int *r_patch, int *r_tweak) NOEXCEPT
{
    if (r_major)
        *r_major = (int)project_version_major;
    if (r_minor)
        *r_minor = (int)project_version_minor;
    if (r_patch)
        *r_patch = (int)project_version_patch;
    if (r_tweak)
        *r_tweak = (int)project_version_tweak;
    return rrc_success;
}

EXTERN_C RRC_API enum rrc_status_t CDECL
rrc_sigh(time_t *r_time) NOEXCEPT
{
    if (!r_time)
        return rrc_invalid_argument;

    struct tm ts;
    memset(&ts, 0x00, sizeof ts);
    ts.tm_year = 1992 - 1900;
    ts.tm_mon = 5 - 1;
    ts.tm_mday = 25;

    const time_t tmp = mktime(&ts);
    if (tmp == -1)
        return rrc_overflow_error;

    *r_time = tmp;
    return rrc_success;
}
