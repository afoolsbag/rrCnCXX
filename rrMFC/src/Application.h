//===-- Application ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 应用类。
///
/// \sa <https://docs.microsoft.com/cpp/mfc/controls-mfc>
///
/// \version 2018-09-05
/// \since 2018-04-11
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include <vector>

namespace rrMFC {

/// \brief 注册消息。
namespace RegisteredMessages {

/// \brief 定制注册消息。
extern UINT Custom;

}//namespace ResigteredMessages

/// \brief 应用消息。
namespace ApplicationMessages {

/// \brief 定制应用消息。
constexpr UINT Custom {WM_APP + 1};

}//namespace ApplicationMessages

///
/// \brief 配置。
///
struct Configurations {
    DWORD  ServiceIpaddr {0uL};
    UINT16 ServiceIpport {0u};

    BOOL StretchMatching {FALSE};
    BOOL ToneshiftMatching {FALSE};
    BOOL SharpenMatching {FALSE};
    BOOL ContrastMatching {FALSE};
    INT  Operation {-1};
    INT  Confidence {0};

    DWORD  PostgreIpaddr {0uL};
    UINT16 PostgreIpport {0u};
    DWORD  RedisIpaddr {0uL};
    UINT16 RedisIpport {0u};
    DWORD  RabbitIpaddr {0uL};
    UINT16 RabbitIpport {0u};
    DWORD  HumanIpaddr {0uL};
    UINT16 HumanIpport {0u};
    DWORD  VehicleIpaddr {0uL};
    UINT16 VehicleIpport {0u};
};

///
/// \brief 应用类。
/// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class>
///
class Application: public CWinApp {
    DECLARE_DYNAMIC(Application)

#// Constructors
public:
    /// \brief 构造函数。
    Application();

    /// \brief 析构函数。
    virtual ~Application() override;

#// Attributes
public:
    /// \brief 配置。
    Configurations Configs;

#// Operations
public:
    /// \brief 从资料读取配置。
    VOID ReadConfigsFromProfile();
    /// \brief 将配置写入资料。
    VOID WriteConfigsToProfile();

#// Overridables
public:
    /// \brief 调用以执行应用程序的一次性初始化。
    /// \deprecated 过时的。
    virtual BOOL InitApplication() override;

    /// \brief 调用以初始化应用程序或线程的新实例。
    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#initinstance>
    virtual BOOL InitInstance() override;

    /// \brief 调用以退出应用程序或线程的该实例。
    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#exitinstance>
    virtual INT ExitInstance() override;

#// Implementation
protected:
    /// \brief 控制台界面：最后命令。\n
    ///        Command Line Interface: Last Command Line.
    std::vector<CString>                                         CliLcl;
    /// \brief 控制台界面：出口标志。
    enum class CliExitType { Loop, Exit, Window, Frame, Dialog } CliExitFlag {CliExitType::Loop};

    /// \brief 控制台界面：欢迎。
    VOID CliWelcome() CONST;
    /// \brief 控制台界面：未知指令。
    VOID CliUnknownCommand() CONST;
    /// \brief 控制台界面：帮助。
    VOID CliHelp() CONST;
    /// \brief 控制台界面：状态。
    VOID CliStatus() CONST;
    /// \brief 控制台界面：按钮。
    VOID CliButton();
    /// \brief 控制台界面：窗口。
    VOID CliWindow();
    /// \brief 控制台界面：框架。
    VOID CliFrame();
    /// \brief 控制台界面：对话框。
    VOID CliDialog();
    /// \brief 控制台界面：出口。
    VOID CliExit();

#// Message Handlers
protected:

};

}//namespace rrmfc
