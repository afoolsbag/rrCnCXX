#          ______            _   __
#         |___  /           | | / /
#  _ __ _ __ / /  ___   ___ | |/ /  ___  ___ _ __   ___ _ __
# | '__| '__/ /  / _ \ / _ \|    \ / _ \/ _ \ '_ \ / _ \ '__|
# | |  | |./ /__| (_) | (_) | |\  \  __/  __/ |_) |  __/ |
# |_|  |_|\_____/\___/ \___/\_| \_/\___|\___| .__/ \___|_|
# zhengrr                                   | |
# 2018-12-29 – 2018-12-29                   |_|
# Unlicense

project(rrZooKeeper VERSION 2018.12.29 LANGUAGES C)
project_more()
compile_option(MULTIPLE_PROCESSES UTF-8 WARNING_AS_ERROR)

add_doxygen()

find_package(Check)
find_package(ZooKeeperC)

aux_source_directory_ex(zSource RECURSE)

add_executable_ex(
  ${zSource} C11
  INCLUDE_DIRECTORIES PRIVATE "./"
  LINK_LIBRARIES      PRIVATE Check::check
                              Check::compat
                              WS2_32
                              ZooKeeperC::hashtable
                              ZooKeeperC::zookeeper)
