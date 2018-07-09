#            _
#           | |
#  _ __ _ __| |    _   _  __ _
# | '__| '__| |   | | | |/ _` |
# | |  | |  | |___| |_| | (_| |
# |_|  |_|  \_____/\__,_|\__,_| rrLua by FIGlet doom
# zhengrr
# 2016-10-27 – 2018-07-09
# The MIT License

project(rrLua VERSION 2018.7.9 LANGUAGES C)
project_extra()
compiler_warning_level(HIGHEST UTF-8)

facile_add_doxygen(OPTIMIZE_OUTPUT_FOR_C)

find_package(Lua)

aux_source_directory_enhanced(zSrc RECURSE SOURCE_PREFIXS "tmain" "tsuite" "tcase")
facile_add_check_executable(OPTION_INITIAL_ON
                            ${zSrc}
             LINK_LIBRARIES Lua::Lua
                POST_COPIES Lua::Lua)
