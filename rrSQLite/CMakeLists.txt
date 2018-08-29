#            _____  _____ _     _ _
#           /  ___||  _  | |   (_) |
#  _ __ _ __\ `--. | | | | |    _| |_ ___
# | '__| '__|`--. \| | | | |   | | __/ _ \
# | |  | |  /\__/ /\ \/' / |___| | ||  __/
# |_|  |_|  \____/  \_/\_\_____/_|\__\___| rrSQLite by FIGlet doom
# zhengrr
# 2018-05-23 – 2018-08-29
# The MIT License

project(rrSQLite VERSION 2018.8.29 LANGUAGES C)
project_extra()
compiler_warning_level(HIGHEST UTF-8)

facile_add_doxygen(OPTIMIZE_OUTPUT_FOR_C)

find_package(SQLite)

aux_source_directory_enhanced(zTest RECURSE)
facile_add_check_executable(SUBNAME "test"
                                    OPTION_INITIAL_ON
                                    ${zTest}
                     LINK_LIBRARIES SQLite::SQLite
                        POST_COPIES SQLite::SQLite)
