#           ______ _____ _____ _______   __
#           | ___ \  _  /  ___|_   _\ \ / /
#  _ __ _ __| |_/ / | | \ `--.  | |  \ V /
# | '__| '__|  __/| | | |`--. \ | |  /   \  zhengrr
# | |  | |  | |   \ \_/ /\__/ /_| |_/ /^\ \ 2019-02-15 – 2019-02-15
# |_|  |_|  \_|    \___/\____/ \___/\/   \/ Unlicense

project(rrPOSIX VERSION 2019.02.15 LANGUAGES C)
project_more()
compile_option(RECOMMENDED_WARNING_LEVEL MULTIPLE_PROCESSES UTF-8 WARNING_AS_ERROR)

add_doxygen(WITH_OPTION OPTIMIZE_OUTPUT_FOR_C)

if(3.12 VERSION_LESS CMAKE_VERSION)
  cmake_policy(SET CMP0074 NEW)
endif()
find_package(Check)

aux_source_directory_ex(zSource RECURSE)
add_executable_ex(
  ${zSource} C11
  INCLUDE_DIRECTORIES PRIVATE "./"
  LINK_LIBRARIES      PRIVATE pthread
                              Check::check)
