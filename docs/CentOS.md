# GNU/Linux 发行版 [*CentOS*](https://centos.org/) 操作系统

## 安装

### 语言环境

```sh
# 可能的，安装语言环境
[user@host *]$ sudo yum install glibc-locale-source
[user@host *]$ sudo yum install glibc-langpack-en

# 可能的，定义语言环境
[user@host *]$ sudo localedef --inputfile=en_US \
                              --charmap=UTF-8 \
                              --verbose \
                              en_US.UTF-8

# 可能的，修改会话语言环境
[user@host *]$ locale                              # 当前会话语言环境
[user@host *]$ locale --all-locales                # 列出可用语言环境
[user@host *]$ vim ~/.bash_profile                 # 设置语言环境
# LANG="zh_CN.utf8"

# 可能的，修改系统语言环境
[user@host *]$ localectl status                    # 当前系统语言环境
[user@host *]$ localectl list-locales              # 列出可用语言环境
[user@host *]$ sudo localectl set-locale <locale>  # 设置语言环境
```
