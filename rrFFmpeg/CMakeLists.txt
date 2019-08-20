#          ____________
#          |  ___|  ___|
# _ __ _ __| |_  | |_ _ __ ___  _ __   ___  __ _
#| '__| '__|  _| |  _| '_ ` _ \| '_ \ / _ \/ _` |
#| |  | |  | |   | | | | | | | | |_) |  __/ (_| |
#|_|  |_|  \_|   \_| |_| |_| |_| .__/ \___|\__, | zhengrr
#                              | |          __/ | 2019-09-19 – 2019-08-19
#                              |_|         |___/  Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project_ex(
  rrFFmpeg
  TIME_AS_VERSION
  LANGUAGES C CXX)

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)

find_package(FFmpeg)

aux_source_directory_ex("." zSrc RECURSE)
add_executable_con(
  rrFFmpegGFS         ${zSrc}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "."
  LINK_LIBRARIES      PRIVATE FFmpeg::avcodec)
