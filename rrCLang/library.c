/** \copyright The MIT License */

#define RRCLANG_EXPORTS
#include "library.h"

#include "config.h"

void rrclang_get_version(struct rrclang_version *verptr)
{
	verptr->major = RRCLANG_VERSION_MAJOR;
	verptr->minor = RRCLANG_VERSION_MINOR;
	verptr->patch = RRCLANG_VERSION_PATCH;
	verptr->tweak = RRCLANG_VERSION_TWEAK;
}

int32_t rrclang_sigh()
{
	return 709444800;
}
