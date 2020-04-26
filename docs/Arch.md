# GNU/Linux 发行版 [*Arch*](https://archlinux.org/) 操作系统

## 安装

*   <https://wiki.archlinux.org/index.php/Installation_guide_(简体中文)>
*   Shell 中以管理员权限执行：`sudo <command line>`
*   VIM 中以管理员权限保存：`:w !sudo tee %`

### 验证启动模式

```sh
ls /sys/firmware/efi/efivars  # 若目录存在，说明选用的 UEFI
```

### 连接到互联网

```shell script
ip link             # 检查网卡
ping archlinux.org  # 检查网络连接

# 若异常可尝试：
systemctl enable dhcpcd.service  # 启用 DHCPCD 服务
```

### 更新系统时间

```shell script
timedatectl status        # 检查服务状态

# 若异常可尝试：
timedatectl set-ntp true  # 启用网络时间同步
```

### 建立硬盘分区

```shell script
lsblk               # 列出块设备

# 为块设备分区
cfdisk -z /dev/<sda>
# 1M           BIOS boot   若选用 BIOS/GPT 则须此分区
# 512M         EFI System  若选用 UEFI 则须此分区
#              Linux root  根目录分区
# 4G           Linux swap  交换分区
```

### 格式化分区

```shell script
# BIOS boot 无需格式化

# 若选用 UEFI 则格式化 EFI System 分区，EFI 分区仅支持 FAT32
mkfs.vfat /dev/<sda>1

# 格式化根目录分区
mkfs.ext4 /dev/<sda>2

# 格式化交换分区
mkswap /dev/<sda>3
swapon /dev/<sda>3

# Linux swap 无需格式化

# 检查分区格式
lsblk -f
```

### 挂载分区

```shell script
# 挂载根分区
mount /dev/<sda>2 /mnt

# 若选用 UEFI 则挂载 EFI 分区
mkdir -p /mnt/boot/EFI
mount /dev/<sda>1 /mnt/boot/EFI

# 检查分区挂载
lsblk
```

### 选择包管理器的在线源的镜像

```shell script
vim /etc/pacman.d/mirrorlist

# 越靠前的镜像优先级越高，且该配置将被复制到新系统，须正确调整
#
### Alibaba
# Server = http://mirrors.aliyun.com/archlinux/$repo/os/$arch
### Tencent
# Server = https://mirrors.cloud.tencent.com/archlinux/$repo/os/$arch
### China
# ...
### Hong Kong
# ...
### Taiwan
# ...
#
# ......
```

### 安装基本系统

```shell script
pacstrap /mnt linux base base-devel vim  # linux       内核
                                         # base        基础软件包
                                         # base-devel  开发软件包
                                         # vim         编辑器
```

## 配置系统

### 配置文件系统表

```shell script
genfstab -U /mnt >> /mnt/etc/fstab  # 生成 fstab
cat /mnt/etc/fstab                  # 检查 fstab
```

### 切换根目录

```shell script
arch-chroot /mnt
```

### 设置时区

```shell script
ln -sf /usr/share/zoneinfo/Asia/Chongqing /etc/localtime  # 东八区
hwclock --systohc --utc                                   # 设置时间标准为 UTC 并同步
date                                                      # 检查当前时间
```

### 设置本地化

```shell script
vim /etc/locale.gen   # 编辑欲支持的本地化配置
locale-gen            # 生成欲支持的本地化配置

vim /etc/locale.conf  # 编辑本地化配置
                      # LANG=en_US.UTF-8
```

### 设置网络

配置主机名和本地静态域名解析

```sh
[user@host *]$ sudo vim /etc/hostname  # 配置主机名

[user@host *]$ sudo vim /etc/hosts     # 配置本地静态域名解析
# 127.0.0.1       localhost
# ::1             localhost
# 127.0.0.1       <hostname>.localdomain  <hostname>
```

选用 [*systemd-networkd*](https://wiki.archlinux.org/index.php/Systemd-networkd) 进行网络管理

```sh
# 二选一：动态主机配置
[user@host *] sudo vim /etc/systemd/network/<dhcp>.network
# [Match]
# Name=en*
#
# [Network]
# DHCP=ipv4

# 二选一：静态主机配置
[user@host *] sudo vim /etc/systemd/network/<en*>.network
# [Match]
# Name=<en*>
#
# [Network]
# Address=192.168.0.1/24
# Gateway=192.168.0.254
# DNS=10.1.10.1
# DNS=8.8.8.8

# 启用并启动 systemd-networkd 网络管理器
[user@host *] sudo systemctl enable systemd-networkd
[user@host *] sudo systemctl start systemd-networkd
# 或者若其已经启动，则强制其重载配置
[user@host *] sudo systemctl force-reload systemd-networkd

```

选用 [*systemd-resolved*](https://wiki.archlinux.org/index.php/Systemd-resolved) 进行域名解析

```sh
# 若需要，可通过 DHCP 获取 DNS：
[user@host *] ln -sf /run/systemd/resolve/resolv.conf /etc/resolv.conf

# 启用并启动 systemd-resolved 网络管理器
[user@host *] sudo systemctl enable systemd-resolved
[user@host *] sudo systemctl start systemd-resolved
```

### 系统管理员密码

```shell script
passwd
```

### 安装引导

```shell script
# BIOS/GTP
pacman -S grub                        # 安装引导程序
grub-install --recheck /dev/sda       # 向分区装载引导
grub-mkconfig -o /boot/grub/grub.cfg  # 生成引导配置

# UEFI
pacman -S efibootmgr grub
grub-install --recheck /dev/sda
grub-mkconfig -o /boot/grub/grub.cfg
```

### 重启

```shell script
exit            # 退出 chroot 环境
umount -R /mnt  # 卸载分区，以检查分区是否仍繁忙，避免数据丢失
reboot          # 硬重启
```
