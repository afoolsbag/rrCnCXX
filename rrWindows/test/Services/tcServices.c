#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include <check.h>

#include "rrWindows/rrWindows.h"
#include "tsServices.h"

/**
 * \addtogroup gServices
 * @{
 */

/**
 * @}
 */

TCase *tcServices(void)
{
    TCase *const tc = tcase_create(__func__);
    return tc;
}
