# ______ _           _ _____ _____  _____ _
# |  ___(_)         | /  __ \  __ \/  ___| |
# | |_   _ _ __   __| | /  \/ |  \/\ `--.| |
# |  _| | | '_ \ / _` | |   | | __  `--. \ |
# | |   | | | | | (_| | \__/\ |_\ \/\__/ / |____
# \_|   |_|_| |_|\__,_|\____/\____/\____/\_____/ FindCGSL by FIGlet doom
# zhengrr                                 
# 2018-08-13 – 2018-10-22
# The Unlicense

#.rst:
# FindCGSL
# --------
#
# Find the `C++ Code Guidelines Support Library <https://github.com/Microsoft/GSL>`_ headers.
#
# IMPORTED Targets
# ^^^^^^^^^^^^^^^^
#
# This module defines the following :prop_tgt:`IMPORTED` targets:
#
# ``CGSL::CGSL``
#   The CGSL library, if found.
#
# Result Variables
# ^^^^^^^^^^^^^^^^
#
# This module defines the following variables:
#
# ``CGSL_FOUND``
#   Found the CGSL.
#
# ``CGSL_INCLUDE_DIRS``
#   The directory containing the CGSL headers.
#
# Cache variables
# ^^^^^^^^^^^^^^^
#
# The following cache variables may also be set:
#
# ``CGSL_ROOT_DIR``
#   The root directory of the CGSL installation (may also be set as an environment variable)::
#
#     v CGSL_ROOT_DIR
#       v include
#         v gsl
#             gsl
#             ...

if(CGSL_FOUND)
  return()
endif()

# hints
set(zHints "${CGSL_ROOT_DIR}" "$ENV{CGSL_ROOT_DIR}")

# include
find_path(
  CGSL_INCLUDE_DIR
  NAMES         "gsl/gsl"
  HINTS         ${zHints}
  PATH_SUFFIXES "include"
  NO_DEFAULT_PATH)
mark_as_advanced(CGSL_INCLUDE_DIR)

set(CGSL_INCLUDE_DIRS ${CGSL_INCLUDE_DIR})

# package
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
  CGSL
  DEFAULT_MSG
  CGSL_INCLUDE_DIR)

if(CGSL_FOUND)
  # target
  if(NOT TARGET CGSL::CGSL)
    add_library(CGSL::CGSL INTERFACE IMPORTED)
    set_target_properties(
      CGSL::CGSL
      PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "${CGSL_INCLUDE_DIRS}")
  endif()
  mark_as_advanced(CGSL_ROOT_DIR)

else()
  # hints
  set(CGSL_ROOT_DIR "${CGSL_ROOT_DIR}" CACHE PATH "The root directory of the CGSL installation.")
  mark_as_advanced(CLEAR CGSL_ROOT_DIR)

endif()
