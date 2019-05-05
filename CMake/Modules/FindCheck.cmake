# ______ _           _ _____ _               _
# |  ___(_)         | /  __ \ |             | |
# | |_   _ _ __   __| | /  \/ |__   ___  ___| | __
# |  _| | | '_ \ / _` | |   | '_ \ / _ \/ __| |/ / zhengrr
# | |   | | | | | (_| | \__/\ | | |  __/ (__|   <  2018-02-02 – 2019-05-05
# \_|   |_|_| |_|\__,_|\____/_| |_|\___|\___|_|\_\ Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

include_guard()

if(NOT COMMAND check_include_file)
  include(CheckIncludeFile)
endif()

if(NOT COMMAND find_package_handle_standard_args)
  include(FindPackageHandleStandardArgs)
endif()

if(NOT COMMAND add_library_ex)
  include("${CMAKE_CURRENT_LIST_DIR}/rrCMake/AddLibrary.cmake")
endif()

if(NOT COMMAND get_toolset_architecture_address_model_tag)
  include("${CMAKE_CURRENT_LIST_DIR}/rrCMake/LibraryTag.cmake")
endif()

#.rst:
# FindCheck
# ---------
#
# Find the `Check <https://libcheck.github.io/check/>`_ headers and libraries.
#
# IMPORTED Targets
# ^^^^^^^^^^^^^^^^
#
# This module defines the following :prop_tgt:`IMPORTED` targets:
#
# ``Check::check``
#   The check library, if found.
#
# ``Check::compat``
#   The compat library, if found.
#
# Result Variables
# ^^^^^^^^^^^^^^^^
#
# This module defines the following variables:
#
# ``Check_FOUND``
#   Found the Check.
#
# Cache variables
# ^^^^^^^^^^^^^^^
#
# The following cache variables may also be set:
#
# ``Check_ROOT``
#   The root directory of the Check installation (may also be set as an environment variable)::
#
#     v Check_ROOT
#       v include
#           check.h
#           ...
#       v lib
#         > vc141x32d
#         > ...
#           check.lib
#           compat.lib

if(Check_FOUND)
  return()
endif()

check_include_file("stdint.h" HAVE_STDINT_H)

#-------------------------------------------------------------------------------
# UNIX-like

if(UNIX)
  # <prefix>/include
  find_path(
    Check_INCLUDE_DIR
    NAMES "check.h")
  mark_as_advanced(Check_INCLUDE_DIR)

  # <prefix>/lib
  find_library(
    Check_check_LIBRARY
    NAMES "check")
  mark_as_advanced(Check_check_LIBRARY)

  find_library(
    Check_compat_LIBRARY
    NAMES "compat")
  mark_as_advanced(Check_compat_LIBRARY)

  # package
  find_package_handle_standard_args(
    Check
    DEFAULT_MSG
    Check_check_LIBRARY
    Check_INCLUDE_DIR
    Check_compat_LIBRARY)

  if(Check_FOUND)
    # targets
    if(NOT TARGET Check::compat)
      add_library_ex(
        Check::compat       STATIC IMPORTED
        PROPERTIES          IMPORTED_LOCATION "${Check_compat_LIBRARY}"
        INCLUDE_DIRECTORIES INTERFACE         "${Check_INCLUDE_DIR}")
    endif()

    if(NOT TARGET Check::check)
      add_library_ex(
        Check::check        STATIC IMPORTED
        PROPERTIES          IMPORTED_LOCATION "${Check_check_LIBRARY}"
        COMPILE_DEFINITIONS INTERFACE         "$<$<BOOL:${HAVE_STDINT_H}>:HAVE_STDINT_H>"
        INCLUDE_DIRECTORIES INTERFACE         "${Check_INCLUDE_DIR}"
        LINK_LIBRARIES      INTERFACE         m rt subunit Check::compat)
    endif()

  endif()

endif()

#-------------------------------------------------------------------------------
# Windows

if(WIN32)
  # <prefix>/include
  find_path(
    Check_INCLUDE_DIR
    NAMES         "check.h")
  mark_as_advanced(Check_INCLUDE_DIR)

  # <prefix>/lib
  get_toolset_architecture_address_model_tag(sTag)

  find_library(
    Check_check_LIBRARY_DEBUG
    NAMES         "check"
    PATH_SUFFIXES "${sTag}d" "${sTag}")
  mark_as_advanced(Check_check_LIBRARY_DEBUG)
  find_library(
    Check_check_LIBRARY_RELEASE
    NAMES         "check"
    PATH_SUFFIXES "${sTag}")
  mark_as_advanced(Check_check_LIBRARY_RELEASE)

  find_library(
    Check_compat_LIBRARY_DEBUG
    NAMES         "compat"
    PATH_SUFFIXES "${sTag}d" "${sTag}")
  mark_as_advanced(Check_compat_LIBRARY_DEBUG)
  find_library(
    Check_compat_LIBRARY_RELEASE
    NAMES         "compat"
    PATH_SUFFIXES "${sTag}")
  mark_as_advanced(Check_compat_LIBRARY_RELEASE)

  # package
  find_package_handle_standard_args(
    Check
    DEFAULT_MSG
    Check_check_LIBRARY_RELEASE
    Check_INCLUDE_DIR
    Check_check_LIBRARY_DEBUG
    Check_compat_LIBRARY_DEBUG
    Check_compat_LIBRARY_RELEASE)

  if(Check_FOUND)
    # targets
    if(NOT TARGET Check::compat)
      add_library_ex(
        Check::compat       STATIC IMPORTED
        PROPERTIES          IMPORTED_LOCATION_DEBUG   "${Check_compat_LIBRARY_DEBUG}"
                            IMPORTED_LOCATION_RELEASE "${Check_compat_LIBRARY_RELEASE}"
        INCLUDE_DIRECTORIES INTERFACE                 "${Check_INCLUDE_DIR}")
    endif()

    if(NOT TARGET Check::check)
      add_library_ex(
        Check::check        STATIC IMPORTED
        PROPERTIES          IMPORTED_LOCATION_DEBUG       "${Check_check_LIBRARY_DEBUG}"
                            IMPORTED_LOCATION_RELEASE     "${Check_check_LIBRARY_RELEASE}"
        COMPILE_DEFINITIONS INTERFACE                     "$<$<BOOL:${HAVE_STDINT_H}>:HAVE_STDINT_H>"
        INCLUDE_DIRECTORIES INTERFACE                     "${Check_INCLUDE_DIR}"
        LINK_LIBRARIES      INTERFACE                     Check::compat)

    endif()

    mark_as_advanced(FORCE Check_ROOT)

  else()
    # hints
    set(Check_ROOT "${Check_ROOT}" CACHE PATH "The root directory of the Check installation.")
    mark_as_advanced(CLEAR Check_ROOT)

  endif()

endif()
