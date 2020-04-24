# 网络嗅探工具 [*Nmap*](https://nmap.org/)

*   [*Reference Guide*](https://nmap.org/man/) <sub>
        [*zh_cn*](https://nmap.org/man/zh/) </sub>
*   [*GUI*](https://nmap.org/zenmap/)

互联网协议套件

|        | abbr. | term                                 | trans.
|:-------|:------|:-------------------------------------|:------
| 应用层 |
| 传输层 | SCTP  | Stream Control Transmission Protocol | 流控制传输协议
|        | TCP   | Transmission Control Protocol        | 传输控制协议
|        | UDP   | User Datagram Protocol               | 用户数据报协议
| 网络层 | IP    | Internet Protocol                    | 网际协议
|        | ICMP  | Internet Control Message Protocol    | 网际控制消息协议
| 链路层 |

IPv4 地址分配

```text
  0.  *.  *.  */8   本网络（RFC 5735）
 10.  *.  *.  */8   A 类专用网络（RFC 1918）
100. 64.  *.  */10  运营商级网络地址转换（RFC 6598）
    127             ↵
127.  *.  *.  */8   本地环回（RFC 5735）
169.254.  *.  */16  链路本地（RFC 3927）
172. 16.  *.  */12  B 类专用网络（RFC 1918）
     31             ↵
192.  0.  0.  */24  保留（RFC 5735）
192.  0.  2.  */24  示例网络 1（RFC 5735）
192. 88. 99.  */24  中继（RFC 3068）
192.168.  *.  */16  C 类专用网络（RFC 1918）
198. 18.  *.  */15  网络基准测试（RFC 2544）
     19             ↵
198. 51.100.  */24  示例网络 2（RFC 5737）
203.  0.113.  */24  示例网络 3（RFC 5737）
224.  *.  *.  */4   多播（RFC 3171）
239                 ↵
240.  *.  *.  */4   保留（RFC 1700）
255                 ↵
255.255.255.255     受限广播（RFC 919）
```

## 命令示例

```fish
root@host *# nmap -sn <target>                   # 主机发现
root@host *# nmap <target>                       # 端口扫描
root@host *# nmap -v -oA <basename> -A <target>  # 信息探测
```

## 命令说明

### 主机发现

```fish
root@host *# nmap -sL <target>  # 列表扫描，不发送报文

root@host *# nmap -sn <target>  # Ping 扫描，使用以下 4 种数据包探测主机是否在线
                                # 1. ICMP Echo Request 包
                                # 2. ICMP Timestamp Request 包
                                # 3. TCP SYN 包，向 HTTPS 443 端口
                                # 4. TCP ACK 包，向 HTTP 80 端口

root@host *# nmap -PS[port,]... <target>  # TCP SYN Ping 扫描，端口默认为 80
root@host *# nmap -PA[port,]... <target>  # TCP ACK Ping 扫描，端口默认为 80
root@host *# nmap -PU[port,]... <target>  # UDP Ping 扫描，端口默认为 40125
root@host *# nmap -PY[port,]... <target>  # SCTP INIT Ping 扫描，默认端口为 80

root@host *# nmap -PE <target>  # ICMP Echo Request Ping 扫描
root@host *# nmap -PP <target>  # ICMP Timestamp Request Ping 扫描
root@host *# nmap -PM <target>  # ICMP Address Mask Request Ping 扫描
```

### 端口扫描

```fish
root@host *# nmap <target>  # 常用端口扫描

root@host *# nmap -sS <target>  # TCP SYN 扫描，不完成 TCP 连接，半开放扫描
root@host *# nmap -sT <target>  # TCP 连接扫描，将留下访问痕迹
root@host *# nmap -sA <target>  # TCP ACK 扫描
root@host *# nmap -sW <target>  # TCP 窗口扫描
root@host *# nmap -sM <target>  # TCP Maimon 扫描

root@host *# nmap -sU <target>  # UDP 扫描

root@host *# nmap -sN <target>  # TCP Null 扫描
root@host *# nmap -sF <target>  # TCP FIN 扫描
root@host *# nmap -sX <target>  # TCP Xmas（FIN、PSH、URG） 扫描

root@host *# nmap -sY <target>  # SCTP INIT 扫描
root@host *# nmap -sZ <target>  # SCTP COOKIE-ECHO 扫描

root@host *# nmap -sO <target>  # IP 协议扫描
```

### 信息探测

依据端口扫描得到的信息，可以进一步探测其所提供的服务和版本，并据此猜测其所用操作系统。

```fish
root@host *# nmap -sV <target>  # 启用服务版本探测
root@host *# nmap -O <target>   # 启用操作系统探测

root@host *# nmap -sC <target>  # 启用脚本扫描

root@host *# nmap -A <target>   # 激烈扫描模式
```

### 杂项

```fish
root@host *# nmap -v <target>   # 增强详细程度
root@host *# nmap -vv <target>  # 增强更多详细程度
root@host *# nmap -d <target>   # 增强调试级别
root@host *# nmap -dd <target>  # 增强更多调试级别

root@host *# nmap -oN <file.nmap> <target>  # 标准输出
root@host *# nmap -oX <file.xml> <target>   # XML 输出
root@host *# nmap -oG <file.gnmap> <target> # 可 Grep 输出
root@host *# nmap -oA <basename> <target>   # 以上三种输出
```

运行时交互：
*   `v`（`V`） 增强（减弱）详细程度
*   `d`（`D`） 增强（减弱）调试级别
*   `p`（`P`） 开启（关闭）包追踪
