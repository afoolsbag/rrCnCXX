# ______ _           _ _____  _____ _____  _____ _
# |  ___(_)         | /  __ \/  __ \  __ \/  ___| |
# | |_   _ _ __   __| | /  \/| /  \/ |  \/\ `--.| |
# |  _| | | '_ \ / _` | |    | |   | | __  `--. \ |
# | |   | | | | | (_| | \__/\| \__/\ |_\ \/\__/ / |____
# \_|   |_|_| |_|\__,_|\____/ \____/\____/\____/\_____/ FindCCGSL by FIGlet doom
# zhengrr
# 2018-08-13 – 2018-09-13
# The Unlicense

#.rst:
# FindCCGSL
# ---------
#
# 寻找 CCGSL(C++ Code Guidelines Support Library)。
#
# 结果变量：
# ::
#
#    CCGSL_FOUND
#    CCGSL_INCLUDE_DIRS
#
# 提示变量：
# ::
#
#    CCGSL_ROOT
#    ENV CCGSL_ROOT
#
# 预期：
# ::
#
#    v CCGSL_ROOT
#       v include
#          v gsl
#               gsl
#               ...
#       > samples
#       > tests
#         ...
#
if(CCGSL_FOUND)
  return()
endif()

# hints

set(zHints "${CCGSL_ROOT}" "$ENV{CCGSL_ROOT}")

# include

find_path(CCGSL_INCLUDE_DIR
          NAMES "gsl/gsl"
          HINTS ${zHints}
  PATH_SUFFIXES "include"
                NO_DEFAULT_PATH)
mark_as_advanced(CCGSL_INCLUDE_DIR)

set(CCGSL_INCLUDE_DIRS ${CCGSL_INCLUDE_DIR})
mark_as_advanced(CCGSL_INCLUDE_DIRS)

# package

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(CCGSL
                      DEFAULT_MSG CCGSL_INCLUDE_DIR)

# hints

if(CCGSL_FOUND)

  mark_as_advanced(CCGSL_ROOT)

else()

  set(CCGSL_ROOT "${CCGSL_ROOT}" CACHE PATH "The root directory of the CCGSL installation.")
  mark_as_advanced(CLEAR CCGSL_ROOT)

endif()
