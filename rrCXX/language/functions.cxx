//===-- Functions -----------------------------------------------*- C++ -*-===//
///
/// \defgroup gFunctions 函数
/// \ingroup gLanguage
///
/// \sa <https://zh.cppreference.com/w/cpp/language/functions>
///
/// \version 2019-03-11
/// \since 2018-09-20
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <optional>
#include <random>
#include <string>
#include <gsl/gsl>

#include <gtest/gtest.h>

using namespace std;
using namespace gsl;

namespace rrcxx {

/// \addtogroup gFunctions
/// @{

/// \brief 带前置和后置条件。
///
/// \remarks I.5: 说明前条件（如果有）
/// \remarks I.6: 优先使用 `Expects()` 来表达前条件
/// \remarks I.7: 说明后条件
/// \remarks I.8: 优先使用 `Ensures()` 来表达后条件
///
/// \sa [*C++C.G. I.5*](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Ri-pre)
/// \sa [*C++C.G. I.6*](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Ri-expects)
/// \sa [*C++C.G. I.7*](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Ri-post)
/// \sa [*C++C.G. I.8*](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Ri-ensures)
TEST(functions, expects_ensures)
{
    const auto area = [](int width, int height) -> int {
        Expects(0 <= width && 0 <= height);
        const auto area = width * height;
        Ensures(0 <= area);
        return area;
    };

    (void)area(2, 3);
}

/// \brief 返回值和错误。
///
/// \sa \ref sReturnValueAndError
TEST(functions, return_value_error)
{
    random_device dev;
    default_random_engine eng(dev());
    bernoulli_distribution dis;

    // 返回值，无错误
    const auto check_service_available = [&]() noexcept -> bool {
        return dis(eng);
    };

    {
        (void)check_service_available();
    }

    // 返回值，抛错误
    const auto run_service_1 = [&check_service_available]() -> string {
        if (!check_service_available())
            throw runtime_error("service not available");
        return "result from service 1"s;
    };

    {
        try {
            cout << "run_service_1 successful: " << run_service_1() << "\n";
        } catch (const runtime_error &e) {
            cout << "run_service_1 failed: " << e.what() << "\n";
        }
    }

    // 返回值和错误
    const auto run_service_2 = [&check_service_available]() noexcept -> pair<optional<string>, optional<string>> {
        if (!check_service_available())
            return make_pair("service not available"s, nullopt);
        return make_pair(nullopt, "result from service 2"s);
    };

    {
        optional<string> error, value;
        tie(error, value) = run_service_2();
        if (error.has_value()) {
            cout << "run_service_2 failed: " << error.value() << "\n";
        } else {
            cout << "run_service_2 successful." << value.value() << "\n";
        }
    }

    // 改写值，返回错误
    const auto run_service_3 = [&check_service_available](string &r) noexcept -> optional<string> {
        if (!check_service_available())
            return "service not available"s;
        r = "result from service 3"s;
        return nullopt;
    };

    {
        string value;
        const auto error = run_service_3(value);
        if (error.has_value()) {
            cout << "run_service_3 failed: " << error.value() << "\n";
        } else {
            cout << "run_service_3 successful: " << value << "\n";
        }
    }
}

/// @}

}
