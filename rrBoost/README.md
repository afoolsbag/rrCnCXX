# zhengrr 所知的 Boost                                               {#mainpage}

[*Boost*](https://boost.org/)

## 风格

标准库（`std`）和指导方针支持库（`gsl`）风格命名；
K&R 和 Stroustrup 风格布局；
`.hpp` 和 `.cpp` 风格后缀。

## 指南

*   通过 Conan/CMake-Conan 管理安装和链接
*   手动安装，并使用 CMake 进行链接（Windows）
    1.  访问 Boost 官网，下载源码并解压
    2.  获取 [*zlib*](https://zlib.net/) 源码，解压放入 Boost 目录，假定为 `zlib-1.2.11`
    3.  获取 [*bzip2*](https://sourceware.org/bzip2/) 源码，解压放入 Boost 目录，假定为 `bzip2-1.0.7`
    4.  调用 `bootstrap` 配置 `Boost.Build` 系统
    5.  调用 `.\b2 -sBZIP2_SOURCE="bzip2-1.0.7" -sZLIB_SOURCE="zlib-1.2.11" --build-type=complete` 编译 Boost 库
    6.  设置环境变量 `BOOST_ROOT` 或 `BOOSTROOT`
    7.  通过 CMake 的 `FindBoost` 模块链接使用 Boost 库

## 许可

项目采用 Unlicense 许可，文档采用 CC0-1.0 许可：

<p xmlns:dct="https://purl.org/dc/terms/">
  <a rel="license"
     href="https://creativecommons.org/publicdomain/zero/1.0/">
    <img src="https://licensebuttons.net/p/zero/1.0/88x31.png" style="border-style: none;" alt="CC0" />
  </a>
  <br />
  To the extent possible under law,
  <span resource="[_:publisher]" rel="dct:publisher">
    <span property="dct:title">zhengrr</span></span>
  has waived all copyright and related or neighboring rights to this work.
</p>
