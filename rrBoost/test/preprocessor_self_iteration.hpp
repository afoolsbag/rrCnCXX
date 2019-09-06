//===-- Preprocessor Self Iteration -----------------------------*- C++ -*-===//
///
/// \file
/// \brief 复杂宏的自包含迭代。
/// \details 该文件通过预处理，生成形如：
///          \code{.cpp}
///          constexpr int sample0 { 0 };
///          constexpr int sample1 { 1 };
///          constexpr int sample2 { 2 };
///          constexpr int sample3 { 3 };
///          constexpr int sample4 { 4 };
///          constexpr int sample5 { 5 };
///          constexpr int sample6 { 6 };
///          constexpr int sample7 { 7 };
///          constexpr int sample8 { 8 };
///          constexpr int sample9 { 9 };
///          \endcode
///          的模板。
///
/// \version 2019-09-06
/// \since 2019-09-05
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

//==============================================================================
#ifndef BOOST_PP_IS_ITERATING

#ifndef PREPROCESSOR_SELF_ITERATION_HPP_
#define PREPROCESSOR_SELF_ITERATION_HPP_

#include <boost/preprocessor.hpp>

#ifndef SAMPLE_MAX
#define SAMPLE_MAX 10
#endif

#define BOOST_PP_ITERATION_PARAMS_1 (3, (0, SAMPLE_MAX, "preprocessor_self_iteration.hpp"))
#include BOOST_PP_ITERATE()

#endif

//==============================================================================
#else

#define k BOOST_PP_ITERATION_START()
#define n BOOST_PP_ITERATION()
#define j BOOST_PP_ITERATION_FINISH()

constexpr int BOOST_PP_CAT(sample, n) { n };

#undef j
#undef n
#undef k

#endif
