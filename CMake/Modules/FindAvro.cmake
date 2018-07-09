#  _____ _           _    _
# |  ___(_)_ __   __| |  / \__   ___ __ ___
# | |_  | | '_ \ / _` | / _ \ \ / | '__/ _ \
# |  _| | | | | | (_| |/ ___ \ V /| | | (_) |
# |_|   |_|_| |_|\__,_/_/   \_\_/ |_|  \___/  FindAvro by FIGlet
# zhengrr
# 2018-04-02 – 2018-07-09
# The MIT License

#.rst:
# FindAvro
# --------
#
# 寻找Avro。
#
# 导入目标：
# ::
#
#    Avro::Avro
#    Avro::AvroGenCpp
#
# 结果变量：
# ::
#
#    Avro_FOUND
#    Avro_AvroGenCpp_EXECUTABLE
#    Avro_INCLUDE_DIRS
#    Avro_LIBRARIES
#
# 提示变量：
# ::
#
#    Avro_ROOT_DIR
#    ENV AVRO_DIR
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
if(Avro_FOUND)
  return()
endif()

# hints

set(zHints "${Avro_ROOT_DIR}" "$ENV{AVRO_DIR}")

# bin

find_program(Avro_AvroGenCpp_EXECUTABLE
          NAMES "avrogencpp"
          HINTS ${zHints}
  PATH_SUFFIXES "bin"
                NO_DEFAULT_PATH)
mark_as_advanced(Avro_AvroGenCpp_EXECUTABLE)

# include

find_path(Avro_INCLUDE_DIR
          NAMES "avro/AvroSerialize.hh"
          HINTS ${zHints}
  PATH_SUFFIXES "include"
                NO_DEFAULT_PATH)
mark_as_advanced(Avro_INCLUDE_DIR)

set(Avro_INCLUDE_DIRS ${Avro_INCLUDE_DIR})
mark_as_advanced(Avro_INCLUDE_DIRS)

# lib

find_library(Avro_avrocpp_LIBRARY
          NAMES "avrocpp"
          HINTS ${zHints}
  PATH_SUFFIXES "lib"
                NO_DEFAULT_PATH)
mark_as_advanced(Avro_avrocpp_LIBRARY)

find_file(Avro_avrocpp_LIBRARY_DLL
          NAMES "avrocpp.dll"
          HINTS ${zHints}
  PATH_SUFFIXES "lib"
                NO_DEFAULT_PATH)
mark_as_advanced(Avro_avrocpp_LIBRARY_DLL)

set(Avro_LIBRARIES ${Avro_avrocpp_LIBRARY})
mark_as_advanced(Avro_LIBRARIES)

# package

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Avro
                      DEFAULT_MSG Avro_avrocpp_LIBRARY
                                  Avro_INCLUDE_DIR
                                  Avro_avrocpp_LIBRARY_DLL)

if(Avro_FOUND)

  # targets

  if(NOT TARGET Avro::Avro)
    add_library(Avro::Avro SHARED IMPORTED)
    set_target_properties(Avro::Avro
               PROPERTIES IMPORTED_IMPLIB "${Avro_avrocpp_LIBRARY}"
                          IMPORTED_LOCATION "${Avro_avrocpp_LIBRARY_DLL}"
                          INTERFACE_INCLUDE_DIRECTORIES "${Avro_INCLUDE_DIR}")
    target_link_libraries(Avro::Avro INTERFACE Boost::boost)
  endif()

  if(NOT TARGET Avro::AvroGenCpp)
    add_executable(Avro::AvroGenCpp IMPORTED)
    set_target_properties(Avro::AvroGenCpp
               PROPERTIES IMPORTED_LOCATION "${Avro_AvroGenCpp_EXECUTABLE}")
  endif()

  mark_as_advanced(Avro_ROOT_DIR)

else()

  # hints

  set(Avro_ROOT_DIR "${Avro_ROOT_DIR}" CACHE PATH "The root directory of the Avro installation.")
  mark_as_advanced(CLEAR Avro_ROOT_DIR)

endif()
