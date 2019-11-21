# [Cheat Engine](https://cheatengine.org/)

## [汇编](https://wiki.cheatengine.org/index.php?title=Assembler)

### [寄存器](https://wiki.cheatengine.org/index.php?title=Assembler#Purpose)

| name                       | term                | description
| :------------------------- | :------------------ | :------
| `RAX`/`EAX`/`AX`/`AH`/`AL` | accumulator         | 累加器
| `RBX`/`EBX`/`BX`/`AH`/`BL` | base index          | 基址索引，用于数组
| `RCX`/`ECX`/`CX`/`CH`/`CL` | counter             | 计数器，用于循环和字符串
| `RDX`/`EDX`/`DX`/`DH`/`DL` |                     | 用于扩展累加器的精度
| `RSI`/`ESI`/`SI`           | source index        | 源索引，用于字符串操作
| `RDI`/`EDI`/`DI`           | destination index   | 目的索引，用于字符串操作
| `RBP`/`EBP`/`BP`           | base pointer        | 栈基指针
| `RSP`/`ESP`/`SP`           | stack pointer       | 栈顶指针
| `R8`/`R8D`/`R8W`/`R8B`     |                     |
| `R9`/`R9D`/`R9W`/`R9B`     |                     |
| `R10`/`R10D`/`R10W`/`R10B` |                     |
| `R11`/`R11D`/`R11W`/`R11B` |                     |
| `R12`/`R12D`/`R12W`/`R12B` |                     |
| `R13`/`R13D`/`R13W`/`R13B` |                     |
| `R14`/`R14D`/`R14W`/`R14B` |                     |
| `R15`/`R15D`/`R15W`/`R15B` |                     |
| `RIP`/`EIP`/`IP`           | instruction pointer | 指令指针
| `CS`                       | code segment        | 代码段
| `DS`                       | data segment        | 数据段
| `SS`                       | stack segment       | 栈段
| `ES`                       | extra segment       | 附加段
| `FS`                       | extra segment #2    | 附加段 #2
| `GS`                       | extra segment #3    | 附加段 #3

`R?X` register, `E?X` extended, `?X` hex, `?H` high, `?L` low;
`R?` register, `R?D` double-word, `R?W` word, `R?B` byte.

```
<                            R?X/R?I/R?P/R?                           >
                                    <          E?X/E?I/E?P/R?D        >
                                                      <  ?X/?I/?P/R?B >
                                                      <  ?H  > <?L/R?B>
........ ........ ........ ........ ........ ........ ........ ........
63    56 55    48 47    40 39    32 31    24 23    16 15     8 7      0
```

![https://wiki.cheatengine.org/index.php?title=Assembler#Structure](https://wiki.cheatengine.org/images/2/2c/Table_of_x86_Registers_svg.svg.png)

### [指令](https://wiki.cheatengine.org/index.php?title=Assembler:Commands)

| name    | term | description
| :------ | :--- | :----------
| `[`*`]` |      | 解引用，类似于 C 语言中的 `*` 操作符
| `MOV`   | move | [`move [size] <destination>, <source>`](https://wiki.cheatengine.org/index.php?title=Assembler:Commands:MOV)
