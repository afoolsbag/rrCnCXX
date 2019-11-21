# 启动

```shell script
sudo shutdown -r now  # 安全地重启系统
sudo shutdown -h now  # 安全地关闭系统
sudo halt             # 硬停机
sudo poweroff         # 硬掉电
sudo reboot           # 硬重启
```

[“第十九章、開機流程、模組管理與 Loader”](http://linux.vbird.org/linux_basic/0510osloader.php). *鳥哥的 Linux 私房菜*.

0.  开机

0.  非易失性存储器（NVM，Non-Volatile Memory）中的固件——基本输入输出系统（BIOS，Basic Input/Output System）或统一可扩展固件接口（UEFI，Unified Extensible Firmware Interface），被加载到主存并运行：

    0.  加电自检（POST，Power-On Self-Test）

    0.  启动设备（Boot Device）中的、可选的全局唯一标识分区表（GPT，GUID Partition Table）中的、主引导记录（MBR，Master Boot Record）中的、一阶段引导程序（1st-Stage Boot Loader），被加载到主存并运行

        常见的一阶段引导程序：
        *   coreboot
        *   Libreboot
        *   Das U-Boot

    0.  可选的，引导分区（Boot Partition）中的、引导扇区（Boot Sector）中的、二阶段引导程序（2nd-Stage Boot Loader），被加载到主存并运行

        常见的二阶段引导程序：
        *   GRUB (UNIX-like)
        *   BOOTMGR
        *   NTLDR (Windows)
        *   BootX (macOS)
        *   SYSLINUX (Linux)

    0.  Linux 内核（`/boot/vmlinuz`）被解压并加载到主存

    0.  虚拟文件系统（`/boot/initrd` 或 `/boot/initramfs`）被解压、加载到主存、并挂载为根目录

    0.  引导程序将控制权交予操作系统

0.  操作系统第一次调用 `systemd` 守护进程，执行 `initrd.target`：

    0.  执行硬件检测

    0.  从虚拟文件系统中加载内核模块（`/lib/modules/$(uname -r)/kernel`）到主存，主要是存储设备的驱动程序

    0.  卸载虚拟文件系统

    0.  挂载实际文件系统到根目录

    0.  硬件就绪（Ready）

0.  操作系统第二次调用 `systemd` 守护进程，进程标识 `1` 号：

    0.  执行 `/etc/systemd/system/default.target`，通常链接为 `/usr/lib/systemd/system/multi-user.target` 或 `/usr/lib/systemd/system/graphical.target`，假定链接为后者

        系统定义的 `*.target[.wants]` 置于 `/usr/lib/systemd/system`，用户定义的 `*.target[.wants]` 置于 `/etc/systemd/system`，为与 System V 兼容，系统 `*.target` 有以下别名：

        ```shell script
        /usr/lib/systemd/system/runlevel0.target  # poweroff.target
                                runlevel1.target  # rescue.target
                                runlevel2.target  # multi-user.target
                                runlevel3.target  # multi-user.target
                                runlevel4.target  # multi-user.target
                                runlevel5.target  # graphical.target
                                runlevel6.target  # reboot.target
        ```

        使用 `systemctl list-dependencies default.target` 可以列出完整依赖列表，下述按执行顺序，选取关注项列出：

    0.  执行 `sysinit.target` 初始化系统，由 `basic.target` 依赖

        0.  依据 `/etc/modules-load.d/*.conf` 加载额外核心模块

        0.  依据 `/etc/modprobe.d/*.conf` 加载额外核心模块参数

        0.  依据 `/etc/sysctl.conf` 加载核心参数，依据 `/etc/sysctl.d/*.conf` 加载额外核心参数

    0.  执行 `basic.target` 准备系统，由 `multi-user.target` 依赖

        0.  依据 `/etc/rc.modules` 和 `/etc/sysconfig/modules/*.modules` 加载模块

    0.  执行 `multi-user.target`，由 `graphical.target` 依赖

        0.  为与 System V 兼容，若 `/etc/rc.local` 可读可执行，则执行

            若 `/etc/rc.local` 链接到 `/etc/rc.d/rc.local`，则此二者都需要可读和可执行权限

    0.  执行 `graphical.target`，由 `default.target` 链接
