#  _____ _           _    _
# |  ___(_)_ __   __| |  / \__   ___ __ ___
# | |_  | | '_ \ / _` | / _ \ \ / | '__/ _ \
# |  _| | | | | | (_| |/ ___ \ V /| | | (_) |
# |_|   |_|_| |_|\__,_/_/   \_\_/ |_|  \___/
# zhengrr                  FindAvro by FIGlet
# 2018-04-02 – 02
# The MIT License

#.rst:
# FindAvro
# --------
#
# 寻找Avro包。
#
# 缓存：
# ::
#
#    Avro_ROOT_DIR
#    ENV AVROROOT
#
# 结果：
# ::
#
#    Avro_FOUND
#    Avro_INCLUDE_DIRS
#    Avro_LIBRARIES
#
#    Avro::Avro
#
# 预期：
# ::
#
#    v avro_root_dir
#       v include
#          v avro
#             > buffer
#               AvroParse.hh
#               AvroSerialize.hh
#               AvroTraits.hh
#               ...
#       v lib
#          v Win32
#             v Debug
#                  avrocpp.dll
#                  avrocpp.lib
#             > Release
#          v x64
#             > Debug
#             > Release
#
set(zHints "${Avro_ROOT_DIR}" "$ENV{AVROROOT}")

if(CMAKE_SIZEOF_VOID_P EQUAL 4)
  set(sArch "Win32")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
  set(sArch "x64")
else()
  message(WARNING "Unexpected CMAKE_SIZEOF_VOID_P(${CMAKE_SIZEOF_VOID_P}).")
  set(sArch ".")
endif()

find_path(Avro_INCLUDE_DIRS
  NAMES
    "avro/AvroSerialize.hh"
  HINTS
    ${zHints}
  PATH_SUFFIXES
    "include"
  NO_DEFAULT_PATH)
mark_as_advanced(Avro_INCLUDE_DIRS)

find_library(Avro_avrocpp_LIBRARY_DEBUG
  NAMES
    "avrocpp"
  HINTS
    ${zHints}
  PATH_SUFFIXES
    "lib/${sArch}/Debug"
  NO_DEFAULT_PATH)
mark_as_advanced(Avro_avrocpp_LIBRARY_DEBUG)
find_library(Avro_avrocpp_LIBRARY_RELEASE
  NAMES
    "avrocpp"
  HINTS
    ${zHints}
  PATH_SUFFIXES
    "lib/${sArch}/Release"
  NO_DEFAULT_PATH)
mark_as_advanced(Avro_avrocpp_LIBRARY_RELEASE)
set(Avro_LIBRARIES ${Avro_avrocpp_LIBRARY_DEBUG} ${Avro_avrocpp_LIBRARY_RELEASE})

include("FindPackageHandleStandardArgs")
find_package_handle_standard_args("Avro"
  DEFAULT_MSG
    Avro_INCLUDE_DIRS
    Avro_avrocpp_LIBRARY_DEBUG
    Avro_avrocpp_LIBRARY_RELEASE)

if(Avro_FOUND)
  if(NOT TARGET Avro::Avro)
    add_library(Avro::Avro UNKNOWN IMPORTED)
  endif()
  if(Avro_avrocpp_LIBRARY_DEBUG)
    set_property(TARGET Avro::Avro APPEND PROPERTY
      IMPORTED_CONFIGURATIONS DEBUG)
    set_target_properties(Avro::Avro PROPERTIES
      IMPORTED_LOCATION_DEBUG "${Avro_avrocpp_LIBRARY_DEBUG}")
  endif()
  if(Avro_avrocpp_LIBRARY_RELEASE)
    set_property(TARGET Avro::Avro APPEND PROPERTY
      IMPORTED_CONFIGURATIONS RELEASE)
    set_target_properties(Avro::Avro PROPERTIES
      IMPORTED_LOCATION_RELEASE "${Avro_avrocpp_LIBRARY_RELEASE}")
  endif()
  set_target_properties(Avro::Avro PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${Avro_INCLUDE_DIRS}")
endif()

if(Boost_FOUND)
  target_link_libraries(Avro::Avro INTERFACE Boost::boost)
endif()
