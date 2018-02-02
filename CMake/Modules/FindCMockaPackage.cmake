#  _____ _           _                                                   zhengrr
# |  ___(_)_ __   __| |                                          2018-1-31 – 2-2
# | |_  | | '_ \ / _` |                                          The MIT License
# |  _| | | | | | (_| |
# |_|   |_|_| |_|\__,_|
#         ____ __  __            _         ____            _
#        / ___|  \/  | ___   ___| | ____ _|  _ \ __ _  ___| | ____ _  __ _  ___
#       | |   | |\/| |/ _ \ / __| |/ / _` | |_) / _` |/ __| |/ / _` |/ _` |/ _ \
#       | |___| |  | | (_) | (__|   | (_| |  __| (_| | (__|   | (_| | (_| |  __/
#        \____|_|  |_|\___/ \___|_|\_\__,_|_|   \__,_|\___|_|\_\__,_|\__, |\___|
#                                        FindCMockaPackage by FIGlet |___/

cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
cmake_policy(SET CMP0057 NEW) #3.3+

#.rst:
# FindCMockaPackage
# -----------------
#
# 寻找CMocka包。
#
# 缓存变量：
# ::
#
#    CMOCKA_ROOT
#
# 结果变量：
# ::
#
#    CMOCKA_PACKAGE_FOUND
#    CMOCKA_PACKAGE_PREFIX_PATH
#
find_path(CMOCK_APACKAGE_PREFIX_PATH
  NAMES
    "cmocka/cmocka-config.cmake"
  HINTS
    "${CMOCKA_ROOT}/CMake"
    "$ENV{CMOCKA_ROOT}/CMake"
  NO_DEFAULT_PATH)
mark_as_advanced(CMOCKA_PACKAGE_PREFIX_PATH)

include("FindPackageHandleStandardArgs")
find_package_handle_standard_args("CMOCKA_PACKAGE"
  DEFAULT_MSG
    CMOCKA_PACKAGE_PREFIX_PATH)

if((CMOCKA_PACKAGE_FOUND) AND (NOT CMOCKA_PACKAGE_PREFIX_PATH IN_LIST CMAKE_PREFIX_PATH))
  list(APPEND CMAKE_PREFIX_PATH "${CMOCKA_PACKAGE_PREFIX_PATH}")
endif()
