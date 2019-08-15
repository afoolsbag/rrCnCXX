//===-- Application Options -------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 应用选项
/// \sa <https://boost.org/doc/libs/1_70_0/doc/html/program_options.html>
///
/// \version 2019-08-15
/// \since 2019-08-15
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRARGSGIZMO_APPOPTS_HPP_
#define RRARGSGIZMO_APPOPTS_HPP_

#include <filesystem>
#include <ostream>
#include <string>
#include <vector>

#include <boost/optional.hpp>
#include <boost/program_options.hpp>

namespace rrargsgizmo {

/// \brief Application Options
class appopts final {
public:
    struct entries_t {
        std::filesystem::path config_file;                   // 配置文件
        bool debug {};                                       // 调试信息
        std::string environment_prefix;                      // 环境变量前缀
        bool help {};                                        // 帮助信息
        std::vector<std::filesystem::path> include_files;    // 包含文件
        std::vector<std::filesystem::path> input_files;      // 输入文件
        int optimization_level {};                           // 优化级别
        std::filesystem::path output_file;                   // 输出文件
        boost::optional<std::filesystem::path> report_file;  // 报告文件
        int verbosity_level {};                              // 输出级别
        bool version {};                                     // 版本信息
        int warning_level {};                                // 警告级别
    };

    explicit appopts(int argc, const char *const argv[]);
    [[nodiscard]] const entries_t *operator->() const { return &entries_; }

    void print_help(std::ostream &os) const;
    void print_options(std::ostream &os) const;

private:
    void parse_from_command_lice(int argc, const char *const argv[]);
    void parse_from_config_file(const std::filesystem::path &config_file);
    void parse_from_environment(const std::string &environment_prefix);

    boost::program_options::options_description general_options_;
    boost::program_options::options_description common_options_;
    boost::program_options::options_description hidden_options_;

    boost::program_options::variables_map vars_;
    entries_t entries_;
};

}

#endif
