#  _____ _           _    _
# |  ___(_)_ __   __| |  / \__   ___ __ ___
# | |_  | | '_ \ / _` | / _ \ \ / | '__/ _ \
# |  _| | | | | | (_| |/ ___ \ V /| | | (_) |
# |_|   |_|_| |_|\__,_/_/   \_\_/ |_|  \___/
# zhengrr                  FindAvro by FIGlet
# 2018-04-02 – 11
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
# 影响：
# ::
#
#    Avro_FOUND
#    Avro_INCLUDE_DIRS
#    Avro_LIBRARIES
#
#    Avro::Avro
#    Avro::AvroGenCpp
#
# 预期：
# ::
#
#    v avro_root_dir
#       v bin
#            avrogencpp.exe
#       v include
#          v avro
#             > buffer
#               AvroParse.hh
#               AvroSerialize.hh
#               AvroTraits.hh
#               ...
#       v lib
#            avrocpp.dll
#            avrocpp.lib
#
set(zHints "${Avro_ROOT_DIR}" "$ENV{AVROROOT}")

# Avro::AvroGenCpp

find_program(Avro_AvroGenCpp_EXECUTABLE
  NAMES
    "avrogencpp"
  HINTS
    ${zHints}
  PATH_SUFFIXES
    "bin"
  NO_DEFAULT_PATH)
mark_as_advanced(Avro_AvroGenCpp_EXECUTABLE)

if(Avro_AvroGenCpp_EXECUTABLE AND NOT TARGET Avro::AvroGenCpp)
  add_executable(Avro::AvroGenCpp IMPORTED GLOBAL)
  set_target_properties(Avro::AvroGenCpp PROPERTIES
    IMPORTED_LOCATION "${Avro_AvroGenCpp_EXECUTABLE}")
endif()

# Avro::Avro

find_path(Avro_INCLUDE_DIRS
  NAMES
    "avro/AvroSerialize.hh"
  HINTS
    ${zHints}
  PATH_SUFFIXES
    "include"
  NO_DEFAULT_PATH)
mark_as_advanced(Avro_INCLUDE_DIRS)

find_library(Avro_avrocpp_LIBRARY
  NAMES
    "avrocpp"
  HINTS
    ${zHints}
  PATH_SUFFIXES
    "lib"
  NO_DEFAULT_PATH)
mark_as_advanced(Avro_avrocpp_LIBRARY)
set(Avro_LIBRARIES ${Avro_avrocpp_LIBRARY})

include("FindPackageHandleStandardArgs")
find_package_handle_standard_args("Avro"
  DEFAULT_MSG
    Avro_INCLUDE_DIRS
    Avro_avrocpp_LIBRARY)

if(Avro_FOUND AND NOT TARGET Avro::Avro)
  add_library(Avro::Avro UNKNOWN IMPORTED)
  set_target_properties(Avro::Avro PROPERTIES
    IMPORTED_LOCATION "${Avro_avrocpp_LIBRARY}"
    INTERFACE_INCLUDE_DIRECTORIES "${Avro_INCLUDE_DIRS}")
endif()

target_link_libraries(Avro::Avro INTERFACE Boost::boost)
