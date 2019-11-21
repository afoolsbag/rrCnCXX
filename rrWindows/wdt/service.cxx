/// \copyright Unlicense

#define _CRT_SECURE_NO_WARNINGS
#include "service.hxx"

#include <ctime>
#include <chrono>
#include <filesystem>
#include <optional>
#include <sstream>
#include <thread>
#include <vector>

#include "rrwindows/rrwindows.hxx"

using namespace std;

namespace {

struct ini_t {
    chrono::seconds check_continue_per_seconds {1s};     ///< `index.check_continue_per_seconds` s
    chrono::seconds scan_processes_per_seconds {10s};    ///< `index.scan_processes_per_seconds` s

    size_t count {0};                                    ///< `index.count`

    struct bone_t {
        bool active {true};                              ///< `boneN.active`

        filesystem::path executable_path;                ///< `boneN.executable_path`
        optional<string> executable_args;                ///< `boneN.executable_args`
        optional<filesystem::path> executable_start_in;  ///< `boneN.executable_start_in`

        string service_name;                             ///< `boneN.service_name`
        vector<string> service_args;                     ///< `boneN.service_args`

        chrono::seconds retry_per_seconds {0s};          ///< `boneN.retry_per_seconds`

        chrono::hours restart_per_days {0h};             ///< `boneN.restart_per_days`
        struct { int hour {0}; int min {0}; int sec {0}; }
        restart_time_of_day {};                          ///< `boneN.restart_time_of_day`

        // runtime data
        chrono::steady_clock::time_point next_retry_time;
        chrono::system_clock::time_point next_restart_time;
    };
    vector<bone_t> bones;
};

ini_t read_ini(filesystem::path ini_path)
{
    ini_t ini;

    ini.check_continue_per_seconds = chrono::seconds(rrwindows::read_ini(ini_path, "index", "check_continue_per_seconds", 1));
    ini.scan_processes_per_seconds = chrono::seconds(rrwindows::read_ini(ini_path, "index", "scan_processes_per_seconds", 10));
    ini.count = rrwindows::read_ini(ini_path, "index", "count", 0);

    for (size_t i = 0; i < ini.count; ++i) {
        ini_t::bone_t bone;

        bone.active = rrwindows::read_ini(ini_path, "bone" + to_string(i), "active", true);

        bone.executable_path = rrwindows::read_ini(ini_path, "bone" + to_string(i), "executable_path", "");
        if (!bone.executable_path.empty()) {
            bone.executable_args = rrwindows::read_ini(ini_path, "bone" + to_string(i), "executable_args", "");
            if (bone.executable_args->empty())
                bone.executable_args.reset();
            bone.executable_start_in = rrwindows::read_ini(ini_path, "bone" + to_string(i), "executable_start_in", "");
            if (bone.executable_start_in->empty())
                bone.executable_start_in = bone.executable_path.parent_path();
        }

        bone.service_name = rrwindows::read_ini(ini_path, "bone" + to_string(i), "service_name", "");
        if (!bone.service_name.empty()) {
            const auto args = rrwindows::read_ini(ini_path, "bone" + to_string(i), "service_args", "");
            for (auto p = args.cbegin(); p != args.cend(); ++p) {
                // 忽略所有前导空白符
                while (isspace(*++p))
                    continue;
                if (args.cend() <= p)
                    throw bad_cast();
                const auto start = p;

                // 划选字符串
                if (*p == '"') {
                    while (*++p != '"')
                        continue;
                } else {
                    while (!isspace(*++p))
                        continue;
                }
                if (args.cend() < p)
                    throw bad_cast();
                const auto end = p;

                bone.service_args.emplace_back(start, end);
            }
        }

        bone.retry_per_seconds = chrono::seconds(rrwindows::read_ini(ini_path, "bone" + to_string(i), "retry_per_seconds", 0));
        if (bone.retry_per_seconds.count()) {
            bone.next_retry_time = chrono::steady_clock::now();
        }

        bone.restart_per_days = chrono::hours(rrwindows::read_ini(ini_path, "bone" + to_string(i), "restart_per_days", 0) * 24);
        if (bone.restart_per_days.count()) {
            const auto time_of_day = rrwindows::read_ini(ini_path, "bone" + to_string(i), "restart_time_of_day", "00:00:00");
            stringstream ss {time_of_day};
            if (ss >> bone.restart_time_of_day.hour)
                if (ss.peek() == ':' && ss.ignore())
                    if (ss >> bone.restart_time_of_day.min)
                        if (ss.peek() == ':' && ss.ignore())
                            ss >> bone.restart_time_of_day.sec;

            time_t tc = time(nullptr);
            tm ts = *localtime(&tc);
            ts.tm_hour = bone.restart_time_of_day.hour;
            ts.tm_min = bone.restart_time_of_day.min;
            ts.tm_sec = bone.restart_time_of_day.sec;
            tc = mktime(&ts);

            bone.next_restart_time = chrono::system_clock::from_time_t(tc);
            if (bone.next_restart_time < chrono::system_clock::now())
                bone.next_restart_time += 24h;
        }

        if (!bone.executable_path.empty() || !bone.service_name.empty())
            ini.bones.emplace_back(bone);
    }

    return ini;
}

SERVICE_STATUS_HANDLE hStatus {nullptr};
void report_status(DWORD dwCurrentState, DWORD dwWin32ExitCode, DWORD dwWaitHint)
{
    static SERVICE_STATUS stStatus {[] {
        SERVICE_STATUS stTmp {};
        stTmp.dwServiceType = SERVICE_WIN32_OWN_PROCESS;
        stTmp.dwServiceSpecificExitCode = 0;
        return stTmp;
    }()};
    static DWORD dwCheckPoint {1};

    stStatus.dwCurrentState = dwCurrentState;

    if (dwCurrentState == SERVICE_RUNNING || dwCurrentState == SERVICE_PAUSED)
        stStatus.dwControlsAccepted = SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_PAUSE_CONTINUE | SERVICE_ACCEPT_SHUTDOWN;
    else
        stStatus.dwControlsAccepted = 0;

    stStatus.dwWin32ExitCode = dwWin32ExitCode;

    if (dwCurrentState == SERVICE_STOPPED || dwCurrentState == SERVICE_RUNNING || dwCurrentState == SERVICE_PAUSED)
        stStatus.dwCheckPoint = 0;
    else
        stStatus.dwCheckPoint = dwCheckPoint++;

    stStatus.dwWaitHint = dwWaitHint;

    if (!SetServiceStatus(hStatus, &stStatus))
        throw rrwindows::system_error_exception("SetServiceStatus failed", GetLastError());
}

bool stop_flag {false};
bool pause_flag {false};

}

namespace rrwdt {

VOID CALLBACK ServiceMain(DWORD dwNumServicesArgs, LPTSTR *lpServiceArgVectors)
{
    UNREFERENCED_PARAMETER(dwNumServicesArgs);
    UNREFERENCED_PARAMETER(lpServiceArgVectors);

    try {

        hStatus = RegisterServiceCtrlHandler(service_name, ServiceCtrlHandler);
        if (!hStatus)
            throw rrwindows::system_error_exception("RegisterServiceCtrlHandler failed", GetLastError());

        report_status(SERVICE_START_PENDING, EXIT_SUCCESS, 3000);

        const auto ini_path = rrwindows::executable_path().replace_extension(".ini");
        auto ini = read_ini(ini_path);
        if (ini.bones.empty()) {
            const auto msg = rrwindows::tstring(_T("cannot found bones in the ")).append(ini_path).append(_T(", quit the watchdog timer"));
            rrwindows::log_event(service_name, EVENTLOG_WARNING_TYPE, msg);
            report_status(SERVICE_STOPPED, EXIT_SUCCESS, 0);
            return;
        }

        report_status(SERVICE_RUNNING, EXIT_SUCCESS, 0);

        while (!stop_flag) {
            if (pause_flag) {
                this_thread::sleep_for(ini.check_continue_per_seconds);
                continue;
            }

            const auto sysnow = chrono::system_clock::now();
            const auto stenow = chrono::steady_clock::now();

            try {

                for (auto &bone : ini.bones) {
                    if (!bone.active)
                        continue;

                    if (bone.restart_per_days.count() && bone.next_restart_time < sysnow) {

                        if (!bone.executable_path.empty())
                            rrwindows::kill_executable(bone.executable_path.filename());

                        if (!bone.service_name.empty())
                            rrwindows::stop_service(bone.service_name);

                        while (bone.next_restart_time < sysnow)
                            bone.next_restart_time += bone.restart_per_days;

                        continue;
                    }

                    if (!bone.retry_per_seconds.count() || bone.next_retry_time < stenow) {

                        if (!bone.executable_path.empty() && !rrwindows::count_processes_by_name(bone.executable_path.filename()))
                            rrwindows::run_executable_as_active(bone.executable_path, bone.executable_args, bone.executable_start_in, false);

                        if (!bone.service_name.empty() && rrwindows::query_service_status(bone.service_name) == rrwindows::service_status::stopped)
                            rrwindows::start_service(bone.service_name, bone.service_args);

                        if (bone.retry_per_seconds.count())
                            while (bone.next_retry_time < stenow)
                                bone.next_retry_time += bone.retry_per_seconds;
                    }
                }

            } catch (const std::exception &e) {
                const auto tc = chrono::system_clock::to_time_t(sysnow);
                TCHAR acTimeBuf[20];
                _tcsftime(acTimeBuf, _countof(acTimeBuf), _T("%FT%T"), localtime(&tc));
                const auto msg = rrwindows::tstring(_T("an exception was caught by processes scan at ")).append(acTimeBuf).append(_T(": ")).append(rrwindows::xstring(e.what()));
                rrwindows::log_event(service_name, EVENTLOG_ERROR_TYPE, msg);

            } catch (...) {
                throw;

            }

            this_thread::sleep_for(ini.scan_processes_per_seconds);
        }

    } catch (const std::exception &e) {
        const auto msg = wstring(L"an exception was caught on the service main function: ").append(rrwindows::xstring(e.what()));
        rrwindows::log_event(service_name, EVENTLOG_ERROR_TYPE, msg);
        report_status(SERVICE_STOPPED, EXIT_FAILURE, 0);

    } catch (...) {
        rrwindows::log_event(service_name, EVENTLOG_ERROR_TYPE, _T("an unexpected exception was caught on the service main function"));
        report_status(SERVICE_STOPPED, EXIT_FAILURE, 0);

    }
}

VOID CALLBACK ServiceCtrlHandler(DWORD dwControl)
{
    switch (dwControl) {
    case SERVICE_CONTROL_STOP:
    case SERVICE_CONTROL_SHUTDOWN:
        report_status(SERVICE_STOP_PENDING, NO_ERROR, 0);
        stop_flag = TRUE;
        report_status(SERVICE_STOPPED, NO_ERROR, 0);
        break;

    case SERVICE_CONTROL_PAUSE:
        report_status(SERVICE_PAUSE_PENDING, NO_ERROR, 0);
        pause_flag = TRUE;
        report_status(SERVICE_PAUSED, NO_ERROR, 0);
        break;

    case SERVICE_CONTROL_CONTINUE:
        report_status(SERVICE_CONTINUE_PENDING, NO_ERROR, 0);
        pause_flag = FALSE;
        report_status(SERVICE_RUNNING, NO_ERROR, 0);
        break;

    case SERVICE_CONTROL_INTERROGATE:
        break;

    default:
        break;
    }
}

}
