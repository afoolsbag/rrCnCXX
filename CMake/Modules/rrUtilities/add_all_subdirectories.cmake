#            _   _ _   _ _ _ _   _                                       zhengrr
#  _ __ _ __| | | | |_(_| (_| |_(_) ___ ___               2016-10-8 – 2017-12-26
# | '__| '__| | | | __| | | | __| |/ _ / __|                     The MIT License
# | |  | |  | |_| | |_| | | | |_| |  __\__ \
# |_|  |_|   \___/ \__|_|_|_|\__|_|\___|___/ rrUtilities by FIGlet
#             _     _           _         _ _               _
#    __ _  __| | __|  ___ _   _| |__   __| (_)_ __ ___  ___| |_ ___  _ __ _   _
#   / _` |/ _` |/ _` / __| | | | '_ \ / _` | | '__/ _ \/ __| __/ _ \| '__| | | |
#  | (_| | (_| | (_| \__ | |_| | |_) | (_| | | | |  __| (__| || (_) | |  | |_| |
#   \__,_|\__,_|\__,_|___/\__,_|_.__/ \__,_|_|_|  \___|\___|\__\___/|_|   \__, |
#                                              add_subdirectory by FIGlet |___/

# .rst
# .. command:: add_all_subdirectories
#
#  将目录下所有子目录添加到构建::
#
#   add_all_subdirectories(
#     [SRCDIR           "<parent directory of source directories>"]
#     [BINDIR           "<parent directory of binary directories>"]
#     [EXCLUDE_FROM_ALL                                           ]
#   )
function(add_all_subdirectories)

  set(opts "EXCLUDE_FROM_ALL")
  set(ovks "SRCDIR" "BINDIR")
  set(mvks)
  cmake_parse_arguments("" "${opts}" "${ovks}" "${mvks}" ${ARGN})
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments(${_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  if(DEFINED _SRCDIR)
    set(path "${_SRCDIR}")
  else()
    set(path "${CMAKE_CURRENT_LIST_DIR}")
  endif()

  file(GLOB files LIST_DIRECTORIES TRUE RELATIVE "${path}" "${path}/*")

  foreach(file IN LISTS files)
    if(IS_DIRECTORY "${path}/${file}")

      if(DEFINED _SRCDIR)
        set(srcdir "${path}/${file}")
      else()
        set(srcdir "${file}")
      endif()

      if(DEFINED _BINDIR)
        set(bindir "${parent_binary_dir}/${dir}")
      else()
        unset(bindir)
      endif()

      if(_EXCLUDE_FROM_ALL)
        set(exclude_from_all "EXCLUDE_FROM_ALL")
      else()
        unset(exclude_from_all)
      endif()

      add_subdirectory("${srcdir}" ${bindir} ${exclude_from_all})

    endif()
  endforeach()

endfunction()
