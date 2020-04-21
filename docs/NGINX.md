# 网页服务器 [*NGINX*](https://nginx.org/)

跨平台的网页服务器。

## 安装

### CentOS

```sh
[user@host *]$ sudo yum install nginx
```

## 常用操作

```fish
user@host *> nginx -v  # 版本
user@host *> nginx -h  # 帮助
user@host *> nginx -t  # 测试

user@host *> nginx            # 启动
user@host *> nginx -s stop    # 快速关闭
user@host *> nginx -s quit    # 优雅关闭
user@host *> nginx -s reload  # 重新加载配置文件
user@host *> nginx -s reopen  # 重新打开日志文件
```

若有意外，可从以下方面排查：

*   防火墙配置

## 配置说明

```fish
user@host *> vim /etc/nginx/nginx.conf
```

```nginx.conf
# 工作用户和组（https://nginx.org/docs/ngx_core_module.html#user）
user nobody nobody;

# 工作线程数（https://nginx.org/docs/ngx_core_module.html#worker_processes）
worker_processes 1;

# 事件上下文（https://nginx.org/docs/ngx_core_module.html#events）
events {
    # 工作线程最大可连接数（https://nginx.org/docs/ngx_core_module.html#worker_connections）
    worker_connections 512;

}

# HTTP 服务上下文（https://nginx.org/docs/http/ngx_http_core_module.html#http）
http {
    # 虚拟服务器配置（https://nginx.org/docs/http/ngx_http_core_module.html#server）
    server {
        # 监听（https://nginx.org/docs/http/ngx_http_core_module.html#listen）
        listen *:80;    # root
        listen *:8000;  # user

        # URI 路由（https://nginx.org/docs/http/ngx_http_core_module.html#location）
        location / {
            # 请求的映射根目录（https://nginx.org/docs/http/ngx_http_core_module.html#root）
            root html;

            # URI 索引（https://nginx.org/docs/http/ngx_http_index_module.html#index）
            index index.html;

        }

    }

}
```

## 配置示例

### 简单静态页面

```nginx.conf
worker_processes auto;
events {
    worker_connections 1024;
}
http {
    server {
        listen 80;
        location / {
            root /path/to/www;
        }
    }
}
```

### [*nginx-rtmp-module*](https://github.com/arut/nginx-rtmp-module)

```nginx.conf
worker_processes auto;
events {
    worker_connections 1024;
}
http {
    include           mime.types;
    default_type      application/octet-stream;
    sendfile          off;                       # 因磁盘 IO 重负载，所以不采用 sendfile 优化
    tcp_nopush        on;
    keepalive_timeout 65;                        # 保活超时（秒）

    server {
        listen        80;                        # HTTP、DASH 和 HLS 协议的访问端口

        location /rtmp_stat {
            rtmp_stat            all;
            rtmp_stat_stylesheet rtmp_stat.xsl;
        }

        location /rtmp_stat.xsl {
            root /usr/local/src/nginx-rtmp-module;
        }

        location /rtmp_control {
            rtmp_control all;
        }

        # HLS
        location /livehls {
            types {
                application/vnd.apple.mpegurl m3u8;
                video/mp2t ts;
            }
            root /tmp;
            add_header 'Cache-Control' 'no-cache';
        }

        # DASH
        location /livedash {
            root /tmp;
            add_header 'Cache-Control' 'no-cache';
        }

    }
}

# RTMP 服务

rtmp {

    server {
        listen 1935;
        chunk_size 4000;

        application livertmp {
            # RTMP
            live on;

            # HLS
            hls on;
            hls_fragment 5s;
            hls_playlist_length 30s;
            hls_path /tmp/livehls;
            hls_nested on;
            hls_cleanup on;

            # DASH
            dash on;
            dash_fragment 5s;
            dash_playlist_length 30s;
            dash_path /tmp/livedash;
            dash_nested on;
            dash_cleanup on;

            # RECORDER
            recorder rec_all {
                record all manual;
                record_path /usr/rec;
                record_suffix _%F_%T.all.flv;
                record_unique on;
            }
        }

        application vod {
            play /usr/rec;
        }
    }
}

```
