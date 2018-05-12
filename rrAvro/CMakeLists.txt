#             _
#  _ __ _ __ / \__   ___ __ ___
# | '__| '__/ _ \ \ / | '__/ _ \
# | |  | | / ___ \ V /| | | (_) |
# |_|  |_|/_/   \_\_/ |_|  \___/
# zhengrr        rrAvro by FIGlet
# 2018-04-02 – 2018-05-12
# The MIT License

project("rrAvro" VERSION 2018.5.12 LANGUAGES CXX)
project_extra()
compiler_warning_level(HIGHEST UTF-8)

if(NOT Boost_FOUND)
  find_package(Boost)
  if(NOT Boost_FOUND)
    set(BOOST_ROOT "${BOOST_ROOT}" CACHE PATH "The root directory of the Boost installation.")
  endif()
endif()

if(NOT Avro_FOUND)
  find_package(Avro)
  if(NOT Avro_FOUND)
    set(Avro_ROOT_DIR "${Avro_ROOT_DIR}" CACHE PATH "The root directory of the Avro installation.")
  endif()
endif()

facile_add_doxygen()

facile_add_executable(SUBNAME "ObjectAndFile"
            OPTION_INITIAL_ON
                              "objf.cxx"
                              "schema/RecordType.hxx"
               LINK_LIBRARIES  Avro::Avro)

facile_add_executable(SUBNAME "ObjectAndStream"
            OPTION_INITIAL_ON
                              "objs.cxx"
                              "avro/DataStream.hxx" "avro/DataStream.cxx"
                              "schema/RecordType.hxx"
               LINK_LIBRARIES  Avro::Avro)
