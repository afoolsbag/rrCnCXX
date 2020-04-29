# 命令行壳层 [*fish*](https://fishshell.com/) (friendly interactive shell)

跨平台的命令行壳层。

## 查询当前壳层

```fish
user@host *> echo $SHELL
```

## 安装 fish

### Arch

```sh
sudo pacman -S fish
```

### CentOS

```sh
# 安装 fish 2
[user@host *]$ sudo yum install fish

# 安装 fish 3
[user@host *]$ sudo wget --directory-prefix=/etc/yum.repos.d https://download.opensuse.org/repositories/shells:fish:release:3/RedHat_RHEL-6/shells:fish:release:3.repo
# CentOS 7     sudo wget --directory-prefix=/etc/yum.repos.d https://download.opensuse.org/repositories/shells:fish:release:3/RHEL_7/shells:fish:release:3.repo
# CentOS 8     sudo wget --directory-prefix=/etc/yum.repos.d https://download.opensuse.org/repositories/shells:fish:release:3/CentOS_8/shells:fish:release:3.repo
[user@host *]$ sudo yum install fish
```

### Kali

```sh
# 安装 fish 3
user@host:*$ sudo apt install fish
```

### Ubuntu

```sh
# 安装 fish 2
user@host:*$ sudo apt install fish

# 安装 fish 3
user@host:*$ sudo apt-add-repository ppa:fish-shell/release-3
user@host:*$ sudo apt update
user@host:*$ sudo apt install fish
```

## 切换默认壳层

```fish
user@host *> cat /ect/shells        # 展示可用壳层
user@host *> sudo vim /etc/shells   # 编辑可用壳层

user@host *> chsh --shell /usr/bin/fish  # 切换默认壳层（重新登陆以生效）
# 或
user@host *> sudo vim /etc/passwd        # 切换默认壳层（重新登录以生效）
```

## 壳层环境

## bash

```text
# 系统环境变量（键值对列表）
/etc/environment

# 系统配置（脚本）
/etc/profile
/etc/profile.d/*.sh
/etc/profile.d/sh.local  # CentOS

# 系统壳层配置（脚本）
/etc/bash.bashrc  # Ubuntu
/etc/bashrc       # CentOS

# 用户环境变量（键值对）
~/.pam_environment  # Ubuntu

# 用户配置（脚本）
~/.profile

# 用户壳层配置（脚本）
~/.bash_profile
~/.bashrc
```

```sh
export PATH="${PATH}:/path/to/directory"
```

## fish

```text
# 系统配置（脚本）
/etc/fish/config.fish
/etc/fish/conf.d/*.fish

# 用户配置（脚本）
~/.config/fish/config.fish
~/.config/fish/conf.d/*.fish
```

```fish
set --export PATH {$PATH} /path/to/directory
```
