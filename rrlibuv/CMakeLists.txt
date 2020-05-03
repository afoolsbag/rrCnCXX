#            _ _ _
#           | (_) |
#  _ __ _ __| |_| |__  _   ___   __
# | '__| '__| | | '_ \| | | \ \ / / zhengrr
# | |  | |  | | | |_) | |_| |\ V /  2020-05-01 – 2020-05-01
# |_|  |_|  |_|_|_.__/ \__,_| \_/   Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

include_hunter_gate_script()

project_ex(
  rrlibuv
  TIME_AS_VERSION
  LANGUAGES C)

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)
