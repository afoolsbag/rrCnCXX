# zhengrr
# 2019-04-15 – 2019-04-15
# Unlicense

cmake_minimum_required(VERSION 3.10)
cmake_policy(VERSION 3.10)

include_guard()

#-------------------------------------------------------------------------------
# FUNCTIONS

# .res
# .. command:: copy_link_libraries
function(copy_link_libraries _TARGET)
  get_target_property(zUnts ${_TARGET} LINK_LIBRARIES)  # untraversed libraries
  set(zTras)                                            # traversed libraries
  while(zUnts)
    foreach(sUnt IN ITEMS ${zUnts})
      if(TARGET ${sUnt})
        get_target_property(zTmps ${sUnt} LINK_LIBRARIES)
        list(APPEND zUnts ${zTmps})
      endif()
      list(APPEND zTras ${sUnt})
    endforeach()
    list(REMOVE_DUPLICATES zUnts)
    list(REMOVE_DUPLICATES zTras)
    list(REMOVE_ITEM zUnts ${zTras})
  endwhile()

  foreach(sLib IN LISTS zTras)
    if(TARGET ${sLib})
      add_custom_command(
        TARGET  ${_TARGET}
                POST_BUILD
        COMMAND "${CMAKE_COMMAND}" "-E" "copy_if_different"
                "$<TARGET_FILE:${sLib}>"
                "$<TARGET_FILE_DIR:${_TARGET}>")
    elseif(EXISTS ${sDep})
      add_custom_command(
        TARGET  ${_TARGET}
                POST_BUILD
        COMMAND "${CMAKE_COMMAND}" "-E" "copy_if_different"
                "${sLib}"
                "$<TARGET_FILE_DIR:${_TARGET}>")
    endif()
  endforeach()
endfunction()
