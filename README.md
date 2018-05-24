# C & C++ in zhengrr's eyes

一份为zhengrr定制化的，关于C语言、C++语言、以及相关和不那么相关技术的备忘。

> Everyone knows it's a mistake to write your whole program by hand in machine language.
> What's less often understood is that there is a more general principle here:
> that if you have a choice of several languages, it is, all other things being equal, a mistake to program in anything but the most powerful one.
>
> [*Beating the Averages*](http://paulgraham.com/avg.html). April 2001, rev. April 2003.

## WWW

[*Wolfram|Alpha*](https://wolframalpha.com/)

[*36氪*](https://36kr.com/)
[*CodeProject*](https://codeproject.com/)
[*DevDocs*](https://devdocs.io/)
[*Hacker News*](https://news.ycombinator.com/)
[*InfoQ*](https://infoq.com/)
[*ITeye*](http://iteye.com/)
[*OverAPI.com*](http://overapi.com/)
[*SegmentFault*](https://segmentfault.com/)
[*Stack Overflow*](https://stackoverflow.com/)
[*V2EX*](https://v2ex.com/)
[*开源中国*](https://oschina.net/)
[*前端乱炖*](http://html-js.com/)

## Symbols

### Directories

+ [*The Free Dictionary*](https://thefreedictionary.com/)
+ :cn:
    + [*汉典*](http://zdic.net/)
+ :gb:
    + [*Abbreviations.com*](https://abbreviations.com/) & [*All Acronyms Dictionary*](https://allacronyms.com/)
    + [*Dictionary.com*](http://dictionary.com/) & [*Thesaurus.com*](http://thesaurus.com/)
    + [*Cambridge*](https://dictionary.cambridge.org/), [*Longman*](https://ldoceonline.com/), [*Oxford*](https://en.oxforddictionaries.com/) & [*Merriam-Webster*](https://merriam-webster.com/)

### Characters

+ [*Unicode® character table*](http://unicode-table.com/)
+ [*Emoji*](http://iemoji.com/)

### Codes

+ ["Date and Time"](https://ewikipedia.org/wiki/Date_and_time_representation_by_country). *Wikipedia*.
    + ["ISO 8601"](https://wikipedia.org/wiki/ISO_8601). *Wikipedia*.
    + [*ISO 8601 — Date and time format*](https://iso.org/iso-8601-date-and-time-format.html)
+ ["Country Code"](https://wikipedia.org/wiki/Country_code). *Wikipedia*.
    + [*ISO 3166 — Country Codes*](https://iso.org/iso-3166-country-codes.html)
+ ["Language Code"](https://wikipedia.org/wiki/Language_code). *Wikipedia*.
    + [*ISO 639 — Language codes*](https://iso.org/iso-639-language-codes.html)
    + [*BCP 47 — Tags for Identifying Languages*](https://tools.ietf.org/html/bcp47)
        + ["Language subtag lookup app"](https://r12a.github.io/app-subtags/). *r12a.io*.

## Groceries

["程序员必读书籍"](http://bestcbooks.com/recommend/most-influential-book/).  *计算机书籍控*.
+ *The Mythical Man-Month: Essays on Software Engineering*. 1st ed. 1975; 2nd ed. 1995. Frederick Brooks.
+ *Code Complete*. 1st ed. 1993; 2nd ed. 2004. Steve McConnell.

[free-programming-books](https://github.com/EbookFoundation/free-programming-books)

### [Git](https://git-scm.com/)

["Reference"](https://git-scm.com/docs). *Git*.
+ Getting and Creating Projects
    + [init](https://git-scm.com/docs/git-init)
      `git init`
+ Basic Snapshotting
    + [status](https://git-scm.com/docs/git-status)
      `git status`
    + [diff](https://git-scm.com/docs/git-diff)
      `git diff <file(s)>`
    + [add](https://git-scm.com/docs/git-add)
      `git add <file(s)>`
    + [rm](https://git-scm.com/docs/git-rm)
      `git rm <file(s)>`
    + [commit](https://git-scm.com/docs/git-commit)
      `git commit -m "..."`
        + [*How to Write a Git Commit Message*](https://chris.beams.io/posts/git-commit/). 2014. Chris Beams.
        + ["Git Commit Guidelines"](https://github.com/angular/angular.js/blob/master/DEVELOPERS.md#-git-commit-guidelines). *Developing AngularJS*.
    + [reset](https://git-scm.com/docs/git-reset)
      `git reset HEAD <file(s)>`
      `git reset --hard HEAD^`
      `git reset --hard <commit_id>`
+ Branching and Merging
    + [checkout](https://git-scm.com/docs/git-checkout)
      `git checkout -- <file(s)>`
+ Inspection and Comparison
    + [log](https://git-scm.com/docs/git-log)
      `git log --pretty=oneline`
+ Guides
    + [.gitattributes](https://git-scm.com/docs/gitattributes)
    + [.gitignore](https://git-scm.com/docs/gitignore)
        + ["A collection of useful .gitignore templates"](https://github.com/github/gitignore). *GitHub*.
    + [.gitmodules](https://git-scm.com/docs/gitmodules)
+ Administration
    + [reflog](https://git-scm.com/docs/git-reflog)

[*Try Git*](https://try.github.io/)
[*Pro Git*. 2nd ed.](https://git-scm.com/book/en/v2)<sub> [*cmn-Hans*](https://git-scm.com/book/zh/v2)</sub>. 2014. Scott Chacon; Ben Straub.
["Git教程"](https://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000). *廖雪峰的官方网站*.

### [Markdown](https://daringfireball.net/markdown/)

["Syntax"](https://daringfireball.net/markdown/syntax). *Markdown*.
+ Block Elements
    + [Blockquotes](https://daringfireball.net/markdown/syntax#blockquote)
    + [Lists](https://daringfireball.net/markdown/syntax#list)

["Markdown support"](http://doxygen.org/manual/markdown.html). *Doxygen*.
+ [Standard Markdown](http://doxygen.org/manual/markdown.html#markdown_std)
+ [Markdown Extensions](http://doxygen.org/manual/markdown.html#markdown_extra)
+ [Doxygen specifics](http://doxygen.org/manual/markdown.html#markdown_dox)

["Mastering Markdown"](https://guides.github.com/features/mastering-markdown/). *GitHub Guides*.

### [Doxygen](http://doxygen.org/)

["Doxygen Manual"](http://doxygen.org/manual). *Doxygen*.
+ [Configuration](http://doxygen.org/manual/config.html)
+ [Special Commands](http://doxygen.org/manual/commands.html)

["Including formulas"](http://doxygen.org/manual/formulas.html). *Doxygen Manual*.
+ [*LaTeX*](https://latex-project.org)
+ [*Dvips*](https://tug.org/texinfohtml/dvips.html)
+ [*GhostScript*](https://ghostscript.com)
+ [*MathJax*](https://mathjax.org/)

["Graphs and diagrams"](http://doxygen.org/manual/diagrams.html). *Doxygen Manual*.
+ [*Graphviz*](https://graphviz.gitlab.io)

["\startuml"](http://doxygen.org/manual/commands.html#cmdstartuml). *Doxygen Manual*.
+ [*PlantUML*](http://plantuml.com)

### Editors

[*Emacs (Editor Macros)*](https://gnu.org/software/emacs/)
[*Vim (Visual Editor Improved)*](http://vim.org/)
[*Notepad++*](https://notepad-plus-plus.org)
[*Visual Studio Code*](https://code.visualstudio.com)

[*Vim Documentation*](http://vimdoc.sourceforge.net)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net)</sub>
+ [help](http://vimdoc.sourceforge.net/htmldoc/help.html)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/help.html)</sub>
+ [quickref](http://vimdoc.sourceforge.net/htmldoc/quickref.html)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html)</sub>
+ index<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/index.html)</sub>

quickref
+ [motion: Left-right](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_lr)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_lr)</sub>
    + 左移`h`　右移`l`　某列`<num>|`
    + 行内　左向搜索`F<char>`　左向搜索到`T<char>`　右向搜索到`t<char>`ill　右向搜索`f<char>`ind
    + 行内　重复搜索`;`　反向重复搜索`,`
    + 顶格`0`　行首`^`　行中`gm`　行尾`g_`　底格`$`
+ [motion: Up-down](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ud)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ud)</sub>
    + 上移`k`且到行首`-`　下移`j`且到行首`+`
    + 顶行`gg`　底行`G`　某行`<num>gg` `<num>G`
+ [motion: Text object](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_tm)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_tm)</sub>
    + 前词头`b`　前词尾`ge`　后词头`w`　后词尾`e`
    + 前串头`B`　前串尾`gE`　后串头`W`　后串尾`E`
+ [motion: Pattern searches](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_pa)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_pa)</sub>
    + 前文查找`?<pattern>`　后文查找`/<pattern>`
    + 前文重复查找`?<CR>`　逆向重复查找`N`　顺向重复查找`n`ext　后文重复查找`/<CR>`
    + 前文查找光标下标识符`#`　后文查找光标下标识符`*`
+ [motion: Marks](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ma)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ma)</sub>
    + 标记局部位置`m{a-z}`ark　标记全局位置`m{A-Z}`　跳转到标记位置`` `{A-Za-z} ``　标记表`:marks`
    + 旧向跳转`<C-O>`lder　新向跳转`<C-I>`　回跳``` `` ```　跳转到最后编辑处`` `" ``　跳转表`:ju`
+ [motion: Various](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_vm)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_vm)</sub>
    + 字符匹配`%`
    + 窗口　顶行`H`ome　中行`M`iddle　底行`L`ast
+ [motion: Using tags](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ta)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ta)</sub>
    + 标签跳出`<C-T>`　标签跳入`<C-]>`
+ [Scrolling](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_sc)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_sc)</sub>
    + 上滚一页`<C-B>`ackwards　上滚半页`<C-U>`pwards　上滚一行`<C-Y>`
    + 下滚一行`<C-E>`xtra　下滚半页`<C-D>`ownwards　下滚一页`<C-F>`orwards
    + 此行置顶`zt`op且到行首`z<CR>`　此行置中`zz`且到行首`z.`　此行置底`zb`ottom且到行首`z-`
+ [insert: Inserting text](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_in)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_in)</sub>
    + 顶格插入`gI`　行首插入`I`　字符前插入`i`nsert　字符后插入`a`ppend　底格插入`A`
    + 上建一行并编辑`O`　下建一行并编辑`o`pen
+ [insert: Keys](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ai)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ai)</sub>
    + 转回普通模式`i_<ESC>` `i_<C-C>`
+ [insert: Special keys](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ss)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ss)</sub>
    + 粘贴`i_<C-R><reg>`egister
    + 清空整行`i_<C-U>`　删除前一单词`i_<C-W>`ord
    + 减少缩进`i_<C-D>`elete　增加缩进`i_<C-T>`ab
+ [insert: Digraphs](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_di)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_di)</sub>
+ [insert: Special inserts](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_si)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_si)</sub>
+ [change: Deleting text](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_de)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_de)</sub>
    + 删除`d<motion>`elete
    + 删除整行`dd`　删除光标前字符`X`　删除光标处字符`x`　删除至底格`D`
    + 连接下行`J`oin
+ [change: Copying and moving](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_cm)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_cm)</sub>
    + 指定寄存器`"<reg>`　寄存表`:reg`
    + [registers](http://vimdoc.sourceforge.net/htmldoc/change.html#registers)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/change.html#registers)</sub>
    + 复制`y<motion>`ank
    + 复制整行`yy` `Y`
    + 光标前粘贴`P`　光标后粘贴`p`ut
+ [change: Changing text](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ch)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ch)</sub>
    + 修改`c<cotion>`hange
    + 修改整行`cc` `S`　修改光标处字符`s`ubstitute　修改至底格`C`
    + 替换光标处字符`r<char>`eplace　替换模式`R`
    + 翻转大小写`~`　数值自减`<C-X>`　数值自增`<C-A>`
+ [change: Complex](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_co)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_co)</sub>
    + 格式化`=<motion>`
	+ 格式化整行`==`
+ [Visual mode](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_vi)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_vi)</sub>
+ [Text objects](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_to)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_to)</sub>
    + 单词`v_[ai]w`ord　字串`v_[ai]W`　句子`v_[ai]s`entence　段落`v_[ai]p`aragraph　a/inner
    + 圆括号块`v_[ai](`　方括号块`v[ai][`　花括号块`v_[ai]{`　尖括号块`v_[ai]<`　标签块`v_[ai]t`
    + 单引号字符串`v_[ai]'`　双引号字符串`v_[ai]"`　反引号字符串`` v_[ai]` ``
+ [Repeating commands](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_re)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_re)</sub>
    + 重复改动`.`
+ [Key mapping](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_km)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_km)</sub>
+ [Abbreviations](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ab)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ab)</sub>
+ [Options](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_op)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_op)</sub>
+ [Undo/Redo commands](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ur)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ur)</sub>
    + 撤销改动`u`ndo　恢复改动`<C-R>`edo　恢复整行改动`U`
+ [External commands](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_et)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_et)</sub>
    + 关键字查询`K`eyword
+ [Quickfix commands](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_qf)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_qf)</sub>
+ [Various commands](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_vc)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_vc)</sub>
+ [Ex: Command-line editing](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ce)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ce)</sub>
+ [Ex: Ranges](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ra)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ra)</sub>
+ [Ex: Special characters](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ex)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ex)</sub>
+ [Starting Vim](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_st)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_st)</sub>
+ [Editing a file](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ed)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ed)</sub>
+ [Using the argument list](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_fl)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_fl)</sub>
+ [Writing and quitting](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_wq)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_wq)</sub>
+ [Automatic commands](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ac)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ac)</sub>
+ [Multi-window commands](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_wi)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_wi)</sub>
    + window　纵向分割窗口`<C-W>s`plit　横向分割窗口`<C-W>v`ertical
    + 窗口尺寸　重置高宽`<C-W>=`
    + 窗口尺寸　减少高度`<C-W>-`　增加高度`<C-W>+`　设置高度`<C-W>_`
    + 窗口尺寸　减少宽度`<C-W><`　增加宽度`<C-W>>`  设置宽度`<C-W>|`
    + 窗口跳转　上一`<C-W>p`revious　下一`<C-W>w`rap
    + 窗口跳转　左侧`<C-W>h`　右侧`<C-W>l`
    + 窗口跳转　顶部`<C-W>t`op　上侧`<C-W>k`　下侧`<C-W>j`　底部`<C-W>b`otton
    + 窗口调整　顺时针`<C-W><C-R>`otate　逆时针`<C-W>R`　对调e`<C-W><C-X>`change
    + 关闭当前窗口`<C-W>c`lose　仅保留当前窗口`<C-W>o`nly
+ [Buffer list commands](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_bu)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_bu)</sub>
+ [Syntax highlighting](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_sy)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_sy)</sub>
+ [GUI commands](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_gu)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_gu)</sub>
+ [Folding](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_fo)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_fo)</sub>
    + fold　关闭折叠至顶`zC`　关闭折叠`zc`lose　打开折叠`zo`pen　打开折叠至底`zO`
    + 关闭所有折叠至顶`zM`　关闭所有折叠`zm`ore　打开所有折叠`zr`educe　打开所有折叠至底`zR`
    + 禁用折叠`zn`one　启用折叠`zN`ormal　开关折叠`zi`nvert
+ More
    + go　左一标签页`gT`　右一标签页`gt`ab　某标签页`<num>gt`

### Environments

[*Cygwin*](http://cygwin.com)
[*MinGW (Minimalist GNU for Windows)*](http://mingw.org)

### Integrated Development Environments

[*Visual Studio*](https://visualstudio.com)
+ [*ReSharper С++*](https://jetbrains.com/resharper-cpp)
+ [*CodeMaid*](http://codemaid.net)
+ 2008 [*Visual Assist*](https://wholetomato.com)
+ 2008 [*IncrediBuild*](https://incredibuild.com)
+ [*Studio Styles*](https://studiostyl.es)
+ [*Dependency Walker*](http://dependencywalker.com)

[*Understand™*](https://scitools.com)

[*CLion*](https://jetbrains.com/clion)

___
<a rel="license" href="http://creativecommons.org/licenses/by/4.0/"><img alt="知识共享许可协议" style="border-width:0" src="https://i.creativecommons.org/l/by/4.0/88x31.png" /></a><br />本作品采用<a rel="license" href="http://creativecommons.org/licenses/by/4.0/">知识共享署名 4.0 国际许可协议</a>进行许可。
