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

  if(NOT DEFINED ARG_SRC_PRT_DIR)
    set(path "${CMAKE_CURRENT_LIST_DIR}")
  else()
    set(path "${ARG_SRC_PRT_DIR}")
  endif()

  file(GLOB files LIST_DIRECTORIES TRUE RELATIVE "${path}" "${path}/*")

  foreach(file IN LISTS files)
    if(IS_DIRECTORY "${path}/${file}")

      if(NOT DEFINED ARG_SRC_PRT_DIR)
        set(srcdir "${file}")
      else()
        set(srcdir "${path}/${file}")
      endif()

      if(NOT DEFINED ARG_BIN_PRT_DIR)
        unset(bindir)
      else()
        set(bindir "${parent_binary_dir}/${dir}")
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

  if(NOT DEFINED ARG_INITIAL_OPTION)
    set(initialoption OFF)
  else()
    set(initialoption "${ARG_INITIAL_OPTION}")
  endif()

  if(NOT DEFINED ARG_BIN_DIR)
    unset(bindir)
  else()
    set(bindir "${ARG_BIN_DIR}")
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
  set(opts "RECURSE" "CONFIGURE" "INSTALL" "C" "CPP" "QT")
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
  if(ARG_CPP)
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

  if(NOT DEFINED ARG_GRP_DIR)
    set(grpdir "${relpath}")
  else()
    set(grpdir "${ARG_GRP_DIR}")
  endif()

  if(NOT DEFINED ARG_CFG_EXTS)
    set(cfgexts ".in")
  else()
    set(cfgexts ${ARG_CFG_EXTS})
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
  if(ARG_CPP)
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
