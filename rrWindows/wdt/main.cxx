/// \copyright Unlicense

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include "rrwindows/rrwindows.hxx"

#include "service.hxx"

using namespace std;

INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
    UNREFERENCED_PARAMETER(envp);
    try {
        if (1 < argc) {
            const auto status = rrwindows::query_service_status(rrwdt::service_name);

            if (rrwindows::strcmp(argv[1], _T("install")) == 0) {
                rrwindows::install_service(rrwdt::service_name, rrwdt::service_display, rrwdt::service_description, rrwindows::executable_path());

            } else if (rrwindows::strcmp(argv[1], _T("remove")) == 0) {
                if (status != rrwindows::service_status::not_exist && status != rrwindows::service_status::stopped)
                    rrwindows::stop_service(rrwdt::service_name);
                rrwindows::remove_service(rrwdt::service_name);

            } else if (rrwindows::strcmp(argv[1], _T("start")) == 0) {
                if (status == rrwindows::service_status::not_exist)
                    rrwindows::install_service(rrwdt::service_name, rrwdt::service_display, rrwdt::service_description, rrwindows::executable_path());
                rrwindows::start_service(rrwdt::service_name);

            } else if (rrwindows::strcmp(argv[1], _T("stop")) == 0) {
                rrwindows::stop_service(rrwdt::service_name);

            } else if (rrwindows::strcmp(argv[1], _T("pause")) == 0) {
                rrwindows::pause_service(rrwdt::service_name);

            } else if (rrwindows::strcmp(argv[1], _T("continue")) == 0) {
                rrwindows::continue_service(rrwdt::service_name);

            } else if (rrwindows::strcmp(argv[1], _T("restart")) == 0) {
                if (status != rrwindows::service_status::stopped)
                    rrwindows::stop_service(rrwdt::service_name);
                rrwindows::start_service(rrwdt::service_name);

            } else {
                rrwindows::puts(_T("使用方法："));
                rrwindows::printf(_T("%s install \t安装服务。\n"), argv[0]);
                rrwindows::printf(_T("%s remove  \t停止并卸载服务。\n"), argv[0]);
                rrwindows::printf(_T("%s start   \t启动服务。\n"), argv[0]);
                rrwindows::printf(_T("%s stop    \t停止服务。\n"), argv[0]);
                rrwindows::printf(_T("%s pause   \t暂停服务。\n"), argv[0]);
                rrwindows::printf(_T("%s continue\t继续服务。\n"), argv[0]);
                rrwindows::printf(_T("%s restart \t重启服务。\n"), argv[0]);

            }
            return EXIT_SUCCESS;
        }

        SERVICE_TABLE_ENTRY stSerTbl[] {
            {const_cast<LPTSTR>(rrwdt::service_name), rrwdt::ServiceMain},
            {nullptr, nullptr}
        };

        if (!StartServiceCtrlDispatcher(stSerTbl)) {
            auto e = rrwindows::system_error_exception("StartServiceCtrlDispatcher failed", GetLastError());
            rrwindows::log_event(rrwdt::service_name, EVENTLOG_ERROR_TYPE, rrwindows::xstring(e.what()));
            throw move(e);
        }

        return EXIT_SUCCESS;

    } catch (const std::exception &e) {
        rrwindows::eprintf(_T("an exception was caught on the main function: %s"), rrwindows::xstring(e.what()).c_str());
        return EXIT_FAILURE;

    } catch (...) {
        rrwindows::eputs(_T("an unexpected exception was caught on the main function"));
        return EXIT_FAILURE;

    }
}
