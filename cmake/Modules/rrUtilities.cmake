# zhengrr
# 2016-10-8 – 2017-12-19
# The MIT License

#.rst:
# rrUtilities
# -----------
#
# zhengrr's CMake Utilities.
#
# CMake 3.3+ Required.

cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
cmake_policy(SET CMP0057 NEW)  # CMake 3.3+

#                            _ _
#   ___ ___  _ __ ___  _ __ (_| | ___ _ __
#  / __/ _ \| '_ ` _ \| '_ \| | |/ _ | '__|
# | (_| (_) | | | | | | |_) | | |  __| |
#  \___\___/|_| |_| |_| .__/|_|_|\___|_|
#                     |_|
#                        compiler by FIGlet

#.rst:
# .. command:: adjust_compiler_warning_level_to_highest
#
#  尝试将编译器警告等级调整至最高::
#
#   adjust_compiler_warning_level_to_highest()
function(adjust_compiler_warning_level_to_highest)

  get_property(langs GLOBAL PROPERTY ENABLED_LANGUAGES)

  if("C" IN_LIST langs)
    if(CMAKE_COMPILER_IS_GNUCC)
      string(CONCAT CMAKE_C_FLAGS "${CMAKE_C_FLAGS}" " -Wall ")
    elseif(MSVC)
      if(CMAKE_C_FLAGS MATCHES "/Wall")
      elseif(CMAKE_C_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/Wall" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
      else()
        string(CONCAT CMAKE_C_FLAGS "${CMAKE_C_FLAGS}" " /Wall ")
      endif()
    endif()
    set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} PARENT_SCOPE)
  endif()

  if("CXX" IN_LIST langs)
    if(CMAKE_COMPILER_IS_GNUCXX)
      string(CONCAT CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" " -Wall ")
    elseif(MSVC)
      if(CMAKE_CXX_FLAGS MATCHES "/Wall")
      elseif(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/Wall" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
      else()
        string(CONCAT CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" " /Wall ")
      endif()
    endif()
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} PARENT_SCOPE)
  endif()

endfunction()

#                  _       _     _
# __   ____ _ _ __(_) __ _| |__ | | ___ ___
# \ \ / / _` | '__| |/ _` | '_ \| |/ _ / __|
#  \ V | (_| | |  | | (_| | |_) | |  __\__ \
#   \_/ \__,_|_|  |_|\__,_|_.__/|_|\___|___/
#                        variables by FIGlet

# .rst
# .. command:: check_name_with_c_identifier_rules
#
#  检查输入是否符合ｃ语言标识符规则::
#
#   check_name_with_c_identifier_rules("<name>" <result>)
function(check_name_with_c_identifier_rules)

  if(NOT "${ARGC}" EQUAL 2)
    message(SEND_ERROR "Incorrect number of arguments (${ARGN}).")
    return()
  endif()

  if("${ARGV0}" MATCHES "^[A-Z_a-z]+[0-9A-Z_a-z]*$")
    set(${ARGV1} TRUE  PARENT_SCOPE)
  else()
    set(${ARGV1} FALSE PARENT_SCOPE)
  endif()

endfunction()

# .rst
# .. command:: set_product_variables
#
#  设置若干变量，假定``PROJECT_NAME``符合ｃ语言标识符规则::
#
#   set_product_variables(
#    [AUTHORS <authors>...]
#    [COPYRIGHT <copyright>]
#   )
#
#  变量列表::
#
#   PRODUCT_NAME
#   PRODUCT_NAME_UPPER
#   PRODUCT_NAME_LOWER
#   PRODUCT_SOURCE_DIR
#   PRODUCT_BINARY_DIR
#   PRODUCT_VERSION
#   PRODUCT_VERSION_MAJRO
#   PRODUCT_VERSION_MINOR
#   PRODUCT_VERSION_PATCH
#   PRODUCT_VERSION_TWEAK
#   PRODUCT_AUTHORS
#   PRODUCT_COPYRIGHT
function(set_product_variables)

  check_name_with_c_identifier_rules("${PROJECT_NAME}" conformed)
  if(NOT conformed)
    message(SEND_ERROR "Undesirable PROJECT_NAME(${PROJECT_NAME}).")
    return()
  endif()

  set(opts)
  set(ovks "COPYRIGHT")
  set(mvks "AUTHORS")
  cmake_parse_arguments("ARG" "${opts}" "${ovks}" "${mvks}" ${ARGN})
  if(PRODUCT_UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments(${PRODUCT_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  string(TOUPPER "${PROJECT_NAME}" name_upper)
  string(TOLOWER "${PROJECT_NAME}" name_lower)

  set(PRODUCT_NAME          "${PROJECT_NAME}"          PARENT_SCOPE)
  set(PRODUCT_NAME_UPPER    "${name_upper}"            PARENT_SCOPE)
  set(PRODUCT_NAME_LOWER    "${name_lower}"            PARENT_SCOPE)
  set(PRODUCT_SOURCE_DIR    "${PROJECT_SOURCE_DIR}"    PARENT_SCOPE)
  set(PRODUCT_BINARY_DIR    "${PROJECT_BINARY_DIR}"    PARENT_SCOPE)
  set(PRODUCT_VERSION       "${PROJECT_VERSION}"       PARENT_SCOPE)
  set(PRODUCT_VERSION_MAJRO "${PROJECT_VERSION_MAJOR}" PARENT_SCOPE)
  set(PRODUCT_VERSION_MINOR "${PROJECT_VERSION_MINOR}" PARENT_SCOPE)
  set(PRODUCT_VERSION_PATCH "${PROJECT_VERSION_PATCH}" PARENT_SCOPE)
  set(PRODUCT_VERSION_TWEAK "${PROJECT_VERSION_TWEAK}" PARENT_SCOPE)
  set(PRODUCT_AUTHORS       "${ARG_AUTHORS}"           PARENT_SCOPE)
  set(PRODUCT_COPYRIGHT     "${ARG_COPYRIGHT}"         PARENT_SCOPE)

endfunction()

# .rst
# .. command:: set_project_extra_variables
#
#  设置若干变量，假定``PROJECT_NAME``符合ｃ语言标识符规则::
#
#   set_project_extra_variables(
#    [AUTHORS <authors>...]
#    [COPYRIGHT <copyright>]
#   )
#
#  变量列表::
#
#   PROJECT_NAME_UPPER
#   PROJECT_NAME_LOWER
#   PROJECT_AUTHORS
#   PROJECT_COPYRIGHT
function(set_project_extra_variables)

  check_name_with_c_identifier_rules("${PROJECT_NAME}" conformed)
  if(NOT conformed)
    message(SEND_ERROR "Undesirable PROJECT_NAME(${PROJECT_NAME}).")
    return()
  endif()

  set(opts)
  set(ovks "COPYRIGHT")
  set(mvks "AUTHORS")
  cmake_parse_arguments("ARG" "${opts}" "${ovks}" "${mvks}" ${ARGN})
  if(PROJECT_UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments:(${PROJECT_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  string(TOUPPER "${PROJECT_NAME}" name_upper)
  string(TOLOWER "${PROJECT_NAME}" name_lower)

  if(NOT DEFINED ARG_AUTHORS)
    set(ARG_AUTHORS "${PRODUCT_AUTHORS}")
  endif()

  if(NOT DEFINED ARG_COPYRIGHT)
    set(ARG_COPYRIGHT "${PRODUCT_COPYRIGHT}")
  endif()

  set(PROJECT_NAME_UPPER "${name_upper}"    PARENT_SCOPE)
  set(PROJECT_NAME_LOWER "${name_lower}"    PARENT_SCOPE)
  set(PROJECT_AUTHORS    "${ARG_AUTHORS}"   PARENT_SCOPE)
  set(PROJECT_COPYRIGHT  "${ARG_COPYRIGHT}" PARENT_SCOPE)

endfunction()

#            _     _           _         _ _               _
#   __ _  __| | __|  ___ _   _| |__   __| (_)_ __ ___  ___| |_ ___  _ __ _   _
#  / _` |/ _` |/ _` / __| | | | '_ \ / _` | | '__/ _ \/ __| __/ _ \| '__| | | |
# | (_| | (_| | (_| \__ | |_| | |_) | (_| | | | |  __| (__| || (_) | |  | |_| |
#  \__,_|\__,_|\__,_|___/\__,_|_.__/ \__,_|_|_|  \___|\___|\__\___/|_|   \__, |
#                                                                        |___/
#                                                    add_subdirectory by FIGlet

# .rst
# .. command:: add_all_subdirectories
#
#  将目录下的所有子目录添加到构建::
#
#   add_all_subdirectories(
#    [SRC_PARRENT_DIR <parent directory of source directories>]
#    [BIN_PARRENT_DIR <parent directory of binary directories>]
#    [EXCLUDE_FROM_ALL]
#   )
function(add_all_subdirectories)
  set(opts "EXCLUDE_FROM_ALL")
  set(ovks "SRC_PARRENT_DIR" "BIN_PARRENT_DIR")
  set(mvks)
  cmake_parse_arguments("ARG" "${opts}" "${ovks}" "${mvks}" ${ARGN})
  if(PROJECT_UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments:(${PROJECT_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  if(DEFINED ARG_SRC_PARRENT_DIR)
    set(path "${ARG_SRC_PARRENT_DIR}")
  else()
    set(path "${CMAKE_CURRENT_LIST_DIR}")
  endif()

  file(GLOB files LIST_DIRECTORIES TRUE RELATIVE "${path}" "${path}/*")

  foreach(file IN LISTS files)
    if(IS_DIRECTORY "${path}/${file}")

      if(DEFINED ARG_SRC_PARRENT_DIR)
        set(src_dir "${path}/${file}")
      else()
        set(src_dir "${file}")
      endif()

      if(DEFINED ARG_BIN_PARRENT_DIR)
        set(bin_dir "${parent_binary_dir}/${dir}")
      else()
        unset(bin_dir)
      endif()

      if(DEFINED ARG_EXCLUDE_FROM_ALL)
        set(exclude_from_all "EXCLUDE_FROM_ALL")
      else()
        unset(exclude_from_all)
      endif()

      add_subdirectory("${src_dir}" ${bin_dir} ${exclude_from_all})

    endif()
  endforeach()

endfunction()

# .rst
# .. command:: add_subdirectory_with_option
#
#  提供选项，可选地将子目录添加到构建::
#
#   add_subdirectory_with_option(
#     SRC_DIR <source directory>
#    [BIN_DIR <binary directory>]
#    [EXCLUDE_FROM_ALL]
#    [INITIAL_OPTION <OFF|ON>]
#   )
macro(add_subdirectory_with_option)
  set(opts "EXCLUDE_FROM_ALL")
  set(ovks "SRC_DIR" "BIN_DIR" "INITIAL_OPTION")
  set(mvks)#########################################################################TODO
  cmake_parse_arguments("ARG" "${opts}" "${ovks}" "${mvks}" ${ARGN})
  if(PROJECT_UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments:(${PROJECT_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  check_name_with_c_identifier_rules("${ARGV0}" conformed)
  if(NOT conformed)
    message(SEND_ERROR "The source directory name(${ARGV0}) doesn't conform to the c identifier rules.")
    break()
  endif()
  string(TOUPPER "${ARGV0}" option_name)

  if(NOT DEFINED initial_option)
    set(initial_option OFF)
  endif()

  option(${option_name} "Subdirectory ${ARGV0}." ${initial_option})
  if(${option_name})
    add_subdirectory("${ARGV0}" ${binary_dir} ${exclude_from_all})
  endif()
endmacro()

#                                                    _ _               _
#   __ _ _   ___  _ ___  ___  _   _ _ __ ___ ___  __| (_)_ __ ___  ___| |_ ___  _ __ _   _
#  / _` | | | \ \/ / __|/ _ \| | | | '__/ __/ _  / _` | | '__/ _ \/ __| __/ _ \| '__| | | |
# | (_| | |_| |>  <\__ | (_) | |_| | | | (_|  __| (_| | | | |  __| (__| || (_) | |  | |_| |
#  \__,_|\__,_/_/\_|___/\___/ \__,_|_|  \___\___ \__,_|_|_|  \___|\___|\__\___/|_|   \__, |
#                                                                                    |___/
#                                                             aux_source_director by FIGlet

# .rst
# .. command:: aux_source_directory_with_group
#
#  ::
#
#   aux_source_directory_with_group(
#
#     [<binary directory>]
#     [EXCLUDE_FROM_ALL]
#     [INITIAL_OPTION <OFF|ON>]
#   )
#
#  参数::
#
#   ``<initial option>``默认为 "OFF"；
#   其余参数参见``add_subdirectory``指令。

(<dir> <var> <>)
