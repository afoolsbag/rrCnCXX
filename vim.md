# [Visual Editor Improved](http://vim.org/)

## References

[*Vim Documentation*](http://vimdoc.sourceforge.net)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net)</sub>
+ [help](http://vimdoc.sourceforge.net/htmldoc/help.html)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/help.html)</sub>
+ [quickref](http://vimdoc.sourceforge.net/htmldoc/quickref.html)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html)</sub>
+ index<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/index.html)</sub>

quickref
+ [motion: Left-right](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_lr)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_lr)</sub>
    + 左移`h`　右移`l`　某列`<num>`
    + 行内　向左搜索`F<char>`　向左搜索到`T<char>`　向右搜索到`t<char>`　向右搜索`f<char>`
    + 行内　重复搜索`;`　反向重复搜索`,`
    + 顶格`0`　行首`^`　行中`gm`　行尾`g_`　底格`$`
+ [motion: Up-down](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ud)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ud)</sub>
    + 上移`k`　下移`j`　上移并置于行首`-`　下移并置于行首`+`
    + 顶行`gg`　底行`G`　某行`<num>gg` `<num>G`
+ [motion: Text object](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_tm)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_tm)</sub>
    + 前一单词头`b`　前一单词尾`ge`　后一单词头`w`　后一单词尾`e`
    + 前一字串头`B`　前一字串尾`gE`　后一字串头`W`　后一字串尾`E`
+ [motion: Pattern searches](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_pa)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_pa)</sub>
    + 前文查找`?<pattern>`　后文查找`/<pattern>`
    + 前文重复查找`?<CR>`　逆向重复查找`N`　顺向重复查找`n`　后文重复查找`/<CR>`
    + 前文查找光标下标识符`#`　后文查找光标下标识符`*`
+ [motion: Marks](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ma)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ma)</sub>
    + 标记局部位置`m{a-z}`　标记全局位置`m{A-Z}`　跳转到标记位置`` `{A-Za-z} ``　标记表`:marks`
    + 旧向跳转`<C-O>`　新向跳转`<C-I>`　回跳``` `` ```　跳转到最后编辑处`` `" ``　跳转表`:ju`
+ [motion: Various](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_vm)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_vm)</sub>
    + 字符匹配`%`
    + 窗口内　顶行`H`　中行`M`　底行`L`
+ [motion: Using tags](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ta)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ta)</sub>
+ [Scrolling](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_sc)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_sc)</sub>
    + 上滚一页`<C-B>`　上滚半页`<C-U>`　上滚一行`<C-Y>`
    + 下滚一行`<C-E>`　下滚半页`<C-D>`　下滚一页`<C-F>`
    + 当前行置顶`zt`　当前行置中`zm`　当前行置底`zb`
+ [insert: Inserting text](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_in)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_in)</sub>
    + 顶格插入`gI`　行首插入`I`　字符前插入`i`　字符后插入`a`　底格插入`A`
    + 上建一行并编辑`O`　下建一行并编辑`o`
+ [insert: Keys](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ai)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ai)</sub>
    + 转回普通模式`i_<ESC>` `i_<C-C>`
+ [insert: Special keys](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ss)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ss)</sub>
    + 粘贴`i_<C-R><reg>`
    + 清空当前行`i_<C-U>`　删除前一单词`i_<C-W>`
    + 减少缩进`i_<C-T>`　增加缩进`i_<C-D>`
+ [insert: Digraphs](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_di)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_di)</sub>
+ [insert: Special inserts](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_si)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_si)</sub>
+ [change: Deleting text](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_de)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_de)</sub>
    + 删除`d<motion>`
    + 删除整行`dd`　删除光标前字符`X`　删除光标处字符`x`　删除至底格`D`
+ [change: Copying and moving](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_cm)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_cm)</sub>
    + 指定寄存器`"<reg>`　寄存表`:reg`
    + [registers](http://vimdoc.sourceforge.net/htmldoc/change.html#registers)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/change.html#registers)</sub>
    + 复制`y<motion>`
    + 光标前粘贴`P`　光标后粘贴`p`
+ [change: Changing text](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ch)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ch)</sub>
    + 修改`c<cotion>`
    + 修改整行`cc` `S`　修改光标处字符`s`　修改至底格`C`
    + 替换光标处字符`r<char>`　替换模式`R`
    + 翻转大小写`~`　数值自减`<C-X>`　数值自增`<C-A>`
+ [change: Complex](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_co)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_co)</sub>
+ [Visual mode](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_vi)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_vi)</sub>
+ [Text objects](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_to)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_to)</sub>
+ [Repeating commands](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_re)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_re)</sub>
    + 重复改动`.`
+ [Key mapping](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_km)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_km)</sub>
+ [Abbreviations](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ab)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ab)</sub>
+ [Options](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_op)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_op)</sub>
+ [Undo/Redo commands](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_ur)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_ur)</sub>
    + 撤销改动`u`　恢复改动`<CTRL-R>`　恢复整行改动`U`
+ [External commands](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_et)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_et)</sub>
    + 关键字查询`K`
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
    + 纵向分割窗口`<C-W><C-S>`　横向分割窗口`<C-W><C-V>`
    + 窗口尺寸　重置高宽`<C-W>=`
    + 窗口尺寸　减少高度`<C-W>-`　增加高度`<C-W>+`　设置高度`<C-W>_`
    + 窗口尺寸　减少宽度`<C-W><`　增加宽度`<C-W>>`  设置宽度`<C-W>|`
    + 窗口跳转　上一`<C-W><C-P>`　下一`<C-W><C-W>`
    + 窗口跳转　左侧`<C-W><C-H>`　右侧`<C-W><C-L>`
    + 窗口跳转　顶部`<C-W><C-T>`　上侧`<C-W><C-K>`　下侧`<C-W><C-J>`　底部`<C-W><C-B>`
    + 窗口调整　顺时针`<C-W><C-R>`　逆时针`<C-W>R`　对调`<C-W><C-X>`
    + 关闭当前窗口`<C-W>c`　仅保留当前窗口`<C-W><C-O>`
+ [Buffer list commands](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_bu)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_bu)</sub>
+ [Syntax highlighting](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_sy)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_sy)</sub>
+ [GUI commands](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_gu)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_gu)</sub>
+ [Folding](http://vimdoc.sourceforge.net/htmldoc/quickref.html#Q_fo)<sub> [*cmn-Hans*](http://vimcdoc.sourceforge.net/doc/quickref.html#Q_fo)</sub>
    + 关闭折叠至顶`zC`　关闭折叠`zc`　打开折叠`zo`　打开折叠至底`zO`
    + 关闭所有折叠至顶`zM`　关闭所有折叠`zm`　打开所有折叠`zr`　打开所有折叠至底`zR`
    + 禁用折叠`zn`　启用折叠`zN`　开关折叠`zi`
+ More
    + 左一标签页`gT`　右一标签页`gT`　某标签页`<num>gt`

___
<a rel="license" href="http://creativecommons.org/licenses/by/4.0/"><img alt="知识共享许可协议" style="border-width:0" src="https://i.creativecommons.org/l/by/4.0/88x31.png" /></a><br />本作品采用<a rel="license" href="http://creativecommons.org/licenses/by/4.0/">知识共享署名 4.0 国际许可协议</a>进行许可。
