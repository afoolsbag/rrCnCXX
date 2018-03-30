/*===-- Executable ---------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 可执行文件
 *
 * \version 2018-03-30
 * \since 2018-03-30
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#include <stdio.h>
#include <stdlib.h>

#include "lib.h"

int main(int argc, char *argv[])
{
	struct rrc_version_t pver;
	rrc_get_version(&pver);

	printf("version: %d.%d.%d.%d",
	       pver.major, pver.minor, pver.patch, pver.tweak);

	return EXIT_SUCCESS;
}
