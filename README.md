# zhengrr 所知的 C 和 C++

一份为 zhengrr 定制化的，关于 C 语言、C++ 语言、以及相关和不那么相关技术的备忘。

## 挑选趁手的家伙

> Everyone knows it's a mistake to write your whole program by hand in machine language.
> What's less often understood is that there is a more general principle here:
> that if you have a choice of several languages, it is, all other things being equal, a mistake to program in anything but the most powerful one.
>
> [*Beating the Averages*](http://paulgraham.com/avg.html). April 2001, rev. April 2003.

> [![Which Programming Language Should I Learn First?](./README-IMG.png)](http://carlcheo.com/startcoding "Which Programming Language Should I Learn First?")

## 项目目录结构

```text
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

## 常用链接

### 写作

**句法**
| [*Jupyter*](https://jupyter.org/)
| [*Markdown*](https://daringfireball.net/markdown/) <sub>
      [*cheatsheet*](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet) </sub>
| [*reStructuredText*](http://docutils.sourceforge.net/rst.html)
| UML <sub>
      [*WhiteStarUML*](http://whitestaruml.sourceforge.net/) </sub>

**字符**
| ASCII Art <sub>
      [*gen*](https://askapache.com/online-tools/figlet-ascii/) </sub>
| [*Emoji*](https://iemoji.com/) <sub>
      [*cheatsheet*](https://github.com/ikatyang/emoji-cheat-sheet) </sub>
| [*Unicode*](https://unicode.org/) <sub>
      [*table*](https://unicode-table.com/),
      [*gb/t 15834-2011*](http://openstd.samr.gov.cn//bzgk/gb/newGbInfo?hcno=22EA6D162E4110E752259661E1A0D0A8),
      [*…*](https://sspai.com/post/45516) </sub>

**代码**
| 地区代码 <sub>
      [*iso 3166*](https://iso.org/iso-3166-country-codes.html) </sub>
| 日期时间 <sub>
      [*iso 8601*](https://iso.org/iso-8601-date-and-time-format.html) </sub>
| 语言代码 <sub>
      [*iso 639*](https://iso.org/iso-639-language-codes.html),
      [*bcp 47*](https://tools.ietf.org/html/bcp47),
      [*-tool*](https://r12a.github.io/app-subtags/) </sub>
| 许可代码 <sub>
      [*spdx list*](https://spdx.org/licenses/) </sub>

**辞典**
| [*The Free Dictionary*](https://thefreedictionary.com/)
| English Dictionaries <sub>
      [*abbreviations.com*](https://www.abbreviations.com/),
      [*all acronyms dictionary*](https://allacronyms.com/);
      [*dictionary.com*](https://dictionary.com/),
      [*thesaurus.com*](https://thesaurus.com/);
      [*cambridge*](https://dictionary.cambridge.org/),
      [*longman*](https://ldoceonline.com/),
      [*merriam-webster*](https://merriam-webster.com/),
      [*oxford*](https://en.oxforddictionaries.com/) </sub>
| 汉语辞典 <sub>
      [*汉典*](http://zdic.net/) </sub>

**风格**
| 引文风格 <sub>
      [*iso 690:2010*](https://iso.org/standard/43320.html),
      [*-m/c*](http://citationmachine.net/iso690-numeric-en/),
      [*gb/t 7714-2015*](http://openstd.samr.gov.cn/),
      [*-guide*](http://citethisforme.com/guides/chinese-gb7714-2005-numeric) </sub>

### 信息

**搜索**
| [*Wolfram|Alpha*](https://wolframalpha.com/)
| [*Wolfram MathWorld*](http://mathworld.wolfram.com/)

**新闻**
| [*InfoQ*](https://infoq.cn/)
| [*好奇心日报*](https://www.qdaily.com/),
  [*后续*](https://houxuapp.com/)
| [*蓝点网*](https://landiannews.com/)

**指数**
| [*TIOBE Index*](https://tiobe.com/tiobe-index/)

**黄页**
| [*awesome*](https://awesome.re/)
| [*DevDocs*](https://devdocs.io/)
| [*OverAPI.com*](http://overapi.com/)
| [*ProgramCreek.com*](https://programcreek.com/)

**书籍**
| [free-programming-books](https://ebookfoundation.github.io/free-programming-books/)
| [计算机书籍控](http://bestcbooks.com/)

### 工具

**系统支持**
| [*NetBSD*](http://netbsd.org/ "1993-04-19"),
  [*Debian*](https://debian.org/ "1993-08-16"),
  [*FreeBSD*](https://freebsd.org/ "1993-11-01"),
  [*SUSE*](https://opensuse.org/ "1994-03-07"),
  [*RHEL*](http://redhat.com/ "1995-05-13, RedHat 企业版"),
  [*Windows 95*](http://microsoft.com/windows95 "1995-08-15"),
  [*OpenBSD*](https://openbsd.org/ "1996-10-01"),
  [*Windows 98*](# "1998-05-15"),
  [*Gentoo*](https://gentoo.org/ "2000-07-26"),
  [*Windows XP*](# "2001-08-24"),
  [*Arch*](https://archlinux.org/ "2002-03-11"),
  [*Fedora*](https://getfedora.org/ "2003-11-06, RedHat 试验版, Linus 使用此版"),
  [*CentOS*](https://centos.org/ "2004-05-14, RedHat 社区版"),
  [*Ubuntu*](https://ubuntu.com/ "2004-10-20"),
  [*Windows 7*](# "2009-07-22"),
  [*Manjaro*](https://manjaro.org/ "2011-07-10"),
  [*Kali*](https://kali.org/ "2013-03-13"),
  [*Windows 10*](https://windows.com/ "2015-07-15")
| [*Cygwin*](https://cygwin.com/ "Cygnus Windows"),
  [*MinGW*](http://mingw.org/ "Minimalist GNU for Windows"),
  [*Mingw-w64*](https://mingw-w64.org/),
  [*MSYS2*](https://www.msys2.org/ "Minimal System")
| [*VMware Workstation*](https://vmware.com/products/workstation-pro.html "1999"),
  [*VirtualBox*](https://virtualbox.org/ "2007-01-15"),
  [*KVM*](https://linux-kvm.org/ "2007-02-05")

**壳层交互**
| [sh](# "Bourne Shell, 1977"),
  [csh](# "C Shell, 1978"),
  [*tcsh*](http://tcsh.org/ "TENEX C Shell, 1983"),
  [*ksh*](http://kornshell.com/ "KornShell, 1983"),
  [*ash*](https://in-ulm.de/~mascheck/various/ash/ "Almquist Shell, 1989-05-30"),
  [*bash*](https://gnu.org/software/bash/ "Bourne-Again Shell, 1989-06-08"),
  [*zsh*](https://zsh.org/ "Z Shell, 1990"),
  [*scsh*](https://scsh.net/ "Scheme Shell, 1994-10-31"),
  [*fish*](https://fishshell.com/ "Friendly Interactive Shell, 2005-02-13")
| [CMD](# "Command Prompt, 1987") <sub>
      [*doc*](https://ss64.com/nt/) </sub>,
  [*PowerShell*](https://microsoft.com/powershell "PowerShell, 2006") <sub>
      [*doc*](https://ss64.com/ps/) </sub>,
  [*ConEmu*](https://conemu.github.io/ "Console Emulator, 2007-03-09"),
  [*Clink*](https://mridgers.github.io/clink/ "2014-02-24"),
  [*Cmder*](https://cmder.net/ "Console Emulator, 2017-07-17")
| [*SecureCRT*](https://vandyke.com/products/securecrt/ "SecureCRT, 1998-06"),
  [*PuTTY*](https://www.chiark.greenend.org.uk/~sgtatham/putty/ "PuTTY, 1999-01-22"),
  [*WinSCP*](https://winscp.net/ "WinSCP, 2000")

**维护和自动化**
| [*AutoHotkey*](https://autohotkey.com/ "一款自动化脚本语言")
| [*cFosSpeed*](https://cfos.de/ "一款网络优化工具")
| [*EasyPHP*](https://easyphp.org/ "一款轻量 Web 服务器")
| [*NSSM*](https://nssm.cc/ "一款服务维护工具")
| [*Rapid Environment Editor*](https://rapidee.com/ "一款环境变量编辑器")
| [*WiX*](https://wixtoolset.org/ "一款安装包制作工具")
| [*Xlight*](https://xlightftpd.com/ "一款轻量 FTP 服务器")

**文件操作**
| [*Beyond Compare*](https://scootersoftware.com/ "一款文件比较工具")
| [*FastCopy*](https://fastcopy.jp/ "一款快速复制工具")
| [*IDM*](https://www.internetdownloadmanager.com/ "一款中心网络下载器"),
  [*qBittorrent*](https://qbittorrent.org/ "一款对等网络下载器") <sub>
      [*qBittorrent-Enhanced-Edition*](https://github.com/c0re100/qBittorrent-Enhanced-Edition) </sub>,
  [*Transmission*](https://transmissionbt.com/ "一款对等网络下载器")

**文本编辑**
| [*Emacs*](https://gnu.org/software/emacs/)
| [*Notepad++*](https://notepad-plus-plus.org/)
| [*UltraEdit*](https://ultraedit.com/)
| [*Vim*](https://www.vim.org/) <sub>
      [*cheatsheet*](https://vim.rtorr.com/lang/zh_cn),
      [*quickref*](http://vimcdoc.sourceforge.net/doc/quickref.html),
      [*index*](http://vimcdoc.sourceforge.net/doc/index.html),
      [*help*](http://vimcdoc.sourceforge.net/doc/help.html),
      [*doc*](http://vimcdoc.sourceforge.net) </sub>
| [*Visual Studio Code*](https://code.visualstudio.com/)
| [*WinHex*](http://winhex.com/winhex/)

**媒体编辑**
| [*Elecard*](https://elecard.com/ "一款视频分析工具")
| [*MediaInfo*](https://mediaarea.net/MediaInfo "一款视频格式分析工具")
| [*VLC*](https://videolan.org/ "一款媒体播放器")

**版本管理**
| [*CVS*](https://savannah.nongnu.org/projects/cvs "Concurrent Versions System, 1990-11-19")
| [*SVN*](https://subversion.apache.org/ "Subversion, 2000-10-20") <sub>
      [*tortoise*](https://tortoisesvn.net/) </sub>
| [*Git*](https://git-scm.com/ "Git, 2005-04-07") <sub>
      [*cheatsheet*](https://git-tower.com/blog/git-cheat-sheet/),
      [*commit*](https://github.com/angular/angular.js/blob/master/DEVELOPERS.md#-git-commit-guidelines),
      [*.gitignore*](https://github.com/github/gitignore),
      [*教程*](https://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000),
      [*tortoise*](https://tortoisegit.org/) </sub>

**集成开发**
| [*CLion*](https://jetbrains.com/clion "一款集成开发环境") <sub>
      [*zh_CN*](https://github.com/pingfangx/jetbrains-in-chinese/tree/master/CLion) </sub>
| [*Visual Studio*](https://visualstudio.com/ "一款集成开发环境") <sub>
      [*r++*](https://jetbrains.com/resharper-cpp "ReSharper C++"),
      [*va*](https://wholetomato.com/ "Visual Assist");
      [*build*](https://incredibuild.com/ "IncrediBuild"),
      [*leak*](https://kinddragon.github.io/vld/ "Visual Leak Detector"),
      [*styles*](https://studiostyl.es/ "Studio Styles") </sub>

**程序调试**
| [*Cheat Engine*](https://cheatengine.org/ "一款程序修改工具")
| [*DebugView*](https://docs.microsoft.com/sysinternals/downloads/debugview "一款调试输出显示工具")
| [*Dependency Walker*](http://dependencywalker.com "一款模块依赖扫描工具")
| [*IDA*](https://hex-rays.com/products/ida/ "一款反汇编调试器")
| [*OllyDbg*](http://ollydbg.de/ "一款反汇编调试器")
| [*PC Hunter*](http://xuetr.com/ "一款杀毒辅助工具")
| [*radare*](https://radare.org/ "一款反汇编调试器")
| [*WinDbg*](http://windbg.org/ "一款调试器")

**网络调试**
| [*bettercap*](https://bettercap.org/ "一款网络嗅探工具")
| [*dSniff*](https://monkey.org/~dugsong/dsniff/ "一款网络嗅探工具")
| [*Ettercap*](https://www.ettercap-project.org "一款网络嗅探工具")
| [*iPerf*](https://iperf.fr/ "一款网速测试工具")
| [*Wireshark*](https://wireshark.org/ "一款流量分析工具")

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
