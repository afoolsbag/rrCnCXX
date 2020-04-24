# 使用 `pacman` 安装开发工具的示例

### Arch

```sh
# 安装 Networking Toolkit
[user@host *]$ sudo pacman -S net-tools

# 安装 Open SSH Server
[user@host *]$ sudo pacman -S openssh

# 安装 VIM
[user@host *]$ sudo pacman -S vim

# 安装 GCC
[user@host *]$ sudo pacman -S base-devel

# 安装 pip3
[user@host *]$ sudo pacman -S python-pip

# 配置 pip 源为豆瓣源
[user@host *]$ vim ~/.config/pip/pip.conf
# [global]
# index-url = https://pypi.doubanio.com/simple

# 安装 CMake
[user@host *]$ sudo pip install cmake

# 安装 Conan
[user@host *]$ sudo pip install conan
```
