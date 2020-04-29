# 使用 `yum` 安装开发工具集的示例

### CentOS

```sh
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

# 若有需要，安装新版 Git
[user@host *]$ sudo yum install asciidoc xmlto docbook2x
[user@host *]$ sudo yum remove git
[user@host ~]$ wget https://mirrors.edge.kernel.org/pub/software/scm/git/git-2.26.2.tar.xz
[user@host ~]$ tar -xavf git-2.26.2.tar.xz
[user@host ~]$ cd git-2.26.2
[user@host git-2.26.2]$ make configure
[user@host git-2.26.2]$ ./configure [--prefix=/usr]
[user@host git-2.26.2]$ make all doc info
[user@host git-2.26.2]$ sudo make install install-doc install-html install-info

# 安装 pip3
[user@host *]$ sudo yum install python3
# 确保 PATH 环境变量包含 ~/.local/bin
# 确保 sys.path (PYTHONPATH) 环境变量包含 ~/.local/lib/python3.?/site-packages

# 配置 pip 源为豆瓣源
[user@host *]$ vim ~/.config/pip/pip.conf
# [global]
# index-url = https://pypi.doubanio.com/simple

# 安装 CMake
[user@host *]$ pip3 install cmake --user

# 安装 Conan
[user@host *]$ pip3 install conan --user
```
