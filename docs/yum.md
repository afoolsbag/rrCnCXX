# 包管理工具 `yum` (yellow dog updater, modified)

适用于 CentOS 和 RHEL 的包管理工具，使用 `rpm` (redhat package manager) 格式安装包。

## 切换镜像源

### CentOS

```sh
# 切换到目录，以简化后续命令中的路径输入
[user@host *]$ cd /etc/yum.repos.d

# 移除并备份原始源
[user@host yum.repos.d]$ sudo mv CentOS-Base.repo CentOS-Base.repo.bak

# 下载并配置阿里云镜像源 (https://developer.aliyun.com/mirror/)
[user@host yum.repos.d]$ sudo curl -o CentOS-Base.repo http://mirrors.aliyun.com/repo/Centos-6.repo
# Or CentOS 7            sudo curl -o CentOS-Base.repo http://mirrors.aliyun.com/repo/Centos-7.repo
# Or CentOS 8            sudo curl -o CentOS-Base.repo http://mirrors.aliyun.com/repo/Centos-8.repo
```

## 添加额外源

### CentOS

```sh
# Software Collections (https://wiki.centos.org/AdditionalResources/Repositories/SCL)
[user@host *]$ sudo yum install centos-release-scl

# Extra Packages for Enterprise (https://fedoraproject.org/wiki/EPEL)
[user@host *]$ sudo yum install epel-release
```

## 同步索引

### CentOS

```sh
[user@host *]$ yum clean all
[user@host *]$ yum makecache
```

## 更新包

### CentOS

```sh
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
