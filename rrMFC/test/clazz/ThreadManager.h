//===-- Thread Manager ------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 线程管理者。
///
/// \version 2018-06-15
/// \since 2018-06-14
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

class ThreadManager: public CObject {
    DECLARE_DYNAMIC(ThreadManager)

#// Constructors
public:
    /// \brief 构造函数。
    ThreadManager() = default;
    /// \brief 析构函数。
    virtual ~ThreadManager() override = default;

#// Attributes
public:

#// Operations
public:
    /// \brief 启动线程。
    inline VOID StartThread()
    {
        if (Thread != NULL)
            return;
        ThreadLoopFlag = TRUE;
        Thread = AfxBeginThread(ThreadWrapper, this);
    }

    /// \brief 等待线程。
    inline VOID WaitThread(CONST DWORD timeOut = INFINITE)
    {
        if (Thread == NULL)
            return;
        WaitForSingleObject(Thread->m_hThread, timeOut);
        Thread = NULL;
    }

    /// \brief 停止线程。
    inline VOID StopThread()
    {
        if (Thread == NULL)
            return;
        ThreadLoopFlag = FALSE;
        Thread = NULL;
    }

    /// \brief 停止并等待线程。
    inline VOID StopWaitThread(CONST DWORD timeOut = INFINITE)
    {
        if (Thread == NULL)
            return;
        ThreadLoopFlag = FALSE;
        WaitForSingleObject(Thread->m_hThread, timeOut);
        Thread = NULL;
    }

#// Overridables
public:

#// Implementation
protected:
    CWinThread * Thread = NULL;           ///< 线程对象。
    BOOL         ThreadLoopFlag = FALSE;  ///< 线程循环标志。

    /// \brief 线程函数。
    UINT CALLBACK ThreadFunction(LPVOID pParam)
    {
        UNUSED_ALWAYS(pParam);
        while (ThreadLoopFlag) {
            // 做一些事
        }
        return EXIT_SUCCESS;
    }

    /// \brief 线程启动包装函数。
    static UINT AFX_CDECL ThreadWrapper(LPVOID pObject)
    {
        ThreadManager *CONST self = reinterpret_cast<ThreadManager *>(pObject);
        ASSERT(self && self->IsKindOf(RUNTIME_CLASS(ThreadManager)));
        return self->ThreadFunction(NULL);
    }

#// Message Handlers
protected:

};
