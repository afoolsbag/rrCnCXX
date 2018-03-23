# [C++](https://isocpp.org)

[*C++98*](https://iso.org/standard/25845.html)
[*C++03*](https://iso.org/standard/38110.html)
[*C++11*](https://iso.org/standard/50372.html)
[*C++14*](https://iso.org/standard/64029.html)
[*C++17*](https://iso.org/standard/68564.html)

## References

["C++ reference"](http://en.cppreference.com/w/cpp). *cppreference.com*.

[*cplusplus.com*](http://cplusplus.com)

## Programming Styles

[*Bjarne Stroustrup's C++ Style and Technique FAQ*](http://stroustrup.com/bs_faq2.html)

[*LLVM Coding Standards*](https://llvm.org/docs/CodingStandards.html)

[*Google C++ Style Guide*](https://google.github.io/styleguide/cppguide)<sub> [*cmn-Hans*](http://zh-google-styleguide.readthedocs.org/)</sub>

### Goals of the Style Guide

0. Style rules should pull their weight
0. Optimize for the reader, not the writer
0. ~~Be consistent with existing code~~
0. Be consistent with the broader C++ community when appropriate
0. Avoid surprising or dangerous constructs
0. ~~Avoid constructs that our average C++ programmer would find tricky or hard to maintain~~
0. Be mindful of our scale
0. Concede to optimization when necessary

### Header Files

+ `source.hxx` `source.cxx` `fragment.inc`
+ Self-contained Headers:
  头文件应自给自足，可单独被调用
+ The #pragma once & #define Guard:
  ```cpp
  #pragma once
  #ifndef PROJECT_PATH_FILE_HXX_
  #define PROJECT_PATH_FILE_HXX_
  // ...
  #endif//PROJECT_PATH_FILE_HXX_
  ```
+ Forward Declarations:
  避免使用前置声明
+ Inline Functions:
  经验规律，10行以内函数可内联
+ Names and Order of Includes:
  ```cpp
  #include "source.hxx"

  #include <pthread.h>
  #include <cstdlib>
  #include <vector>

  #include "thirdparty/lib1337.hh"
  #include "src/other.hxx"
  ```

### Scoping

+ Namespaces:
  ```cpp
  namespace prj {
  // ...
  }//namespace prj
  ```
    + 禁止使用Using指令`using namespace`
    + 头文件中谨慎使用命名空间别名`namespace alias`
    + 仅在大型版本控制中使用内联命名空间`inline namespace`
+ Unnamed Namespaces and Static Variables:
  ```cpp
  namespace {
  // ...
  }//namespace
  ```
    + 头文件中谨慎使用文件作用域，源文件中鼓励使用
+ Nonmember, Static Member, and Global Functions
+ Local Variables:
    + 使局部变量作用域尽可能窄
    + 使局部变量声明处距定义处尽可能近，最好声明同时定义
    + 使局部变量定义处距使用处尽可能近，最好定义后立即使用
+ Static and Global Variables:
    + 静态变量泛指全局变量、文件静态变量、静态类属性和函数静态变量
    + 静态变量限定数据类型：原生类型、及其指针、数组或结构体
    + 额外的，类静态属性限定常量表达式`constexpr`
+ `thread_local` Variables

### Classes

### Functions

### Other

### Naming

+ General Naming Rules:
  公开则详细，私有则简略，以尽量简便的形式表达尽量清晰的含义。
+ Folder Names:
  全小写、下划线，`ui`、`net`、`algo`
+ File Names:
    + 一般地，不缩写、全小写、下划线，`config.hxx`、`main.cxx`、`fuzzy_algorithm.cxx`
    + 类定义文件可以类名为名，`FileOfClass.hxx`、`FileOfClass.cxx`
+ Type Names:
  大驼峰，`Player`、`ProPlayer`
+ Variable Names:
    + 一般地，全小写，`user_name`、`username`、`usr`
    + 私有属性，后缀`_`，`catch_size_`
    + 静态变量，前缀`s_`，`s_function_usage_count`，避免使用静态变量
    + 全局变量，前缀`g_`，`g_active_user_count`，避免使用全局变量
+ Constant Names:
    + 此处常量指编译时常量
    + 前缀`k`、小驼峰：`kRed`、`kGreen`、`kBlue`
    + 特别地，静态常量依此例，`kProjectName`
+ Function Names：
    + 函数、类方法，大驼峰：`GeneratePlayerUuid()`
    + 对象方法，小驼峰：`getPlayerName()`
+ Namespace Names:
  不缩写、全小写、下划线：`rrcxx`
+ Enumerator Names:
  同编译时常量
+ Macro Names:
  全大写、下划线，`TESTING_DATA`

### Comments

+ Comment Style:
  尽可能使用`//`和`///`
+ File Comments
+ Class Comments
+ Function Comments
  ```cpp
  /// \brief 功能简述。
  /// \details 功能详述。
  /// \warning 警告。
  ///
  /// \param arg 一个参数。
  /// \returns 输入的值。
  ///
  /// \pre 调用前置要求。
  /// \note 调用注意事项。
  /// \post 调用后续处理。
  ///
  /// \version 2018-03-23
  /// \authors zhengrr-γ
  /// \remark 当前版本。
  ///
  /// \date 2018-02-22
  /// \authors zhengrr-β
  /// \remark 重要版本更新。
  ///
  /// \since 2018-02-21
  /// \authors zhengrr-α
  /// \remark 诞生啦。
  int func(const int arg);
  ```
  其中，`\version`、`\date`和`\since`块内容用于迭代内交流，迭代末当清理：
  ```cpp
  /// \version 2018-03-23
  /// \since 2018-02-21
  /// \authors zhengrr-α; zhengrr-β; zhengrr-γ
  ```
+ Variable Comments
+ Implementation Comments
+ Punctuation, Spelling and Grammar
+ TODO Comments
+ Deprecation Comments

### Formatting

+ Line Length:
  80字符
+ Non-ASCII Characters:
  使用UTF-8编码
+ Spaces vs. Tabs:
  空格，缩进2空格
+ Function Declarations and Definitions
+ Lambda Expressions
+ Function Calls
+ Braced Initializer List Format
+ Conditionals
+ Loops and Switch Statements
+ Pointer and Reference Expressions
+ Boolean Expressions
+ Return Values
+ Variable and Array Initialization
+ Preprocessor Directives
+ Class Format
+ Constructor Initializer Lists
+ Namespace Formatting:
  不缩进
+ Horizontal Whitespace
+ Vertical Whitespace

## Guides

["C/C++"](http://fffaraz.github.io/awesome-cpp/). *Awesome*.

[*Bjarne Stroustrup's homepage*](http://stroustrup.com/)

["C++必读书籍推荐"](http://bestcbooks.com/recommended-cpp-books/). *计算机书籍控*.

## Groceries

[*Google Test*](https://github.com/google/googletest)

___
<a rel="license" href="http://creativecommons.org/licenses/by/4.0/"><img alt="知识共享许可协议" style="border-width:0" src="https://i.creativecommons.org/l/by/4.0/88x31.png" /></a><br />本作品采用<a rel="license" href="http://creativecommons.org/licenses/by/4.0/">知识共享署名 4.0 国际许可协议</a>进行许可。
