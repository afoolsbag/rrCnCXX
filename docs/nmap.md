# nmap

[*Network Mapper*](https://nmap.org/)
/ doc <sub>[*zh_CN*](https://nmap.org/man/zh/)</sub>
/ gui `zenmap`

|        | abbr. | term                              | trans.
|:-------|:------|:----------------------------------|:------
| 应用层 |
| 传输层 | TCP   | Transmission Control Protocol     | 传输控制协议
|        | UDP   | User Datagram Protocol            | 用户数据报协议
| 网络层 | IP    | Internet Protocol                 | 网际协议
|        | ICMP  | Internet Control Message Protocol | 网际控制消息协议
| 链接层 |

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

## 主机发现

```shell script
nmap -sn <net or host>  # Ping 扫描，使用以下 4 种数据包探测主机是否在线
                        # 1. ICMP Echo Request 包
                        # 2. ICMP Timestamp Request 包
                        # 3. TCP SYN 包，向 HTTPS 443 端口
                        # 4. TCP ACK 包，向 HTTP 80 端口
```
