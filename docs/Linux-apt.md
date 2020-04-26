# 包管理工具 apt（advanced packaging tool）

适用于 Debian、Kali 和 Ubuntu 的包管理工具，使用 dpkg（debian package）格式安装包。

*   [“dpkg”](https://wiki.debian.org/dpkg). *Debian Wiki*.
*   [“dpkg”](https://help.ubuntu.com/lts/serverguide/dpkg.html). *Official Ubuntu Documentation*.
*   [“AptCLI”](https://wiki.debian.org/AptCLI). *Debian Wiki*.
*   [“Apt”](https://help.ubuntu.com/lts/serverguide/apt.html). *Official Ubuntu Documentation*.

## 配置源、同步索引和更新包

### Kali

```sh
# 备份原始源
user@host:*$ sudo cp /etc/apt/sources.list /etc/apt/sources.list.bak

# 配置中科大镜像源（https://mirrors.ustc.edu.cn/kali/）
user@host:*$ sudo vim /etc/apt/sources.list
# deb https://mirrors.ustc.edu.cn/kali kali-rolling main non-free contrib
# deb-src https://mirrors.ustc.edu.cn/kali kali-rolling main non-free contrib

# 同步索引
user@host:*$ sudo apt update

# 更新包
user@host:*$ sudo apt upgrade
```

### Ubuntu

```sh
# 备份原始源
user@host:*$ sudo cp /etc/apt/sources.list /etc/apt/sources.list.bck

# 配置阿里云镜像源 (https://developer.aliyun.com/mirror/ubuntu)
user@host:*$ sudo vim /etc/apt/sources.list
# :%s/archive\.ubuntu\.com/mirrors.aliyun.com/g

# 同步索引
user@host:*$ sudo apt update

# 更新包
user@host:*$ sudo apt upgrade
```

## 搜索、展示、安装、卸载包

```fish
user@host *> apt search <name>           # 搜索
user@host *> apt show <package>          # 展示
user@host *> sudo apt install <package>  # 安装
user@host *> sudo apt remove <package>   # 卸载
user@host *> sudo apt autoremove         # 卸载残留依赖
```

## 离线安装、更新工具 [Keryx](https://launchpad.net/keryx)
