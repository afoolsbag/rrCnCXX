# 网页服务器 [*NGINX*](https://nginx.com/)

## [*nginx-rtmp-module*](https://github.com/arut/nginx-rtmp-module)

```fish
user@host *> vim path/to/nginx.conf
```

```vim
# 全局配置

worker_processes auto;  # 工作进程数

events {
    worker_connections 1024;  # 每个工作线程的最大连接数
}

# HTTP 服务

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
