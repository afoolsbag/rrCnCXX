#!/usr/bin/env bash
#           ______
#           |  _  \
#  _ __ _ __| | | |__ _  ___ _ __ ___   ___  _ __
# | '__| '__| | | / _` |/ _ \ '_ ` _ \ / _ \| '_ \
# | |  | |  | |/ / (_| |  __/ | | | | | (_) | | | |
# |_|  |_|  |___/ \__,_|\___|_| |_| |_|\___/|_| |_|
# zhengrr
# 2019-10-31 – 2020-05-29
# Unlicense
#
# 一段简单的守护脚本

# 配置 CONFIGURATIONS
#-------------------------------------------------------------------------------
readonly CONFIGURATION_NAKED_WORKING_USER=''
readonly CONFIGURATION_NAKED_WORKING_DIRECTORY=''
readonly CONFIGURATION_NAKED_EXECUTABLE=''
readonly CONFIGURATION_NAKED_ARGUMENTS=''
readonly CONFIGURATION_NAKED_INPUT_FILE=''
readonly CONFIGURATION_NAKED_OUTPUT_FILE=''
readonly CONFIGURATION_NAKED_ERROR_FILE=''

# 命令行参数解析 COMMAND LINE ARGUMENTS PARSING
#-------------------------------------------------------------------------------
ARG_BACKGROUND=0
ARG_DEBUG=0
ARG_HELP=0
ARG_TEST=0
readonly ARGS=$(getopt --options "bdht" --longoptions "background,debug,help,test" --name "$0" -- "$@")
if (( $? )); then
    echo "Command line arguments parsing failed."
    exit 1
fi

eval set -- "${ARGS}"
while true; do
        case "$1" in
                '-b'|'--background')
                        ARG_BACKGROUND=1
                        shift
                        ;;
                '-d'|'--debug')
                        ARG_DEBUG=1
                        shift
                        ;;
                '-h'|'--help')
                        ARG_HELP=1
                        shift
                        ;;
                '-t'|'--test')
                        ARG_TEST=1
                        shift
                        ;;
                '--')
                        shift; break
                        ;;
                *)
                        echo 'Unexpected case routing.'
                        shift; exit 2
                        ;;
        esac
done

if (( ARG_HELP )); then
        echo "A simple daemon write by bash script."
        echo ""
        echo "Usage:"
        echo "        $0 [options]"
        echo ""
        echo "Options:"
        echo "        -b[ackground]   run in the background"
        echo "        -d[ebug]        show debug information"
        echo "        -h[elp]         show this message and exit"
        echo "        -t[est]         verify configurations and exit"
        exit 0
fi

# 配置验证和缺省值 CONFIGURATION VERIFICATION AND DEFAULT VALUES
#-------------------------------------------------------------------------------
readonly SCRIPT="$(readlink --canonicalize-existing "${BASH_SOURCE[0]}")"
readonly SCRIPT_DIRECTORY="$(readlink --canonicalize-existing "$(dirname SCRIPT)")"
readonly SCRIPT_BASENAME="$(basename "${SCRIPT}" ".sh")"

# 工作用户
# 1. 若指定了工作用户，则验证并使用该用户
# 2. 否则使用当前用户
if [[ -n "${CONFIGURATION_NAKED_WORKING_USER}" ]]; then
        if (( "$(grep --word-regexp --count "${CONFIGURATION_NAKED_WORKING_USER}" '/etc/passwd')" == 0 )); then
                echo "The CONFIGURATION_NAKED_WORKING_USER='${CONFIGURATION_NAKED_WORKING_USER}' isn't an existing user."
                exit 3
        fi
        readonly NAKED_WORKING_USER="${CONFIGURATION_NAKED_WORKING_USER}"
else
        readonly NAKED_WORKING_USER="$(whoami)"
fi

# 工作目录
# 1. 若指定了工作目录，则验证并使用该目录
# 2. 否则，若指定了程序，则验证并使用程序目录
# 3. 否则，使用脚本目录
if [[ -n "${CONFIGURATION_NAKED_WORKING_DIRECTORY}" ]]; then
        if [[ "${CONFIGURATION_NAKED_WORKING_DIRECTORY:0:1}" == '/' ]]; then
                tmp="$(readlink --canonicalize-missing "${CONFIGURATION_NAKED_WORKING_DIRECTORY}")"
        else
                tmp="$(readlink --canonicalize-missing "${SCRIPT_DIRECTORY}/${CONFIGURATION_NAKED_WORKING_DIRECTORY}")"
        fi
        if [[ ! -d "$tmp" ]]; then
                echo "The CONFIGURATION_NAKED_WORKING_DIRECTORY='${CONFIGURATION_NAKED_WORKING_DIRECTORY}' isn't an path to directory."
                exit 4
        fi
        readonly NAKED_WORKING_DIRECTORY="$tmp"
elif [[ -n "${CONFIGURATION_NAKED_EXECUTABLE}" ]]; then
        if [[ "${CONFIGURATION_NAKED_EXECUTABLE:0:1}" == '/' ]]; then
                tmp="$(dirname "$(readlink --canonicalize-missing "${CONFIGURATION_NAKED_EXECUTABLE}")")"
        else
                tmp="$(dirname "$(readlink --canonicalize-missing "${SCRIPT_DIRECTORY}/${CONFIGURATION_NAKED_EXECUTABLE}")")"
        fi
        if [[ ! -x "$tmp" ]]; then
                echo "The CONFIGURATION_NAKED_EXECUTABLE='${CONFIGURATION_NAKED_EXECUTABLE}' isn't an path to executable."
                exit 5
        fi
        readonly NAKED_WORKING_DIRECTORY="$tmp"
else
        readonly NAKED_WORKING_DIRECTORY="${SCRIPT_DIRECTORY}"
fi

# 程序
# 1. 若指定了程序，则验证并使用该程序
# 2. 否则，若脚本名形如 <executable_base_name>d[.sh]，则验证并使用程序 <working_directory>/<executable_base_name>[.sh]
if [[ -n "${CONFIGURATION_NAKED_EXECUTABLE}" ]]; then
        if [[ "${CONFIGURATION_NAKED_EXECUTABLE:0:1}" == '/' ]]; then
                tmp="$(readlink --canonicalize-missing "${CONFIGURATION_NAKED_EXECUTABLE}")"
        else
                tmp="$(readlink --canonicalize-missing "${SCRIPT_DIRECTORY}/${CONFIGURATION_NAKED_EXECUTABLE}")"
        fi
        if [[ ! -x "$tmp" ]]; then
                echo "The CONFIGURATION_NAKED_EXECUTABLE='${CONFIGURATION_NAKED_EXECUTABLE}' isn't an path to executable."
                exit 6
        fi
        readonly NAKED_EXECUTABLE="$tmp"
elif [[ "${SCRIPT_BASENAME: -1}" == 'd' ]]; then
        if [[ -x "${NAKED_WORKING_DIRECTORY}/${SCRIPT_BASENAME:0:-1}" ]]; then
                readonly NAKED_EXECUTABLE="${NAKED_WORKING_DIRECTORY}/${SCRIPT_BASENAME:0:-1}"
        elif [[ -x "${NAKED_WORKING_DIRECTORY}/${SCRIPT_BASENAME:0:-1}.sh" ]]; then
                readonly NAKED_EXECUTABLE="${NAKED_WORKING_DIRECTORY}/${SCRIPT_BASENAME:0:-1}.sh"
        else
                echo "The NAKED_EXECUTABLE is inferred from the script name, but isn't an path to executable."
                exit 7
        fi
else
        echo "The CONFIGURATION_NAKED_EXECUTABLE is missing, and the NAKED_EXECUTABLE can't be inferred from the script name."
        exit 8
fi
readonly NAKED_EXECUTABLE_NAME="$(basename "${NAKED_EXECUTABLE}")"

# 参数
readonly NAKED_ARGUMENTS="${CONFIGURATION_NAKED_ARGUMENTS}"

# 输入流重定向
# 1. 若指定了输入流，则验证并使用该输入流
# 2. 否则使用 /dev/null
if [[ -n "${CONFIGURATION_NAKED_INPUT_FILE}" ]]; then
        readonly NAKED_INPUT_FILE="${CONFIGURATION_NAKED_INPUT_FILE}"
else
        readonly NAKED_INPUT_FILE='/dev/null'
fi

# 输出流重定向
# 1. 若指定了输出流，则验证并使用该输出流
# 2. 否则使用 <working_directory>/<executable_name>.log
if [[ -n "${CONFIGURATION_NAKED_OUTPUT_FILE}" ]]; then
        if [[ ! -d "$(dirname "${CONFIGURATION_NAKED_OUTPUT_FILE}")" ]]; then
                echo "The parent directory of CONFIGURATION_NAKED_OUTPUT_FILE='${CONFIGURATION_NAKED_OUTPUT_FILE}' doesn't exist."
                exit 9
        fi
        readonly NAKED_OUTPUT_FILE="${CONFIGURATION_NAKED_OUTPUT_FILE}"
else
        readonly NAKED_OUTPUT_FILE="${NAKED_WORKING_DIRECTORY}/${NAKED_EXECUTABLE_NAME}.log"
fi

# 错误流重定向
# 1. 若指定了错误流，则验证并使用该错误流
# 2. 否则使用 <working_directory>/<executable_name>.err
if [[ -n "${CONFIGURATION_NAKED_ERROR_FILE}" ]]; then
        if [[ ! -d "$(dirname "${CONFIGURATION_NAKED_ERROR_FILE}")" ]]; then
                echo "The parent directory of CONFIGURATION_NAKED_ERROR_FILE='${CONFIGURATION_NAKED_ERROR_FILE}' doesn't exist."
                exit 10
        fi
        readonly NAKED_ERROR_FILE="${CONFIGURATION_NAKED_ERROR_FILE}"
else
        readonly NAKED_ERROR_FILE="${NAKED_WORKING_DIRECTORY}/${NAKED_EXECUTABLE_NAME}.err"
fi

# 调试和测试 DEBUGGING AND TESTING
#-------------------------------------------------------------------------------
if (( ARG_DEBUG )); then
        echo "NAKED_WORKING_USER='${NAKED_WORKING_USER}'"
        echo "NAKED_WORKING_DIRECTORY='${NAKED_WORKING_DIRECTORY}'"
        echo "NAKED_EXECUTABLE='${NAKED_EXECUTABLE}'"
        echo "NAKED_ARGUMENTS='${NAKED_ARGUMENTS}'"
        echo "NAKED_INPUT_FILE='${NAKED_INPUT_FILE}'"
        echo "NAKED_OUTPUT_FILE='${NAKED_OUTPUT_FILE}'"
        echo "NAKED_ERROR_FILE='${NAKED_ERROR_FILE}'"
fi

if (( ARG_TEST )); then
        exit 0
fi

# 后台运行 RUN IN THE BACKGROUND
#-------------------------------------------------------------------------------
if (( ARG_BACKGROUND )); then
        nohup "$0" 0<'/dev/null' 1>'/dev/null' 2>'/dev/null' &
        exit 0
fi

# 守护循环 DAEMON LOOP
#-------------------------------------------------------------------------------
while true; do

        if (( "$(ps ax | grep --invert-match 'grep' | grep --word-regexp --count "${NAKED_EXECUTABLE}")" == 0 )); then

                cd "${NAKED_WORKING_DIRECTORY}" \
                        || { echo "Change directory to '${NAKED_WORKING_DIRECTORY}' failed."; \
                             exit 11; }

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
