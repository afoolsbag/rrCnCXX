#  _____ _           _    _
# |  ___(_)_ __   __| |  / \__   ___ __ ___
# | |_  | | '_ \ / _` | / _ \ \ / | '__/ _ \
# |  _| | | | | | (_| |/ ___ \ V /| | | (_) |
# |_|   |_|_| |_|\__,_/_/   \_\_/ |_|  \___/  FindAvro by FIGlet
# zhengrr
# 2018-04-02 – 2018-10-22
# The Unlicense

#.rst:
# FindAvro
# --------
#
# Find the `Apache Avro <https://avro.apache.org/>`_ headers and libraries.
#
# IMPORTED Targets
# ^^^^^^^^^^^^^^^^
#
# This module defines the following :prop_tgt:`IMPORTED` targets:
#
# ``Avro::AvroCpp``
#   The AvroCpp library, if found.
#
# ``Avro::AvroGenCpp``
#   The AvroGenCpp executable, if found.
#
# Result Variables
# ^^^^^^^^^^^^^^^^
#
# This module defines the following variables:
#
# ``Avro_FOUND``
#   Found the Avro.
#
# ``Avro_INCLUDE_DIRS``
#   The directory containing the Avro headers.
#
# ``Avro_LIBRARIES``
#   The Avro libraries.
#
# ``Avro_AvroGenCpp_EXECUTABLE``
#   The path to the AvroGenCpp executable.
#
# Cache variables
# ^^^^^^^^^^^^^^^
#
# The following cache variables may also be set:
#
# ``Avro_ROOT_DIR``
#   The root directory of the Avro installation (may also be set as an environment variable)::
#
#     v Avro_ROOT_DIR
#       v bin
#           avrogencpp.exe
#       v include
#         v avro
#           > buffer
#             AvroParse.hh
#             AvroSerialize.hh
#             AvroTraits.hh
#             ...
#       v lib
#           avrocpp.dll
#           avrocpp.lib

if(Avro_FOUND)
  return()
endif()

# hints
set(zHints "${Avro_ROOT_DIR}" "$ENV{Avro_ROOT_DIR}")

# bin
find_program(
  Avro_AvroGenCpp_EXECUTABLE
  NAMES         "avrogencpp"
  HINTS         ${zHints}
  PATH_SUFFIXES "bin"
  NO_DEFAULT_PATH)
mark_as_advanced(Avro_AvroGenCpp_EXECUTABLE)

# include
find_path(
  Avro_INCLUDE_DIR
  NAMES         "avro/AvroSerialize.hh"
  HINTS         ${zHints}
  PATH_SUFFIXES "include"
  NO_DEFAULT_PATH)
mark_as_advanced(Avro_INCLUDE_DIR)

set(Avro_INCLUDE_DIRS ${Avro_INCLUDE_DIR})

# lib
find_library(
  Avro_AvroCpp_LIBRARY
  NAMES         "avrocpp"
  HINTS         ${zHints}
  PATH_SUFFIXES "lib"
  NO_DEFAULT_PATH)
mark_as_advanced(Avro_AvroCpp_LIBRARY)
find_file(
  Avro_AvroCpp_LIBRARY_DLL
  NAMES         "avrocpp.dll"
  HINTS         ${zHints}
  PATH_SUFFIXES "lib"
  NO_DEFAULT_PATH)
mark_as_advanced(Avro_AvroCpp_LIBRARY_DLL)

set(Avro_LIBRARIES ${Avro_AvroCpp_LIBRARY})

# package
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
  Avro
  DEFAULT_MSG
  Avro_AvroCpp_LIBRARY
  Avro_INCLUDE_DIR
  Avro_AvroCpp_LIBRARY_DLL)

if(Avro_FOUND)
  # targets
  if(NOT TARGET Avro::AvroCpp)
    add_library(Avro::AvroCpp SHARED IMPORTED)
    set_target_properties(
      Avro::AvroCpp
      PROPERTIES IMPORTED_IMPLIB               "${Avro_AvroCpp_LIBRARY}"
                 IMPORTED_LOCATION             "${Avro_AvroCpp_LIBRARY_DLL}"
                 INTERFACE_INCLUDE_DIRECTORIES "${Avro_INCLUDE_DIR}")
    target_link_libraries(Avro::AvroCpp INTERFACE Boost::boost)
  endif()
  if(NOT TARGET Avro::AvroGenCpp)
    add_executable(Avro::AvroGenCpp IMPORTED)
    set_target_properties(
      Avro::AvroGenCpp
      PROPERTIES IMPORTED_LOCATION "${Avro_AvroGenCpp_EXECUTABLE}")
  endif()
  mark_as_advanced(Avro_ROOT_DIR)

else()
  # hints
  set(Avro_ROOT_DIR "${Avro_ROOT_DIR}" CACHE PATH "The root directory of the Avro installation.")
  mark_as_advanced(CLEAR Avro_ROOT_DIR)

endif()
