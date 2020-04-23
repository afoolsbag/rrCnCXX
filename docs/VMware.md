# 虚拟机 [*VMware*](https://vmware.com/)

## 安装 VMware Tools

*   虚拟系统拥有虚拟 CD/DVD 驱动设备
*   用户拥有管理员权限

### CentOS

```sh
# 查找 CD/DVD 设备
[user@host *]$ lsblk

# 创建目录并挂载设备
[user@host *]$ sudo mkdir /mnt/cdrom
[user@host *]$ sudo mount /dev/<rom> /mnt/cdrom

# 复制安装包并解压
[user@host *]$ cd ~
[user@host ~]$ cp /mnt/cdrom/VMwareTools-<*> .
[user@host ~]$ tar -xavf VMwareTools-<*>

# 安装依赖
[user@host *]$ sudo yum install perl

# 安装 VMware Tools
[user@host *]# sudo ~/vmware-tools-distrib/vmware-install.pl --default

```
