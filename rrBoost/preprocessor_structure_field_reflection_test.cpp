//===-- Preprocessor Structure Filed Reflection -----------------*- C++ -*-===//
///
/// \file
/// \brief 使用 Boost.Preprocessor 实现结构体字段反射。
///
/// \version 2020-01-10
/// \since 2019-12-31
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <iostream>

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

    string             string_field;

#ifdef ANONYMOUS_FOOBAR_FIELDS
#error macro naming conflict
#endif
#define ANONYMOUS_FOOBAR_FIELDS                                                \
    (bool_field)                                                               \
    (char_field)(wchar_field)(char16_field)(char32_field)                      \
    (signed_char_field)(unsigned_char_field)(signed_short_int_field)           \
        (unsigned_short_int_field)(signed_int_field)(unsigned_int_field)       \
        (signed_long_int_field)(unsigned_long_int_field)                       \
        (signed_long_long_int_field)(unsigned_long_long_int_field)             \
    (float_field)(double_field)(long_double_field)                             \
    (string_field)

    /// \brief 由……访问
    /// \details 由访问者遍历访问字段。
    template <typename VisitorType>
    void visit_by(VisitorType &&visitor)
    {
#   define macro(r, d, field)                                                  \
        do {                                                                   \
            visitor(BOOST_PP_STRINGIZE(field), field);                         \
        } while (0);

        BOOST_PP_SEQ_FOR_EACH(macro, ~, ANONYMOUS_FOOBAR_FIELDS);
#   undef macro
    }

};

/// \brief 访问者
constexpr struct print_visitor_type {
    template <typename FieldType>
    void operator()(const char *field_name, const FieldType &field_value) const
    {
        cout << field_name << ": " << field_value << '\n';
    }
} print_visitor;

}

namespace rrboost {

TEST(preprocessor, structure_field_reflection)
{
    foobar data {};
    data.visit_by(print_visitor);
}

}
