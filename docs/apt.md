# 包管理工具 `apt` (advanced packaging tool)

适用于 Debian、Kali 和 Ubuntu 的包管理工具，使用 `dpkg` (debian package) 格式安装包。

*   [“dpkg”](https://wiki.debian.org/dpkg). *Debian Wiki*.
*   [“dpkg”](https://help.ubuntu.com/lts/serverguide/dpkg.html). *Official Ubuntu Documentation*.
*   [“AptCLI”](https://wiki.debian.org/AptCLI). *Debian Wiki*.
*   [“Apt”](https://help.ubuntu.com/lts/serverguide/apt.html). *Official Ubuntu Documentation*.

## 配置源、同步索引和更新包

```shell
# 配置镜像源
sudo vim /etc/apt/sources.list

# Kali with USCT Mirror (https://mirrors.ustc.edu.cn/)
#         deb https://mirrors.ustc.edu.cn/kali kali-rolling main non-free contrib
#         deb-src https://mirrors.ustc.edu.cn/kali kali-rolling main non-free contrib

# Ubuntu 18.04 (bionic) with Alibaba Mirror (https://opsx.alibaba.com/mirror)
#         deb http://mirrors.aliyun.com/ubuntu/ bionic main restricted universe multiverse
#         deb-src http://mirrors.aliyun.com/ubuntu/ bionic main restricted universe multiverse
#         deb http://mirrors.aliyun.com/ubuntu/ bionic-security main restricted universe multiverse
#         deb-src http://mirrors.aliyun.com/ubuntu/ bionic-security main restricted universe multiverse
#         deb http://mirrors.aliyun.com/ubuntu/ bionic-updates main restricted universe multiverse
#         deb-src http://mirrors.aliyun.com/ubuntu/ bionic-updates main restricted universe multiverse
#         deb http://mirrors.aliyun.com/ubuntu/ bionic-proposed main restricted universe multiverse
#         deb-src http://mirrors.aliyun.com/ubuntu/ bionic-proposed main restricted universe multiverse
#         deb http://mirrors.aliyun.com/ubuntu/ bionic-backports main restricted universe multiverse
#         deb-src http://mirrors.aliyun.com/ubuntu/ bionic-backports main restricted universe multiverse

# Ubuntu 16.04 with Alibaba Mirror
#         deb http://mirrors.aliyun.com/ubuntu/ xenial main
#         deb-src http://mirrors.aliyun.com/ubuntu/ xenial main
#         deb http://mirrors.aliyun.com/ubuntu/ xenial-updates main
#         deb-src http://mirrors.aliyun.com/ubuntu/ xenial-updates main
#         deb http://mirrors.aliyun.com/ubuntu/ xenial universe
#         deb-src http://mirrors.aliyun.com/ubuntu/ xenial universe
#         deb http://mirrors.aliyun.com/ubuntu/ xenial-updates universe
#         deb-src http://mirrors.aliyun.com/ubuntu/ xenial-updates universe
#         deb http://mirrors.aliyun.com/ubuntu/ xenial-security main
#         deb-src http://mirrors.aliyun.com/ubuntu/ xenial-security main
#         deb http://mirrors.aliyun.com/ubuntu/ xenial-security universe
#         deb-src http://mirrors.aliyun.com/ubuntu/ xenial-security universe

# 同步索引
sudo apt update

# 更新包
sudo apt upgrade
```

## 搜索、展示、安装、卸载包

```shell
apt search <name>           # 搜索
apt show <package>          # 展示
sudo apt install <package>  # 安装
sudo apt remove <package>   # 卸载
sudo apt autoremove         # 卸载残留依赖
```

## 离线安装、更新工具 [Keryx](https://launchpad.net/keryx)

## Ubuntu 开发工具链的安装示例

```shell
# 配置镜像源
# ......

# 安装 Networking Toolkit
sudo apt install net-tools

# 安装 Open SSH Server
sudo apt install openssh-server

# 安装 VIM
sudo apt install vim

# 安装 GCC
sudo apt install build-essential
# sudo add-apt-repository ppa:ubuntu-toolchain-r/test
# sudo apt update
# sudo apt install gcc-7 g++-7 gcc-8 g++-8 gcc-9 g++-9
# export CC=/usr/bin/gcc-9
# export CXX=/usr/bin/g++-9

# 安装 GDB
sudo apt install gdb

# 安装 pip3
sudo apt install python3-pip
# PATH += ~/.local/bin

# 配置 pip 源
vim ~/.config/pip/pip.conf
# [global]
# index-url = https://pypi.doubanio.com/simple

# 安装 CMake
pip3 install cmake
# 或
wget -P ~ https://cmake.org/files/v3.15/cmake-3.15.5-Linux-x86_64.sh
sudo chmod a+x ~/cmake-3.15.5-Linux-x86_64.sh
sudo ~/cmake-3.15.5-Linux-x86_64.sh --prefix=/usr/local --exclude-subdir --skip-license

# 安装 Conan
pip3 install conan

# 离线安装 MySQL
mkdir ~/mysql-installer
# 从 https://pkgs.org/download/libaio1 下载 libaio1
# ......
# 从 https://pkgs.org/download/libmecab2 下载 libmecab2
# ......
# 从 https://dev.mysql.com/downloads/mysql/ 下载 MySQL
# ......
tar -xavf ~/mysql-installer/mysql-server_<version>.deb-bundle.tar
# 安装
sudo dpkg -i ~/mysql-installer/*.deb
```
