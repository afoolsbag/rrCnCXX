# [C++](https://isocpp.org/)

[*C++98*](https://iso.org/standard/25845.html)
[*C++03*](https://iso.org/standard/38110.html)
[*C++11*](https://iso.org/standard/50372.html)
[*C++14*](https://iso.org/standard/64029.html)
[*C++17*](https://iso.org/standard/68564.html)

## References

["C++ reference"](http://en.cppreference.com/w/cpp). *cppreference.com*.

[*cplusplus.com*](http://cplusplus.com/)

## Programming Styles

**缩进**：
随意。
不合意？格式化工具，请。

**命名**：
以助辨识、理解和记忆。
过繁妨碍辨识，过简妨碍理解，无歧义不冗余刚刚好。

*缩写*：
[广为人知的](http://wikipedia.org "Wikipedia 可查的")应当使用（如：`TCP` `HTTP`），
[业内通行的](http://Abbreviations.com "Abbreviations 推荐的")可以使用（如：`cur` `img`），
自行约定的谨慎使用（如：`fs`/`fsys`/`file_system`）。

*类型名*：
驼峰式（紧凑、突出内聚感）；
大驼峰（区别于对象）：
`Account` `App` `Session`

*对象名*：
驼峰式（紧凑、突出内聚感）；
小驼峰（区别于类型）；
据环境，可选应用匈牙利式（突出重点）；
常量前置`k`，全局前置`g`，属性后置`_`；
例外的，类型属性采用大驼峰：
`kAdultAge` `gErrorCode` `.birthday_` `.OperationHours_` `kAgeOfAdult` `ageTheLittleOne`

*方法名*：
对象方法采用小驼峰，类型方法采用大驼峰：
`.getId` `.setName` `.doSomething` `.SetUp`

*函数名*：
全小写配下划线（继承自 C）：
`do_something` `make_it_better`

[*Google C++ Style Guide*](https://google.github.io/styleguide/cppguide)<sub> [*cmn-Hans*](http://zh-google-styleguide.readthedocs.org/)</sub>

## Guides

["C/C++"](http://fffaraz.github.io/awesome-cpp/). *Awesome*.

[*Bjarne Stroustrup's homepage*](http://stroustrup.com/)

["C++必读书籍推荐"](http://bestcbooks.com/recommended-cpp-books/). *计算机书籍控*.

## Others

[*Google Test*](https://github.com/google/googletest)
