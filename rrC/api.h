/*===-- API Import/Export Macro Definition ---------------------*- C -*-===*//**
 *
 * \file
 * \brief 应用程序接口导入/导出宏定义
 *
 * \author zhengrr
 * \date 2016-8-1 – 2018-2-1
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#ifndef RRC_API_H_
#define RRC_API_H_

#if defined(_MSC_VER) || defined(__CYGWIN__)
# define RRC_EXPORT_ __declspec(dllexport)                   /**< 导出（存储类型属性） */
# define RRC_IMPORT_ __declspec(dllimport)                   /**< 导入（存储类型属性） */
# define RRC_LOCAL_                                          /**< 本地（存储类型属性） */
#elif 4 <= __GNUC__
# define RRC_EXPORT_ __attribute__((visibility("default")))  /**< 导出（存储类型属性） */
# define RRC_IMPORT_ __attribute__((visibility("default")))  /**< 导入（存储类型属性） */
# define RRC_LOCAL_ __attribute__((visibility("hidden")))    /**< 本地（存储类型属性） */
#else
# define RRC_EXPORT_                                         /**< 导出（存储类型属性） */
# define RRC_IMPORT_                                         /**< 导入（存储类型属性） */
# define RRC_LOCAL_                                          /**< 本地（存储类型属性） */
#endif

#ifdef RRCLANG_EXPORTS
# define RRC_API RRC_EXPORT_                                 /**< 导出/导入（存储类型属性） */
#else
# define RRC_API RRC_IMPORT_                                 /**< 导出/导入（存储类型属性） */
#endif

#endif/* RRC_API_H_*/
