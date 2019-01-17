# zhengrr 所知的 C 和 C++

一份为 zhengrr 定制化的，关于 C 语言、C++ 语言、以及相关和不那么相关技术的备忘。

> Everyone knows it's a mistake to write your whole program by hand in machine language.
> What's less often understood is that there is a more general principle here:
> that if you have a choice of several languages, it is, all other things being equal, a mistake to program in anything but the most powerful one.
>
> [*Beating the Averages*](http://paulgraham.com/avg.html). April 2001, rev. April 2003.

[*TIOBE Index*](https://tiobe.com/tiobe-index/)

## 参考

/ [*Wolfram|Alpha*](https://wolframalpha.com/)
/ [*Wolfram MathWorld*](http://mathworld.wolfram.com/)

/ [*36氪*](https://36kr.com/)
/ [*CodeProject*](https://codeproject.com/)
/ [*DevDocs*](https://devdocs.io/)
/ [*Hacker News*](https://news.ycombinator.com/)
/ [*InfoQ*](https://infoq.com/)
/ [*ITeye*](http://iteye.com/)
/ [*OverAPI.com*](http://overapi.com/)
/ [*SegmentFault*](https://segmentfault.com/)
/ [*Stack Overflow*](https://stackoverflow.com/)
/ [*V2EX*](https://v2ex.com/)
/ [*开源中国*](https://oschina.net/)
/ [*前端乱炖*](http://html-js.com/)

*词典*
/ [*Abbreviations.com*](https://abbreviations.com/)
/ [*All Acronyms Dictionary*](https://allacronyms.com/)
/ [*Cambridge*](https://dictionary.cambridge.org/)
/ [*Dictionary.com*](https://dictionary.com/)
/ [*Longman*](https://ldoceonline.com/)
/ [*Merriam-Webster*](https://merriam-webster.com/)
/ [*Oxford*](https://en.oxforddictionaries.com/)
/ [*The Free Dictionary*](https://thefreedictionary.com/)
/ [*Thesaurus.com*](https://thesaurus.com/)
/ [*汉典*](http://zdic.net/)

*字符*
/ [*Emoji*](https://iemoji.com/)
/ [*Unicode® character table*](https://unicode-table.com/)

*代码*
/ [*ASCII Figlet Generator*](https://www.askapache.com/online-tools/figlet-ascii/)
/ [*Country Code*](https://wikipedia.org/wiki/Country_code) (
    / [*ISO 3166 — Country Codes*](https://iso.org/iso-3166-country-codes.html) )
/ [*Date and Time*](https://ewikipedia.org/wiki/Date_and_time_representation_by_country) (
    / [*ISO 8601*](https://wikipedia.org/wiki/ISO_8601)
    / [*ISO 8601 — Date and time format*](https://iso.org/iso-8601-date-and-time-format.html) )
/ ["Language Code"](https://wikipedia.org/wiki/Language_code) (
    / [*ISO 639 — Language codes*](https://iso.org/iso-639-language-codes.html)
    / [*BCP 47 — Tags for Identifying Languages*](https://tools.ietf.org/html/bcp47)
    / [*Language subtag lookup app*](https://r12a.github.io/app-subtags/) )
/ [*SPDX License List*](https://spdx.org/licenses/)

## 指南

["程序员必读书籍"](http://bestcbooks.com/recommend/most-influential-book/). *计算机书籍控*.
*   *The Mythical Man-Month: Essays on Software Engineering*. 1st ed. 1975; 2nd ed. 1995. Frederick Brooks.
*   *Code Complete*. 1st ed. 1993; 2nd ed. 2004. Steve McConnell.

[free-programming-books](https://github.com/EbookFoundation/free-programming-books)

## Awesome

[*awesome*](https://awesome.re/)

*编辑*
/ [*Emacs*](https://gnu.org/software/emacs/)
/ [*Notepad++*](https://notepad-plus-plus.org/)
/ [*Vim*](https://www.vim.org/)
/ [*Visual Studio Code*](https://code.visualstudio.com/)

*环境*
/ [*Cygwin*](https://cygwin.com/ "Cygnus Windows")
/ [*MinGW*](http://mingw.org/ "Minimalist GNU for Windows")
/ [*Mingw-w64*](https://mingw-w64.org/)
/ [*MSYS2*](https://www.msys2.org/ "Minimal System")

*开发*
/ [*CLion*](https://jetbrains.com/clion)
/ [*Understand™*](https://scitools.com/)
/ [*Visual Studio*](https://visualstudio.com/) (
    / [*IncrediBuild*](https://incredibuild.com/)
    / [*ReSharper С++*](https://jetbrains.com/resharper-cpp)
    / [*Studio Styles*](https://studiostyl.es/)
    / [*Visual Assist*](https://wholetomato.com/) )

*工具*
/ [*Ettercap*](https://www.ettercap-project.org/)
/ [*FastCopy*](https://fastcopy.jp/)
/ [*iPerf*](https://iperf.fr/)
/ [*Rapid Environment Editor*](https://rapidee.com/)
/ [*Wireshark*](https://wireshark.org/)

## Git

[*Git*](https://git-scm.com/)

["Reference"](https://git-scm.com/docs). *Git*.
*   Getting and Creating Projects
    *   [init](https://git-scm.com/docs/git-init)
        `git init`
*   Basic Snapshotting
    *   [status](https://git-scm.com/docs/git-status)
        `git status`
    *   [diff](https://git-scm.com/docs/git-diff)
        `git diff <file(s)>`
    *   [add](https://git-scm.com/docs/git-add)
        `git add <file(s)>`
    *   [rm](https://git-scm.com/docs/git-rm)
        `git rm <file(s)>`
    *   [commit](https://git-scm.com/docs/git-commit)
        `git commit -m "..."`
        *   ["Git Commit Guidelines"](https://github.com/angular/angular.js/blob/master/DEVELOPERS.md#-git-commit-guidelines). *Developing AngularJS*.
        *   [*How to Write a Git Commit Message*](https://chris.beams.io/posts/git-commit/). 2014. Chris Beams.
    *   [reset](https://git-scm.com/docs/git-reset)
        `git reset HEAD <file(s)>`
        `git reset --hard HEAD^`
        `git reset --hard <commit_id>`
*   Branching and Merging
    *   [checkout](https://git-scm.com/docs/git-checkout)
        `git checkout -- <file(s)>`
*   Inspection and Comparison
    *   [log](https://git-scm.com/docs/git-log)
        `git log --pretty=oneline`
*   Guides
    *   [.gitattributes](https://git-scm.com/docs/gitattributes)
    *   [.gitignore](https://git-scm.com/docs/gitignore)
        *   ["A collection of useful .gitignore templates"](https://github.com/github/gitignore). *GitHub*.
    *   [.gitmodules](https://git-scm.com/docs/gitmodules)
*   Administration
    *   [reflog](https://git-scm.com/docs/git-reflog)

/ [*Try Git*](https://try.github.io/)
/ [*Pro Git*. 2nd ed.](https://git-scm.com/book/en/v2)<sub> [*cmn-Hans*](https://git-scm.com/book/zh/v2)</sub>. 2014. Scott Chacon; Ben Straub.
/ ["Git教程"](https://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000). *廖雪峰的官方网站*.

## Markdown

[*Markdown*](https://daringfireball.net/markdown/)

["Syntax"](https://daringfireball.net/markdown/syntax). *Markdown*.
*   Block Elements
    *   [Blockquotes](https://daringfireball.net/markdown/syntax#blockquote)
    *   [Lists](https://daringfireball.net/markdown/syntax#list)

["Markdown support"](http://doxygen.org/manual/markdown.html). *Doxygen*.
*   [Standard Markdown](http://doxygen.org/manual/markdown.html#markdown_std)
*   [Markdown Extensions](http://doxygen.org/manual/markdown.html#markdown_extra)
*   [Doxygen specifics](http://doxygen.org/manual/markdown.html#markdown_dox)

["Mastering Markdown"](https://guides.github.com/features/mastering-markdown/). *GitHub Guides*.

## Doxygen

[*Doxygen*](http://doxygen.org/)

["Doxygen Manual"](http://doxygen.org/manual). *Doxygen*.
*   [Including formulas](http://doxygen.org/manual/formulas.html)
    *   [*LaTeX*](https://latex-project.org)
        *   [*An introduction to beautiful math on Quora*](https://math-on-quora.surge.sh/)
        *   [*Detexify LaTeX handwritten symbol recognition*](http://detexify.kirelabs.org/)
        *   [*TexPaste: Math Pastebin with LaTeX*](http://texpaste.com/)
    *   [*Dvips*](https://tug.org/texinfohtml/dvips.html)
    *   [*GhostScript*](https://ghostscript.com)
    *   [*MathJax*](https://mathjax.org/)
*   [Configuration](http://doxygen.org/manual/config.html)
*   [Special Commands](http://doxygen.org/manual/commands.html)
    *   [\startuml](http://doxygen.org/manual/commands.html#cmdstartuml)
        *   [*PlantUML*](http://plantuml.com)
*   [Graphs and diagrams](http://doxygen.org/manual/diagrams.html)
    *   [*Graphviz*](https://graphviz.gitlab.io)

## Vim

[*Vim Documentation*](http://vimdoc.sourceforge.net)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net)</sub>
*   [help](http://vimdoc.sourceforge.net/htmldoc/help.html)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/help.html)</sub>
*   [quickref](http://vimdoc.sourceforge.net/htmldoc/quickref.html)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html)</sub>
*   index<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/index.html)</sub>

quickref
*   [motion: Left-right](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_lr) [左右动作](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_lr)
    *   左移<kbd>h</kbd>　某列<kbd>Number</kbd><kbd>|</kbd>　右移<kbd>l</kbd>
    *   顶格<kbd>0</kbd>　行首<kbd>^</kbd>　行中<kbd>g</kbd><kbd>m</kbd>　行尾<kbd>g</kbd><kbd>_</kbd>　底格<kbd>$</kbd>
    *   行内－　反向重复搜索<kbd>,</kbd>
    *   行内－　逆向搜索<kbd>F</kbd><kbd>Character</kbd>　逆向搜索到<kbd>T</kbd><kbd>Character</kbd>　顺向搜索到<kbd>t</kbd><kbd>Character</kbd>　顺向搜索<kbd>f</kbd><kbd>Character</kbd>
    *   行内－　重复搜索<kbd>;</kbd>
*   [motion: Up-down](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ud) [上下动作](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ud)
    *   顶行<kbd>g</kbd><kbd>g</kbd>
    *   上移<kbd>k</kbd>　且到行首<kbd>-</kbd>
    *   某行<kbd>Number</kbd><kbd>g</kbd><kbd>g</kbd>　或<kbd>Number</kbd><kbd>G</kbd>
    *   下移<kbd>j</kbd>　且到行首<kbd>+</kbd>
    *   底行<kbd>G</kbd>
*   [motion: Text object](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_tm) [文本对象动作](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_tm)
    *   前词头<kbd>b</kbd>　前词尾<kbd>g</kbd><kbd>e</kbd>　后词头<kbd>w</kbd>　后词尾<kbd>e</kbd>
    *   前块头<kbd>B</kbd>　前块尾<kbd>g</kbd><kbd>E</kbd>　后块头<kbd>W</kbd>　后块尾<kbd>E</kbd>
*   [motion: Pattern searches](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_pa) [模式查找](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_pa)
    *   前文查找<kbd>?</kbd>`Pattern`<kbd>Enter</kbd>　后文查找<kbd>/</kbd>`Pattern`<kbd>Enter</kbd>
    *   前文重复查找<kbd>?</kbd><kbd>Enter</kbd>　反向重复查找<kbd>N</kbd>　顺向重复查找<kbd>n</kbd>　后文重复查找<kbd>/</kbd><kbd>Enter</kbd>
    *   前文查找光标下标识符<kbd>#</kbd>　后文查找光标下标识符<kbd>*</kbd>
*   [motion: Marks](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ma) [位置标记和相关动作](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ma)
    *   标记局部位置<kbd>m</kbd><kbd>a-z</kbd>　标记全局位置<kbd>m</kbd><kbd>A-Z</kbd>　跳转到标记位置<kbd>\`</kbd><kbd>A-Za-z</kbd>　标记表<kbd>:</kbd>`marks`<kbd>Enter</kbd>
    *   旧向跳转<kbd>Ctrl-O</kbd>　新向跳转<kbd>Ctrl-I</kbd>　回跳<kbd>\`</kbd><kbd>\`</kbd>　跳转到最后编辑处<kbd>\`</kbd><kbd>"</kbd>　跳转表<kbd>:</kbd>`ju`<kbd>Enter</kbd>
*   [motion: Various](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_vm) [其它动作](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_vm)
    *   字符匹配<kbd>%</kbd>
    *   窗口内－　顶行行首<kbd>H</kbd>
    *   窗口内－　中行行首<kbd>M</kbd>
    *   窗口内－　底行行首<kbd>L</kbd>
*   [motion: Using tags](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ta) [使用标签](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ta)
    *   标签跳出<kbd>Ctrl-T</kbd>　标签跳入<kbd>Ctrl-]</kbd>
*   [Scrolling](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_sc) [屏幕滚动](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_sc)
    *   上滚一页<kbd>Ctrl-B</kbd>
    *   上滚半页<kbd>Ctrl-U</kbd>
    *   上滚一行<kbd>Ctrl-Y</kbd>
    *   此行置顶<kbd>z</kbd><kbd>t</kbd>　且到行首<kbd>z</kbd><kbd>Enter</kbd>
    *   此行置中<kbd>z</kbd><kbd>z</kbd>　且到行首<kbd>z</kbd><kbd>.</kbd>
    *   此行置底<kbd>z</kbd><kbd>b</kbd>　且到行首<kbd>z</kbd><kbd>-</kbd>
    *   下滚一行<kbd>Ctrl-E</kbd>
    *   下滚半页<kbd>Ctrl-D</kbd>
    *   下滚一页<kbd>Ctrl-F</kbd>
*   [insert: Inserting text](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_in) [插入文本](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_in)
    *   上建一行并编辑<kbd>O</kbd>
    *   顶格插入<kbd>g</kbd><kbd>I</kbd>　行首插入<kbd>I</kbd>　字符前插入<kbd>i</kbd>　字符后插入<kbd>a</kbd>　底格插入<kbd>A</kbd>
    *   下建一行并编辑<kbd>o</kbd>
*   [insert: Keys](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ai) [插入模式键](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ai)
    *   离开插入模式`i_`<kbd>ESC</kbd>　或`i_`<kbd>Ctrl-C</kbd>
*   [insert: Special keys](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ss) [插入模式特殊键](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ss)
    *   插入光标上方字符`i_`<kbd>Ctrl-Y</kbd>
    *   粘贴`i_`<kbd>Ctrl-R</kbd><kbd>Register</kbd>　重复上次插入`i_`<kbd>Ctrl-A</kbd>　并离开插入模式`i_`<kbd>Ctrl-@</kbd>
    *   插入光标下方字符`i_`<kbd>Ctrl-E</kbd>
    *   清空整行`i_`<kbd>Ctrl-U</kbd>　删除前一单词`i_`<kbd>Ctrl-W</kbd>
    *   减少缩进`i_`<kbd>Ctrl-D</kbd>　增加缩进`i_`<kbd>Ctrl-T</kbd>
*   [insert: Digraphs](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_di) [二合字母](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_di)
*   [insert: Special inserts](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_si) [特殊插入](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_si)
*   [change: Deleting text](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_de) [删除文本](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_de)
    *   删除<kbd>d</kbd><kbd>Motion...</kbd>
    *   删除整行<kbd>d</kbd><kbd>d</kbd>　删除光标前字符<kbd>X</kbd>　删除光标处字符<kbd>x</kbd>　删除至底格<kbd>D</kbd>
    *   连接下行<kbd>J</kbd>
*   [change: Copying and moving](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_cm) [复制与移动文本](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_cm)
    *   指定寄存器<kbd>"</kbd><kbd>Register</kbd>　寄存表<kbd>:</kbd>`reg`<kbd>Enter</kbd>
    *   [registers](http://vimdoc.sourceforge.net/htmldoc/change.html#registers) [寄存器](http://vimcdoc.sourceforge.net/doc/change.html#registers)
    *   复制<kbd>y</kbd><kbd>Motion...</kbd>
    *   复制整行<kbd>y</kbd><kbd>y</kbd>　或<kbd>Y</kbd>
    *   光标前粘贴<kbd>P</kbd>　光标后粘贴<kbd>p</kbd>
*   [change: Changing text](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ch) [改变文本](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ch)
    *   修改<kbd>c</kbd><kbd>Motion...</kbd>
    *   修改整行<kbd>c</kbd><kbd>c</kbd>　或<kbd>S</kbd>　修改光标处字符<kbd>s</kbd>　修改至底格<kbd>C</kbd>
    *   替换光标处字符<kbd>r</kbd><kbd>Character</kbd>　替换模式<kbd>R</kbd>
    *   翻转大小写<kbd>\~</kbd>　翻转大小写<kbd>g</kbd><kbd>\~</kbd><kbd>Motion...</kbd>　改为小写<kbd>g</kbd><kbd>u</kbd><kbd>Motion...</kbd>　改为大写<kbd>g</kbd><kbd>U</kbd><kbd>Motion...</kbd>
    *   ROT13替换<kbd>g</kbd><kbd>?</kbd><kbd>Motion...</kbd>
    *   数值自减<kbd>Ctrl-X</kbd>　数值自增<kbd>Ctrl-A</kbd>
    *   减少缩进<kbd><</kbd><kbd><</kbd>　增加缩进<kbd>></kbd><kbd>></kbd>
*   [change: Complex](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_co) [复杂改动](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_co)
    *   格式化<kbd>=</kbd><kbd>Motion...</kbd>
    *   格式化整行<kbd>=</kbd><kbd>=</kbd>
*   [Visual mode](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_vi) [可视模式](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_vi)
    *   可视模式－　字符方式<kbd>v</kbd>　行方式<kbd>V</kbd>　列块方式<kbd>Ctrl-V</kbd>
*   [Text objects](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_to) [文本对象](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_to)
    *   单词`v_`<kbd>a/i</kbd><kbd>w</kbd>　字块`v_`<kbd>a/i</kbd><kbd>W</kbd>　句子`v_`<kbd>a/i</kbd><kbd>s</kbd>　段落`v_`<kbd>a/i</kbd><kbd>p</kbd>
    *   圆括号块`v_`<kbd>a/i</kbd><kbd>(</kbd>　方括号块`v_`<kbd>a/i</kbd><kbd>[</kbd>　花括号块`v_`<kbd>a/i</kbd><kbd>{</kbd>　尖括号块`v_`<kbd>a/i</kbd><kbd><</kbd>　标签块`v_`<kbd>a/i</kbd><kbd>t</kbd>
    *   单引号字符串`v_`<kbd>a/i</kbd><kbd>'</kbd>　双引号字符串`v_`<kbd>a/i</kbd><kbd>"</kbd>　反引号字符串`v_`<kbd>a/i</kbd><kbd>\`</kbd>
*   [Repeating commands](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_re) [重复命令](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_re)
    *   重复改动<kbd>.</kbd>
    *   录制宏<kbd>q</kbd><kbd>Register</kbd><kbd>Macro...</kbd><kbd>q</kbd>　执行宏<kbd>@</kbd><kbd>Register</kbd>
*   [Key mapping](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_km) [键盘映射](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_km)
*   [Abbreviations](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ab) [缩写](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ab)
*   [Options](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_op) [选项](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_op)
*   [Undo/Redo commands](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ur) [撤销与重做命令](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ur)
    *   撤销改动<kbd>u</kbd>　重做改动<kbd>Ctrl-R</kbd>　恢复最近被改动的行<kbd>U</kbd>
*   [External commands](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_et) [外部命令](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_et)
    *   关键字查询<kbd>K</kbd>
*   [Quickfix commands](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_qf) [快速修复命令](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_qf)
*   [Various commands](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_vc) [杂项命令](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_vc)
*   [Ex: Command-line editing](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ce) [命令行编辑](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ce)
*   [Ex: Ranges](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ra) [额外范围](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ra)
*   [Ex: Special characters](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ex) [特殊额外字符](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ex)
*   [Starting Vim](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_st) [启动VIM](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_st)
*   [Editing a file](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ed) [文件编辑](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ed)
*   [Using the argument list](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_fl) [使用参数列表](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_fl)
*   [Writing and quitting](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_wq) [写入和退出](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_wq)
*   [Automatic commands](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ac) [自动命令](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ac)
*   [Multi-window commands](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_wi) [多窗口命令](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_wi)
    *   窗口－　（纵向）分割<kbd>Ctrl-W</kbd><kbd>s</kbd>　横向分割<kbd>CTRL-W</kbd><kbd>v</kbd>
    *   活动窗口－　顶部<kbd>Ctrl-W</kbd><kbd>t</kbd>　上一<kbd>Ctrl-W</kbd><kbd>W</kbd>
    *   活动窗口－　上方<kbd>Ctrl-W</kbd><kbd>k</kbd>
    *   活动窗口－　左侧<kbd>Ctrl-W</kbd><kbd>h</kbd>　回<kbd>Ctrl-W</kbd>　右侧<kbd>Ctrl-W</kbd><kbd>l</kbd>
    *   活动窗口－　下方<kbd>Ctrl-W</kbd><kbd>j</kbd>
    *   活动窗口－　底部<kbd>Ctrl-W</kbd><kbd>b</kbd>　下一<kbd>Ctrl-W</kbd><kbd>w</kbd>
    *   窗口尺寸－　设置高度<kbd>Ctrl-W</kbd><kbd>_</kbd>　增加高度<kbd>Ctrl-W</kbd><kbd>+</kbd>
    *   窗口尺寸－　减少宽度<kbd>Ctrl-W</kbd><kbd><</kbd>　重置尺寸<kbd>Ctrl-W</kbd><kbd>=</kbd>　增加宽度<kbd>Ctrl-W</kbd><kbd>></kbd>
    *   窗口尺寸－　设置宽度<kbd>Ctrl-W</kbd><kbd>|</kbd>　减少高度<kbd>Ctrl-W</kbd><kbd>-</kbd>
    *   调整窗口－　逆时针<kbd>Ctrl-W</kbd><kbd>R</kbd>　顺时针<kbd>Ctrl-W</kbd><kbd>r</kbd>　对调<kbd>Ctrl-W</kbd><kbd>x</kbd>
    *   关闭当前窗口<kbd>Ctrl-W</kbd><kbd>c</kbd>　仅保留当前窗口<kbd>Ctrl-W</kbd><kbd>o</kbd>
*   [Buffer list commands](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_bu)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_bu)</sub>
*   [Syntax highlighting](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_sy)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_sy)</sub>
*   [GUI commands](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_gu)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_gu)</sub>
*   [Folding](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_fo)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_fo)</sub>
    *   关闭折叠至顶<kbd>z</kbd><kbd>C</kbd>　关闭折叠<kbd>z</kbd><kbd>c</kbd>　打开折叠<kbd>z</kbd><kbd>o</kbd>　打开折叠至底<kbd>z</kbd><kbd>O</kbd>
    *   关闭所有折叠至顶<kbd>z</kbd><kbd>M</kbd>　关闭所有折叠<kbd>z</kbd><kbd>m</kbd>　打开所有折叠<kbd>z</kbd><kbd>r</kbd>　打开所有折叠至底<kbd>z</kbd><kbd>R</kbd>
    *   禁用折叠<kbd>z</kbd><kbd>n</kbd>　启用折叠<kbd>z</kbd><kbd>N</kbd>　开关折叠<kbd>z</kbd><kbd>i</kbd>
*   More
    *   左一标签页<kbd>g</kbd><kbd>T</kbd>　某标签页<kbd>Number</kbd><kbd>g</kbd><kbd>t</kbd>　右一标签页<kbd>g</kbd><kbd>t</kbd>

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
