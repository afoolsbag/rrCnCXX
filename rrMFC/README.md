# [Microsoft Foundation Class Library](https://docs.microsoft.com/cpp/mfc)

## Programming Styles

+ ["Why use prefixes on member variables in C++ classes"](https://stackoverflow.com/questions/1228161). *Stack Overflow*.
+ ["Framework Design Guidelines"](https://docs.microsoft.com/dotnet/standard/design-guidelines). *Microsoft® Docs*.

### `resource.h`

| prefix | Recommend Range | brief            | Required Range  |               |
|:------ | ---------------:|:---------------- | ---------------:| -------------:|
| `IDF`  |     `101–  285` | frame            |    `0x1–0x6FFF` |     `1–28671` |
| `IDR`  |   `101xx–285xx` | multiple         |    `0x1–0x6FFF` |     `1–28671` |
| `IDC`  |   `101xx–285xx` | cursors          |    `0x1–0x6FFF` |     `1–28671` |
| `IDI`  |   `101xx–285xx` | icons            |    `0x1–0x6FFF` |     `1–28671` |
| `IDM`  |   `101xx–285xx` | menus            |    `0x1–0x6FFF` |     `1–28671` |
| `IDA`  |   `101xx–285xx` | accelerator      |    `0x1–0x6FFF` |     `1–28671` |
| `IDD`  |   `101xx–285xx` | dialog templates |    `0x1–0x6FFF` |     `1–28671` |
| `IDB`  |   `101xx–285xx` | bitmaps          |    `0x1–0x6FFF` |     `1–28671` |
| `IDS`  |   `101xx–285xx` | strings          |    `0x1–0x7FFF` |     `1–32767` |
| `IDP`  |   `101xx–285xx` | prompts          |    `0x1–0x7FFF` |     `1–32767` |
| `ID`   |   `40001–49999` | commands         | `0x8000–0xDFFF` | `32768–57343` |
| `IDC`  |   `50001–57343` | controls         |    `0x8–0xDFFF` |     `8–57343` |

## Guides

*Programming Windows® with MFC*. Jeff Prosise.

["MFC Tutorial"](https://www.tutorialspoint.com/mfc/). *Tutorials Point*.

___
<a rel="license" href="http://creativecommons.org/licenses/by/4.0/"><img alt="知识共享许可协议" style="border-width:0" src="https://i.creativecommons.org/l/by/4.0/88x31.png" /></a><br />本作品采用<a rel="license" href="http://creativecommons.org/licenses/by/4.0/">知识共享署名 4.0 国际许可协议</a>进行许可。
