#            ____                  _
#  _ __ _ __| __ )  ___   ___  ___| |_
# | '__| '__|  _ \ / _ \ / _ \/ __| __|
# | |  | |  | |_) | (_) | (_) \__ | |_
# |_|  |_|  |____/ \___/ \___/|___/\__|
# zhengrr             rrBoost by FIGlet
# 2016-10-27 – 2018-04-02
# The MIT License

project("rrBoost" VERSION 2018.4.2 LANGUAGES CXX)
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

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})
facile_add_executable(SUBNAME "ProgOpts" TGTNAMEVAR sTgtName
  "prog_opts/main.cxx")
