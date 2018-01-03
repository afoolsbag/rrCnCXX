#             ____           _
#  _ __ _ __ / _____  ___  _| |    __ _ _ __   __ _ _   _  __ _  __ _  ___
# | '__| '__| |   \ \/ \ \/ | |   / _` | '_ \ / _` | | | |/ _` |/ _` |/ _ \
# | |  | |  | |___ >  < >  <| |__| (_| | | | | (_| | |_| | (_| | (_| |  __/
# |_|  |_|   \____/_/\_/_/\_|_____\__,_|_| |_|\__, |\__,_|\__,_|\__, |\___|
# zhengrr                                     |___/             |___/
# 2016-10-13 – 2018-1-2                             rrCxxLanguage by FIGlet
# The MIT License

project("rrCxxLanguage" LANGUAGES CXX)
set_project_extra_variables()

adjust_compiler_warning_level_to_highest()

quick_add_doxygen_with_option()

enable_testing()
quick_aux_source_directory(sourceFiles RECURSE CXX)
quick_add_googletest_with_option(sourceFiles)
