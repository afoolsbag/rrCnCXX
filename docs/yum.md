# 包管理工具 `yum` (yellow dog updater, modified)

适用于 CentOS 和 RHEL 的包管理工具，使用 `rpm` (redhat package manager) 格式安装包。

## 配置源、同步索引和更新包

### CentOS

```sh
# 移除并备份原始源
[user@host *]$ sudo mv /etc/yum.repos.d/CentOS-Base.repo /etc/yum.repos.d/CentOS-Base.repo.bak

# 下载并应用阿里云镜像源 (https://developer.aliyun.com/mirror/centos)
[user@host *]$ sudo curl -o /etc/yum.repos.d/CentOS-Base.repo http://mirrors.aliyun.com/repo/Centos-6.repo
# CentOS 7     sudo curl -o /etc/yum.repos.d/CentOS-Base.repo http://mirrors.aliyun.com/repo/Centos-7.repo
# CentOS 8     sudo curl -o /etc/yum.repos.d/CentOS-Base.repo http://mirrors.aliyun.com/repo/Centos-8.repo

# 启用额外源：Software Collections (https://wiki.centos.org/AdditionalResources/Repositories/SCL)
[user@host *]$ sudo yum install centos-release-scl

# 启用额外源：Extra Packages for Enterprise (https://fedoraproject.org/wiki/EPEL)
[user@host *]$ sudo yum install epel-release

# 同步索引
[user@host *]$ yum clean all
[user@host *]$ yum makecache

# 更新包
[user@host *]$ sudo yum update
```

## 搜索、展示、安装、卸载包

### CentOS

```sh
[user@host *]$ yum search <name>           # 搜索
[user@host *]$ yum info <package>          # 展示
[user@host *]$ sudo yum install <packege>  # 安装
[user@host *]$ sudo yum remove <package>   # 卸载
```
