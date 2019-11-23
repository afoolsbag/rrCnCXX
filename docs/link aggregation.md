# 链路聚合

## Ubuntu 

[*UbuntuBonding*](https://help.ubuntu.com/community/UbuntuBonding)

```shell script
# 聚合 eno0、eno0 到 bond0

# 0. 检查支持
# ......

# 1. 关闭网络服务
sudo systemctl stop networking.service

# 2. 修改配置文件
sudo vim /etc/notwork/interfaces
# auto eno1
# iface eno1 inet manual
#         bond-master bond0
#
# auto eno2
# iface eno2 inet manual
#         bond-master bond0
#
# auto bond0
# iface bond0 inet static
#         address 192.168.0.1
#         gateway 192.168.0.254
#         netmask 255.255.255.0
#         bond-mode balance-alb
#         bond-miimon 100
#         bond-slaves eno1 eno2

# 3. 启动网络服务
sudo systemctl start networking.service

# 4. 检查聚合接口
cat /proc/net/bonding/bond0
```
