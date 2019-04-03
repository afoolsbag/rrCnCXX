# ______ _           _ _     _              _ _
# |  ___(_)         | | |   (_)            | (_)
# | |_   _ _ __   __| | |__  _ _ __ ___  __| |_ ___
# |  _| | | '_ \ / _` | '_ \| | '__/ _ \/ _` | / __| zhengrr
# | |   | | | | | (_| | | | | | | |  __/ (_| | \__ \ 2019-04-02 – 2019-04-02
# \_|   |_|_| |_|\__,_|_| |_|_|_|  \___|\__,_|_|___/ Unlicense

if(NOT COMMAND find_package_handle_standard_args)
  include(FindPackageHandleStandardArgs)
endif()

if(NOT COMMAND get_toolset_architecture_address_model_tag)
  include("${CMAKE_CURRENT_LIST_DIR}/rrCMake/LibraryTag.cmake")
endif()

#.rst:
# Findhiredis
# -----------
#
# Find the `hiredis <https://github.com/redis/hiredis>`_ headers and libraries.
#
# IMPORTED Targets
# ^^^^^^^^^^^^^^^^
#
# This module defines the following :prop_tgt:`IMPORTED` targets:
#
# ``hiredis::hiredis``
#   The hiredis library, if found.
#
# Result Variables
# ^^^^^^^^^^^^^^^^
#
# This module defines the following variables:
#
# ``hiredis_FOUND``
#   Found the hiredis.
#
# Cache variables
# ^^^^^^^^^^^^^^^
#
# The following cache variables may also be set:
#
# ``hiredis_ROOT``
#   The root directory of the Check installation (may also be set as an environment variable)::
#
#     v hiredis_ROOT
#       v include
#         v hiredis
#             hiredis.h
#             ...
#       v lib
#         > vc141x32d
#         > ...
#           hiredis.lib

if(hiredis_FOUND)
  return()
endif()

#-------------------------------------------------------------------------------
# UNIX-like

if(UNIX)

  # <prefix>/include
  find_path(
    hiredis_INCLUDE_DIR
    NAMES "hiredis/hiredis.h")
  mark_as_advanced(hiredis_INCLUDE_DIR)

  # <prefix>/lib
  find_library(
    hiredis_hiredis_LIBRARY
    NAMES "hiredis")
  mark_as_advanced(hiredis_hiredis_LIBRARY)

  # package
  find_package_handle_standard_args(
    hiredis
    DEFAULT_MSG
    hiredis_hiredis_LIBRARY
    hiredis_INCLUDE_DIR)

  if(hiredis_FOUND)
    # targets
    if(NOT TARGET hiredis::hiredis)
      add_library(hiredis::hiredis STATIC IMPORTED)
      set_target_properties(
        hiredis::hiredis
        PROPERTIES IMPORTED_LOCATION             "${hiredis_hiredis_LIBRARY}"
                   INTERFACE_INCLUDE_DIRECTORIES "${hiredis_INCLUDE_DIR}")
    endif()

  endif()

endif()

#-------------------------------------------------------------------------------
# Windows

if(WIN32)

  cmake_minimum_required(VERSION 3.12)  # CMP0074

  # <prefix>/include
  find_path(
    hiredis_INCLUDE_DIR
    NAMES         "hiredis/hiredis.h")
  mark_as_advanced(hiredis_INCLUDE_DIR)

  # <prefix>/lib
  get_toolset_architecture_address_model_tag(sTag)

  find_library(
    hiredis_hiredis_LIBRARY_DEBUG
    NAMES         "hiredis"
    PATH_SUFFIXES "${sTag}d" "${sTag}")
  mark_as_advanced(hiredis_hiredis_LIBRARY_DEBUG)
  find_library(
    hiredis_hiredis_LIBRARY_RELEASE
    NAMES         "hiredis"
    PATH_SUFFIXES "${sTag}")
  mark_as_advanced(hiredis_hiredis_LIBRARY_RELEASE)

  # package
  find_package_handle_standard_args(
    hiredis
    DEFAULT_MSG
    hiredis_hiredis_LIBRARY_RELEASE
    hiredis_INCLUDE_DIR
    hiredis_hiredis_LIBRARY_DEBUG)

  if(hiredis_FOUND)
    # targets
    if(NOT TARGET hiredis::hiredis)
      add_library(hiredis::hiredis STATIC IMPORTED)
      set_target_properties(
        hiredis::hiredis
        PROPERTIES IMPORTED_LOCATION_DEBUG       "${hiredis_hiredis_LIBRARY_DEBUG}"
                   IMPORTED_LOCATION_RELEASE     "${hiredis_hiredis_LIBRARY_RELEASE}"
                   INTERFACE_INCLUDE_DIRECTORIES "${hiredis_INCLUDE_DIR}")
      target_link_libraries(
        hiredis::hiredis
        INTERFACE WS2_32)
    endif()

    mark_as_advanced(hiredis_ROOT)

  else()
    # hints
    set(hiredis_ROOT "${hiredis_ROOT}" CACHE PATH "The root directory of the hiredis installation.")
    mark_as_advanced(CLEAR hiredis_ROOT)

  endif()

endif()
