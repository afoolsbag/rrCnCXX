/**
 * \file
 * \author zhengrr
 * \date 2016-8-1 – 2018-1-15
 * \copyright The MIT License
 */

#ifndef RRCLANG_API_H_
#define RRCLANG_API_H_

#if defined(_MSC_VER) || defined(__CYGWIN__)
# define RRCLANG_EXPORT_ __declspec(dllexport)
# define RRCLANG_IMPORT_ __declspec(dllimport)
# define RRCLANG_LOCAL_
#elif 4 <= __GNUC__
# define RRCLANG_EXPORT_ __attribute__((visibility("default")))
# define RRCLANG_IMPORT_ __attribute__((visibility("default")))
# define RRCLANG_LOCAL_ __attribute__((visibility("hidden")))
#else
# define RRCLANG_EXPORT_
# define RRCLANG_IMPORT_
# define RRCLANG_LOCAL_
#endif

#ifdef RRCLANG_EXPORTS
# define RRCLANG_API RRCLANG_EXPORT_
#else
# define RRCLANG_API RRCLANG_IMPORT_
#endif

#endif/* RRCLANG_API_H_*/
