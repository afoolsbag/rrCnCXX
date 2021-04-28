# zhengrr 所知的 C 和 C++

一份为 zhengrr 定制化的，关于 C 语言、C++ 语言、以及相关和不那么相关技术的备忘。

## 项目目录结构

```txt
rrCnCxx\ ...............................项目根目录
  CMake\ ...............................CMake 自定义模组，引自 rrCMake 项目
  docs\ ................................文档
  include\ .............................库的私有包装
  rr*\ .................................库的示例项目
  scripts\ .............................系统语言脚本（.sh、.cmd 或 .ps1）
  .gitignore ...........................Git 忽略列表
  .gitmodules ..........................Git 子模块列表
  .gitmodules-update.cmd ...............Git 子模块更新脚本
  CMakeLists.txt .......................CMake 入口
  README.md ............................自述文档
  README* ..............................自述文档所用资源
  UNLICENSE.txt ........................版权声明
```

## Awesome

### C/C++ 构建工具 CMake

``` batch
:: 使用 Scoop 安装 CMake
%USERPROFILE%> scoop install cmake

:: 使用命令行的构建示例
%USERPROFILE%> cmake -G "Visual Studio 16 2019" ^
                     -A "x64" ^
                     -S "." ^
                     -B "build64"

:: 或使用图形界面构建
%USERPROFILE%> cmake-gui
```

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
