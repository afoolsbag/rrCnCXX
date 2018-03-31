/*===-- Executable ---------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 可执行文件
 *
 * \version 2018-03-31
 * \since 2018-03-30
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lib.h"

int main(int argc, char *argv[])
{
	struct rrc_version_t ver;
	rrc_get_version(&ver);
	printf("version: %hu.%hu.%hu.%hu\n",
	       ver.major, ver.minor, ver.patch, ver.tweak);

	time_t sigh = rrc_sigh();
	printf("whisper: %s", asctime(localtime(&sigh)));

	return EXIT_SUCCESS;
}
