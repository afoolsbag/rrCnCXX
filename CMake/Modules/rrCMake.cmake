#            _____ ___  ___      _
#           /  __ \|  \/  |     | |
#  _ __ _ __| /  \/| .  . | __ _| | _____
# | '__| '__| |    | |\/| |/ _` | |/ / _ \ zhengrr
# | |  | |  | \__/\| |  | | (_| |   <  __/ 2016-10-08 – 2019-04-22
# |_|  |_|   \____/\_|  |_/\__,_|_|\_\___| Unlicense

#.rst
# rrCMake
# -------
#
# zhengrr's CMake Utilities.

cmake_minimum_required(VERSION 3.10)
cmake_policy(VERSION 3.10)

include_guard()

# .ret
# .. command:: rrcmake_include_module_files
function(rrcmake_include_module_files)
  file(GLOB zModuleFiles "${CMAKE_CURRENT_LIST_DIR}/rrCMake/*.cmake")
  foreach(sModuleFile IN LISTS zModuleFiles)
    include("${sModuleFile}")
  endforeach()
endfunction()

rrcmake_include_module_files()
