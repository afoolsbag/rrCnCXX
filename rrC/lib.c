/** \copyright The MIT License */

#define RRCLANG_EXPORTS
#include "lib.h"

#include "cfg.h"

void rrclang_get_ver(struct rrclang_ver *verptr)
{
	verptr->major = RRCLANG_VER_MAJOR;
	verptr->minor = RRCLANG_VER_MINOR;
	verptr->patch = RRCLANG_VER_PATCH;
	verptr->tweak = RRCLANG_VER_TWEAK;
}

int32_t rrclang_sigh(void)
{
	return 709444800;
}
