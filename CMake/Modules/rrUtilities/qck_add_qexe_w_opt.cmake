# zhengrr
# 2018-1-30
# The MIT License

# .rst
# .. command:: quick_add_qt_executable_with_option
#
#    简便生成可执行文件::
#
#       quick_add_qt_executable_with_option(
#         [SUBNAME subname]
#         [WIN32]
#         [C90 | C99 | C11]
#         [CXX98 | CXX11 | CXX14 | CXX17]
#         [AUTOMOC] [AUTOUIC] [AUTORCC]
#         SOURCE_FILES <source>...
#         LINK_LIBRARIES <librarys>...
#       )
#
#    选项名形如 ``<PROJECT_NAME_UPPER>[_<subname_upper>]_COMPILE_QTEXE``
#
#    目标名形如 ``<PROJECT_NAME_LOWER>[_<subname_lower>]_qtexe``
#
#    参见
#
#    + `add_executable <https://cmake.org/cmake/help/latest/command/add_executable>`_
#    + `set_target_properties <https://cmake.org/cmake/help/latest/command/set_target_properties>`_
#    + `C_STANDARD <https://cmake.org/cmake/help/latest/prop_tgt/C_STANDARD>`_
#    + `CXX_STANDARD <https://cmake.org/cmake/help/latest/prop_tgt/CXX_STANDARD>`_
#
function(quick_add_qt_executable_with_option)

endfunction()