#            ____                  _
#  _ __ _ __| __ )  ___   ___  ___| |_
# | '__| '__|  _ \ / _ \ / _ \/ __| __|
# | |  | |  | |_) | (_) | (_) \__ | |_
# |_|  |_|  |____/ \___/ \___/|___/\__| rrBoost by FIGlet
# zhengrr
# 2016-10-27 – 2018-10-22
# The Unlicense

cmake_policy(SET CMP0074 NEW) #3.12+

project(rrBoost VERSION 2018.10.15 LANGUAGES CXX)
project_more()
compile_option(MULTIPLE_PROCESSES UTF-8)

facile_add_doxygen()

find_package(CGSL)
find_package(Boost)
if(NOT Boost_FOUND)
  set(BOOST_ROOT "${BOOST_ROOT}" CACHE PATH "The root directory of the Boost installation.")
endif()

aux_source_directory_ex(zSource RECURSE)
facile_add_gtest_executable(
  NAME "test"
  ${zSource}
  CXX17
  INCLUDE_DIRECTORIES PRIVATE "./"
  LINK_DIRECTORIES    PRIVATE ${Boost_LIBRARY_DIRS}
  LINK_LIBRARIES      PRIVATE CGSL::CGSL
                              Boost::boost)
