//===-- Singleton -----------------------------------------------*- C++ -*-===//
///
/// \defgroup gSingleton 单例
/// \ingroup gDzn
///
/// 单例设计模式：
///
/// 意图保证一个类仅有一个实例，并提供一个访问它的全局访问点。
///
/// > + 对唯一实例的受控访问
/// > + 缩小命名空间
/// > + 允许对操作和表示的精化
/// > + 允许可变数目的实例
/// > + 比类操作更灵活
///
/// \version 2018-09-27
/// \since 2016-10-18
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <memory>
#include <mutex>

#include <gtest/gtest.h>
#include "rrcxx/cxx_versions.hxx"

namespace rrcxx::test {

/// \addtogroup gSingleton
/// @{

// eager singleton

/// \brief 饿汉单例。
class eager_singleton {
protected:
    explicit eager_singleton() = default;
public:
    explicit eager_singleton(const eager_singleton &) = delete;
    eager_singleton &operator=(const eager_singleton &) = delete;
    explicit eager_singleton(eager_singleton &&) = delete;
    eager_singleton &operator=(eager_singleton &&) = delete;
    virtual ~eager_singleton() = default;

    /// \brief 获取实例。
    static eager_singleton &instance()
    {
        static std::unique_ptr<eager_singleton> instance_owner {nullptr};
        if (instance_owner == nullptr)
            instance_owner = std::make_unique<eager_singleton>();
        return *instance_owner;
    }
};
/// \brief 尽早初始化。
static eager_singleton &initialize_early = eager_singleton::instance();

// lazy singleton

/// \brief 懒汉单例。
class lazy_singleton {
protected:
    explicit lazy_singleton() = default;
public:
    explicit lazy_singleton(const lazy_singleton &) = delete;
    lazy_singleton &operator=(const lazy_singleton &) = delete;
    explicit lazy_singleton(lazy_singleton &&) = delete;
    lazy_singleton &operator=(lazy_singleton &&) = delete;
    virtual  ~lazy_singleton() = default;

    /// \brief 获取实例。
    static lazy_singleton &instance()
    {
#if N2660
        static lazy_singleton instance_owner;
        return instance_owner;

#else
        static std::unique_ptr<lazy_singleton> instance_owner {nullptr};
        static std::mutex mutex;
        mutex.lock();
        {
            if (instance_owner == nullptr)
                instance_owner = std::make_unique<lazy_singleton>();
        }
        mutex.unlock();
        return *instance_owner;

#endif
    }
};

/// \brief 单例。
/// \sa \ref sCxxAndDclp
TEST(singleton, test)
{
    auto &eager_singleton_1 = eager_singleton::instance();
    auto &eager_singleton_2 = eager_singleton::instance();
    ASSERT_EQ(&eager_singleton_1, &eager_singleton_2);

    auto &lazy_singleton_1 = lazy_singleton::instance();
    auto &lazy_singleton_2 = lazy_singleton::instance();
    ASSERT_EQ(&lazy_singleton_1, &lazy_singleton_2);
}

/// @}

}//namespace rrcxx::test
