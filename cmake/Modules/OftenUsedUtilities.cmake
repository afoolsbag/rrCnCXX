# zhengrr
# 2017-12-13 – 14
# The MIT License

#.rst:
# OftenUsedUtilities
# ------------------
#
# 此模块提供了若干指令，用于简化常用操作。

# .rst
# .. command:: add_subdirectory_all
#
#  包含所有子文件夹的``add_subdirectory``指令::
#
#   add_subdirectory_with_option(
#     <source directory>
#     [<initial option, default OFF>]
#   )

# .rst
# .. command:: add_subdirectory_with_option
#
#  带选项的``add_subdirectory``指令::
#
#   add_subdirectory_with_option(
#     <source directory>
#     [<initial option, default OFF>]
#   )
macro(add_subdirectory_with_option)
  if(${ARGC} GREATER 0)
    string(TOUPPER "${ARGV0}" option_name)
  elseif()
    # 参数缺失交由 add_subdirectory 指令处理
  endif()

  if(${ARGC} GREATER 1)
    set(initial_option "${ARGV1}")
  elseif()
    set(initial_option "OFF")
  endif()

  option(${option_name} "Project ${ARGV0}." ${option})
  if(${option_name})
    add_subdirectory("${ARGV0}")
  endif()
endmacro()
