#!/usr/bin/env bash
#                _          _ _               _       _
#               | |        | | |             (_)     | |
#  _ __ _ __ ___| |__   ___| | |___  ___ _ __ _ _ __ | |_
# | '__| '__/ __| '_ \ / _ \ | / __|/ __| '__| | '_ \| __|
# | |  | |  \__ \ | | |  __/ | \__ \ (__| |  | | |_) | |_
# |_|  |_|  |___/_| |_|\___|_|_|___/\___|_|  |_| .__/ \__|
# zhengrr                                      | |
# 2019-09-09 – 2019-09-11                      |_|
# Unlicense

# see also: https://shellscript.sh/
#           https://ss64.com/bash/

# 壳层脚本需要具备可读权限和可执行权限：
# `chmod a+rx rrshellscript.sh`

#-------------------------------------------------------------------------------
# 变量

# 继承壳层变量
# 1. 使用 `export` 导出变量，以使后续脚本继承此变量；
# 2. 使用 `source` 就地运行，以使该脚本继承所有变量（就地使用当前壳层运行，将导致 shebang 无效）；
#    `.` 是 `source` 的别名。

# 特殊变量
echo "_________________"
echo "SPECIAL VARIABLES"
echo ""
echo "hostname of running = \"${HOSTNAME}\""  # 运行时主机名
echo "username of running = \"${USER}\""      # 运行时用户名
echo "process of running  = \"${$}\""         # 运行时进程标识
echo "callee of running   = \"${0}\""         # 运行时调用名
echo "string of arguments = \"${*}\""         # 参数字串，不包括 `${0}`
echo "number of arguments = \"${#}\""         # 参数数目，不包括 `${0}`
echo "list of arguments   = \"${@}\""         # 参数列表，不包括 `${0}`
echo "argument 1          = \"${1}\""         # 参数 1
echo "argument 2          = \"${2}\""         # 参数 2
echo "argument 3          = \"${3}\""         # 参数 3
echo "argument 4          = \"${4}\""         # 参数 4
echo "argument 5          = \"${5}\""         # 参数 5
echo "argument 6          = \"${6}\""         # 参数 6
echo "argument 7          = \"${7}\""         # 参数 7
echo "argument 8          = \"${8}\""         # 参数 8
echo "argument 9          = \"${9}\""         # 参数 9
echo "number of this line = \"${LINENO}\""
echo "number of time cost = \"${SECONDS}\""
echo "random number       = \"${RANDOM}\""
echo ""

# 变量
echo "_________"
echo "VARIABLES"
echo ""
variable=""                                   # 变量赋值
echo "variable = \"${variable}\""             # 变量取值
echo "variable = \"${variable:-"default"}\""  # 变量取值，若为空则替换为缺省值
echo "variable = \"${variable:="default"}\""  # 变量取值，若为空则替换为缺省值，并将其赋予变量
echo ""

# 输入输出
# `echo -n "please enter a string: "`  在 sh 中使用 `"\c"` 替代 `-n`
# `read -r input`
# `echo "input: ${input}"`

# 转义字符
echo "_________________"
echo "ESCAPE CHARACTERS"
echo ""
echo "#34 \""
echo "#36 \$"
echo "#92 \\"
echo "#96 \`"
echo ""

#-------------------------------------------------------------------------------
# 测试
#
# 使用 `test` 判断表达式，若为真则返回 `0`，若为假则返回 `1`；
# `[` 是 `test` 的别名。
#
# 值得注意的是，`=` 和 `!=` 用于测试字符串相等，且不支持 `==`；
# 数值判断使用 `-ne`、`-lt`、`-le`、`-eq`、`-ge` 和 `-gt`，因为命令参数 `<` 和 `>` 会被理解为重定向。

# if 条件
expr1="-0"
expr2="+0"
if [ "${expr1}" = "${expr2}" ]; then
        echo "test NOT pass, something is wrong"
        exit 1
elif [ "${expr1}" -ne "${expr2}" ]; then
        echo "test NOT pass, something is wrong"
        exit 1
else
        :  # do nothing
fi

# case 条件
cond="xyz"
case "${cond}" in
        "abc")
                echo 'case "abc", something is wrong'
                ;;
        "def")
                echo 'case "def", something is wrong'
                ;;
        "ghi")
                echo 'case "ghi", something is wrong'
                ;;
        *)
                :  # do nothing
                ;;
esac

# for 循环
echo "___________"
echo "FOR LOOPING"
echo ""
for _ in 1 2 3 4 5 6 7 8 9; do
          echo -n "."
          sleep 1
done
echo ""
echo ""

# while 循环
#
# 若壳层支持，`((...))` 是 `[...]` 针对数学表达式的加强版；
# 　　　　　　`[[...]]` 是 `[...]` 针对字串表达式的加强版；
# 　　　　　　注意其中变量无需 `${...}` 取值。
echo "_____________"
echo "WHILE LOOPING"
echo ""
i=0
while (( i < 18 )); do
          echo -n "."
          i=$(( i + 2 ))
          sleep 1
done
echo ""
echo ""

#-------------------------------------------------------------------------------
# 外部程序

echo "________________"
echo "EXTERNAL PROGRAM"
echo ""

# 输入输出重定向
#
# 标准流的文件描述符
# 标准输入流 `stdin`  0
# 标准输出流 `stdout` 1
# 标准错误流 `stderr` 2
#
# 标准输出流重定向覆盖到文件 `1>"path"` 标准输出流重定向追加到文件 `1>>"path"`
# 标准错误流重定向覆盖到文件 `2>"path"` 标准错误流重定向追加到文件 `2>>"path"`
# 　　　二者重定向覆盖到文件 `&>"path"` 　　　二者重定向追加到文件 `&>>"path"`
ls "/" 1>"/dev/null"
ls "%" 2>"/dev/null"
ls     &>"/dev/null"

# 管道
# 将 `cmd1` 的标准输出流重定向到 `cmd2` 的标准输入流
# cmd1 args1... | cmd2 args2

# 后台
# 将 `cmd` 在后台启动
# cmd args... &

# 获取返回值
whoami &>"/dev/null"
whoami_return=${?}
echo "whoami_return = \"${whoami_return}\""

# 获取标准输出
whoami_stdout=$(whoami)  # 旧式用法 `user=`whoami``
echo "whoami_stdout = \"${whoami_stdout}\""

echo ""
