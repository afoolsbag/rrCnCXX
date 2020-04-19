# 使用 `yum` 安装开发工具集的示例

### CentOS

```sh
# 配置镜像源和额外源
# ......

# 安装 Networking Toolkit
[user@host *]$ sudo yum install net-tools

# 安装 Open SSH Server 并启用
[user@host *]$ sudo yum install openssh-server
[user@host *]$ sudo systemctl start sshd

# 安装 VIM
[user@host *]$ sudo yum install vim

# 安装默认版本 GCC
[user@host *]$ sudo yum group install 'Development Tools'

# 若有需要，安装指定版本 GCC，并切换到指定环境
[user@host *]$ sudo yum install devtoolset-6 devtoolset-7 devtoolset-8 devtoolset-9
[user@host *]$ scl enable devtoolset-9 bash

# 安装 pip3
[user@host *]$ sudo yum install python3
# 确保 PATH 环境变量包含 /usr/local/bin

# 配置 pip 源为豆瓣源
[user@host *]$ vim ~/.config/pip/pip.conf
# [global]
# index-url = https://pypi.doubanio.com/simple

# 安装 CMake
[user@host *]$ sudo pip3 install cmake

# 安装 Conan
[user@host *]$ sudo pip3 install conan
```
