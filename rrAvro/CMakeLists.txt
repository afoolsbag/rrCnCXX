#             _
#  _ __ _ __ / \__   ___ __ ___
# | '__| '__/ _ \ \ / | '__/ _ \
# | |  | | / ___ \ V /| | | (_) |
# |_|  |_|/_/   \_\_/ |_|  \___/
# zhengrr        rrAvro by FIGlet
# 2018-04-02 – 2018-04-02
# The MIT License

project("rrAvro" VERSION 2018.4.2 LANGUAGES CXX)
project_variables()
highest_warning_level()

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

facile_add_executable(SUBNAME "Abc"
  "abc.cxx" LINKS Avro::Avro)
