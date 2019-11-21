# [`readelf`](https://linux.die.net/man/1/readelf)

```shell script
# Excutable and Linking Format
fish> readelf <option(s)> <elf-file(s)>

Options:
  -a --all              # 等同于下行参数
     -h -l -S -s -r -d -V -A -I
  -h --file-header      # 文件头
  -l --program-headers  # 程序头
     --segments
  -S --section-headers  # 节头
     --sections
  -s --syms             # 符号表
     --symbols
  -r --relocs
  -d --dynamic
  -V --version-info
  -I --histogram

  --dyn-syms            # 动态符号表
```

## [`ldd`](https://linux.die.net/man/1/ldd)
```
fish> ldd [option(s)] <file(s)>
```
