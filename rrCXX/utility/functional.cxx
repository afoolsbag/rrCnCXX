//===-- Functional ----------------------------------------------*- C++ -*-===//
///
/// \defgroup gFunctional 函数对象
/// \ingroup gUtility
///
/// \sa [“函数对象”](https://zh.cppreference.com/w/cpp/utility/functional). *cppreference.com*.
///
/// \version 2019-07-25
/// \since 2019-07-25
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdint>
#include <functional>

#include <gtest/gtest.h>

using namespace std;

namespace rrcxx {
/// \addtogroup gFunctional
/// @{

namespace {
/// \breif just return number
class jrn final {
public:
    static int func_1337() { return 1337; }
    static int func_x(int8_t) { return 8; }
    static int func_x(int16_t) { return 16; }
    static int func_x(int32_t) { return 32; }
    static int func_x(int64_t) { return 64; }

    int meth_1337() { return 1337; }
    int meth_x(int8_t) { return 8; }
    int meth_x(int16_t) { return 16; }
    int meth_x(int32_t) { return 32; }
    int meth_x(int64_t) { return 64; }
};
}

/// \breif 函数对象包装
TEST(functional, function_object_wrapper)
{
    jrn obj;

    const auto func_1337 = function {&jrn::func_1337};
    ASSERT_EQ(1337, func_1337());

    const auto func_8 = function {static_cast<int(*)(int8_t)>(&jrn::func_x)};
    ASSERT_EQ(8, func_8(INT8_MAX));

    const auto meth_1337 = mem_fn(&jrn::meth_1337);
    ASSERT_EQ(1337, meth_1337(obj));

    const auto meth_8 = mem_fn(static_cast<int(jrn::*)(int8_t)>(&jrn::meth_x));
    ASSERT_EQ(8, meth_8(obj, INT8_MAX));
}

namespace {
template<typename R, typename... Ps>
R exception_to_print(const function<R(Ps...)> &func, Ps&&... args)
{
    try {
        return func(std::forward<Ps>(args)...);
    } catch(const exception &e) {
        fprintf(stderr, "a exception occurred: %s", e.what());
    } catch(...) {
        fputs("a unexpected exception occurred", stderr);
    }
}

}

/// \breif 函数调用包装
TEST(functional, function_invoke_wrapper)
{
    //TODO:
    //exception_to_print<int , int>(a);
}

/// @}
}
