#          __        ___           _
#  _ __ _ _\ \      / (_)_ __   __| | _____      _____
# | '__| '__\ \ /\ / /| | '_ \ / _` |/ _ \ \ /\ / / __|
# | |  | |   \ V  V / | | | | | (_| | (_) \ V  V /\__ \
# |_|  |_|    \_/\_/  |_|_| |_|\__,_|\___/ \_/\_/ |___/
# zhengrr                           rrWindows by FIGlet
# 2016-10-12 – 2018-1-11
# The MIT License

project("rrWindows" LANGUAGES C)
set_project_extra_variables()

adjust_compiler_warning_level_to_highest()

quick_add_doxygen_with_option()

set(CMAKE_INCLUDE_CURRENT_DIR ON)

quick_add_executable_with_option(SUBNAME "ConsoleApplication" "ConsoleApplication.c")
quick_add_executable_with_option(SUBNAME "DesktopApplication" WIN32 "DesktopApplication.c")
quick_add_executable_with_option(SUBNAME "Peon" "Peon.c")
quick_add_executable_with_option(SUBNAME "Unicode" "Unicode.c")

#add_library(${PROJECT_NAME}_dicelib_static STATIC "DiceLib.h" "DiceLib.c")
add_library(${PROJECT_NAME_LOWER}_dicelib_shared SHARED "DiceLib.h" "DiceLib.c")
add_executable(${PROJECT_NAME_LOWER}_dice_exe "Dice.c")
target_link_libraries(${PROJECT_NAME_LOWER}_dice_exe ${PROJECT_NAME_LOWER}_dicelib_shared)
