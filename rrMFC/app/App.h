//===-- Application ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 应用（类）。
///
/// \version 2018-06-23
/// \since 2018-04-11
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include <vector>

///
/// \brief 应用（类）。
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class
///
class Application: public CWinApp {

#// Constructors
public:
    /// \brief 构造函数。
    Application();

    /// \brief 析构函数。
    virtual ~Application() override;

#// Attributes
public:

#// Operations
public:

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
    /// \sa <https://docs.microsoft.com/windows/console/handlerroutine>
    static BOOL WINAPI HandlerRoutine(DWORD dwCtrlType);

    /// \brief 符记化命令行（按空白符）。
    static std::vector<CString> TokenizeCommandLine(CONST CString &commandLine);

    /// \brief 命令匹配（单匹配）。
    static inline BOOL CommandMatches(CONST CString &command, CONST CString &target)
    {
        if (!command.CompareNoCase(target))
            return TRUE;
        return FALSE;
    }

    /// \brief 命令匹配（双匹配）。
    static inline BOOL CommandMatches(CONST CString &command, CONST CString &target, CONST CString &target2)
    {
        if (!command.CompareNoCase(target))
            return TRUE;
        if (!command.CompareNoCase(target2))
            return TRUE;
        return FALSE;
    }

    /// \brief 命令匹配（三匹配）。
    static inline BOOL CommandMatches(CONST CString &command, CONST CString &target, CONST CString &target2, CONST CString &target3)
    {
        if (!command.CompareNoCase(target))
            return TRUE;
        if (!command.CompareNoCase(target2))
            return TRUE;
        if (!command.CompareNoCase(target3))
            return TRUE;
        return FALSE;
    }

    /// \brief 清空控制台，并显示欢迎信息。
    static VOID ShowHello();
    /// \brief 显示未知信息。
    static VOID ShowUnknown(CONST std::vector<CString> &tokens);
    /// \brief 显示帮助信息。
    static VOID ShowHelp(CONST std::vector<CString> &tokens);
    /// \brief 显示状态信息。
    static VOID ShowStatus(CONST std::vector<CString> &tokens);

#// Message Handlers
protected:

};
