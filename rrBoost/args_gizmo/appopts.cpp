/// \copyright Unlicense

#include "appopts.hpp"

#include <fstream>
#include <sstream>

#ifdef WIN32
#include <Windows.h>
#endif

#include <boost/algorithm/string.hpp>
#include <boost/dll.hpp>
#include <boost/optional/optional_io.hpp>

using namespace std;
namespace bfs = boost::filesystem;
namespace bpo = boost::program_options;

namespace rrargsgizmo {

appopts::appopts(int argc, const char *const argv[])
{
    const auto default_config_file = boost::dll::program_location().replace_extension(".cfg");
    const auto default_environment_prefix = boost::dll::program_location().stem().string() + "_";
    general_options_.add_options()
        ("help,?", bpo::bool_switch(&entries_.help), "显示帮助信息")
        ("version", bpo::bool_switch(&entries_.version), "显示版本信息");
    common_options_.add_options()
        ("debug,!", bpo::bool_switch(&entries_.debug), "启用调试");
    hidden_options_.add_options()
        ("configuration-file", bpo::value(&entries_.configuration_file)->default_value(default_config_file), "配置文件")
        ("environment-prefix", bpo::value(&entries_.environment_prefix)->default_value(default_environment_prefix), "环境变量前缀");
#//=============================================================================
#//
    common_options_.add_options()
        ("include-file,I", bpo::value(&entries_.include_files)->composing(), "包含文件")
        ("optimization-level,O", bpo::value(&entries_.optimization_level)->default_value(0), "优化级别")
        ("output-file,o", bpo::value(&entries_.output_file)->default_value("out.exe"), "输出文件")
        ("report-file", bpo::value(&entries_.report_file), "报告文件")
        ("verbosity-level,v", bpo::value(&entries_.verbosity_level)->default_value(2), "输出级别")
        ("warning-level,w", bpo::value(&entries_.warning_level)->default_value(3), "警告级别");
    hidden_options_.add_options()
        ("input-file", bpo::value(&entries_.input_files)->composing(), "输入文件");
#//
#//-----------------------------------------------------------------------------
    parse_from_command_lice(argc, argv);
    parse_from_configuration_file(entries_.configuration_file);
    parse_from_environment(entries_.environment_prefix);
}
void appopts::print_help(std::ostream &os) const
{
    const auto program_name = boost::dll::program_location().filename().string();

    os << '\n';
#//=============================================================================
#//
    os << "用法: " << program_name << " [选项]... <文件>...\n";
#//
#//-----------------------------------------------------------------------------
    os << '\n';
    bpo::options_description desc {"选项"};
    desc.add(general_options_).add(common_options_);
    os << desc;
    os << '\n';
}

void appopts::print_options(std::ostream &os) const
{
    os << '\n';
    os << "调试: \n";
    os << '\n';
    os << "  help               = " << entries_.help << '\n';
    os << "  debug              = " << entries_.debug << '\n';
    os << "  version            = " << entries_.version << '\n';
    os << "  configuration-file = " << entries_.configuration_file << '\n';
    os << "  environment-prefix = " << entries_.environment_prefix << '\n';
#//=============================================================================
#//
    os << "  include-files      = "; for (const auto &e : entries_.include_files) os << e << ' '; os << '\n';
    os << "  input-files        = "; for (const auto &e : entries_.input_files) os << e << ' '; os << '\n';
    os << "  optimization-level = " << entries_.optimization_level << '\n';
    os << "  output-file        = " << entries_.output_file << '\n';
    os << "  report-file        = " << entries_.report_file << '\n';
    os << "  verbosity-level    = " << entries_.verbosity_level << '\n';
    os << "  warning-level      = " << entries_.warning_level << '\n';
#//
#//-----------------------------------------------------------------------------
    os << '\n';
}

void appopts::parse_from_command_lice(int argc, const char *const argv[])
{
    bpo::options_description opts;
    opts.add(general_options_).add(common_options_).add(hidden_options_);
#//=============================================================================
#//
    bpo::positional_options_description pos;
    pos.add("input-file", -1);
#//
#//-----------------------------------------------------------------------------
    bpo::store(bpo::command_line_parser {argc, argv}.options(opts).positional(pos).run(), vars_);
    bpo::notify(vars_);
}

void appopts::parse_from_configuration_file(const boost::filesystem::path &configuration_file)
{
    if (!exists(configuration_file))
        ofstream {configuration_file.c_str()};

    ifstream ifs {configuration_file.c_str()};
    if (!ifs) {
        ostringstream oss;
        oss << "读取配置文件 " << configuration_file << " 异常";
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
        auto variable = boost::to_lower_copy(environment_variable);
        if (variable.compare(0, prefix_length, prefix_lower) != 0)
            return "";
        boost::erase_head(variable, prefix_length);
        boost::replace_all(variable, "_", "-");
        return variable;
    };

    bpo::options_description opts;
    opts.add(common_options_).add(hidden_options_);

    bpo::store(bpo::parse_environment(opts, variables_map), vars_);
    bpo::notify(vars_);
}

void appopts::launch_debugger()
{
#ifdef WIN32
    WCHAR acBuf[MAX_PATH];
    if (GetSystemDirectoryW(acBuf, _countof(acBuf)) == 0)
        return;
    const auto vsjitdebugger = bfs::path {acBuf} / L"vsjitdebugger.exe";
    auto cmd = vsjitdebugger.wstring() + L" -p " + to_wstring(GetCurrentProcessId());

    STARTUPINFOW stStartupInfo {};
    stStartupInfo.cb = sizeof(stStartupInfo);

    PROCESS_INFORMATION stProcInfo {};

    if (!CreateProcessW(reinterpret_cast<LPCWSTR>(vsjitdebugger.wstring().c_str()),
                        reinterpret_cast<LPWSTR>(cmd.data()),
                        nullptr,
                        nullptr,
                        FALSE,
                        0,
                        nullptr,
                        nullptr,
                        &stStartupInfo,
                        &stProcInfo))
        return;
    CloseHandle(stProcInfo.hThread);
    CloseHandle(stProcInfo.hProcess);

    while (!IsDebuggerPresent())
        Sleep(1000 / 25);

    DebugBreak();
#endif
}

}
