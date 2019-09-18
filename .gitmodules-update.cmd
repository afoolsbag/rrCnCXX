@ECHO OFF
CHCP 65001
SETLOCAL ENABLEEXTENSIONS
SET script_directory=%~dp0%

WHERE /Q git ^
        || ECHO The git executable not found. && ^
           CALL :pause_if_need && ^
           EXIT /B 1

git submodule update --remote %script_directory% ^
        && ECHO Update git submodules succeed. ^
        || ECHO Update git submodules failed. && ^
           CALL :pause_if_need && ^
           EXIT /B 2

CALL :pause_if_need
EXIT /B 0

:pause_if_need
        ECHO %CMDCMDLINE% | FINDSTR /L %COMSPEC% 1>NUL 2>NUL ^
                && PAUSE
EXIT /B 0
