/**
 * \file
 * \author zhengrr
 * \date 2017-1-12 – 2018-1-23
 * \copyright The MIT License
 */

#ifndef RRCXXLANG_API_HPP_
#define RRCXXLANG_API_HPP_

#if defined(_MSC_VER) || defined(__CYGWIN__)
# define RRCXXLANG_EXPORT_ __declspec(dllexport)                   ///< 导出（存储类型属性）
# define RRCXXLANG_IMPORT_ __declspec(dllimport)                   ///< 导入（存储类型属性）
# define RRCXXLANG_LOCAL_                                          ///< 本地（存储类型属性）
#elif 4 <= __GNUC__
# define RRCXXLANG_EXPORT_ __attribute__((visibility("default")))  ///< 导出（存储类型属性）
# define RRCXXLANG_IMPORT_ __attribute__((visibility("default")))  ///< 导入（存储类型属性）
# define RRCXXLANG_LOCAL_ __attribute__((visibility("hidden")))    ///< 本地（存储类型属性）
#else
# define RRCXXLANG_EXPORT_                                         ///< 导出（存储类型属性）
# define RRCXXLANG_IMPORT_                                         ///< 导入（存储类型属性）
# define RRCXXLANG_LOCAL_                                          ///< 本地（存储类型属性）
#endif

#ifdef RRCXXLANG_EXPORTS
# define RRCXXLANG_API RRCXXLANG_EXPORT_                           ///< 导出/导入（存储类型属性）
#else
# define RRCXXLANG_API RRCXXLANG_IMPORT_                           ///< 导出/导入（存储类型属性）
#endif

#endif//RRCXXLANG_API_HPP_
