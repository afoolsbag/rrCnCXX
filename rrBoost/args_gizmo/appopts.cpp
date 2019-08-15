/// \copyright Unlicense

#include "appopts.hpp"

#include <fstream>
#include <sstream>

#include <boost/algorithm/string.hpp>
#include <boost/dll.hpp>
#include <boost/optional/optional_io.hpp>

using namespace std;
namespace bpo = boost::program_options;

namespace rrargsgizmo {

appopts::appopts(int argc, const char *const argv[])
{
    const auto default_config_file = boost::dll::program_location().replace_extension(".cfg");
    const auto default_environment_prefix = boost::dll::program_location().stem().string() + "_";

    general_options_.add_options()
        ("help,?", bpo::bool_switch(&entries_.help), "显示帮助信息")
        ("version,!", bpo::bool_switch(&entries_.version), "显示版本信息");

    common_options_.add_options()
        ("debug", bpo::bool_switch(&entries_.debug), "调试信息")
        ("include-file,I", bpo::value(&entries_.include_files)->composing(), "包含文件")
        ("optimization-level,O", bpo::value(&entries_.optimization_level)->default_value(0), "优化级别")
        ("output-file,o", bpo::value(&entries_.output_file)->default_value("out.exe"), "输出文件")
        ("report-file", bpo::value(&entries_.report_file), "报告文件")
        ("verbosity-level,v", bpo::value(&entries_.verbosity_level)->default_value(2), "输出级别")
        ("warning-level,w", bpo::value(&entries_.warning_level)->default_value(3), "警告级别");

    hidden_options_.add_options()
        ("config-file,c", bpo::value(&entries_.config_file)->default_value(default_config_file.c_str()), "配置文件")
        ("environment-prefix,e", bpo::value(&entries_.environment_prefix)->default_value(default_environment_prefix), "环境变量前缀")
        ("input-file", bpo::value(&entries_.input_files)->composing(), "输入文件");

    parse_from_command_lice(argc, argv);
    parse_from_config_file(entries_.config_file);
    parse_from_environment(entries_.environment_prefix);
}
void appopts::print_help(std::ostream &os) const
{
    constexpr char figlet_logo[] {
        R"(            ___                _____ _                     )" "\n"
        R"(           / _ \              |  __ (_)                    )" "\n"
        R"( _ __ _ __/ /_\ \_ __ __ _ ___| |  \/_ _____ __ ___   ___  )" "\n"
        R"(| '__| '__|  _  | '__/ _` / __| | __| |_  / '_ ` _ \ / _ \ )" "\n"
        R"(| |  | |  | | | | | | (_| \__ \ |_\ \ |/ /| | | | | | (_) |)" "\n"
        R"(|_|  |_|  \_| |_/_|  \__, |___/\____/_/___|_| |_| |_|\___/ )" "\n"
        R"(                      __/ |                                )" "\n"
        R"(                     |___/                                 )" "\n"};

    os << figlet_logo
        << '\n'
        << "语法: rrArgsGizmo [选项]... <文件>...\n"
        << '\n';

    bpo::options_description desc {"选项"};
    desc.add(general_options_).add(common_options_);
    os << desc;
}

void appopts::print_options(std::ostream &os) const
{
    os << "config-file        = " << entries_.config_file << '\n';
    os << "debug              = " << entries_.debug << '\n';
    os << "environment-prefix = " << entries_.environment_prefix << '\n';
    os << "help               = " << entries_.help << '\n';

    os << "include-files      = ";
    for (const auto &item : entries_.include_files)
        os << item << "; ";
    os << '\n';

    os << "input-files        = ";
    for (const auto &item : entries_.input_files)
        os << item << "; ";
    os << '\n';

    os << "optimization-level = " << entries_.optimization_level << '\n';
    os << "output-file        = " << entries_.output_file << '\n';
    os << "report-file        = " << entries_.report_file << '\n';
    os << "verbosity-level    = " << entries_.verbosity_level << '\n';
    os << "version            = " << entries_.version << '\n';
    os << "warning-level      = " << entries_.warning_level << '\n';
}

void appopts::parse_from_command_lice(int argc, const char *const argv[])
{
    bpo::options_description opts;
    opts.add(general_options_).add(common_options_).add(hidden_options_);

    bpo::positional_options_description pos;
    pos.add("input-file", -1);

    bpo::store(bpo::command_line_parser {argc, argv}.options(opts).positional(pos).run(), vars_);
    bpo::notify(vars_);
}

void appopts::parse_from_config_file(const filesystem::path &config_file)
{
    if (!exists(config_file))
        ofstream {config_file};

    ifstream ifs {config_file};
    if (!ifs) {
        ostringstream oss;
        oss << "读取配置文件 " << config_file << " 异常";
        throw runtime_error {oss.str()};
    }

    bpo::options_description opts;
    opts.add(common_options_).add(hidden_options_);

    bpo::store(bpo::parse_config_file(ifs, opts), vars_);
    bpo::notify(vars_);
}

void appopts::parse_from_environment(const string &environment_prefix)
{
    const auto prefix_lower = boost::to_lower_copy(environment_prefix);
    const auto prefix_length = environment_prefix.length();

    const auto variables_map = [&](const string &environment_variable) -> string {
        auto tmp = boost::to_lower_copy(environment_variable);
        if (tmp.compare(0, prefix_length, prefix_lower) != 0)
            return "";
        boost::erase_head(tmp, prefix_length);
        boost::replace_all(tmp, "_", "-");
        return tmp;
    };

    bpo::options_description opts;
    opts.add(common_options_).add(hidden_options_);

    bpo::store(bpo::parse_environment(opts, variables_map), vars_);
    bpo::notify(vars_);
}

}
