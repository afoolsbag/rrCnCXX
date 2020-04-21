# 使用 `yum` 安装 nginx-rtmp-module 的示例

## 最简示例

### CentOS

```sh
# 安装默认版本 GCC
[user@host *]$ sudo yum group install 'Development Tools'

# 安装 NGINX 依赖
[user@host *]$ sudo yum install openssl-devel pcre-devel zlib-devel

# 切换到 root 权限
[user@host *]$ su

# 切换到用户源码目录
[user@host *]# cd /usr/local/src

# 拉取 NGINX 源码 (https://nginx.org/en/download.html)
[user@host src]# wget https://nginx.org/download/nginx-<version>.tar.gz
[user@host src]# tar -xzvf nginx-<version>.tar.gz

# 拉取 nginx-rtmp-module 源码
[user@host src]# git clone https://github.com/arut/nginx-rtmp-module.git

# 切换到 NGINX 源码目录
[user@host src]# cd nginx-<version>

# 配置、编译、安装
[user@host nginx-<version>]# ./configure --add-module=../nginx-rtmp-module
[user@host nginx-<version>]# make
[user@host nginx-<version>]# make install

# 运行 NGINX
[user@host *]$ sudo /usr/local/nginx/sbin/nginx
# 停止 NGINX
[user@host *]$ sudo kill -QUIT $( cat /usr/local/nginx/logs/nginx.pid )
```

## 最佳实践

### CentOS

```sh
# 安装默认版本 GCC
[user@host *]$ sudo yum group install 'Development Tools'

# 安装 NGINX 依赖
[user@host *]$ sudo yum install openssl-devel pcre-devel zlib-devel

# 切换到 root 权限
[user@host *]$ su

# 切换到用户源码目录
[user@host *]# cd /usr/local/src

# 拉取 NGINX 源码 (https://nginx.org/en/download.html)
[user@host src]# wget https://nginx.org/download/nginx-<version>.tar.gz
[user@host src]# tar -xzvf nginx-<version>.tar.gz

# 拉取 nginx-rtmp-module 源码
[user@host src]# git clone https://github.com/arut/nginx-rtmp-module.git

# 切换到 NGINX 源码目录
[user@host src]# cd nginx-<version>

# https://howtoforge.com/tutorial/how-to-install-nginx-with-rtmp-module-on-centos/
```
