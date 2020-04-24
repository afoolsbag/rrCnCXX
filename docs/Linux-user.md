# 用户

```shell script
useradd -m <username>         # 新建用户，并创建用户主目录
passwd <username>             # 交互式修改用户密码

usermod [options] <username>  # 修改用户
userdel -r <username>         # 删除用户，并移除用户主目录
```

## 为用户赋予 `sudo` 权限

```shell script
# 新建文件并编辑：
# sudo vim /etc/sudoers.d/<username>

<user>  ALL=(ALL:ALL)   NOPASSWD:ALL
```
