# 数据包过滤框架 [*netfilter*](https://netfilter.org/)

适用于 Linux 2.4.x 及更高版本内核的数据包过滤框架。

## 常用操作

### CentOS

```sh
[user@host *]$ systemctl status firewalld  # 查看 FirewallD 服务状态

[user@host *]$ sudo firewall-cmd --list-all  # 列出所有规则

[user@host *]$ sudo firewall-cmd --query-port=<port>/<protocol>               # 查询一条规则
[user@host *]$ sudo firewall-cmd --permanent --add-port=<port>/<protocol>     # 持久添加一条规则
[user@host *]$ sudo firewall-cmd --permanent --remove-port=<port>/<protocol>  # 持久移除一条规则

[user@host *]$ sudo firewall-cmd --reload  # 重新加载配置
```
