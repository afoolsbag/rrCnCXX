#!/usr/bin/env bash
#           ______
#           |  _  \
#  _ __ _ __| | | |__ _  ___ _ __ ___   ___  _ __
# | '__| '__| | | / _` |/ _ \ '_ ` _ \ / _ \| '_ \
# | |  | |  | |/ / (_| |  __/ | | | | | (_) | | | |
# |_|  |_|  |___/ \__,_|\___|_| |_| |_|\___/|_| |_|
# zhengrr
# 2019-10-31 – 2020-06-08
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
ARGUMENT_BACKGROUND=0
ARGUMENT_DEBUG=0
ARGUMENT_HELP=0
ARGUMENT_KILL=0
ARGUMENT_TEST=0
ARGUMENT_NAKED_WORKING_USER=''
ARGUMENT_NAKED_WORKING_DIRECTORY=''
ARGUMENT_NAKED_EXECUTABLE=''
ARGUMENT_NAKED_ARGUMENTS=''
ARGUMENT_NAKED_INPUT_FILE=''
ARGUMENT_NAKED_OUTPUT_FILE=''
ARGUMENT_NAKED_ERROR_FILE=''
ARGUMENTS=$(getopt --options 'bdhktu:f:x:a:i:o:e:' \
                   --longoptions 'background,debug,help,kill,test,working-user:,working-directory:,executable:,arguments:,input-file:,output-file:,error-file:' \
                   --name "$0" -- "$@")
if (( $? )); then
        echo 'Command line arguments parsing failed.'
        echo "Try '$0 --help' for help text."
        exit 1
fi

eval set -- "${ARGUMENTS}"
while true; do
        case "$1" in
                '-b'|'--background')         ARGUMENT_BACKGROUND=1;                  shift;    ;;
                '-d'|'--debug')              ARGUMENT_DEBUG=1;                       shift;    ;;
                '-h'|'--help')               ARGUMENT_HELP=1;                        shift;    ;;
                '-k'|'--kill')               ARGUMENT_KILL=1;                        shift;    ;;
                '-t'|'--test')               ARGUMENT_TEST=1;                        shift;    ;;
                '-u'|'--working-user')       ARGUMENT_NAKED_WORKING_USER="$2";       shift 2;  ;;
                '-f'|'--working-directory')  ARGUMENT_NAKED_WORKING_DIRECTORY="$2";  shift 2;  ;;
                '-x'|'--executable')         ARGUMENT_NAKED_EXECUTABLE="$2";         shift 2;  ;;
                '-a'|'--arguments')          ARGUMENT_NAKED_ARGUMENTS="$2";          shift 2;  ;;
                '-i'|'--input-file')         ARGUMENT_NAKED_INPUT_FILE="$2";         shift 2;  ;;
                '-o'|'--output-file')        ARGUMENT_NAKED_OUTPUT_FILE="$2";        shift 2;  ;;
                '-e'|'--error-file')         ARGUMENT_NAKED_ERROR_FILE="$2";         shift 2;  ;;
                '--')                                                                shift;    break;   ;;
                *)                           echo 'Unexpected case routing.';        shift;    exit 2;  ;;
        esac
done
if [[ -n "$*" ]]; then
        echo "$0: unexpected arguments: '$*'"
        echo 'Command line arguments parsing failed.'
        echo "Try '$0 --help' for help text."
        exit 3
fi

if (( ARGUMENT_HELP )); then
        echo 'A simple daemon write by bash script.'
        echo ''
        echo 'Usage:'
        echo "  $0 [options]"
        echo ''
        echo ' Control options:'
        echo '  -b, --background                                 Run in the background.'
        echo '  -d, --debug                                      Show debug information.'
        echo '  -h, --help                                       Show this message and exit.'
        echo '  -k, --kill                                       Kill daemon and naked process(es) by name.'
        echo '  -t, --test                                       Verify configurations and exit.'
        echo ''
        echo ' Argument options:'
        echo '  -u, --working-user=NAKED_WORKING_USER            Set the naked working user.'
        echo '  -f, --working-directory=NAKED_WORKING_DIRECTORY  Set the naked working directory.'
        echo '  -x, --executable=NAKED_EXECUTABLE                Set the naked executable.'
        echo '  -a, --arguments=NAKED_ARGUMENTS                  Set the naked arguments.'
        echo '  -i, --input-file=NAKED_INPUT_FILE                Set the naked input file.'
        echo '  -o, --output-file=NAKED_OUTPUT_FILE              Set the naked output file.'
        echo '  -e, --error-file=NAKED_ERROR_FILE                Set the naked error file.'
        exit 0
fi

# 配置验证和缺省值 CONFIGURATION VERIFICATION AND DEFAULT VALUES
#-------------------------------------------------------------------------------
readonly SCRIPT="$(readlink --canonicalize-existing "${BASH_SOURCE[0]}")"
readonly SCRIPT_DIRECTORY="$(readlink --canonicalize-existing "$(dirname "${SCRIPT}")")"
readonly SCRIPT_BASENAME="$(basename "${SCRIPT}" '.sh')"

# 工作用户
# 1. 若从命令行指定了工作用户，则验证并使用该用户
# 2. 否则，若从配置项指定了工作用户，则验证并使用该用户
# 3. 否则使用当前用户
if [[ -n "${ARGUMENT_NAKED_WORKING_USER}" ]]; then
        if (( "$(grep --word-regexp --count "${ARGUMENT_NAKED_WORKING_USER}" '/etc/passwd')" == 0 )); then
                echo "The ARGUMENT_NAKED_WORKING_USER='${ARGUMENT_NAKED_WORKING_USER}' isn't an existing user."
                exit 4
        fi
        readonly NAKED_WORKING_USER="${ARGUMENT_NAKED_WORKING_USER}"
elif [[ -n "${CONFIGURATION_NAKED_WORKING_USER}" ]]; then
        if (( "$(grep --word-regexp --count "${CONFIGURATION_NAKED_WORKING_USER}" '/etc/passwd')" == 0 )); then
                echo "The CONFIGURATION_NAKED_WORKING_USER='${CONFIGURATION_NAKED_WORKING_USER}' isn't an existing user."
                exit 5
        fi
        readonly NAKED_WORKING_USER="${CONFIGURATION_NAKED_WORKING_USER}"
else
        readonly NAKED_WORKING_USER="$(whoami)"
fi

# 工作目录
# 1. 若从命令行指定了工作目录，则验证并使用该目录
# 2. 否则，若从配置项指定了工作目录，则验证并使用该目录
# 3. 否则，若从命令行指定了程序，则验证并使用程序目录
# 4. 否则，若从配置项指定了程序，则验证并使用程序目录
# 5. 否则使用脚本目录
if [[ -n "${ARGUMENT_NAKED_WORKING_DIRECTORY}" ]]; then
        if [[ "${ARGUMENT_NAKED_WORKING_DIRECTORY:0:1}" == '/' ]]; then
                tmp="$(readlink --canonicalize-missing "${ARGUMENT_NAKED_WORKING_DIRECTORY}")"
        else
                tmp="$(readlink --canonicalize-missing "${SCRIPT_DIRECTORY}/${ARGUMENT_NAKED_WORKING_DIRECTORY}")"
        fi
        if [[ ! -d "$tmp" ]]; then
                echo "The ARGUMENT_NAKED_WORKING_DIRECTORY='${ARGUMENT_NAKED_WORKING_DIRECTORY}' isn't an path to directory."
                exit 6
        fi
        readonly NAKED_WORKING_DIRECTORY="$tmp"
elif [[ -n "${CONFIGURATION_NAKED_WORKING_DIRECTORY}" ]]; then
        if [[ "${CONFIGURATION_NAKED_WORKING_DIRECTORY:0:1}" == '/' ]]; then
                tmp="$(readlink --canonicalize-missing "${CONFIGURATION_NAKED_WORKING_DIRECTORY}")"
        else
                tmp="$(readlink --canonicalize-missing "${SCRIPT_DIRECTORY}/${CONFIGURATION_NAKED_WORKING_DIRECTORY}")"
        fi
        if [[ ! -d "$tmp" ]]; then
                echo "The CONFIGURATION_NAKED_WORKING_DIRECTORY='${CONFIGURATION_NAKED_WORKING_DIRECTORY}' isn't an path to directory."
                exit 7
        fi
        readonly NAKED_WORKING_DIRECTORY="$tmp"
elif [[ -n "${ARGUMENT_NAKED_EXECUTABLE}" ]]; then
        if [[ "${ARGUMENT_NAKED_EXECUTABLE:0:1}" == '/' ]]; then
                tmp="$(readlink --canonicalize-missing "${ARGUMENT_NAKED_EXECUTABLE}")"
        else
                tmp="$(readlink --canonicalize-missing "${SCRIPT_DIRECTORY}/${ARGUMENT_NAKED_EXECUTABLE}")"
        fi
        if [[ ! -x "$tmp" ]]; then
                echo "The ARGUMENT_NAKED_EXECUTABLE='${ARGUMENT_NAKED_EXECUTABLE}' isn't an path to executable."
                exit 8
        fi
        readonly NAKED_WORKING_DIRECTORY="$(dirname "$tmp")"
elif [[ -n "${CONFIGURATION_NAKED_EXECUTABLE}" ]]; then
        if [[ "${CONFIGURATION_NAKED_EXECUTABLE:0:1}" == '/' ]]; then
                tmp="$(readlink --canonicalize-missing "${CONFIGURATION_NAKED_EXECUTABLE}")"
        else
                tmp="$(readlink --canonicalize-missing "${SCRIPT_DIRECTORY}/${CONFIGURATION_NAKED_EXECUTABLE}")"
        fi
        if [[ ! -x "$tmp" ]]; then
                echo "The CONFIGURATION_NAKED_EXECUTABLE='${CONFIGURATION_NAKED_EXECUTABLE}' isn't an path to executable."
                exit 9
        fi
        readonly NAKED_WORKING_DIRECTORY="$(dirname "$tmp")"
else
        readonly NAKED_WORKING_DIRECTORY="${SCRIPT_DIRECTORY}"
fi

# 程序
# 1. 若从命令行指定了程序，则验证并使用该程序
# 2. 否则，若从配置项指定了程序，则验证并使用该程序
# 3. 否则，若脚本名形如 <executable_base_name>d[.sh]，则验证并使用程序 <working_directory>/<executable_base_name>[.sh]
if [[ -n "${ARGUMENT_NAKED_EXECUTABLE}" ]]; then
        if [[ "${ARGUMENT_NAKED_EXECUTABLE:0:1}" == '/' ]]; then
                tmp="$(readlink --canonicalize-missing "${ARGUMENT_NAKED_EXECUTABLE}")"
        else
                tmp="$(readlink --canonicalize-missing "${SCRIPT_DIRECTORY}/${ARGUMENT_NAKED_EXECUTABLE}")"
        fi
        if [[ ! -x "$tmp" ]]; then
                echo "The ARGUMENT_NAKED_EXECUTABLE='${ARGUMENT_NAKED_EXECUTABLE}' isn't an path to executable."
                exit 10
        fi
        readonly NAKED_EXECUTABLE="$tmp"
elif [[ -n "${CONFIGURATION_NAKED_EXECUTABLE}" ]]; then
        if [[ "${CONFIGURATION_NAKED_EXECUTABLE:0:1}" == '/' ]]; then
                tmp="$(readlink --canonicalize-missing "${CONFIGURATION_NAKED_EXECUTABLE}")"
        else
                tmp="$(readlink --canonicalize-missing "${SCRIPT_DIRECTORY}/${CONFIGURATION_NAKED_EXECUTABLE}")"
        fi
        if [[ ! -x "$tmp" ]]; then
                echo "The CONFIGURATION_NAKED_EXECUTABLE='${CONFIGURATION_NAKED_EXECUTABLE}' isn't an path to executable."
                exit 11
        fi
        readonly NAKED_EXECUTABLE="$tmp"
elif [[ "${SCRIPT_BASENAME: -1}" == 'd' ]]; then
        if [[ -x "${NAKED_WORKING_DIRECTORY}/${SCRIPT_BASENAME:0:-1}" ]]; then
                readonly NAKED_EXECUTABLE="${NAKED_WORKING_DIRECTORY}/${SCRIPT_BASENAME:0:-1}"
        elif [[ -x "${NAKED_WORKING_DIRECTORY}/${SCRIPT_BASENAME:0:-1}.sh" ]]; then
                readonly NAKED_EXECUTABLE="${NAKED_WORKING_DIRECTORY}/${SCRIPT_BASENAME:0:-1}.sh"
        else
                echo "The NAKED_EXECUTABLE='${NAKED_WORKING_DIRECTORY}/${SCRIPT_BASENAME:0:-1}[.sh]' is inferred from the script name, but isn't an path to executable."
                exit 12
        fi
else
        echo "The ARGUMENT_NAKED_EXECUTABLE and CONFIGURATION_NAKED_EXECUTABLE is missing, and the NAKED_EXECUTABLE can't be inferred from the script name."
        exit 13
fi
readonly NAKED_EXECUTABLE_NAME="$(basename "${NAKED_EXECUTABLE}")"

# 参数
# 1. 若从命令行指定了参数，则验证并使用该参数
# 2. 否则使用从配置项指定的参数
if [[ -n "${ARGUMENT_NAKED_ARGUMENTS}" ]]; then
        readonly NAKED_ARGUMENTS="${ARGUMENT_NAKED_ARGUMENTS}"
else
        readonly NAKED_ARGUMENTS="${CONFIGURATION_NAKED_ARGUMENTS}"
fi

# 输入流重定向
# 1. 若从命令行指定了输入流，则验证并使用该输入流
# 2. 否则，若从配置项指定了输入流，则验证并使用该输入流
# 2. 否则使用 /dev/null
if [[ -n "${ARGUMENT_NAKED_INPUT_FILE}" ]]; then
        if [[ "${ARGUMENT_NAKED_INPUT_FILE:0:1}" == '/' ]]; then
                tmp="$(readlink --canonicalize-missing "${ARGUMENT_NAKED_INPUT_FILE}")"
        else
                tmp="$(readlink --canonicalize-missing "${SCRIPT_DIRECTORY}/${ARGUMENT_NAKED_INPUT_FILE}")"
        fi
        if [[ ! -e "$tmp" ]]; then
                echo "The ARGUMENT_NAKED_INPUT_FILE='${ARGUMENT_NAKED_INPUT_FILE}' doesn't exist."
                exit 14
        fi
        readonly NAKED_INPUT_FILE="$tmp"
elif [[ -n "${CONFIGURATION_NAKED_INPUT_FILE}" ]]; then
        if [[ "${CONFIGURATION_NAKED_INPUT_FILE:0:1}" == '/' ]]; then
                tmp="$(readlink --canonicalize-missing "${CONFIGURATION_NAKED_INPUT_FILE}")"
        else
                tmp="$(readlink --canonicalize-missing "${SCRIPT_DIRECTORY}/${CONFIGURATION_NAKED_INPUT_FILE}")"
        fi
        if [[ ! -e "$tmp" ]]; then
                echo "The CONFIGURATION_NAKED_INPUT_FILE='${CONFIGURATION_NAKED_INPUT_FILE}' doesn't exist."
                exit 15
        fi
        readonly NAKED_INPUT_FILE="$tmp"
else
        readonly NAKED_INPUT_FILE='/dev/null'
fi

# 输出流重定向
# 1. 若从命令行指定了输出流，则验证并使用该输出流
# 1. 否则，若从配置项指定了输出流，则验证并使用该输出流
# 2. 否则使用 <working_directory>/<executable_name>.log
if [[ -n "${ARGUMENT_NAKED_OUTPUT_FILE}" ]]; then
        if [[ "${ARGUMENT_NAKED_OUTPUT_FILE:0:1}" == '/' ]]; then
                tmp="$(readlink --canonicalize-missing "${ARGUMENT_NAKED_OUTPUT_FILE}")"
        else
                tmp="$(readlink --canonicalize-missing "${SCRIPT_DIRECTORY}/${ARGUMENT_NAKED_OUTPUT_FILE}")"
        fi
        if [[ ! -d "$(dirname "$tmp")" ]]; then
                echo "The parent directory of ARGUMENT_NAKED_OUTPUT_FILE='${ARGUMENT_NAKED_OUTPUT_FILE}' doesn't exist."
                exit 16
        fi
        readonly NAKED_OUTPUT_FILE="$tmp"
elif [[ -n "${CONFIGURATION_NAKED_OUTPUT_FILE}" ]]; then
        if [[ "${CONFIGURATION_NAKED_OUTPUT_FILE:0:1}" == '/' ]]; then
                tmp="$(readlink --canonicalize-missing "${CONFIGURATION_NAKED_OUTPUT_FILE}")"
        else
                tmp="$(readlink --canonicalize-missing "${SCRIPT_DIRECTORY}/${CONFIGURATION_NAKED_OUTPUT_FILE}")"
        fi
        if [[ ! -d "$(dirname "$tmp")" ]]; then
                echo "The parent directory of CONFIGURATION_NAKED_OUTPUT_FILE='${CONFIGURATION_NAKED_OUTPUT_FILE}' doesn't exist."
                exit 17
        fi
        readonly NAKED_OUTPUT_FILE="$tmp"
else
        readonly NAKED_OUTPUT_FILE="${NAKED_WORKING_DIRECTORY}/${NAKED_EXECUTABLE_NAME}.log"
fi

# 错误流重定向
# 1. 若从命令行指定了错误流，则验证并使用该错误流
# 1. 否则，若从配置项指定了错误流，则验证并使用该错误流
# 2. 否则使用 <working_directory>/<executable_name>.err
if [[ -n "${ARGUMENT_NAKED_ERROR_FILE}" ]]; then
        if [[ "${ARGUMENT_NAKED_ERROR_FILE:0:1}" == '/' ]]; then
                tmp="$(readlink --canonicalize-missing "${ARGUMENT_NAKED_ERROR_FILE}")"
        else
                tmp="$(readlink --canonicalize-missing "${SCRIPT_DIRECTORY}/${ARGUMENT_NAKED_ERROR_FILE}")"
        fi
        if [[ ! -d "$(dirname "$tmp")" ]]; then
                echo "The parent directory of ARGUMENT_NAKED_ERROR_FILE='${ARGUMENT_NAKED_ERROR_FILE}' doesn't exist."
                exit 18
        fi
        readonly NAKED_ERROR_FILE="$tmp"
elif [[ -n "${CONFIGURATION_NAKED_ERROR_FILE}" ]]; then
        if [[ "${CONFIGURATION_NAKED_ERROR_FILE:0:1}" == '/' ]]; then
                tmp="$(readlink --canonicalize-missing "${CONFIGURATION_NAKED_ERROR_FILE}")"
        else
                tmp="$(readlink --canonicalize-missing "${SCRIPT_DIRECTORY}/${CONFIGURATION_NAKED_ERROR_FILE}")"
        fi
        if [[ ! -d "$(dirname "$tmp")" ]]; then
                echo "The parent directory of CONFIGURATION_NAKED_ERROR_FILE='${CONFIGURATION_NAKED_ERROR_FILE}' doesn't exist."
                exit 19
        fi
        readonly NAKED_ERROR_FILE="$tmp"
else
        readonly NAKED_ERROR_FILE="${NAKED_WORKING_DIRECTORY}/${NAKED_EXECUTABLE_NAME}.err"
fi

# 调试和测试 DEBUGGING AND TESTING
#-------------------------------------------------------------------------------
if (( ARGUMENT_DEBUG )); then
        echo "NAKED_WORKING_USER='${NAKED_WORKING_USER}'"
        echo "NAKED_WORKING_DIRECTORY='${NAKED_WORKING_DIRECTORY}'"
        echo "NAKED_EXECUTABLE='${NAKED_EXECUTABLE}'"
        echo "NAKED_ARGUMENTS='${NAKED_ARGUMENTS}'"
        echo "NAKED_INPUT_FILE='${NAKED_INPUT_FILE}'"
        echo "NAKED_OUTPUT_FILE='${NAKED_OUTPUT_FILE}'"
        echo "NAKED_ERROR_FILE='${NAKED_ERROR_FILE}'"
fi

if (( ARGUMENT_TEST )); then
        exit 0
fi

# 按名称杀死守护进程和裸进程 KILL DAEMON AND NAKED PROCESS(ES) BY NAME
#-------------------------------------------------------------------------------
if (( ARGUMENT_KILL )); then
        ps -Af | grep --invert-match 'grep' | grep --word-regexp "${SCRIPT}" | grep --invert-match --word-regexp "${$}" | awk '{print $2}' | xargs kill --signal TERM &>'/dev/null'
        ps -Af | grep --invert-match 'grep' | grep --word-regexp "${NAKED_EXECUTABLE}" | awk '{print $2}' | xargs kill --signal TERM &>'/dev/null'
        exit 0
fi

# 后台运行 RUN IN THE BACKGROUND
#-------------------------------------------------------------------------------
if (( ARGUMENT_BACKGROUND )); then
        nohup "${SCRIPT}" \
                -u "${ARGUMENT_NAKED_WORKING_USER}" \
                -f "${ARGUMENT_NAKED_WORKING_DIRECTORY}" \
                -x "${ARGUMENT_NAKED_EXECUTABLE}" \
                -a "${ARGUMENT_NAKED_ARGUMENTS}" \
                -i "${ARGUMENT_NAKED_INPUT_FILE}" \
                -o "${ARGUMENT_NAKED_OUTPUT_FILE}" \
                -e "${ARGUMENT_NAKED_ERROR_FILE}" \
                0<'/dev/null' 1>'/dev/null' 2>'/dev/null' &
        exit 0
fi

# 按名称守护循环 DAEMON LOOP BY NAME
#-------------------------------------------------------------------------------
while true; do

        if (( "$(ps -Af | grep --invert-match 'grep' | grep --word-regexp --count "${NAKED_EXECUTABLE}")" == 0 )); then

                cd "${NAKED_WORKING_DIRECTORY}" \
                        || { echo "Change directory to '${NAKED_WORKING_DIRECTORY}' failed."; \
                             exit 20; }

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
