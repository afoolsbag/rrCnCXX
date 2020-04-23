# 网络（配置）

## 配置 IP 协议

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

`Settings` > `Network` > `Wired` > `⚙` > `IPv4`
