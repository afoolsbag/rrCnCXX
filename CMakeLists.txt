# zhengrr
# 2016-6-28 – 2017-12-13
# The MIT License

cmake_minimum_required(VERSION 3.0)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules")
include("CompilerWarningLevel")
include("OftenUsedVariables")
include("OftenUsedUtilities")
include("SourceFilesUtilities")

project("rrCnCXX" VERSION 1.3.3.7 LANGUAGES NONE)
make_product_variables(AUTHORS "zhengrr" COPYRIGHT "The MIT License")

add_subdirectory_with_option("rrclang")
add_subdirectory_with_option("rrcexe")
add_subdirectory_with_option("rrclib")

add_subdirectory_with_option("rrcxxlang")
add_subdirectory_with_option("rrcxxexe")
add_subdirectory_with_option("rrcxxlib")

add_subdirectory_with_option("rrlinux")
add_subdirectory_with_option("rrlua")
add_subdirectory_with_option("rropengl")
add_subdirectory_with_option("rrwindows")

add_subdirectory_with_option("rrboost")
add_subdirectory_with_option("rrdirectx")
add_subdirectory_with_option("rrlive555")
add_subdirectory_with_option("rrmfc")
add_subdirectory_with_option("rrqt")

install(DIRECTORY "dzns" DESTINATION ".")
install(DIRECTORY "docs" DESTINATION ".")
install(DIRECTORY "spls" DESTINATION ".")
install(FILES "LICENSE.txt" DESTINATION ".")
