# [C](http://open-std.org/jtc1/sc22/wg14)

[*C90*](https://iso.org/standard/17782.html)
[*C99*](https://iso.org/standard/29237.html)
[*C11*](https://iso.org/standard/57853.html)

## References

["C reference"](http://cppreference.com/w/c). *cppreference.com*.

["C Language Reference"](https://docs.microsoft.com/cpp/c-language/c-language-reference). *Microsoft® Docs*.

[*The GNU C Reference Manual*](https://gnu.org/software/gnu-c-manual/gnu-c-manual.html)

["C and C++ Language Syntax Reference"](https://cprogramming.com/reference). *Cprogramming.com*.

## Programming Styles

+ 遵循传统
+ 屏幕：80字符×24行
+ 缩进：8空格宽制表符（`Tab`）
+ 命名：以助于辨识和理解
    + 缩写：
      [广为人知](https://wikipedia.org)的应当使用（`tcp` `http`），
      [业内通行](https://abbreviations.com)的可以使用（`cur` `img`），
      自行约定的审慎使用（`fs` `fsys` `file_system`）
    + 全局对象应描述性命名，且仅使用广为人知的缩写（`count_active_users()`）
    + 宏、枚举值、常量：全大写配下划线式（`RED` `GREEN` `BLUE`）
    + 类型、函数、变量：全小写配下划线式（`size_t` `do_something()` `tmp`）
+ 大括号：函数的新起一行，其他的置于行尾
+ 函数：应简短、甜美且专注
    + 宽度一屏内（80字符）
    + 长度两屏内（约50行），长而简明的函数除外（如长长的`switch-case`函数）
    + 晦涩（过长或过深）应考虑重构

[*Linux kernel coding style*](https://github.com/torvalds/linux/blob/master/Documentation/process/coding-style.rst)

[*GNU Coding Standards*](https://gnu.org/prep/standards/standards.html)

[*NGINX coding style*](https://nginx.com/resources/wiki/start/topics/examples/coding_style)

[*PostgreSQL Coding Conventions*](https://postgresql.org/docs/current/static/source.html)

## Guides

["C"](https://notabug.org/koz.ross/awesome-c). *Awesome*.

*C Programming: A Modern Approach.* 1st ed. 1996; [2nd ed.](http://knking.com/books/c2) 2008. K. N. King.
+ *The C Programming Language*. 1st ed. 1978; 2nd ed. 1988. Brian Kernighan; Dennis Ritchie.
+ *Pointers on C*. 1997. Kenneth Reek.
+ *C Traps and Pitfalls*. 1989. Andrew Koenig.
+ *Expert C Programming: Deep C Secrets*. 1994. Peter van der Linden.

## Groceries

[*Check*](https://libcheck.github.io/check)

*C Interfaces and Implementations: Techniques for Creating Reusable Software*. 1997. David R. Hanson.

[*The C Library Reference Guide*](https://www-s.acm.illinois.edu/webmonkeys/book/c_guide). 1997. Eric Huss.

*The Standard C Library*. 1992. P. J. Plauger.

[*Implementing Exceptions in C*](http://hpl.hp.com/techreports/Compaq-DEC/SRC-RR-40.pdf). 1989. Eric. S. Roberts.

___
<a rel="license" href="http://creativecommons.org/licenses/by/4.0/"><img alt="知识共享许可协议" style="border-width:0" src="https://i.creativecommons.org/l/by/4.0/88x31.png" /></a><br />本作品采用<a rel="license" href="http://creativecommons.org/licenses/by/4.0/">知识共享署名 4.0 国际许可协议</a>进行许可。
