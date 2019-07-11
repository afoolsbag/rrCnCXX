# zhengrr 所知的 Avro                                                {#mainpage}

[*Apache Avro*](https://avro.apache.org/)，一种数据序列化框架。

## 风格

大驼峰式命名；
`.hh` 和 `.cc` 风格后缀。

## 指南

*   手动安装，并使用 CMake 进行链接（Windows）
    1.  安装 Boost 库
    2.  访问 Avro 官网，下载 avro-cpp 源码并解压
    3.  使用 CMake 编译安装 avro-cpp 并编入对应目录（如 `vc141x64d`）
    4.  设置环境变量 `AvroCpp_ROOT`
    5.  通过 rrCMake 的 `FindAvroCpp` 模块链接使用 avro-cpp 库

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
