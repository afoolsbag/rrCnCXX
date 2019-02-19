/*===-- Local File Systems -------------------------------------*- C -*-===*//**
 *
 * \defgroup gFileIO 本地文件系统
 * \ingroup gDevelop
 *
 * \sa ["Local File Systems"](https://docs.microsoft.com/windows/desktop/FileIO/). *Microsoft Docs*.
 *     *   Directory Management
 *     *   Disk Management
 *     *   File Management
 *     *   Transactional NTFS (TxF)
 *     *   Volume Management
 *
 * \version 2019-02-19
 * \since 2018-02-05
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once

#include <check.h>

TCase *tcDirectoryManagement(void);

inline Suite *tsFileIO(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tcDirectoryManagement());
    return ts;
}
