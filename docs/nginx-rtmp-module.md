# 流媒体服务器 [*nginx-rtmp-module*](https://github.com/arut/nginx-rtmp-module)

跨平台的流媒体服务器。

## 安装

### CentOS

```sh
# 安装默认版本 GCC
[user@host *]$ sudo yum group install 'Development Tools'

# 安装 NGINX 依赖
[user@host *]$ sudo yum install openssl-devel pcre-devel zlib-devel

# 创建并切换到主目录下的项目源码目录
[user@host *]$ mkdir ~/nginx-rtmp-src
[user@host *]$ cd ~/nginx-rtmp-src

# 拉取 NGINX 源码（https://nginx.org/en/download.html）
[user@host nginx-rtmp-src]$ wget https://nginx.org/download/nginx-1.18.0.tar.gz
[user@host nginx-rtmp-src]$ tar -xzvf nginx-1.18.0.tar.gz

# 拉取 nginx-rtmp-module 源码
[user@host nginx-rtmp-src]$ git clone https://github.com/arut/nginx-rtmp-module.git

# 切换到 NGINX 源码目录
[user@host nginx-rtmp-src]$ cd nginx-1.18.0

# 配置、编译、安装
[user@host nginx-1.18.0]$ ./configure --prefix=</path/to/nginx-rtmp> \
                                      --add-module=../nginx-rtmp-module
[user@host nginx-1.18.0]$ make
[user@host nginx-1.18.0]$ make install

# 创建录像目录
[user@host *]$ sudo mkdir /var/nginx-rtmp-vod
[user@host *]$ sudo chmod a+w /var/nginx-rtmp-vod

# https://howtoforge.com/tutorial/how-to-install-nginx-with-rtmp-module-on-centos/
```

### Ubuntu

```sh
# 安装 GCC
user@host:*$ sudo apt install build-essential

# 安装 NGINX 依赖
user@host:*$ sudo apt install libpcre3-dev libssl-dev zlib1g-dev

# 创建并切换到主目录下的项目源码目录
user@host:*$ mkdir ~/nginx-rtmp-src
user@host:*$ cd ~/nginx-rtmp-src

# 拉取 NGINX 源码（https://nginx.org/en/download.html）
user@host:~/nginx-rtmp-src$ wget https://nginx.org/download/nginx-1.18.0.tar.gz
user@host:~/nginx-rtmp-src$ tar -xzvf nginx-1.18.0.tar.gz

# 拉取 nginx-rtmp-module 源码
user@host:~/nginx-rtmp-src$ git clone https://github.com/arut/nginx-rtmp-module.git

# 切换到 NGINX 源码目录
user@host:~/nginx-rtmp-src$ cd nginx-1.18.0

# 配置、编译、安装
user@host:~/nginx/rtmp-src/nginx-1.18.0$ ./configure --prefix=</path/to/nginx-rtmp> \
                                                     --add-module=../nginx-rtmp-module
user@host:~/nginx/rtmp-src/nginx-1.18.0$ make
user@host:~/nginx/rtmp-src/nginx-1.18.0$ make install

# 创建录像目录
user@host:*$ sudo mkdir /var/nginx-rtmp-vod
user@host:*$ sudo chmod a+w /var/nginx-rtmp-vod

# https://howtoforge.com/tutorial/how-to-install-nginx-with-rtmp-module-on-centos/
```

## 配置

```nginx.conf
user <user>;
worker_processes auto;
events {
    worker_connections 1024;
}
http {
    include      mime.types;
    default_type application/octet-stream;
    server {
        listen 80;
        location /stat {
            rtmp_stat            all;
            rtmp_stat_stylesheet stat.xsl;
        }
        location /stat.xsl {
            root </path/to/nginx-rtmp-module>;
        }
        location /control {
            rtmp_control all;
        }
        location ~ ^/live/(.+\.(mpd|m4a|m4v))$ {
            alias /tmp/nginx-rtmp-dash/$1;
            types {
                application/dash+xml mpd;
                audio/mp4            m4a;
                video/mp4            m4v;
            }
            add_header 'Cache-Control' 'no-cache';
        }
        location ~ ^/live/(.+\.(m3u8|ts))$ {
            alias /tmp/nginx-rtmp-hls/$1;
            types {
                application/vnd.apple.mpegurl m3u8;
                video/mp2t                    ts;
            }
            add_header 'Cache-Control' 'no-cache';
        }
    }
}
rtmp {
    server {
        listen 1935;
        application live {
            # RTMP
            live                 on;
            # HLS
            hls                  on;
            hls_fragment         5s;
            hls_playlist_length  30s;
            hls_path             /tmp/nginx-rtmp-hls;
            hls_nested           on;
            hls_cleanup          on;
            # DASH
            dash                 on;
            dash_fragment        5s;
            dash_playlist_length 30s;
            dash_path            /tmp/nginx-rtmp-dash;
            dash_nested          on;
            dash_cleanup         on;
            # RECORD
            record               off; #all;
            record_path          /var/nginx-rtmp-vod;
            record_suffix        _%F_%T.flv;
            record_unique        on;
            record_interval      10m;
        }
        application vod {
            play /var/nginx-rtmp-vod;
        }
    }
}
```

*   状态：`http://host:80/stat`
*   推流（RTMP）：`rtmp://host/live/<name>`
*   拉流（RTMP）：`rtmp://host/live/<name>`
*   拉流（DASH）：`http://host/live/<name>/index.mpd`
*   拉流（HLS）：`http://host/live/<name>/index.m3u8`
