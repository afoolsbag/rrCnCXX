#          ______            _   __
#         |___  /           | | / /
#  _ __ _ __ / /  ___   ___ | |/ /  ___  ___ _ __   ___ _ __
# | '__| '__/ /  / _ \ / _ \|    \ / _ \/ _ \ '_ \ / _ \ '__|
# | |  | |./ /__| (_) | (_) | |\  \  __/  __/ |_) |  __/ |
# |_|  |_|\_____/\___/ \___/\_| \_/\___|\___| .__/ \___|_|
# zhengrr                                   | |
# 2018-12-29 – 2019-01-03                   |_|
# Unlicense

project(rrZooKeeper VERSION 2018.01.03 LANGUAGES C)
project_more()
compile_option(MULTIPLE_PROCESSES UTF-8 WARNING_AS_ERROR)

add_doxygen()

find_package(ZooKeeperC)

add_executable_ex(
  NAME SyncCRUD "sync_crud_test.c" FLAT_GROUP C11
  INCLUDE_DIRECTORIES PRIVATE "./"
  LINK_LIBRARIES      PRIVATE ZooKeeperC::zookeeper)

add_executable_ex(
  NAME AsyncCRUD "async_crud_test.c" FLAT_GROUP C11
  INCLUDE_DIRECTORIES PRIVATE "./"
  LINK_LIBRARIES      PRIVATE ZooKeeperC::zookeeper)

add_executable_ex(
  NAME Watch "watch_test.c" FLAT_GROUP C11
  INCLUDE_DIRECTORIES PRIVATE "./"
  LINK_LIBRARIES      PRIVATE ZooKeeperC::zookeeper)

add_executable_ex(
  NAME EphSeq "eph_seq_test.c" FLAT_GROUP C11
  INCLUDE_DIRECTORIES PRIVATE "./"
  LINK_LIBRARIES      PRIVATE ZooKeeperC::zookeeper)
