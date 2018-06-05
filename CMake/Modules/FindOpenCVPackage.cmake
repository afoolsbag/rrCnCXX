# ______ _           _ _____                  _____ _   _______          _
# |  ___(_)         | |  _  |                /  __ \ | | | ___ \        | |
# | |_   _ _ __   __| | | | |_ __   ___ _ __ | /  \/ | | | |_/ /_ _  ___| | ____ _  __ _  ___
# |  _| | | '_ \ / _` | | | | '_ \ / _ \ '_ \| |   | | | |  __/ _` |/ __| |/ / _` |/ _` |/ _ \
# | |   | | | | | (_| \ \_/ / |_) |  __/ | | | \__/\ \_/ / | | (_| | (__|   < (_| | (_| |  __/
# \_|   |_|_| |_|\__,_|\___/| .__/ \___|_| |_|\____/\___/\_|  \__,_|\___|_|\_\__,_|\__, |\___|
# zhengrr                   | |                    FindOpenCVPackage by FIGlet doom __/ |
# 2018-06-04 – 04           |_|                                                    |___/
# The MIT License

#.rst:
# FindOpenCVPackage
# -----------------
#
# 寻找OpenCV包。
#
# 缓存：
# ::
#
#    OpenCV_ROOT_DIR
#    ENV OPENCVDIR
#
# 影响：
# ::
#
#    OpenCVPackage_FOUND
#    OpenCVPackage_PREFIX_PATH
#
# 参见：
#
if(OpenCVPackage_FOUND)
  return()
endif()

set(zHints "${OpenCV_ROOT_DIR}" "$ENV{OPENCVDIR}")

find_path(OpenCV_ROOT_DIR
  NAMES "OpenCVConfig.cmake"
  HINTS ${zHints}
        NO_DEFAULT_PATH)
mark_as_advanced(OpenCV_ROOT_DIR)

find_path(OpenCVPackage_PREFIX_PATH
  NAMES "OpenCVConfig.cmake"
  HINTS ${zHints}
        NO_DEFAULT_PATH)
mark_as_advanced(OpenCVPackage_PREFIX_PATH)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(OpenCVPackage
                      DEFAULT_MSG OpenCV_ROOT_DIR
                                  OpenCVPackage_PREFIX_PATH)

if(OpenCVPackage_FOUND)
  if(NOT OpenCVPackage_PREFIX_PATH IN_LIST CMAKE_PREFIX_PATH)
    list(APPEND CMAKE_PREFIX_PATH "${OpenCVPackage_PREFIX_PATH}")
  endif()
else()
  set(OpenCV_ROOT_DIR "${OpenCV_ROOT_DIR}" CACHE PATH "The root directory of the OpenCV installation.")
  mark_as_advanced(CLEAR OpenCV_ROOT_DIR)
endif()
