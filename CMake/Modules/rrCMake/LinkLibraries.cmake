# zhengrr
# 2019-04-15 – 2019-04-17
# Unlicense

cmake_minimum_required(VERSION 3.10)
cmake_policy(VERSION 3.10)

include_guard()

#.rst:
# .. command:: get_link_libraries
#
#   获取链接库（get link libraries）。
#
#   .. code-block:: cmake
#
#     get_link_libraries(
#       <variable> <target> [RECURSE]
#     )
function(get_link_libraries _VARIABLE _TARGET)
  set(zOptKws RECURSE)
  cmake_parse_arguments(PARSE_ARGV 2 "" "${zOptKws}" "" "")
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "Unexpected arguments: ${_UNPARSED_ARGUMENTS}.")
  endif()

  if(_RECURSE)
    get_target_property(zNonItems ${_TARGET} LINK_LIBRARIES)  # non-recursive
    set(zRecItems)                                            # recursive
    while(zNonItems)
      foreach(sNonItem IN ITEMS ${zNonItems})
        if(TARGET ${sNonItem})
          get_target_property(sType ${sNonItem} TYPE)
          if(sType STREQUAL "INTERFACE_LIBRARY")
            get_target_property(zTmpItems ${sNonItem} INTERFACE_LINK_LIBRARIES)
            list(APPEND zNonItems ${zTmpItems})
          else()
            get_target_property(zTmpItems ${sNonItem} LINK_LIBRARIES)
            list(APPEND zNonItems ${zTmpItems})
          endif()
        endif()
        list(APPEND zRecItems ${sNonItem})
      endforeach()
      list(REMOVE_DUPLICATES zNonItems)
      list(REMOVE_DUPLICATES zRecItems)
      list(REMOVE_ITEM zNonItems ${zRecItems})
    endwhile()
    set(${_VARIABLE} ${zRecItems} PARENT_SCOPE)
  else()
    get_target_property(zTmpItems ${_TARGET} LINK_LIBRARIES)
    set(${_VARIABLE} ${zTmpItems} PARENT_SCOPE)
  endif()
endfunction()

#.rst:
# .. command:: post_build_copy_link_libraries
#
#   构建后复制链接库（post build copy link libraries）。
#
#   .. code-block:: cmake
#
#     post_build_copy_link_libraries(
#       <target> [RECURSE]
#     )
function(post_build_copy_link_libraries _TARGET)
  set(zOptKws RECURSE)
  cmake_parse_arguments(PARSE_ARGV 1 "" "${zOptKws}" "" "")
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "Unexpected arguments: ${_UNPARSED_ARGUMENTS}.")
  endif()

  if(DEFINED _RECURSE)
    set(_RECURSE RECURSE)
  else()
    set(_RECURSE)
  endif()

  get_link_libraries(zLibs ${_TARGET} ${_RECURSE})

  foreach(sLib IN LISTS zLibs)
    if(TARGET ${sLib})
      get_target_property(sType ${sLib} TYPE)
      if(sType STREQUAL "SHARED_LIBRARY")
        add_custom_command(
          TARGET  ${_TARGET}
                  POST_BUILD
          COMMAND "${CMAKE_COMMAND}" "-E" "copy_if_different"
                  "$<TARGET_FILE:${sLib}>"
                  "$<TARGET_FILE_DIR:${_TARGET}>")
      endif()
    elseif(EXISTS ${sLib})
      add_custom_command(
        TARGET  ${_TARGET}
                POST_BUILD
        COMMAND "${CMAKE_COMMAND}" "-E" "copy_if_different"
                "${sLib}"
                "$<TARGET_FILE_DIR:${_TARGET}>")
    endif()
  endforeach()
endfunction()

#.rst:
# .. command:: install_link_libraries
#
#   安装链接库（install link libraries）。
#
#   .. code-block:: cmake
#
#     install_link_libraries(
#       <target> [RECURSE]
#     )
function(install_link_libraries)
  message(AUTHOR_WARNING "This function not yet implemented.")
endfunction()
