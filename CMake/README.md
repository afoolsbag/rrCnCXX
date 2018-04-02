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
    + 内容为字符串，前缀`s`、小驼峰，`sHerName`
    + 内容为字符串列表，前缀`z`、小驼峰，`zCountries`
    + 内容为变量名，前缀`v`、小驼峰，`vHerNameVar`
    + 内容为变量名列表，前缀`w`、小驼峰，`wBuildVars`
+ 变量的引用
    + 引用字符串变量（`s-`）建议括上引号`"${sHerName}"`，空值会被正确解析为空串`""`
    + 相对的，若希望忽略空值，则不要括起`${sOptionalProperty}`
    + 引用变量名变量（`v-`）无需引号，不具名符号没有意义
    + 引用列表变量（`z-`、`w-`）避免扩上引号，除非刻意将列表字符串化

## Groceries

[*reStructuredText*](http://docutils.sourceforge.net/rst.html)
+ [Quick reStructuredText](http://docutils.sourceforge.net/docs/user/rst/quickref.html)
+ [*Online reStructuredText editor*](http://rst.ninjs.org/)

___
<a rel="license" href="http://creativecommons.org/licenses/by/4.0/"><img alt="知识共享许可协议" style="border-width:0" src="https://i.creativecommons.org/l/by/4.0/88x31.png" /></a><br />本作品采用<a rel="license" href="http://creativecommons.org/licenses/by/4.0/">知识共享署名 4.0 国际许可协议</a>进行许可。
