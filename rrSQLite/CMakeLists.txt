#            _____  _____ _     _ _
#           /  ___||  _  | |   (_) |
#  _ __ _ __\ `--. | | | | |    _| |_ ___
# | '__| '__|`--. \| | | | |   | | __/ _ \
# | |  | |  /\__/ /\ \/' / |___| | ||  __/
# |_|  |_|  \____/  \_/\_\_____/_|\__\___|
# zhengrr          rrSQLite by FIGlet doom
# 2018-05-23 – 23
# The MIT License

project(rrSQLite VERSION 2018.5.23 LANGUAGES C)
project_extra()
compiler_warning_level(HIGHEST UTF-8)

facile_add_doxygen(OPTIMIZE_OUTPUT_FOR_C)

find_package(SQLite)
if(NOT SQLite_FOUND)
  message(WARNING "SQLite not found.")
endif()
aux_source_directory_enhanced(zSrc RECURSE SOURCE_PREFIXS "tmain" "tsuite" "tcase")
facile_add_check_executable(OPTION_INITIAL_ON
                            ${zSrc}
             LINK_LIBRARIES SQLite)
