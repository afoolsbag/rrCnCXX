# ______ _           _   _________ ___________ _     ___________
# |  ___(_)         | | |_  | ___ \_   _| ___ \ |   |_   _| ___ \
# | |_   _ _ __   __| |   | | |_/ / | | | |_/ / |     | | | |_/ /
# |  _| | | '_ \ / _` |   | |    /  | | |  __/| |     | | | ___ \ zhengrr
# | |   | | | | | (_| /\__/ / |\ \  | | | |   | |_____| |_| |_/ / 2019-01-17 – 2019-01-18
# \_|   |_|_| |_|\__,_\____/\_| \_| \_/ \_|   \_____/\___/\____/  Unlicense

if(NOT COMMAND get_toolset_architecture_address_model_tag)
  include("${CMAKE_CURRENT_LIST_DIR}/rrCMake/LibraryTag.cmake")
endif()

#.rst:
# FindJRTPLIB
# -----------
#
# Find the `JRTPLIB <https://research.edm.uhasselt.be/jori/page/CS/Jrtplib.html>`_ headers and libraries.
#
# IMPORTED Targets
# ^^^^^^^^^^^^^^^^
#
# This module defines the following :prop_tgt:`IMPORTED` targets:
#
# ``JRPTLIB::jrtplib``
#   The jrtplib library, if found.
#
# Result Variables
# ^^^^^^^^^^^^^^^^
#
# This module defines the following variables:
#
# ``JRTPLIB_FOUND``
#   Found the JRTPLIB.
#
# Cache variables
# ^^^^^^^^^^^^^^^
#
# The following cache variables may also be set:
#
# ``JRTPLIB_ROOT_DIR``
#   The root directory of the JRTPLIB installation (may also be set as an environment variable)::
#
#     v JRTPLIB_ROOT_DIR
#       v include
#         v jrtplib3
#             rtcpapppacket.h
#             ...
#       v lib
#         > vc141x32d
#         > ...
#           jrtplib.lib

if(JRTPLIB_FOUND)
  return()
endif()

# hints
set(zHints "${JRTPLIB_ROOT_DIR}" "$ENV{JRTPLIB_ROOT_DIR}")

# include
find_path(
  JRTPLIB_INCLUDE_DIR
  NAMES         "jrtplib3/rtpsession.h"
  HINTS         ${zHints}
  PATH_SUFFIXES "include"
  NO_DEFAULT_PATH)
mark_as_advanced(JRTPLIB_INCLUDE_DIR)

# lib
get_toolset_architecture_address_model_tag(sTag)
set(zDbgPathSufs "lib/${sTag}d" "lib/${sTag}" "lib")
set(zRelPathSufs                "lib/${sTag}" "lib")

find_library(
  JRTPLIB_jrtplib_LIBRARY_DEBUG
  NAMES         "jrtplib_d"
  HINTS         ${zHints}
  PATH_SUFFIXES ${zDbgPathSufs}
  NO_DEFAULT_PATH)
mark_as_advanced(JRTPLIB_jrtplib_LIBRARY_DEBUG)
find_library(
  JRTPLIB_jrtplib_LIBRARY_RELEASE
  NAMES         "jrtplib"
  HINTS         ${zHints}
  PATH_SUFFIXES ${zRelPathSufs}
  NO_DEFAULT_PATH)
mark_as_advanced(JRTPLIB_jrtplib_LIBRARY_RELEASE)

# package
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
  JRTPLIB
  DEFAULT_MSG
  JRTPLIB_jrtplib_LIBRARY_RELEASE
  JRTPLIB_INCLUDE_DIR
  JRTPLIB_jrtplib_LIBRARY_DEBUG)

if(JRTPLIB_FOUND)
  # targets
  if(NOT TARGET JRTPLIB::jrtplib)
    add_library(JRTPLIB::jrtplib STATIC IMPORTED)
    set_target_properties(
      JRTPLIB::jrtplib
      PROPERTIES IMPORTED_LOCATION_DEBUG       "${JRTPLIB_jrtplib_LIBRARY_DEBUG}"
                 IMPORTED_LOCATION_RELEASE     "${JRTPLIB_jrtplib_LIBRARY_RELEASE}"
                 INTERFACE_INCLUDE_DIRECTORIES "${JRTPLIB_INCLUDE_DIR}")
    target_link_libraries(
      JRTPLIB::jrtplib
      INTERFACE WS2_32)
  endif()

  mark_as_advanced(JRTPLIB_ROOT_DIR)

else()
  # hints
  set(JRTPLIB_ROOT_DIR "${JRTPLIB_ROOT_DIR}" CACHE PATH "The root directory of the JRTPLIB installation.")
  mark_as_advanced(CLEAR JRTPLIB_ROOT_DIR)

endif()
