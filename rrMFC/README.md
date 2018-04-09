# [Microsoft Foundation Class (Library)](https://docs.microsoft.com/cpp/mfc)

## Programming Styles

+ ["Why use prefixes on member variables in C++ classes"](https://stackoverflow.com/questions/1228161). *Stack Overflow*.
+ ["Framework Design Guidelines"](https://docs.microsoft.com/dotnet/standard/design-guidelines). *Microsoft® Docs*.

Default as CXX Programming Styles.

### Naming

+ 宏适用`ALL_UPPER`
+ 局部变量适用`camelCase`
+ 其它适用`PascalCase`

### Formatting

+ Visual Studio Default
+ UTF-8
+ 4 Spaces
+ K&R (functions are special)

### `resource.h`

| prefix | Recommend Range | brief            | Required Range  |               |
|:------ | ---------------:|:---------------- | ---------------:| -------------:|
| `IDR`  | `001 00–285 00` | multiple         |    `0x1–0x6FFF` |     `1–28671` |
| `IDA`  | `001 xx–285 xx` | accelerator      |    `0x1–0x6FFF` |     `1–28671` |
| `IDB`  | `001 xx–285 xx` | bitmaps          |    `0x1–0x6FFF` |     `1–28671` |
| `IDC`  | `001 xx–285 xx` | cursors          |    `0x1–0x6FFF` |     `1–28671` |
| `IDD`  | `001 00–285 00` | dialog templates |    `0x1–0x6FFF` |     `1–28671` |
| `IDF`  | `001 xx-285 xx` | frames           |    `0x1-0x6FFF` |     `1-28671` |
| `IDI`  | `001 xx–285 xx` | icons            |    `0x1–0x6FFF` |     `1–28671` |
| `IDM`  | `001 xx–285 xx` | menus            |    `0x1–0x6FFF` |     `1–28671` |
| `IDS`  | `001 xx–285 xx` | strings          |    `0x1–0x7FFF` |     `1–32767` |
| `IDP`  | `001 xx–285 xx` | prompts          |    `0x1–0x7FFF` |     `1–32767` |
| `ID`   |   `40001–49999` | commands         | `0x8000–0xDFFF` | `32768–57343` |
| `IDC`  |   `50001–57343` | controls         |    `0x8–0xDFFF` |     `8–57343` |

e.g.:
```c++
#define IDR_MAIN_WINDOW                 100  // multiple resources
#define IDF_MAIN_WINDOW                 100  // frame
#define IDI_MAIN_WINDOW                 100  // icon
#define IDS_MAIN_WINDOW                 100  // title
#define IDM_MAIN_WINDOW                 100  // menu
#define IDA_MAIN_WINDOW                 100  // accelerator

#define IDD_MAIN_DIALOG                 200  // dialog templates
#define IDI_MAIN_DIALOG                 200  // icon
#define IDS_MAIN_DIALOG                 200  // tiele

#define IDC_OK_BUTTON                   50001
#define IDC_CANCEL_BUTTON               50002
```

["ID Naming and Numbering Conventions"](https://docs.microsoft.com/cpp/mfc/tn020-id-naming-and-numbering-conventions). *Microsoft® Docs*.

## Guides

*Programming Windows® with MFC*. Jeff Prosise.

["MFC Tutorial"](https://www.tutorialspoint.com/mfc/). *Tutorials Point*.

___
<a rel="license" href="http://creativecommons.org/licenses/by/4.0/"><img alt="知识共享许可协议" style="border-width:0" src="https://i.creativecommons.org/l/by/4.0/88x31.png" /></a><br />本作品采用<a rel="license" href="http://creativecommons.org/licenses/by/4.0/">知识共享署名 4.0 国际许可协议</a>进行许可。
