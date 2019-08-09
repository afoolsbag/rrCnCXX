# zhengrr 所知的 SWIG                                                {#mainpage}

[*Simplified Wrapper and Interface Generator*](http://swig.org/)

关于 C++ 库的三种导出方式：

*   C 方法
    *   `+` 操作系统范围 C ABI 已形成事实标准；几乎所有现代编程语言都支持与 C 互操作。
    *   `+` 独立的资源管理，不对 CRT 作限制。
    *   `-` 不支持异常。
    *   `-` 手动资源管理。
    *   `-` 繁琐；句柄和方法分离。
    *   `*` 以上缺陷可通过调用语言包装进行改进。
*   C++ 方法
    *   `+` 导出 C++ 类和本地 C++ 类一样使用。
    *   `+` 可以捕获 DLL 引发的异常。
    *   `+` 可缓解大型项目的重建压力。
    *   `+` 有助于项目模块化。
    *   `-` 必须使用相同的动态 CRT。
    *   `-` 必须使用相同的异常配置。
    *   `-` 符号导出将导出类的所有内容。
    *   `-` C++ ABI 尚无事实标准；不与纯 C 兼容。
*   COM 方法
    *   `+` 导出的 C++ 类可以与任何 C++ 编译器一同使用。
    *   `+` 独立的资源管理，不对 CRT 作限制。
    *   `+` 使项目模块化。
    *   `+` 容易转换为 COM 模块。
    *   `-` 手动管理实例的创建和销毁。
    *   `-` 接口类型受限：COM 接口类型限制。
    *   `-` 不与纯 C 兼容。

## 参考

[SWIG Documentation, Papers, and Presentations](http://swig.org/doc.html)

*   [“a.out”](https://wikipedia.org/wiki/A.out). *Wikipedia*.
*   [“Common Object File Format”](https://wikipedia.org/wiki/COFF). *Wikipedia*.
*   [“Executable and Linkable Format”](https://wikipedia.org/wiki/Executable_and_Linkable_Format). *Wikipedia*.
*   [“Mach-O”](https://wikipedia.org/wiki/Mach-O). *Wikipedia*.
*   [“Portable Executable”](https://wikipedia.org/wiki/Portable_Executable). *Wikipedia*.

## 指南

*   手动安装，并使用 CMake 进行链接（Windows）
    1.  访问 SWIG 官网，下载 `swigwin-4.0.0.zip` 包并解压
    2.  设置环境变量 `SWIG_HOME`
    3.  通过 CMake 的 `FindSWIG` 模块链接使用 SWIG 库

/ [“开发人员 SWIG 快速入门”](https://ibm.com/developerworks/cn/aix/library/au-swig/). *IBM Developer*

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
