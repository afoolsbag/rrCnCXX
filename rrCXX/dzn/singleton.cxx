/**
 * \defgroup g_singleton 单例模式
 * \ingroup g_dzn_patterns
 *
 * \author zhengrr
 * \date 2016-10-18 – 2018-1-29
 * \copyright The MIT License
 *
 * @{
 */

#include "cxxver.hxx"

#if !N2660
#include <mutex>
#endif

#include <gtest/gtest.h>

namespace {

/// 饿汉单例模式
class EagerSingleton {
 public:
  explicit EagerSingleton(const EagerSingleton &) = delete;
  EagerSingleton &operator=(const EagerSingleton &) = delete;
  static EagerSingleton &Instance();
 private:
  explicit EagerSingleton() = default;
};// class EagerSingleton

EagerSingleton &EagerSingleton::Instance() {
  static EagerSingleton *instancePointer{};
  if (!instancePointer) {
    instancePointer = new EagerSingleton();
  }
  return *instancePointer;
}

EagerSingleton &gBeforeMain = EagerSingleton::Instance();

/// 懒汉单例模式
class LazySingleton {
 public:
  explicit LazySingleton(const LazySingleton &) = delete;
  LazySingleton &operator=(const LazySingleton &) = delete;
  static LazySingleton &Instance();
 private:
  explicit LazySingleton() = default;
};// class LazySingleton

LazySingleton &LazySingleton::Instance() {
#if N2660
  static LazySingleton inst;
  return inst;
#else// !N2660
  static LazySingleton *pInst{};
  static std::mutex mutex;
  mutex.lock();
  {
    if (!pInst)
      pInst = new LazySingleton;
  }
  mutex.unlock();
  return *pInst;
#endif// N2660
};

}// namespace

/**
 * \brief singleton preliminary
 * \sa \ref s_cxx_and_dclp
 */
TEST(singleton, preliminary) {
  auto &eagerSingleton1 = EagerSingleton::Instance();
  auto &eagerSingleton2 = EagerSingleton::Instance();
  assert(&eagerSingleton1 == &eagerSingleton2);

  auto &lazySingleton1 = LazySingleton::Instance();
  auto &lazySingleton2 = LazySingleton::Instance();
  assert(&lazySingleton1 == &lazySingleton2);
}

/** @} */
