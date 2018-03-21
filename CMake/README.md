# [CMake](https://cmake.org)

## References

[Reference Documentation](https://cmake.org/cmake/help/latest)
+ [cmake-commands(7)](https://cmake.org/cmake/help/latest/manual/cmake-commands.7)
+ [cmake-language(7)](https://cmake.org/cmake/help/latest/manual/cmake-language.7)
+ [cmake-developer(7)](https://cmake.org/cmake/help/latest/manual/cmake-developer.7)

[Wiki](https://cmake.org/Wiki)
+ [CMake Useful Variables](https://cmake.org/Wiki/CMake_Useful_Variables)

## Programming Styles

+ 变量名
    + 内容必然为字符串，前缀`s`、小驼峰，`sHerName`
    + 内容可能为字符串列表，前缀`z`、小驼峰，`zCountries`
    + 内容必然为变量名，前缀`v`、小驼峰，`sHerNameVar`
    + 内容可能为变量名列表，前缀`w`、小驼峰，`wBuildVars`
+ 变量的引用:
    + 引用`s-`类变量时鼓励括上引号，`"${sHerName}"`，当变量值为空时会被正确理解为空串
    + 对应的，若希望引用空值被直接忽略，则不要使用引号将其括起
    + 引用`v-`类变量时避免括上引号，CMake中标示符不可为空串
    + 引用`z-`类和`w-`类变量避免使用双引号，除非刻意将其字符串化

## Groceries

[*reStructuredText*](http://docutils.sourceforge.net/rst.html)
+ [Quick reStructuredText](http://docutils.sourceforge.net/docs/user/rst/quickref.html)
+ [*Online reStructuredText editor*](http://rst.ninjs.org/)

___
<a rel="license" href="http://creativecommons.org/licenses/by/4.0/"><img alt="知识共享许可协议" style="border-width:0" src="https://i.creativecommons.org/l/by/4.0/88x31.png" /></a><br />本作品采用<a rel="license" href="http://creativecommons.org/licenses/by/4.0/">知识共享署名 4.0 国际许可协议</a>进行许可。
