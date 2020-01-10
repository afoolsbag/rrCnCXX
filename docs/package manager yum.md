# 包管理器 `yum` (yellow dog updater, modified)

`yum` 包管理器使用 `rpm` (redhat package manager) 安装包，适用于 CentOS 和 RHEL。 

## 配置源、同步索引和更新包

```shell
# 配置镜像源
cd /etc/yum.repos.d                            # 切换到目录，以简化后续命令中的路径输入
sudo mv CentOS-Base.repo CentOS-Base.repo.bak  # 备份

# CentOS 7 with Alibaba Mirror (https://opsx.alibaba.com/mirror)
#         sudo curl -o CentOS-Base.repo http://mirrors.aliyun.com/repo/Centos-7.repo

# CentOS 6 with Alibaba Mirror
#         sudo curl -o CentOS-Base.repo http://mirrors.aliyun.com/repo/Centos-6.repo

# 配置额外源
sudo yum install centos-release-scl  # Software Collections (https://wiki.centos.org/AdditionalResources/Repositories/SCL)
sudo yum install epel-release        # Extra Packages for Enterprise (https://fedoraproject.org/wiki/EPEL)

# 同步索引
yum clean all
yum makecache

# 更新包
sudo yum update
```

## 搜索、展示、安装、卸载包

```shell
yum search <name>           # 搜索
yum info <package>          # 展示
sudo yum install <packege>  # 安装
sudo yum remove <package>   # 卸载
```

## CentOS 开发工具链的安装示例

```shell
# 配置镜像源和额外源
# ......

# 安装 Networking Toolkit
sudo yum install net-tools

# 安装 Open SSH Server 并启用
sudo yum install openssh-server
sudo systemctl start sshd

# 安装 VIM
sudo yum install vim

# 安装 GCC
sudo yum group install "Development Tools"
# sudo yum install centos-release-scl
# sudo yum install devtoolset-6 devtoolset-7 devtoolset-8
# scl enable devtoolset-8 fish

# 安装 pip3
sudo yum install python3
# PATH += /usr/local/bin

# 配置 pip 源
vim ~/.config/pip/pip.conf
# [global]
# index-url = https://pypi.doubanio.com/simple

# 安装 CMake
sudo pip3 install cmake

# 安装 Conan
sudo pip3 install conan
```
