# 使用 `apt` 安装开发工具链的示例

### Ubuntu

```shell
# 安装 Networking Toolkit
user@host:*$ sudo apt install net-tools

# 安装 Open SSH Server
user@host:*$ sudo apt install openssh-server

# 安装 VIM
user@host:*$ sudo apt install vim

# 安装 GCC
user@host:*$ sudo apt install build-essential

# 若有需要，安装指定版本 GCC，并切换到指定环境
user@host:*$ sudo add-apt-repository ppa:ubuntu-toolchain-r/test
user@host:*$ sudo apt update
user@host:*$ sudo apt install gcc-9 g++-9
user@host:*$ export CC=/usr/bin/gcc-9
user@host:*$ export CXX=/usr/bin/g++-9

# 安装 GDB
user@host:*$ sudo apt install gdb

# 安装 pip3
user@host:*$ sudo apt install python3-pip
# 确保 PATH 环境变量包含 ~/.local/bin

# 配置 pip 源
user@host:*$ vim ~/.config/pip/pip.conf
# [global]
# index-url = https://pypi.doubanio.com/simple

# 安装 CMake
user@host:*$ pip3 install cmake
# 或从官网安装包安装
user@host:*$ wget -P ~ https://cmake.org/files/v3.17/cmake-3.17.0-Linux-x86_64.sh
user@host:*$ sudo chmod a+x ~/cmake-3.17.0-Linux-x86_64.sh
user@host:*$ sudo ~/cmake-3.17.0-Linux-x86_64.sh --prefix=/usr/local --exclude-subdir --skip-license

# 安装 Conan
user@host:*$ pip3 install conan

# 离线安装 MySQL
user@host:*$ mkdir ~/mysql-installer
# 从 https://pkgs.org/download/libaio1 下载 libaio1
# ......
# 从 https://pkgs.org/download/libmecab2 下载 libmecab2
# ......
# 从 https://dev.mysql.com/downloads/mysql/ 下载 MySQL
# ......
user@host:*$ tar -xavf ~/mysql-installer/mysql-server_<version>.deb-bundle.tar
# 安装
user@host:*$ sudo dpkg -i ~/mysql-installer/*.deb
```
