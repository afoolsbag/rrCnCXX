#                          _ _
#                         | | |
#  _ __ _ __ ___ _ __   __| | | ___   __ _
# | '__| '__/ __| '_ \ / _` | |/ _ \ / _` |
# | |  | |  \__ \ |_) | (_| | | (_) | (_| |
# |_|  |_|  |___/ .__/ \__,_|_|\___/ \__, |
#               | |                   __/ |
# zhengrr       |_|                  |___/  rrspdlog by FIGlet doom
# 2018-08-04 – 2018-08-04
# The MIT License

project(rrspdlog VERSION 2108.8.4 LANGUAGES CXX)
project_extra()
compiler_warning_level(HIGHEST UTF-8)

facile_add_doxygen()

find_package(spdlog)

aux_source_directory_enhanced(zSrc RECURSE)
facile_add_executable(OPTION_INITIAL_ON
                      ${zSrc}
  INCLUDE_DIRECTORIES PRIVATE ${spdlog_INCLUDE_DIRS})
