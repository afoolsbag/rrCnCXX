# 壳层

## 查询当前壳层

```shell script
echo $SHELL
```

## 安装 fish 壳层

*Arch*
```shell script
sudo pacman -S fish
```

*CentOS*
```shell script
# 安装 fish 2
sudo yum install fish

# 安装 fish 3
cd /etc/yum.repos.d
sudo wget https://download.opensuse.org/repositories/shells:fish:release:3/RHEL_7/shells:fish:release:3.repo
sudo yum install fish
```

*Ubuntu*
```shell script
# 安装 fish 2
sudo apt install fish

# 安装 fish 3
sudo apt-add-repository ppa:fish-shell/release-3
sudo apt update
sudo apt install fish
```

## 切换默认壳层

```shell script
cat /ect/shells        # 展示可用壳层
sudo vim /etc/shells   # 编辑可用壳层

chsh --shell /usr/bin/fish  # 切换默认壳层（重新登陆以生效）
# 或
sudo vim /etc/passwd        # 切换默认壳层（重新登录以生效）
```

## 壳层环境

*bash*
```shell script
~/.bash_profile  # 壳层相关的配置入口
  ~/.profile     # 壳层无关的用户配置，如 PATH
  ~/.bashrc      # 壳层相关的用户配置
    /etc/bashrc  # 壳层相关的通用配置
```

*fish*
```shell script
~/.config/fish/config.fish  # 用户配置

set --export PATH {$PATH} /path/to/added
```
