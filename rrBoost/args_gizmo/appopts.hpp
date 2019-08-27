//===-- Application Options -------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 应用选项
/// \sa <https://boost.org/doc/libs/1_71_0/doc/html/program_options.html>
///
/// \version 2019-08-27
/// \since 2019-08-15
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRARGSGIZMO_APPOPTS_HPP_
#define RRARGSGIZMO_APPOPTS_HPP_

#include <string>
#include <vector>

#include <boost/filesystem.hpp>
#include <boost/optional.hpp>
#include <boost/program_options.hpp>

namespace rrargsgizmo {

/// \brief Application Options
class appopts final {
private:
    struct {
        bool help {};                                // 帮助信息
        bool debug {};                               // 调试信息
        bool version {};                             // 版本信息
        boost::filesystem::path configuration_file;  // 配置文件
        std::string environment_prefix;              // 环境变量前缀
#//=============================================================================
#//
        std::vector<boost::filesystem::path> include_directories;  // 包含目录
        std::vector<boost::filesystem::path> input_files;          // 输入文件
        int optimization_level {};                                 // 优化级别
        boost::filesystem::path output_file;                       // 输出文件
        boost::optional<boost::filesystem::path> report_file;      // 报告文件
        int verbosity_level {};                                    // 输出级别
        int warning_level {};                                      // 警告级别
#//
#//-----------------------------------------------------------------------------
    } entries_;

public:
    explicit appopts(int argc, const char *const argv[]);
    [[nodiscard]] const auto *operator->() const { return &entries_; }

    void print_help(std::ostream &os) const;
    void print_options(std::ostream &os) const;

private:
    void parse_from_command_lice(int argc, const char *const argv[]);
    void parse_from_configuration_file(const boost::filesystem::path &configuration_file);
    void parse_from_environment(const std::string &environment_prefix);

    boost::program_options::options_description general_options_;
    boost::program_options::options_description common_options_;
    boost::program_options::options_description hidden_options_;

    boost::program_options::variables_map vars_;

public:
    static void launch_debugger();
};

}

#endif
