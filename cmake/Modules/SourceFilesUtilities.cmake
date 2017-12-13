# zhengrr
# 2016-10-8 – 2017-12-13
# The MIT License

#.rst:
# SourceFilesUtilities
# --------------------
#
# 此模块提供了若指令，用于简化源文件的处理。
#
# 须 CMake 3.3 及以上版本。

cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
cmake_policy(SET CMP0057 NEW)  # CMake 3.3+

#.rst:
# .. command:: find_source_files
#
#  此指令在 SRC_DIR，查找符合 SRC_EXTS 的所有文件，将结果存储到 SRC_VAR 并纳入 GRP_DIR::
#
#   find_source_files(
#     [RECURSE]
#     SRC_VAR <source variable>
#     SRC_DIR <source directory>
#     GRP_DIR <group directory>
#     SRC_EXTS <source extensions>...
#   )
#
#  此指令接受下述参数::
#
#   RECURSE                          递归查找；
#   SRC_VAR <source variable>        源文件变量；
#   SRC_DIR <source directory>       源文件目录，绝对路径；
#   GRP_DIR <group directory>        分组目录；
#   SRC_EXTS <source extensions>...  源文件后缀名。
function(find_source_files)
  set(options "RECURSE")
  set(one_value_keywords "SRC_VAR" "SRC_DIR" "GRP_DIR")
  set(multi_value_keywords "SRC_EXTS")
  cmake_parse_arguments("ARG" "${options}" "${one_value_keywords}" "${multi_value_keywords}" ${ARGN})
  if(ARG_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "Unexpected arguments '${ARG_UNPARSED_ARGUMENTS}'.")
  endif()

  if(ARG_RECURSE)
    set(file_manipulation_command "GLOB_RECURSE")
  else()
    set(file_manipulation_command "GLOB")
  endif()

  if((NOT ARG_SRC_VAR) OR (NOT ARG_SRC_VAR MATCHES "^[0-9A-Za-z_-]+$"))
    message(FATAL_ERROR "The argument SRC_VAR is null or invalid, "
        "it's '${ARG_SRC_VAR}'.")
  endif()

  if((NOT ARG_SRC_DIR) OR (NOT IS_DIRECTORY "${ARG_SRC_DIR}"))
    message(FATAL_ERROR "The argument SRC_DIR is null or invalid, "
        "it's '${ARG_SRC_DIR}'.")
  endif()

  if((NOT ARG_GRP_DIR) OR (NOT ARG_GRP_DIR MATCHES "^[ 0-9A-Z\\a-z/_-]+$"))
    message(FATAL_ERROR "The argument GRP_DIR is null or invalid, "
        "it's '${ARG_GRP_DIR}'.")
  endif()

  if(NOT ARG_SRC_EXTS)
    message(FATAL_ERROR "The argument SRC_EXTS is null.")
  endif()
  foreach(extension ${ARG_SRC_EXTS})
    if(NOT extension MATCHES "^([.][^ \"%*./:<>?\\|]+)+$")
      message(FATAL_ERROR "A argument in SRC_EXTS is invalid, "
          "it's '${extension}' in '${ARG_SRC_EXTS}'.")
    endif()
  endforeach()

  unset(source_files)
  unset(done_list)
  foreach(extension ${ARG_SRC_EXTS})
    if(NOT extension IN_LIST done_list)
      file(${file_manipulation_command} files "${ARG_SRC_DIR}/*${extension}")
      foreach(file ${files})
        if(NOT file IN_LIST source_files)
          get_filename_component(file_directory "${file}" DIRECTORY)
          string(REGEX REPLACE "^${ARG_SRC_DIR}" "" relative_directory "${file_directory}")
          string(REPLACE "/" "\\\\" group_directory "${ARG_GRP_DIR}${relative_directory}")
          list(APPEND source_files "${file}")
          source_group("${group_directory}" FILES "${file}")
        endif()
      endforeach()
      list(APPEND done_list "${extension}")
    endif()
  endforeach()

  set(${ARG_SRC_VAR} ${source_files} PARENT_SCOPE)
endfunction()

#.rst:
# .. command:: find_and_configure_source_files
#
#  此指令在 SRC_DIR，查找符合 SRC_EXTS 的所有文件，将结果存储到 SRC_VAR 并纳入 GRP_DIR；
#  并将查找到的文件进行配置处理到 GEN_DIR，将处理后的文件也存储到 SRC_VAR 并纳入 GRP_DIR::
#
#   find_and_configure_source_files(
#     [RECURSE]
#     SRC_VAR <source variable>
#     SRC_DIR <source directory>
#     GRP_DIR <group directory>
#     GEN_DIR <generate directory>
#     SRC_EXTS <source extensions>...
#   )
#
#  此指令接受下述参数::
#
#   RECURSE                          递归查找；
#   SRC_VAR <source variable>        源文件变量；
#   SRC_DIR <source directory>       源文件目录，绝对路径；
#   GRP_DIR <group directory>        分组目录；
#   GEN_DIR <generate directory>     生成目录；
#   SRC_EXTS <source extensions>...  源文件后缀名。
function(find_and_configure_source_files)
  set(options "RECURSE")
  set(one_value_keywords "SRC_VAR" "SRC_DIR" "GRP_DIR" "GEN_DIR")
  set(multi_value_keywords "SRC_EXTS")
  cmake_parse_arguments("ARG" "${options}" "${one_value_keywords}" "${multi_value_keywords}" ${ARGN})
  if(ARG_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "Unexpected arguments '${ARG_UNPARSED_ARGUMENTS}'.")
  endif()

  if(ARG_RECURSE)
    set(file_manipulation_command "GLOB_RECURSE")
  else()
    set(file_manipulation_command "GLOB")
  endif()

  if((NOT ARG_SRC_VAR) OR (NOT ARG_SRC_VAR MATCHES "^[0-9A-Za-z_-]+$"))
    message(FATAL_ERROR "The argument SRC_VAR is null or invalid, "
        "it's '${ARG_SRC_VAR}'.")
  endif()

  if((NOT ARG_SRC_DIR) OR (NOT IS_DIRECTORY "${ARG_SRC_DIR}"))
    message(FATAL_ERROR "The argument SRC_DIR is null or invalid, "
        "it's '${ARG_SRC_DIR}'.")
  endif()

  if((NOT ARG_GRP_DIR) OR (NOT ARG_GRP_DIR MATCHES "^[ 0-9A-Z\\a-z/_-]+$"))
    message(FATAL_ERROR "The argument GRP_DIR is null or invalid, "
        "it's '${ARG_GRP_DIR}'.")
  endif()

  if((NOT ARG_GEN_DIR) OR (NOT IS_ABSOLUTE "${ARG_GEN_DIR}"))
    message(FATAL_ERROR "The argument GEN_DIR is null or invalid, "
        "it's '${ARG_GEN_DIR}'.")
  endif()

  if(NOT ARG_SRC_EXTS)
    message(FATAL_ERROR "The argument SRC_EXTS is null.")
  endif()
  foreach(extension ${ARG_SRC_EXTS})
    if(NOT extension MATCHES "^([.][^ \"%*./:<>?\\|]+)+$")
      message(FATAL_ERROR "A argument in SRC_EXTS is invalid, "
          "it's '${extension}' in '${ARG_SRC_EXTS}'.")
    endif()
  endforeach()

  unset(source_files)
  unset(done_list)
  foreach(extension ${ARG_SRC_EXTS})
    if(NOT extension IN_LIST done_list)
      file(${file_manipulation_command} files "${ARG_SRC_DIR}/*${extension}")
      foreach(file ${files})
        if(NOT file IN_LIST source_files)
          get_filename_component(file_directory "${file}" DIRECTORY)
          string(REGEX REPLACE "^${ARG_SRC_DIR}" "" relative_directory "${file_directory}")
          string(REPLACE "/" "\\\\" group_directory "${ARG_GRP_DIR}${relative_directory}")
          get_filename_component(file_name "${file}" NAME)
          string(REPLACE "." "\\." regex "${extension}")
          string(REGEX REPLACE "${regex}$" "" generated_name "${file_name}")
          set(generated "${ARG_GEN_DIR}${relative_directory}/${generated_name}")
          list(APPEND source_files "${file}")
          source_group("${group_directory}" FILES "${file}")
          configure_file("${file}" "${generated}" @ONLY)
          list(APPEND source_files "${generated}")
          source_group("${group_directory}" FILES "${generated}")
        endif()
      endforeach()
      list(APPEND done_list "${extension}")
    endif()
  endforeach()

  set(${ARG_SRC_VAR} ${source_files} PARENT_SCOPE)
endfunction()

#.rst:
# .. command:: install_source_files
#
#  此指令在 SRC_DIR，查找符合 SRC_EXTS 的所有文件，将其复制到 INS_DIR。
#
#   install_source_files(
#     [RECURSE]
#     SRC_DIR <source directory>
#     INS_DIR <install directory>
#     SRC_EXTS <source extensions>...
#   )
#
#  此指令接受下述参数::
#
#   RECURSE                          递归查找；
#   SRC_DIR <source directory>       源文件目录，采用绝对路径；
#   INS_DIR <install directory>      安装目录；
#   SRC_EXTS <source extensions>...  源文件后缀名。
function(install_source_files)
  set(options "RECURSE")
  set(one_value_keywords "SRC_DIR" "INS_DIR")
  set(multi_value_keywords "SRC_EXTS")
  cmake_parse_arguments("ARG" "${options}" "${one_value_keywords}" "${multi_value_keywords}" ${ARGN})
  if(ARG_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "Unexpected arguments '${ARG_UNPARSED_ARGUMENTS}'.")
  endif()

  if(ARG_RECURSE)
    set(file_manipulation_command "GLOB_RECURSE")
  else()
    set(file_manipulation_command "GLOB")
  endif()

  if((NOT ARG_SRC_DIR) OR (NOT IS_DIRECTORY "${ARG_SRC_DIR}"))
    message(FATAL_ERROR "The argument SRC_DIR is null or invalid, "
        "it's '${ARG_SRC_DIR}'.")
  endif()

  if((NOT ARG_INS_DIR) OR (NOT IS_ABSOLUTE "${ARG_INS_DIR}"))
    message(FATAL_ERROR "The argument INS_DIR is null or invalid, "
        "it's '${ARG_INS_DIR}'.")
  endif()

  if(NOT ARG_SRC_EXTS)
    message(FATAL_ERROR "The argument SRC_EXTS is null.")
  endif()
  foreach(extension ${ARG_SRC_EXTS})
    if(NOT extension MATCHES "^([.][^ \"%*./:<>?\\|]+)+$")
      message(FATAL_ERROR "A argument in SRC_EXTS is invalid, "
          "it's '${extension}' in '${ARG_SRC_EXTS}'.")
    endif()
  endforeach()

  unset(done_list)
  foreach(extension ${ARG_SRC_EXTS})
    if(NOT extension IN_LIST done_list)
      file(${file_manipulation_command} files "${ARG_SRC_DIR}/*${extension}")
      foreach(file ${files})
        get_filename_component(file_directory "${file}" DIRECTORY)
        string(REGEX REPLACE "^${ARG_SRC_DIR}" "" relative_directory "${file_directory}")
        install(FILES "${file}" DESTINATION "${ARG_INS_DIR}${relative_directory}")
      endforeach()
      list(APPEND done_list "${extension}")
    endif()
  endforeach()
endfunction()

#.rst:
# .. command:: source_files_helper
#
#  结合 ``find_source_files``、``find_and_configure_source_files`` 和 ``install_source_files`` 指令；
#  并提供常用默认值以简化指令::
#
#   source_files_helper(
#     [RECURSE] [CONFIGURE] [INSTALL]
#     [C] [CPP] [QT]
#     SRC_VAR <source variable>
#     [SRC_DIR <source directory>]
#     [GRP_DIR <group directory>]
#     [GEN_DIR <generate directory>]
#     [INS_DIR <install directory>]
#     [FND_EXTS <find extensions>...]
#     [CFG_EXTS <find and configure extensions>...]
#     [INS_EXTS <install extensions>...]
#   )
function(source_files_helper)
  set(options "RECURSE" "CONFIGURE" "INSTALL" "C" "CPP" "QT")
  set(one_value_keywords "SRC_VAR" "SRC_DIR" "GRP_DIR" "GEN_DIR" "INS_DIR")
  set(multi_value_keywords "FND_EXTS" "CFG_EXTS" "INS_EXTS")
  cmake_parse_arguments("ARG" "${options}" "${one_value_keywords}" "${multi_value_keywords}" ${ARGN})
  if(ARG_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "Unexpected arguments '${ARG_UNPARSED_ARGUMENTS}'.")
  endif()

  set(project_source_directory "${PROJECT_SOURCE_DIR}")
  set(current_source_directory "${CMAKE_CURRENT_LIST_DIR}")
  string(REGEX REPLACE "^${project_source_directory}" "" relative_directory "${current_source_directory}")
  set(project_binary_directory "${PROJECT_BINARY_DIR}")
  set(current_binary_directory "${project_binary_directory}${relative_directory}")
  string(TOLOWER "${PROJECT_NAME}" project_name_lower)
  set(project_install_directory "${CMAKE_INSTALL_PREFIX}")
  set(current_install_directory "${project_install_directory}/include/${project_name_lower}")

  if(ARG_RECURSE)
    set(recurse_option "RECURSE")
  else()
    set(recurse_option "")
  endif()

  if((NOT ARG_SRC_VAR) OR (NOT ARG_SRC_VAR MATCHES "^[0-9A-Za-z_-]+$"))
    message(FATAL_ERROR "The argument SRC_VAR is null or invalid, "
        "it's '${ARG_SRC_VAR}'.")
  endif()

  if(NOT ARG_SRC_DIR)
    set(source_directory "${current_source_directory}")
  elseif(NOT IS_DIRECTORY "${ARG_SRC_DIR}")
    set(source_directory "${current_source_directory}/${ARG_SRC_DIR}")
  else()
    set(source_directory "${ARG_SRC_DIR}")
  endif()
  if(NOT IS_DIRECTORY "${source_directory}")
    message(FATAL_ERROR "The argument SRC_DIR is invalid, "
        "it's '${ARG_SRC_DIR}'.")
  endif()

  if(NOT ARG_GRP_DIR)
    string(REPLACE "/" "\\\\\\\\" group_directory "${relative_directory}")
  else()
    set(group_directory "${ARG_GRP_DIR}")
  endif()
  if(NOT group_directory MATCHES "^[ 0-9A-Z\\a-z/_-]+$")
    message(FATAL_ERROR "The argument GRP_DIR is invalid, "
        "it's '${ARG_GRP_DIR}'.")
  endif()

  if(NOT ARG_GEN_DIR)
    set(generate_directory "${current_binary_directory}")
  elseif(NOT IS_ABSOLUTE "${ARG_GENDIR}")
    set(generate_directory "${current_binary_directory}/${ARG_GEN_DIR}")
  else()
    set(generate_directory "${ARG_GEN_DIR}")
  endif()
  if(NOT IS_ABSOLUTE "${generate_directory}")
    message(FATAL_ERROR "The argument GEN_DIR is invalid, "
        "it's '${ARG_GEN_DIR}'.")
  endif()

  if(NOT ARG_INS_DIR)
    set(install_directory "${current_install_directory}")
  elseif(NOT IS_ABSOLUTE "${ARG_INS_DIR}")
    set(install_directory "${current_install_directory}/${ARG_INS_DIR}")
  else()
    set(install_directory "${ARG_INS_DIR}")
  endif()
  if(NOT IS_ABSOLUTE "${install_directory}")
    message(FATAL_ERROR "The argument INS_DIR is invalid, "
        "it's '${ARG_INS_DIR}'.")
  endif()

  unset(find_extensions)
  set(find_extensions ${ARG_FND_EXTS})
  if(ARG_C)
    list(APPEND find_extensions ".h" ".c")
  endif()
  if(ARG_CPP)
    list(APPEND find_extensions ".H" ".h++" ".hh" ".hpp" ".hxx" ".inl" ".C" ".c++" ".cc" ".cpp" ".cxx")
  endif()
  if(ARG_QT)
    list(APPEND find_extensions ".ui" ".qml" ".qrc" ".ts")
  endif()
  foreach(extension ${find_extensions})
    if(NOT extension MATCHES "^([.][^ \"%*./:<>?\\|]+)+$")
      message(FATAL_ERROR "A argument in FND_EXTS is invalid, "
          "it's '${extension}' in '${ARG_FND_EXTS}'.")
    endif()
  endforeach()

  unset(configure_extensions)
  if(NOT ARG_CFG_EXTS)
    set(configure_extensions ".in")
  else()
    set(configure_extensions ${ARG_CFG_EXTS})
  endif()
  foreach(extension ${configure_extensions})
    if(NOT extension MATCHES "^([.][^ \"%*./:<>?\\|]+)+$")
      message(FATAL_ERROR "A argument in CFG_EXTS is invalid, "
          "it's '${extension}' in '${ARG_CFG_EXTS}'.")
    endif()
  endforeach()

  unset(install_extensions)
  set(install_extensions ${ARG_INS_EXTS})
  if(ARG_C)
    list(APPEND install_extensions ".h")
  endif()
  if(ARG_CPP)
    list(APPEND install_extensions ".H" ".h++" ".hh" ".hpp" ".hxx" ".inl")
  endif()
  foreach(extension ${install_extensions})
    if(NOT extension MATCHES "^([.][^ \"%*./:<>?\\|]+)+$")
      message(FATAL_ERROR "A argument in INS_EXTS is invalid, "
          "it's '${extension}' in '${ARG_INS_EXTS}'.")
    endif()
  endforeach()

  find_source_files(${recurse_option}
      SRC_VAR source_files_half
      SRC_DIR ${source_directory}
      GRP_DIR ${group_directory}
      SRC_EXTS ${find_extensions})

  if(ARG_CONFIGURE)
    find_and_configure_source_files(${recurse_option}
        SRC_VAR source_files_other_half
        SRC_DIR ${source_directory}
        GRP_DIR ${group_directory}
        GEN_DIR ${generate_directory}
        SRC_EXTS ${configure_extensions})
  endif()

  if(ARG_INSTALL)
    install_source_files(${recurse_option}
        SRC_DIR ${source_directory}
        INS_DIR ${install_directory}
        SRC_EXTS ${install_extensions})
  endif()

  if(ARG_CONFIGURE AND ARG_INSTALL)
    install_source_files(${recurse_option}
        SRC_DIR ${generate_directory}
        INS_DIR ${install_directory}
        SRC_EXTS ${install_extensions})
  endif()

  set(${ARG_SRC_VAR} ${source_files_half} ${source_files_other_half} PARENT_SCOPE)
endfunction()
