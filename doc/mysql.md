# [*mysql*](https://mysql.com/)

登录和登出
```shell script
fish> mysql -u NAME (--user=USR) -p (--password=PWD)
mysql> exit
```

允许远程管理（允许 `root` 用户远程登录）
```shell script
# 切换到 `mysql` 数据库
mysql> use mysql;

# 查询 `root` 用户的登录限制
mysql> SELECT Host, User FROM user WHERE User='root';

# 取消登录限制
mysql> UPDATE user SET Host='%' WHERE User='root';

# 再次查询 `root` 用户的登录限制
mysql> SELECT Host, User FROM user WHERE User='root';

# 使其立刻生效
mysql> flush privileges;
```

禁用 SSL
```shell script
# 检查是否启用 SSL
mysql> SHOW VARIABLES LIKE '%ssl%';

# 禁用 SSL
fish> vim /etc/mysql/mysql.conf.d/mysqld.cnf
vim> skip_ssl  # 在尾部追加

# 重启服务
fish> service mysql restart

# 再次检查是否启用 SSL
mysql> SHOW VARIABLES LIKE '%ssl%';
```
