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
    + 左移<kbd>h</kbd>　某列<kbd>Number</kbd><kbd>|</kbd>　右移<kbd>l</kbd>
    + 顶格<kbd>0</kbd>　行首<kbd>^</kbd>　行中<kbd>g</kbd><kbd>m</kbd>　行尾<kbd>g</kbd><kbd>_</kbd>　底格<kbd>$</kbd>
    + 行内　反向重复搜索<kbd>,</kbd>
    + 行内　逆向搜索<kbd>F</kbd><kbd>Character</kbd>　逆向搜索到<kbd>T</kbd><kbd>Character</kbd>　顺向搜索到<kbd>t</kbd><kbd>Character</kbd>　顺向搜索<kbd>f</kbd><kbd>Character</kbd>
    + 行内　重复搜索<kbd>;</kbd>　反向重复搜索<kbd>,</kbd>
+ [motion: Up-down](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ud)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ud)</sub>
    + 顶行<kbd>g</kbd><kbd>g</kbd>
    + 上移<kbd>k</kbd>　且到行首<kbd>-</kbd>
    + 某行<kbd>Number</kbd><kbd>g</kbd><kbd>g</kbd>　或<kbd>Number</kbd><kbd>G</kbd>
    + 下移<kbd>j</kbd>　且到行首<kbd>=</kbd>
    + 底行<kbd>G</kbd>
+ [motion: Text object](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_tm)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_tm)</sub>
    + 前词头<kbd>b</kbd>　前词尾<kbd>g</kbd><kbd>e</kbd>　后词头<kbd>w</kbd>　后词尾<kbd>e</kbd>
    + 前串头<kbd>B</kbd>　前串尾<kbd>g</kbd><kbd>E</kbd>　后串头<kbd>W</kbd>　后串尾<kbd>E</kbd>
+ [motion: Pattern searches](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_pa)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_pa)</sub>
    + 前文查找<kbd>?</kbd>`Pattern`<kbd>Enter</kbd>　后文查找<kbd>/</kbd>`Pattern`<kbd>Enter</kbd>
    + 前文重复查找<kbd>?</kbd><kbd>Enter</kbd>　反向重复查找<kbd>N</kbd>　顺向重复查找<kbd>n</kbd>　后文重复查找<kbd>/</kbd><kbd>Enter</kbd>
    + 前文查找光标下标识符<kbd>#</kbd>　后文查找光标下标识符<kbd>*</kbd>
+ [motion: Marks](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ma)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ma)</sub>
    + 标记局部位置<kbd>m</kbd><kbd>a-z</kbd>　标记全局位置<kbd>m</kbd><kbd>A-Z</kbd>　跳转到标记位置<kbd>\`</kbd><kbd>A-Za-z</kbd>　标记表<kbd>:</kbd>`marks`<kbd>Enter</kbd>
    + 旧向跳转<kbd>Ctrl-O</kbd>　新向跳转<kbd>Ctrl-I</kbd>　回跳<kbd>\`</kbd><kbd>\`</kbd>　跳转到最后编辑处<kbd>\`</kbd><kbd>"</kbd>　跳转表<kbd>:</kbd>`ju`<kbd>Enter</kbd>
+ [motion: Various](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_vm)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_vm)</sub>
    + 字符匹配<kbd>%</kbd>
    + 窗口　顶行<kbd>H</kbd>　中行<kbd>M</kbd>　底行<kbd>L</kbd>
+ [motion: Using tags](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ta)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ta)</sub>
    + 标签跳出<kbd>Ctrl-T</kbd>　标签跳入<kbd>Ctrl-]</kbd>
+ [Scrolling](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_sc)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_sc)</sub>
    + 上滚一页<kbd>Ctrl-B</kbd>
    + 上滚半页<kbd>Ctrl-U</kbd>
    + 上滚一行<kbd>Ctrl-Y</kbd>
    + 此行置顶<kbd>z</kbd><kbd>t</kbd>　且到行首<kbd>z</kbd><kbd>Enter</kbd>
    + 此行置中<kbd>z</kbd><kbd>z</kbd>　且到行首<kbd>z</kbd><kbd>.</kbd>
    + 此行置底<kbd>z</kbd><kbd>b</kbd>　且到行首<kbd>z</kbd><kbd>-</kbd>
    + 下滚一行<kbd>Ctrl-E</kbd>
    + 下滚半页<kbd>Ctrl-D</kbd>
    + 下滚一页<kbd>Ctrl-F</kbd>
+ [insert: Inserting text](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_in)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_in)</sub>
    + 上建一行并编辑<kbd>O</kbd>
    + 顶格插入<kbd>g</kbd><kbd>I</kbd>　行首插入<kbd>I</kbd>　字符前插入<kbd>i</kbd>　字符后插入<kbd>a</kbd>　底格插入<kbd>A</kbd>
    + 下建一行并编辑<kbd>o</kbd>
+ [insert: Keys](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ai)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ai)</sub>
    + 离开插入模式`i_`<kbd>ESC</kbd>　或`i_`<kbd>Ctrl-C</kbd>
+ [insert: Special keys](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ss)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ss)</sub>
    + 插入光标上方字符`i_`<kbd>Ctrl-Y</kbd>　插入光标下方字符`i_`<kbd>Ctrl-E</kbd>
    + 粘贴`i_`<kbd>Ctrl-R</kbd><kbd>Register</kbd>
    + 清空整行`i_`<kbd>Ctrl-U</kbd>　删除前一单词`i_`<kbd>Ctrl-W</kbd>
    + 减少缩进`i_`<kbd>Ctrl-D</kbd>　增加缩进`i_`<kbd>Ctrl-T</kbd>
+ [insert: Digraphs](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_di)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_di)</sub>
+ [insert: Special inserts](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_si)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_si)</sub>
+ [change: Deleting text](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_de)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_de)</sub>
    + 删除<kbd>d</kbd><kbd>Motion...</kbd>
    + 删除整行<kbd>d</kbd><kbd>d</kbd>　删除光标前字符<kbd>X</kbd>　删除光标处字符<kbd>x</kbd>　删除至底格<kbd>D</kbd>
    + 连接下行<kbd>J</kbd>
+ [change: Copying and moving](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_cm)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_cm)</sub>
    + 指定寄存器<kbd>"</kbd><kbd>Register</kbd>　寄存表<kbd>:</kbd>`reg`<kbd>Enter</kbd>
    + [registers](http://vimdoc.sourceforge.net/htmldoc/change.html#registers)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/change.html#registers)</sub>
    + 复制<kbd>y</kbd><kbd>Motion...</kbd>
    + 复制整行<kbd>y</kbd><kbd>y</kbd>　或<kbd>Y</kbd>
    + 光标前粘贴<kbd>P</kbd>　光标后粘贴<kbd>p</kbd>
+ [change: Changing text](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ch)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ch)</sub>
    + 修改<kbd>c</kbd><kbd>Motion...</kbd>
    + 修改整行<kbd>c</kbd><kbd>c</kbd>　或<kbd>S</kbd>　修改光标处字符<kbd>s</kbd>　修改至底格<kbd>C</kbd>
    + 替换光标处字符<kbd>r</kbd><kbd>Character</kbd>　替换模式<kbd>R</kbd>
    + 翻转大小写<kbd>~</kbd>　数值自减<kbd>Ctrl-X</kbd>　数值自增<kbd>Ctrl-A</kbd>
+ [change: Complex](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_co)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_co)</sub>
    + 格式化<kbd>=</kbd><kbd>Motion...</kbd>
	+ 格式化整行<kbd>=</kbd><kbd>=</kbd>
+ [Visual mode](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_vi)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_vi)</sub>
+ [Text objects](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_to)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_to)</sub>
    + 单词`v_`<kbd>a/i</kbd><kbd>w</kbd>　字串`v_[ai]W`　句子`v_[ai]s`entence　段落`v_[ai]p`aragraph　a/inner
    + 圆括号块`v_[ai](`　方括号块`v[ai][`　花括号块`v_[ai]{`　尖括号块`v_[ai]<`　标签块`v_[ai]t`
    + 单引号字符串`v_[ai]'`　双引号字符串`v_[ai]"`　反引号字符串`` v_[ai]` ``
+ [Repeating commands](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_re)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_re)</sub>
    + 重复改动<kbd>.</kbd>
+ [Key mapping](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_km)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_km)</sub>
+ [Abbreviations](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ab)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ab)</sub>
+ [Options](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_op)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_op)</sub>
+ [Undo/Redo commands](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ur)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ur)</sub>
    + 撤销改动<kbd>u</kbd>　恢复改动<kbd>Ctrl-R</kbd>　恢复整行改动<kbd>U</kbd>
+ [External commands](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_et)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_et)</sub>
    + 关键字查询<kbd>K</kbd>
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
    + 纵向分割窗口<kbd>Ctrl-W</kbd><kbd>s</kbd>　横向分割窗口<kbd>CTRL-W</kbd><kbd>v</kbd>
    + 重置窗口尺寸<kbd>Ctrl-W</kbd><kbd>=</kbd>
    + 减少窗口高度<kbd>CTRL-W</kbd><kbd>-</kbd>　增加窗口高度<kbd>CTRL-W</kbd><kbd>+</kbd>　设置窗口高度<kbd>CTRL-W</kbd><kbd>_</kbd>
    + 减少窗口宽度<kbd>CTRL-W</kbd><kbd><</kbd>　增加窗口宽度<kbd>CTRL-W</kbd><kbd>></kbd>　设置窗口宽度<kbd>CTRL-W</kbd><kbd>|</kbd>
    + 活动到上一窗口<kbd>CTRL-W</kbd><kbd>p</kbd>　活动到下一窗口<kbd>CTRL-W</kbd><kbd>w</kbd>
    + 活动到左侧窗口<kbd>CTRL-W</kbd><kbd>h</kbd>　活动到右侧窗口<kbd>CTRL-W</kbd><kbd>l</kbd>
    + 活动到顶部窗口<kbd>CTRL-W</kbd><kbd>t</kbd>　活动到上侧窗口<kbd>CTRL-W</kbd><kbd>k</kbd>　活动到下侧窗口<kbd>CTRL-W</kbd><kbd>j</kbd>　活动到底部窗口<kbd>CTRL-W</kbd><kbd>b</kbd>
    + 顺时针调整窗口<kbd>CTRL-W</kbd><kbd>r</kbd>　逆时针调整窗口<kbd>CTRL-W</kbd><kbd>R</kbd>　窗口对调<kbd>CTRL-W</kbd><kbd>x</kbd>
    + 关闭当前窗口<kbd>CTRL-W</kbd><kbd>c</kbd>　仅保留当前窗口<kbd>CTRL-W</kbd><kbd>o</kbd>
+ [Buffer list commands](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_bu)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_bu)</sub>
+ [Syntax highlighting](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_sy)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_sy)</sub>
+ [GUI commands](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_gu)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_gu)</sub>
+ [Folding](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_fo)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_fo)</sub>
    + 关闭折叠至顶<kbd>z</kbd><kbd>C</kbd>　关闭折叠<kbd>z</kbd><kbd>c</kbd>　打开折叠<kbd>z</kbd><kbd>o</kbd>　打开折叠至底<kbd>z</kbd><kbd>O</kbd>
    + 关闭所有折叠至顶<kbd>z</kbd><kbd>M</kbd>　关闭所有折叠<kbd>z</kbd><kbd>m</kbd>　打开所有折叠<kbd>z</kbd><kbd>r</kbd>　打开所有折叠至底<kbd>z</kbd><kbd>R</kbd>
    + 禁用折叠<kbd>z</kbd><kbd>n</kbd>　启用折叠<kbd>z</kbd><kbd>N</kbd>　开关折叠<kbd>z</kbd><kbd>i</kbd>
+ More
    + 左一标签页<kbd>g</kbd><kbd>T</kbd>　右一标签页<kbd>g</kbd><kbd>t</kbd>　某标签页<kbd>Number</kbd><kbd>g</kbd><kbd>t</kbd>

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
