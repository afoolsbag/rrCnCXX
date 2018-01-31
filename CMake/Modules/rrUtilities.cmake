#            _       ____ __  __       _          _   _ _   _ _ _ _   _
#  _ __ _ __( ___   / ___|  \/  | __ _| | _____  | | | | |_(_| (_| |_(_) ___ ___
# | '__| '__|/ __| | |   | |\/| |/ _` | |/ / _ \ | | | | __| | | | __| |/ _ / __|
# | |  | |   \__ \ | |___| |  | | (_| |   |  __/ | |_| | |_| | | | |_| |  __\__ \
# |_|  |_|   |___/  \____|_|  |_|\__,_|_|\_\___|  \___/ \__|_|_|_|\__|_|\___|___/
# zhengrr                                         rr's CMake Utilities by FIGlet
# The MIT License

#.rst:
# rrUtilities
# -----------
#
# zhengrr's CMake Utilities.
#
# 参见：
#
# + `"foreach" <https://cmake.org/cmake/help/latest/command/foreach>`_. *CMake Documentation*.
# + `"include" <https://cmake.org/cmake/help/latest/command/include>`_. *CMake Documentation*.
#

function(rr_utilities)
  file(GLOB zModuleFiles "${CMAKE_CURRENT_LIST_DIR}/rrUtilities/*.cmake")
  foreach(sModuleFile IN LISTS zModuleFiles)
    include("${sModuleFile}")
  endforeach()
endfunction()

rr_utilities()
