# GNU/Linux 操作系统

## 目录结构说明

```text
/              #                      根目录
+ bin          # binary               预装程序目录（由系统发行商维护）
+ boot         # boot                 启动相关目录
+ dev          # device               设备目录
+ etc          # et cetera            配置目录
+ home/<user>  #                      用户主目录
+ lib          # library              预装库目录（由系统发行商维护）
+ lost+found
+ media        # media                媒体设备的临时挂载目录
+ mnt          # mount                文件设备的临时挂载目录
+ opt          # optional             选装程序目录
+ proc         # process              内核映射目录
+ root         #                      系统管理员用户主目录
+ sbin         # system binary        预装系统程序目录（由系统发行商维护）
+ srv          # service              服务相关目录
+ sys          # system               设备映射目录
+ tmp          # temporary            临时文件目录（重启清空）
+ usr
| + bin        # user binary          用户程序目录（由包管理器维护）
| + include    # user include         用户包含文件目录（由包管理器维护）
| + lib        # user library         用户库目录（由包管理器维护）
| + lobal
| | + bin      # user binary          用户本地程序目录
| | + include  # user include         用户本地包含文件目录
| | + lib      # user library         用户本地库目录
| | + sbin     # user system library  用户本地系统程序目录
| | + share    # user share           用户本地共享文件目录
| | + src      # user source          用户本地源文件目录
| + sbin       # user system library  用户系统程序目录（由包管理器维护）
| + share      # user share           用户共享文件目录（由包管理器维护）
| + src        # user source          用户源文件目录（由包管理器维护）
+ var          # variable             变量目录
  + log        #                      日志目录
```

## 系统信息

```fish
# 查看发行版信息
user@host *> lsb_release -a (--all)
# 或者
user@host *> cat /etc/os-release

# CentOS
user@host *> cat /etc/redhat-release


# 查看处理器信息
user@host *> cat /proc/cpuinfo

# 查看内存信息
user@host *> free -h (--human)

# 查看硬盘信息
user@host *> lsblk
```

## 符号链接

```sh
ln -s <target-path> <new-path>
```

## 配置静态 IPv4

### Kali

图形用户界面，略。

### CentOS

```sh
[user@host *]$ sudo vim /etc/sysconfig/network-scripts/ifcfg-en<*>
```

```/etc/sysconfig/network-scripts/ifcfg-en<*>
# 动态网络配置
BOOTPROTO=dhcp

# 静态网络配置
BOOTPROTO=static
IPADDR=192.168.0.1
NETMASK=255.255.255.0
GATEWAY=192.168.0.254
DNS1=223.6.6.6
DNS2=8.8.8.8
```

```sh
[user@host *]$ sudo systemctl restart network
```

### Ubuntu Desktop

图形用户界面，略。
