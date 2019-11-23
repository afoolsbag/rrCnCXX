# Crossing the Wall

**在浏览器地址栏输入一个网址，在执行“跳转”的瞬间，发生了什么？**

不妨假定输入的是世界上的第一个页面：<http://info.cern.ch/hypertext/WWW/TheProject.html>。

1.  浏览器从网址中解析出主机：

    网址即 URL（Uniform Resource Locator，统一资源定位符），是 URI（Uniform Resource Identifier，统一资源标识符）的一种，格式为
    ```text
    scheme:[//[user:password@]host[:port]][/]path[?query][#fragment]
    ```
    其中的 `host` 即为主机。
    主机可以用域名或 IP（Internet Protocol，网际协议）地址表示，前述的 URL 即以域名 `info.cern.ch` 表示主机。

2.  若主机以域名表示，则通过 DNS（Domain Name System，域名系统）进行域名解析以查找 IP 地址：

    1.  浏览器首先会在内置 DNS 缓存中查找，若找到则将其返回，否则进行下一步；
    2.  浏览器请求操作系统解析域名，操作系统尝试在系统 DNS 缓存中查找，若找到……，否则……；
        *   查看当前系统缓存 `ipconfig /displaydns`
        *   清空当前系统缓存 `ipconfig /flushdns`
        *   浏览器 DNS 缓存和系统 DNS 缓存都存储在内存中，断电清空
    3.  操作系统尝试在 HOSTS 文件中查找，若找到……，否则……；
        *   HOSTS 文件位置 `%SystemRoot%\System32\drivers\etc\hosts`
    4.  操作系统请求 DNS 服务器解析域名，DNS 服务器尝试在缓存中查找，若找到……，否则……；
        *   阿里云公共 DNS `223.5.5.5` / `223.6.6.6` / `2400:3200::1` / `2400:3200:baba::1`
        *   百度公共 DNS `180.76.76.76` / `2400:da00::6666`
        *   Google Public DNS `8.8.8.8` / `8.8.4.4`
        *   OpenDNS `207.67.222.222` / `208.67.220.220`
    5.  DNS 服务器递归请求根服务器、主服务器、域服务器等解析域名，若找到……，否则……；
    6.  报错：“找不到……的服务器 IP 地址”。

    前述域名在此文写作时被解析为 IPv6 地址 `2001:1458:201:a4::100:2f`。

3.  取得 IP 地址后，尝试与对应 IP 地址端口建立 TCP（Transmission Control Protocol，传输控制协议）连接；

4.  建立 TCP 连接后，按协议与服务器进行交互，并对收到的数据进行处理、渲染和呈现。

依据以上流程，若要需要定向屏蔽网络服务，可能的技术方案：

## DNS 劫持

通过把持 DNS 服务器，修改域名解析规则，将敏感域名解析到错误的地址，以达到屏蔽效果。

应对：
*   配置 HOSTS，在本机将敏感域名解析为 IP 地址，绕过 DNS 服务器
*   配置信任的 DNS 服务器

## DNS 污染

DNS 主要使用 UDP（User Datagram Protocol，用户数据报协议） 53 端口，且每次请求只认首个有效回应。
于是通过把持网络要冲，对检测到的敏感 DNS 解析请求，抢先回发错误回应，以达到屏蔽效果。

应对：
*   配置 HOSTS，在本机将敏感域名解析为 IP 地址，绕过 DNS 服务器

## IP 黑名单

通过把持网络要冲，将与敏感 IP 地址交互的数据包拦截，以达到屏蔽效果。

应对：
*   使用代理，不直接访问敏感 IP 地址

## SNI 阻断

## HTTP/SOCKS 代理检测

HTTP 代理通常使用 80 / 8080 / 3128 / 8081 / 9080 端口，SOCKS 代理通常使用 1080 端口，
这两种代理对内容都不加密，因而很容易被检测，从而拦截屏蔽。

对 HTTP 内容经过简单的 BASE64 转换的方法，也轻易被监测、拦截、屏蔽。

Proxy Hunter

## HTTPS 代理检测

active probe 检测

无法获取代理的内容，但可以基于特征检测出典型代理。无法完全拦截，但可以拦截部分。

## PPTP 检测

加密强度不高
已被干掉

## SSH 检测

通过流量大小检测

变种：
进行了混淆的 SSH
多伦多大学公民实验室 赛风（PSIPHON）
依然可用

## CDN 检测

通过将代理流量装入 CDN Host 头，绕过检测

Lantern、FireFly、Tor Browser – Meek

## OpenVPN

高强度加密
但是特征太明显
被干掉

但是经过混淆后还可以用

## Cisco AnyConnect

类似 OpenVPN，但是这货有很多大型跨国企业也在用，因而无法粗暴屏蔽，好在配置麻烦，使用者较少

仍然可用

## SoftEther VPN / VPNGate

日本筑波大学 VPNGate

特征被掌握

偶尔可用

## Shadowsocks
