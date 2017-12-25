#===========================================================================
# zhengrr
# 2016-10-24 – 2017-7-27
# The MIT License
#---------------------------------------------------------------------------

#.rst:
# FindLIVE555
# -----------
#
# 此模块用于寻找 LIVE555。
#
# 此模块定义并设置了以下变量：
#
#  ``LIVE555_BASE_DIR``
#  ``LIVE555_FOUND``
#  ``LIVE555_INCLUDE_DIRS``
#  ``LIVE555_LIBRARIES``
#
#  ``LIVE555_BasicUsageEnvironment_LIBRARY``
#  ``LIVE555_groupsock_LIBRARY``
#  ``LIVE555_liveMedia_LIBRARY``
#  ``LIVE555_UsageEnvironment_LIBRARY``

function(find_live555)
  set(LIVE555_FOUND TRUE)

  if(NOT IS_DIRECTORY "${LIVE555_BASE_DIR}")
    set(LIVE555_FOUND FALSE)
  endif()

  if(LIVE555_FOUND)
    find_path(LIVE555_INCLUDE_DIRS
        NAMES "live555/BasicUsageEnvironment.hh"
              "live555/Groupsock.hh"
              "live555/liveMedia.hh"
              "live555/UsageEnvironment.hh"
        PATHS "${LIVE555_BASE_DIR}")
    find_library(LIVE555_BasicUsageEnvironment_LIBRARY
        NAMES "BasicUsageEnvironment" PATHS "${LIVE555_BASE_DIR}")
    find_library(LIVE555_groupsock_LIBRARY
        NAMES "groupsock"             PATHS "${LIVE555_BASE_DIR}")
    find_library(LIVE555_liveMedia_LIBRARY
        NAMES "liveMedia"             PATHS "${LIVE555_BASE_DIR}")
    find_library(LIVE555_UsageEnvironment_LIBRARY
        NAMES "UsageEnvironment"      PATHS "${LIVE555_BASE_DIR}")
  endif()

  include(FindPackageHandleStandardArgs)
  find_package_handle_standard_args(LIVE555
      FOUND_VAR     LIVE555_FOUND
      REQUIRED_VARS LIVE555_INCLUDE_DIRS
                    LIVE555_BasicUsageEnvironment_LIBRARY
                    LIVE555_groupsock_LIBRARY
                    LIVE555_liveMedia_LIBRARY
                    LIVE555_UsageEnvironment_LIBRARY)

  set(LIVE555_LIBRARIES
      ${LIVE555_BasicUsageEnvironment_LIBRARY}
      ${LIVE555_groupsock_LIBRARY}
      ${LIVE555_liveMedia_LIBRARY}
      ${LIVE555_UsageEnvironment_LIBRARY})

  set(LIVE555_BASE_DIR ${LIVE555_BASE_DIR} CACHE PATH "LIVE555 base directory.")
  set(LIVE555_FOUND ${LIVE555_FOUND} PARENT_SCOPE)
  set(LIVE555_LIBRARIES ${LIVE555_LIBRARIES} PARENT_SCOPE)
  mark_as_advanced(
      LIVE555_INCLUDE_DIRS
      LIVE555_BasicUsageEnvironment_LIBRARY
      LIVE555_groupsock_LIBRARY
      LIVE555_liveMedia_LIBRARY
      LIVE555_UsageEnvironment_LIBRARY)
endfunction()


find_live555()
