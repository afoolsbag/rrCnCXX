#ifndef SWIG
// [SWIG-4.0 Documentation](http://swig.org/Doc4.0/)
// [Sections](http://swig.org/Doc4.0/Sections.html)
// [Contents](http://swig.org/Doc4.0/Contents.html)

//==============================================================================
// [4 Scripting Languages](http://swig.org/Doc4.0/Scripting.html)
// [4.1 The two language view of the world](http://swig.org/Doc4.0/Scripting.html#Scripting_nn2)
// [4.2 How does a scripting language talk to C?](http://swig.org/Doc4.0/Scripting.html#Scripting_nn3)
// [4.3 Building scripting language extensions](http://swig.org/Doc4.0/Scripting.html#Scripting_nn9)

//==============================================================================
// [5 SWIG Basics](http://swig.org/Doc4.0/SWIG.html)
//------------------------------------------------------------------------------
// [5.2 Wrapping Simple C Declarations](http://swig.org/Doc4.0/SWIG.html#SWIG_nn9)
// [5.2.1 Basic Type Handling](http://swig.org/Doc4.0/SWIG.html#SWIG_nn10)
bool;
signed char;
unsigned char;
short;
unsigned short;
int;
unsigned;
long;
unsigned long;
float;
double;
//long double;
// [5.2.2 Global Variables](http://swig.org/Doc4.0/SWIG.html#SWIG_nn11)
// [5.2.3 Constants](http://swig.org/Doc4.0/SWIG.html#SWIG_nn12)
// [5.2.4 A brief word about const](http://swig.org/Doc4.0/SWIG.html#SWIG_nn13)
// [5.2.5 A cautionary tale of char *](http://swig.org/Doc4.0/SWIG.html#SWIG_nn14)
//------------------------------------------------------------------------------
// [5.3 Pointers and complex objects](http://swig.org/Doc4.0/SWIG.html#SWIG_nn15)
// [5.3.1 Simple pointers](http://swig.org/Doc4.0/SWIG.html#SWIG_nn16)
// [5.3.2 Run time pointer type checking](http://swig.org/Doc4.0/SWIG.html#SWIG_nn17)
// [5.3.3 Derived types, structs, and classes](http://swig.org/Doc4.0/SWIG.html#SWIG_nn18)
// [5.3.4 Undefined datatypes](http://swig.org/Doc4.0/SWIG.html#SWIG_nn19)
// [5.3.5 Typedef](http://swig.org/Doc4.0/SWIG.html#SWIG_nn20)
//------------------------------------------------------------------------------
// [5.4 Other Practicalities](http://swig.org/Doc4.0/SWIG.html#SWIG_nn21)
// [5.4.1 Passing structures by value](http://swig.org/Doc4.0/SWIG.html#SWIG_nn22)
// [5.4.2 Return by value](http://swig.org/Doc4.0/SWIG.html#SWIG_nn23)
// [5.4.3 Linking to structure variables](http://swig.org/Doc4.0/SWIG.html#SWIG_nn24)
// [5.4.4 Linking to char *](http://swig.org/Doc4.0/SWIG.html#SWIG_nn25)
// [5.4.5 Arrays](http://swig.org/Doc4.0/SWIG.html#SWIG_nn26)
// [5.4.6 Creating read-only variables](http://swig.org/Doc4.0/SWIG.html#SWIG_readonly_variables)
// [5.4.7 Renaming and ignoring declarations](http://swig.org/Doc4.0/SWIG.html#SWIG_rename_ignore)
// [5.4.8 Default/optional arguments](http://swig.org/Doc4.0/SWIG.html#SWIG_default_args)
// [5.4.9 Pointers to functions and callbacks](http://swig.org/Doc4.0/SWIG.html#SWIG_nn30)
//------------------------------------------------------------------------------
// [5.5 Structures and unions](http://swig.org/Doc4.0/SWIG.html#SWIG_nn31)
// [5.5.1 Typedef and structures](http://swig.org/Doc4.0/SWIG.html#SWIG_nn32)
// [5.5.2 Character strings and structures](http://swig.org/Doc4.0/SWIG.html#SWIG_nn33)
// [5.5.3 Array members](http://swig.org/Doc4.0/SWIG.html#SWIG_nn34)
// [5.5.4 Structure data members](http://swig.org/Doc4.0/SWIG.html#SWIG_structure_data_members)
// [5.5.5 C constructors and destructors](http://swig.org/Doc4.0/SWIG.html#SWIG_nn36)
// [5.5.6 Adding member functions to C structures](http://swig.org/Doc4.0/SWIG.html#SWIG_adding_member_functions)
// [5.5.7 Nested structures](http://swig.org/Doc4.0/SWIG.html#SWIG_nested_structs)
// [5.5.8 Other things to note about structure wrapping](http://swig.org/Doc4.0/SWIG.html#SWIG_nn39)
//------------------------------------------------------------------------------
// [5.6 Code Insertion](http://swig.org/Doc4.0/SWIG.html#SWIG_nn40)
// [5.6.1 The output of SWIG](http://swig.org/Doc4.0/SWIG.html#SWIG_nn41)
// [5.6.2 Code insertion blocks](http://swig.org/Doc4.0/SWIG.html#SWIG_nn42)
// [5.6.3 Inlined code blocks](http://swig.org/Doc4.0/SWIG.html#SWIG_nn43)
// [5.6.4 Initialization blocks](http://swig.org/Doc4.0/SWIG.html#SWIG_nn44)
//------------------------------------------------------------------------------
// [5.7 An Interface Building Strategy](http://swig.org/Doc4.0/SWIG.html#SWIG_nn45)
// [5.7.1 Preparing a C program for SWIG](http://swig.org/Doc4.0/SWIG.html#SWIG_nn46)
// [5.7.2 The SWIG interface file](http://swig.org/Doc4.0/SWIG.html#SWIG_nn47)
// [5.7.3 Why use separate interface files?](http://swig.org/Doc4.0/SWIG.html#SWIG_nn48)
// [5.7.4 Getting the right header files](http://swig.org/Doc4.0/SWIG.html#SWIG_nn49)
// [5.7.5 What to do with main()](http://swig.org/Doc4.0/SWIG.html#SWIG_nn50)

//==============================================================================
// [6 SWIG and C++](http://swig.org/Doc4.0/SWIGPlus.html)

//==============================================================================
// [7 SWIG and C++11](http://swig.org/Doc4.0/CPlusPlus11.html)

//==============================================================================
// [8 SWIG and C++14](http://swig.org/Doc4.0/CPlusPlus14.html)

//==============================================================================
// [9 SWIG and C++17](http://swig.org/Doc4.0/CPlusPlus17.html)

//==============================================================================
// [10 Preprocessing](http://swig.org/Doc4.0/Preprocessor.html)

//==============================================================================
// [11 SWIG library](http://swig.org/Doc4.0/Library.html)
//------------------------------------------------------------------------------
// [11.1 The %include directive and library search path](http://swig.org/Doc4.0/Library.html#Library_nn2)
//------------------------------------------------------------------------------
// [11.2 C arrays and pointers](http://swig.org/Doc4.0/Library.html#Library_nn3)
// [11.2.1 cpointer.i](http://swig.org/Doc4.0/Library.html#Library_nn4)
%include <cpointer.i>
%pointer_functions(int, intptr);
%pointer_class(int, intptr);
// [11.2.2 carrays.i](http://swig.org/Doc4.0/Library.html#Library_carrays)
%include <carrays.i>
%array_functions(int, intarr);
%array_class(int, intarr);
// [11.2.3 cmalloc.i](http://swig.org/Doc4.0/Library.html#Library_nn6)
// [11.2.4 cdata.i](http://swig.org/Doc4.0/Library.html#Library_nn7)
//------------------------------------------------------------------------------
// [11.3 C string handling](http://swig.org/Doc4.0/Library.html#Library_nn8)
// [11.3.1 Default string handling](http://swig.org/Doc4.0/Library.html#Library_nn9)
// [11.3.2 Passing binary data](http://swig.org/Doc4.0/Library.html#Library_nn10)
// [11.3.3 Using %newobject to release memory](http://swig.org/Doc4.0/Library.html#Library_nn11)
// [11.3.4 cstring.i](http://swig.org/Doc4.0/Library.html#Library_nn12)
//------------------------------------------------------------------------------
// [11.4 STL/C++ library](http://swig.org/Doc4.0/Library.html#Library_stl_cpp_library)
// [11.5 Utility Libraries](http://swig.org/Doc4.0/Library.html#Library_nn16)

//==============================================================================
// [12 Argument Handling](http://swig.org/Doc4.0/Arguments.html)
//------------------------------------------------------------------------------
// [12.1 The typemaps.i library](http://swig.org/Doc4.0/Arguments.html#Arguments_nn2)
// [12.1.1 Introduction](http://swig.org/Doc4.0/Arguments.html#Arguments_nn3)
// [12.1.2 Input parameters](http://swig.org/Doc4.0/Arguments.html#Arguments_nn4)
// [12.1.3 Output parameters](http://swig.org/Doc4.0/Arguments.html#Arguments_nn5)
// [12.1.4 Input/Output parameters](http://swig.org/Doc4.0/Arguments.html#Arguments_nn6)
// [12.1.5 Using different names](http://swig.org/Doc4.0/Arguments.html#Arguments_nn7)
//------------------------------------------------------------------------------
// [12.2 Applying constraints to input values](http://swig.org/Doc4.0/Arguments.html#Arguments_nn8)
// [12.2.1 Simple constraint example](http://swig.org/Doc4.0/Arguments.html#Arguments_nn9)
// [12.2.2 Constraint methods](http://swig.org/Doc4.0/Arguments.html#Arguments_nn10)
// [12.2.3 Applying constraints to new datatypes](http://swig.org/Doc4.0/Arguments.html#Arguments_nn11)

//==============================================================================
// [13 Typemaps](http://swig.org/Doc4.0/Typemaps.html)

//==============================================================================
// [14 Customization Features](http://swig.org/Doc4.0/Customization.html)

//==============================================================================
// [15 Contracts](http://swig.org/Doc4.0/Contract.html)

//==============================================================================
// [16 Variable Length Arguments](http://swig.org/Doc4.0/Varargs.html)

//==============================================================================
// [17 SWIG and Doxygen Translation](http://swig.org/Doc4.0/Doxygen.html)

//==============================================================================
// [18 Warning Messages](http://swig.org/Doc4.0/Warnings.html)

//==============================================================================
// [19 Working with Modules](http://swig.org/Doc4.0/Modules.html)

//==============================================================================
// [21 SWIG and Android](http://swig.org/Doc4.0/Android.html)
// [22 SWIG and C#](http://swig.org/Doc4.0/CSharp.html)
// 23 SWIG and D
// 24 SWIG and Go
// 25 SWIG and Guile
// [26 SWIG and Java](http://swig.org/Doc4.0/Java.html)
// 27 SWIG and Javascript
// 28 SWIG and Lua
// 29 SWIG and Octave
// 30 SWIG and Perl5
// 31 SWIG and PHP
// 32 SWIG and Python
// 33 SWIG and R
// 34 SWIG and Ruby
// 35 SWIG and Scilab
// 36 SWIG and Tcl
// 37 SWIG and MzScheme/Racket
// 38 SWIG and OCaml
// 39 Extending SWIG to support new languages
#endif

%module rrlx

%include <cpointer.i>
%pointer_class(int, intptr);

%{
#include "rrlx/rrlx.h"
%}

/**
 * \brief 状态码。
 */
enum rrlx_status_t {
    rrlx_success = 0,                  /**< 成功 */

    rrlx_exception,                    /**< 标准基异常 */
    rrlx_logic_error,                  /**< 标准逻辑错误：程序内部错误逻辑所导致的可避免错误。 */
    rrlx_invalid_argument,             /**< 标准无效参数：因参数值未被接受而引发的错误。 */
    rrlx_domain_error,                 /**< 标准定义域错误 */
    rrlx_length_error,                 /**< 标准长度错误：试图超出一些对象的实现定义长度极限所导致的错误。 */
    rrlx_out_of_range,                 /**< 标准越界错误：访问试图受定义范围外的元素所带来的错误。 */
    rrlx_future_error,
    rrlx_bad_optional_access,
    rrlx_runtime_error,                /**< 标准运行时错误：源于程序作用域外，且不能轻易预测到的错误。 */
    rrlx_range_error,                  /**< 标准值域错误 */
    rrlx_overflow_error,               /**< 标准算术上溢错误 */
    rrlx_underflow_error,              /**< 标准算术下溢错误 */
    rrlx_regex_error,
    rrlx_nonexistent_local_time,
    rrlx_ambiguous_local_time,
    rrlx_tx_exception,
    rrlx_system_error,                 /**< 标准系统错误 */
    rrlx_ios_base_failure,             /**< 标准输入输出系统错误 */
    rrlx_filesystem_filesystem_error,  /**< 标准文件系统错误 */
    rrlx_bad_typeid,
    rrlx_bad_cast,
    rrlx_bad_any_cast,
    rrlx_bad_weak_ptr,
    rrlx_bad_function_call,
    rrlx_bad_alloc,                    /**< 标准存储分配失败 */
    rrlx_bad_array_new_length,
    rrlx_bad_exception,
    rrlx_bad_variant_access,

    rrlx_internal_error,               /**< 内部错误：可紧接调用 `rrlx_alloc_last_internal_error_zstring` 获取错误信息。 */
    rrlx_unexpected_exception          /**< 不预期的异常：不遵循标准异常或任何已知异常，意料之外的状况。 */
};

enum rrlx_status_t rrlx_get_version(int *r_major, int *r_minor, int *r_patch, int *r_tweak);

typedef struct incomplete_rrlx_t *rrlx_handle_t;

enum rrlx_status_t rrlx_construct(rrlx_handle_t *r_handle);
enum rrlx_status_t rrlx_destruct(rrlx_handle_t handle);
enum rrlx_status_t rrlx_set_basic(rrlx_handle_t handle, int value);
enum rrlx_status_t rrlx_get_basic(rrlx_handle_t handle, int *r_value);
enum rrlx_status_t rrlx_set_array(rrlx_handle_t handle, const uint8_t data[], size_t size);
enum rrlx_status_t rrlx_get_array(rrlx_handle_t handle, uint8_t buffer[], size_t *r_size);
enum rrlx_status_t rrlx_get_array_cvr(rrlx_handle_t handle, const uint8_t *(*r_data), size_t *r_size);
enum rrlx_status_t rrlx_set_string(rrlx_handle_t handle, const char string[]);
enum rrlx_status_t rrlx_get_string_fsb(rrlx_handle_t handle, char buffer[rrlx_string_fsb_size]);
enum rrlx_status_t rrlx_get_string_cvr(rrlx_handle_t handle, const char *(*r_string));

typedef void(*rrlx_callback_t)(void *p_user_data);
enum rrlx_status_t rrlx_set_callback(rrlx_handle_t handle, rrlx_callback_t callback, void *p_user_data);
enum rrlx_status_t rrlx_invoke_callback(rrlx_handle_t handle);

enum rrlx_status_t rrlx_get_last_error_message(rrlx_handle_t handle, char buffer[rrlx_last_error_message_fsb_size]);
