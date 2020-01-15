//===-- Preprocessor Structure Filed Reflection -----------------*- C++ -*-===//
///
/// \file
/// \brief 使用 Boost.Preprocessor 实现结构体字段反射。
///
/// \version 2020-01-15
/// \since 2019-12-31
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <array>
#include <functional>
#include <iostream>
#include <string>

#include <boost/mpl/for_each.hpp>
#include <boost/mpl/range_c.hpp>
#include <boost/preprocessor.hpp>
#include <gtest/gtest.h>

using namespace std;

namespace {

struct foobar {
    bool               bool_field;

    char               char_field;
    wchar_t            wchar_field;
    char16_t           char16_field;
    char32_t           char32_field;

    signed char        signed_char_field;
    unsigned char      unsigned_char_field;
    short              signed_short_int_field;
    unsigned short     unsigned_short_int_field;
    int                signed_int_field;
    unsigned           unsigned_int_field;
    long               signed_long_int_field;
    unsigned long      unsigned_long_int_field;
    long long          signed_long_long_int_field;
    unsigned long long unsigned_long_long_int_field;

    float              float_field;
    double             double_field;
    long double        long_double_field;

    std::string        string_field;

#   ifdef ANONYMOUS_FOOBAR_FIELDS
#   error macro naming conflict
#   endif
#   define ANONYMOUS_FOOBAR_FIELDS                                             \
        (bool_field)                                                           \
        (char_field)(wchar_field)(char16_field)(char32_field)                  \
        (signed_char_field)(unsigned_char_field)(signed_short_int_field)       \
            (unsigned_short_int_field)(signed_int_field)(unsigned_int_field)   \
            (signed_long_int_field)(unsigned_long_int_field)                   \
            (signed_long_long_int_field)(unsigned_long_long_int_field)         \
        (float_field)(double_field)(long_double_field)                         \
        (string_field)

    /// \brief 字段数
    static constexpr std::size_t fields_count {BOOST_PP_SEQ_SIZE(ANONYMOUS_FOOBAR_FIELDS)};

    /// \brief 字段名
    static constexpr std::array<const char[32], fields_count> field_names {
#       define macro(r, d, field)                                              \
            BOOST_PP_STRINGIZE(field) ,
            BOOST_PP_SEQ_FOR_EACH(macro, ~, ANONYMOUS_FOOBAR_FIELDS)
#       undef macro
    };

    /// \brief 第 N 个字段引用
    template <std::size_t N>
    auto &field_ref()
    {
        static_assert(N < fields_count);
#       define macro(r, d, i, field)                                           \
        do {                                                                   \
            if constexpr (N == i)                                              \
                return field;                                                  \
        } while (0);
        BOOST_PP_SEQ_FOR_EACH_I(macro, ~, ANONYMOUS_FOOBAR_FIELDS);
#       undef macro
    }

    /// \brief 访问（访问者模式）
    /// \param lhv     左手对象
    /// \param rhv     右手对象
    /// \param visitor 可调用对象，提供形如 `void(const char *field_name, FieldType &lhv_field_ref, FieldType &rhv_field_ref)` 的调用方法
    template <typename VisitorType>
    static void visit(foobar &lhv, foobar &rhv, VisitorType &&visitor)
    {
        using fields_range = boost::mpl::range_c<std::size_t, 0, fields_count>;
        boost::mpl::for_each<fields_range>(
            std::bind(
                [](foobar &lhv, foobar &rhv, VisitorType &visitor, auto n) { using N = decltype(n); visitor(field_names[N::value], lhv.field_ref<N::value>(), rhv.field_ref<N::value>()); },
                std::ref(lhv),
                std::ref(rhv),
                std::ref(visitor),
                std::placeholders::_1));
    }

    /// \brief 访问（访问者模式）
    /// \param obj     对象
    /// \param visitor 可调用对象，提供形如 `void(const char *field_name, FieldType &field_ref)` 的调用方法
    template <typename VisitorType>
    static void visit(foobar &obj, VisitorType &&visitor)
    {
        visit(obj, obj, [&](const char *field_name, const auto &field_ref, const auto &) { visitor(field_name, field_ref); });
    }

    /// \brief 由……访问（访问者模式）
    /// \param visitor 可调用对象，提供形如 `void(const char *field_name, FieldType &field_ref)` 的调用方法
    template <typename VisitorType>
    void visit_by(VisitorType &&visitor)
    {
        visit(*this, visitor);
    }
};

}

namespace rrboost {

TEST(preprocessor, structure_field_reflection)
{
    foobar data {};
    data.visit_by([](const char *field_name, const auto &field_ref) {
        cout << field_name << ": " << field_ref << '\n';
    });
}

}

