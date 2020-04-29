# 分布式版本控制系统 [*Git*](https://git-scm.com/)

*   [*Git 教程*](https://liaoxuefeng.com/wiki/896043488029600)
*   [*Sourcetree*](https://sourcetreeapp.com/)

## 配置

```fish
user@host *> git config --list           # 列出配置
# abbr.      git config -l
user@host *> git config --system --list  # 系统配置（/etc/gitconfig）
user@host *> git config --global --list  # 用户配置（~/.gitconfig）
user@host *> git config --local  --list  # 项目配置（.git/config）
```

### 为当前用户设置名称和邮箱

```fish
user@host *> git config --global user.name "<name>"
user@host *> git config --global user.email "<email@example.com>"
```

### 生成 SSH 密钥对

```fish
user@host *> ssh-keygen -t rsa -C "<email@example.com>"  # ~/.ssh
user@host *> cd ~/.ssh
```

## 版本库（Repository，`.git`）

```fish
user@host ~/wdir> git remote --verbose  # 列出远端库
# abbr.           git remote -v
```

### 在本地创建版本库

```fish
# 初始化版本库
user@host ~/wdir> git init

# 添加远端库
user@host ~/wdir> git remote add <origin> <git@host:wdir.git>

# 绑定当前分支到远端 <origin> 库
user@host ~/wdir> git branch --set-upstream-to=<origin>
# abbr.           git branch -u <origin>

# 推送本地提交到远端库
user@host ~/wdir> git push <origin> <master>
```

### 从远端复制版本库

```fish
# 从远端复制版本库
user@host ~> git clone <git@host:wdir.git>

# 创建远端分支到本地
user@host ~/wdir> git branch --set-upstream-to=<origin/dev> <dev>
# abbr.           git branch -u <origin/dev> <dev>
```

## 分支（Branch）

```fish
user@host ~/wdir> git branch          # 展示分支

user@host ~/wdir> git branch <dev>    # 创建分支

user@host ~/wdir> git --delete <dev>  # 删除分支
# abbr.           git -d <dev>

user@host ~/wdir> git switch <dev>    # 切换分支
# depr.           git checkout <dev>


user@host ~/wdir> git switch --create <dev>  # 创建并切换分支
# abbr.           git switch -c <dev>
# depr.           git checkout -b <dev>
```

### 提交

```fish
# 查看提交历史
user@host ~/wdri> git log
user@host ~/wdri> git log --abbrev-commit --graph --pretty=oneline
# abbr.           git log --graph --online
```

### 合并分支（Merge）

```fish
user@host ~/wdir (dev)> git checkout <master>  # 切换到主分支
user@host ~/wdir (master)> git merge <dev>     # 合并分支

# 禁用快进模式，带记录地合并分支
user@host ~/wdir (master)> git merge --no-ff -m "<merge with no-ff>" <dev>

# 若有冲突
user@host ~/wdir (master)> git status          # 查看冲突
# ......                                       # 解决冲突
user@host ~/wdir (master)> git add <file>      # 提交修改
user@host ~/wdir (master)> git commit -m "<conflict fixed>"

# 若希望整理提交历史，将分岔合并
user@host ~/wdir (master)> git rebase
```

### 标签（Tag）

```fish
```

## 暂存区（`index`）

```fish
user@host ~/wdir> git diff --cached                 # 比较暂存区与版本库

user@host ~/wdir> git commit --message="<message>"  # 提交暂存区修改到版本库 `index` >> `branch`
# abbr.           git commit -m "<message>"

user@host ~/wdir> git restore --staged <file>...    # 回退暂存区修改到工作区
# depr.           git reset HEAD [file]...
```

## 工作区（Working Directory，`wdir`）

```fish
user@host ~/wdir> git status                 # 查看工作区状态

user@host ~/wdir> git diff HEAD              # 比较工作区与版本库
user@host ~/wdir> git diff                   # 比较工作区与暂存区

user@host ~/wdir> git add <file>...          # 添加工作区修改到暂存区 `wdir` >> `index`

user@host ~/wdir> git restore <file>...      # 放弃工作区修改
# depr.           git checkout -- <file>...
```

### 藏匿（Stash）

```fish
user@host ~/wdir> git stash                 # 藏匿脏工作区，以处理突发事件，譬如漏洞修复
# ......
user@host ~/wdir> git stash pop             # 恢复脏工作区，继续之前的工作

user@host ~/wdir> git cherry-pick <commit>  # 复制特定提交到当前分支
                                            # 常用于将主分支的漏洞修复，应用到开发分支


user@host ~/wdir> git stash list               # 列出存储的脏工作区
user@host ~/wdir> git stash apply [stash@{0}]  # 恢复指定的脏工作区，且不将其丢弃
user@host ~/wdir> git stash drop [stash@{0}]   # 丢弃指定的脏工作区
```

## 服务

### Ubuntu

```sh
# 安装 git
user@host:*$ sudo apt install git

# 创建名为 git 用户，并禁用其默认 Shell
user@host:*$ sudo adduser git
user@host:*$ sudo vim /etc/passwd
# git:x:1001:1001:user for git service:/home/git:/usr/bin/git-shell

# 导入证书
user@host:*$ cd /home/git
user@host:~$ sudo --user=git mkdir .ssh
# abbr.      sudo -u git mkdir .ssh
user@host:~$ sudo --user=git vim .ssh/authorized_keys  # 一行一条
# abbr.      sudo -u git vim .ssh/authorized_keys

# 初始化仓库
user@host:~$ sudo --user=git git init --bare <wdir.git>
# abbr.      sudo -u git git init --bare <wdir.git>
```
