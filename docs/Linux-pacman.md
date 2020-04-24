# 包管理工具 [*pacman*](https://www.archlinux.org/pacman/)

适用于 Arch 的包管理工具。

## 配置源、同步索引和更新包

### Arch

```sh
# 配置镜像源
[user@host *]$ sudo vim /etc/pacman.d/mirrorlist

# 同步索引
[user@host *]$ sudo pacman -Sy

# 同步索引并更新包
[user@host *]$ sudo pacman -Syu
```

## 搜索、展示、安装、卸载包

### Arch

```sh
[user@host *]$ pacman -Ss <name>                # 搜索
[user@host *]$ pacman -Si <package>             # 展示
[user@host *]$ sudo pacman -S <package>         # 安装
[user@host *]$ sudo pacman -R <package>         # 卸载
[user@host *]$ sudo pacman -Rs $(pacman -Qtdq)  # 卸载残留依赖
```
