/** \file
 *  \author zhengrr
 *  \date 2017-1-12 – 2018-1-8
 *  \copyright The MIT License */

#ifndef RRCXXLANG_API_HPP_
#define RRCXXLANG_API_HPP_

#if defined(_MSC_VER) || defined(__CYGWIN__)
# define RRCXXLANG_EXPORT_ __declspec(dllexport)
# define RRCXXLANG_IMPORT_ __declspec(dllimport)
# define RRCXXLANG_LOCAL_
#elif 4 <= __GNUC__
# define RRCXXLANG_EXPORT_ __attribute__((visibility("default")))
# define RRCXXLANG_IMPORT_ __attribute__((visibility("default")))
# define RRCXXLANG_LOCAL_ __attribute__((visibility("hidden")))
#else
# define RRCXXLANG_EXPORT_
# define RRCXXLANG_IMPORT_
# define RRCXXLANG_LOCAL_
#endif

#ifdef RRCXXLANG_EXPORTS
# define RRCXXLANG_API RRCXXLANG_EXPORT_
#else
# define RRCXXLANG_API RRCXXLANG_IMPORT_
#endif

#endif//RRCXXLANG_API_HPP_
