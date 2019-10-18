# zhengrr 所知的 Assembly                                            {#mainpage}

目前编译器优化十分疯狂，业余人员手工汇编反倒弄巧成拙，仅建议在调用扩展指令集优化热点时使用汇编。

单指令流多数据流 x86 架构扩展指令集：

| Year | x86 IS. | `x86intrin.h` |
| ---: | :------ | :------------ |
| 1996 | MMX     | `mmintrin.h`  |
| 1998 | 3DNow!  |               |
| 1999 | SSE     | `xmmintrin.h` |
| 2001 | SSE2    | `emmintrin.h` |
| 2004 | SSE3    | `pmmintrin.h` |
| 2006 | SSE3s   | `tmmintrin.h` |
|      | SSE4.1  | `smmintrin.h` |
|      | SSE4.2  | `nmmintrin.h` |
|      | SSE4a   | `ammintrin.h` |
| 2007 | SSE5    |               |
| 2008 | AVX     | `immintrin.h` |
| 2009 | F16C    |               |
|      | XOP     |               |
| 2011 | FMA4    |               |
| 2013 | FMA3    |               |
|      | AVX2    |               |
| 2015 | AVX-512 | `zmmintrin.h` |

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
