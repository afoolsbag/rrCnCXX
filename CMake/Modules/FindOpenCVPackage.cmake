# ______ _           _ _____                  _____ _   _______          _
# |  ___(_)         | |  _  |                /  __ \ | | | ___ \        | |
# | |_   _ _ __   __| | | | |_ __   ___ _ __ | /  \/ | | | |_/ /_ _  ___| | ____ _  __ _  ___
# |  _| | | '_ \ / _` | | | | '_ \ / _ \ '_ \| |   | | | |  __/ _` |/ __| |/ / _` |/ _` |/ _ \
# | |   | | | | | (_| \ \_/ / |_) |  __/ | | | \__/\ \_/ / | | (_| | (__|   < (_| | (_| |  __/
# \_|   |_|_| |_|\__,_|\___/| .__/ \___|_| |_|\____/\___/\_|  \__,_|\___|_|\_\__,_|\__, |\___|
# zhengrr                   | |                    FindOpenCVPackage by FIGlet doom __/ |
# 2018-06-04 – 2018-09-06   |_|                                                    |___/
# The Unlicense

#.rst:
# FindOpenCVPackage
# -----------------
#
# 寻找 OpenCV 包。
#
# 结果变量：
# ::
#
#    OpenCVPackage_FOUND
#    OpenCVPackage_PREFIX_PATH
#
# 提示变量：
# ::
#
#    OpenCV_ROOT
#    ENV OpenCV_ROOT
#
if(OpenCVPackage_FOUND)
  return()
endif()

# hints

set(zHints "${OpenCV_ROOT}" "$ENV{OpenCV_ROOT}")

# prefix

find_path(OpenCVPackage_PREFIX_PATH
    NAMES "OpenCVConfig.cmake"
    HINTS ${zHints}
          NO_DEFAULT_PATH)
mark_as_advanced(OpenCVPackage_PREFIX_PATH)

# package

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(OpenCVPackage
                      DEFAULT_MSG OpenCVPackage_PREFIX_PATH)

if(OpenCVPackage_FOUND)

  # append

  if(NOT OpenCVPackage_PREFIX_PATH IN_LIST CMAKE_PREFIX_PATH)
    list(APPEND CMAKE_PREFIX_PATH "${OpenCVPackage_PREFIX_PATH}")
  endif()

  mark_as_advanced(OpenCV_ROOT)

else()

  # hints

  set(OpenCV_ROOT "${OpenCV_ROOT}" CACHE PATH "The root directory of the OpenCV installation.")
  mark_as_advanced(CLEAR OpenCV_ROOT)

endif()
