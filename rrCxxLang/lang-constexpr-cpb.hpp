/** \file
 *  \brief C++ constexpr 兼容性。
 *  \author zhengrr
 *  \date 2017-1-12
 *  \copyright The MIT License
 */
#ifndef RRDEMO__CDOM__CPP_LIBRARY__LANG_CONSTEXPR_CPB_HPP
#define RRDEMO__CDOM__CPP_LIBRARY__LANG_CONSTEXPR_CPB_HPP

#if !(201103L <= __cplusplus) && \
    !(defined __GNUC__ && (4 < __GNUC__ || 4 == __GNUC__ && 6 <= __GNUC_MINOR__)) && \
    !(defined _MSC_VER && 1900 <= _MSC_VER)
/// 编译器不支持 `constexpr`，采用兼容处理。
/** 简单地使用 `const` 替代 `constexpr`，失去了诸多特性，仅可作为权宜方案。\n
 *  若于生产环境，需考虑上下文，酌情替换为宏、`const` 或 `inline` 等以模拟原语义。
 *  \warning 此为权宜方案，勿用于生产环境。
 */
# define constexpr const

#endif

#endif// RRDEMO__CDOM__CPP_LIBRARY__LANG_CONSTEXPR_CPB_HPP
