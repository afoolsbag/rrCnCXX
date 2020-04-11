#!/usr/bin/env bash
#  _ __ _ __    _____  _____
# | '__| '__|  / _ \ \/ / _ \
# | |  | |    |  __/>  <  __/
# |_|  |_|     \___/_/\_\___|
# zhengrr
# 2019-10-31 – 2020-04-08
# Unlicense
#
# 一段简短的脚本，用作示例的可执行程序
#
# 该程序倒计时 `ltis` 秒，以秒为间隔回显剩余的秒数。
#
# 若希望在类 Unix 系统上运行此脚本，请确保：
# 1. 该脚本的字符集为 `UTF-8`
# 2. 该脚本的换行符为 `LF`
# 3. 当前用户对该脚本具有可读权限 `r` 和可执行权限 `x`

ltis=60  # left time in seconds

echo "$((ltis)) SECONDS TIMING..."
while (( 0 < ltis )); do
        sleep 1
        echo "$((--ltis))s"
done
echo "...TIME OUT"

exit 0
