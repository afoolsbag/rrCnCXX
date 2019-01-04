# ______ _           _______    _ _   __       __ _         
# |  ___(_)         | | ___ \  | | | / /      / _| |        
# | |_   _ _ __   __| | |_/ /__| | |/ /  __ _| |_| | ____ _ 
# |  _| | | '_ \ / _` |    // _` |    \ / _` |  _| |/ / _` | zhengrr
# | |   | | | | | (_| | |\ \ (_| | |\  \ (_| | | |   < (_| | 2019-01-03 – 2019-01-03
# \_|   |_|_| |_|\__,_\_| \_\__,_\_| \_/\__,_|_| |_|\_\__,_| Unlicense

if(NOT COMMAND get_toolset_architecture_address_model_tag)
  include("${CMAKE_CURRENT_LIST_DIR}/rrCMake/LibraryTag.cmake")
endif()

#.rst:
# FindRdKafka
# -----------
#
# Find the `librdkafka <https://github.com/edenhill/librdkafka>`_ headers and libraries.
