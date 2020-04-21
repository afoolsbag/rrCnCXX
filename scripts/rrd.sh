#!/usr/bin/env bash
#           ______
#           |  _  \
#  _ __ _ __| | | |__ _  ___ _ __ ___   ___  _ __
# | '__| '__| | | / _` |/ _ \ '_ ` _ \ / _ \| '_ \
# | |  | |  | |/ / (_| |  __/ | | | | | (_) | | | |
# |_|  |_|  |___/ \__,_|\___|_| |_| |_|\___/|_| |_|
# zhengrr
# 2019-10-31 – 2020-04-21
# Unlicense
#
# 一段简单的守护脚本

# 配置
readonly NAKED_WORKING_USER='zwh'
readonly NAKED_WORKING_DIRECTORY='/home/scripts'
readonly NAKED_EXECUTABLE='/home/scripts/rr.sh'
readonly NAKED_ARGUMENTS=''
readonly NAKED_INPUT_FILE='/dev/null'
readonly NAKED_OUTPUT_FILE='/home/scripts/rr.log'
readonly NAKED_ERROR_FILE='/home/scripts/rr.err'

# 配置检验
if (( "$(grep --word-regexp --count "${NAKED_WORKING_USER}" '/etc/passwd')" == 0 )); then
        echo "The config NAKED_WORKING_USER='${NAKED_WORKING_USER}' isn't an existing user."
        exit 1
fi
if [[ ! "${NAKED_WORKING_DIRECTORY}" == '/'* || ! -d "${NAKED_WORKING_DIRECTORY}" ]]; then
        echo "The config NAKED_WORKING_DIRECTORY='${NAKED_WORKING_DIRECTORY}' isn't an absolute path to directory."
        exit 1
fi
if [[ ! "${NAKED_EXECUTABLE}" == '/'* || ! -x "${NAKED_EXECUTABLE}" ]]; then
        echo "The config NAKED_EXECUTABLE='${NAKED_EXECUTABLE}' isn't an absolute path to executable."
        exit 1
fi

# 自行生成的值
readonly NAKED_EXECUTABLE_NAME="$(basename "${NAKED_EXECUTABLE}")"

# 循环检查
while true; do

        if (( "$(ps aux | grep --invert-match 'grep' | grep --word-regexp --count "${NAKED_EXECUTABLE}")" == 0 )); then

                cd "${NAKED_WORKING_DIRECTORY}"
                rc="$?"
                if (( rc != 0 )); then
                        echo "Change directory to '${NAKED_WORKING_DIRECTORY}' failed."
                        exit 1
                fi

                sudo --user="${NAKED_WORKING_USER}" \
                        nohup "${NAKED_EXECUTABLE}" ${NAKED_ARGUMENTS} \
                                0<"${NAKED_INPUT_FILE}" \
                                1>"${NAKED_OUTPUT_FILE}" \
                                2>"${NAKED_ERROR_FILE}" \
                                &
                rc="$?"
                if (( rc != 0 )); then
                        echo "Run ${NAKED_EXECUTABLE_NAME} failed with code $rc, more information see '${NAKED_OUTPUT_FILE}' and '${NAKED_ERROR_FILE}'."
                fi

        fi

        sleep 15s

done
