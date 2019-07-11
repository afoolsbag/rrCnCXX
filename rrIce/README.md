# zhengrr 所知的 ICE                                                 {#mainpage}

[*ZeroC ICE*](https://zeroc.com/products/ice)，一种远程过程调用框架。

## 参考

[The Slice Language](https://doc.zeroc.com/ice/3.7/the-slice-language)
*   [Slice Compilation](https://doc.zeroc.com/ice/3.7/the-slice-language/slice-compilation)
*   [Slice Source Files](https://doc.zeroc.com/ice/3.7/the-slice-language/slice-source-files)
*   [Lexical Rules](https://doc.zeroc.com/ice/3.7/the-slice-language/lexical-rules)
*   [Modules](https://doc.zeroc.com/ice/3.7/the-slice-language/modules)
*   [Basic Types](https://doc.zeroc.com/ice/3.7/the-slice-language/basic-types)

## 风格

驼峰风格命名；
`.h` 和 `.cpp` 风格后缀。

## 指南

*   手动安装，并使用 CMake 进行链接（Windows）
    1.  访问 ZeroC ICE 官网，下载 `zeroc.ice.*.nupkg` 包并解压
    2.  设置环境变量 `ICE_HOME`
    3.  通过 CMake 的 `FindIce` 模块链接使用 ZeroC ICE 库

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
