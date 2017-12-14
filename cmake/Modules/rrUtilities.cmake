# zhengrr
# 2016-10-8 – 2017-12-14
# The MIT License

#.rst:
# rrUtilities
# -----------
#
# zhengrr's CMake Utilities.
#
# 此模块提供了若干指令，用于简化操作。
#
# 须 CMake 3.3 及以上版本。

# --------------------------------------------------------------------------

# .rst
# .. command:: add_subdirectories_all
#
#  ``add_subdirectory``的变体，将目录下的所有子目录添加到构建::
#
#   add_subdirectories_all(
#     [<parent directory of source directories>]
#     [<parent directory of binary directories>]
#     [EXCLUDE_FROM_ALL]
#   )
#
#  参数::
#
#   <parent directory of source directories> 默认为当前目录；
#   其余参数参见 add_subdirectory 指令。
macro(add_subdirectories_all)
  # TODO:
  # 判断传入参数：
  #  0 个：采用默认值；
  #  1 个：判断 ARGV0 为 <parent ... source ...> 或 EXCLUDE_FROM_ALL；
  #  2 个：判断 ARGV1 为 <parent ... binary ...> 或 EXCLUDE_FROM_ALL；
  #  3 个：略；
  # 以及健壮性处理。
endmacro()

# .rst
# .. command:: add_subdirectory_with_option
#
#  ``add_subdirectory``的变体，提供选项选择是否将子目录添加到构建::
#
#   add_subdirectory_with_option(
#     <source directory>
#     [<binary directory>]
#     [EXCLUDE_FROM_ALL]
#     [INITIAL_OPTION <OFF|ON>]
#   )
#  参数::
#
#   <initial option> 默认为 "OFF"；
#   其余参数参见 add_subdirectory 指令。
macro(add_subdirectory_with_option)
  # TODO:
  # 判断传入参数：
  #  1 个：采用默认值；
  #  2 个：判断 ARGV1 为 <binary directory> 或 EXCLUDE_FROM_ALL；
  #  3 个：判断为 <binary directory> EXCLUDE_FROM_ALL 或 INITIAL_OPTION <OFF|ON>；
  #  5 个：略；
  # 以及健壮性处理。
endmacro()
