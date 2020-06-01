@ECHO OFF
CHCP 65001
SETLOCAL ENABLEEXTENSIONS
SET script_directory=%~dp0

WHERE /Q plantuml ^
        || ECHO The plantuml executable not found. ^
        && CALL :pause_if_double_click ^
        && EXIT /B 1

WHERE /Q dot ^
        || ECHO The dot executable not found. ^
        && CALL :pause_if_double_click ^
        && EXIT /B 2

plantuml -o %script_directory%\out -r -charset UTF-8 %script_directory%\src ^
        && ECHO plantuml build succeed. ^
        || ECHO plantuml build failed. ^
        && CALL :pause_if_double_click ^
        && EXIT /B 3

CALL :pause_if_double_click
EXIT /B 0

:pause_if_double_click
        ECHO %CMDCMDLINE% | FINDSTR /L %COMSPEC% 1>NUL 2>NUL ^
                && PAUSE
        EXIT /B 0
