#            ____                  _
#  _ __ _ __| __ )  ___   ___  ___| |_
# | '__| '__|  _ \ / _ \ / _ \/ __| __|
# | |  | |  | |_) | (_) | (_) \__ | |_
# |_|  |_|  |____/ \___/ \___/|___/\__|
# zhengrr             rrBoost by FIGlet
# 2016-10-27 – 2018-03-31
# The MIT License

project("rrBoost" VERSION 2018.3.22 LANGUAGES CXX)
project_variables()
highest_warning_level()

if(NOT Boost_FOUND)
  find_package(Boost 1.66.0
    COMPONENTS
      program_options)
  if(NOT Boost_FOUND)
    set(BOOST_ROOT "${BOOST_ROOT}" CACHE PATH "The root directory of the Boost installation.")
  endif()
endif()

facile_add_doxygen()

facile_add_executable(SUBNAME "hello_boost"
  "main.cxx")
