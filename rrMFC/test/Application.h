//===-- Application ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 应用类。
///
/// \sa <https://docs.microsoft.com/cpp/mfc/controls-mfc>
///
/// \version 2018-09-14
/// \since 2018-04-11
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include <vector>

namespace rrMFC {
namespace Test {

/// \brief 注册消息。
namespace RegisteredMessages {

/// \brief 定制注册消息。
extern unsigned Custom;

extern unsigned HostMove;

extern unsigned GuestCreate;
extern unsigned GuestSize;
extern unsigned GuestShowWindow;
extern unsigned GuestDestroy;

}//namespace ResigteredMessages

/// \brief 应用消息。
namespace ApplicationMessages {

/// \brief 定制应用消息。
constexpr unsigned Custom {WM_APP + 1};

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
    ~Application() override final;

#// Attributes
public:
    /// \brief 配置。
    Configurations Configs;

#// Operations
public:
    /// \brief 从资料读取配置。
    void ReadConfigsFromProfile();
    /// \brief 将配置写入资料。
    void WriteConfigsToProfile();

#// Overridables
public:
    /// \brief 调用以执行应用程序的一次性初始化。
    /// \deprecated 过时的。
    BOOL InitApplication() override final;

    /// \brief 调用以初始化应用程序或线程的新实例。
    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#initinstance>
    BOOL InitInstance() override final;

    /// \brief 调用以退出应用程序或线程的该实例。
    /// \sa <https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#exitinstance>
    int ExitInstance() override final;

#// Implementation
protected:
    /// \brief 控制台界面：最后命令行。\n
    ///        Command Line Interface: Last Command Line.
    std::vector<CString>                                         CliLcl;
    /// \brief 控制台界面：出口标志。
    enum class CliExitType { Loop, Exit, Window, Frame, Dialog } CliExitFlag {CliExitType::Loop};

    void CliWelcome() const;         ///< 控制台界面：欢迎。
    void CliUnknownCommand() const;  ///< 控制台界面：未知命令。
    void CliHelp() const;            ///< 控制台界面：帮助。
    void CliStatus() const;          ///< 控制台界面：状态。

    void CliButtonDialog() const;  ///< 控制台界面：按钮对话框。
    void CliEditDialog() const;    ///< 控制台界面：编辑对话框。
    void CliListDialog() const;    ///< 控制台界面：列表对话框。
    void CliTabDialog() const;     ///< 控制台界面：标签页对话框。
    void CliTreeDialog() const;    ///< 控制台界面：树对话框。

    void CliDdxDialog() const;
    void CliProgressBox() const;
    void CliPropertySheet();

    void CliWindow();  ///< 控制台界面：窗口。
    void CliFrame();   ///< 控制台界面：框架。
    void CliDialog();  ///< 控制台界面：对话框。
    void CliExit();    ///< 控制台界面：出口。

#// Message Handlers
protected:

};

}//namespace Test
}//namespace rrmfc
