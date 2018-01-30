/**
 * \file
 * \brief API import/export macro definition
 * \details 应用程序接口导入/导出宏定义。
 * \author zhengrr
 * \date 2016-8-1 – 2018-1-30
 * \copyright The MIT License
 */

#ifndef RRCLANG_API_H_
#define RRCLANG_API_H_

#if defined(_MSC_VER) || defined(__CYGWIN__)
# define RRCLANG_EXPORT_ __declspec(dllexport)                   /**< 导出（存储类型属性） */
# define RRCLANG_IMPORT_ __declspec(dllimport)                   /**< 导入（存储类型属性） */
# define RRCLANG_LOCAL_                                          /**< 本地（存储类型属性） */
#elif 4 <= __GNUC__
# define RRCLANG_EXPORT_ __attribute__((visibility("default")))  /**< 导出（存储类型属性） */
# define RRCLANG_IMPORT_ __attribute__((visibility("default")))  /**< 导入（存储类型属性） */
# define RRCLANG_LOCAL_ __attribute__((visibility("hidden")))    /**< 本地（存储类型属性） */
#else
# define RRCLANG_EXPORT_                                         /**< 导出（存储类型属性） */
# define RRCLANG_IMPORT_                                         /**< 导入（存储类型属性） */
# define RRCLANG_LOCAL_                                          /**< 本地（存储类型属性） */
#endif

#ifdef RRCLANG_EXPORTS
# define RRCLANG_API RRCLANG_EXPORT_                             /**< 导出/导入（存储类型属性） */
#else
# define RRCLANG_API RRCLANG_IMPORT_                             /**< 导出/导入（存储类型属性） */
#endif

#endif/* RRCLANG_API_H_*/
