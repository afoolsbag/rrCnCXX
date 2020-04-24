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

```fish
# ~/.bash_profile  # 壳层相关的配置入口
#   ~/.profile     # 壳层无关的用户配置，如 PATH
#   ~/.bashrc      # 壳层相关的用户配置
#     /etc/bashrc  # 壳层相关的通用配置
```

## fish

```fish
# ~/.config/fish/config.fish  # 用户配置

user@host *> set --export PATH {$PATH} /path/to/added
```
