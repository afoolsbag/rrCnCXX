# 网页服务器 [*NGINX*](https://nginx.org/)

跨平台的网页服务器。

## 安装

### CentOS

```sh
[user@host *]$ sudo yum install nginx
```

### Ubuntu

```sh
user@host:*$ sudo apt install nginx
```

## 常用命令

```fish
user@host *> nginx -v  # 版本
user@host *> nginx -h  # 帮助
user@host *> nginx -t  # 测试

user@host *> nginx            # 启动
user@host *> nginx -s stop    # 快速停止
user@host *> nginx -s quit    # 优雅地退出
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
    include mine.types;

    # 默认 MINE 类型（https://nginx.org/docs/http/ngx_http_core_module.html#default_type）
    default_type text/plain;

    # 保活超时（https://nginx.org/docs/http/ngx_http_core_module.html#keepalive_timeout）
    keepalive_timeout 75s;

    # 是否启用 sendfile() 函数（https://nginx.org/docs/http/ngx_http_core_module.html#sendfile）
    sendfile off;
    # 是否启用 TCP_NOPUSH 或 TCP_CORK 选项（https://nginx.org/docs/http/ngx_http_core_module.html#tcp_nopush）
    tcp_nopush off;

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
