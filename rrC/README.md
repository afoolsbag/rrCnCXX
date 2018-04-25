# [C](http://open-std.org/jtc1/sc22/wg14/)

*C*(1972)
*K&R C*(1978)
*ANSI C*(1989)
[*C90*](https://iso.org/standard/17782.html)(1990)
[*C99*](https://iso.org/standard/29237.html)(1999)
[*C11*](https://iso.org/standard/57853.html)(2011)

+ ["C (programming language) Uses"](https://wikipedia.org/wiki/C_(programming_language)#Uses). *Wikipedia*.
+ ["Why does C programming suck?"](https://quora.com/Why-does-C-programming-suck). *Quora*.

## References

+ ["C reference"](http://cppreference.com/w/c). *cppreference.com*.
+ ["C Language Reference"](https://docs.microsoft.com/cpp/c-language/c-language-reference). *Microsoft® Docs*.
+ [*The GNU C Reference Manual*](https://gnu.org/software/gnu-c-manual/gnu-c-manual.html)
+ ["C and C++ Language Syntax Reference"](https://cprogramming.com/reference). *Cprogramming.com*.

## Programming Styles

+ [*Linux kernel coding style*](https://github.com/torvalds/linux/blob/master/Documentation/process/coding-style.rst)
+ [*GNU Coding Standards*](https://gnu.org/prep/standards/standards.html)
+ [*SEI CERT C Coding Standard*](https://wiki.sei.cmu.edu/confluence/display/c)
+ [*NGINX coding style*](https://nginx.com/resources/wiki/start/topics/examples/coding_style)
+ [*PostgreSQL Coding Conventions*](https://postgresql.org/docs/current/static/source.html)

### Naming

| Entity Kinds | Preview       |
|:------------ |:------------- |
| folder       | `all_lower`   |
| file         | `all_lower`   |
| macro        | `ALL_UPPER`   |
| typedef      | `all_lower_t` |
| struct       | `all_lower_t` |
| struct field | `all_lower`   |
| enum         | `all_lower_t` |
| enumerator   | `ALL_UPPER`   |
| union        | `all_lower_t` |
| union member | `all_lower`   |
| function     | `all_lower`   |

| l/g          | a/r/t/s/e      | cv               | Preview         |
|:------------ |:-------------- |:---------------- | ---------------:|
| local        | [`auto`]       | [`const`]        |     `all_lower` |
| local        | [`auto`]       | `volatile`       |   `v_all_lower` |
| local        | [`auto`]       | `const volatile` |  `cv_all_lower` |
| local        | `register`     |                  |   `r_all_lower` |
| local        | `thread_local` |                  |   `t_all_lower` |
| local/global | `static`       | `const`          |     `ALL_UPPER` |
| local/global | `static`       |                  |   `s_all_lower` |
| local/global | `static`       | `volatile`       |  `sv_all_lower` |
| local/global | `static`       | `const volatile` | `scv_all_lower` |
| global       | [`extern`]     | `const`          |     `ALL_UPPER` |
| global       | [`extern`]     |                  |   `g_all_lower` |
| global       | [`extern`]     | `volatile`       |  `gv_all_lower` |
| global       | [`extern`]     | `const volatile` | `gcv_all_lower` |

+ 对于数据，倾向于紧凑的命名，`name` `getname(id_t id)`
+ 对于过程，倾向于明确的命名，`cut_off_power_of(device_t device)`

### Formatting

+ `.h` `.c`
+ UTF-8
+ 80 columns × 24 lines
+ 1 tab (8 characters)
+ K&R (functions are special)

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
