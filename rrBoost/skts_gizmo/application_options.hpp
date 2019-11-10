//===-- Application Options -------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 应用选项
/// \sa <https://boost.org/doc/libs/master/libs/program_options/>
///
/// \version 2019-11-10
/// \since 2019-08-15
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef APPLICATION_OPTIONS_HPP_
#define APPLICATION_OPTIONS_HPP_

#include <cstdint>
#include <string>
#include <vector>

#include <boost/filesystem.hpp>
#include <boost/optional.hpp>
#include <boost/program_options.hpp>

/// \brief Application Options
class application_options final {
private:
    struct {
        bool help;                                   ///< 帮助信息
        bool debug;                                  ///< 调试信息
        bool version;                                ///< 版本信息
        boost::filesystem::path configuration_file;  ///< 配置文件
        std::string environment_prefix;              ///< 环境变量前缀
#//=============================================================================
#//
        boost::filesystem::path  logs_directory;      ///< 日志目录
        std::uint16_t            export_port;         ///< 导出端口（监听端口）
        std::vector<std::string> parameters;          ///< 参数
#//
#//-----------------------------------------------------------------------------
    } entries_;

public:
    explicit application_options(int argc, const char *const argv[]);
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

    boost::program_options::variables_map variables_map_;

public:
    static void launch_debugger();
};

#endif
