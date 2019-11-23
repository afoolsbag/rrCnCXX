# [*Tar*](https://gnu.org/software/tar/)

```shell script
# 操作
tar -c (--create)   # 创建
tar -x (--extract)  # 提取

# 存储形式
tar -f (--file=ARCHIVE)  # 存储为文件

# 压缩算法
tar -j (--bzip2)
tar -J (--xz)
tar --lzip
tar --lzma
tar --lzop
tar -z (--gzip)

# 信息输出
tar -v (--verbose)
```

```shell script
tar -czvf <archive.tar.gz> <source>         # 压缩
tar -xzvf <archive.tar.gz> -C <target-dir>  # 解压

tar -xavf <archive.tar.gz> -C <target-dir>  # 解压
```
