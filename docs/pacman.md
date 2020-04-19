# 包管理器 `pacman`

`pacman` 包管理器适用于 Arch。

## 配置源、同步索引和更新包

```shell
# 配置镜像源
sudo vim /etc/pacman.d/mirrorlist

# 同步索引
sudo pacman -Sy

# 同步索引并更新包
sudo pacman -Syu
```

## 搜索、展示、安装、卸载包

```shell
pacman -Ss <name>                # 搜索
pacman -Si <package>             # 展示
sudo pacman -S <package>         # 安装
sudo pacman -R <package>         # 卸载
sudo pacman -Rs $(pacman -Qtdq)  # 卸载残留依赖
```

## Arch 开发工具链的安装示例

```shell
# 配置镜像源
# ......

# 安装 Networking Toolkit
sudo pacman -S net-tools

# 安装 Open SSH Server
sudo pacman -S openssh

# 安装 VIM
sudo pacman -S vim

# 安装 GCC
sudo pacman -S base-devel

# 安装 pip3
sudo pacman -S python-pip

# 配置 pip 源
vim ~/.config/pip/pip.conf
# [global]
# index-url = https://pypi.doubanio.com/simple

# 安装 CMake
sudo pip install cmake

# 安装 Conan
sudo pip install conan
```
