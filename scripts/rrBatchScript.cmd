::           ______       _       _     _____           _       _
::           | ___ \     | |     | |   /  ___|         (_)     | |
::  _ __ _ __| |_/ / __ _| |_ ___| |__ \ `--.  ___ _ __ _ _ __ | |_
:: | '__| '__| ___ \/ _` | __/ __| '_ \ `--. \/ __| '__| | '_ \| __|
:: | |  | |  | |_/ / (_| | || (__| | | /\__/ / (__| |  | | |_) | |_
:: |_|  |_|  \____/ \__,_|\__\___|_| |_\____/ \___|_|  |_| .__/ \__|
:: zhengrr                                               | |
:: 2019-09-10 – 2019-09-17                               |_|
:: Unlicense

:: see also: https://steve-jansen.github.io/guides/windows-batch-scripting/
::           https://wikibooks.org/wiki/Windows_Batch_Scripting
::           https://ss64.com/nt/

:: 沉默，除非显式指定，否则不回显指令
@ECHO OFF

:: 切换字符编码 Change Code Page
CHCP 65001

:: 注释
REM 官方提供的注释方式 Remark
::  或者使用两次标签操作，在大多数情形下可以用作注释，且更具可读性

:: 全局变量
SET GLOBAL_VARIABLE=this is a global string.

:: 局部变量
SETLOCAL ENABLEEXTENSIONS
SET local_variable=this is a local string.

:: 特殊变量
ECHO.
ECHO Script fully path: %~f0%
ECHO Script directory:  %~dp0%
ECHO Script name:       %~nx0%
ECHO Script callee:     %0%
ECHO Argument1:         %1%
ECHO Argument2:         %2%
ECHO Argument3:         %3%
ECHO Argument4:         %4%
ECHO Argument5:         %5%
ECHO Argument6:         %6%
ECHO Argument7:         %7%
ECHO Argument8:         %8%
ECHO Argument9:         %9%

SET script_directory=%~dp0%
SET script_name=%~nx0%

:: 判断指令成功与否
:: SomeCommand.exe && ECHO SomeCommand.exe succeeded!
:: SomeCommand.exe || ECHO SomeCommand.exe failed with return code %ERRORLEVEL%
:: SomeCommand.exe || EXIT /B 1

:: 输入输出重定向
:: SomeCommand.exe 1>NUL  2>NUL
:: SomeCommand.exe 1>>NUL 2>>NUL
:: SomeCommand.exe | AnotherCommand.exe

:: 条件语句
IF NOT EXIST "%0%" (
        ECHO Something is wrong.
        EXIT /B 1
)

SET var=hello, world
IF NOT DEFINED var (
        ECHO Something is wrong.
        EXIT /B 1
)

IF NOT "%var%"=="hello, world" (
        ECHO Something is wrong.
        EXIT /B 1
)

:: 检查是否从资源管理器（双击）运行，若是则在退出前暂停，以供使用者查看输出
CALL :pause_if_need
EXIT /B 0

:: 函数
:: 通过 `CALL :pause_if_need arg1 arg2 ... argN` 调用
:pause_if_need
        ECHO %CMDCMDLINE% | FINDSTR /L %COMSPEC% 1>NUL 2>NUL ^
                && PAUSE
EXIT /B 0
