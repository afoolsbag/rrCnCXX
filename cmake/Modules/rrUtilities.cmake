#            _   _ _   _ _ _ _   _
#  _ __ _ __| | | | |_(_| (_| |_(_) ___ ___
# | '__| '__| | | | __| | | | __| |/ _ / __|
# | |  | |  | |_| | |_| | | | |_| |  __\__ \
# |_|  |_|   \___/ \__|_|_|_|\__|_|\___|___/
#                      rrUtilities by FIGlet

# zhengrr
# 2016-10-8 – 2017-12-20
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

#                                  _               _
#  _ __   __ _ _ __ ___   ___  ___| |__   ___  ___| | __
# | '_ \ / _` | '_ ` _ \ / _ \/ __| '_ \ / _ \/ __| |/ /
# | | | | (_| | | | | | |  __| (__| | | |  __| (__|   <
# |_| |_|\__,_|_| |_| |_|\___|\___|_| |_|\___|\___|_|\_\
#                                   name check by FIGlet

# .rst
# .. command:: check_name_with_c_identifier_rules
#
#  检查输入是否符合Ｃ语言标识符（命名）规则::
#
#   check_name_with_c_identifier_rules(
#     "<name>"
#      <result>
#   )
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
# .. command:: check_name_with_cmake_recommend_variable_rules
#
#  检查输入是否符合ＣＭａｋｅ推荐变量（命名）规则::
#
#   check_name_with_cmake_recommend_variable_rules(
#     "<name>"
#      <result>
#   )
function(check_name_with_cmake_recommend_variable_rules)

  if(NOT "${ARGC}" EQUAL 2)
    message(SEND_ERROR "Incorrect number of arguments (${ARGN}).")
    return()
  endif()

  if("${ARGV0}" MATCHES "^[-0-9A-Z_a-z]+$")
    set(${ARGV1} TRUE  PARENT_SCOPE)
  else()
    set(${ARGV1} FALSE PARENT_SCOPE)
  endif()

endfunction()

# .rst
# .. command:: check_name_with_file_extension_rules
#
#  检查输入是否符合文件扩展名（命名）规则::
#
#   check_name_with_file_extension_rules(
#     "<name>"
#      <result>
#   )
function(check_name_with_file_extension_rules)

  if(NOT "${ARGC}" EQUAL 2)
    message(SEND_ERROR "Incorrect number of arguments (${ARGN}).")
    return()
  endif()

  if("${ARGV0}" MATCHES "^([.][0-9A-Za-z]+)+$")
    set(${ARGV1} TRUE  PARENT_SCOPE)
  else()
    set(${ARGV1} FALSE PARENT_SCOPE)
  endif()

endfunction()

#                  _       _     _
# __   ____ _ _ __(_) __ _| |__ | | ___ ___
# \ \ / / _` | '__| |/ _` | '_ \| |/ _ / __|
#  \ V | (_| | |  | | (_| | |_) | |  __\__ \
#   \_/ \__,_|_|  |_|\__,_|_.__/|_|\___|___/
#                        variables by FIGlet

# .rst
# .. command:: set_product_variables
#
#  设置若干变量::
#
#   set_product_variables(
#     [AUTHORS   "<authors>"...]
#     [COPYRIGHT "<copyright>" ]
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
  if(DEFINED ARG_UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments(${ARG_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  string(TOUPPER "${PROJECT_NAME}" nameupper)
  string(TOLOWER "${PROJECT_NAME}" namelower)

  set(PRODUCT_NAME          "${PROJECT_NAME}"          PARENT_SCOPE)
  set(PRODUCT_NAME_UPPER    "${nameupper}"             PARENT_SCOPE)
  set(PRODUCT_NAME_LOWER    "${namelower}"             PARENT_SCOPE)
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
#  设置若干变量::
#
#   set_project_extra_variables(
#     [AUTHORS   "<authors>"...]
#     [COPYRIGHT "<copyright>" ]
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
  if(DEFINED ARG_UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments(${ARG_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  string(TOUPPER "${PROJECT_NAME}" nameupper)
  string(TOLOWER "${PROJECT_NAME}" namelower)

  if(NOT DEFINED ARG_AUTHORS)
    set(ARG_AUTHORS "${PRODUCT_AUTHORS}")
  endif()

  if(NOT DEFINED ARG_COPYRIGHT)
    set(ARG_COPYRIGHT "${PRODUCT_COPYRIGHT}")
  endif()

  set(PROJECT_NAME_UPPER "${nameupper}"     PARENT_SCOPE)
  set(PROJECT_NAME_LOWER "${namelower}"     PARENT_SCOPE)
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
#  将目录下所有子目录添加到构建::
#
#   add_all_subdirectories(
#     [SRC_PRT_DIR      "<parent directory of source directories>"]
#     [BIN_PRT_DIR      "<parent directory of binary directories>"]
#     [EXCLUDE_FROM_ALL                                           ]
#   )
function(add_all_subdirectories)

  set(opts "EXCLUDE_FROM_ALL")
  set(ovks "SRC_PRT_DIR" "BIN_PRT_DIR")
  set(mvks)
  cmake_parse_arguments("ARG" "${opts}" "${ovks}" "${mvks}" ${ARGN})
  if(DEFINED ARG_UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments(${ARG_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  if(DEFINED ARG_SRC_PRT_DIR)
    set(path "${ARG_SRC_PRT_DIR}")
  else()
    set(path "${CMAKE_CURRENT_LIST_DIR}")
  endif()

  file(GLOB files LIST_DIRECTORIES TRUE RELATIVE "${path}" "${path}/*")

  foreach(file IN LISTS files)
    if(IS_DIRECTORY "${path}/${file}")

      if(DEFINED ARG_SRC_PRT_DIR)
        set(srcdir "${path}/${file}")
      else()
        set(srcdir "${file}")
      endif()

      if(DEFINED ARG_BIN_PRT_DIR)
        set(bindir "${parent_binary_dir}/${dir}")
      else()
        unset(bindir)
      endif()

      if(ARG_EXCLUDE_FROM_ALL)
        set(exclude_from_all "EXCLUDE_FROM_ALL")
      else()
        unset(exclude_from_all)
      endif()

      add_subdirectory("${srcdir}" ${bindir} ${exclude_from_all})

    endif()
  endforeach()

endfunction()

# .rst
# .. command:: add_subdirectory_with_option
#
#  提供选项，可选地将子目录添加到构建::
#
#   add_subdirectory_with_option(
#      SRC_DIR          "<source directory>"
#     [BIN_DIR          "<binary directory>"]
#     [EXCLUDE_FROM_ALL                     ]
#     [INITIAL_OPTION    <OFF|ON>           ]
#   )
function(add_subdirectory_with_option)

  set(opts "EXCLUDE_FROM_ALL")
  set(ovks "SRC_DIR" "BIN_DIR" "INITIAL_OPTION")
  set(mvks)
  cmake_parse_arguments("ARG" "${opts}" "${ovks}" "${mvks}" ${ARGN})
  if(DEFINED ARG_UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments(${ARG_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  if(NOT DEFINED ARG_SRC_DIR)
    message(SEND_ERROR "Missing SRC_DIR.")
    return()
  endif()
  check_name_with_cmake_recommend_variable_rules("${ARG_SRC_DIR}" conformed)
  if(NOT conformed)
    message(SEND_ERROR "Undesirable SRC_DIR(${ARG_SRC_DIR}).")
    return()
  endif()

  string(TOUPPER "${ARG_SRC_DIR}" optionname)

  if(DEFINED ARG_INITIAL_OPTION)
    set(initialoption "${ARG_INITIAL_OPTION}")
  else()
    set(initialoption OFF)
  endif()

  if(DEFINED ARG_BIN_DIR)
    set(bindir "${ARG_BIN_DIR}")
  else()
    unset(bindir)
  endif()

  if(ARG_EXCLUDE_FROM_ALL)
    set(exclude_from_all "EXCLUDE_FROM_ALL")
  else()
    unset(exclude_from_all)
  endif()

  option(${optionname} "Subdirectory ${ARG_SRC_DIR}." ${initialoption})
  if(${optionname})
    add_subdirectory("${ARG_SRC_DIR}" ${bindir} ${exclude_from_all})
  endif()

endfunction()

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
#  查找目录下所有指定文件并分组::
#
#   aux_source_directory_with_group(
#      SRC_DIR  "<source directory>"
#      SRC_EXTS "<source extensions>"...
#     [RECURSE                          ]
#      GRP_DIR  "<group directory>"
#      SRC_VAR   <source variable>
#   )
function(aux_source_directory_with_group)

  set(opts "RECURSE")
  set(ovks "SRC_DIR" "GRP_DIR" "SRC_VAR")
  set(mvks "SRC_EXTS")
  cmake_parse_arguments("ARG" "${opts}" "${ovks}" "${mvks}" ${ARGN})
  if(DEFINED ARG_UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments(${ARG_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  if(NOT DEFINED ARG_SRC_DIR)
    message(SEND_ERROR "Missing SRC_DIR.")
    return()
  endif()
  if(NOT IS_DIRECTORY "${ARG_SRC_DIR}")
    message(SEND_ERROR "Undesirable SRC_DIR(${ARG_SRC_DIR}).")
    return()
  endif()

  if(NOT DEFINED ARG_SRC_EXTS)
    message(SEND_ERROR "Missing SRC_EXTS.")
    return()
  endif()
  list(REMOVE_DUPLICATES ARG_SRC_EXTS)
  foreach(ext ${ARG_SRC_EXTS})
    check_name_with_file_extension_rules("${ext}" conformed)
    if(NOT conformed)
      message(SEND_ERROR "Undesirable extension(${ext}).")
      return()
    endif()
  endforeach()

  if(ARG_RECURSE)
    set(recurse "GLOB_RECURSE")
  else()
    set(recurse "GLOB")
  endif()

  # GRP_DIR

  if(NOT DEFINED ARG_SRC_VAR)
    message(SEND_ERROR "Missing SRC_VAR.")
    return()
  endif()
  check_name_with_cmake_recommend_variable_rules("${ARG_SRC_VAR}" conformed)
  if(NOT conformed)
    message(SEND_ERROR "Undesirable SRC_VAR(${ARG_SRC_VAR}).")
    return()
  endif()

  unset(srcfiles)
  foreach(ext ${ARG_SRC_EXTS})
    file(${recurse} files "${ARG_SRC_DIR}/*${ext}")
    foreach(file ${files})

      list(APPEND srcfiles "${file}")

      get_filename_component(filedir "${file}" DIRECTORY)
      string(REGEX REPLACE "^${ARG_SRC_DIR}" "" relpath "${filedir}")
      string(REPLACE "/" "\\\\" grpdir "${ARG_GRP_DIR}${relpath}")
      source_group("${grpdir}" FILES "${file}")

    endforeach()
  endforeach()

  set(${ARG_SRC_VAR} "${srcfiles}" PARENT_SCOPE)

endfunction()

# .rst
# .. command:: aux_source_directory_with_group_and_config
#
#  查找目录下所有指定文件、分组并配置::
#
#   aux_source_directory_with_group(
#      SRC_DIR  "<source directory>"
#      SRC_EXTS "<source extensions>"...
#     [RECURSE                          ]
#      GRP_DIR  "<group directory>"
#      GEN_DIR  "<generating directory>"
#      SRC_VAR   <source variable>
#   )
function(aux_source_directory_with_group_and_config)

  set(opts "RECURSE")
  set(ovks "SRC_DIR" "GRP_DIR" "GEN_DIR" "SRC_VAR")
  set(mvks "SRC_EXTS")
  cmake_parse_arguments("ARG" "${opts}" "${ovks}" "${mvks}" ${ARGN})
  if(DEFINED ARG_UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments(${ARG_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  if(NOT DEFINED ARG_SRC_DIR)
    message(SEND_ERROR "Missing SRC_DIR.")
    return()
  endif()
  if(NOT IS_DIRECTORY "${ARG_SRC_DIR}")
    message(SEND_ERROR "Undesirable SRC_DIR(${ARG_SRC_DIR}).")
    return()
  endif()

  if(NOT DEFINED ARG_SRC_EXTS)
    message(SEND_ERROR "Missing SRC_EXTS.")
    return()
  endif()
  list(REMOVE_DUPLICATES ARG_SRC_EXTS)
  foreach(ext ${ARG_SRC_EXTS})
    check_name_with_file_extension_rules("${ext}" conformed)
    if(NOT conformed)
      message(SEND_ERROR "Undesirable extension(${ext}).")
      return()
    endif()
  endforeach()

  if(ARG_RECURSE)
    set(recurse "GLOB_RECURSE")
  else()
    set(recurse "GLOB")
  endif()

  # GRP_DIR

  if(NOT DEFINED ARG_GEN_DIR)
    message(SEND_ERROR "Missing GEN_DIR.")
    return()
  endif()
  if(NOT IS_ABSOLUTE "${ARG_GEN_DIR}")
    message(SEND_ERROR "Undesirable GEN_DIR(${ARG_GEN_DIR}).")
    return()
  endif()

  if(NOT DEFINED ARG_SRC_VAR)
    message(SEND_ERROR "Missing SRC_VAR.")
    return()
  endif()
  check_name_with_cmake_recommend_variable_rules("${ARG_SRC_VAR}" conformed)
  if(NOT conformed)
    message(SEND_ERROR "Undesirable SRC_VAR(${ARG_SRC_VAR}).")
    return()
  endif()

  unset(srcfiles)
  foreach(ext ${ARG_SRC_EXTS})
    file(${recurse} files "${ARG_SRC_DIR}/*${ext}")
    foreach(file ${files})

      list(APPEND srcfiles "${file}")

      get_filename_component(filedir "${file}" DIRECTORY)
      string(REGEX REPLACE "^${ARG_SRC_DIR}" "" relpath "${filedir}")
      string(REPLACE "/" "\\\\" grpdir "${ARG_GRP_DIR}${relpath}")
      source_group("${grpdir}" FILES "${file}")

      get_filename_component(filename "${file}" NAME)
      string(REPLACE "." "[.]" extregex "${ext}")
      string(REGEX REPLACE "${extregex}$" "" genfilename "${filename}")
      set(genfile "${ARG_GEN_DIR}${relpath}/${genfilename}")
      configure_file("${file}" "${genfile}" @ONLY)

      list(APPEND srcfiles "${genfile}")

      source_group("${grpdir}" FILES "${genfile}")

    endforeach()
  endforeach()

  set(${ARG_SRC_VAR} "${srcfiles}" PARENT_SCOPE)

endfunction()

# .rst
# .. command:: aux_source_directory_with_install
#
#  查找目录下所有指定文件并安装::
#
#   aux_source_directory_with_install(
#      SRC_DIR  "<source directory>"
#      SRC_EXTS "<source extensions>"...
#     [RECURSE                          ]
#      INS_DIR  "<install directory>"
#   )
function(aux_source_directory_with_install)

  set(opts "RECURSE")
  set(ovks "SRC_DIR" "INS_DIR")
  set(mvks "SRC_EXTS")
  cmake_parse_arguments("ARG" "${opts}" "${ovks}" "${mvks}" ${ARGN})
  if(DEFINED ARG_UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments(${ARG_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  if(NOT DEFINED ARG_SRC_DIR)
    message(SEND_ERROR "Missing SRC_DIR.")
    return()
  endif()
  if(NOT IS_DIRECTORY "${ARG_SRC_DIR}")
    message(SEND_ERROR "Undesirable SRC_DIR(${ARG_SRC_DIR}).")
    return()
  endif()

  if(NOT DEFINED ARG_SRC_EXTS)
    message(SEND_ERROR "Missing SRC_EXTS.")
    return()
  endif()
  list(REMOVE_DUPLICATES ARG_SRC_EXTS)
  foreach(ext ${ARG_SRC_EXTS})
    check_name_with_file_extension_rules("${ext}" conformed)
    if(NOT conformed)
      message(SEND_ERROR "Undesirable extension(${ext}).")
      return()
    endif()
  endforeach()

  if(ARG_RECURSE)
    set(recurse "GLOB_RECURSE")
  else()
    set(recurse "GLOB")
  endif()

  if(NOT DEFINED ARG_INS_DIR)
    message(SEND_ERROR "Missing INS_DIR.")
    return()
  endif()
  if(NOT IS_ABSOLUTE "${ARG_INS_DIR}")
    message(SEND_ERROR "Undesirable INS_DIR(${ARG_INS_DIR}).")
    return()
  endif()

  foreach(ext ${ARG_SRC_EXTS})
    file(${recurse} files "${ARG_SRC_DIR}/*${ext}")
    foreach(file ${files})

      get_filename_component(filedir "${file}" DIRECTORY)
      string(REGEX REPLACE "^${ARG_SRC_DIR}" "" relpath "${filedir}")
      install(FILES "${file}" DESTINATION "${ARG_INS_DIR}${relpath}")

    endforeach()
  endforeach()

endfunction()

# .rst
# .. command:: quick_aux_source_directory
#
#  简便查找、分组、配置、安装源文件::
#
#   quick_aux_source_directory(
#     [SRC_DIR  "<source directory>"                  ]
#     [SRC_EXTS "<source extensions>"...              ]
#     [RECURSE                                        ]
#     [GRP_DIR   <group directory>                    ]
#     [CONFIGURE                                      ]
#     [CFG_EXTS "<source and configure extensions>"...]
#     [GEN_DIR   <generate directory>                 ]
#     [INSTALL                                        ]
#     [INS_EXTS "<install extensions>"...             ]
#     [INS_DIR   <install directory>                  ]
#      SRC_VAR <source variable>
#     [C] [CXX] [QT]
#   )
function(quick_aux_source_directory)

  set(opts "RECURSE" "CONFIGURE" "INSTALL" "C" "CXX" "QT")
  set(ovks "SRC_DIR" "GRP_DIR" "GEN_DIR" "INS_DIR" "SRC_VAR")
  set(mvks "SRC_EXTS" "CFG_EXTS" "INS_EXTS")
  cmake_parse_arguments("ARG" "${opts}" "${ovks}" "${mvks}" ${ARGN})
  if(DEFINED ARG_UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments(${ARG_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  set(prjsrcdir "${PROJECT_SOURCE_DIR}")
  set(cursrcdir "${CMAKE_CURRENT_LIST_DIR}")
  string(REGEX REPLACE "^${prjsrcdir}" "" relpath "${cursrcdir}")
  set(prjbindir "${PROJECT_BINARY_DIR}")
  set(curbindir "${prjbindir}${relpath}")
  string(TOLOWER "${PROJECT_NAME}" prjlower)
  set(prjinsdir "${CMAKE_INSTALL_PREFIX}")
  set(curinsdir "${prjinsdir}/include/${prjlower}")

  if(NOT DEFINED ARG_SRC_DIR)
    set(srcdir "${cursrcdir}")
  elseif(NOT IS_DIRECTORY "${ARG_SRC_DIR}")
    set(srcdir "${cursrcdir}/${ARG_SRC_DIR}")
  else()
    set(srcdir "${ARG_SRC_DIR}")
  endif()
  if(NOT IS_DIRECTORY "${srcdir}")
    message(SEND_ERROR "Undesirable SRC_DIR(${ARG_SRC_DIR}).")
    return()
  endif()

  set(srcexts "${ARG_FND_EXTS}")
  if(ARG_C)
    list(APPEND srcexts ".h" ".c")
  endif()
  if(ARG_CXX)
    list(APPEND srcexts ".H" ".hh" ".hpp" ".hxx" ".inl" ".C" ".cc" ".cpp" ".cxx")
  endif()
  if(ARG_QT)
    list(APPEND srcexts ".ui" ".qml" ".qrc" ".ts")
  endif()
  list(REMOVE_DUPLICATES srcexts)
  foreach(ext ${srcexts})
    check_name_with_file_extension_rules("${ext}" conformed)
    if(NOT conformed)
      message(SEND_ERROR "Undesirable extension(${ext}).")
      return()
    endif()
  endforeach()

  if(ARG_RECURSE)
    set(recurse "RECURSE")
  else()
    unset(recurse)
  endif()

  if(DEFINED ARG_GRP_DIR)
    set(grpdir "${ARG_GRP_DIR}")
  else()
    set(grpdir "${relpath}")
  endif()

  if(DEFINED ARG_CFG_EXTS)
    set(cfgexts ${ARG_CFG_EXTS})
  else()
    set(cfgexts ".in")
  endif()
  foreach(ext ${cfgexts})
    check_name_with_file_extension_rules("${ext}" conformed)
    if(NOT conformed)
      message(SEND_ERROR "Undesirable extension(${ext}).")
      return()
    endif()
  endforeach()

  if(NOT DEFINED ARG_GEN_DIR)
    set(gendir "${curbindir}")
  elseif(NOT IS_ABSOLUTE "${ARG_GEN_DIR}")
    set(gendir "${curbindir}/${ARG_GEN_DIR}")
  else()
    set(gendir "${ARG_GEN_DIR}")
  endif()
  if(NOT IS_ABSOLUTE "${gendir}")
    message(SEND_ERROR "Undesirable GEN_DIR(${ARG_GEN_DIR}).")
    return()
  endif()

  set(insexts ${ARG_INS_EXTS})
  if(ARG_C)
    list(APPEND insexts ".h")
  endif()
  if(ARG_CXX)
    list(APPEND insexts ".H" ".hh" ".hpp" ".hxx" ".inl")
  endif()
  foreach(ext ${insexts})
    check_name_with_file_extension_rules("${ext}" conformed)
    if(NOT conformed)
      message(SEND_ERROR "Undesirable extension(${ext}).")
      return()
    endif()
  endforeach()

  if(NOT DEFINED ARG_INS_DIR)
    set(insdir "${curinsdir}")
  elseif(NOT IS_ABSOLUTE "${ARG_INS_DIR}")
    set(insdir "${curinsdir}/${ARG_INS_DIR}")
  else()
    set(insdir "${ARG_INS_DIR}")
  endif()
  if(NOT IS_ABSOLUTE "${insdir}")
    message(SEND_ERROR "Undesirable INS_DIR(${ARG_INS_DIR}).")
    return()
  endif()

  if(NOT DEFINED ARG_SRC_VAR)
    message(SEND_ERROR "Missing SRC_VAR.")
    return()
  endif()
  check_name_with_cmake_recommend_variable_rules("${ARG_SRC_VAR}" conformed)
  if(NOT conformed)
    message(SEND_ERROR "Undesirable SRC_VAR(${ARG_SRC_VAR}).")
    return()
  endif()

  aux_source_directory_with_group(
    SRC_DIR    "${srcdir}"
    SRC_EXTS    ${srcexts}
    ${recurse}
    GRP_DIR    "${grpdir}"
    SRC_VAR    srcfiles1
  )

  if(ARG_CONFIGURE)
    aux_source_directory_with_group_and_config(
      SRC_DIR    "${srcdir}"
      SRC_EXTS    ${cfgexts}
      ${recurse}
      GRP_DIR    "${grpdir}"
      GEN_DIR    "${gendir}"
      SRC_VAR     srcfiles2
    )
  endif()

  if(ARG_INSTALL)
    aux_source_directory_with_install(
      SRC_DIR    "${srcdir}"
      SRC_EXTS    ${insexts}
      ${recurse}
      INS_DIR    "${insdir}"
    )
  endif()

  if(ARG_INSTALL AND ARG_CONFIGURE)
    aux_source_directory_with_install(
      SRC_DIR    "${gendir}"
      SRC_EXTS    ${insexts}
      ${recurse}
      INS_DIR    "${insdir}"
    )
  endif()

  set(${ARG_SRC_VAR} "${srcfiles1}" "${srcfiles2}" PARENT_SCOPE)

endfunction()

#            _     _                _                  _                       _
#   __ _  __| | __| | ___ _   _ ___| |_ ___  _ __ ___ | |_ __ _ _ __ __ _  ___| |_
#  / _` |/ _` |/ _` |/ __| | | / __| __/ _ \| '_ ` _ \| __/ _` | '__/ _` |/ _ | __|
# | (_| | (_| | (_| | (__| |_| \__ | || (_) | | | | | | || (_| | | | (_| |  __| |_
#  \__,_|\__,_|\__,_|\___|\__,_|___/\__\___/|_| |_| |_|\__\__,_|_|  \__, |\___|\__|
#                                                                   |___/
#                                                       add_custom_target by FIGlet

# .rst
# .. command:: quick_add_executable_with_option
#
#  简便生成可执行文件::
#
#   quick_add_executable_with_option(
#      SRC_VAR  <source variable>
#     [CSTD     <90|99|11>       ]
#     [CXXSTD   <98|11|14|17>    ]
#   )
function(quick_add_executable_with_option)

  set(opts)
  set(ovks "SRC_VAR" "CSTD" "CXXSTD")
  set(mvks)
  cmake_parse_arguments("ARG" "${opts}" "${ovks}" "${mvks}" ${ARGN})
  if(DEFINED ARG_UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments(${ARG_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  if(NOT DEFINED ARG_SRC_VAR)
    message(SEND_ERROR "Missing SRC_VAR.")
    return()
  endif()

  if(DEFINED ARG_CSTD)
    set(cstd "C_STANDARD ${ARG_CSTD} C_STANDARD_REQUIRED ON")
  else()
    unset(cstd)
  endif()

  if(DEFINED ARG_CXXSTD)
    set(cxxstd "CXX_STANDARD ${ARG_CXXSTD} CXX_STANDARD_REQUIRED ON")
  else()
    unset(cxxstd)
  endif()

  string(TOUPPER "${PROJECT_NAME}" upper)
  string(TOLOWER "${PROJECT_NAME}" lower)

  option(${upper}_COMPILE_EXE "Build executable file." ON)
  if(${upper}_COMPILE_EXE)
    add_executable(${lower}_exe ${${ARG_SRC_VAR}})
    set_target_properties(${lower}_exe PROPERTIES
      cstd
      cxxstd
      OUTPUT_NAME "${PROJECT_NAME}" CLEAN_DIRECT_OUTPUT ON)
    install(TARGETS ${lower}_exe DESTINATION "bin")
  endif()

endfunction()

# .rst
# .. command:: quick_add_library_with_option
#
#  简便生成库::
#
#   quick_add_library_with_option(
#      SRC_VAR  <source variable>
#     [TYPE     <STATIC|SHARED|MODULE>]
#     [CSTD     <90|99|11>            ]
#     [CXXSTD   <98|11|14|17>         ]
#   )
function(quick_add_library_with_option)

  set(opts)
  set(ovks "SRC_VAR" "TYPE" "CSTD" "CXXSTD")
  set(mvks)
  cmake_parse_arguments("ARG" "${opts}" "${ovks}" "${mvks}" ${ARGN})
  if(DEFINED ARG_UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments(${ARG_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  if(NOT DEFINED ARG_SRC_VAR)
    message(SEND_ERROR "Missing SRC_VAR.")
    return()
  endif()

  if(NOT DEFINED ARG_TYPE)
    set(typetext "library")
    set(typeupper "LIBRARY")
    set(typelower "library")
  elseif("${ARG_TYPE}" STREQUAL "STATIC")
    set(typetext "static library")
    set(typeupper "STATIC")
    set(typelower "static")
  elseif("${ARG_TYPE}" STREQUAL "SHARED")
    set(typetext "shared library")
    set(typeupper "SHARED")
    set(typelower "shared")
  elseif("${ARG_TYPE}" STREQUAL "MODULE")
    set(typetext "module library")
    set(typeupper "MODULE")
    set(typelower "module")
  else()
    message(SEND_ERROR "Undesirable TYPE(${ARG_TYPE}).")
    return()
  endif()

  if(DEFINED ARG_CSTD)
    set(cstd "C_STANDARD ${ARG_CSTD} C_STANDARD_REQUIRED ON")
  else()
    unset(cstd)
  endif()

  if(DEFINED ARG_CXXSTD)
    set(cxxstd "CXX_STANDARD ${ARG_CXXSTD} CXX_STANDARD_REQUIRED ON")
  else()
    unset(cxxstd)
  endif()

  string(TOUPPER "${PROJECT_NAME}" nameupper)
  string(TOLOWER "${PROJECT_NAME}" namelower)

  option(${nameupper}_COMPILE_${typeupper} "Build ${typetext}." ON)
  if(${nameupper}_COMPILE_${typeupper})
    add_library(${namelower}_${typelower} ${ARG_TYPE} ${${ARG_SRC_VAR}})
    set_target_properties(${namelower}_${typelower} PROPERTIES
      cstd
      cxxstd
      OUTPUT_NAME "${PROJECT_NAME}" CLEAN_DIRECT_OUTPUT ON)
    install(TARGETS ${namelower}_${typelower} DESTINATION "lib")
  endif()

endfunction()

# .rst
# .. command:: quick_add_doxygen_with_option
#
#  简便生成Ｄｏｘｙｇｅｎ文档::
#
#   quick_add_doxygen_with_option(
#     [SPECIAL <API|DEV>]
#   )
function(quick_add_doxygen_with_option)

  set(opts)
  set(ovks "SPECIAL")
  set(mvks)
  cmake_parse_arguments("ARG" "${opts}" "${ovks}" "${mvks}" ${ARGN})
  if(DEFINED ARG_UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments(${ARG_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  if(NOT DEFINED ARG_SPECIAL)
    set(text "documentation")
    set(upper "DOC")
    set(lower "doc")
  elseif("${ARG_SPECIAL}" STREQUAL "API")
    set(text "API documentation")
    set(upper "API_DOC")
    set(lower "api_doc")
  elseif("${ARG_SPECIAL}" STREQUAL "DEV")
    set(text "developing documentation")
    set(upper "DEV_DOC")
    set(lower "dev_doc")
  else()
    message(SEND_ERROR "Undesirable SPECIAL(${ARG_SPECIAL}).")
    return()
  endif()

  find_package(Doxygen)
  option(${PROJECT_NAME_UPPER}_GEN_${upper} "Generate ${text} (requires Doxygen)." ${DOXYGEN_FOUND})
  if(${PROJECT_NAME_UPPER}_GEN_${upper})
    if(NOT DOXYGEN_FOUND)
      message(SEND_ERROR "Doxygen is needed to generate the ${text}.")
      return()
    endif()

    set(doxyfile_in "${PROJECT_SOURCE_DIR}/doxygen/Doxyfile.in")
    set(doxyfile    "${PROJECT_BINARY_DIR}/doxygen/Doxyfile")
    configure_file(${doxyfile_in} ${doxyfile} @ONLY)

    file(GLOB srcfiles "*.h" "*.hpp")
    list(APPEND srcfiles ${doxyfile_in})
    source_group("" FILES ${srcfiles})

    add_custom_target(${PROJECT_NAME_LOWER}_${lower}
      COMMAND "${DOXYGEN_EXECUTABLE}" "${doxyfile}"
      WORKING_DIRECTORY "${PROJECT_BINARY_DIR}"
      COMMENT "Generating ${text} with Doxygen."
      VERBATIM
      SOURCES ${srcfiles})
    install(DIRECTORY "${PROJECT_BINARY_DIR}/doxygen/docs/" DESTINATION "docs")
  endif()

endfunction()
