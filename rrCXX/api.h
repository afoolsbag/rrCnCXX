/**
 * \file
 * \brief API import/export macro definition
 * \details 应用程序接口导入/导出宏定义。
 * \author zhengrr
 * \date 2017-1-12 – 2018-2-1
 * \copyright The MIT License
 */

#ifndef RRCXX_API_H_
#define RRCXX_API_H_

#if defined(_MSC_VER) || defined(__CYGWIN__)
# define RRCXX_EXPORT_ __declspec(dllexport)                   /**< 导出（存储类型属性） */
# define RRCXX_IMPORT_ __declspec(dllimport)                   /**< 导入（存储类型属性） */
# define RRCXX_LOCAL_                                          /**< 本地（存储类型属性） */
#elif 4 <= __GNUC__
# define RRCXX_EXPORT_ __attribute__((visibility("default")))  /**< 导出（存储类型属性） */
# define RRCXX_IMPORT_ __attribute__((visibility("default")))  /**< 导入（存储类型属性） */
# define RRCXX_LOCAL_ __attribute__((visibility("hidden")))    /**< 本地（存储类型属性） */
#else
# define RRCXX_EXPORT_                                         /**< 导出（存储类型属性） */
# define RRCXX_IMPORT_                                         /**< 导入（存储类型属性） */
# define RRCXX_LOCAL_                                          /**< 本地（存储类型属性） */
#endif

#ifdef RRCXX_EXPORTS
# define RRCXX_API RRCXX_EXPORT_                               /**< 导出/导入（存储类型属性） */
#else
# define RRCXX_API RRCXX_IMPORT_                               /**< 导出/导入（存储类型属性） */
#endif

#endif/* RRCXX_API_H_*/
