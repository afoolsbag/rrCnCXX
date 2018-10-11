#            _____ ___  ___      _
#           /  __ \|  \/  |     | |
#  _ __ _ __| /  \/| .  . | __ _| | _____
# | '__| '__| |    | |\/| |/ _` | |/ / _ \
# | |  | |  | \__/\| |  | | (_| |   <  __/
# |_|  |_|   \____/\_|  |_/\__,_|_|\_\___| rrCMake by FIGlet doom
# zhengrr
# The Unlicense

include_guard()

#.rst:
# rrCMake
# -------
#
# zhengrr's CMake Utilities.

#.res:
# .. command:: rrcmake_include_module_files
function(rrcmake_include_module_files)
  file(GLOB zModuleFiles "${CMAKE_CURRENT_LIST_DIR}/rrCMake/*.cmake")
  foreach(sModuleFile IN LISTS zModuleFiles)
    include("${sModuleFile}")
  endforeach()
endfunction()

rrcmake_include_module_files()
