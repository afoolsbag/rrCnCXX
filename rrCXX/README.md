# [C++](https://isocpp.org)

[*C++98*](https://iso.org/standard/25845.html)
[*C++03*](https://iso.org/standard/38110.html)
[*C++11*](https://iso.org/standard/50372.html)
[*C++14*](https://iso.org/standard/64029.html)
[*C++17*](https://iso.org/standard/68564.html)

## References

+ ["C++ reference"](http://en.cppreference.com/w/cpp). *cppreference.com*.
+ [*cplusplus.com*](http://cplusplus.com)

## Programming Styles

1. 规则应当有用
2. 易读先于易写
3. 避免危险
4. 避免复杂
5. 留意规模
6. 在且仅在必要时做优化
7. 可选择时，与组内风格保持一致
8. 可选择时，与社区风格保持一致
9. 在任何应当违背规则的地方，违背它

+ [*C++ Core Guidelines*](http://isocpp.github.io/CppCoreGuidelines/)<sub> [*cmn-Hans*](https://github.com/lynnboy/CppCoreGuidelines-zh-CN)</sub>
+ [*Google C++ Style Guide*](https://google.github.io/styleguide/cppguide)<sub> [*cmn-Hans*](http://zh-google-styleguide.readthedocs.org/)</sub>
+ [*LLVM Coding Standards*](https://llvm.org/docs/CodingStandards.html)
+ [*SEI CERT C++ Coding Standard*](https://wiki.sei.cmu.edu/confluence/pages/viewpage.action?pageId=88046682)
+ [*High Integrity C++ Coding Standard*](http://codingstandard.com/)
+ [*C++ Coding Standard*](http://possibility.com/Cpp/CppCodingStandard.html)

Default as C Programming Styles.

### Naming

| Entity Kinds                     | Preview           | Sample                |
|:-------------------------------- |:----------------- |:--------------------- |
| file for class definition        | `UpperCamelCase`  | `CustomClass.hxx`     |
| namespace                        | `all_lower`       | `rrcxx`               |
| typedef                          | `UpperCamelCase`  | `CustomType`          |
| struct/class                     | `UpperCamelCase`  | `CustomClass`         |
| public struct/class field        | `all_lower`       | `.name`               |
| non-public struct/class field    | `all_lower_`      | `.uuid_`              |
| enum                             | `UpperCamelCase`  | `Color`               |
| enumerator                       | `kUpperCamelCase` | `.kRed`               |
| union                            | `UpperCamelCase`  |                       |
| global function                  | `UpperCamelCase`  | `GenerateUuid()`      |
| static member function           | `UpperCamelCase`  | `::ClassUsageCount()` |
| non-static member function       | `lowerCamelCase`  | `.ObjectUsageCount()` |

### Formatting

+ `.hxx` `.cxx`
+ 2 Spaces

### Comments

+ File
  ```cpp
  //===-- File Brief ----------------------------------------------*- C++ -*-===//
  ///
  /// \file
  /// \brief 文件简述。
  /// \details 文件详述。
  ///
  /// \version 2018-03-26
  /// \since 2018-03-26
  /// \authors zhengrr
  /// \copyright The MIT License
  ///
  //===----------------------------------------------------------------------===//
  ```
+ Function
  ```cpp
  /// \brief 功能简述。
  /// \details 功能详述。
  /// \warning 警告。
  ///
  /// \param arg 一个参数。
  /// \returns 返回值。
  ///
  /// \pre 调用前置要求。
  /// \note 调用注意事项。
  /// \post 调用后续处理。
  ///
  /// \version 2018-04-08
  /// \since 2018-02-21
  /// \authors zhengrr-α; zhengrr-β; zhengrr-γ
  ///
  /// OR
  ///
  /// \version 2018-04-08
  /// \authors zhengrr-γ
  /// \remark 当前版本。
  ///
  /// \date 2018-03-12
  /// \authors zhengrr-β
  /// \remark 重要版本更新。
  ///
  /// \since 2018-02-21
  /// \authors zhengrr-α
  /// \remark 诞生啦。
  int func(const int arg);
  ```

## Guides

["C/C++"](http://fffaraz.github.io/awesome-cpp/). *Awesome*.

[*Bjarne Stroustrup's homepage*](http://stroustrup.com/)

["C++必读书籍推荐"](http://bestcbooks.com/recommended-cpp-books/). *计算机书籍控*.

## Groceries

[*Google Test*](https://github.com/google/googletest)

___
<a rel="license" href="http://creativecommons.org/licenses/by/4.0/"><img alt="知识共享许可协议" style="border-width:0" src="https://i.creativecommons.org/l/by/4.0/88x31.png" /></a><br />本作品采用<a rel="license" href="http://creativecommons.org/licenses/by/4.0/">知识共享署名 4.0 国际许可协议</a>进行许可。
