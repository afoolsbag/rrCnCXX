#!/usr/bin/env bash
#           ______
#           |  _  \
#  _ __ _ __| | | |__ _  ___ _ __ ___   ___  _ __
# | '__| '__| | | / _` |/ _ \ '_ ` _ \ / _ \| '_ \
# | |  | |  | |/ / (_| |  __/ | | | | | (_) | | | |
# |_|  |_|  |___/ \__,_|\___|_| |_| |_|\___/|_| |_|
# zhengrr
# 2019-10-31 – 2019-11-13
# Unlicense
#
# 简陋的守护脚本

# 配置
readonly NAKING_USER='ubuntu'
readonly NAKING_WDIR='/home/ubuntu/script'
readonly NAKING_PATH='/home/ubuntu/script/rr.sh'
readonly NAKING_ARGS=''
readonly NAKING_INPFILE='/dev/null'
readonly NAKING_LOGFILE='/home/ubuntu/script/rr.log'
readonly NAKING_ERRFILE='/home/ubuntu/script/rr.err'

# 配置检验
if (( "$(grep --count --word-regexp "${NAKING_USER}" '/etc/passwd')" == 0 )); then
        echo "The config NAKING_USER isn't an existing user."
        exit 1
fi
if [[ ! "${NAKING_WDIR}" == '/'* || ! -d "${NAKING_WDIR}" ]]; then
        echo "The config NAKING_WDIR isn't an absolute path to directory."
        exit 1
fi
if [[ ! "${NAKING_PATH}" == '/'* || ! -x "${NAKING_PATH}" ]]; then
        echo "The config NAKING_PATH isn't an absolute path to execuable."
        exit 1
fi

# 自行生成的值
readonly NAKING_NAME="$(basename "${NAKING_PATH}")"

# 循环检查
while true; do

        if (( "$(ps aux | grep --count --word-regexp "${NAKING_NAME}")" <= 1 )); then
                cd "${NAKING_WDIR}"
                sudo --user="${NAKING_USER}" \
                        nohup "${NAKING_PATH}" ${NAKING_ARGS} \
                                0<"${NAKING_INPFILE}"\
                                1>"${NAKING_LOGFILE}"\
                                2>"${NAKING_ERRFILE}"\
                                &
                rc="$?"
                if (( rc != 0 )); then
                        echo "Run ${NAKING_NAME} failed with code $rc, more information see ${NAKING_LOGFILE} and ${NAKING_ERRFILE}."
                fi
        fi

        sleep 60

done
