::           ______       _       _     _____           _       _
::           | ___ \     | |     | |   /  ___|         (_)     | |
::  _ __ _ __| |_/ / __ _| |_ ___| |__ \ `--.  ___ _ __ _ _ __ | |_
:: | '__| '__| ___ \/ _` | __/ __| '_ \ `--. \/ __| '__| | '_ \| __|
:: | |  | |  | |_/ / (_| | || (__| | | /\__/ / (__| |  | | |_) | |_
:: |_|  |_|  \____/ \__,_|\__\___|_| |_\____/ \___|_|  |_| .__/ \__|
:: zhengrr                                               | |
:: 2019-09-10 – 2021-04-12                               |_|
:: Unlicense
::
:: see also: https://steve-jansen.github.io/guides/windows-batch-scripting/
::           https://wikibooks.org/wiki/Windows_Batch_Scripting
::           https://ss64.com/nt/

:: "关闭后续命令的默认回显，前缀 @ 用以关闭此行命令自身的默认回显"
@ECHO OFF

:: "切换字符编码（Change Code Page）到代码页 65001，即 UTF-8"
CHCP 65001 > NUL

REM "官方提供的注释方式（Remark）"
:: "或者使用两次标签操作，在大多数情形下可以用作注释，且更具可读性"
:: "含有非 ASCII 字符的注释若被误识别为命令，可将其用引号括起以缓解此问题"

:: "设置默认环境中的环境变量，一般由命令提示符作为默认环境"
:: "环境变量名对大小写不敏感，全大写以表明其作用范围是默认范围，在离开此脚本后依然有效"
SET COMMAND_PROMPT_ENVIRONMENT_VARIABLE=This is a string save on command prompt.

:: "新压入一层环境，最大支持嵌套 32 层环境"
:: "后续设置的环境变量都将在新压入的这一层，在 ENDLOCAL 或离开此脚本后这一层将被弹出，这些环境变量也将失效"
SETLOCAL ENABLEEXTENSIONS
:: "利用这一特性可以将这些环境变量视为局部变量"
SET var=This is a string save on local.


:: "实参变量"
:: see also: https://ss64.com/nt/syntax-args.html
ECHO.
ECHO 提供以下实参变量：
ECHO.
ECHO %%0                             %0
ECHO %%~f0 (fully)                   %~f0
ECHO %%~d0 (drive)                   %~d0
ECHO %%~p0 (path)                    %~p0
ECHO %%~n0 (name)                    %~n0
ECHO %%~x0 (extension)               %~x0
ECHO %%*                             %*
ECHO %%1                             %1
ECHO %%2                             %2
ECHO %%3                             %3
ECHO %%4                             %4
ECHO %%5                             %5
ECHO %%6                             %6
ECHO %%7                             %7
ECHO %%8                             %8
ECHO %%9                             %9

:: "动态变量"
:: see also: CMD> SET /?
ECHO.
ECHO 若启用了命令提示符扩展（SETLOCAL /ENABLEEXTENSIONS），则提供以下动态变量：
ECHO.
ECHO %%CD%%                           %CD%
ECHO %%DATE%%                         %DATE%
ECHO %%TIME%%                         %TIME%
ECHO %%RANDOM%%                       %RANDOM%
ECHO %%ERRORLEVEL%%                   %ERRORLEVEL%
ECHO %%CMDEXTVERSION%%                %CMDEXTVERSION%
ECHO %%CMDCMDLINE%%                   %CMDCMDLINE%
ECHO %%HIGHESTNUMANODENUMBER%%        %HIGHESTNUMANODENUMBER%

:: "环境变量"
:: see also: CMD> SET
ECHO.
ECHO 提供以下环境变量：
ECHO.
ECHO %%SYSTEMDRIVE%%                  %SYSTEMDRIVE%
ECHO %%SYSTEMROOT%%                   %SYSTEMROOT%
ECHO %%WINDIR%%                       %WINDIR%
ECHO %%DRIVERDATA%%                   %DRIVERDATA%
ECHO %%PROGRAMFILES%%                 %PROGRAMFILES%
ECHO %%PROGRAMFILES(x86)%%            %PROGRAMFILES(x86)%
ECHO %%COMMONPROGRAMFILES%%           %COMMONPROGRAMFILES%
ECHO %%COMMONPROGRAMFILES(x86)%%      %COMMONPROGRAMFILES(x86)%
ECHO %%PROGRAMDATA%%                  %PROGRAMDATA%
ECHO %%HOMEDRIVE%%                    %HOMEDRIVE%
ECHO %%ALLUSERSPROFILE%%              %ALLUSERSPROFILE%
ECHO %%PUBLIC%%                       %PUBLIC%
ECHO %%USERPROFILE%%                  %USERPROFILE%
ECHO %%APPDATA%%                      %APPDATA%
ECHO %%LOCALAPPDATA%%                 %LOCALAPPDATA%
ECHO %%TEMP%%                         %TEMP%
ECHO %%TMP%%                          %TMP%

:: "将父路径和脚本名赋予变量以便于使用"
SET parent=%~dp0
SET me=%~n0

:: "判断指令成功与否"
:: SomeCommand.exe && ECHO SomeCommand.exe succeeded!
:: SomeCommand.exe || ECHO SomeCommand.exe failed with return code %ERRORLEVEL%
:: SomeCommand.exe || EXIT /B 1

:: "输入输出重定向"
:: SomeCommand.exe 1>NUL  2>NUL
:: SomeCommand.exe 1>>NUL 2>>NUL
:: SomeCommand.exe | AnotherCommand.exe

:: "条件语句"
IF NOT EXIST "%0" (
        ECHO Something is wrong.
        EXIT /B 1
)

SET var=hello, world
IF NOT DEFINED var (
        ECHO Something is wrong.
        EXIT /B 1
)

IF NOT "%var%" == "hello, world" (
        ECHO Something is wrong.
        EXIT /B 1
)

:: "一种防止子例程结束父例程的技巧"
START "" /B /WAIT ^
        CMD /C ^
                ECHO. & ECHO The quick brown fox jumps over the lazy dog.

:: "检查是否从资源管理器（双击）运行，若是则在退出前暂停，以供使用者查看输出"
ECHO.
ECHO %%COMSPEC%%                      %COMSPEC%
ECHO %%CMDCMDLINE%%                   %CMDCMDLINE%
CALL :pause_if_double_click
EXIT /B 0

::                                           COMSPEC                      CMDCMDLINE
:: [x] Double click in explorer.             C:\WINDOWS\system32\cmd.exe  C:\WINDOWS\system32\cmd.exe /c ""path\to\script.cmd" "
:: [x] Run via start menu (Run).             ~                            C:\WINDOWS\system32\cmd.exe /c ""path\to\script.cmd" "
:: [x] Run via address bar.                  ~                            C:\WINDOWS\system32\cmd.exe /c ""path\to\script.cmd" "
:: [ ] Run via Cmd from start menu.          ~                            "C:\WINDOWS\system32\cmd.exe"
:: [ ] Run via Cmd from address bar.         ~                            "C:\Windows\System32\cmd.exe"
:: [ ] Run via Cmd in terminal.              ~                            cmd.exe
:: [x] Run via PowerShell from start menu.   ~                            C:\WINDOWS\system32\cmd.exe /c ""path\to\script.cmd" "
:: [x] Run via PowerShell from address bar.  ~                            C:\WINDOWS\system32\cmd.exe /c ""path\to\script.cmd" "
:: [x] Run via PowerShell in terminal.       ~                            C:\WINDOWS\system32\cmd.exe /c ""path\to\script.cmd" "
:: [ ] Run via Cmder from start menu.        ~                            cmd /k ""path\to\init.bat" "
:: [ ] Run via Cmder from address bar.       ~                            cmd /k ""path\to\init.bat" "
:: [ ] Run via Cmder in terminal.            ~                            cmd /k ""path\to\init.bat" "
:pause_if_double_click
        ECHO %CMDCMDLINE% | FINDSTR /L /B %COMSPEC% > NUL ^
                && PAUSE
        EXIT /B 0
