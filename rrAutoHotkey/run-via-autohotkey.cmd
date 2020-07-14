@ECHO OFF
CHCP 65001
SETLOCAL ENABLEEXTENSIONS
SET script_ahk=%~dpn0.ahk
SET start_title=Run %script_ahk% via autohotkey

WHERE /Q autohotkey ^
        || ECHO The autohotkey executable not found. ^
        && CALL :pause_if_double_click ^
        && EXIT /B 1

IF NOT EXIST "%script_ahk%" (
        ECHO The autohotkey script "%script_ahk%" is not exist.
        CALL :pause_if_double_click
        EXIT /B 2
)

START "%start_title%" /MIN autohotkey "%script_ahk%" ^
        && ECHO Start via autohotkey succeed. ^
        || ECHO Start via autohotkey failed. ^
        && CALL :pause_if_double_click ^
        && EXIT /B 3

TIMEOUT /T 1 /NOBREAK 1>NUL ^
        && ECHO Wait one second for start succeed. ^
        || ECHO Wait one second for start failed. ^
        && CALL :pause_if_double_click ^
        && EXIT /B 4

TASKKILL /FI "WINDOWTITLE eq %start_title%" 1>NUL ^
        && ECHO Kill redundant console succeed. ^
        || ECHO Kill redundant console failed. ^
        && CALL :pause_if_double_click ^
        && EXIT /B 5

::CALL :pause_if_double_click
EXIT /B 0

:pause_if_double_click
        ECHO %CMDCMDLINE% | FINDSTR /L %COMSPEC% 1>NUL 2>NUL ^
                && PAUSE
        EXIT /B 0
