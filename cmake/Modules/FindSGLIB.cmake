#===========================================================================
# zhengrr
# 2016-11-11 – 2017-7-27
# The MIT License
#---------------------------------------------------------------------------

#.rst:
# FindSGLIB
# ---------
#
# 此模块用于寻找 FindSGLIB。
#
# 此模块定义并设置了以下变量：
#
# ``SGLIB_FOUND``
# ``SGLIB_BASE_DIR``
# ``SGLIB_INCLUDE_DIRS``

function(find_sglib)
  set(SGLIB_FOUND TRUE)

  if(NOT IS_DIRECTORY "${SGLIB_BASE_DIR}")
    set(SGLIB_FOUND FALSE)
  endif()

  if(SGLIB_FOUND)
    find_path(SGLIB_INCLUDE_DIRS
        NAMES "sglib/sglib.h"
        PATHS "${SGLIB_BASE_DIR}")
  endif()

  include(FindPackageHandleStandardArgs)
  find_package_handle_standard_args(SGLIB
      FOUND_VAR     SGLIB_FOUND
      REQUIRED_VARS SGLIB_INCLUDE_DIRS)

  set(SGLIB_BASE_DIR ${SGLIB_BASE_DIR} CACHE PATH "SGLIB base directory.")
  set(SGLIB_FOUND ${SGLIB_FOUND} PARENT_SCOPE)
  mark_as_advanced(SGLIB_INCLUDE_DIRS)
endfunction()


find_sglib()
