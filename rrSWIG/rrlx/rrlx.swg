//==============================================================================
// [SWIG-4.0 Documentation](http://swig.org/Doc4.0/)
//   [Sections](http://swig.org/Doc4.0/Sections.html)
//   [Contents](http://swig.org/Doc4.0/Contents.html)
//     SWIG Core Documentation
//       [1 Preface](http://swig.org/Doc4.0/Preface.html)
//       [2 Introduction](http://swig.org/Doc4.0/Introduction.html)
//       [3 Getting started on Windows](http://swig.org/Doc4.0/Windows.html)
//
//       [4 Scripting Languages](http://swig.org/Doc4.0/Scripting.html)
//       [5 SWIG Basics](http://swig.org/Doc4.0/SWIG.html)
//
//       [6 SWIG and C++](http://swig.org/Doc4.0/SWIGPlus.html)
//       [7 SWIG and C++11](http://swig.org/Doc4.0/CPlusPlus11.html)
//       [8 SWIG and C++14](http://swig.org/Doc4.0/CPlusPlus14.html)
//       [9 SWIG and C++17](http://swig.org/Doc4.0/CPlusPlus17.html)
//
//       [10 Preprocessing](http://swig.org/Doc4.0/Preprocessor.html)
//       [11 SWIG library](http://swig.org/Doc4.0/Library.html)
//       [12 Argument Handling](http://swig.org/Doc4.0/Arguments.html)
//       [13 Typemaps](http://swig.org/Doc4.0/Typemaps.html)
//       [14 Customization Features](http://swig.org/Doc4.0/Customization.html)
//       [15 Contracts](http://swig.org/Doc4.0/Contract.html)
//       [16 Variable Length Arguments](http://swig.org/Doc4.0/Varargs.html)
//       [17 SWIG and Doxygen Translation](http://swig.org/Doc4.0/Doxygen.html)
//       [18 Warning Messages](http://swig.org/Doc4.0/Warnings.html)
//       [19 Working with Modules](http://swig.org/Doc4.0/Modules.html)
//       [20 Using SWIG with ccache - ccache-swig(1) manpage](http://swig.org/Doc4.0/CCache.html)
//
//     Supported Language Modules Documentation
//       [21 SWIG and Android](http://swig.org/Doc4.0/Android.html)
//       [22 SWIG and C#](http://swig.org/Doc4.0/CSharp.html)
//       23 SWIG and D
//       24 SWIG and Go
//       25 SWIG and Guile
//       [26 SWIG and Java](http://swig.org/Doc4.0/Java.html)
//       27 SWIG and Javascript
//       28 SWIG and Lua
//       29 SWIG and Octave
//       30 SWIG and Perl5
//       31 SWIG and PHP
//       32 SWIG and Python
//       33 SWIG and R
//       34 SWIG and Ruby
//       35 SWIG and Scilab
//       36 SWIG and Tcl
//
//     Experimental Language Modules Documentation
//       37 SWIG and MzScheme/Racket
//       38 SWIG and OCaml
//
//     Developer Documentation
//       39 Extending SWIG to support new languages
//------------------------------------------------------------------------------

// 在 C# 和 Java 中，module 将作为公有静态函数的容器类存在，其命名约定为 UpperCamelCase 样式。
#if defined(SWIGCSHARP) || defined(SWIGJAVA)
%module Rrlx
#else
%module rrlx
#endif

//==============================================================================
// C API WRAPPER

%include <carrays.i>
%include <cpointer.i>
%include <stdint.i>
%include <typemaps.i>

typedef unsigned long size_t;
%{
#include "rrlx/rrlx.h"
%}

#if defined(SWIGJAVA)
%array_class(uint8_t, CUInt8Array)
%pointer_class(size_t, CSize)
#endif

// %rename(TARGET_ID, match$name="SOURCE_ID") "";  <=>  %rename(TARGET_ID) SOURCE_ID;
// %rename("$ignore", match$name="SOURCE_ID") "";  <=>  %rename("$ignore") SOURCE_ID;  <=>  %ignore SOURCE_ID;
//
// %rename("%s",                        ...) "...";
// %rename("%(uppercase)s",             ...) "...";  all_upper        -> ALL_UPPER
// %rename("%(camelcase)s",             ...) "...";  upper_camel_case -> UpperCamelCase
// %rename("%(lowercamelcase)s",        ...) "...";  lower_camel_case -> lowerCamelCase
// %rename("%(undercase)s",             ...) "...";  AllLower         -> all_lower
// %rename("%(schemify)s",              ...) "...";  scheme_case      -> scheme-case
// %rename("%(strip:[PREFIX])s",        ...) "...";
// %rename("%(rsreip:[SUFFIX])s",       ...) "...";
// %rename("%(regex:/PATTERN/SUBST/)s", ...) "...";  SA: https://perldoc.perl.org/perlre.html
//                                                       SWIG 不支持 s/PATTERN/SUBST/g 替换
//
// %rename(..., match="..."                              ) "";  SA: swig.swg § %rename predicates
// %rename(..., match$name="SOURCE_ID"                   ) "";  <=> %rename(...) SOURCE_ID;
// %rename(..., regexmatch$name="SOURCE_ID_REGEXP"       ) "";  <=> %rename(..., regextarget=1) "SOURCE_ID_REGEXP";
// %rename(..., notregexmatch$name="NOT_SOURCE_ID_REGEXP") "";
// %rename(..., fullname=1                               ) "";

// 在 C# 和 Java 中，枚举类型命名约定为 UpperCamelCase 样式。
#if defined(SWIGCSHARP) || defined(SWIGJAVA)
%rename(R"(%(regex:/^rrlx_([^_]+)_t$/\u\1/)s)", %$isenum, regextarget=1, fullname=1) "^rrlx_([^_]+)$";
#endif

// 在 C# 中，枚举项命名约定为 UpperCamelCase 样式；
// 在 Java 中，枚举项命名约定为 ALL_UPPER 样式。
#if defined(SWIGCSHARP)
%rename(R"(%(regex:/^rrlx_([^_]+)$/\u\1/)s)", %$isenumitem, regextarget=1, fullname=1) "^rrlx_([^_]+)$";
%rename(R"(%(regex:/^rrlx_([^_]+)_([^_]+)$/\u\1\u\2/)s)", %$isenumitem, regextarget=1, fullname=1) "^rrlx_([^_]+)_([^_]+)$";
%rename(R"(%(regex:/^rrlx_([^_]+)_([^_]+)_([^_]+)$/\u\1\u\2\u\3/)s)", %$isenumitem, regextarget=1, fullname=1) "^rrlx_([^_]+)_([^_]+)_([^_]+)$";
%rename(R"(%(regex:/^rrlx_([^_]+)_([^_]+)_([^_]+)_([^_]+)$/\u\1\u\2\u\3\u\4/)s)", %$isenumitem, regextarget=1, fullname=1) "^rrlx_([^_]+)_([^_]+)_([^_]+)_([^_]+)$";
#elif defined(SWIGJAVA)
%rename(R"(%(regex:/^rrlx_(.*)$/\U\1\E/)s)", %$isenumitem, regextarget=1, fullname=1) "^rrlx_";
#endif

// 在 C# 中，公有静态成员函数命名约定为 UpperCamelCase 样式；
// 在 Java 中，公有静态成员函数命名约定为 lowerCamelCase 样式。
#if defined(SWIGCSHARP)
%rename(R"(%(regex:/^rrlx_([^_]+)$/\u\1/)s)", %$isglobal, %$isfunction, regextarget=1, fullname=1) "^rrlx_([^_]+)$";
%rename(R"(%(regex:/^rrlx_([^_]+)_([^_]+)$/\u\1\u\2/)s)", %$isglobal, %$isfunction, regextarget=1, fullname=1) "^rrlx_([^_]+)_([^_]+)$";
%rename(R"(%(regex:/^rrlx_([^_]+)_([^_]+)_([^_]+)$/\u\1\u\2\u\3/)s)", %$isglobal, %$isfunction, regextarget=1, fullname=1) "^rrlx_([^_]+)_([^_]+)_([^_]+)$";
%rename(R"(%(regex:/^rrlx_([^_]+)_([^_]+)_([^_]+)_([^_]+)$/\u\1\u\2\u\3\u\4/)s)", %$isglobal, %$isfunction, regextarget=1, fullname=1) "^rrlx_([^_]+)_([^_]+)_([^_]+)_([^_]+)$";
#elif defined(SWIGJAVA)
%rename(R"(%(regex:/^rrlx_([^_]+)$/\l\1/)s)", %$isglobal, %$isfunction, regextarget=1, fullname=1) "^rrlx_([^_]+)$";
%rename(R"(%(regex:/^rrlx_([^_]+)_([^_]+)$/\l\1\u\2/)s)", %$isglobal, %$isfunction, regextarget=1, fullname=1) "^rrlx_([^_]+)_([^_]+)$";
%rename(R"(%(regex:/^rrlx_([^_]+)_([^_]+)_([^_]+)$/\l\1\u\2\u\3/)s)", %$isglobal, %$isfunction, regextarget=1, fullname=1) "^rrlx_([^_]+)_([^_]+)_([^_]+)$";
%rename(R"(%(regex:/^rrlx_([^_]+)_([^_]+)_([^_]+)_([^_]+)$/\l\1\u\2\u\3\u\4/)s)", %$isglobal, %$isfunction, regextarget=1, fullname=1) "^rrlx_([^_]+)_([^_]+)_([^_]+)_([^_]+)$";
#endif

enum rrlx_status_t {
    rrlx_success = 0,
    rrlx_exception,
    rrlx_logic_error,
    rrlx_invalid_argument,
    rrlx_domain_error,
    rrlx_length_error,
    rrlx_out_of_range,
    rrlx_future_error,
    rrlx_bad_optional_access,
    rrlx_runtime_error,
    rrlx_range_error,
    rrlx_overflow_error,
    rrlx_underflow_error,
    rrlx_regex_error,
    rrlx_nonexistent_local_time,
    rrlx_ambiguous_local_time,
    rrlx_tx_exception,
    rrlx_system_error,
    rrlx_ios_base_failure,
    rrlx_filesystem_filesystem_error,
    rrlx_bad_typeid,
    rrlx_bad_cast,
    rrlx_bad_any_cast,
    rrlx_bad_weak_ptr,
    rrlx_bad_function_call,
    rrlx_bad_alloc,
    rrlx_bad_array_new_length,
    rrlx_bad_exception,
    rrlx_bad_variant_access,
    rrlx_internal_error,
    rrlx_unexpected_exception
};

%apply int *OUTPUT { int *r_major };
%apply int *OUTPUT { int *r_minor };
%apply int *OUTPUT { int *r_patch };
%apply int *OUTPUT { int *r_tweak };
enum rrlx_status_t rrlx_get_version(int *r_major, int *r_minor, int *r_patch, int *r_tweak);

typedef struct incomplete_rrlx_t *rrlx_handle_t;
#if defined(SWIGJAVA)
%pointer_class(rrlx_handle_t, CHandle);
#endif

enum rrlx_status_t rrlx_construct(rrlx_handle_t *r_handle);

enum rrlx_status_t rrlx_destruct(rrlx_handle_t handle);

enum rrlx_status_t rrlx_set_basic(rrlx_handle_t handle, int value);

%apply int *OUTPUT { int *r_value };
enum rrlx_status_t rrlx_get_basic(rrlx_handle_t handle, int *r_value);

enum rrlx_status_t rrlx_set_array(rrlx_handle_t handle, const uint8_t *data, size_t size);

%apply size_t *INOUT { size_t *r_size };
enum rrlx_status_t rrlx_get_array(rrlx_handle_t handle, uint8_t *buffer, size_t *r_size);

%apply size_t *OUTPUT { size_t *r_size };
enum rrlx_status_t rrlx_get_array_cvr(rrlx_handle_t handle, const uint8_t *(*r_data), size_t *r_size);

enum rrlx_status_t rrlx_set_string(rrlx_handle_t handle, const char *string);

#if defined(SWIGJAVA)
%rename(StringFsbSize) rrlx_string_fsb_size;
#endif
%constant size_t rrlx_string_fsb_size = 777;

enum rrlx_status_t rrlx_get_string_fsb(rrlx_handle_t handle, char buffer[rrlx_string_fsb_size]);

enum rrlx_status_t rrlx_get_string_cvr(rrlx_handle_t handle, const char *(*r_string));

#if defined(SWIGJAVA)
%rename(Callback) rrlx_callback_t;
#endif
typedef void(*rrlx_callback_t)(void *p_user_data);

enum rrlx_status_t rrlx_set_callback(rrlx_handle_t handle, rrlx_callback_t callback, void *p_user_data);

enum rrlx_status_t rrlx_invoke_callback(rrlx_handle_t handle);

enum rrlx_status_t rrlx_get_last_error_message(rrlx_handle_t handle, char buffer[rrlx_last_error_message_fsb_size]);

//==============================================================================
// C++ API WRAPPER

%include <std_string.i>
%include <std_vector.i>

typedef unsigned long std::size_t;
%{
#include "rrlx/rrlx.hxx"
%}

namespace std {
#if defined(SWIGJAVA)
    %template(UInt8Vector) vector<uint8_t>;
#endif
};

namespace rrlx {

#if defined(SWIGJAVA)
%rename(Version) version_t;
#endif
struct version_t {
    int major;
    int minor;
    int patch;
    int tweak;
};

version_t version();

#if defined(SWIGJAVA)
%rename(Clazz)     clazz;
%rename(setBasic)  clazz::basic(int value);
%rename(getBasic)  clazz::basic() const;
%rename(setArray)  clazz::array(const array_t &value);
%rename(getArray)  clazz::array() const;
%rename(setString) clazz::string(const std::string &value);
%rename(getString) clazz::string() const;
#endif
class clazz {
public:
    explicit clazz();
    clazz(const clazz &) = delete;
    clazz &operator=(const clazz &) = delete;
    clazz(clazz &&) noexcept;
    clazz &operator=(clazz &&) noexcept;
    ~clazz() noexcept;

    void basic(int value);
    int basic() const;

    using array_t = std::vector<uint8_t>;
    void array(const array_t &value);
    const array_t &array() const;

    void string(const std::string &value);
    const std::string &string() const;

    using callback_t = std::function<void(void *)>;
    void set_callback(const callback_t &callback, void *p_user_data);
    void invoke_callback() const;
};

}
