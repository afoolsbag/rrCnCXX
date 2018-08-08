//===-- Singleton -----------------------------------------------*- C++ -*-===//
///
/// \defgroup gSingleton 单例模式
/// \ingroup gDzn
///
/// \version 2018-08-07
/// \since 2016-10-18
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#include "rrCXX/ver.hxx"

#if !N2660
#include <mutex>
#endif

#include <gtest/gtest.h>

namespace rrcxx {
namespace dzn {

/// @addtogroup gSingleton
/// @{

///
/// \brief 饿汉单例模式。
///
class EagerSingleton {
private:
    /// \brief 默认构造函数。
    explicit EagerSingleton() = default;
public:
    /// \brief 复制构造函数。
    explicit EagerSingleton(const EagerSingleton &) = delete;
    /// \brief 复制赋值运算。
    EagerSingleton &operator=(const EagerSingleton &) = delete;
    /// \brief 获取实例。
    static EagerSingleton &Instance();
};

EagerSingleton &EagerSingleton::Instance()
{
    static EagerSingleton *instancePointer {};
    if (!instancePointer) {
        instancePointer = new EagerSingleton();
    }
    return *instancePointer;
}

namespace {
EagerSingleton &sInitializeEarly = EagerSingleton::Instance();
}// namespace

///
/// \brief 懒汉单例模式。
///
class LazySingleton {
private:
    /// \brief 默认构造函数。
    explicit LazySingleton() = default;
public:
    /// \brief 复制构造函数。
    explicit LazySingleton(const LazySingleton &) = delete;
    /// \brief 复制赋值运算。
    LazySingleton &operator=(const LazySingleton &) = delete;
    /// \brief 获取实例。
    static LazySingleton &Instance();
};

LazySingleton &LazySingleton::Instance()
{
#if N2660
    static LazySingleton inst;
    return inst;

#else
    static LazySingleton *pInst {};
    static std::mutex mutex;
    mutex.lock();
    {
        if (!pInst)
            pInst = new LazySingleton;
    }
    mutex.unlock();
    return *pInst;

#endif
};

/// \brief 单例模式。
/// \sa \ref sCxxAndDclp
TEST(singleton, preliminary)
{
    auto &eagerSingleton1 = EagerSingleton::Instance();
    auto &eagerSingleton2 = EagerSingleton::Instance();
    ASSERT_EQ(&eagerSingleton1, &eagerSingleton2);

    auto &lazySingleton1 = LazySingleton::Instance();
    auto &lazySingleton2 = LazySingleton::Instance();
    ASSERT_EQ(&lazySingleton1, &lazySingleton2);
}

/// @}

}//namespace dzn
}//namespace rrcxx
